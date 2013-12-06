// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "key.h"

#include <QDebug>

/*-------KEYWINDOW SIZE CONSTANTS-------*/
#define KEYWINDOW_LG_WIDTH 1150
#define KEYWINDOW_SM_WIDTH 935
#define KEYWINDOW_HEIGHT 410
#define LINE_SEPARATOR_LG 1130
#define LINE_SEPARATOR_SM 915

/*-------KEYBOX SIZE AND SPACING CONSTANTS-------*/

//Keybox dimensions
#define KEYBOX_WIDTH 101
#define KEYBOX_HEIGHT 64
//Space between key boxes
#define KEYBOX_X_SPACING 10
#define KEYBOX_Y_SPACING 10
//Key box starting position (refers to keybox 1 position)
#define KEYBOX_STARTING_X_POS 10
#define KEYBOX_STARTING_Y_POS 204


Key::Key(QWidget *parent, int keyInstanceNum) :
    QWidget(parent),
    keyBoxForm(new Ui::keyBoxForm),
    keyWindowForm(new Ui::keyWindowForm),
    dataCooker(keyInstanceNum, this),
    keyWindowWidget(new QWidget(this)),
    keyBoxWidget(new QWidget(this))
{
    keyInstance = keyInstanceNum;

    alphaNumManager.instanceNum = keyInstance;
    ledManager.keyInstanceNum = keyInstance;

    dataCooker.hide();

    //Set up the Key Box
    //keyBoxWidget = new QWidget(this);
    keyBoxForm->setupUi(keyBoxWidget);
    keyBoxWidget->setFixedSize(KEYBOX_WIDTH, KEYBOX_HEIGHT);

    if(keyInstanceNum < 5)
    {
        this->setGeometry(10 + ((keyInstance) * (KEYBOX_WIDTH + KEYBOX_X_SPACING)), KEYBOX_STARTING_Y_POS, KEYBOX_WIDTH, KEYBOX_HEIGHT);
    }
    else
    {
        this->setGeometry(10 + ((keyInstance - 5) * (KEYBOX_WIDTH + KEYBOX_X_SPACING)), KEYBOX_STARTING_Y_POS - KEYBOX_HEIGHT - KEYBOX_Y_SPACING, KEYBOX_WIDTH, KEYBOX_HEIGHT);
    }


    //Set up the Key Window
    //keyWindowWidget = new QWidget();
    keyWindowForm->setupUi(keyWindowWidget);
    keyWindowWidget->setFixedSize(KEYWINDOW_SM_WIDTH, KEYWINDOW_HEIGHT);
    QRect screenGeometry = QApplication::desktop()->availableGeometry();
    keyWindowWidget->setGeometry(20 + (keyInstance * 15), (screenGeometry.height() / 2) + (keyInstance * 15), KEYWINDOW_SM_WIDTH, KEYWINDOW_HEIGHT);
    keyWindowWidget->setWindowTitle(QString("Key %1 Modulation").arg((keyInstance+1)%10));
    //keyWindowWidget->setParent(this);
    keyWindowWidget->setWindowFlags(Qt::Tool | Qt::WindowCloseButtonHint | Qt::CustomizeWindowHint| Qt::WindowStaysOnTopHint);

    //What's in the Key Box?
    connect(keyBoxForm->openWindow,SIGNAL(clicked()), this, SLOT(slotOpenWindow()));

    //What's in the Key Window?
    for(int i = 0; i < 6; i++)
    {
        modline[i] = new Modline(keyWindowWidget, keyInstance, i);
        modline[i]->slotConnectElements();
        displayLinkedButtonGroup.addButton(modline[i]->displayLinkButton, i);
    }

    connect(keyWindowForm->ledDisplayCheckBox, SIGNAL(toggled(bool)), this, SLOT(slotShowDisplaySettings(bool)));
    connect(keyWindowForm->addmodline, SIGNAL(clicked()), this, SLOT(slotAddSubtractModlines()));
    connect(keyWindowForm->deletemodline, SIGNAL(clicked()), this, SLOT(slotAddSubtractModlines()));

    //Carson's attempt to dynamically update the key window instance label — shit works
    keyWindowForm->keyWindowInstanceLabel->setText(QString("%1").arg((keyInstance + 1) % 10));
    keyBoxForm->openWindow->setStyleSheet(stylesheets.keyBoxOpenButtonStyleSheet.at(keyInstance));

    counter = 0;
}

