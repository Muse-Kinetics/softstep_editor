// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "mididevicemanager.h"
#include "sysexmessages.h"

#ifdef Q_OS_MAC
MidiDeviceManager *callbackClassPointer;
void midiSystemChanged(const MIDINotification *message, void *refCon);                                  //Called when the system's MIDI has changed
void incomingMidi(const MIDIPacketList *pktlist, void *readProcRefCon, void *srcConnRefCon);            //Called upon incoming midi from connected port (SSCOM)
void sysExComplete(MIDISysexSendRequest*);                                                              //Called when sysex event has been completely sent
void midiInputIncomingMidi(const MIDIPacketList *pktlist, void *readProcRefCon, void *srcConnRefCon);   //Midi input from settings' input

MIDIEndpointRef* midiInputSourcePointers;

MidiDeviceManager::MidiDeviceManager(QWidget *parent) :
    QWidget(parent)
{
//    ioGate = true;

//    mode = "standalone";

//    sysexFIFOClock = new QTimer(this);
//    connect(sysexFIFOClock, SIGNAL(timeout()), this, SLOT(slotDrainSysexFIFO()));

//    fwUpdateRequested = false;
//    callbackClassPointer = this;
//    createAppMidiClient();

    calibrationPhase = "complete";

    //connect(&midiFormatOutput, SIGNAL(signalSendMidiPacketList(QString, MIDIPacket)), this, SLOT(hosted_slotSendPacket(QString,MIDIPacket)));
}

//void MidiDeviceManager::createAppMidiClient()
//{
//    MIDIClientCreate(CFSTR("SoftStep MIDI Client"), midiSystemChanged, this, &appClientRef);
//    MIDIInputPortCreate(appClientRef, CFSTR("SoftStep MIDI Client In Port"), incomingMidi, this, &appInPortRef);
//    MIDIOutputPortCreate(appClientRef, CFSTR("SoftStep MIDI Client Out Port"), &appOutPortRef);
//}

//bool MidiDeviceManager::connectSource()
//{
//    if(getSource() != -1)
//    {
//        //qDebug() << "connect source called";
//        //Connect Source
//        MIDIEndpointRef endpointRef = MIDIGetSource(getSource());
//        MIDIPortConnectSource(appInPortRef, endpointRef, &endpointRef);
//        //qDebug() << "Source Connected: " << sourceName;

//        queryReplied = false;
//        slotSendSysEx("deviceQuery", _fw_query_syx_softstep, 67, "SSCOM Port 1");
//        return true;
//    }
//    else
//    {
//        emit signalConnected(false);
//        return false;
//    }
//}

//void MidiDeviceManager::slotSetMode(QString m)
//{
//    mode = m;

//    //qDebug() << "slot set mode";

//    if(mode == "hosted")
//    {
//        //Virtual Source Creation "SoftStep Share"
//        MIDISourceCreate(appClientRef, CFSTR("SoftStep Share"), &appVirtualSourceRef);

//        //hosted_slotRepopulateMidiSourceDests called here because new port is created

//        //Create entirely new port for external midi inputs
//        MIDIInputPortCreate(appClientRef, CFSTR("SoftStep External MIDI In Port"), midiInputIncomingMidi, this, &midiInputPort);
//        //hosted_slotConnectExternalMidiInputSources();

//        slotHostedOnOff(true);
//    }
//    else
//    {
//        MIDIEndpointDispose(appVirtualSourceRef);
//        MIDIEndpointDispose(appVirtualDestRef);

//        //Delete external midi input port
//        MIDIPortDispose(midiInputPort);

//        slotHostedOnOff(false);
//    }
//}

//int MidiDeviceManager::getSource()
//{
//    //Returns index of first instance of SSCOM Port 1
//    for(unsigned int i=0; i<MIDIGetNumberOfSources(); i++)
//    {
//        if(getDisplayName(MIDIGetSource(i)).contains("SSCOM") && getDisplayName(MIDIGetSource(i)).contains("1"))
//        {
//            return i;
//        }
//    }

//    return -1;
//}

//int MidiDeviceManager::getDestination()
//{
//    //Returns index of first instance of SSCOM Port 1
//    for(unsigned int i=0; i<MIDIGetNumberOfDestinations(); i++)
//    {

//        //qDebug() << "destination namE" << getDisplayName(MIDIGetDestination(i)) << i;

//        if(getDisplayName(MIDIGetDestination(i)).contains("SSCOM") && getDisplayName(MIDIGetDestination(i)).contains("1"))
//        {
//            sscomPort1DestRef = MIDIGetDestination(i);
//            return i;
//        }
//    }

//    return -1;
//}

//void MidiDeviceManager::slotHostedOnOff(bool onOff)
//{
//    //FIFO necessary because firmware requires delay between messages
//    if(!onOff)
//    {
//        //mode = "standalone";

//        sysexFIFOClock->stop();
//        sysexFIFOsQueue.clear();


//        sysexFIFOsQueue.append(_fw_tether_off);
//        sysexFIFOsQueue.append(_fw_standalone_on);
//        //sysexFIFOsQueue.append(_fw_scenechange_on_persist); -- Handled by settings now
//        sysexFIFOsQueue.append(_fw_nav_standalone_on_persist);
//        sysexFIFOsQueue.append(_fw_nav_standalone_on);


//        //sysexFIFOsQueue.append(_fw_tether_off);
//        //sysexFIFOsQueue.append(_fw_nav_tether_off);
//        //sysexFIFOsQueue.append(_fw_standalone_on);


//        sysexFIFOClock->start(100);
//    }
//    else
//    {
//        //mode = "hosted";

//        sysexFIFOClock->stop();
//        sysexFIFOsQueue.clear();

//        sysexFIFOsQueue.append(_fw_scenechange_on_persist);
//        sysexFIFOsQueue.append(_fw_nav_standalone_on_persist);
//        sysexFIFOsQueue.append(_fw_tether_on);
//        sysexFIFOsQueue.append(_fw_standalone_off);
//        sysexFIFOsQueue.append(_fw_nav_standalone_off);


//        //sysexFIFOsQueue.append(_fw_tether_on);
//        //sysexFIFOsQueue.append(_fw_nav_tether_on);
//        //sysexFIFOsQueue.append(_fw_standalone_off);


//        sysexFIFOClock->start(100);
//    }
//}

//void MidiDeviceManager::slotSceneChangeOnOff(bool onOff)
//{
//    //qDebug() << "scene change on/off";

//    if(onOff)
//    {
//        sysexFIFOsQueue.append(_fw_tether_off);
//        sysexFIFOsQueue.append(_fw_standalone_on);
//        sysexFIFOsQueue.append(_fw_scenechange_on_persist);
//        sysexFIFOsQueue.append(_fw_nav_standalone_on_persist);
//        sysexFIFOsQueue.append(_fw_nav_standalone_on);

//    }
//    else
//    {
//        sysexFIFOsQueue.append(_fw_tether_off);
//        sysexFIFOsQueue.append(_fw_standalone_on);
//        sysexFIFOsQueue.append(_fw_scenechange_off_persist);
//        sysexFIFOsQueue.append(_fw_nav_standalone_on_persist);
//        sysexFIFOsQueue.append(_fw_nav_standalone_on);

//    }

//    if(!sysexFIFOClock->isActive())
//    {
//        sysexFIFOClock->start(100);
//    }
//}

//void MidiDeviceManager::slotBackLightOnOff(bool onOff)
//{
//    if(onOff)
//    {
//        sysexFIFOsQueue.append(_backlight_on);
//    }
//    else
//    {
//        sysexFIFOsQueue.append(_backlight_off);
//    }

//    if(!sysexFIFOClock->isActive())
//    {
//        sysexFIFOClock->start(100);
//    }
//}

//void MidiDeviceManager::slotTetherOnOffInStandalone(bool onOff)
//{

//    //---- !!!! This function only used for pedal calibration !!! ----//

//    //Turn tether on during calibration
//    if(onOff)
//    {
//        calibrationPhase = "start";

