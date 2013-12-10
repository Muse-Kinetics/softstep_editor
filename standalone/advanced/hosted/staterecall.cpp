// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "staterecall.h"

StateRecall::StateRecall(QObject *parent) :
    QObject(parent)
{
    initGate = true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// Init / Preset Management ///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void StateRecall::slotInit(QList<QString> presetNames, int keyNumVal)
{
    if(initGate)
    {
        keyNum = keyNumVal;
        initGate = false;
        QList<MIDIPacket> tempInitPacketList = getInitMIDIPacketList();

        //Init state recallable params per preset
        for(int i = 0; i < presetNames.count(); i++)
        {
            //Counter
            counterState.insert(presetNames.at(i), 0);

            //Inc-Dec
            yIncDecState.insert(presetNames.at(i), 0);
            xIncDecState.insert(presetNames.at(i), 0);

            //Modlines
            for(int m = 0; m < 6; m++)
            {
                //Toggles
                toggleStates[m].insert(presetNames.at(i), false);

                //Led States in modline
                ledStates[m].insert(presetNames.at(i), false);
            }

            lastMidiPacketList.insert(presetNames.at(i), tempInitPacketList);
        }

        //qDebug() << "Key" << keyNumVal << "state recaller initialized.";
    }
}

void StateRecall::slotInitNewPreset(QString presetName)
{
    QList<MIDIPacket> tempInitPacketList = getInitMIDIPacketList();

    //Counter
    counterState.insert(presetName, 0);

    //Inc-Dec
    yIncDecState.insert(presetName, 0);
    xIncDecState.insert(presetName, 0);

    //Modlines
    for(int m = 0; m < 6; m++)
    {
        //Toggles
        toggleStates[m].insert(presetName, false);

        //Led States in modline
        ledStates[m].insert(presetName, false);
    }

    lastMidiPacketList.insert(presetName, tempInitPacketList);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////// Storage ////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void StateRecall::slotStoreToggleStates(int modlineNum, bool state)
{
    toggleStates[modlineNum].insert(presetName, state);
}

void StateRecall::slotStoreCounterState(int val)
{
    counterState.insert(presetName, val);
}

void StateRecall::slotStoreIncDecState(int x, int y)
{
    yIncDecState.insert(presetName, y);
    xIncDecState.insert(presetName, x);
}

void StateRecall::slotStoreLedStates(int modlineNum, bool state)
{
    ledStates[modlineNum].insert(presetName, state);
}

void StateRecall::slotStoreLedLastPacketList(QList<MIDIPacket> pktlst)
{
    lastMidiPacketList.insert(presetName, pktlst);
}

void StateRecall::slotStorePreviousKeyValueState(int val)
{
    previousKeyValueState.insert(presetName, val);
}

void StateRecall::slotStoreInitModeState(int modlineNum, bool called)
{
    initModeOnceCalledState[modlineNum].insert(presetName, called);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// Init / Preset Management ///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void StateRecall::slotRecallState(QString name)
{
    /*
    //Inc-Dec
    emit signalStateRecallYIncDec(yIncDecState.value(name));
    emit signalStateRecallXIncDec(xIncDecState.value(name));

    //Counter
    emit signalStateRecallCounter(counterState.value(name));

    for(int i = 0; i < 6; i++)
    {
        //Toggles
        //emit signalStateRecallToggles(i, toggleStates[i].value(name));

        //LEDs
        emit signalStateRecallLedStates(i, toggleStates[i].value(name));
    }

    emit signalStateRecallLedLastPacketList(lastMidiPacketList.value(name));*/
}

//------------------------------------------------------------------------------------------------------------------//
QList<MIDIPacket> StateRecall::getInitMIDIPacketList()
{
    //Led MidiPacket
    QList<MIDIPacket> initPacketList; //6 packets, 3 for red off, and 3 for green off

    //-------------------------------- Green
    MIDIPacket keyPacketGreen;
    keyPacketGreen.timeStamp = 0;
    keyPacketGreen.length = 3;

    //Key / LED referred to
    keyPacketGreen.data[0] = 176;
    keyPacketGreen.data[1] = 40;
    keyPacketGreen.data[2] = keyNum;

    initPacketList.append(keyPacketGreen);

    MIDIPacket colorPacketGreen;
    colorPacketGreen.timeStamp = 0;
    colorPacketGreen.length = 3;

    //Red or green?
    colorPacketGreen.data[0] = 176;
    colorPacketGreen.data[1] = 41;
    colorPacketGreen.data[2] = 0;

    initPacketList.append(colorPacketGreen);

    MIDIPacket typePacketGreen;
    typePacketGreen.timeStamp = 0;
    typePacketGreen.length = 3;

    //Led mode type
    typePacketGreen.data[0] = 176;
    typePacketGreen.data[1] = 42;
    typePacketGreen.data[2] = 0;

    initPacketList.append(typePacketGreen);


    //-------------------------------- Red
    MIDIPacket keyPacketRed;
    keyPacketRed.timeStamp = 0;
    keyPacketRed.length = 3;

    //Key / LED referred to
    keyPacketRed.data[0] = 176;
    keyPacketRed.data[1] = 40;
    keyPacketRed.data[2] = keyNum;

    initPacketList.append(keyPacketRed);

    MIDIPacket colorPacketRed;
    colorPacketRed.timeStamp = 0;
    colorPacketRed.length = 3;

    //Red or green?
    colorPacketRed.data[0] = 176;
    colorPacketRed.data[1] = 41;
    colorPacketRed.data[2] = 1;

    initPacketList.append(colorPacketRed);

    MIDIPacket typePacketRed;
    typePacketRed.timeStamp = 0;
    typePacketRed.length = 3;

    //Led mode type
    typePacketRed.data[0] = 176;
    typePacketRed.data[1] = 42;
    typePacketRed.data[2] = 0;

    initPacketList.append(typePacketRed);

    return initPacketList;
}
