// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "copypastehandler.h"

CopyPasteHandler::CopyPasteHandler(PresetInterface *presetInterfacer, QObject *parent) :
    QObject(parent)
{
    presetInterface = presetInterfacer;

    slotSetCurrentKey();
}

void CopyPasteHandler::slotSetCurrentKey()
{
    currentKeyNumber = 1;
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
        if(i.key().contains(QString("%1_key").arg(currentKeyNumber)) || i.key().contains(QString("key%1_").arg(currentKeyNumber)))
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
            preset.insert(i.key(), i.value());
            //qDebug() << "paste matching value" << i.key() << i.value();
        }
    }
    presetInterface->jsonMasterMapCopy.insert(presetInterface->slotGetPresetStringFromInt(presetInterface->currentPresetNum), preset);
    presetInterface->slotRecallPreset(presetInterface->currentPresetNum);
    presetInterface->slotCheckSaveState();
}
