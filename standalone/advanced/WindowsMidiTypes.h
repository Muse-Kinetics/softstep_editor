// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef WINODWSMIDITYPES_H
#define WINODWSMIDITYPES_H

#ifdef Q_OS_MAC

#else

#include <Windows.h>

typedef struct
{
    int timestamp;
    int length;

    union
    {
        DWORD dwData;
        BYTE bData[4];
    };

    unsigned char data[256];
    int timeStamp;

} MIDIPacket;

typedef int MIDIEndpointRef;

#endif //Q_OS_MAC

#endif // WINODWSMIDITYPES_H