//        sysexFIFOClock->stop();
//        sysexFIFOsQueue.clear();

//        sysexFIFOsQueue.append(_fw_scenechange_on_persist);
//        sysexFIFOsQueue.append(_fw_tether_on);
//        sysexFIFOsQueue.append(_fw_standalone_off);
//        sysexFIFOsQueue.append(_fw_nav_standalone_off);

//        sysexFIFOClock->start(100);

//        //Cue calibration start
//        emit signalStartStandaloneCalibration();
//    }

//    //Turn thether off at end of calibration
//    else
//    {
//        calibrationPhase = "stop";

//        sysexFIFOClock->stop();
//        sysexFIFOsQueue.clear();

//        sysexFIFOsQueue.append(_fw_tether_off);
//        sysexFIFOsQueue.append(_fw_standalone_on);
//        sysexFIFOsQueue.append(_fw_nav_standalone_on_persist);
//        sysexFIFOsQueue.append(_fw_nav_standalone_on);

//        sysexFIFOClock->start(100);

//    }
//}

//void MidiDeviceManager::slotUpdateFirmware()
//{
//    //qDebug() << "Send the firmware" << firmwareByteArray;
//    emit signalProgressDialog("setup", firmwareByteArray.size());
//    //slotSendSysEx(firmwareByteArray, "QuNexus Port 1");
//}


////////////////////////////////////////////////////////
///////////////// Helper Funcitons /////////////////////
////////////////////////////////////////////////////////
//QString MidiDeviceManager::getDisplayName(MIDIObjectRef object)
//{
//    // Returns the display name of a given MIDIObjectRef as an NSString
//    CFStringRef name = nil; //place holder for name

//    if(noErr != MIDIObjectGetStringProperty(object, kMIDIPropertyDisplayName, &name))
//    {//get the name using midi services function
//        return nil;
//    }

//    return QString(cFStringRefToQString(name)); //return the name
//}

//QString MidiDeviceManager::cFStringRefToQString(CFStringRef ref)
//{
//    //this function just translates a CFStringRef into a QString
//    CFRange range;
//    range.location = 0;
//    range.length = CFStringGetLength(ref);
//    QString result(range.length, QChar(0));

//    UniChar *chars = new UniChar[range.length];
//    CFStringGetCharacters(ref, range, chars);
//    //[nsstr getCharacters:chars range:range];
//    result = QString::fromUtf16(chars, range.length);
//    delete[] chars;
//    return result;
//}

//void MidiDeviceManager::slotDrainSysexFIFO()
//{
//    //If anything in list, send the next message
//    if(sysexFIFOsQueue.size())
//    {
//        //Backlighting are the only 35 byte messages we send so far
//        if(_backlight_on == sysexFIFOsQueue.first() || _backlight_off == sysexFIFOsQueue.first())
//        {
//            slotSendSysEx("message", sysexFIFOsQueue.first(), 35, "SSCOM Port 1");
//        }
//        else
//        {
//            slotSendSysEx("message", sysexFIFOsQueue.first(), 43, "SSCOM Port 1");
//        }

//        sysexFIFOsQueue.removeFirst();
//    }

//    //Otherwise stop calling function
//    else
//    {
//        sysexFIFOClock->stop();

//        if(calibrationPhase != "complete")
//        {
//            if(calibrationPhase == "start")
//            {
//                emit signalStartStandaloneCalibration();
//            }
//            else
//            {
//                emit signalStopStandaloneCalibration();
//            }
//        }
//    }
//}

//void MidiDeviceManager::slotSendSysEx(QString messageID, unsigned char* bytes, int len, QString destinationName)
//{

//    //qDebug() << "slsotSendSysEx" << messageID;

//    if(getDestination() > -1)
//    {

//        int dest = getDestination();
//        //Creat char array to hold sysex bytes
//        //unsigned char* sysExCharData = new unsigned char(sysExMessageByteArray.size());

//        //Assign bytes to char array
//        //sysExCharData = (unsigned char*)sysExMessageByteArray.data();

//        //Create new sysex event/request
//        MIDISysexSendRequest* sysExMsgReq = new MIDISysexSendRequest;

//        //Set the message's fields
//        sysExMsgReq->destination = MIDIGetDestination(dest);
//        sysExMsgReq->data = (const Byte *)bytes;
//        sysExMsgReq->bytesToSend = len;
//        sysExMsgReq->complete = false;
//        sysExMsgReq->completionProc = &sysExComplete;
//        sysExMsgReq->completionRefCon = bytes;

//        //Send the message
//        MIDISendSysex(sysExMsgReq);

//        //Wait for entire message to be sent
//        int bytes = -1;

//        while(!sysExMsgReq->complete)
//        {
//            QApplication::processEvents();

//            if(bytes != (long)sysExMsgReq->bytesToSend)
//            {
//                bytes = sysExMsgReq->bytesToSend;

//                if(messageID == "update firmware")
//                {
//                    emit signalFwBytesLeft(sysExMsgReq->bytesToSend);
//                }
//            }
//            //qDebug() << "sysEx msg bytes left:" << bytes;
//        }

//        if(messageID == "presets image")
//        {
//            qDebug() << "MDM -- Presets sent";
//            emit signalPresetsSent();
//        }

//        if(messageID == "settings image")
//        {
//            qDebug() << "MDM -- Settings sent";
//            emit signalSettingsSent();
//        }

//    }
//    else
//    {
//        qDebug() << "WARNING: Send SysEx Matching Destination: " << destinationName << " NOT Found.";
//    }
//}

//void MidiDeviceManager::slotProcessSysEx(QByteArray sysExMessageByteArray)
//{
//    //qDebug() << "sysex length" << sysExMessageByteArray.count();

//    //---------- PRE v76 reply
//    if(sysExMessageByteArray.indexOf(QByteArray((const char*)_fw_query_reply_header, 4)) == 2 && sysExMessageByteArray.size() == 91 && !queryReplied)
//    {
//        //qDebug() << "Got the reply" << sysExMessageByteArray.count();
//        queryReplied = true;

//        //qDebug() << foundBootloaderVersion;
//        //qDebug() << foundFirmwwareVersion;
//        //qDebug() << expectedBootloaderVersion;
//        //qDebug() << expectedFirmwareVersion;

//        //emit signalFirmwareOutOfDate(expectedBootloaderVersion,foundBootloaderVersion,expectedFirmwareVersion,foundFirmwwareVersion);
//        emit signalProcessFwQueryReply(sysExMessageByteArray);
//    }

//    //---------- POST v76 reply
//    else if(sysExMessageByteArray.indexOf(QByteArray((const char*)_fw_query_reply_header, 4)) == 2 && sysExMessageByteArray.size() == 128 && !queryReplied)
//    {
//        for(int i = 0; i < sysExMessageByteArray.size(); i++)
//        {
//            int x = (uint)sysExMessageByteArray.at(i);
//            QString xAsHex = QString("0x%1").arg(x, 0, 16);
//            //qDebug() << xAsHex;
//        }

//        queryReplied = true;

//        emit signalProcessFwQueryReply(sysExMessageByteArray);

//    }

//    //If a query was sent and we got a bad reply
//    else if(!queryReplied)
//    {
//        slotSendSysEx("deviceQuery", _fw_query_syx_softstep, 67, "SSCOM Port 1");
//    }
//}


////------------------------------------------------------ Hosted
//void MidiDeviceManager::hosted_slotParsePacket(const MIDIPacket * packet)
//{
//    //Sends raw packet to be parsed from SSCOM Port 1
//    emit hosted_signalParsePacket(packet);
//}

//void MidiDeviceManager::hosted_slotSendPacket(QString port, MIDIPacket packet)
//{
//    //Semds Packet to external dest
//    //qDebug() << "hosted_slotSendPacketCalled - data:" << packet.data[0] << packet.data[1] << packet.data[2] << "length, time : " << packet.length << packet.timeStamp << "\n";

//    //Packet Size max size
//    Byte packetListSize[256];

