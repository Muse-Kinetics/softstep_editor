// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
//#include "mididevicemanager.h"
#include "sysexmessages.h"

#ifdef Q_OS_MAC
SS_MidiDeviceManager *callbackClassPointer;
void midiSystemChanged(const MIDINotification *message, void *refCon);                          //Called when the system's MIDI has changed
void incomingMidi(const MIDIPacketList *pktlist, void *readProcRefCon, void *srcConnRefCon);    //Called upon incoming midi from connected port
void sysExComplete(MIDISysexSendRequest*);                                                      //Called when sysex event has been completely sent


SS_MidiDeviceManager::SS_MidiDeviceManager(QWidget *parent) :
    QWidget(parent)
{
//    inBootloader = false;
//    fwUpdateRequested = false;

//    sysexFIFOClock = new QTimer();
//    connect(sysexFIFOClock, SIGNAL(timeout()), this, SLOT(slotDrainSysexFIFO()));

//    callbackClassPointer = this;

//    createAppMidiClient();
}

void SS_MidiDeviceManager::slotStandaloneOn()
{
    // EB TODO - reconnect this with new handlers
//    sysexFIFOClock->stop();
//    sysexFIFOsQueue.clear();


//    sysexFIFOsQueue.append(_fw_tether_off);
//    sysexFIFOsQueue.append(_fw_standalone_on);
//    sysexFIFOsQueue.append(_fw_scenechange_on_persist);
//    sysexFIFOsQueue.append(_fw_nav_standalone_on_persist);
//    sysexFIFOsQueue.append(_fw_nav_standalone_on);


//    //sysexFIFOsQueue.append(_fw_tether_off);
//    //sysexFIFOsQueue.append(_fw_nav_tether_off);
//    //sysexFIFOsQueue.append(_fw_standalone_on);


//    sysexFIFOClock->start(100);
}

//void SS_MidiDeviceManager::slotDrainSysexFIFO()
//{
//    //If anything in list, send the next message
//    if(!sysexFIFOsQueue.isEmpty())
//    {
//        slotSendSysEx("message", sysexFIFOsQueue.first(), 43, "SSCOM Port 1");
//        sysexFIFOsQueue.removeFirst();
//    }

//    //Otherwise stop calling function
//    else
//    {
//        sysexFIFOClock->stop();
//    }
//}

//void SS_MidiDeviceManager::createAppMidiClient()
//{
//    MIDIClientCreate(CFSTR("QuNexus MIDI Client"), midiSystemChanged, this, &appClientRef);
//    MIDIInputPortCreate(appClientRef, CFSTR("QuNexus MIDI Client In Port"), incomingMidi, this, &appInPortRef);
//    MIDIOutputPortCreate(appClientRef, CFSTR("QuNexus MIDI Client Out Port"), &appOutPortRef);
//}

//bool SS_MidiDeviceManager::connectSource()
//{
//    if(getSource() != -1)
//    {
//        qDebug() << "connect source called";
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

//int SS_MidiDeviceManager::getSource()
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

//int SS_MidiDeviceManager::getDestination()
//{
//    //Returns index of first instance of SSCOM Port 1
//    for(unsigned int i=0; i<MIDIGetNumberOfDestinations(); i++)
//    {
//        if(getDisplayName(MIDIGetDestination(i)).contains("SSCOM") && getDisplayName(MIDIGetDestination(i)).contains("1"))
//        {
//            return i;
//        }
//    }

//    return -1;
//}

//void SS_MidiDeviceManager::slotRequestFirmwareUpdate()
//{
//    //No bootloader for softstep -- QuNexus legacy
//}

//void SS_MidiDeviceManager::slotEnterBootloader()
//{
//    //No bootloader for softstep -- QuNexus legacy
//}

//void SS_MidiDeviceManager::slotUpdateFirmware()
//{
//    //Not used -- handled in sysex composer
//}


////////////////////////////////////////////////////////
///////////////// Helper Funcitons /////////////////////
////////////////////////////////////////////////////////
//QString SS_MidiDeviceManager::getDisplayName(MIDIObjectRef object)
//{
//    // Returns the display name of a given MIDIObjectRef as an NSString
//    CFStringRef name = nil; //place holder for name

//    if(noErr != MIDIObjectGetStringProperty(object, kMIDIPropertyDisplayName, &name))
//    {//get the name using midi services function
//        return nil;
//    }

//    return QString(cFStringRefToQString(name)); //return the name
//}

