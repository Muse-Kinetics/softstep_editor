// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "copypastehandler.h"

CopyPasteHandler::CopyPasteHandler(PresetInterface *presetInterfacer, QObject *parent) :
    QObject(parent)
{
    presetInterface = presetInterfacer;

    //slotSetCurrentKey();
}

void CopyPasteHandler::slotSetCurrentKey(int currentKeyNum)
{
    currentKeyNumber = currentKeyNum;
    qDebug() << "from copy paste handler - current key number is:" << currentKeyNumber;
}

void CopyPasteHandler::slotCopyPreset()
{
    presetCopiedMap = presetInterface->jsonMasterMapCopy.value(presetInterface->slotGetPresetStringFromInt(presetInterface->currentPresetNum)).toMap();

    emit signalUpdatePasteAvailability();
}

void CopyPasteHandler::slotPastePreset()
{
    presetInterface->defaultPresetMap.clear();

    if(mode == "standalone")
    {
        int countModlines = 0;
        QMapIterator<QString, QVariant> map(presetCopiedMap);

        //count how many modlines are enabled
        while(map.hasNext())
        {
            map.next();

            if(map.key().contains("_enable") && map.value() == true)
            {
                countModlines++;
            }
        }

        //qDebug() << "Number of Enabled Modlines in the copied map:" << countModlines;

        if(countModlines > 50)
        {
            emit signalModlineWarning(QString("This preset exceeds the maximum number of active modlines allowed in Standalone Mode. Presets in Standalone Mode must have 50 active modlines or less. Turn off some modlines and try again."));
        }
        else
        {
            presetInterface->slotConstructDefaultStandaloneMap();
        }
    }
    else if(mode == "hosted")
    {
        presetInterface->slotConstructDefaultHostedMap();
    }

    if(!presetInterface->defaultPresetMap.isEmpty())
    {
        QMapIterator<QString, QVariant> i(presetInterface->defaultPresetMap);

        //iterate through default map and compare with the presetCopiedMap
        while(i.hasNext())
        {
            i.next();
            if(!presetCopiedMap.contains(i.key()))
            {
                //if presetCopiedMap doesn't contain a value in the default map, insert it
                presetCopiedMap.insert(i.key(), i.value());
                //qDebug() << "From slotPastePreset - this was MISSING:" << i.key() << i.value();
            }

            //if copying from one mode to the other the device menu values for port 1 should change
            if(i.key().contains("_device"))
            {
                //qDebug() << "Paste Preset Parameter" << presetCopiedMap.value(i.key());
                if(presetCopiedMap.value(i.key()) == "SSCOM Port 1" && mode == "hosted")
                {
                    presetCopiedMap.insert(i.key(), "SoftStep Share");
                    //qDebug() << "SSCOM Port 1 has been changed to SoftStep Share" << i.key();
                }
                else if(presetCopiedMap.value(i.key()) == "SoftStep Share" && mode == "standalone")
                {
                    presetCopiedMap.insert(i.key(), "SSCOM Port 1");
                    //qDebug() << "SoftStep Share has been changed to SSCOM Port 1" << i.key();
                }
            }
        }

        //check for EXTRA parameters in the copied preset
        QMapIterator<QString, QVariant> j(presetCopiedMap);
        QStringList badKeys; //stores parameters we need to remove from the map

        while(j.hasNext())
        {
            j.next();

            //If the default map does not contain something in the preset
            if(!presetInterface->defaultPresetMap.contains(j.key()))
            {
                //add to list of bad keys
                badKeys.append(j.key());
                //qDebug() << "From slotPastePreset - this was EXTRA:" << j.key() << j.value();
            }
        }
        //Iterate through the bad keys and remove from preset
        for(int i = 0; i<badKeys.count(); i++)
        {
            presetCopiedMap.remove(badKeys.at(i));
        }

        presetInterface->jsonMasterMapCopy.insert(presetInterface->slotGetPresetStringFromInt(presetInterface->currentPresetNum), presetCopiedMap);
        presetInterface->slotRecallPreset(presetInterface->currentPresetNum);
        presetInterface->slotCheckSaveState();
    }
}