//    //Allocates bytes, sets size of total packetlist
//    MIDIPacketList* packetList = (MIDIPacketList*)packetListSize;

//    //Initialize packet
//    MIDIPacket* pkt = MIDIPacketListInit(packetList); //Init midi packet

//    //Add new packet to list
//    MIDIPacketListAdd(packetList, 256, pkt, 0, packet.length, packet.data);

//    //---------------------------- Send packet to virtual source

//    if(port == "SoftStep Share")
//    {
//        MIDIReceived(appVirtualSourceRef, packetList);
//    }
//    else if(port.contains("SSCOM") && port.contains("1"))
//    {
//        //qDebug() << "send message to SSCOM1";
//        MIDISend(appOutPortRef, sscomPort1DestRef, packetList);
//    }
//    else
//    {
//        MIDISend(appOutPortRef, externalDests.value(port), packetList);
//    }

//}

//void MidiDeviceManager::hosted_slotRepopulateMidiSourceDests()
//{
//    //Called when midi system changes, automaticall called on hosted to standlaone/switch because of "SoftStep Share"

//    //----------------------- Get non SSCOM sources
//    midiInputSources.clear();

//    for(unsigned int i=0; i<MIDIGetNumberOfSources(); i++)
//    {
//        //Allocate new array of endpoint pointers for passing as refcon
//        midiInputSourcePointers = new MIDIEndpointRef[MIDIGetNumberOfSources()];

//        //Expander
//        if(getDisplayName(MIDIGetSource(i)).contains("SSCOM") && getDisplayName(MIDIGetSource(i)).contains("2"))
//        {
//            midiInputSources.insert("SoftStep Expander", MIDIGetSource(i));

//            //Insert MIDIEndpointRef into array
//            //midiInputSourcePointers[i] = MIDIGetSource(i);
//        }

//        if(!getDisplayName(MIDIGetSource(i)).contains("SSCOM") && !getDisplayName(MIDIGetSource(i)).contains("SoftStep Share"))
//        {
//            //qDebug() << "Non-SoftStep Source: " << getDisplayName(MIDIGetSource(i));

//            //Store name of midi input source and it's endpoint ref
//            midiInputSources.insert(getDisplayName(MIDIGetSource(i)), MIDIGetSource(i));

//            //Insert MIDIEndpointRef into array
//            //midiInputSourcePointers[i] = MIDIGetSource(i);
//        }
//    }

//    //Sends sources to midi input in settings page, connected in mainwindow
//    emit hosted_signalMidiInputSourceMenus(midiInputSources);

//    //----------------------- Get non SSCOM destinations
//    externalDests.clear();

//    //Make sure SoftStep Share is in there but points to nothing
//    externalDests.insert("SoftStep Share", 0);

//    for(unsigned int i=0; i<MIDIGetNumberOfDestinations(); i++)
//    {
//        ///qDebug() << "Destinations: " << getDisplayName(MIDIGetSource(i));

//        if(!getDisplayName(MIDIGetDestination(i)).contains("SSCOM Port 1") && !getDisplayName(MIDIGetDestination(i)).contains("SoftStep Share"))
//        {
//            if(getDisplayName(MIDIGetDestination(i)).contains("SSCOM Port 2"))
//            {
//                //We would like port 2 to be named SoftStep Expander
//                externalDests.insert("SoftStep Expander", MIDIGetDestination(i));
//            }
//            else
//            {
//                //Store name of dest and it's endpoint ref
//                externalDests.insert(getDisplayName(MIDIGetDestination(i)), MIDIGetDestination(i));
//            }
//            //qDebug() << "Non-SoftStep Destination: " << getDisplayName(MIDIGetDestination(i));
//        }
//    }

//    //qDebug() << "Modline Device Menus:" << externalDests.keys();

//    //Sneds destinations to device menus in modlines
//    emit hosted_signalPopulateDeviceMenus(externalDests);
//}

//void MidiDeviceManager::hosted_slotParseMidiInputPacket(const MIDIPacket *packet, QString deviceName)
//{
//    //Sends raw packet to be parsed from SSCOM Port 1
//    emit hosted_signalParseMidiInputPacket(packet, deviceName);
//}

//void MidiDeviceManager::hosted_slotConnectExternalMidiInputSources()
//{
//    //er = midiInputSources.value(getDisplayName(MIDIGetSource(0)));

//    for(unsigned int i=0; i<MIDIGetNumberOfSources(); i++)
//    {
//        if(getDisplayName(MIDIGetSource(i)).contains("SSCOM") && getDisplayName(MIDIGetSource(i)).contains("1"))
//        {
//            //Filter out SSCOM Port 1 and
//        }
//        else
//        {
//            //midiInputSources.value(getDisplayName(MIDIGetSource(i)));

//            //MIDIEndpointRef* epr = &midiInputSourcePointers[i];

//            midiInputSourcePointers[i] = MIDIGetSource(i);

//            //qDebug() << "----------------------------" << "slot connect external midi sources" << getDisplayName(MIDIGetSource(i)) << midiInputSourcePointers[i];

//            MIDIPortConnectSource(midiInputPort, MIDIGetSource(i), (void*)&midiInputSourcePointers[i]);
//        }
//    }
//}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////       Callbacks       /////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//void midiSystemChanged(const MIDINotification *message, void *refCon)
//{
//    Q_UNUSED(refCon);

//    //------------------------------------------- this function needs optimization, too many calls to repopulate menus, but will do for now
//    bool repopulateMidiSourceDests = false;

//    if(message->messageID == kMIDIMsgObjectAdded)
//    {
//        //qDebug() << "object added";

//        MIDIObjectAddRemoveNotification *msg = (MIDIObjectAddRemoveNotification *)message;

//        //If object added is a source...
//        if(msg->childType == kMIDIObjectType_Source)
//        {
//            if(callbackClassPointer->getDisplayName(msg->child).contains("SSCOM") && callbackClassPointer->getDisplayName(msg->child).contains("1"))
//            {
//                callbackClassPointer->connectSource();
//            }

//            //Non softstep source added
//            if(!callbackClassPointer->getDisplayName(msg->child).contains("SSCOM"))
//            {
//                //qDebug() << "non-softstep source added";
//                repopulateMidiSourceDests = true;
//            }
//        }

//        if(msg->childType == kMIDIObjectType_Destination)
//        {

//            //Non softstep destination removed
//            if(!callbackClassPointer->getDisplayName(msg->child).contains("SSCOM"))
//            {
//                //qDebug() << "non-softstep destination added";
//                repopulateMidiSourceDests = true;
//            }
//        }
//    }

//    else if(message->messageID == kMIDIMsgObjectRemoved)
//    {
//        MIDIObjectAddRemoveNotification *msg = (MIDIObjectAddRemoveNotification *)message;

//        if(msg->childType == kMIDIObjectType_Source)
//        {
//            if(callbackClassPointer->getDisplayName(msg->child).contains("SSCOM") && callbackClassPointer->getDisplayName(msg->child).contains("1"))
//            {
//                callbackClassPointer->connectSource();
//            }

//            //Non softstep source removed
//            if(!callbackClassPointer->getDisplayName(msg->child).contains("SSCOM"))
//            {
//                //qDebug() << "non-softstep source removed";
//                repopulateMidiSourceDests = true;
//            }
//        }

//        if(msg->childType == kMIDIObjectType_Destination)
//        {
//            //Non softstep destination removed
//            if(!callbackClassPointer->getDisplayName(msg->child).contains("SSCOM"))
//            {
//                //qDebug() << "non-softstep destination removed";
//                repopulateMidiSourceDests = true;
//            }
//        }
//    }
//    else if(message->messageID == kMIDIMsgSetupChanged)
//    {
//        // MIDIObjectAddRemoveNotification *msg = (MIDIObjectAddRemoveNotification *)message;
//        //qDebug() << "midi setup changed" << message->messageID << msg->childType << callbackClassPointer->getDisplayName(msg->child);
//        repopulateMidiSourceDests = true;
//    }

