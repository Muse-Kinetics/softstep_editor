// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef FACTORYPRESETS_H
#define FACTORYPRESETS_H

#include <QVariant>

class FactoryPresets
{
public:
    FactoryPresets();

    QVariantMap programChangeMap;
    QVariantMap factoryElevenRackMap;
    QVariantMap factoryPodMap;
    QVariantMap factoryLiveMap;
    void        createProgramChange();
    void        createElevenRackMap();
    void        createPodMap();
    void        createLiveMap();

};

#endif // FACTORYPRESETS_H
