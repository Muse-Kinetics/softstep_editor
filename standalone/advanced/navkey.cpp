// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "navkey.h"

//-------NAV PAD WINDOW SIZE CONSTANTS------------//
#define NAVWINDOW_LG_WIDTH 1118
#define NAVWINDOW_SM_WIDTH 935
#define NAVWINDOW_HEIGHT 410

//-------NAV BOX SIZE CONSTANTS-------//
#define NAVBOX_WIDTH 101
#define NAVBOX_HEIGHT 64
#define NAVBOX_STARTING_X_POS 579
#define KEYBOX_STARTING_X_POS 10

#ifdef Q_OS_MAC
#define NAVBOX_STARTING_Y_POS 204
#else
#define NAVBOX_STARTING_Y_POS 224
#endif


//-------NAV PAD WINDOW LINE SEPARATOR WIDTHS-------//
#define LINE_SEPARATOR_LG 1098
#define LINE_SEPARATOR_SM 915

NavKey::NavKey(QWidget *parent) :
    QWidget(parent),
    navBoxForm(new Ui::navBoxForm),
    navKeyWindowForm(new Ui::navKeyWindowForm),
    dataCooker(this),
    navBoxWidget(new QWidget(this)),
    navKeyWindowWidget(new QWidget(this))
{
    alphaNumManager.instanceNum = 99;

    dataCooker.hide();

    //set up the nav pad box
    navBoxForm->setupUi(navBoxWidget);
    navBoxWidget->setFixedSize(NAVBOX_WIDTH,NAVBOX_HEIGHT);
    this->setGeometry(NAVBOX_STARTING_X_POS, NAVBOX_STARTING_Y_POS, NAVBOX_WIDTH, NAVBOX_HEIGHT);

    //set ub the nav pad window
    navKeyWindowForm->setupUi(navKeyWindowWidget);
    navKeyWindowWidget->setFixedSize(NAVWINDOW_SM_WIDTH,NAVWINDOW_HEIGHT);
    QRect screenGeometry = QApplication::desktop()->availableGeometry();
    navKeyWindowWidget->setGeometry(170, (screenGeometry.height() / 2.4) + 150, NAVWINDOW_SM_WIDTH, NAVWINDOW_HEIGHT);
    navKeyWindowWidget->setWindowTitle(QString("Nav Pad Modulation"));
    navKeyWindowWidget->hide();
    navKeyWindowWidget->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint | Qt::CustomizeWindowHint);

    //what's in the nav pad box?
    connect(navBoxForm->openNavWindow, SIGNAL(clicked()), this, SLOT(slotOpenWindow()));

    //what's in the nav pad window?
    for(int i = 0; i < 6; i++)
    {
        navModline[i] = new NavModline(navKeyWindowWidget, i); //construct modlines
        navModline[i]->slotConnectElements(); //connect modlines
        displayLinkedButtonGroup.addButton(navModline[i]->displayLinkButton, i);
    }
    connect(navKeyWindowForm->showLEDSettings, SIGNAL(toggled(bool)), this, SLOT(slotShowDisplaySettings(bool)));
    connect(navKeyWindowForm->addmodline, SIGNAL(clicked()), this, SLOT(slotAddSubtractModlines()));
    connect(navKeyWindowForm->deletemodline, SIGNAL(clicked()), this, SLOT(slotAddSubtractModlines()));

    counter = 0;

   disableOverlay = new QWidget(navKeyWindowWidget);
}

void NavKey::slotOpenWindow()
{
    navKeyWindowWidget->show();
    navKeyWindowWidget->raise();
}