//QString SS_MidiDeviceManager::cFStringRefToQString(CFStringRef ref)
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

//void SS_MidiDeviceManager::slotSendSysEx(QString messageID,unsigned char* bytes, int len, QString destinationName)
//{

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
//        qDebug() << "Matching Destination: " << destinationName << " NOT Found!";
//    }
//}

//void SS_MidiDeviceManager::slotProcessSysEx(QByteArray sysExMessageByteArray)
//{
//    qDebug() << "sysex length" << sysExMessageByteArray.count();

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
//        /*for(int i = 0; i < sysExMessageByteArray.size(); i++)
//        {
//            int x = (uint)sysExMessageByteArray.at(i);
//            QString xAsHex = QString("0x%1").arg(x, 0, 16);
//            qDebug() << xAsHex;
//        }*/

//        queryReplied = true;

//        emit signalProcessFwQueryReply(sysExMessageByteArray);

//    }

//    //If a query was sent and we got a bad reply
//    else if(!queryReplied)
//    {
//        slotSendSysEx("deviceQuery", _fw_query_syx_softstep, 67, "SSCOM Port 1");
//    }
//}



//////////////////////////////////////////////////////////
//////////////////Non-Class Callbacks ////////////////////
//////////////////////////////////////////////////////////
//void midiSystemChanged(const MIDINotification *message, void *refCon)
//{
//    Q_UNUSED(refCon)

//    if(message->messageID == kMIDIMsgObjectAdded)
//    {
//        MIDIObjectAddRemoveNotification *msg = (MIDIObjectAddRemoveNotification *)message;

//        if(msg->childType == kMIDIObjectType_Source)
//        {
//            if(callbackClassPointer->getDisplayName(msg->child).contains("SSCOM") && callbackClassPointer->getDisplayName(msg->child).contains("1"))
//            {
//                callbackClassPointer->connectSource();
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
//        }
//    }
//}

//void incomingMidi(const MIDIPacketList *pktlist, void *readProcRefCon, void *srcConnRefCon){

//    Q_UNUSED(readProcRefCon)
//    Q_UNUSED(srcConnRefCon)

//    //iterate through midi packets and process according to type
//    const MIDIPacket *packet = &pktlist->packet[0];

//    //for number packets in packet list
//    for(unsigned int i =0; i < pktlist->numPackets; i++)
//    {
//        //for length of packet
//        for(int j = 0; j < packet->length; j++)
//        {
//            //If a SysEx Start Byte, set filter switch
//            if(packet->data[j] == 240)
//            {
//                callbackClassPointer->isSysEx = true;
//            }

//            //If a SysEx End Byte, set filter switch off and send last bytes
//            else if (packet->data[j] == 247)
//            {
//                callbackClassPointer->isSysEx = false;
//                callbackClassPointer->sysExMessage.append(packet->data[j]);
//                //qDebug() << "----- SysEx In ----- :" << packet->data[j];

//                callbackClassPointer->slotProcessSysEx(callbackClassPointer->sysExMessage);
//                callbackClassPointer->sysExMessage.clear();
//            }

//            //Processes SysEx
//            if(callbackClassPointer->isSysEx)
//            {
//                callbackClassPointer->sysExMessage.append(packet->data[j]);
//                //qDebug() << "----- SysEx In ----- :" << packet->data[j];
//            }
//            else if(packet->data[j] != 247)
//            {
//                qDebug() << "MIDI Channel Event: " << packet->data[j];
//            }
//        }

//        //advance packet in midi packet list
//        packet = MIDIPacketNext(packet);
//    }
//}

//void sysExComplete(MIDISysexSendRequest* request)
//{
//    Q_UNUSED(request)
//    qDebug() << "Sys Ex Sent";
//}
#else

SS_MidiDeviceManager::SS_MidiDeviceManager(QObject *parent) :
    QObject(parent)
{
    settingsSent = true;
    presetsSent = true;

    sysexFIFOClock = new QTimer(this);
    connect(sysexFIFOClock, SIGNAL(timeout()), this, SLOT(slotDrainSysexFIFO()));

    numDevices = 0;

    sysExType = "None";
    globals.clear();

    qDebug() <<"ERROR" << MMSYSERR_ALLOCATED;

    inBootloader = false;
    fwUpdateRequested = false;

    inHandle = NULL;
    outHandle = NULL;
    connected = false;
    refreshDevices = true;

    //------------------------------- Polling

    //Devices
    devicePoller = new QTimer(this);
    connect(devicePoller, SIGNAL(timeout()), this, SLOT(slotPollDevices()));
    devicePoller->start(1000);

    //Version
    versionPoller = new QTimer(this);
    connect(versionPoller, SIGNAL(timeout()), this, SLOT(slotPollVersion()));
    versionReply = false;
    queryReplied = false;
}

