// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "key.h"

Key::Key(QWidget *parent, int instanceNum) :
    QWidget(parent)
{
    instance = instanceNum;

    disableKeyEvent = false;

    this->setObjectName(QString("%1_Key").arg(instanceNum));

    //---------------------------------------- Set Up Ui
    QWidget *formWidget = new QWidget(this);

    keyForm.setupUi(formWidget);
    this->setFixedSize(157,157);

    keyForm.instanceLabel->setText(QString("%1").arg((instanceNum)%10));

    if(instanceNum < 6)
    {
        this->setGeometry(10 + ((instanceNum - 1)*167),177,157,157);
    }
    else
    {
        this->setGeometry(10 + ((instanceNum - 6)*167),10,157,157);
    }

    //---------------------------------------- Populate Checkbox list
    checkBoxes.append(keyForm.sourceNote);
    checkBoxes.append(keyForm.sourcePressure);
    checkBoxes.append(keyForm.sourceToggle);
    checkBoxes.append(keyForm.sourceXY);
    checkBoxes.append(keyForm.sourceYInc);
    checkBoxes.append(keyForm.sourceProgram);

    keyForm.name->setAttribute(Qt::WA_MacShowFocusRect, false);
    keyForm.noteNum->setAttribute(Qt::WA_MacShowFocusRect, false);
    keyForm.noteToggle->setAttribute(Qt::WA_MacShowFocusRect, false);
    keyForm.noteVelocity->setAttribute(Qt::WA_MacShowFocusRect, false);
    keyForm.pressureCC->setAttribute(Qt::WA_MacShowFocusRect, false);
    keyForm.pressureSmooth->setAttribute(Qt::WA_MacShowFocusRect, false);
    keyForm.toggleCC->setAttribute(Qt::WA_MacShowFocusRect, false);
    keyForm.toggleHi->setAttribute(Qt::WA_MacShowFocusRect, false);
    keyForm.toggleLo->setAttribute(Qt::WA_MacShowFocusRect, false);
    keyForm.xyLatch->setAttribute(Qt::WA_MacShowFocusRect, false);
    keyForm.xyXCC->setAttribute(Qt::WA_MacShowFocusRect, false);
    keyForm.xyYCC->setAttribute(Qt::WA_MacShowFocusRect, false);
    keyForm.yIncCC->setAttribute(Qt::WA_MacShowFocusRect, false);
    keyForm.yIncSpeed->setAttribute(Qt::WA_MacShowFocusRect, false);
    keyForm.programBank->setAttribute(Qt::WA_MacShowFocusRect, false);
    keyForm.programNum->setAttribute(Qt::WA_MacShowFocusRect, false);

    keyForm.yIncSpeed->hide();
    keyForm.yIncSpeedLabel->hide();

    //slotConnectElements();
}