void NavKey::slotConnectElements()
{
    //nav name (from the nav box form)
    connect(navBoxForm->keyName, SIGNAL(textEdited(QString)), this, SLOT(slotValueChanged()));
    connect(navBoxForm->keyName, SIGNAL(textEdited(QString)), navKeyWindowForm->keyname, SLOT(setText(QString)));
    connect(navKeyWindowForm->keyname, SIGNAL(textEdited(QString)), navBoxForm->keyName, SLOT(setText(QString)));

    //nav modulation window stuff
    connect(navKeyWindowForm->navpadmode_modline, SIGNAL(clicked()),this,SLOT(slotValueChanged()));
    connect(navKeyWindowForm->navpadmode_programchange, SIGNAL(clicked()),this,SLOT(slotValueChanged()));

    //counter stuff
    if(mode == "hosted")
    {
        connect(navKeyWindowForm->counterMin, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));
        connect(navKeyWindowForm->counterMax, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));
        connect(navKeyWindowForm->counterWrap, SIGNAL(clicked()), this, SLOT(slotValueChanged()));
    }

    //display stuff
    connect(navKeyWindowForm->displayprefix,SIGNAL(textChanged(QString)),this,SLOT(slotValueChanged()));
    connect(navKeyWindowForm->keyname,SIGNAL(textChanged(QString)),this,SLOT(slotValueChanged()));
    connect(navKeyWindowForm->leddisplaymode,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //Hosted streaming
    for(int i = 0; i < 6; i++)
    {
        connect(navModline[i], SIGNAL(signalSetSource(QString,int)), &dataCooker, SLOT(slotSetSource(QString,int)));
        connect(&dataCooker, SIGNAL(signalTransformSource(int,int,QString)), navModline[i], SLOT(slotTransformSource(int,int,QString)));
        //connect(navModline[i], SIGNAL(hosted_signalYIncSet(int)), &dataCooker, SLOT(slotYIncSet(int)));

        //alphanumeric display -- needs special slot because it is display linked
        connect(navModline[i], SIGNAL(hosted_signalSendParamDisplayOutput(int,int)), &alphaNumManager, SLOT(slotDisplayParam(int,int)));

        //counter
        //connect(navModline[i], SIGNAL(hosted_signalCounter(QString,int)), this, SLOT(slotCounter(QString,int)));
        //connect(this, SIGNAL(signalCounterValue(int)), navModline[i], SLOT(slotCounterReturn(int)));
    }

    //Program change mode
    connect(&dataCooker, SIGNAL(signalDisplayProgramChangeDecade(int)), this, SLOT(slotDisplayProgramChangeDecade(int)));
}

void NavKey::slotDisconnectElements()
{
    //nav name (from the nav box form)
    disconnect(navBoxForm->keyName, SIGNAL(textEdited(QString)), this, SLOT(slotValueChanged()));

    //nav modulation window stuff
    disconnect(navKeyWindowForm->navpadmode_modline, SIGNAL(clicked()),this,SLOT(slotValueChanged()));
    disconnect(navKeyWindowForm->navpadmode_programchange, SIGNAL(clicked()),this,SLOT(slotValueChanged()));

    //counter stuff
    if(mode == "hosted")
    {
        disconnect(navKeyWindowForm->counterMin, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));
        disconnect(navKeyWindowForm->counterMax, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));
        disconnect(navKeyWindowForm->counterWrap, SIGNAL(clicked()), this, SLOT(slotValueChanged()));
    }

    //display stuff
    disconnect(navKeyWindowForm->displayprefix,SIGNAL(textChanged(QString)),this,SLOT(slotValueChanged()));
    disconnect(navKeyWindowForm->keyname,SIGNAL(textChanged(QString)),this,SLOT(slotValueChanged()));
    disconnect(navKeyWindowForm->leddisplaymode,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //Hosted streaming
    for(int i = 0; i < 6; i++)
    {
        disconnect(navModline[i], SIGNAL(signalSetSource(QString,int)), &dataCooker, SLOT(slotSetSource(QString,int)));
        disconnect(&dataCooker, SIGNAL(signalTransformSource(int,int,QString)), navModline[i], SLOT(slotTransformSource(int,int,QString)));

        //alphanumeric display -- needs special slot because it is display linked
        disconnect(navModline[i], SIGNAL(hosted_signalSendParamDisplayOutput(int,int)), &alphaNumManager, SLOT(slotDisplayParam(int,int)));

        //counter
        //disconnect(navModline[i], SIGNAL(hosted_signalCounter(QString,int)), this, SLOT(slotCounter(QString,int)));
        //disconnect(this, SIGNAL(signalCounterValue(int)), navModline[i], SLOT(slotCounterReturn(int)));
    }

    //Program change mode
    disconnect(&dataCooker, SIGNAL(signalDisplayProgramChangeDecade(int)), this, SLOT(slotDisplayProgramChangeDecade(int)));
}