void SS_MidiDeviceManager::slotStandaloneOn()
{
    sysexFIFOClock->stop();
    sysexFIFOsQueue.clear();
    sysexFIFOsQueue.append(_fw_tether_off);
    sysexFIFOsQueue.append(_fw_standalone_on);
    sysexFIFOsQueue.append(_fw_scenechange_on_persist);
    sysexFIFOsQueue.append(_fw_nav_standalone_on_persist);
    //May need conditional here for VK2A
    //sysexFIFOsQueue.append(_fw_nav_tether_off);
    sysexFIFOClock->start(100);
}

void SS_MidiDeviceManager::slotDrainSysexFIFO()
{
    //If anything in list, send the next message
    if(!sysexFIFOsQueue.isEmpty())
    {
        slotSendSysEx("message", sysexFIFOsQueue.first(), 43, "SSCOM Port 1");
        sysexFIFOsQueue.removeFirst();
    }

    //Otherwise stop calling function
    else
    {
        sysexFIFOClock->stop();
    }
}

bool SS_MidiDeviceManager::connectSource()
{
    qDebug() << "connect source" << getSource();

    if(getSource() != -1)
    {
        //Connect Source
        slotCloseMidiIn();
        slotCloseMidiOut();
        slotOpenMidiIn(getSource());
        slotOpenMidiOut(getDestination());
        versionReply = false;
        queryReplied = false;
        versionPoller->start(1000);
        return true;
    }
    else
    {
        slotCloseMidiIn();
        slotCloseMidiOut();
        emit signalConnected(false);
        return false;
    }
}

void SS_MidiDeviceManager::slotOpenMidiIn(int index){

    DWORD   err;

    /* Is it not yet open? */
    if (!inHandle)
    {
        /* Open MIDI Input and set Windows to call my
          midiInputEvt() callback function. You may prefer
          to have something other than CALLBACK_FUNCTION. Also,
          I open device 0. You may want to give the user a choice */
        if (!(err = midiInOpen(&inHandle, index, (DWORD_PTR)MidiDeviceManager::midiInCallback, (DWORD_PTR)this, CALLBACK_FUNCTION)))
        {
            sysExInBuffer = GlobalAlloc(GHND, 500); //allocate sysex input buffer
            if(sysExInBuffer)
            { //if exists...
                sysExInHdr.lpData = (LPSTR)GlobalLock(sysExInBuffer); //set pointer to our buffer in header struct
                if(sysExInHdr.lpData)
                { //if above pointer successfully set...
                    sysExInHdr.dwBufferLength = 500; //allocate an input of 500 byte length
                    sysExInHdr.dwFlags = 0; //no flags

                    err = midiInPrepareHeader(inHandle, &sysExInHdr, sizeof(MIDIHDR)); //prepare the header (return MMRESULT err)
                    if(err == MMSYSERR_NOERROR)
                    { //if not error...
                        err = midiInAddBuffer(inHandle, &sysExInHdr, sizeof(MIDIHDR)); //add the buffer to our current device
                        if(err == MMSYSERR_NOERROR)
                        { //if no error...
                            err = midiInStart(inHandle); //start midi input***** (there's no midi out start)
                            if(err != MMSYSERR_NOERROR)
                            { //if error in starting...
                                qDebug("couldn't open midi in"); //print error
                            }
                            else
                            {
                                qDebug("device open"); //if successful, print device open
                            }
                        }
                    }
                }
            }

            /* Start recording Midi and return if SUCCESS */
            if (!(err = midiInStart(inHandle)))
            {

                //return(0);
            }

            /* ============== ERROR ============== */

            /* Close MIDI In and zero handle */
            //slotCloseMidiIn();


        }

        /* Return the error */
        qDebug() << "OPEN MIDI IN ERR:"<< (err);

    }
}

void SS_MidiDeviceManager::slotOpenMidiOut(int index){

    DWORD   err;

    /* Is it not yet open? */
    if (!outHandle)
    {
        /* Open MIDI Output. */
        if (!(err = midiOutOpen(&outHandle, index, (DWORD_PTR)midiOutCallback, (DWORD_PTR)this, CALLBACK_FUNCTION)))
        {
            //return(0);
        }

        /* ============== ERROR ============== */
    }

    /* Return the error */
    qDebug() << "OPEN MIDI OUT ERR:"<< (err);

}