//    //If midi system changed (not including softstep)
//    if(repopulateMidiSourceDests)
//    {
//        callbackClassPointer->hosted_slotRepopulateMidiSourceDests();
//        callbackClassPointer->hosted_slotConnectExternalMidiInputSources();
//    }
//}

//void incomingMidi(const MIDIPacketList *pktlist, void *readProcRefCon, void *srcConnRefCon){

//    Q_UNUSED(readProcRefCon);
//    Q_UNUSED(srcConnRefCon);

//    if(callbackClassPointer->ioGate)
//    {
//        //qDebug() << "incoming midi";
//        //iterate through midi packets and process according to type
//        const MIDIPacket *packet = &pktlist->packet[0];

//        //for number packets in packet list
//        for(unsigned int i =0; i < pktlist->numPackets; i++)
//        {

//            //for length of packet
//            for(int j = 0; j < packet->length; j++)
//            {
//                //If a SysEx Start Byte, set filter switch
//                if(packet->data[j] == 240)
//                {
//                    callbackClassPointer->isSysEx = true;
//                }

//                //If a SysEx End Byte, set filter switch off and send last bytes
//                else if (packet->data[j] == 247)
//                {
//                    callbackClassPointer->isSysEx = false;
//                    callbackClassPointer->sysExMessage.append(packet->data[j]);
//                    //qDebug() << "----- SysEx In ----- :" << packet->data[j];

//                    callbackClassPointer->slotProcessSysEx(callbackClassPointer->sysExMessage);
//                    callbackClassPointer->sysExMessage.clear();
//                }

//                //Processes SysEx
//                if(callbackClassPointer->isSysEx)
//                {
//                    callbackClassPointer->sysExMessage.append(packet->data[j]);
//                    //qDebug() << "----- SysEx In ----- :" << packet->data[j];
//                }

//                else if(packet->data[j] != 247)
//                {
//                    //qDebug() << "MIDI Channel Event: " << packet->data[j];
//                    if(callbackClassPointer->mode == "hosted")
//                    {
//                        //qDebug() << i;
//                        callbackClassPointer->hosted_slotParsePacket(packet);
//                        break;
//                    }
//                    else if(callbackClassPointer->mode == "standalone" && callbackClassPointer->calibrationPhase != "complete")
//                    {
//                        callbackClassPointer->hosted_slotParsePacket(packet);
//                        break;
//                    }
//                }
//            }

//            //advance packet in midi packet list
//            packet = MIDIPacketNext(packet);
//        }
//    }
//}

//void midiInputIncomingMidi(const MIDIPacketList *pktlist, void *readProcRefCon, void *srcConnRefCon)
//{
//    Q_UNUSED(readProcRefCon);

//    if(callbackClassPointer->ioGate)
//    {
//        //Receives midi from SoftStep Share
//        MIDIEndpointRef* epr = (MIDIEndpointRef*)srcConnRefCon;

//        //iterate through midi packets and process according to type
//        const MIDIPacket *packet = &pktlist->packet[0];

//        //for number packets in packet list
//        for(unsigned int i =0; i < pktlist->numPackets; i++)
//        {
//            //for length of packet
//            for(int j = 0; j < packet->length; j++)
//            {
//                //qDebug() << "Extermal MIDI Channel Event: " << packet->data[j] << callbackClassPointer->getDisplayName(*epr);// << *string;
//            }

//            //emit pack to be parsed by midi input
//            callbackClassPointer->hosted_slotParseMidiInputPacket(packet, callbackClassPointer->getDisplayName(*epr));

//            //advance packet in midi packet list
//            packet = MIDIPacketNext(packet);
//        }
//    }
//}

//void sysExComplete(MIDISysexSendRequest* request)
//{
//    Q_UNUSED(request);

//    //qDebug() << "Sys Ex Sent";
//}
//#else

//MidiDeviceManager::MidiDeviceManager(QWidget *parent) :
//    QWidget(parent)
//{
//    ioGate = true;

//    fwUpdateRequested = false;

//    numDevices = 0;

//    sysExType = "None";
//    globals.clear();

//    //qDebug() <<"ERROR" << MMSYSERR_ALLOCATED;

//    inHandle = NULL;
//    outHandle = NULL;
//    connected = false;
//    refreshDevices = true;

//    sysexFIFOClock = new QTimer(this);
//    connect(sysexFIFOClock, SIGNAL(timeout()), this, SLOT(slotDrainSysexFIFO()));

//    connect(&midiFormatOutput, SIGNAL(signalSendMidiPacketList(QString, MIDIPacket)), this, SLOT(hosted_slotSendPacket(QString,MIDIPacket)));

//    //------------------------------- Polling

//    //Devices
//    devicePoller = new QTimer(this);
//    connect(devicePoller, SIGNAL(timeout()), this, SLOT(slotPollDevices()));
//    //devicePoller->start(1);

//    //Version
//    versionPoller = new QTimer(this);
//    connect(versionPoller, SIGNAL(timeout()), this, SLOT(slotPollVersion()));
//    versionReply = false;
//    queryReplied = false;

//    calibrationPhase = "complete";
//}

//bool MidiDeviceManager::connectSource()
//{
//    if(getSource() != -1)
//    {
//        //Connect Source
//        slotCloseMidiIn();
//        slotCloseMidiOut();
//        slotOpenMidiIn(getSource());
//        slotOpenMidiOut(getDestination());
//        queryReplied = false;
//        versionReply = false;
//        versionPoller->start(500);
//        return true;
//    }
//    else
//    {
//        slotCloseMidiIn();
//        slotCloseMidiOut();
//        emit signalConnected(false);
//        return false;
//    }
//}

//void MidiDeviceManager::slotOpenMidiIn(int index){

//    DWORD   err;

//    // Is it not yet open?
//    if (!inHandle)
//    {
//        /* Open MIDI Input and set Windows to call my
//          midiInputEvt() callback function. You may prefer
//          to have something other than CALLBACK_FUNCTION. Also,
//          I open device 0. You may want to give the user a choice */
//        if (!(err = midiInOpen(&inHandle, index, (DWORD_PTR)MidiDeviceManager::midiInCallback, (DWORD_PTR)this, CALLBACK_FUNCTION)))
//        {
//            sysExInBuffer = GlobalAlloc(GHND, 500); //allocate sysex input buffer
//            if(sysExInBuffer)
//            { //if exists...
//                sysExInHdr.lpData = (LPSTR)GlobalLock(sysExInBuffer); //set pointer to our buffer in header struct
//                if(sysExInHdr.lpData)
//                { //if above pointer successfully set...
//                    sysExInHdr.dwBufferLength = 500; //allocate an input of 500 byte length
//                    sysExInHdr.dwFlags = 0; //no flags

//                    err = midiInPrepareHeader(inHandle, &sysExInHdr, sizeof(MIDIHDR)); //prepare the header (return MMRESULT err)
//                    if(err == MMSYSERR_NOERROR)
//                    { //if not error...
//                        err = midiInAddBuffer(inHandle, &sysExInHdr, sizeof(MIDIHDR)); //add the buffer to our current device
//                        if(err == MMSYSERR_NOERROR)
//                        { //if no error...
//                            err = midiInStart(inHandle); //start midi input***** (there's no midi out start)
//                            if(err != MMSYSERR_NOERROR)
//                            { //if error in starting...
//                                qDebug("couldn't open midi in"); //print error
//                            }
//                            else
//                            {
//                                qDebug("device open"); //if successful, print device open
//                            }
//                        }
//                    }
//                }
//            }

//            /* Start recording Midi and return if SUCCESS */
//            if (!(err = midiInStart(inHandle)))
//            {

//                //return(0);
//            }

//            /* ============== ERROR ============== */

//            /* Close MIDI In and zero handle */
//            //slotCloseMidiIn();


//        }

//        /* Return the error */
//        qDebug() << "OPEN MIDI IN ERR:"<< (err);

//    }
//}

//void MidiDeviceManager::slotOpenMidiOut(int index){