void NavKey::slotValueChanged()
{
    if(QObject::sender())
    {
        QString jsonName;
        QObject *sender = QObject::sender();
        QVariant value;
        bool updateAlphaDisplayParams = false;

        //nav name
        if(sender == navBoxForm->keyName)
        {
            jsonName = "name";
            value = navBoxForm->keyName->text();
            updateAlphaDisplayParams = true;
        }
        //key counter stuff
        else if(sender == navKeyWindowForm->counterMin)
        {
            jsonName = "counter_min";
            value = navKeyWindowForm->counterMin->value();
        }
        else if(sender == navKeyWindowForm->counterMax)
        {
            jsonName = "counter_max";
            value = navKeyWindowForm->counterMax->value();
        }
        else if(sender == navKeyWindowForm->counterWrap)
        {
            jsonName = "counter_wrap";
            value = navKeyWindowForm->counterWrap->isChecked();
        }
        //modline mode stuff
        else if(sender == navKeyWindowForm->navpadmode_modline)
        {
            jsonName = "modlinemode";
            value = 0;
        }
        else if(sender == navKeyWindowForm->navpadmode_programchange)
        {
            jsonName = "modlinemode";
            value = 1;
        }
        //display stuff
        else if(sender == navKeyWindowForm->displayprefix)
        {
            jsonName = "prefix";
            value = navKeyWindowForm->displayprefix->text();
            updateAlphaDisplayParams = true;
        }
        else if(sender == navKeyWindowForm->keyname)
        {
            jsonName = "name";
            value = navKeyWindowForm->keyname->text();
            updateAlphaDisplayParams = true;
        }
        else if(sender == navKeyWindowForm->leddisplaymode)
        {
            jsonName = "displaymode";
            value = navKeyWindowForm->leddisplaymode->currentText();
            updateAlphaDisplayParams = true;
        }

        emit signalStoreValue(QString("nav_%1").arg(jsonName), value, -1);

        //if an alphanum param was modified update its members
        if(updateAlphaDisplayParams = true)
        {
            slotSetAlphaNumSettings();
        }
    }

    dataCooker.slotSetCounterParams(navKeyWindowForm->counterMin->value(),navKeyWindowForm->counterMax->value(), navKeyWindowForm->counterWrap->isChecked());

    emit signalCheckSavedState();

    slotUpdateModlineMode();
}

void NavKey::slotRecallPreset(QVariantMap preset, QVariantMap)
{
    slotDisconnectElements();

    if(mode == "hosted")
    {
        //--------------------------------------------- Store states from older preset, using "old" preset name (updated below after recall)
        stateRecaller.presetName = currentPreset;

        //Key Counter
        stateRecaller.slotStoreCounterState(counter);

        //Inc-Dec -- -1 one for x value because it's not used
        stateRecaller.slotStoreIncDecState(-1, dataCooker.yIncCount);

        for(int i=0; i < 6; i++)
        {
            //Init Modes
            stateRecaller.slotStoreInitModeState(i, navModline[i]->initModeOnceCalled);

            //Toggle
            stateRecaller.slotStoreToggleStates(i, navModline[i]->toggleTable);
        }

        //Set new preset name
        stateRecaller.presetName = preset.value("preset_name").toString();
        currentPreset = preset.value("preset_name").toString();
    }

    navBoxForm->keyName->setText(preset.value(QString("nav_name")).toString());

    //this stuff is to determine the modlinemode (0 is for modline, 1 is for programchange... this can be changed)
    int modlinemode = preset.value(QString("nav_modlinemode")).toInt();
    if(modlinemode == 0)
    {
        navKeyWindowForm->navpadmode_modline->setChecked(TRUE);
        navKeyWindowForm->navpadmode_programchange->setChecked(FALSE);
    }
    else if(modlinemode == 1)
    {
        navKeyWindowForm->navpadmode_modline->setChecked(FALSE);
        navKeyWindowForm->navpadmode_programchange->setChecked(TRUE);
    }

    //counter stuff
    if(mode == "hosted")
    {
        navKeyWindowForm->counterMin->setValue(preset.value(QString("nav_counter_min")).toInt());
        navKeyWindowForm->counterMax->setValue(preset.value(QString("nav_counter_max")).toInt());
        navKeyWindowForm->counterWrap->setChecked(preset.value(QString("nav_counter_wrap")).toInt());
    }

    //display stuff
    navKeyWindowForm->displayprefix->setText(preset.value(QString("nav_prefix")).toString());
    navKeyWindowForm->keyname->setText(preset.value(QString("nav_name")).toString());
    navKeyWindowForm->leddisplaymode->setCurrentIndex(navKeyWindowForm->leddisplaymode->findText(preset.value(QString("nav_displaymode")).toString()));

    slotConnectElements();

    alphaNumManager.paramDisplay = false; //close gate initially, on preset change
    slotSetAlphaNumSettings();


    if(mode == "hosted")
    {
        alphaNumManager.slotPresetChangeDisplayPresetName();
    }


    dataCooker.slotSetCounterParams(navKeyWindowForm->counterMin->value(),navKeyWindowForm->counterMax->value(), navKeyWindowForm->counterWrap->isChecked());

    if(mode == "hosted")
    {
        //--------------------------------------------- Recall states from current preset
        //Counter
        counter = stateRecaller.counterState.value(currentPreset);

        //Inc-Dec
        dataCooker.yIncCount = stateRecaller.yIncDecState.value(currentPreset);

        for(int i = 0; i < 6; i++)
        {
            //Init Modes
            navModline[i]->initModeOnceCalled = stateRecaller.initModeOnceCalledState[i].value(currentPreset);

            //Toggle
            navModline[i]->toggleTable = stateRecaller.toggleStates[i].value(currentPreset);
        }
    }

    slotUpdateModlineMode();

}