void Key::keyPressEvent(QKeyEvent *keyEvent)
{
    if((keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return) && !disableKeyEvent)
    {
        //------------ Toggles
        if(keyForm.noteToggle->hasFocus())
        {
            keyForm.noteToggle->setChecked(!keyForm.noteToggle->isChecked());
        }
        else if(keyForm.xyLatch->hasFocus())
        {
            keyForm.xyLatch->setChecked(!keyForm.xyLatch->isChecked());
        }

        //------------ Checkboxes

        //MIDI Note
        else if(keyForm.sourceNote->hasFocus())
        {
            //Flip state
            keyForm.sourceNote->setChecked(!keyForm.sourceNote->isChecked());

            //Set Param Window, clear others if necessary
            if(keyForm.sourceNote->isChecked())
            {
                for(int i = 0; i < checkBoxes.count(); i++)
                {
                    if(keyForm.sourceNote != checkBoxes.at(i))
                    {
                        checkBoxes.at(i)->setChecked(false);
                    }
                    else
                    {
                        keyForm.sourcesParams->setCurrentIndex(i);
                    }
                }
            }
        }

        //Pressure
        else if(keyForm.sourcePressure->hasFocus())
        {
            keyForm.sourcePressure->setChecked(!keyForm.sourcePressure->isChecked());

            if(keyForm.sourcePressure->isChecked())
            {
                for(int i = 0; i < checkBoxes.count(); i++)
                {
                    if(keyForm.sourcePressure != checkBoxes.at(i))
                    {
                        checkBoxes.at(i)->setChecked(false);
                    }
                    else
                    {
                        keyForm.sourcesParams->setCurrentIndex(i);
                    }
                }
            }
        }

        //Toggle
        else if(keyForm.sourceToggle->hasFocus())
        {
            keyForm.sourceToggle->setChecked(!keyForm.sourceToggle->isChecked());

            if(keyForm.sourceToggle->isChecked())
            {
                for(int i = 0; i < checkBoxes.count(); i++)
                {
                    if(keyForm.sourceToggle != checkBoxes.at(i))
                    {
                        checkBoxes.at(i)->setChecked(false);
                    }
                    else
                    {
                        keyForm.sourcesParams->setCurrentIndex(i);
                    }
                }
            }
        }

        //XY
        else if(keyForm.sourceXY->hasFocus())
        {
            keyForm.sourceXY->setChecked(!keyForm.sourceXY->isChecked());

            if(keyForm.sourceXY->isChecked())
            {
                for(int i = 0; i < checkBoxes.count(); i++)
                {
                    if(keyForm.sourceXY != checkBoxes.at(i))
                    {
                        checkBoxes.at(i)->setChecked(false);
                    }
                    else
                    {
                        keyForm.sourcesParams->setCurrentIndex(i);
                    }
                }
            }
        }

        //YInc
        else if(keyForm.sourceYInc->hasFocus())
        {
            keyForm.sourceYInc->setChecked(!keyForm.sourceYInc->isChecked());

            if(keyForm.sourceYInc->isChecked())
            {
                for(int i = 0; i < checkBoxes.count(); i++)
                {
                    if(keyForm.sourceYInc != checkBoxes.at(i))
                    {
                        checkBoxes.at(i)->setChecked(false);
                    }
                    else
                    {
                        keyForm.sourcesParams->setCurrentIndex(i);
                    }
                }
            }
        }

        //Program
        else if(keyForm.sourceProgram->hasFocus())
        {
            keyForm.sourceProgram->setChecked(!keyForm.sourceProgram->isChecked());

            if(keyForm.sourceProgram->isChecked())
            {
                for(int i = 0; i < checkBoxes.count(); i++)
                {
                    if(keyForm.sourceProgram != checkBoxes.at(i))
                    {
                        checkBoxes.at(i)->setChecked(false);
                    }
                    else
                    {
                        keyForm.sourcesParams->setCurrentIndex(i);
                    }
                }
            }
        }

        //Update JSON
        slotValueChanged();
    }
}

bool Key::isKeyOff()
{
    for(int i = 0; i < checkBoxes.count(); i++)
    {
        if(checkBoxes.at(i)->isChecked())
        {
            return false;
        }
    }

    keyForm.sourcesParams->setCurrentIndex(6);
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////            /////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////    Slots   /////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////            /////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Key::slotConnectElements()
{
    //source
    for(int i = 0; i < checkBoxes.size(); i++)
    {
        connect(checkBoxes.at(i), SIGNAL(clicked()), this, SLOT(slotValueChanged()));
    }

    //name
    connect(keyForm.name, SIGNAL(textEdited(QString)), this, SLOT(slotValueChanged()));

    //noteNum
    connect(keyForm.noteNum, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));

    //noteVelocity
    connect(keyForm.noteVelocity, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));

    //noteToggle
    connect(keyForm.noteToggle, SIGNAL(clicked()), this, SLOT(slotValueChanged()));

    //pressureCC
    connect(keyForm.pressureCC, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));

    //pressureSmooth
    connect(keyForm.pressureSmooth, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));

    //toggleCC
    connect(keyForm.toggleCC, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));

    //toggleLo
    connect(keyForm.toggleLo, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));

    //toggleHi
    connect(keyForm.toggleHi, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));

    //xyXCC
    connect(keyForm.xyXCC, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));

    //xyYCC
    connect(keyForm.xyYCC, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));

    //xyLatch
    connect(keyForm.xyLatch, SIGNAL(clicked()), this, SLOT(slotValueChanged()));

    //YIncCC
    connect(keyForm.yIncCC, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));

    //YINc speed
    connect(keyForm.yIncSpeed, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));

    //programNum
    connect(keyForm.programNum, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));

    //programBank
    connect(keyForm.programBank, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));
}

