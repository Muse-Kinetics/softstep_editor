// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "copypastehandler.h"

CopyPasteHandler::CopyPasteHandler(PresetInterface *presetInterfacer, QObject *parent) :
    QObject(parent)
{
    presetInterface = presetInterfacer;
}

void CopyPasteHandler::slotCopyPreset()
{
    presetCopiedMap = presetInterface->jsonMasterMapCopy.value(QString("Preset_00%1").arg(presetInterface->currentPresetNum)).toMap();
    qDebug() << "update paste availability";
    emit signalUpdatePasteAvailability();
}

void CopyPasteHandler::slotPastePreset()
{
    presetInterface->slotConstructDefaultMap();

    QMapIterator<QString, QVariant> i(presetInterface->defaultParamMap);

    //iterate through the default map and compare with the presetCopiedMap
    while(i.hasNext())
    {
        i.next();
        if(!presetCopiedMap.contains(i.key()))
        {
            //if presetCopiedMap doesn't contain a value in the default map, insert it
            presetCopiedMap.insert(i.key(), i.value());
            qDebug() << "From slotPastePreset - this was MISSING:" << i.key() << i.value();
        }
    }

    //check for EXTRA parameters in the copied preset
    QMapIterator<QString, QVariant> j(presetCopiedMap);
    QStringList badKeys; //stores parameters we need to remove from the map

    while(j.hasNext())
    {
        j.next();
        //If the default map does not contain something in the preset
        if(!presetInterface->defaultParamMap.contains(j.key()))
        {
            //add to list of bad keys
            badKeys.append(j.key());
            qDebug() << "From slotPastePreset - this was EXTRA:" << j.key() << j.value();
        }
    }
    //Iterate through the bad keys and remove from preset
    for(int i = 0; i<badKeys.count(); i++)
    {
        presetCopiedMap.remove(badKeys.at(i));
    }

    presetInterface->jsonMasterMapCopy.insert(QString("Preset_00%1").arg(presetInterface->currentPresetNum), presetCopiedMap);
    presetInterface->slotRecallPreset(presetInterface->currentPresetNum+1);
    presetInterface->slotCheckSaveState();
}