//    DWORD   err;

//    /* Is it not yet open? */
//    if (!outHandle)
//    {
//        /* Open MIDI Output. */
//        if (!(err = midiOutOpen(&outHandle, index, (DWORD_PTR)midiOutCallback, (DWORD_PTR)this, CALLBACK_FUNCTION)))
//        {
//            //return(0);
//        }

//        /* ============== ERROR ============== */
//    }

//    /* Return the error */
//    qDebug() << "OPEN MIDI OUT ERR:"<< (err);

//}

//void MidiDeviceManager::slotCloseMidiIn(){

//    DWORD   err;

//    /* Is the device open? */
//    if ((err = (DWORD)inHandle))
//    {
//        /* Unqueue any buffers we added. If you don't
//          input System Exclusive, you won't need this */
//        midiInReset(inHandle);

//        /* Close device */
//        if (!(err = midiInClose(inHandle)))
//        {
//            /* Clear handle so that it's safe to call closeMidiIn() anytime */
//            inHandle = 0;
//        }
//    }

//    qDebug() << "CLOSE MIDI IN ERR" << err;
//}

//void MidiDeviceManager::slotCloseMidiOut(){

//    qDebug() << "slot close OUT device";
//    DWORD   err;

//    /* Is the device open? */
//    if ((err = (DWORD)outHandle))
//    {
//        /* If you have any system exclusive buffers that
//                       you sent via midiOutLongMsg(), and which are still being output,
//                       you may need to wait for their MIDIERR_STILLPLAYING flags to be
//                       cleared before you close the device. Some drivers won't close with
//                       pending output, and will give an error. */

//        /* Close device */
//        if (!(err = midiOutClose(outHandle)))
//        {
//            /* Clear handle so that it's safe to call closeMidiOut() anytime */
//            outHandle = 0;
//        }
//    }


//    qDebug() << "CLOSE MIDI OUT ERR" << err;
//}

//int MidiDeviceManager::getSource()
//{
//    if(QSysInfo::windowsVersion() == QSysInfo::WV_XP)
//    {
//        for(uint i =0; i<midiInGetNumDevs(); i++)
//        {
//            if(getDisplayName(i, "In") == "USB Audio Device")
//            {
//                qDebug() << i << getDisplayName(i, "In");
//                return i;
//            }
//        }
//    }
//    else
//    {

//        for(uint i =0; i<midiInGetNumDevs(); i++)
//        {
//            if(getDisplayName(i, "In") == "SSCOM")
//            {
//                qDebug() << i << getDisplayName(i, "In");
//                return i;
//            }
//        }
//    }
//    return -1;
//}

//int MidiDeviceManager::getDestination()
//{
//    for(uint i =0; i<midiOutGetNumDevs(); i++)
//    {
//        //qDebug() << i << getDisplayName(i, "Out");
//    }

//    if(QSysInfo::windowsVersion() == QSysInfo::WV_XP)
//    {
//        for(uint i =0; i<midiOutGetNumDevs(); i++)
//        {
//            if(getDisplayName(i, "Out") == "USB Audio Device")
//            {
//                qDebug() << i << getDisplayName(i, "Out");
//                return i;
//            }
//        }
//    }
//    else
//    {
//        for(uint i =0; i<midiOutGetNumDevs(); i++)
//        {
//            if(getDisplayName(i, "Out") == "SSCOM")
//            {
//                qDebug() << i << getDisplayName(i, "Out");
//                return i;
//            }
//        }
//    }


//    return -1;
//}

//QString MidiDeviceManager::getDisplayName(int deviceIndex, QString inOrOut)
//{
//    if(inOrOut == "In")
//    {


//        MIDIINCAPS capabilities;

//        midiInGetDevCaps(deviceIndex, &capabilities, sizeof(MIDIINCAPS));

//        QString displayName;
//        uint charNum = 0;

//        //Make QString
//        while(capabilities.szPname[charNum] != '\0')
//        {
//            displayName.append(QChar(capabilities.szPname[charNum]));
//            charNum++;
//        }

//        return displayName;
//    }
//    else
//    {

//        MIDIOUTCAPS capabilities;

//        midiOutGetDevCaps(deviceIndex, &capabilities, sizeof(MIDIOUTCAPS));

//        QString displayName;
//        uint charNum = 0;

//        //Make QString
//        while(capabilities.szPname[charNum] != '\0')
//        {
//            displayName.append(QChar(capabilities.szPname[charNum]));
//            charNum++;
//        }

//        return displayName;
//    }
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////// Slots //////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//void MidiDeviceManager::slotSendSysEx(QString messageID, unsigned char *sysEx, int len, QString destinationName)
//{
//    qDebug() << "------------- send sysex" << messageID << destinationName;

//    if(messageID == "update firmware")
//    {
//        fwUpdateRequested = true;
//    }

//    qDebug() << "sysex bytes" << len;
//    UINT err;

//    sysExOutBuffer = GlobalAlloc(GHND, len);
//    sysExOutHdr.lpData = (LPSTR)GlobalLock(sysExOutBuffer);
//    sysExOutHdr.dwBufferLength = len;
//    sysExOutHdr.dwFlags = 0;

//    err = midiOutPrepareHeader(outHandle, &sysExOutHdr, sizeof(MIDIHDR));

//    qDebug() << "SysEx Out Prepare Header err: " << err;

//    if(!err)
//    {
//        memcpy(sysExOutHdr.lpData, sysEx, len);

//        qDebug() << "SysEx Out Header Flags: " << sysExOutHdr.dwFlags << MHDR_DONE << MHDR_INQUEUE << MHDR_ISSTRM << MHDR_PREPARED;

//        err = midiOutLongMsg(outHandle, &sysExOutHdr, sizeof(MIDIHDR));

//        if(messageID == "presets image")
//        {
//            qDebug() << "MDM -- Presets sent";
//            emit signalPresetsSent();
//        }

//        if(messageID == "settings image")
//        {
//            qDebug() << "MDM -- Settings sent";
//            emit signalSettingsSent();
//        }

//        if(err)
//        {
//            char errMsg[120];
//            midiOutGetErrorText(err, (LPWSTR)errMsg, 120);
//            qDebug()<<"Midi Out Long err:" << errMsg;
//        }
//    }
//}

//void MidiDeviceManager::slotProcessSysEx(QByteArray sysExMessageByteArray)
//{
//    qDebug() << "sysex length" << sysExMessageByteArray.count();

//    /*
//    for(int i = 0; i < sysExMessageByteArray.size(); i++)
//    {
//        int x = (uint)sysExMessageByteArray.at(i);
//        QString xAsHex = QString("0x%1").arg(x, 0, 16);
//        qDebug() << xAsHex;
//    }
//    */

//    qDebug() << "reply index" << sysExMessageByteArray.indexOf(QByteArray((const char*)_fw_query_reply_header, 4));

//    //---------- PRE v76 reply
//    if(sysExMessageByteArray.indexOf(QByteArray((const char*)_fw_query_reply_header, 4)) == 2 && sysExMessageByteArray.size() == 91 && !queryReplied)
//    {

//        qDebug() << "------- PRE V76 Got the reply" << sysExMessageByteArray.count();
//        queryReplied = true;


//#ifdef Q_OS_MAC

//#else
//        if(fwUpdateRequested)
//        {
//            fwUpdateRequested = false;
//            signalFwBytesLeft(0);
//            QApplication::processEvents();
//        }

//#endif

//        //qDebug() << foundBootloaderVersion;
//        //qDebug() << foundFirmwwareVersion;
//        //qDebug() << expectedBootloaderVersion;
//        //qDebug() << expectedFirmwareVersion;

//        //emit signalFirmwareOutOfDate(expectedBootloaderVersion,foundBootloaderVersion,expectedFirmwareVersion,foundFirmwwareVersion);
//        emit signalProcessFwQueryReply(sysExMessageByteArray);

//    }