void CopyPasteHandler::slotPasteNewPreset()
{
    presetInterface->defaultPresetMap.clear();

    if(mode == "standalone")
    {
        int countModlines = 0;
        QMapIterator<QString, QVariant> map(presetCopiedMap);

        //count how many modlines are enabled
        while(map.hasNext())
        {
            map.next();

            if(map.key().contains("_enable") && map.value() == true)
            {
                countModlines++;
            }
        }

        //qDebug() << "Number of Enabled Modlines in the Copied Map:" << countModlines;

        if(countModlines > 50)
        {
            emit signalModlineWarning(QString("This preset exceeds the maximum number of active modlines allowed in Standalone Mode. Presets in Standalone Mode must have 50 active modlines or less. Turn off some modlines and try again."));
        }
        else
        {
            presetInterface->slotConstructDefaultStandaloneMap();
        }
    }
    else if(mode == "hosted")
    {
        presetInterface->slotConstructDefaultHostedMap();
    }

    if(!presetInterface->defaultPresetMap.isEmpty())
    {
        QMapIterator<QString, QVariant> i(presetInterface->defaultPresetMap);

        //iterate through default map and compare with the presetCopiedMap
        while(i.hasNext())
        {
            i.next();
            if(!presetCopiedMap.contains(i.key()))
            {
                //if presetCopiedMap doesn't contain a value in the default map, insert it
                presetCopiedMap.insert(i.key(), i.value());
                //qDebug() << "From slotPastePreset - this was MISSING:" << i.key() << i.value();
            }

            //if copying from one mode to the other the device menu values for port 1 should change
            if(i.key().contains("_device"))
            {
                //qDebug() << "Paste Preset Parameter" << presetCopiedMap.value(i.key());
                if(presetCopiedMap.value(i.key()) == "SSCOM Port 1" && mode == "hosted")
                {
                    presetCopiedMap.insert(i.key(), "SoftStep Share");
                    //qDebug() << "SSCOM Port 1 has been changed to SoftStep Share";
                }
                else if(presetCopiedMap.value(i.key()) == "SoftStep Share" && mode == "standalone")
                {
                    presetCopiedMap.insert(i.key(), "SSCOM Port 1");
                    //qDebug() << "SoftStep Share has been changed to SSCOM Port 1";
                }
            }
        }

        //check for EXTRA parameters in the copied preset
        QMapIterator<QString, QVariant> j(presetCopiedMap);
        QStringList badKeys; //stores parameters we need to remove from the map

        while(j.hasNext())
        {
            j.next();

            //If the default map does not contain something in the preset
            if(!presetInterface->defaultPresetMap.contains(j.key()))
            {
                //add to list of bad keys
                badKeys.append(j.key());
                //qDebug() << "From slotPastePreset - this was EXTRA:" << j.key() << j.value();
            }
        }
        //Iterate through the bad keys and remove from preset
        for(int i = 0; i<badKeys.count(); i++)
        {
            presetCopiedMap.remove(badKeys.at(i));
        }

        //Set Imported Preset to New preset and Update
        presetInterface->presetListCopy.clear();
        presetInterface->presetListMaster.clear();

        int numPresets = presetInterface->slotGetNumPresetsInJson();

        for(int i = 0; i < numPresets; i++)
        {
            presetInterface->presetListCopy.append(presetInterface->jsonMasterMapCopy.value(presetInterface->slotGetPresetStringFromInt(i)).toMap());
            presetInterface->presetListMaster.append(presetInterface->jsonMasterMap.value(presetInterface->slotGetPresetStringFromInt(i)).toMap());
        }
        presetInterface->presetListCopy.append(presetCopiedMap);
        presetInterface->presetListMaster.append(presetCopiedMap);

        presetInterface->slotOrderPresetsInJson();
        presetInterface->slotWriteJSON(presetInterface->jsonMasterMap);
        emit signalAddRemovePreset();
        emit signalPresetMenu(numPresets);

        //presetInterface->jsonMasterMapCopy.insert(presetInterface->slotGetPresetStringFromInt(presetInterface->currentPresetNum), presetCopiedMap);
        //presetInterface->slotRecallPreset(presetInterface->currentPresetNum);
        //presetInterface->slotCheckSaveState();
    }
}

