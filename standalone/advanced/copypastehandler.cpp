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
    presetInterface->jsonMasterMapCopy.insert(presetInterface->slotGetPresetStringFromInt(presetInterface->currentPresetNum), presetCopiedMap);
    presetInterface->slotRecallPreset(presetInterface->currentPresetNum);
    presetInterface->slotCheckSaveState();
}

void CopyPasteHandler::slotCopyKey()
{
    qDebug() << "slot copy key called";

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
    qDebug() << "slot paste key called";

    QVariantMap preset = presetInterface->jsonMasterMapCopy.value(presetInterface->slotGetPresetStringFromInt(presetInterface->currentPresetNum)).toMap();
    QMapIterator<QString,QVariant> i(keyCopiedMap);

    while(i.hasNext())
    {
        i.next();
        if(preset.contains(i.key()))
        {
            QString oldKey = i.key();
            QString newKey;

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

            preset.insert(newKey, i.value());
            //qDebug() << "paste matching value" << i.key() << newKey << i.value();
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