void SS_MidiDeviceManager::slotCloseMidiIn(){

    DWORD   err;

    /* Is the device open? */
    if ((err = (DWORD)inHandle))
    {
        /* Unqueue any buffers we added. If you don't
          input System Exclusive, you won't need this */
        midiInReset(inHandle);

        /* Close device */
        if (!(err = midiInClose(inHandle)))
        {
            /* Clear handle so that it's safe to call closeMidiIn() anytime */
            inHandle = 0;
        }
    }

    qDebug() << "CLOSE MIDI IN ERR" << err;
}

void SS_MidiDeviceManager::slotCloseMidiOut(){

    qDebug() << "slot close OUT device";
    DWORD   err;

    /* Is the device open? */
    if ((err = (DWORD)outHandle))
    {
        /* If you have any system exclusive buffers that
                       you sent via midiOutLongMsg(), and which are still being output,
                       you may need to wait for their MIDIERR_STILLPLAYING flags to be
                       cleared before you close the device. Some drivers won't close with
                       pending output, and will give an error. */

        /* Close device */
        if (!(err = midiOutClose(outHandle)))
        {
            /* Clear handle so that it's safe to call closeMidiOut() anytime */
            outHandle = 0;
        }
    }


    qDebug() << "CLOSE MIDI OUT ERR" << err;
}

int SS_MidiDeviceManager::getSource()
{
    qDebug() << "get source";

    if(QSysInfo::windowsVersion() == QSysInfo::WV_XP)
    {
        for(uint i =0; i<midiInGetNumDevs(); i++)
        {
            if(getDisplayName(i, "In") == "USB Audio Device")
            {
                qDebug() << i << getDisplayName(i, "In");
                return i;
            }
        }
    }
    else
    {
        qDebug() << "getSource win 7";

        for(uint i =0; i<midiInGetNumDevs(); i++)
        {
            qDebug() << i << getDisplayName(i, "In");

            if(getDisplayName(i, "In") == "SSCOM")
            {
                qDebug() << i << getDisplayName(i, "In");
                return i;
            }
        }
    }
    return -1;
}

int SS_MidiDeviceManager::getDestination()
{
    if(QSysInfo::windowsVersion() == QSysInfo::WV_XP)
    {
        for(uint i =0; i<midiOutGetNumDevs(); i++)
        {
            if(getDisplayName(i, "Out") == "USB Audio Device")
            {
                qDebug() << i << getDisplayName(i, "Out");
                return i;
            }
        }
    }
    else
    {
        for(uint i =0; i<midiOutGetNumDevs(); i++)
        {
            if(getDisplayName(i, "Out") == "SSCOM")
            {
                qDebug() << i << getDisplayName(i, "Out");
                return i;
            }
        }
    }


    return -1;
}