void Key::slotOpenWindow()
{
    //qDebug() << QString("Open Key %1 Button clicked! Open the window!").arg(keyInstance+1);
    keyWindowWidget->show();
    keyWindowWidget->raise();
}

void Key::slotConnectElements()
{
    //key name (from the keyBoxForm)
    connect(keyBoxForm->keyName,SIGNAL(textEdited(QString)),this,SLOT(slotValueChanged()));
    connect(keyBoxForm->keyName,SIGNAL(textEdited(QString)),keyWindowForm->keyname, SLOT(setText(QString)));
    connect(keyWindowForm->keyname,SIGNAL(textEdited(QString)),keyBoxForm->keyName, SLOT(setText(QString)));

    //key counter stuff
    if(mode == "hosted")
    {
        connect(keyWindowForm->counterMin,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
        connect(keyWindowForm->counterMax,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
        connect(keyWindowForm->counterWrap,SIGNAL(clicked()),this,SLOT(slotValueChanged()));
    }

    //display stuff
    connect(keyWindowForm->displayprefix,SIGNAL(textChanged(QString)),this,SLOT(slotValueChanged()));
    connect(keyWindowForm->keyname,SIGNAL(textChanged(QString)),this,SLOT(slotValueChanged()));
    connect(keyWindowForm->leddisplaymode,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //Modlines
    for(int i = 0; i < 6; i++)
    {
        //Source Streaming
        connect(modline[i], SIGNAL(signalSetSource(QString,int)), &dataCooker, SLOT(slotSetSource(QString,int)));
        connect(&dataCooker, SIGNAL(signalTransformSource(int, int, QString)), modline[i], SLOT(slotTransformSource(int, int, QString)));
        connect(modline[i], SIGNAL(hosted_signalSendModlineOutput(int,int)), &dataCooker, SLOT(slotReceiveModlineOutput(int,int)));
        connect(modline[i], SIGNAL(hosted_signalYIncSet(int)), &dataCooker, SLOT(slotYIncSet(int)));
        connect(modline[i], SIGNAL(hosted_signalXIncSet(int)), &dataCooker, SLOT(slotXIncSet(int)));

        //Leds -- used modline output because all lines' logic is checked
        connect(modline[i], SIGNAL(hosted_signalSendModlineOutput(int,int)), &ledManager, SLOT(slotReceiveModlineOutput(int,int)));
        connect(modline[i], SIGNAL(hosted_signalSetLEDMode(int, QString,QString)), &ledManager, SLOT(slotSetLedModes(int,QString,QString)));

        //alphanumeric display -- needs special slot because it is display linked
        connect(modline[i], SIGNAL(hosted_signalSendParamDisplayOutput(int,int)), &alphaNumManager, SLOT(slotDisplayParam(int,int)));

        //Counter
        connect(modline[i], SIGNAL(hosted_signalCounter(QString,int)), this, SLOT(slotCounter(QString,int)));
        connect(this, SIGNAL(signalCounterValue(int)), modline[i], SLOT(slotCounterReturn(int)));

        //State Recall
        //connect(modline[i], SIGNAL(hosted_signalStoreToggleState(int,bool)), &stateRecaller, SLOT(slotStoreToggleStates(int,bool)));

        connect(&stateRecaller, SIGNAL(signalStateRecallLedLastPacketList(QList<MIDIPacket>)), &ledManager, SLOT(slotStateRecallLedLastPacket(QList<MIDIPacket>)));

    }

    //alphanumeric display - handled in main window
    //connect(&dataCooker, SIGNAL(signalThisKeyPressed(int)), &alphaNumManager, SLOT(slotDisplayKeyName()));
}

void Key::slotDisconnectElements()
{
    //key name (from the keyBoxForm)
    disconnect(keyBoxForm->keyName,SIGNAL(textEdited(QString)),this,SLOT(slotValueChanged()));

    //key counter stuff
    if(mode == "hosted")
    {
        disconnect(keyWindowForm->counterMin,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
        disconnect(keyWindowForm->counterMax,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
        disconnect(keyWindowForm->counterWrap,SIGNAL(clicked()),this,SLOT(slotValueChanged()));
    }

    //display stuff
    disconnect(keyWindowForm->displayprefix,SIGNAL(textChanged(QString)),this,SLOT(slotValueChanged()));
    disconnect(keyWindowForm->keyname,SIGNAL(textChanged(QString)),this,SLOT(slotValueChanged()));
    disconnect(keyWindowForm->leddisplaymode,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //Hosted streaming
    for(int i = 0; i < 6; i++)
    {
        disconnect(modline[i], SIGNAL(signalSetSource(QString,int)), &dataCooker, SLOT(slotSetSource(QString,int)));
        disconnect(&dataCooker, SIGNAL(signalTransformSource(int, int, QString)), modline[i], SLOT(slotTransformSource(int, int, QString)));
        disconnect(modline[i], SIGNAL(hosted_signalSendModlineOutput(int,int)), &dataCooker, SLOT(slotReceiveModlineOutput(int,int)));
        disconnect(modline[i], SIGNAL(hosted_signalYIncSet(int)), &dataCooker, SLOT(slotYIncSet(int)));
        disconnect(modline[i], SIGNAL(hosted_signalXIncSet(int)), &dataCooker, SLOT(slotXIncSet(int)));

        //leds -- used modline output because all lines' logic is checked
        disconnect(modline[i], SIGNAL(hosted_signalSendModlineOutput(int,int)), &ledManager, SLOT(slotReceiveModlineOutput(int,int)));
        disconnect(modline[i], SIGNAL(hosted_signalSetLEDMode(int, QString,QString)), &ledManager, SLOT(slotSetLedModes(int,QString,QString)));

        disconnect(modline[i], SIGNAL(hosted_signalSendParamDisplayOutput(int,int)), &alphaNumManager, SLOT(slotDisplayParam(int,int)));

        disconnect(modline[i], SIGNAL(hosted_signalCounter(QString,int)), this, SLOT(slotCounter(QString,int)));
        disconnect(this, SIGNAL(signalCounterValue(int)), modline[i], SLOT(slotCounterReturn(int)));
    }

    disconnect(&stateRecaller, SIGNAL(signalStateRecallLedLastPacketList(QList<MIDIPacket>)), &ledManager, SLOT(slotStateRecallLedLastPacket(QList<MIDIPacket>)));
}

void Key::slotValueChanged()
{
    if(QObject::sender())
    {
        QString jsonName;
        QObject *sender = QObject::sender();
        QVariant value;
        bool updateAlphaDisplayParams = false;


        //key name (from the keyBoxForm
        if(sender == keyBoxForm->keyName)
        {
            jsonName = "name";
            value = keyBoxForm->keyName->text();
            updateAlphaDisplayParams = true;
        }
        //key counter stuff
        else if(sender == keyWindowForm->counterMin)
        {
            jsonName = "counter_min";
            value = keyWindowForm->counterMin->value();
        }
        else if(sender == keyWindowForm->counterMax)
        {
            jsonName = "counter_max";
            value = keyWindowForm->counterMax->value();
        }
        else if(sender == keyWindowForm->counterWrap)
        {
            jsonName = "counter_wrap";
            value = keyWindowForm->counterWrap->isChecked();
        }
        //display stuff
        else if(sender == keyWindowForm->displayprefix)
        {
            jsonName = "prefix";
            value = keyWindowForm->displayprefix->text();
            updateAlphaDisplayParams = true;
        }
        else if(sender == keyWindowForm->keyname)
        {
            jsonName = "name";
            value = keyWindowForm->keyname->text();
            updateAlphaDisplayParams = true;
        }
        else if(sender == keyWindowForm->leddisplaymode)
        {
            jsonName = "displaymode";
            value = keyWindowForm->leddisplaymode->currentText();
            updateAlphaDisplayParams = true;
        }

        emit signalStoreValue(QString("%1_key_").arg(keyInstance+1) + jsonName, value, -1);

        //If an alphanum param was modified update it's members
        if(updateAlphaDisplayParams = true)
        {
            slotSetAlphaNumSettings();
        }
    }



    emit signalCheckSavedState();
}

void Key::slotRecallPreset(QVariantMap preset, QVariantMap)
{
    //qDebug() << "Key State Recall" << keyInstance;

    //Disconnect UI Elements, to avoid looping call
    slotDisconnectElements();

    if(mode == "hosted")
    {
        //--------------------------------------------- Store states from older preset, using "old" preset name (updated below after recall)
        stateRecaller.presetName = currentPreset;

        //Key Counter
        stateRecaller.slotStoreCounterState(counter);

        //Inc-Dec Counters
        stateRecaller.slotStoreIncDecState(dataCooker.xIncCount, dataCooker.yIncCount);

        //Previous Key Pressed
        stateRecaller.slotStorePreviousKeyValueState(dataCooker.previousKeyPressed[1]);

        for(int i=0; i < 6; i++)
        {
            //Init Modes
            stateRecaller.slotStoreInitModeState(i, modline[i]->initModeOnceCalled);

            //Toggle
            stateRecaller.slotStoreToggleStates(i, modline[i]->toggleTable);

            //LEDs
            stateRecaller.slotStoreLedStates(i, ledManager.state[i]);
        }
        //(LEDs)
        stateRecaller.slotStoreLedLastPacketList(ledManager.lastPacketListSent);

        //Set new preset name
        stateRecaller.presetName = preset.value("preset_name").toString();
        currentPreset = preset.value("preset_name").toString();
    }

    //Change UI Elements
    keyBoxForm->keyName->setText(preset.value(QString("%1_key_name").arg(keyInstance+1)).toString());

    if(mode == "hosted")
    {
        keyWindowForm->counterMin->setValue(preset.value(QString("%1_key_counter_min").arg(keyInstance+1)).toInt());
        keyWindowForm->counterMax->setValue(preset.value(QString("%1_key_counter_max").arg(keyInstance+1)).toInt());
        keyWindowForm->counterWrap->setChecked(preset.value(QString("%1_key_counter_wrap").arg(keyInstance+1)).toBool());
    }

    keyWindowForm->displayprefix->setText(preset.value(QString("%1_key_prefix").arg(keyInstance+1)).toString());
    keyWindowForm->keyname->setText(preset.value(QString("%1_key_name").arg(keyInstance+1)).toString());
    keyWindowForm->leddisplaymode->setCurrentIndex(keyWindowForm->leddisplaymode->findText(preset.value(QString("%1_key_displaymode").arg(keyInstance+1)).toString()));

    //Reconnect UI Elements
    slotConnectElements();

    //Reset Alphanumeric Display
    alphaNumManager.paramDisplay = false; //close gate initially
    slotSetAlphaNumSettings();

    if(mode == "hosted")
    {
        //--------------------------------------------- Recall states from current preset
        //Counter
        counter = stateRecaller.counterState.value(currentPreset);

        //Inc-Dec
        dataCooker.yIncCount = stateRecaller.yIncDecState.value(currentPreset);
        dataCooker.xIncOrDec = stateRecaller.xIncDecState.value(currentPreset);

        for(int i = 0; i < 6; i++)
        {
            //Init Modes
            modline[i]->initModeOnceCalled = stateRecaller.initModeOnceCalledState[i].value(currentPreset);

            //Toggle
            modline[i]->toggleTable = stateRecaller.toggleStates[i].value(currentPreset);

            //LEDs -- state
            ledManager.state[i] = stateRecaller.ledStates[i].value(currentPreset);
        }

        //LEDs -- last packet
        ledManager.slotStateRecallLedLastPacket(stateRecaller.lastMidiPacketList.value(currentPreset));
    }
}

void Key::slotShowDisplaySettings(bool show)
{
    if(show == TRUE)
    {
        //show large window
        keyWindowWidget->setFixedWidth(KEYWINDOW_LG_WIDTH);
        //show large line separator
        keyWindowForm->label->setFixedWidth(LINE_SEPARATOR_LG);
    }
    else
    {
        //show small window
        keyWindowWidget->setFixedWidth(KEYWINDOW_SM_WIDTH);
        //show small line separator
        keyWindowForm->label->setFixedWidth(LINE_SEPARATOR_SM);
    }
}

void Key::slotWindowHeight(int modlinesShowing)
{
    if(modlinesShowing == 2)
    {
        keyWindowWidget->setFixedHeight(KEYWINDOW_HEIGHT-188);
        keyWindowForm->addmodline->setGeometry(9,192,22,22);
        keyWindowForm->deletemodline->setGeometry(35,192,22,22);
        modline[2]->hide();
        modline[3]->hide();
        modline[4]->hide();
        modline[5]->hide();
    }
    else if(modlinesShowing == 3)
    {
        keyWindowWidget->setFixedHeight(KEYWINDOW_HEIGHT-141);
        keyWindowForm->addmodline->setGeometry(9,239,22,22);
        keyWindowForm->deletemodline->setGeometry(35,239,22,22);
        modline[2]->show();
        modline[3]->hide();
        modline[4]->hide();
        modline[5]->hide();
    }
    else if(modlinesShowing == 4)
    {
        keyWindowWidget->setFixedHeight(KEYWINDOW_HEIGHT-94);
        keyWindowForm->addmodline->setGeometry(9,286,22,22);
        keyWindowForm->deletemodline->setGeometry(35,286,22,22);
        modline[2]->show();
        modline[3]->show();
        modline[4]->hide();
        modline[5]->hide();
    }
    else if(modlinesShowing == 5)
    {
        keyWindowWidget->setFixedHeight(KEYWINDOW_HEIGHT-47);
        keyWindowForm->addmodline->setGeometry(9,333,22,22);
        keyWindowForm->deletemodline->setGeometry(35,333,22,22);
        modline[2]->show();
        modline[3]->show();
        modline[4]->show();
        modline[5]->hide();
    }
    else if(modlinesShowing == 6)
    {
        keyWindowWidget->setFixedHeight(KEYWINDOW_HEIGHT);
        keyWindowForm->addmodline->setGeometry(9,380,22,22);
        keyWindowForm->deletemodline->setGeometry(35,380,22,22);
        modline[2]->show();
        modline[3]->show();
        modline[4]->show();
        modline[5]->show();
    }
}

void Key::slotRecallShowModlines(QVariantMap preset, QVariantMap)
{
    numModlines = 2;

    //first determine how many modlines should be showing based on which preset is recalled
    for(int i = 0; i < 6; i++)
    {
        bool modlineEnabled;

        modlineEnabled = preset.value(QString("key%1_modline%2_enable").arg(keyInstance+1).arg(i+1)).toBool();

        if(i>1 && modlineEnabled == TRUE)
        {
            numModlines = i+1;
        }
    }

    slotWindowHeight(numModlines);
    //qDebug() << QString("show %1 key %2 modlines").arg(numModlines).arg(keyInstance+1);
}

void Key::slotAddSubtractModlines()
{
    //then add or subtract modlines when the buttons are clicked
    if(QObject::sender())
    {
        QObject *sender = QObject::sender();

        if(sender == keyWindowForm->addmodline)
        {
            numModlines++;
        }
        else if(sender == keyWindowForm->deletemodline)
        {
            numModlines--;
        }
    }
    if(numModlines > 6)
    {
        numModlines = 6;
        keyWindowForm->addmodline->setCheckable(FALSE);
    }
    else if(numModlines < 2)
    {
        numModlines = 2;
        keyWindowForm->deletemodline->setCheckable(FALSE);
    }
    else
    {
        keyWindowForm->addmodline->setCheckable(TRUE);
        keyWindowForm->deletemodline->setCheckable(TRUE);
    }

    slotWindowHeight(numModlines);
    //qDebug() << QString("show %1 key %2 modlines").arg(numModlines).arg(keyInstance+1);
}

void Key::slotSetMode(QString m)
{
    mode = m;

    if(mode == "hosted")
    {
        keyWindowForm->counterMax->setEnabled(true);
        keyWindowForm->counterMin->setEnabled(true);
        keyWindowForm->counterWrap->setEnabled(true);
    }
    else
    {
        keyWindowForm->counterMax->setEnabled(false);
        keyWindowForm->counterMin->setEnabled(false);
        keyWindowForm->counterWrap->setEnabled(false);
    }
}

void Key::slotSetDataCookerSettings()
{

}

void Key::slotSetPresetName(QString name)
{
    alphaNumManager.currentPresetName = name;
}

void Key::slotSetAlphaNumSettings()
{

    alphaNumManager.displayMode = keyWindowForm->leddisplaymode->currentText();
    alphaNumManager.keyName = keyWindowForm->keyname->text();
    alphaNumManager.prefix = keyWindowForm->displayprefix->text();
}

void Key::slotCounter(QString whatToDo, int val)
{
    //qDebug() << keyInstance << whatToDo << val;

    bool wrap = keyWindowForm->counterWrap->isChecked();
    int min = keyWindowForm->counterMin->value();
    int max = keyWindowForm->counterMax->value();

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