//    //---------- POST v76 reply
//    else if(sysExMessageByteArray.indexOf(QByteArray((const char*)_fw_query_reply_header, 4)) == 2 && sysExMessageByteArray.size() == 128 && !queryReplied)
//    {
//        qDebug() << "Got the reply p76" << sysExMessageByteArray.count();
//        /*
//        for(int i = 0; i < sysExMessageByteArray.size(); i++)
//        {
//            int x = (uint)sysExMessageByteArray.at(i);
//            QString xAsHex = QString("0x%1").arg(x, 0, 16);
//            qDebug() << xAsHex;
//        }*/

//#ifdef Q_OS_MAC

//#else
//        if(fwUpdateRequested)
//        {
//            fwUpdateRequested = false;
//            signalFwBytesLeft(0);
//            QApplication::processEvents();
//        }

//#endif

//        queryReplied = true;

//        emit signalProcessFwQueryReply(sysExMessageByteArray);
//        qDebug() << "emit this signal!";

//    }

//    //If a query was sent and we got a bad reply
//    else if(!queryReplied)
//    {
//        //Windows -- do nothing, handled by version poller...
//        //slotSendSysEx("deviceQuery", _fw_query_syx_softstep, 67, "SSCOM Port 1");
//    }
//}

//void MidiDeviceManager::slotPollDevices()
//{
//    //qDebug() << "poll devices";

//    //static int numDevices = 0;

//    if(numDevices != midiInGetNumDevs())
//    {
//        numDevices = midiInGetNumDevs();
//        //hosted_slotRepopulateMidiSourceDests();
//        //hosted_slotConnectExternalMidiInputSources();
//        connectSource();
//    }
//}

//void MidiDeviceManager::slotPollVersion()
//{
//    if(!queryReplied)
//        //if(!versionReply)
//    {
//        slotSendSysEx("deviceQuery", _fw_query_syx_softstep, 67, "SSCOM Port 1");
//        emit signalConnected(false);
//    }
//    else
//    {
//        qDebug() << "STOP";
//        versionPoller->stop();
//        emit signalConnected(true);
//        //emit signalConnected(true);
//    }
//}

///////////////////////////////////////////////////////////////////////// Mac Port
//void MidiDeviceManager::slotUpdateFirmware()
//{

//}

//void MidiDeviceManager::slotSetMode(QString m)
//{
//    mode = m;

//    //qDebug() << "slot set mode";

//    if(mode == "hosted")
//    {
//        slotHostedOnOff(true);
//    }
//    else
//    {
//        slotHostedOnOff(false);
//    }
//}

//void MidiDeviceManager::slotHostedOnOff(bool onOff)
//{
//    //FIFO necessary because firmware requires delay between messages
//    if(!onOff)
//    {
//        //mode = "standalone";

//        sysexFIFOClock->stop();
//        sysexFIFOsQueue.clear();


//        sysexFIFOsQueue.append(_fw_tether_off);
//        sysexFIFOsQueue.append(_fw_standalone_on);
//        //sysexFIFOsQueue.append(_fw_scenechange_on_persist); -- Handled by settings now
//        sysexFIFOsQueue.append(_fw_nav_standalone_on_persist);
//        sysexFIFOsQueue.append(_fw_nav_standalone_on);


//        //sysexFIFOsQueue.append(_fw_tether_off);
//        //sysexFIFOsQueue.append(_fw_nav_tether_off);
//        //sysexFIFOsQueue.append(_fw_standalone_on);


//        sysexFIFOClock->start(100);
//    }
//    else
//    {
//        //mode = "hosted";

//        sysexFIFOClock->stop();
//        sysexFIFOsQueue.clear();

//        sysexFIFOsQueue.append(_fw_scenechange_on_persist);
//        sysexFIFOsQueue.append(_fw_nav_standalone_on_persist);
//        sysexFIFOsQueue.append(_fw_tether_on);
//        sysexFIFOsQueue.append(_fw_standalone_off);
//        sysexFIFOsQueue.append(_fw_nav_standalone_off);


//        //sysexFIFOsQueue.append(_fw_tether_on);
//        //sysexFIFOsQueue.append(_fw_nav_tether_on);
//        //sysexFIFOsQueue.append(_fw_standalone_off);


//        sysexFIFOClock->start(100);
//    }
//}

//void MidiDeviceManager::slotDrainSysexFIFO()
//{
//    //If anything in list, send the next message
//    if(sysexFIFOsQueue.size())
//    {
//        //Backlighting are the only 35 byte messages we send so far
//        if(_backlight_on == sysexFIFOsQueue.first() || _backlight_off == sysexFIFOsQueue.first())
//        {
//            slotSendSysEx("message", sysexFIFOsQueue.first(), 35, "SSCOM Port 1");
//        }
//        else
//        {
//            slotSendSysEx("message", sysexFIFOsQueue.first(), 43, "SSCOM Port 1");
//        }

//        sysexFIFOsQueue.removeFirst();
//    }

//    //Otherwise stop calling function
//    else
//    {
//        sysexFIFOClock->stop();

//        if(calibrationPhase != "complete")
//        {
//            if(calibrationPhase == "start")
//            {
//                emit signalStartStandaloneCalibration();
//            }
//            else
//            {
//                emit signalStopStandaloneCalibration();
//            }
//        }
//    }
//}

//void MidiDeviceManager::hosted_slotParsePacket(const MIDIPacket* packet)
//{
//    emit hosted_signalParsePacket(packet);
//}

//void MidiDeviceManager::hosted_slotSendPacket(QString port, MIDIPacket packet)
//{

//    //Semds Packet to external dest
//    //qDebug() << port; //<< "hosted_slotSendPacketCalled - data:" << packet.data[0] << packet.data[1] << packet.data[2] << "length, time : " << packet.length << packet.timeStamp << "\n";

//    DWORD msg = 0x00000000;
//    DWORD msg2 = 0x00000000;
//    bool sendMsg2 = false;

//    //Current possible sizes from midiout format: 2, 3, 6
//    switch (packet.length)
//    {
//    case 2:
//        msg = (msg << 8) + 0x00;
//        msg = (msg << 8) + packet.data[1];
//        msg = (msg << 8) + packet.data[0];
//        break;

//    case 3:
//        msg = (msg << 8) + 0x00;
//        msg = (msg << 8) + packet.data[2];
//        msg = (msg << 8) + packet.data[1];
//        msg = (msg << 8) + packet.data[0];
//        break;

//    case 6:

//        //Format first msg
//        msg = (msg << 8) + 0x00;
//        msg = (msg << 8) + packet.data[2];
//        msg = (msg << 8) + packet.data[1];
//        msg = (msg << 8) + packet.data[0];

//        //Format 2nd msg
//        msg2 = (msg2 << 8) + 0x00;
//        msg2 = (msg2 << 8) + packet.data[5];
//        msg2 = (msg2 << 8) + packet.data[4];
//        msg2 = (msg2 << 8) + packet.data[3];

//        //Open 2nd msg gate
//        sendMsg2 = true;

//        break;

//    default:
//        break;
//    }



//    //qDebug() << "msg" << msg;

//    if(port == "SoftStep Share")
//    {
//        //MIDIReceived(appVirtualSourceRef, packetList);
//    }

//    //Send a messaget to the board, like queries, etc.
//    else if(port.contains("SSCOM") && port.contains("1"))
//    {
//        //qDebug() << "send message to SSCOM1";
//        midiOutShortMsg(outHandle, msg);
//    }

//    //Send a message to somewhere else
//    else if(externalDests.contains(port))
//    {
//        //qDebug() << "send message to SSCOM1" << port;

//        HMIDIOUT    handle;

//        /* Open default MIDI Out device */
//        if (!midiOutOpen(&handle, externalDests.value(port), 0, 0, CALLBACK_NULL) )
//        {
//            //Always send first msg
//            midiOutShortMsg(handle, msg);

//            //If a two message packet, send out second message
//            if(sendMsg2)
//            {
//                midiOutShortMsg(handle, msg2);
//            }