QString SS_MidiDeviceManager::getDisplayName(int deviceIndex, QString inOrOut)
{
    if(inOrOut == "In")
    {


        MIDIINCAPS capabilities;

        midiInGetDevCaps(deviceIndex, &capabilities, sizeof(MIDIINCAPS));

        QString displayName;
        uint charNum = 0;

        //Make QString
        while(capabilities.szPname[charNum] != '\0')
        {
            displayName.append(QChar(capabilities.szPname[charNum]));
            charNum++;
        }

        return displayName;
    }
    else
    {

        MIDIOUTCAPS capabilities;

        midiOutGetDevCaps(deviceIndex, &capabilities, sizeof(MIDIOUTCAPS));

        QString displayName;
        uint charNum = 0;

        //Make QString
        while(capabilities.szPname[charNum] != '\0')
        {
            displayName.append(QChar(capabilities.szPname[charNum]));
            charNum++;
        }

        return displayName;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////// Slots //////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SS_MidiDeviceManager::slotSendSysEx(QString messageID, unsigned char *sysEx, int len, QString destinationName)
{

    if(messageID == "update firmware")
    {
        fwUpdateRequested = true;
    }
    if(messageID == "settings image")
    {
        settingsSent = false;
    }
    if(messageID == "presets image")
    {
        presetsSent = false;
    }

    qDebug() << "sysex bytes" << len;
    UINT err;

    sysExOutBuffer = GlobalAlloc(GHND, len);
    sysExOutHdr.lpData = (LPSTR)GlobalLock(sysExOutBuffer);
    sysExOutHdr.dwBufferLength = len;
    sysExOutHdr.dwFlags = 0;

    err = midiOutPrepareHeader(outHandle, &sysExOutHdr, sizeof(MIDIHDR));

    qDebug() << "SysEx Out Prepare Header err: " << err;

    if(!err)
    {
        memcpy(sysExOutHdr.lpData, sysEx, len);

        qDebug() << "SysEx Out Header Flags: " << sysExOutHdr.dwFlags << MHDR_DONE << MHDR_INQUEUE << MHDR_ISSTRM << MHDR_PREPARED;

        err = midiOutLongMsg(outHandle, &sysExOutHdr, sizeof(MIDIHDR));



        if(err)
        {
            char errMsg[120];
            midiOutGetErrorText(err, (LPWSTR)errMsg, 120);
            qDebug()<<"Midi Out Long err:" << errMsg;
        }
        else
        {
            midiOutUnprepareHeader(outHandle, &sysExOutHdr, sizeof(MIDIHDR));
            GlobalUnlock(sysExOutBuffer);
            GlobalFree(sysExOutBuffer);

            qDebug() << "MEMORY DEALLOCATED";

            if(messageID == "presets image")
            {
                qDebug() << "MDM -- Presets sent";
                emit signalPresetsSent();
            }

            if(messageID == "settings image")
            {
                qDebug() << "MDM -- Settings sent";
                emit signalSettingsSent();
            }
        }
    }
}

void SS_MidiDeviceManager::slotProcessSysEx(QByteArray sysExMessageByteArray)
{
    /*
    qDebug() << "sysex length" << sysExMessageByteArray.count();

    if(sysExMessageByteArray.indexOf(QByteArray((const char*)_fw_query_reply_header, 4)) == 2 && sysExMessageByteArray.size() == 91 && !versionReply)
    {
        qDebug() << "Got the reply" << sysExMessageByteArray.count();
        versionReply = true;
        Sleep(500);
        emit signalProcessFwQueryReply(sysExMessageByteArray);
    }
    */

    qDebug() << "sysex length" << sysExMessageByteArray.count();

    /*
    for(int i = 0; i < sysExMessageByteArray.size(); i++)
    {
        int x = (uint)sysExMessageByteArray.at(i);
        QString xAsHex = QString("0x%1").arg(x, 0, 16);
        qDebug() << xAsHex;
    }
    */

    qDebug() << "reply index" << sysExMessageByteArray.indexOf(QByteArray((const char*)_fw_query_reply_header, 4));

    //---------- PRE v76 reply
    if(sysExMessageByteArray.indexOf(QByteArray((const char*)_fw_query_reply_header, 4)) == 2 && sysExMessageByteArray.size() == 91 && !queryReplied)
    {
        qDebug() << "Got the reply" << sysExMessageByteArray.count();
        queryReplied = true;

#ifdef Q_OS_MAC

#else
        if(fwUpdateRequested)
        {
            fwUpdateRequested = false;
            signalFwBytesLeft(0);
            QApplication::processEvents();
        }

#endif

        //qDebug() << foundBootloaderVersion;
        //qDebug() << foundFirmwwareVersion;
        //qDebug() << expectedBootloaderVersion;
        //qDebug() << expectedFirmwareVersion;

        //emit signalFirmwareOutOfDate(expectedBootloaderVersion,foundBootloaderVersion,expectedFirmwareVersion,foundFirmwwareVersion);
        emit signalProcessFwQueryReply(sysExMessageByteArray);
    }

    //---------- POST v76 reply
    else if(sysExMessageByteArray.indexOf(QByteArray((const char*)_fw_query_reply_header, 4)) == 2 && sysExMessageByteArray.size() == 128 && !queryReplied)
    {
        qDebug() << "Got the reply p76" << sysExMessageByteArray.count();
        /*
        for(int i = 0; i < sysExMessageByteArray.size(); i++)
        {
            int x = (uint)sysExMessageByteArray.at(i);
            QString xAsHex = QString("0x%1").arg(x, 0, 16);
            qDebug() << xAsHex;
        }*/

        queryReplied = true;

#ifdef Q_OS_MAC

#else
        if(fwUpdateRequested)
        {
            fwUpdateRequested = false;
            signalFwBytesLeft(0);
            QApplication::processEvents();
        }

#endif

        emit signalProcessFwQueryReply(sysExMessageByteArray);
        qDebug() << "emit this signal!";

    }

    //If a query was sent and we got a bad reply
    else if(!queryReplied)
    {
        //slotSendSysEx("deviceQuery", _fw_query_syx_softstep, 67, "SSCOM Port 1");
        //QTimer::singleShot(1000, this, SLOT(slotDeviceQueryWait()));
    }
}

void SS_MidiDeviceManager::slotPollDevices()
{

    //static int numDevices = 0;

    if(numDevices != midiInGetNumDevs())
    {
        qDebug() << "poll devices -- attempt to connect source";
        numDevices = midiInGetNumDevs();
        connectSource();
    }
}

void SS_MidiDeviceManager::slotPollVersion()
{
    if(!queryReplied)
    {
        slotSendSysEx("deviceQuery", _fw_query_syx_softstep, 67, "SSCOM Port 1");
        emit signalConnected(false);
    }
    else
    {
        qDebug() << "STOP";
        emit signalConnected(true);
        versionPoller->stop();

        slotStandaloneOn();
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////// Callbacks ////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CALLBACK SS_MidiDeviceManager::midiInCallback(HMIDIIN hMidiIn,UINT wMsg,DWORD_PTR dwInstance,DWORD_PTR dwParam1,DWORD_PTR dwParam2)
{
    //qDebug() << "midi in" << dwParam1 << dwParam2;

    /*/qDebug() << MIM_DATA << uMsg;
    //qDebug() << dwParam;
    qDebug()    <<"status"<< ((dwParam) & 0xFF)
                << "data1" << ((dwParam>>8) & 0xFF)
                << "data2" << ((dwParam>>16) & 0xFF); //status byte*/

    SS_MidiDeviceManager *mdm = (SS_MidiDeviceManager *) dwInstance;

    switch(wMsg){
    case MIM_OPEN:
        //qDebug("MMOPEN");
        break;
    case MIM_ERROR:
        //qDebug("MMERROR");
        break;
    case MIM_LONGERROR:
        //qDebug("MIM_LONGERROR");
        break;
    case MIM_MOREDATA:
        //qDebug("MIM_MOREDATA");
        break;
    case MIM_CLOSE:
        //qDebug("MIM_ClOSE");
        break;
    case MIM_DATA:
        //qDebug("MIM_DATA");
        break;
    case MIM_LONGDATA:
    {
        qDebug("MIM_LONGDATA");

        LPMIDIHDR lpMidiHdr = (LPMIDIHDR) dwParam1;

        if(lpMidiHdr->dwBytesRecorded){

            qDebug() << "----------- Bytes Recorded -----------" << lpMidiHdr->dwBytesRecorded;

            mdm->slotProcessSysEx(QByteArray(lpMidiHdr->lpData, lpMidiHdr->dwBytesRecorded));

            midiInAddBuffer(hMidiIn, lpMidiHdr, sizeof(MIDIHDR));
        }
    }

        break;
    default:
        qDebug("in callback");
        break;
    }
}

void CALLBACK SS_MidiDeviceManager::midiOutCallback(HMIDIOUT handle, UINT uMsg, DWORD_PTR dwInstance, DWORD_PTR dwParam, DWORD_PTR dwParam1)
{
    //qDebug() <<  "msg type" << uMsg << MOM_DONE << MOM_CLOSE << MOM_OPEN;

    switch(uMsg)
    {
    case MOM_DONE:
        qDebug("MOM_DONE");
        break;
    case MOM_CLOSE:
        qDebug("MOM_CLOSE");
        break;
    case MOM_OPEN:
        qDebug("MOM_OPEN");
        break;
    default:
        qDebug("out callback");
        break;

    }

    SS_MidiDeviceManager *mda = (SS_MidiDeviceManager *) dwInstance;

    if(uMsg == MOM_DONE){
        //midiOutUnprepareHeader(mda->outHandle, &mda->sysExOutHdr, sizeof(MIDIHDR));
        //GlobalUnlock(mda->sysExOutBuffer);
        //GlobalFree(mda->sysExOutBuffer);
        //qDebug() << "MEMORy DEALLOCATED";

        if(mda->fwUpdateRequested == true)
        {
            //mda->fwUpdateRequested = false;
            //emit mda->signalFwBytesLeft(0);
            //mda->slotCloseMidiIn();
            //mda->slotCloseMidiIn();
            //mda->numDevices = 0; //Resets polling
            //qDebug() << "Get Source" << mda->getSource();
        }
    }
}

#endif