void NavKey::slotShowDisplaySettings(bool show)
{
    if(show == TRUE)
    {
        //show large window
        navKeyWindowWidget->setFixedWidth(NAVWINDOW_LG_WIDTH);
        //show large line separator
        navKeyWindowForm->label->setFixedWidth(LINE_SEPARATOR_LG);
    }
    else
    {
        //show small window
        navKeyWindowWidget->setFixedWidth(NAVWINDOW_SM_WIDTH);
        //show small line separator
        navKeyWindowForm->label->setFixedWidth(LINE_SEPARATOR_SM);
    }

    slotUpdateModlineMode();
}

void NavKey::slotWindowHeight(int modlinesShowing)
{
    if(modlinesShowing == 2)
    {
        navKeyWindowWidget->setFixedHeight(NAVWINDOW_HEIGHT-188);
        navKeyWindowForm->addmodline->setGeometry(9,192,22,22);
        navKeyWindowForm->deletemodline->setGeometry(35,192,22,22);
        navModline[2]->hide();
        navModline[3]->hide();
        navModline[4]->hide();
        navModline[5]->hide();
    }
    else if(modlinesShowing == 3)
    {
        navKeyWindowWidget->setFixedHeight(NAVWINDOW_HEIGHT-141);
        navKeyWindowForm->addmodline->setGeometry(9,239,22,22);
        navKeyWindowForm->deletemodline->setGeometry(35,239,22,22);
        navModline[2]->show();
        navModline[3]->hide();
        navModline[4]->hide();
        navModline[5]->hide();
    }
    else if(modlinesShowing == 4)
    {
        navKeyWindowWidget->setFixedHeight(NAVWINDOW_HEIGHT-94);
        navKeyWindowForm->addmodline->setGeometry(9,286,22,22);
        navKeyWindowForm->deletemodline->setGeometry(35,286,22,22);
        navModline[2]->show();
        navModline[3]->show();
        navModline[4]->hide();
        navModline[5]->hide();
    }
    else if(modlinesShowing == 5)
    {
        navKeyWindowWidget->setFixedHeight(NAVWINDOW_HEIGHT-47);
        navKeyWindowForm->addmodline->setGeometry(9,333,22,22);
        navKeyWindowForm->deletemodline->setGeometry(35,333,22,22);
        navModline[2]->show();
        navModline[3]->show();
        navModline[4]->show();
        navModline[5]->hide();
    }
    else if(modlinesShowing == 6)
    {
        navKeyWindowWidget->setFixedHeight(NAVWINDOW_HEIGHT);
        navKeyWindowForm->addmodline->setGeometry(9,380,22,22);
        navKeyWindowForm->deletemodline->setGeometry(35,380,22,22);
        navModline[2]->show();
        navModline[3]->show();
        navModline[4]->show();
        navModline[5]->show();
    }
}

void NavKey::slotRecallShowModlines(QVariantMap preset, QVariantMap)
{
    numModlines = 2;

    //first determine how many modlines should be showing based on which preset is recalled
    for(int i = 0; i < 6; i++)
    {
        bool modlineEnabled;

        modlineEnabled = preset.value(QString("nav_modline%1_enable").arg(i+1)).toBool();

        if(i>1 && modlineEnabled == TRUE)
        {
            numModlines = i+1;
        }
    }

    slotWindowHeight(numModlines);
    //qDebug() << QString("show %1 nav modlines").arg(numModlines);

    slotUpdateModlineMode();
}