//            /* Close the MIDI device */
//            midiOutClose(handle);
//        }
//        else
//        {
//            qDebug() << "ERROR opening output device";
//        }
//    }
//}

//void MidiDeviceManager::hosted_slotRepopulateMidiSourceDests()
//{
//    //Called when midi system changes, automaticall called on hosted to standlaone/switch because of "SoftStep Share"

//    qDebug() << "__________ hosted_slotRepopulateMidiSourceDests()";

//    //----------------------- Get non SSCOM sources
//    midiInputSources.clear();

//    for(int i=0; i<midiInGetNumDevs(); i++)
//    {
//        if(QSysInfo::windowsVersion() == QSysInfo::WV_XP)
//        {
//            if(getDisplayName(i, "In") != QString("USB Audio Device"))
//            {
//                qDebug() << "MIDI INPUT SOURCE i -- NO SSCOM!" << i << getDisplayName(i, "In");

//                if(getDisplayName(i, "In").contains("USB Audio Device") && getDisplayName(i, "In").contains("2"))
//                {
//                    //We would like port 2 to be named SoftStep Expander
//                    midiInputSources.insert("SoftStep Expander", i);
//                }
//                else
//                {
//                    //Store name of dest and it's endpoint ref
//                    midiInputSources.insert(getDisplayName(i, "In"), i);
//                }
//                //qDebug() << "Non-SoftStep Destination: " << getDisplayName(MIDIGetDestination(i));
//            }
//        }
//        else
//        {
//            if(getDisplayName(i, "In") != QString("SSCOM"))
//            {
//                qDebug() << "MIDI INPUT SOURCE i -- NO SSCOM!" << i << getDisplayName(i, "In");

//                if(getDisplayName(i, "In").contains("SSCOM") && getDisplayName(i, "In").contains("2"))
//                {
//                    //We would like port 2 to be named SoftStep Expander
//                    midiInputSources.insert("SoftStep Expander", i);
//                }
//                else
//                {
//                    //Store name of dest and it's endpoint ref
//                    midiInputSources.insert(getDisplayName(i, "In"), i);
//                }
//                //qDebug() << "Non-SoftStep Destination: " << getDisplayName(MIDIGetDestination(i));
//            }
//        }



//        //Allocate new array of endpoint pointers for passing as refcon
//        //midiInputSourcePointers = new MIDIEndpointRef[MIDIGetNumberOfSources()];
//    }

//    //Sends sources to midi input in settings page, connected in mainwindow
//    emit hosted_signalMidiInputSourceMenus(midiInputSources);


//    //----------------------- Get non SSCOM destinations
//    externalDests.clear();

//    for(uint i =0; i<midiOutGetNumDevs(); i++)
//    {
//        if(QSysInfo::windowsVersion() == QSysInfo::WV_XP)
//        {
//            if(getDisplayName(i, "Out") != QString("USB Audio Device"))
//            {
//                if(getDisplayName(i, "Out").contains("USB Audio Device") && getDisplayName(i, "Out").contains("2"))
//                {
//                    //We would like port 2 to be named SoftStep Expander
//                    externalDests.insert("SoftStep Expander", i);
//                }
//                else
//                {
//                    //Store name of dest and it's endpoint ref
//                    externalDests.insert(getDisplayName(i, "Out"), i);
//                }
//                //qDebug() << "Non-SoftStep Destination: " << getDisplayName(MIDIGetDestination(i));
//            }
//        }
//        else
//        {
//            if(getDisplayName(i, "Out") != QString("SSCOM"))
//            {
//                if(getDisplayName(i, "Out").contains("SSCOM") && getDisplayName(i, "Out").contains("2"))
//                {
//                    //We would like port 2 to be named SoftStep Expander
//                    externalDests.insert("SoftStep Expander", i);
//                }
//                else
//                {
//                    //Store name of dest and it's endpoint ref
//                    externalDests.insert(getDisplayName(i, "Out"), i);
//                }
//                //qDebug() << "Non-SoftStep Destination: " << getDisplayName(MIDIGetDestination(i));
//            }
//        }
//    }

//    //Sneds destinations to device menus in modlines
//    emit hosted_signalPopulateDeviceMenus(externalDests);
//}

////-------------------------- MIDI Input from Settings
//void MidiDeviceManager::hosted_slotParseMidiInputPacket(const MIDIPacket* packet, QString deviceName)
//{
//    //qDebug() << "hosted_slotParseMidiInputPacket" << deviceName;
//    emit hosted_signalParseMidiInputPacket(packet, deviceName);
//}

//void MidiDeviceManager::hosted_slotConnectExternalMidiInputSources()
//{
//    //qDebug() << "midi input sources" << midiInputSources.keys();

//    for(int i = 0; i < midiInputSources.count(); i++)
//    {
//        qDebug() << "midi open error:" << midiInOpen(&externalInHandle[i], midiInputSources.values().at(i), (DWORD_PTR)MidiDeviceManager::externalMidiInCallback, (DWORD_PTR)this, CALLBACK_FUNCTION);
//        midiInStart(externalInHandle[i]);
//    }


//    //er = midiInputSources.value(getDisplayName(MIDIGetSource(0)));

//    /*for(int i=0; i<MIDIGetNumberOfSources(); i++)
//    {
//        if(getDisplayName(MIDIGetSource(i)).contains("SSCOM") && getDisplayName(MIDIGetSource(i)).contains("1"))
//        {
//            //Filter out SSCOM Port 1 and
//        }
//        else
//        {
//            //midiInputSources.value(getDisplayName(MIDIGetSource(i)));

//            //MIDIEndpointRef* epr = &midiInputSourcePointers[i];

//            midiInputSourcePointers[i] = MIDIGetSource(i);

//            //qDebug() << "----------------------------" << "slot connect external midi sources" << getDisplayName(MIDIGetSource(i)) << midiInputSourcePointers[i];

//            MIDIPortConnectSource(midiInputPort, MIDIGetSource(i), (void*)&midiInputSourcePointers[i]);
//        }
//    }*/
//}

////--------------------------- Pedal Calibration
//void MidiDeviceManager::slotTetherOnOffInStandalone(bool onOff)
//{
//    //---- !!!! This function only used for pedal calibration !!! ----//

//    //Turn tether on during calibration
//    if(onOff)
//    {
//        calibrationPhase = "start";

//        sysexFIFOClock->stop();
//        sysexFIFOsQueue.clear();

//        sysexFIFOsQueue.append(_fw_scenechange_on_persist);
//        sysexFIFOsQueue.append(_fw_tether_on);
//        sysexFIFOsQueue.append(_fw_standalone_off);
//        sysexFIFOsQueue.append(_fw_nav_standalone_off);

//        sysexFIFOClock->start(100);

//        //Cue calibration start
//        emit signalStartStandaloneCalibration();
//    }

//    //Turn thether off at end of calibration
//    else
//    {
//        calibrationPhase = "stop";

//        sysexFIFOClock->stop();
//        sysexFIFOsQueue.clear();

//        sysexFIFOsQueue.append(_fw_tether_off);
//        sysexFIFOsQueue.append(_fw_standalone_on);
//        sysexFIFOsQueue.append(_fw_nav_standalone_on_persist);
//        sysexFIFOsQueue.append(_fw_nav_standalone_on);

//        sysexFIFOClock->start(100);

//    }
//}

////--------------------------- One-off sysex messages
//void MidiDeviceManager::slotSceneChangeOnOff(bool onOff)
//{
//    //qDebug() << "scene change on/off";

//    if(onOff)
//    {
//        sysexFIFOsQueue.append(_fw_tether_off);
//        sysexFIFOsQueue.append(_fw_standalone_on);
//        sysexFIFOsQueue.append(_fw_scenechange_on_persist);
//        sysexFIFOsQueue.append(_fw_nav_standalone_on_persist);
//        sysexFIFOsQueue.append(_fw_nav_standalone_on);