void Key::slotValueChanged()
{

    qDebug() << "instance num" << instance;
    //############### This is a rather bloated way of doing things, could be optimzed by referencing component name/type and using fewer condidtions
    //############### though the app is small enough for it to barely make sense

    //---------------------------------------------------------------------------------------------------------------------//
    //-------------------------------------------------          UI         -----------------------------------------------//
    //---------------------------------------------------------------------------------------------------------------------//

    //If UIC was not manually altered by an event filter (only possible for source checkboxes)
    if(QObject::sender())
    {
        QObject *sender = QObject::sender();

        if(sender == keyForm.name)
        {
            emit signalStoreValue(QString("%1_key_name").arg(instance), keyForm.name->text(), -1);
        }

        //note
        else if(sender == keyForm.noteNum)
        {
            emit signalStoreValue(QString("%1_key_noteNum").arg(instance), keyForm.noteNum->value(), -1);
        }
        else if(sender == keyForm.noteVelocity)
        {
            emit signalStoreValue(QString("%1_key_noteVelocity").arg(instance), keyForm.noteVelocity->value(), -1);
        }
        else if(sender == keyForm.noteToggle)
        {
            emit signalStoreValue(QString("%1_key_noteToggle").arg(instance), int(keyForm.noteToggle->isChecked()), -1);
        }

        //pressure
        else if(sender == keyForm.pressureCC)
        {
            emit signalStoreValue(QString("%1_key_pressureCC").arg(instance), keyForm.pressureCC->value(), -1);
        }
        else if(sender == keyForm.pressureSmooth)
        {
            emit signalStoreValue(QString("%1_key_pressureSmooth").arg(instance), keyForm.pressureSmooth->value(), -1);
        }

        //toggle
        else if(sender == keyForm.toggleCC)
        {
            emit signalStoreValue(QString("%1_key_toggleCC").arg(instance), keyForm.toggleCC->value(), -1);
        }

        else if(sender == keyForm.toggleLo)
        {
            emit signalStoreValue(QString("%1_key_toggleLo").arg(instance), keyForm.toggleLo->value(), -1);
        }

        else if(sender == keyForm.toggleHi)
        {
            emit signalStoreValue(QString("%1_key_toggleHi").arg(instance), keyForm.toggleHi->value(), -1);
        }

        //xy
        else if (sender == keyForm.xyXCC)
        {
            emit signalStoreValue(QString("%1_key_xyXCC").arg(instance), keyForm.xyXCC->value(), -1);
        }
        else if(sender == keyForm.xyYCC)
        {
            emit signalStoreValue(QString("%1_key_xyYCC").arg(instance), keyForm.xyYCC->value(), -1);
        }
        else if(sender == keyForm.xyLatch)
        {
            emit signalStoreValue(QString("%1_key_xyLatch").arg(instance), int(keyForm.xyLatch->isChecked()), -1);
        }

        //yInc
        else if(sender == keyForm.yIncCC)
        {
            emit signalStoreValue(QString("%1_key_yIncCC").arg(instance), keyForm.yIncCC->value(), -1);
        }

        else if(sender == keyForm.yIncSpeed)
        {
            emit signalStoreValue(QString("%1_key_yIncSpeed").arg(instance), keyForm.yIncSpeed->value(), -1);
        }

        //program
        else if(sender == keyForm.programNum)
        {
            emit signalStoreValue(QString("%1_key_programNum").arg(instance), keyForm.programNum->value(), -1);
        }

        else if(sender == keyForm.programBank)
        {
            emit signalStoreValue(QString("%1_key_programBank").arg(instance), keyForm.programBank->value(), -1);
        }

        //----- Handle mutant radio button / checkboxes (radios w. all off state)
        else if(sender->objectName().contains("source"))
        {
            for(int i = 0; i < checkBoxes.count(); i++)
            {
                if(reinterpret_cast<QCheckBox *>(sender) != checkBoxes.at(i))
                {
                    checkBoxes.at(i)->setChecked(false);

                }
                else
                {
                    keyForm.sourcesParams->setCurrentIndex(i);
                }
            }
        }
    }



    //---------------------------------------------------------------------------------------------------------------------//
    //-------------------------------------------------  Source / Modlines  -----------------------------------------------//
    //---------------------------------------------------------------------------------------------------------------------//

    //Check if key is off
    if(isKeyOff())
    {
        emit signalStoreValue(QString("%1_key_source").arg(instance), "None", -1);

        //--------- Modlines
        //Source
        emit signalStoreValue(QString("%1_key_modline_source").arg(instance), "None", -1);
        emit signalStoreValue(QString("%1_key_modline2_source").arg(instance), "None", -1);

        //Dest
        emit signalStoreValue(QString("%1_key_modline_destination").arg(instance), "None", -1);
        emit signalStoreValue(QString("%1_key_modline2_destination").arg(instance), "None", -1);
    }
    else
    {
        //Store Check Boxes ############## may need to optimize here depending on UI response when editing rapidly ##########
        for(int i = 0; i < checkBoxes.count(); i++)
        {
            if(checkBoxes.at(i)->isChecked())
            {
                //emit source for ui
                emit signalStoreValue(QString("%1_key_source").arg(instance), checkBoxes.at(i)->objectName(), -1);

                //set modline params based on selected source

                //Note
                if(checkBoxes.at(i)->objectName() == "sourceNote")
                {
                    //--------- Modlines
                    //Source
                    emit signalStoreValue(QString("%1_key_modline_source").arg(instance), "Foot_On", -1);
                    emit signalStoreValue(QString("%1_key_modline2_source").arg(instance), "None", -1);

                    //Table
                    if(keyForm.noteToggle->isChecked())
                    {
                        emit signalStoreValue(QString("%1_key_modline_table").arg(instance), "Toggle_127", -1);
                    }
                    else
                    {
                        emit signalStoreValue(QString("%1_key_modline_table").arg(instance), "1_Lin", -1);
                    }

                    //Gain
                    emit signalStoreValue(QString("%1_key_modline_gain").arg(instance), 1.00f, -1);

                    //Min
                    emit signalStoreValue(QString("%1_key_modline_min").arg(instance), 0, -1);

                    //Max
                    emit signalStoreValue(QString("%1_key_modline_max").arg(instance), 127, -1);

                    //Slew
                    emit signalStoreValue(QString("%1_key_modline_slew").arg(instance), 0, -1);

                    //Dest
                    emit signalStoreValue(QString("%1_key_modline_destination").arg(instance), "Note_Set", -1);

                    //LED
                    emit signalStoreValue(QString("%1_key_led_green").arg(instance), "True", -1);
                }

                //Pressure
                else if(checkBoxes.at(i)->objectName() == "sourcePressure")
                {
                    //Source
                    emit signalStoreValue(QString("%1_key_modline_source").arg(instance), "Pressure_Live", -1);
                    emit signalStoreValue(QString("%1_key_modline2_source").arg(instance), "None", -1);

                    //Table
                    emit signalStoreValue(QString("%1_key_modline_table").arg(instance), "1_Lin", -1);

                    //Gain
                    emit signalStoreValue(QString("%1_key_modline_gain").arg(instance), 1.00, -1);

                    //Min
                    emit signalStoreValue(QString("%1_key_modline_min").arg(instance), 0, -1);

                    //Max
                    emit signalStoreValue(QString("%1_key_modline_max").arg(instance), 127, -1);

                    //Slew
                    emit signalStoreValue(QString("%1_key_modline_slew").arg(instance), keyForm.pressureSmooth->value(), -1);

                    //Dest
                    emit signalStoreValue(QString("%1_key_modline_destination").arg(instance), "CC", -1);

                    //CC#
                    emit signalStoreValue(QString("%1_key_modline_cc").arg(instance), keyForm.pressureCC->value(), -1);

                    //LED
                    emit signalStoreValue(QString("%1_key_led_green").arg(instance), "True", -1);
                }

                //Toggle
                else if(checkBoxes.at(i)->objectName() == "sourceToggle")
                {
                    //Source
                    emit signalStoreValue(QString("%1_key_modline_source").arg(instance), "Foot_On", -1);
                    emit signalStoreValue(QString("%1_key_modline2_source").arg(instance), "None", -1);

                    //Table
                    emit signalStoreValue(QString("%1_key_modline_table").arg(instance), "Toggle_127", -1);

                    //Gain
                    emit signalStoreValue(QString("%1_key_modline_gain").arg(instance), 1.00, -1);

                    //Min
                    emit signalStoreValue(QString("%1_key_modline_min").arg(instance), keyForm.toggleLo->value(), -1);

                    //Max
                    emit signalStoreValue(QString("%1_key_modline_max").arg(instance), keyForm.toggleHi->value(), -1);

                    //Slew
                    emit signalStoreValue(QString("%1_key_modline_slew").arg(instance), 0, -1);

                    //Dest
                    emit signalStoreValue(QString("%1_key_modline_destination").arg(instance), "CC", -1);

                    //CC#
                    emit signalStoreValue(QString("%1_key_modline_cc").arg(instance), keyForm.toggleCC->value(), -1);

                    //LED
                    emit signalStoreValue(QString("%1_key_led_green").arg(instance), "True", -1);
                }

                //XY
                else if(checkBoxes.at(i)->objectName() == "sourceXY")
                {
                    //Source
                    //Latch
                    if(keyForm.xyLatch->isChecked())
                    {
                        //X
                        if(keyForm.xyXCC->value() != -1)
                        {
                            emit signalStoreValue(QString("%1_key_modline_source").arg(instance), "X_Latch", -1);
                        }
                        else
                        {
                            emit signalStoreValue(QString("%1_key_modline_source").arg(instance), "None", -1);
                        }

                        //Y
                        if(keyForm.xyYCC->value() != -1)
                        {
                            emit signalStoreValue(QString("%1_key_modline2_source").arg(instance), "Y_Latch", -1);
                        }
                        else
                        {
                            emit signalStoreValue(QString("%1_key_modline2_source").arg(instance), "None", -1);
                        }
                    }

                    //Live
                    else
                    {
                        //X
                        if(keyForm.xyXCC->value() != -1)
                        {
                            emit signalStoreValue(QString("%1_key_modline_source").arg(instance), "X_Live", -1);
                        }
                        else
                        {
                            emit signalStoreValue(QString("%1_key_modline_source").arg(instance), "None", -1);
                        }

                        //Y
                        if(keyForm.xyYCC->value() != -1)
                        {
                            emit signalStoreValue(QString("%1_key_modline2_source").arg(instance), "Y_Live", -1);
                        }
                        else
                        {
                            emit signalStoreValue(QString("%1_key_modline2_source").arg(instance), "None", -1);
                        }
                    }

                    //Table
                    emit signalStoreValue(QString("%1_key_modline_table").arg(instance), "1_Lin", -1);

                    //Gain
                    emit signalStoreValue(QString("%1_key_modline_gain").arg(instance), 1.00, -1);

                    //Min
                    emit signalStoreValue(QString("%1_key_modline_min").arg(instance), 0, -1);
                    emit signalStoreValue(QString("%1_key_modline2_min").arg(instance), 0, -1);

                    //Max
                    emit signalStoreValue(QString("%1_key_modline_max").arg(instance), 127, -1);
                    emit signalStoreValue(QString("%1_key_modline2_max").arg(instance), 127, -1);

                    //Slew
                    emit signalStoreValue(QString("%1_key_modline_slew").arg(instance), 0, -1);

                    //Dest
                    emit signalStoreValue(QString("%1_key_modline_destination").arg(instance), "CC", -1);
                    emit signalStoreValue(QString("%1_key_modline2_destination").arg(instance), "CC", -1);

                    //CC#s
                    emit signalStoreValue(QString("%1_key_modline_cc").arg(instance), keyForm.xyXCC->value(), -1);
                    emit signalStoreValue(QString("%1_key_modline2_cc").arg(instance), keyForm.xyYCC->value(), -1);

                    //LED
                    emit signalStoreValue(QString("%1_key_led_green").arg(instance), "True", -1);
                }

                //Y Inc
                else if(checkBoxes.at(i)->objectName() == "sourceYInc")
                {
                    //Source
                    emit signalStoreValue(QString("%1_key_modline_source").arg(instance), "Y_Increment", -1);
                    emit signalStoreValue(QString("%1_key_modline2_source").arg(instance), "None", -1);

                    //Table
                    emit signalStoreValue(QString("%1_key_modline_table").arg(instance), "1_Lin", -1);

                    //Gain
                    emit signalStoreValue(QString("%1_key_modline_gain").arg(instance), 1.00, -1);

                    //Min
                    emit signalStoreValue(QString("%1_key_modline_min").arg(instance), 0, -1);

                    //Max
                    emit signalStoreValue(QString("%1_key_modline_max").arg(instance), 127, -1);

                    //Slew
                    emit signalStoreValue(QString("%1_key_modline_slew").arg(instance), 0, -1);

                    //Dest
                    emit signalStoreValue(QString("%1_key_modline_destination").arg(instance), "CC", -1);

                    //CC#
                    emit signalStoreValue(QString("%1_key_modline_cc").arg(instance), keyForm.yIncCC->value(), -1);

                    //Speed
                    emit signalStoreValue(QString("%1_key_setting_yAccel").arg(instance), keyForm.yIncSpeed->value(), -1);

                    //LED
                    emit signalStoreValue(QString("%1_key_led_green").arg(instance), "True", -1);

                }

                //Program
                else if(checkBoxes.at(i)->objectName() == "sourceProgram")
                {
                    //Modline 1: Bank, Modline 2: Program

                    //Source
                    emit signalStoreValue(QString("%1_key_modline_source").arg(instance), "Foot_On", -1);
                    emit signalStoreValue(QString("%1_key_modline2_source").arg(instance), "Foot_On", -1);

                    //Table
                    emit signalStoreValue(QString("%1_key_modline_table").arg(instance), "Toggle_127", -1);

                    //Gain
                    emit signalStoreValue(QString("%1_key_modline_gain").arg(instance), 1.00, -1);

                    //Min
                    emit signalStoreValue(QString("%1_key_modline_min").arg(instance), keyForm.programBank->value(), -1);
                    emit signalStoreValue(QString("%1_key_modline2_min").arg(instance), keyForm.programNum->value(), -1);

                    //Max
                    emit signalStoreValue(QString("%1_key_modline_max").arg(instance), keyForm.programBank->value(), -1);
                    emit signalStoreValue(QString("%1_key_modline2_max").arg(instance), keyForm.programNum->value(), -1);

                    //Slew
                    emit signalStoreValue(QString("%1_key_modline_slew").arg(instance), 0, -1);

                    //Dest
                    if(keyForm.programBank->value() != -1)
                    {
                        emit signalStoreValue(QString("%1_key_modline_destination").arg(instance), "Bank", -1);
                    }
                    else
                    {
                        emit signalStoreValue(QString("%1_key_modline_destination").arg(instance), "None", -1);
                    }

                    emit signalStoreValue(QString("%1_key_modline2_destination").arg(instance), "Program", -1);
                }

                break;
            }
        }
    }

    emit signalCheckSavedState();
}