void CopyPasteHandler::slotCopyKey()
{
    //qDebug() << "slot copy key called";

    keyCopiedMap.clear();

    QVariantMap preset = presetInterface->jsonMasterMapCopy.value(presetInterface->slotGetPresetStringFromInt(presetInterface->currentPresetNum)).toMap();
    QMapIterator<QString, QVariant> i(preset);
    while(i.hasNext())
    {
        i.next();
        if(i.key().contains(QString("%1_key").arg(currentKeyNumber+1)) || i.key().contains(QString("key%1_").arg(currentKeyNumber+1)))
        {
            keyCopiedMap.insert(i.key(),i.value());
        }
    }

    emit signalUpdatePasteAvailability();
}

void CopyPasteHandler::slotPasteKey()
{
    //qDebug() << "slot paste key called";

    QVariantMap preset = presetInterface->jsonMasterMapCopy.value(presetInterface->slotGetPresetStringFromInt(presetInterface->currentPresetNum)).toMap();
    QMapIterator<QString,QVariant> i(keyCopiedMap);

    while(i.hasNext())
    {
        i.next();

        QString oldKey = i.key();
        QString newKey;
        QVariant value = i.value();

        if(preset.contains(i.key()))
        {
            if(oldKey.contains("_key_"))
            {
                //Here I need to replace the "#_key" with the currentKeyNumber+1
                if(oldKey.contains("10_key"))
                {
                    oldKey.remove(0, 2);
                    oldKey.insert(0, QString("%1").arg(currentKeyNumber+1));
                    newKey = oldKey;
                }
                else
                {
                    oldKey.remove(0, 1);
                    oldKey.insert(0, QString("%1").arg(currentKeyNumber+1));
                    newKey = oldKey;
                }
            }
            else
            {
                //Here I need to replace the "key#" with the currentKeyNumber+1
                if(oldKey.contains("key10"))
                {
                    oldKey.remove(3, 2);
                    oldKey.insert(3, QString("%1").arg(currentKeyNumber+1));
                    newKey = oldKey;
                }
                else
                {
                    oldKey.remove(3, 1);
                    oldKey.insert(3, QString("%1").arg(currentKeyNumber+1));
                    newKey = oldKey;
                }
            }
            preset.insert(newKey, value);
            //qDebug() << "paste matching value" << i.key() << newKey << i.value();
        }
    }

    if(mode == "standalone")
    {
        //count how many modlines are enabled
        int countModlines = 0;
        QMapIterator<QString, QVariant> j(preset);
        while(j.hasNext())
        {
            j.next();

            if(j.key().contains("_enable") && j.value() == true)
            {
                countModlines++;
            }
        }

        if(countModlines > 50)
        {
            emit signalModlineWarning(QString("The maximum number of active modlines allowed in Standalone Mode has been exceeded.  Some modlines on the key you just pasted may have been disabled. Presets in Standalone Mode must have 50 active modlines or less."));

            while(j.hasPrevious() && countModlines > 50)
            {
                j.previous();

                for(int i = 0; i < 6; i++)
                {
                    QString enableParameter = QString("key%1_modline%2_enable").arg(currentKeyNumber+1).arg(i+1);

                    if(j.key() == enableParameter && j.value() == true)
                    {
                        preset.insert(enableParameter, false);
                        countModlines--;
                    }
                }
            }
        }
    }
    presetInterface->jsonMasterMapCopy.insert(presetInterface->slotGetPresetStringFromInt(presetInterface->currentPresetNum), preset);
    presetInterface->slotRecallPreset(presetInterface->currentPresetNum);
    presetInterface->slotCheckSaveState();
}

void CopyPasteHandler::slotSetMode(QString m)
{
    mode = m;

    keyCopiedMap.clear();
}