//    }
//    else
//    {
//        sysexFIFOsQueue.append(_fw_tether_off);
//        sysexFIFOsQueue.append(_fw_standalone_on);
//        sysexFIFOsQueue.append(_fw_scenechange_off_persist);
//        sysexFIFOsQueue.append(_fw_nav_standalone_on_persist);
//        sysexFIFOsQueue.append(_fw_nav_standalone_on);

//    }

//    if(!sysexFIFOClock->isActive())
//    {
//        sysexFIFOClock->start(100);
//    }
//}

//void MidiDeviceManager::slotBackLightOnOff(bool onOff)
//{
//    if(onOff)
//    {
//        sysexFIFOsQueue.append(_backlight_on);
//    }
//    else
//    {
//        sysexFIFOsQueue.append(_backlight_off);
//    }

//    if(!sysexFIFOClock->isActive())
//    {
//        sysexFIFOClock->start(100);
//    }
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////// Callbacks ////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//void CALLBACK MidiDeviceManager::midiInCallback(HMIDIIN hMidiIn,UINT wMsg,DWORD_PTR dwInstance,DWORD_PTR dwParam1,DWORD_PTR dwParam2)
//{
//    //qDebug() << "midi in" << dwParam1 << dwParam2;

//    //qDebug() << MIM_DATA << uMsg;
//    //qDebug() << dwParam;
//    //qDebug()    <<"status"<< ((dwParam1) & 0xFF)
//      //        << "data1" << ((dwParam1>>8) & 0xFF)
//        //    << "data2" << ((dwParam1>>16) & 0xFF); //status byte
//    MidiDeviceManager *mdm = (MidiDeviceManager *) dwInstance;
//    MIDIPacket *packet = new MIDIPacket;


//    switch(wMsg){
//    case MIM_OPEN:
//        qDebug("MMOPEN");
//        break;
//    case MIM_ERROR:
//        qDebug("MMERROR");
//        break;
//    case MIM_LONGERROR:
//        qDebug("MIM_LONGERROR");
//        break;
//    case MIM_MOREDATA:
//        qDebug("MIM_MOREDATA");
//        break;
//    case MIM_CLOSE:
//        qDebug("MIM_ClOSE");
//        break;
//    case MIM_DATA:
//        //qDebug("MIM_DATA");

//        if(mdm->ioGate)
//        {
//            //qDebug() << "MIDI Channel Event: ";
//            if(mdm->mode == "hosted")
//            {
//                packet->data[0] = (dwParam1) & 0xFF;
//                packet->data[1] = (dwParam1>>8) & 0xFF;
//                packet->data[2] = (dwParam1>>16) & 0xFF;

//                mdm->hosted_slotParsePacket(packet);
//                break;
//            }
//            else if(mdm->mode == "standalone" && mdm->calibrationPhase != "complete")
//            {
//                //qDebug() << "PEDAL CALIBRATION";

//                packet->data[0] = (dwParam1) & 0xFF;
//                packet->data[1] = (dwParam1>>8) & 0xFF;
//                packet->data[2] = (dwParam1>>16) & 0xFF;

//                mdm->hosted_slotParsePacket(packet);
//                break;
//            }
//        }

//        break;
//    case MIM_LONGDATA:
//    {
//        qDebug("MIM_LONGDATA");

//        LPMIDIHDR lpMidiHdr = (LPMIDIHDR) dwParam1;

//        if(lpMidiHdr->dwBytesRecorded){

//            qDebug() << "----------- Bytes Recorded -----------" << lpMidiHdr->dwBytesRecorded;

//            mdm->slotProcessSysEx(QByteArray(lpMidiHdr->lpData, lpMidiHdr->dwBytesRecorded));

//            midiInAddBuffer(hMidiIn, lpMidiHdr, sizeof(MIDIHDR));
//        }
//    }

//        break;
//    default:
//        qDebug("in callback");
//        break;
//    }
//}

//void CALLBACK MidiDeviceManager::midiOutCallback(HMIDIOUT handle, UINT uMsg, DWORD_PTR dwInstance, DWORD_PTR dwParam, DWORD_PTR dwParam1)
//{
//    //qDebug() <<  "msg type" << uMsg << MOM_DONE << MOM_CLOSE << MOM_OPEN;

//    switch(uMsg)
//    {
//    case MOM_DONE:
//        qDebug("MOM_DONE");
//        break;
//    case MOM_CLOSE:
//        qDebug("MOM_CLOSE");
//        break;
//    case MOM_OPEN:
//        qDebug("MOM_OPEN");
//        break;
//    default:
//        qDebug("out callback");
//        break;

//    }

//    MidiDeviceManager *mda = (MidiDeviceManager *) dwInstance;

//    if(uMsg == MOM_DONE){
//        midiOutUnprepareHeader(mda->outHandle, &mda->sysExOutHdr, sizeof(MIDIHDR));
//        GlobalUnlock(mda->sysExOutBuffer);
//        GlobalFree(mda->sysExOutBuffer);
//        qDebug() << "MEMORY DEALLOCATED";

//        if(mda->fwUpdateRequested == true)
//        {
//            //mda->fwUpdateRequested = false;
//            //emit mda->signalFwBytesLeft(0);
//            //mda->slotCloseMidiIn();
//            //mda->slotCloseMidiIn();
//            //mda->numDevices = 0; //Resets polling
//            //qDebug() << "Get Source" << mda->getSource();
//        }
//    }
//}

//void CALLBACK MidiDeviceManager::externalMidiInCallback(HMIDIIN hMidiIn,UINT wMsg,DWORD_PTR dwInstance,DWORD_PTR dwParam1,DWORD_PTR dwParam2)
//{
//    //qDebug() << "EXTERNAL MIDI INPUT CALLBACK";
//    //qDebug() << "midi in" << dwParam1 << dwParam2;
//    //qDebug() << MIM_DATA << uMsg;
//    //qDebug() << dwParam;
//    //qDebug() <<"status"<< ((dwParam1) & 0xFF)
//    //         << "data1" << ((dwParam1>>8) & 0xFF)
//    //         << "data2" << ((dwParam1>>16) & 0xFF); //status byte

//    MidiDeviceManager *mdmInput = (MidiDeviceManager *) dwInstance;
//    MIDIPacket *packet = new MIDIPacket;
//    QString deviceName = "";

//    for(int i = 0; i < mdmInput->midiInputSources.count(); i++)
//    {
//        //qDebug() << "midi open error:" << midiInOpen(&externalInHandle[i], midiInputSources.values().at(i), (DWORD_PTR)MidiDeviceManager::externalMidiInCallback, (DWORD_PTR)this, CALLBACK_FUNCTION);
//        //midiInStart(externalInHandle[i]);

//        if(hMidiIn == mdmInput->externalInHandle[i])
//        {
//            deviceName = mdmInput->getDisplayName(mdmInput->midiInputSources.values().at(i), "In");
//        }
//    }

//    qDebug() << "deviceName" << deviceName;

//    switch(wMsg){
//    case MIM_OPEN:
//        qDebug("MMOPEN");
//        break;
//    case MIM_ERROR:
//        qDebug("MMERROR");
//        break;
//    case MIM_LONGERROR:
//        qDebug("MIM_LONGERROR");
//        break;
//    case MIM_MOREDATA:
//        qDebug("MIM_MOREDATA");
//        break;
//    case MIM_CLOSE:
//        qDebug("MIM_ClOSE");
//        break;
//    case MIM_DATA:
//        //qDebug("MIM_DATA");

//        if(mdmInput->ioGate)
//        {
//            //qDebug() << "MIDI Channel Event: ";
//            if(mdmInput->mode == "hosted")
//            {
//                packet->data[0] = (dwParam1) & 0xFF;
//                packet->data[1] = (dwParam1>>8) & 0xFF;
//                packet->data[2] = (dwParam1>>16) & 0xFF;

//                mdmInput->hosted_slotParseMidiInputPacket(packet, deviceName);
//                break;
//            }
//        }

//        break;

//    case MIM_LONGDATA:
//        break;

//    default:
//        qDebug("in callback");
//        break;
//    }
//}

#endif