void Key::slotRecallPreset(QVariantMap preset, QVariantMap master)
{
    //qDebug() << "--------------------------------------- recall preset - key:" << instance << preset.value(QString("%1_key_source").arg(instance)).toString();

    //Show/Hide Factory/Custom Preset
    if(!preset.value("useFactory").toString().contains("No"))
    {
        keyForm.name->setFocusPolicy(Qt::NoFocus);
        keyForm.noteNum->setFocusPolicy(Qt::NoFocus);
        keyForm.noteToggle->setFocusPolicy(Qt::NoFocus);
        keyForm.noteVelocity->setFocusPolicy(Qt::NoFocus);
        keyForm.pressureCC->setFocusPolicy(Qt::NoFocus);
        keyForm.pressureSmooth->setFocusPolicy(Qt::NoFocus);
        keyForm.toggleCC->setFocusPolicy(Qt::NoFocus);
        keyForm.toggleHi->setFocusPolicy(Qt::NoFocus);
        keyForm.toggleLo->setFocusPolicy(Qt::NoFocus);
        keyForm.xyLatch->setFocusPolicy(Qt::NoFocus);
        keyForm.xyXCC->setFocusPolicy(Qt::NoFocus);
        keyForm.xyYCC->setFocusPolicy(Qt::NoFocus);
        keyForm.yIncCC->setFocusPolicy(Qt::NoFocus);
        keyForm.yIncSpeed->setFocusPolicy(Qt::NoFocus);
        keyForm.programBank->setFocusPolicy(Qt::NoFocus);
        keyForm.programNum->setFocusPolicy(Qt::NoFocus);

        keyForm.yIncSpeed->hide();
        keyForm.yIncSpeedLabel->hide();

        for(int i =0; i < checkBoxes.size(); i++)
        {
            checkBoxes.at(i)->setFocusPolicy(Qt::NoFocus);
        }
    }
    else
    {
        for(int i =0; i < checkBoxes.size(); i++)
        {
            checkBoxes.at(i)->setFocusPolicy(Qt::StrongFocus);
        }

        keyForm.name->setFocusPolicy(Qt::StrongFocus);
        keyForm.noteNum->setFocusPolicy(Qt::StrongFocus);
        keyForm.noteToggle->setFocusPolicy(Qt::StrongFocus);
        keyForm.noteVelocity->setFocusPolicy(Qt::StrongFocus);
        keyForm.pressureCC->setFocusPolicy(Qt::StrongFocus);
        keyForm.pressureSmooth->setFocusPolicy(Qt::StrongFocus);
        keyForm.toggleCC->setFocusPolicy(Qt::StrongFocus);
        keyForm.toggleHi->setFocusPolicy(Qt::StrongFocus);
        keyForm.toggleLo->setFocusPolicy(Qt::StrongFocus);
        keyForm.xyLatch->setFocusPolicy(Qt::StrongFocus);
        keyForm.xyXCC->setFocusPolicy(Qt::StrongFocus);
        keyForm.xyYCC->setFocusPolicy(Qt::StrongFocus);
        keyForm.yIncCC->setFocusPolicy(Qt::StrongFocus);
        keyForm.yIncSpeed->setFocusPolicy(Qt::StrongFocus);
        keyForm.programBank->setFocusPolicy(Qt::StrongFocus);
        keyForm.programNum->setFocusPolicy(Qt::StrongFocus);

        keyForm.yIncSpeed->hide();
        keyForm.yIncSpeedLabel->hide();

    }

    //Sources
    for(int i =0; i < checkBoxes.size(); i++)
    {
        if(preset.value(QString("%1_key_source").arg(instance)).toString() == checkBoxes.at(i)->objectName())
        {
            checkBoxes.at(i)->setChecked(true);
            keyForm.sourcesParams->setCurrentIndex(i);
        }
        else
        {
            checkBoxes.at(i)->setChecked(false);
        }
    }

    isKeyOff();

    //Name
    keyForm.name->setText(preset.value(QString("%1_key_name").arg(instance)).toString());

    //Note
    keyForm.noteNum->setValue(preset.value(QString("%1_key_noteNum").arg(instance)).toInt());
    keyForm.noteVelocity->setValue(preset.value(QString("%1_key_noteVelocity").arg(instance)).toInt());
    keyForm.noteToggle->setChecked(preset.value(QString("%1_key_noteToggle").arg(instance)).toBool());

    //Pressure
    keyForm.pressureCC->setValue(preset.value(QString("%1_key_pressureCC").arg(instance)).toInt());
    keyForm.pressureSmooth->setValue(preset.value(QString("%1_key_pressureSmooth").arg(instance)).toInt());

    //Toggle
    keyForm.toggleCC->setValue(preset.value(QString("%1_key_toggleCC").arg(instance)).toInt());
    keyForm.toggleLo->setValue(preset.value(QString("%1_key_toggleLo").arg(instance)).toInt());
    keyForm.toggleHi->setValue(preset.value(QString("%1_key_toggleHi").arg(instance)).toInt());

    //XY
    keyForm.xyXCC->setValue(preset.value(QString("%1_key_xyXCC").arg(instance)).toInt());
    keyForm.xyYCC->setValue(preset.value(QString("%1_key_xyYCC").arg(instance)).toInt());
    keyForm.xyLatch->setChecked(preset.value(QString("%1_key_xyLatch").arg(instance)).toBool());

    //YInc
    keyForm.yIncCC->setValue(preset.value(QString("%1_key_yIncCC").arg(instance)).toInt());
    keyForm.yIncSpeed->setValue(preset.value(QString("%1_key_yIncSpeed").arg(instance)).toInt());

    //Program
    keyForm.programNum->setValue(preset.value(QString("%1_key_programNum").arg(instance)).toInt());
    keyForm.programBank->setValue(preset.value(QString("%1_key_programBank").arg(instance)).toInt());
}

void Key::slotEnableDisableKeyEvents(bool state)
{
    disableKeyEvent = state;
}