void NavKey::slotAddSubtractModlines()
{
    //then add or subtract modlines when the buttons are clicked
    if(QObject::sender())
    {
        QObject *sender = QObject::sender();

        if(sender == navKeyWindowForm->addmodline)
        {
            numModlines++;
        }
        else if(sender == navKeyWindowForm->deletemodline)
        {
            emit signalDeleteModline(numModlines, FALSE);
            numModlines--;
        }
    }
    if(numModlines > 6)
    {
        numModlines = 6;
        navKeyWindowForm->addmodline->setCheckable(FALSE);
    }
    else if(numModlines < 2)
    {
        numModlines = 2;
        navKeyWindowForm->deletemodline->setCheckable(FALSE);
    }
    else
    {
        navKeyWindowForm->addmodline->setCheckable(TRUE);
        navKeyWindowForm->deletemodline->setCheckable(TRUE);
    }

    slotWindowHeight(numModlines);
    //qDebug() << QString("show %1 nav modlines").arg(numModlines);

    slotUpdateModlineMode();
}

void NavKey::slotSetMode(QString m)
{
    mode = m;

    if(mode == "hosted")
    {
        navKeyWindowForm->counterMax->setEnabled(true);
        navKeyWindowForm->counterMin->setEnabled(true);
        navKeyWindowForm->counterWrap->setEnabled(true);
    }
    else
    {
        navKeyWindowForm->counterMax->setEnabled(false);
        navKeyWindowForm->counterMin->setEnabled(false);
        navKeyWindowForm->counterWrap->setEnabled(false);
    }
}

void NavKey::slotPopulateMenus(QStringList displayModes)
{
    //Set Display Mode Menus
    navKeyWindowForm->leddisplaymode->clear();
    navKeyWindowForm->leddisplaymode->addItems(displayModes);
}

void NavKey::slotSetDataCookerSettings()
{

}

void NavKey::slotSetPresetName(QString name)
{
    alphaNumManager.currentPresetName = name;
}

void NavKey::slotSetAlphaNumSettings()
{

    //qDebug() << navKeyWindowForm->navpadmode_modline->isChecked();

    //If in nav pad is in modline mode
    if(navKeyWindowForm->navpadmode_modline->isChecked())
    {
        alphaNumManager.displayMode = navKeyWindowForm->leddisplaymode->currentText();
        alphaNumManager.keyName = navKeyWindowForm->keyname->text();
        alphaNumManager.prefix = navKeyWindowForm->displayprefix->text();
        alphaNumManager.postfix = "";
    }

    //If nav pad is in program change
    else
    {
        alphaNumManager.displayMode = "Immed Param";
        alphaNumManager.keyName = navKeyWindowForm->keyname->text();
        alphaNumManager.prefix = "";
        alphaNumManager.postfix = "_";
    }

}

void NavKey::slotCounter(QString whatToDo, int val)
{
    bool wrap = navKeyWindowForm->counterWrap->isChecked();
    int min = navKeyWindowForm->counterMin->value();
    int max = navKeyWindowForm->counterMax->value();

    if(whatToDo == "Inc")
    {
        if(wrap && counter == max)
        {
            counter = min;
        }
        else if(!wrap && counter == max)
        {
            counter == max;
        }
        else if(counter < min)
        {
            counter = min;
        }
        else
        {
            counter++;
        }
    }
    else if(whatToDo == "Dec")
    {
        if(wrap && counter == min)
        {
            counter = max;
        }
        else if(!wrap && counter == min)
        {
            counter == min;
        }
        else
        {
            counter--;
        }
    }
    else if(whatToDo == "Set")
    {
        if(val > max)
        {
            val = max;
        }

        if(val < min)
        {
            val = min;
        }

        counter = val;
    }

    emit signalCounterValue(counter);
}

void NavKey::slotDisplayProgramChangeDecade(int decade)
{
    //qDebug() << "decade" << decade << dataCooker.navPadMode;

    if(decade < 10)
    {
        alphaNumManager.slotFormatAndOutputString(QString("%1_  ").arg(decade));
    }
    else
    {
        alphaNumManager.slotFormatAndOutputString(QString("%1_ ").arg(decade));
    }
}

void NavKey::slotUpdateModlineMode()
{
    //QWidget *disableOverlay = new QWidget(navKeyWindowWidget);
    disableOverlay->setStyleSheet("background: rgba(0,0,0,100); border: none;");
    disableOverlay->setGeometry(4,55,navKeyWindowWidget->width() - 8, navKeyWindowWidget->height() - 55 - 4);

    if(navKeyWindowForm->navpadmode_modline->isChecked())
    {
        dataCooker.navPadMode = "modline";
        //qDebug() << "show modlines";
        disableOverlay->raise();
        disableOverlay->hide();
    }
    else
    {
         dataCooker.navPadMode = "program";
         //qDebug() << "hide modlines";
         disableOverlay->raise();
         disableOverlay->show();
    }

    for(int i = 0; i < 6; i++)
    {
        navModline[i]->lower();
    }

}
