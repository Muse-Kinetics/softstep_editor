// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "factorypresets.h"

FactoryPresets::FactoryPresets()
{
    createProgramChange();
    createElevenRackMap();
    createPodMap();
    createLiveMap();
}

//--------------------------------------------------------- Program Change -----------------------------------------------------//
void FactoryPresets::createProgramChange()
{
    //Preset Globals
    //programChangeMap["midiChannel"] = 1;
    //programChangeMap["sensitivity"] = 1.00;
    //programChangeMap["navPadCC"] = 7;
    //programChangeMap["pedalCC"] = 26;
    //programChangeMap["backlight"] = true;
    programChangeMap["displayname"] = "PRGM";

    programChangeMap["useFactory"] = "Program Change";


    //------------------------------------------------ Key1
    programChangeMap["key1_name"] = "1KEY";
    programChangeMap["key1_displaymode"] = 4;
    programChangeMap["key1_prefix"] = "PG";

    //Modline 1
    programChangeMap["key1_modline1_enable"] = 1;
    programChangeMap["key1_modline1_source"] = "Nav Yx10 & Key";
    programChangeMap["key1_modline1_gain"] = 1.00;
    programChangeMap["key1_modline1_offset"] = 0.00;
    programChangeMap["key1_modline1_table"] = "1_Lin";
    programChangeMap["key1_modline1_min"] = 0;
    programChangeMap["key1_modline1_max"] = 127;
    programChangeMap["key1_modline1_slew"] = 0;
    programChangeMap["key1_modline1_destination"] = "Program";
    programChangeMap["key1_modline1_channel"] = 1;
    programChangeMap["key1_modline1_device"] = "SSCOM_Port_1";
    programChangeMap["key1_modline1_ledgreen"] = "None";
    programChangeMap["key1_modline1_ledred"] = "None";
    programChangeMap["key1_modline1_displaylinked"] = 1;

    //Modline 2
    programChangeMap["key1_modline2_enable"] = 1;
    programChangeMap["key1_modline2_source"] = "Nav Yx10 & Key";
    programChangeMap["key1_modline2_gain"] = 1.00;
    programChangeMap["key1_modline2_offset"] = 0.00;
    programChangeMap["key1_modline2_table"] = "1_Lin";
    programChangeMap["key1_modline2_min"] = 0;
    programChangeMap["key1_modline2_max"] = 127;
    programChangeMap["key1_modline2_slew"] = 0;
    programChangeMap["key1_modline2_destination"] = "Program";
    programChangeMap["key1_modline2_channel"] = 1;
    programChangeMap["key1_modline2_device"] = "SoftStep_Expander";
    programChangeMap["key1_modline2_ledgreen"] = "None";
    programChangeMap["key1_modline2_ledred"] = "None";
    programChangeMap["key1_modline2_displaylinked"] = 0;

    //Modline 3
    programChangeMap["key1_modline3_enable"] = 1;
    programChangeMap["key1_modline3_source"] = "Key 1 Pressed";
    programChangeMap["key1_modline3_gain"] = 1.00;
    programChangeMap["key1_modline3_offset"] = 0.00;
    programChangeMap["key1_modline3_table"] = "1_Lin";
    programChangeMap["key1_modline3_min"] = 0;
    programChangeMap["key1_modline3_max"] = 127;
    programChangeMap["key1_modline3_slew"] = 0;
    programChangeMap["key1_modline3_destination"] = "None";
    programChangeMap["key1_modline3_channel"] = 1;
    programChangeMap["key1_modline3_device"] = "None";
    programChangeMap["key1_modline3_ledgreen"] = "True";
    programChangeMap["key1_modline3_ledred"] = "None";
    programChangeMap["key1_modline3_displaylinked"] = 0;

    //Modline 4
    programChangeMap["key1_modline4_enable"] = 1;
    programChangeMap["key1_modline4_source"] = "Other Key Pressed";
    programChangeMap["key1_modline4_gain"] = 1.00;
    programChangeMap["key1_modline4_offset"] = 0.00;
    programChangeMap["key1_modline4_table"] = "1_Lin";
    programChangeMap["key1_modline4_min"] = 0;
    programChangeMap["key1_modline4_max"] = 127;
    programChangeMap["key1_modline4_slew"] = 0;
    programChangeMap["key1_modline4_destination"] = "None";
    programChangeMap["key1_modline4_channel"] = 1;
    programChangeMap["key1_modline4_device"] = "None";
    programChangeMap["key1_modline4_ledgreen"] = "Off";
    programChangeMap["key1_modline4_ledred"] = "None";
    programChangeMap["key1_modline4_displaylinked"] = 0;

    //Modline 5
    programChangeMap["key1_modline5_enable"] = 1;
    programChangeMap["key1_modline5_source"] = "Init";
    programChangeMap["key1_modline5_gain"] = 1.00;
    programChangeMap["key1_modline5_offset"] = 127.00;
    programChangeMap["key1_modline5_table"] = "1_Lin";
    programChangeMap["key1_modline5_min"] = 0;
    programChangeMap["key1_modline5_max"] = 127;
    programChangeMap["key1_modline5_slew"] = 0;
    programChangeMap["key1_modline5_destination"] = "CC";
    programChangeMap["key1_modline5_channel"] = 1;
    programChangeMap["key1_modline5_device"] = "SSCOM_Port_1";
    programChangeMap["key1_modline5_ledgreen"] = "None";
    programChangeMap["key1_modline5_ledred"] = "None";
    programChangeMap["key1_modline5_displaylinked"] = 0;

    //Modline 6
    programChangeMap["key1_modline6_enable"] = 1;
    programChangeMap["key1_modline6_source"] = "Pedal";
    programChangeMap["key1_modline6_gain"] = 1.00;
    programChangeMap["key1_modline6_offset"] = 0.00;
    programChangeMap["key1_modline6_table"] = "1_Lin";
    programChangeMap["key1_modline6_min"] = 0;
    programChangeMap["key1_modline6_max"] = 127;
    programChangeMap["key1_modline6_slew"] = 0;
    programChangeMap["key1_modline6_destination"] = "CC";
    programChangeMap["key1_modline6_channel"] = 1;
    programChangeMap["key1_modline6_device"] = "SSCOM_Port_1";
    programChangeMap["key1_modline6_ledgreen"] = "None";
    programChangeMap["key1_modline6_ledred"] = "None";
    programChangeMap["key1_modline6_displaylinked"] = 0;

    //------------------------------------------------ Key2
    programChangeMap["key2_name"] = "2KEY";
    programChangeMap["key2_displaymode"] = 4;
    programChangeMap["key2_prefix"] = "PG";

    //Modline 1
    programChangeMap["key2_modline1_enable"] = 1;
    programChangeMap["key2_modline1_source"] = "Nav Yx10 & Key";
    programChangeMap["key2_modline1_gain"] = 1.00;
    programChangeMap["key2_modline1_offset"] = 0.00;
    programChangeMap["key2_modline1_table"] = "1_Lin";
    programChangeMap["key2_modline1_min"] = 0;
    programChangeMap["key2_modline1_max"] = 127;
    programChangeMap["key2_modline1_slew"] = 0;
    programChangeMap["key2_modline1_destination"] = "Program";
    programChangeMap["key2_modline1_channel"] = 1;
    programChangeMap["key2_modline1_device"] = "SSCOM_Port_1";
    programChangeMap["key2_modline1_ledgreen"] = "None";
    programChangeMap["key2_modline1_ledred"] = "None";
    programChangeMap["key2_modline1_displaylinked"] = 1;

    //Modline 2
    programChangeMap["key2_modline2_enable"] = 1;
    programChangeMap["key2_modline2_source"] = "Nav Yx10 & Key";
    programChangeMap["key2_modline2_gain"] = 1.00;
    programChangeMap["key2_modline2_offset"] = 0.00;
    programChangeMap["key2_modline2_table"] = "1_Lin";
    programChangeMap["key2_modline2_min"] = 0;
    programChangeMap["key2_modline2_max"] = 127;
    programChangeMap["key2_modline2_slew"] = 0;
    programChangeMap["key2_modline2_destination"] = "Program";
    programChangeMap["key2_modline2_channel"] = 1;
    programChangeMap["key2_modline2_device"] = "SoftStep_Expander";
    programChangeMap["key2_modline2_ledgreen"] = "None";
    programChangeMap["key2_modline2_ledred"] = "None";
    programChangeMap["key2_modline2_displaylinked"] = 0;

    //Modline 3
    programChangeMap["key2_modline3_enable"] = 1;
    programChangeMap["key2_modline3_source"] = "Key 2 Pressed";
    programChangeMap["key2_modline3_gain"] = 1.00;
    programChangeMap["key2_modline3_offset"] = 0.00;
    programChangeMap["key2_modline3_table"] = "1_Lin";
    programChangeMap["key2_modline3_min"] = 0;
    programChangeMap["key2_modline3_max"] = 127;
    programChangeMap["key2_modline3_slew"] = 0;
    programChangeMap["key2_modline3_destination"] = "None";
    programChangeMap["key2_modline3_channel"] = 1;
    programChangeMap["key2_modline3_device"] = "None";
    programChangeMap["key2_modline3_ledgreen"] = "True";
    programChangeMap["key2_modline3_ledred"] = "None";
    programChangeMap["key2_modline3_displaylinked"] = 0;

    //Modline 4
    programChangeMap["key2_modline4_enable"] = 1;
    programChangeMap["key2_modline4_source"] = "Other Key Pressed";
    programChangeMap["key2_modline4_gain"] = 1.00;
    programChangeMap["key2_modline4_offset"] = 0.00;
    programChangeMap["key2_modline4_table"] = "1_Lin";
    programChangeMap["key2_modline4_min"] = 0;
    programChangeMap["key2_modline4_max"] = 127;
    programChangeMap["key2_modline4_slew"] = 0;
    programChangeMap["key2_modline4_destination"] = "None";
    programChangeMap["key2_modline4_channel"] = 1;
    programChangeMap["key2_modline4_device"] = "None";
    programChangeMap["key2_modline4_ledgreen"] = "Off";
    programChangeMap["key2_modline4_ledred"] = "None";
    programChangeMap["key2_modline4_displaylinked"] = 0;

    //Modline 5
    programChangeMap["key2_modline5_enable"] = 0;
    programChangeMap["key2_modline5_source"] = "None";
    programChangeMap["key2_modline5_gain"] = 1.00;
    programChangeMap["key2_modline5_offset"] = 0.00;
    programChangeMap["key2_modline5_table"] = "1_Lin";
    programChangeMap["key2_modline5_min"] = 0;
    programChangeMap["key2_modline5_max"] = 127;
    programChangeMap["key2_modline5_slew"] = 0;
    programChangeMap["key2_modline5_destination"] = "None";
    programChangeMap["key2_modline5_channel"] = 1;
    programChangeMap["key2_modline5_device"] = "None";
    programChangeMap["key2_modline5_ledgreen"] = "None";
    programChangeMap["key2_modline5_ledred"] = "None";
    programChangeMap["key2_modline5_displaylinked"] = 0;

    //Modline 6
    programChangeMap["key2_modline6_enable"] = 0;
    programChangeMap["key2_modline6_source"] = "None";
    programChangeMap["key2_modline6_gain"] = 1.00;
    programChangeMap["key2_modline6_offset"] = 0.00;
    programChangeMap["key2_modline6_table"] = "1_Lin";
    programChangeMap["key2_modline6_min"] = 0;
    programChangeMap["key2_modline6_max"] = 127;
    programChangeMap["key2_modline6_slew"] = 0;
    programChangeMap["key2_modline6_destination"] = "None";
    programChangeMap["key2_modline6_channel"] = 1;
    programChangeMap["key2_modline6_device"] = "None";
    programChangeMap["key2_modline6_ledgreen"] = "None";
    programChangeMap["key2_modline6_ledred"] = "None";
    programChangeMap["key2_modline6_displaylinked"] = 0;

    //------------------------------------------------ Key3
    programChangeMap["key3_name"] = "3KEY";
    programChangeMap["key3_displaymode"] = 4;
    programChangeMap["key3_prefix"] = "PG";

    //Modline 1
    programChangeMap["key3_modline1_enable"] = 1;
    programChangeMap["key3_modline1_source"] = "Nav Yx10 & Key";
    programChangeMap["key3_modline1_gain"] = 1.00;
    programChangeMap["key3_modline1_offset"] = 0.00;
    programChangeMap["key3_modline1_table"] = "1_Lin";
    programChangeMap["key3_modline1_min"] = 0;
    programChangeMap["key3_modline1_max"] = 127;
    programChangeMap["key3_modline1_slew"] = 0;
    programChangeMap["key3_modline1_destination"] = "Program";
    programChangeMap["key3_modline1_channel"] = 1;
    programChangeMap["key3_modline1_device"] = "SSCOM_Port_1";
    programChangeMap["key3_modline1_ledgreen"] = "None";
    programChangeMap["key3_modline1_ledred"] = "None";
    programChangeMap["key3_modline1_displaylinked"] = 1;

    //Modline 2
    programChangeMap["key3_modline2_enable"] = 1;
    programChangeMap["key3_modline2_source"] = "Nav Yx10 & Key";
    programChangeMap["key3_modline2_gain"] = 1.00;
    programChangeMap["key3_modline2_offset"] = 0.00;
    programChangeMap["key3_modline2_table"] = "1_Lin";
    programChangeMap["key3_modline2_min"] = 0;
    programChangeMap["key3_modline2_max"] = 127;
    programChangeMap["key3_modline2_slew"] = 0;
    programChangeMap["key3_modline2_destination"] = "Program";
    programChangeMap["key3_modline2_channel"] = 1;
    programChangeMap["key3_modline2_device"] = "SoftStep_Expander";
    programChangeMap["key3_modline2_ledgreen"] = "None";
    programChangeMap["key3_modline2_ledred"] = "None";
    programChangeMap["key3_modline2_displaylinked"] = 0;

    //Modline 3
    programChangeMap["key3_modline3_enable"] = 1;
    programChangeMap["key3_modline3_source"] = "Key 3 Pressed";
    programChangeMap["key3_modline3_gain"] = 1.00;
    programChangeMap["key3_modline3_offset"] = 0.00;
    programChangeMap["key3_modline3_table"] = "1_Lin";
    programChangeMap["key3_modline3_min"] = 0;
    programChangeMap["key3_modline3_max"] = 127;
    programChangeMap["key3_modline3_slew"] = 0;
    programChangeMap["key3_modline3_destination"] = "None";
    programChangeMap["key3_modline3_channel"] = 1;
    programChangeMap["key3_modline3_device"] = "None";
    programChangeMap["key3_modline3_ledgreen"] = "True";
    programChangeMap["key3_modline3_ledred"] = "None";
    programChangeMap["key3_modline3_displaylinked"] = 0;

    //Modline 4
    programChangeMap["key3_modline4_enable"] = 1;
    programChangeMap["key3_modline4_source"] = "Other Key Pressed";
    programChangeMap["key3_modline4_gain"] = 1.00;
    programChangeMap["key3_modline4_offset"] = 0.00;
    programChangeMap["key3_modline4_table"] = "1_Lin";
    programChangeMap["key3_modline4_min"] = 0;
    programChangeMap["key3_modline4_max"] = 127;
    programChangeMap["key3_modline4_slew"] = 0;
    programChangeMap["key3_modline4_destination"] = "None";
    programChangeMap["key3_modline4_channel"] = 1;
    programChangeMap["key3_modline4_device"] = "None";
    programChangeMap["key3_modline4_ledgreen"] = "Off";
    programChangeMap["key3_modline4_ledred"] = "None";
    programChangeMap["key3_modline4_displaylinked"] = 0;

    //Modline 5
    programChangeMap["key3_modline5_enable"] = 0;
    programChangeMap["key3_modline5_source"] = "None";
    programChangeMap["key3_modline5_gain"] = 1.00;
    programChangeMap["key3_modline5_offset"] = 0.00;
    programChangeMap["key3_modline5_table"] = "1_Lin";
    programChangeMap["key3_modline5_min"] = 0;
    programChangeMap["key3_modline5_max"] = 127;
    programChangeMap["key3_modline5_slew"] = 0;
    programChangeMap["key3_modline5_destination"] = "None";
    programChangeMap["key3_modline5_channel"] = 1;
    programChangeMap["key3_modline5_device"] = "None";
    programChangeMap["key3_modline5_ledgreen"] = "None";
    programChangeMap["key3_modline5_ledred"] = "None";
    programChangeMap["key3_modline5_displaylinked"] = 0;

    //Modline 6
    programChangeMap["key3_modline6_enable"] = 0;
    programChangeMap["key3_modline6_source"] = "None";
    programChangeMap["key3_modline6_gain"] = 1.00;
    programChangeMap["key3_modline6_offset"] = 0.00;
    programChangeMap["key3_modline6_table"] = "1_Lin";
    programChangeMap["key3_modline6_min"] = 0;
    programChangeMap["key3_modline6_max"] = 127;
    programChangeMap["key3_modline6_slew"] = 0;
    programChangeMap["key3_modline6_destination"] = "None";
    programChangeMap["key3_modline6_channel"] = 1;
    programChangeMap["key3_modline6_device"] = "None";
    programChangeMap["key3_modline6_ledgreen"] = "None";
    programChangeMap["key3_modline6_ledred"] = "None";
    programChangeMap["key3_modline6_displaylinked"] = 0;

    //------------------------------------------------ Key4
    programChangeMap["key4_name"] = "4KEY";
    programChangeMap["key4_displaymode"] = 4;
    programChangeMap["key4_prefix"] = "PG";

    //Modline 1
    programChangeMap["key4_modline1_enable"] = 1;
    programChangeMap["key4_modline1_source"] = "Nav Yx10 & Key";
    programChangeMap["key4_modline1_gain"] = 1.00;
    programChangeMap["key4_modline1_offset"] = 0.00;
    programChangeMap["key4_modline1_table"] = "1_Lin";
    programChangeMap["key4_modline1_min"] = 0;
    programChangeMap["key4_modline1_max"] = 127;
    programChangeMap["key4_modline1_slew"] = 0;
    programChangeMap["key4_modline1_destination"] = "Program";
    programChangeMap["key4_modline1_channel"] = 1;
    programChangeMap["key4_modline1_device"] = "SSCOM_Port_1";
    programChangeMap["key4_modline1_ledgreen"] = "None";
    programChangeMap["key4_modline1_ledred"] = "None";
    programChangeMap["key4_modline1_displaylinked"] = 1;

    //Modline 2
    programChangeMap["key4_modline2_enable"] = 1;
    programChangeMap["key4_modline2_source"] = "Nav Yx10 & Key";
    programChangeMap["key4_modline2_gain"] = 1.00;
    programChangeMap["key4_modline2_offset"] = 0.00;
    programChangeMap["key4_modline2_table"] = "1_Lin";
    programChangeMap["key4_modline2_min"] = 0;
    programChangeMap["key4_modline2_max"] = 127;
    programChangeMap["key4_modline2_slew"] = 0;
    programChangeMap["key4_modline2_destination"] = "Program";
    programChangeMap["key4_modline2_channel"] = 1;
    programChangeMap["key4_modline2_device"] = "SoftStep_Expander";
    programChangeMap["key4_modline2_ledgreen"] = "None";
    programChangeMap["key4_modline2_ledred"] = "None";
    programChangeMap["key4_modline2_displaylinked"] = 0;

    //Modline 3
    programChangeMap["key4_modline3_enable"] = 1;
    programChangeMap["key4_modline3_source"] = "Key 4 Pressed";
    programChangeMap["key4_modline3_gain"] = 1.00;
    programChangeMap["key4_modline3_offset"] = 0.00;
    programChangeMap["key4_modline3_table"] = "1_Lin";
    programChangeMap["key4_modline3_min"] = 0;
    programChangeMap["key4_modline3_max"] = 127;
    programChangeMap["key4_modline3_slew"] = 0;
    programChangeMap["key4_modline3_destination"] = "None";
    programChangeMap["key4_modline3_channel"] = 1;
    programChangeMap["key4_modline3_device"] = "None";
    programChangeMap["key4_modline3_ledgreen"] = "True";
    programChangeMap["key4_modline3_ledred"] = "None";
    programChangeMap["key4_modline3_displaylinked"] = 0;

    //Modline 4
    programChangeMap["key4_modline4_enable"] = 1;
    programChangeMap["key4_modline4_source"] = "Other Key Pressed";
    programChangeMap["key4_modline4_gain"] = 1.00;
    programChangeMap["key4_modline4_offset"] = 0.00;
    programChangeMap["key4_modline4_table"] = "1_Lin";
    programChangeMap["key4_modline4_min"] = 0;
    programChangeMap["key4_modline4_max"] = 127;
    programChangeMap["key4_modline4_slew"] = 0;
    programChangeMap["key4_modline4_destination"] = "None";
    programChangeMap["key4_modline4_channel"] = 1;
    programChangeMap["key4_modline4_device"] = "None";
    programChangeMap["key4_modline4_ledgreen"] = "Off";
    programChangeMap["key4_modline4_ledred"] = "None";
    programChangeMap["key4_modline4_displaylinked"] = 0;

    //Modline 5
    programChangeMap["key4_modline5_enable"] = 0;
    programChangeMap["key4_modline5_source"] = "None";
    programChangeMap["key4_modline5_gain"] = 1.00;
    programChangeMap["key4_modline5_offset"] = 0.00;
    programChangeMap["key4_modline5_table"] = "1_Lin";
    programChangeMap["key4_modline5_min"] = 0;
    programChangeMap["key4_modline5_max"] = 127;
    programChangeMap["key4_modline5_slew"] = 0;
    programChangeMap["key4_modline5_destination"] = "None";
    programChangeMap["key4_modline5_channel"] = 1;
    programChangeMap["key4_modline5_device"] = "None";
    programChangeMap["key4_modline5_ledgreen"] = "None";
    programChangeMap["key4_modline5_ledred"] = "None";
    programChangeMap["key4_modline5_displaylinked"] = 0;

    //Modline 6
    programChangeMap["key4_modline6_enable"] = 0;
    programChangeMap["key4_modline6_source"] = "None";
    programChangeMap["key4_modline6_gain"] = 1.00;
    programChangeMap["key4_modline6_offset"] = 0.00;
    programChangeMap["key4_modline6_table"] = "1_Lin";
    programChangeMap["key4_modline6_min"] = 0;
    programChangeMap["key4_modline6_max"] = 127;
    programChangeMap["key4_modline6_slew"] = 0;
    programChangeMap["key4_modline6_destination"] = "None";
    programChangeMap["key4_modline6_channel"] = 1;
    programChangeMap["key4_modline6_device"] = "None";
    programChangeMap["key4_modline6_ledgreen"] = "None";
    programChangeMap["key4_modline6_ledred"] = "None";
    programChangeMap["key4_modline6_displaylinked"] = 0;

    //------------------------------------------------ Key5
    programChangeMap["key5_name"] = "5KEY";
    programChangeMap["key5_displaymode"] = 4;
    programChangeMap["key5_prefix"] = "PG";

    //Modline 1
    programChangeMap["key5_modline1_enable"] = 1;
    programChangeMap["key5_modline1_source"] = "Nav Yx10 & Key";
    programChangeMap["key5_modline1_gain"] = 1.00;
    programChangeMap["key5_modline1_offset"] = 0.00;
    programChangeMap["key5_modline1_table"] = "1_Lin";
    programChangeMap["key5_modline1_min"] = 0;
    programChangeMap["key5_modline1_max"] = 127;
    programChangeMap["key5_modline1_slew"] = 0;
    programChangeMap["key5_modline1_destination"] = "Program";
    programChangeMap["key5_modline1_channel"] = 1;
    programChangeMap["key5_modline1_device"] = "SSCOM_Port_1";
    programChangeMap["key5_modline1_ledgreen"] = "None";
    programChangeMap["key5_modline1_ledred"] = "None";
    programChangeMap["key5_modline1_displaylinked"] = 1;

    //Modline 2
    programChangeMap["key5_modline2_enable"] = 1;
    programChangeMap["key5_modline2_source"] = "Nav Yx10 & Key";
    programChangeMap["key5_modline2_gain"] = 1.00;
    programChangeMap["key5_modline2_offset"] = 0.00;
    programChangeMap["key5_modline2_table"] = "1_Lin";
    programChangeMap["key5_modline2_min"] = 0;
    programChangeMap["key5_modline2_max"] = 127;
    programChangeMap["key5_modline2_slew"] = 0;
    programChangeMap["key5_modline2_destination"] = "Program";
    programChangeMap["key5_modline2_channel"] = 1;
    programChangeMap["key5_modline2_device"] = "SoftStep_Expander";
    programChangeMap["key5_modline2_ledgreen"] = "None";
    programChangeMap["key5_modline2_ledred"] = "None";
    programChangeMap["key5_modline2_displaylinked"] = 0;

    //Modline 3
    programChangeMap["key5_modline3_enable"] = 1;
    programChangeMap["key5_modline3_source"] = "Key 5 Pressed";
    programChangeMap["key5_modline3_gain"] = 1.00;
    programChangeMap["key5_modline3_offset"] = 0.00;
    programChangeMap["key5_modline3_table"] = "1_Lin";
    programChangeMap["key5_modline3_min"] = 0;
    programChangeMap["key5_modline3_max"] = 127;
    programChangeMap["key5_modline3_slew"] = 0;
    programChangeMap["key5_modline3_destination"] = "None";
    programChangeMap["key5_modline3_channel"] = 1;
    programChangeMap["key5_modline3_device"] = "None";
    programChangeMap["key5_modline3_ledgreen"] = "True";
    programChangeMap["key5_modline3_ledred"] = "None";
    programChangeMap["key5_modline3_displaylinked"] = 0;

    //Modline 4
    programChangeMap["key5_modline4_enable"] = 1;
    programChangeMap["key5_modline4_source"] = "Other Key Pressed";
    programChangeMap["key5_modline4_gain"] = 1.00;
    programChangeMap["key5_modline4_offset"] = 0.00;
    programChangeMap["key5_modline4_table"] = "1_Lin";
    programChangeMap["key5_modline4_min"] = 0;
    programChangeMap["key5_modline4_max"] = 127;
    programChangeMap["key5_modline4_slew"] = 0;
    programChangeMap["key5_modline4_destination"] = "None";
    programChangeMap["key5_modline4_channel"] = 1;
    programChangeMap["key5_modline4_device"] = "None";
    programChangeMap["key5_modline4_ledgreen"] = "Off";
    programChangeMap["key5_modline4_ledred"] = "None";
    programChangeMap["key5_modline4_displaylinked"] = 0;

    //Modline 5
    programChangeMap["key5_modline5_enable"] = 0;
    programChangeMap["key5_modline5_source"] = "None";
    programChangeMap["key5_modline5_gain"] = 1.00;
    programChangeMap["key5_modline5_offset"] = 0.00;
    programChangeMap["key5_modline5_table"] = "1_Lin";
    programChangeMap["key5_modline5_min"] = 0;
    programChangeMap["key5_modline5_max"] = 127;
    programChangeMap["key5_modline5_slew"] = 0;
    programChangeMap["key5_modline5_destination"] = "None";
    programChangeMap["key5_modline5_channel"] = 1;
    programChangeMap["key5_modline5_device"] = "None";
    programChangeMap["key5_modline5_ledgreen"] = "None";
    programChangeMap["key5_modline5_ledred"] = "None";
    programChangeMap["key5_modline5_displaylinked"] = 0;

    //Modline 6
    programChangeMap["key5_modline6_enable"] = 0;
    programChangeMap["key5_modline6_source"] = "None";
    programChangeMap["key5_modline6_gain"] = 1.00;
    programChangeMap["key5_modline6_offset"] = 0.00;
    programChangeMap["key5_modline6_table"] = "1_Lin";
    programChangeMap["key5_modline6_min"] = 0;
    programChangeMap["key5_modline6_max"] = 127;
    programChangeMap["key5_modline6_slew"] = 0;
    programChangeMap["key5_modline6_destination"] = "None";
    programChangeMap["key5_modline6_channel"] = 1;
    programChangeMap["key5_modline6_device"] = "None";
    programChangeMap["key5_modline6_ledgreen"] = "None";
    programChangeMap["key5_modline6_ledred"] = "None";
    programChangeMap["key5_modline6_displaylinked"] = 0;

    //------------------------------------------------ Key6
    programChangeMap["key6_name"] = "6KEY";
    programChangeMap["key6_displaymode"] = 4;
    programChangeMap["key6_prefix"] = "PG";

    //Modline 1
    programChangeMap["key6_modline1_enable"] = 1;
    programChangeMap["key6_modline1_source"] = "Nav Yx10 & Key";
    programChangeMap["key6_modline1_gain"] = 1.00;
    programChangeMap["key6_modline1_offset"] = 0.00;
    programChangeMap["key6_modline1_table"] = "1_Lin";
    programChangeMap["key6_modline1_min"] = 0;
    programChangeMap["key6_modline1_max"] = 127;
    programChangeMap["key6_modline1_slew"] = 0;
    programChangeMap["key6_modline1_destination"] = "Program";
    programChangeMap["key6_modline1_channel"] = 1;
    programChangeMap["key6_modline1_device"] = "SSCOM_Port_1";
    programChangeMap["key6_modline1_ledgreen"] = "None";
    programChangeMap["key6_modline1_ledred"] = "None";
    programChangeMap["key6_modline1_displaylinked"] = 1;

    //Modline 2
    programChangeMap["key6_modline2_enable"] = 1;
    programChangeMap["key6_modline2_source"] = "Nav Yx10 & Key";
    programChangeMap["key6_modline2_gain"] = 1.00;
    programChangeMap["key6_modline2_offset"] = 0.00;
    programChangeMap["key6_modline2_table"] = "1_Lin";
    programChangeMap["key6_modline2_min"] = 0;
    programChangeMap["key6_modline2_max"] = 127;
    programChangeMap["key6_modline2_slew"] = 0;
    programChangeMap["key6_modline2_destination"] = "Program";
    programChangeMap["key6_modline2_channel"] = 1;
    programChangeMap["key6_modline2_device"] = "SoftStep_Expander";
    programChangeMap["key6_modline2_ledgreen"] = "None";
    programChangeMap["key6_modline2_ledred"] = "None";
    programChangeMap["key6_modline2_displaylinked"] = 0;

    //Modline 3
    programChangeMap["key6_modline3_enable"] = 1;
    programChangeMap["key6_modline3_source"] = "Key 6 Pressed";
    programChangeMap["key6_modline3_gain"] = 1.00;
    programChangeMap["key6_modline3_offset"] = 0.00;
    programChangeMap["key6_modline3_table"] = "1_Lin";
    programChangeMap["key6_modline3_min"] = 0;
    programChangeMap["key6_modline3_max"] = 127;
    programChangeMap["key6_modline3_slew"] = 0;
    programChangeMap["key6_modline3_destination"] = "None";
    programChangeMap["key6_modline3_channel"] = 1;
    programChangeMap["key6_modline3_device"] = "None";
    programChangeMap["key6_modline3_ledgreen"] = "True";
    programChangeMap["key6_modline3_ledred"] = "None";
    programChangeMap["key6_modline3_displaylinked"] = 0;

    //Modline 4
    programChangeMap["key6_modline4_enable"] = 1;
    programChangeMap["key6_modline4_source"] = "Other Key Pressed";
    programChangeMap["key6_modline4_gain"] = 1.00;
    programChangeMap["key6_modline4_offset"] = 0.00;
    programChangeMap["key6_modline4_table"] = "1_Lin";
    programChangeMap["key6_modline4_min"] = 0;
    programChangeMap["key6_modline4_max"] = 127;
    programChangeMap["key6_modline4_slew"] = 0;
    programChangeMap["key6_modline4_destination"] = "None";
    programChangeMap["key6_modline4_channel"] = 1;
    programChangeMap["key6_modline4_device"] = "None";
    programChangeMap["key6_modline4_ledgreen"] = "Off";
    programChangeMap["key6_modline4_ledred"] = "None";
    programChangeMap["key6_modline4_displaylinked"] = 0;

    //Modline 5
    programChangeMap["key6_modline5_enable"] = 0;
    programChangeMap["key6_modline5_source"] = "None";
    programChangeMap["key6_modline5_gain"] = 1.00;
    programChangeMap["key6_modline5_offset"] = 0.00;
    programChangeMap["key6_modline5_table"] = "1_Lin";
    programChangeMap["key6_modline5_min"] = 0;
    programChangeMap["key6_modline5_max"] = 127;
    programChangeMap["key6_modline5_slew"] = 0;
    programChangeMap["key6_modline5_destination"] = "None";
    programChangeMap["key6_modline5_channel"] = 1;
    programChangeMap["key6_modline5_device"] = "None";
    programChangeMap["key6_modline5_ledgreen"] = "None";
    programChangeMap["key6_modline5_ledred"] = "None";
    programChangeMap["key6_modline5_displaylinked"] = 0;

    //Modline 6
    programChangeMap["key6_modline6_enable"] = 0;
    programChangeMap["key6_modline6_source"] = "None";
    programChangeMap["key6_modline6_gain"] = 1.00;
    programChangeMap["key6_modline6_offset"] = 0.00;
    programChangeMap["key6_modline6_table"] = "1_Lin";
    programChangeMap["key6_modline6_min"] = 0;
    programChangeMap["key6_modline6_max"] = 127;
    programChangeMap["key6_modline6_slew"] = 0;
    programChangeMap["key6_modline6_destination"] = "None";
    programChangeMap["key6_modline6_channel"] = 1;
    programChangeMap["key6_modline6_device"] = "None";
    programChangeMap["key6_modline6_ledgreen"] = "None";
    programChangeMap["key6_modline6_ledred"] = "None";
    programChangeMap["key6_modline6_displaylinked"] = 0;

    //------------------------------------------------ Key7
    programChangeMap["key7_name"] = "7KEY";
    programChangeMap["key7_displaymode"] = 4;
    programChangeMap["key7_prefix"] = "PG";

    //Modline 1
    programChangeMap["key7_modline1_enable"] = 1;
    programChangeMap["key7_modline1_source"] = "Nav Yx10 & Key";
    programChangeMap["key7_modline1_gain"] = 1.00;
    programChangeMap["key7_modline1_offset"] = 0.00;
    programChangeMap["key7_modline1_table"] = "1_Lin";
    programChangeMap["key7_modline1_min"] = 0;
    programChangeMap["key7_modline1_max"] = 127;
    programChangeMap["key7_modline1_slew"] = 0;
    programChangeMap["key7_modline1_destination"] = "Program";
    programChangeMap["key7_modline1_channel"] = 1;
    programChangeMap["key7_modline1_device"] = "SSCOM_Port_1";
    programChangeMap["key7_modline1_ledgreen"] = "None";
    programChangeMap["key7_modline1_ledred"] = "None";
    programChangeMap["key7_modline1_displaylinked"] = 1;

    //Modline 2
    programChangeMap["key7_modline2_enable"] = 1;
    programChangeMap["key7_modline2_source"] = "Nav Yx10 & Key";
    programChangeMap["key7_modline2_gain"] = 1.00;
    programChangeMap["key7_modline2_offset"] = 0.00;
    programChangeMap["key7_modline2_table"] = "1_Lin";
    programChangeMap["key7_modline2_min"] = 0;
    programChangeMap["key7_modline2_max"] = 127;
    programChangeMap["key7_modline2_slew"] = 0;
    programChangeMap["key7_modline2_destination"] = "Program";
    programChangeMap["key7_modline2_channel"] = 1;
    programChangeMap["key7_modline2_device"] = "SoftStep_Expander";
    programChangeMap["key7_modline2_ledgreen"] = "None";
    programChangeMap["key7_modline2_ledred"] = "None";
    programChangeMap["key7_modline2_displaylinked"] = 0;

    //Modline 3
    programChangeMap["key7_modline3_enable"] = 1;
    programChangeMap["key7_modline3_source"] = "Key 7 Pressed";
    programChangeMap["key7_modline3_gain"] = 1.00;
    programChangeMap["key7_modline3_offset"] = 0.00;
    programChangeMap["key7_modline3_table"] = "1_Lin";
    programChangeMap["key7_modline3_min"] = 0;
    programChangeMap["key7_modline3_max"] = 127;
    programChangeMap["key7_modline3_slew"] = 0;
    programChangeMap["key7_modline3_destination"] = "None";
    programChangeMap["key7_modline3_channel"] = 1;
    programChangeMap["key7_modline3_device"] = "None";
    programChangeMap["key7_modline3_ledgreen"] = "True";
    programChangeMap["key7_modline3_ledred"] = "None";
    programChangeMap["key7_modline3_displaylinked"] = 0;

    //Modline 4
    programChangeMap["key7_modline4_enable"] = 1;
    programChangeMap["key7_modline4_source"] = "Other Key Pressed";
    programChangeMap["key7_modline4_gain"] = 1.00;
    programChangeMap["key7_modline4_offset"] = 0.00;
    programChangeMap["key7_modline4_table"] = "1_Lin";
    programChangeMap["key7_modline4_min"] = 0;
    programChangeMap["key7_modline4_max"] = 127;
    programChangeMap["key7_modline4_slew"] = 0;
    programChangeMap["key7_modline4_destination"] = "None";
    programChangeMap["key7_modline4_channel"] = 1;
    programChangeMap["key7_modline4_device"] = "None";
    programChangeMap["key7_modline4_ledgreen"] = "Off";
    programChangeMap["key7_modline4_ledred"] = "None";
    programChangeMap["key7_modline4_displaylinked"] = 0;

    //Modline 5
    programChangeMap["key7_modline5_enable"] = 0;
    programChangeMap["key7_modline5_source"] = "None";
    programChangeMap["key7_modline5_gain"] = 1.00;
    programChangeMap["key7_modline5_offset"] = 0.00;
    programChangeMap["key7_modline5_table"] = "1_Lin";
    programChangeMap["key7_modline5_min"] = 0;
    programChangeMap["key7_modline5_max"] = 127;
    programChangeMap["key7_modline5_slew"] = 0;
    programChangeMap["key7_modline5_destination"] = "None";
    programChangeMap["key7_modline5_channel"] = 1;
    programChangeMap["key7_modline5_device"] = "None";
    programChangeMap["key7_modline5_ledgreen"] = "None";
    programChangeMap["key7_modline5_ledred"] = "None";
    programChangeMap["key7_modline5_displaylinked"] = 0;

    //Modline 6
    programChangeMap["key7_modline6_enable"] = 0;
    programChangeMap["key7_modline6_source"] = "None";
    programChangeMap["key7_modline6_gain"] = 1.00;
    programChangeMap["key7_modline6_offset"] = 0.00;
    programChangeMap["key7_modline6_table"] = "1_Lin";
    programChangeMap["key7_modline6_min"] = 0;
    programChangeMap["key7_modline6_max"] = 127;
    programChangeMap["key7_modline6_slew"] = 0;
    programChangeMap["key7_modline6_destination"] = "None";
    programChangeMap["key7_modline6_channel"] = 1;
    programChangeMap["key7_modline6_device"] = "None";
    programChangeMap["key7_modline6_ledgreen"] = "None";
    programChangeMap["key7_modline6_ledred"] = "None";
    programChangeMap["key7_modline6_displaylinked"] = 0;

    //------------------------------------------------ Key8
    programChangeMap["key8_name"] = "8KEY";
    programChangeMap["key8_displaymode"] = 4;
    programChangeMap["key8_prefix"] = "PG";

    //Modline 1
    programChangeMap["key8_modline1_enable"] = 1;
    programChangeMap["key8_modline1_source"] = "Nav Yx10 & Key";
    programChangeMap["key8_modline1_gain"] = 1.00;
    programChangeMap["key8_modline1_offset"] = 0.00;
    programChangeMap["key8_modline1_table"] = "1_Lin";
    programChangeMap["key8_modline1_min"] = 0;
    programChangeMap["key8_modline1_max"] = 127;
    programChangeMap["key8_modline1_slew"] = 0;
    programChangeMap["key8_modline1_destination"] = "Program";
    programChangeMap["key8_modline1_channel"] = 1;
    programChangeMap["key8_modline1_device"] = "SSCOM_Port_1";
    programChangeMap["key8_modline1_ledgreen"] = "None";
    programChangeMap["key8_modline1_ledred"] = "None";
    programChangeMap["key8_modline1_displaylinked"] = 1;

    //Modline 2
    programChangeMap["key8_modline2_enable"] = 1;
    programChangeMap["key8_modline2_source"] = "Nav Yx10 & Key";
    programChangeMap["key8_modline2_gain"] = 1.00;
    programChangeMap["key8_modline2_offset"] = 0.00;
    programChangeMap["key8_modline2_table"] = "1_Lin";
    programChangeMap["key8_modline2_min"] = 0;
    programChangeMap["key8_modline2_max"] = 127;
    programChangeMap["key8_modline2_slew"] = 0;
    programChangeMap["key8_modline2_destination"] = "Program";
    programChangeMap["key8_modline2_channel"] = 1;
    programChangeMap["key8_modline2_device"] = "SoftStep_Expander";
    programChangeMap["key8_modline2_ledgreen"] = "None";
    programChangeMap["key8_modline2_ledred"] = "None";
    programChangeMap["key8_modline2_displaylinked"] = 0;

    //Modline 3
    programChangeMap["key8_modline3_enable"] = 1;
    programChangeMap["key8_modline3_source"] = "Key 8 Pressed";
    programChangeMap["key8_modline3_gain"] = 1.00;
    programChangeMap["key8_modline3_offset"] = 0.00;
    programChangeMap["key8_modline3_table"] = "1_Lin";
    programChangeMap["key8_modline3_min"] = 0;
    programChangeMap["key8_modline3_max"] = 127;
    programChangeMap["key8_modline3_slew"] = 0;
    programChangeMap["key8_modline3_destination"] = "None";
    programChangeMap["key8_modline3_channel"] = 1;
    programChangeMap["key8_modline3_device"] = "None";
    programChangeMap["key8_modline3_ledgreen"] = "True";
    programChangeMap["key8_modline3_ledred"] = "None";
    programChangeMap["key8_modline3_displaylinked"] = 0;

    //Modline 4
    programChangeMap["key8_modline4_enable"] = 1;
    programChangeMap["key8_modline4_source"] = "Other Key Pressed";
    programChangeMap["key8_modline4_gain"] = 1.00;
    programChangeMap["key8_modline4_offset"] = 0.00;
    programChangeMap["key8_modline4_table"] = "1_Lin";
    programChangeMap["key8_modline4_min"] = 0;
    programChangeMap["key8_modline4_max"] = 127;
    programChangeMap["key8_modline4_slew"] = 0;
    programChangeMap["key8_modline4_destination"] = "None";
    programChangeMap["key8_modline4_channel"] = 1;
    programChangeMap["key8_modline4_device"] = "None";
    programChangeMap["key8_modline4_ledgreen"] = "Off";
    programChangeMap["key8_modline4_ledred"] = "None";
    programChangeMap["key8_modline4_displaylinked"] = 0;

    //Modline 5
    programChangeMap["key8_modline5_enable"] = 0;
    programChangeMap["key8_modline5_source"] = "None";
    programChangeMap["key8_modline5_gain"] = 1.00;
    programChangeMap["key8_modline5_offset"] = 0.00;
    programChangeMap["key8_modline5_table"] = "1_Lin";
    programChangeMap["key8_modline5_min"] = 0;
    programChangeMap["key8_modline5_max"] = 127;
    programChangeMap["key8_modline5_slew"] = 0;
    programChangeMap["key8_modline5_destination"] = "None";
    programChangeMap["key8_modline5_channel"] = 1;
    programChangeMap["key8_modline5_device"] = "None";
    programChangeMap["key8_modline5_ledgreen"] = "None";
    programChangeMap["key8_modline5_ledred"] = "None";
    programChangeMap["key8_modline5_displaylinked"] = 0;

    //Modline 6
    programChangeMap["key8_modline6_enable"] = 0;
    programChangeMap["key8_modline6_source"] = "None";
    programChangeMap["key8_modline6_gain"] = 1.00;
    programChangeMap["key8_modline6_offset"] = 0.00;
    programChangeMap["key8_modline6_table"] = "1_Lin";
    programChangeMap["key8_modline6_min"] = 0;
    programChangeMap["key8_modline6_max"] = 127;
    programChangeMap["key8_modline6_slew"] = 0;
    programChangeMap["key8_modline6_destination"] = "None";
    programChangeMap["key8_modline6_channel"] = 1;
    programChangeMap["key8_modline6_device"] = "None";
    programChangeMap["key8_modline6_ledgreen"] = "None";
    programChangeMap["key8_modline6_ledred"] = "None";
    programChangeMap["key8_modline6_displaylinked"] = 0;

    //------------------------------------------------ Key9
    programChangeMap["key9_name"] = "9KEY";
    programChangeMap["key9_displaymode"] = 4;
    programChangeMap["key9_prefix"] = "PG";

    //Modline 1
    programChangeMap["key9_modline1_enable"] = 1;
    programChangeMap["key9_modline1_source"] = "Nav Yx10 & Key";
    programChangeMap["key9_modline1_gain"] = 1.00;
    programChangeMap["key9_modline1_offset"] = 0.00;
    programChangeMap["key9_modline1_table"] = "1_Lin";
    programChangeMap["key9_modline1_min"] = 0;
    programChangeMap["key9_modline1_max"] = 127;
    programChangeMap["key9_modline1_slew"] = 0;
    programChangeMap["key9_modline1_destination"] = "Program";
    programChangeMap["key9_modline1_channel"] = 1;
    programChangeMap["key9_modline1_device"] = "SSCOM_Port_1";
    programChangeMap["key9_modline1_ledgreen"] = "None";
    programChangeMap["key9_modline1_ledred"] = "None";
    programChangeMap["key9_modline1_displaylinked"] = 1;

    //Modline 2
    programChangeMap["key9_modline2_enable"] = 1;
    programChangeMap["key9_modline2_source"] = "Nav Yx10 & Key";
    programChangeMap["key9_modline2_gain"] = 1.00;
    programChangeMap["key9_modline2_offset"] = 0.00;
    programChangeMap["key9_modline2_table"] = "1_Lin";
    programChangeMap["key9_modline2_min"] = 0;
    programChangeMap["key9_modline2_max"] = 127;
    programChangeMap["key9_modline2_slew"] = 0;
    programChangeMap["key9_modline2_destination"] = "Program";
    programChangeMap["key9_modline2_channel"] = 1;
    programChangeMap["key9_modline2_device"] = "SoftStep_Expander";
    programChangeMap["key9_modline2_ledgreen"] = "None";
    programChangeMap["key9_modline2_ledred"] = "None";
    programChangeMap["key9_modline2_displaylinked"] = 0;

    //Modline 3
    programChangeMap["key9_modline3_enable"] = 1;
    programChangeMap["key9_modline3_source"] = "Key 9 Pressed";
    programChangeMap["key9_modline3_gain"] = 1.00;
    programChangeMap["key9_modline3_offset"] = 0.00;
    programChangeMap["key9_modline3_table"] = "1_Lin";
    programChangeMap["key9_modline3_min"] = 0;
    programChangeMap["key9_modline3_max"] = 127;
    programChangeMap["key9_modline3_slew"] = 0;
    programChangeMap["key9_modline3_destination"] = "None";
    programChangeMap["key9_modline3_channel"] = 1;
    programChangeMap["key9_modline3_device"] = "None";
    programChangeMap["key9_modline3_ledgreen"] = "True";
    programChangeMap["key9_modline3_ledred"] = "None";
    programChangeMap["key9_modline3_displaylinked"] = 0;

    //Modline 4
    programChangeMap["key9_modline4_enable"] = 1;
    programChangeMap["key9_modline4_source"] = "Other Key Pressed";
    programChangeMap["key9_modline4_gain"] = 1.00;
    programChangeMap["key9_modline4_offset"] = 0.00;
    programChangeMap["key9_modline4_table"] = "1_Lin";
    programChangeMap["key9_modline4_min"] = 0;
    programChangeMap["key9_modline4_max"] = 127;
    programChangeMap["key9_modline4_slew"] = 0;
    programChangeMap["key9_modline4_destination"] = "None";
    programChangeMap["key9_modline4_channel"] = 1;
    programChangeMap["key9_modline4_device"] = "None";
    programChangeMap["key9_modline4_ledgreen"] = "Off";
    programChangeMap["key9_modline4_ledred"] = "None";
    programChangeMap["key9_modline4_displaylinked"] = 0;

    //Modline 5
    programChangeMap["key9_modline5_enable"] = 0;
    programChangeMap["key9_modline5_source"] = "None";
    programChangeMap["key9_modline5_gain"] = 1.00;
    programChangeMap["key9_modline5_offset"] = 0.00;
    programChangeMap["key9_modline5_table"] = "1_Lin";
    programChangeMap["key9_modline5_min"] = 0;
    programChangeMap["key9_modline5_max"] = 127;
    programChangeMap["key9_modline5_slew"] = 0;
    programChangeMap["key9_modline5_destination"] = "None";
    programChangeMap["key9_modline5_channel"] = 1;
    programChangeMap["key9_modline5_device"] = "None";
    programChangeMap["key9_modline5_ledgreen"] = "None";
    programChangeMap["key9_modline5_ledred"] = "None";
    programChangeMap["key9_modline5_displaylinked"] = 0;

    //Modline 6
    programChangeMap["key9_modline6_enable"] = 0;
    programChangeMap["key9_modline6_source"] = "None";
    programChangeMap["key9_modline6_gain"] = 1.00;
    programChangeMap["key9_modline6_offset"] = 0.00;
    programChangeMap["key9_modline6_table"] = "1_Lin";
    programChangeMap["key9_modline6_min"] = 0;
    programChangeMap["key9_modline6_max"] = 127;
    programChangeMap["key9_modline6_slew"] = 0;
    programChangeMap["key9_modline6_destination"] = "None";
    programChangeMap["key9_modline6_channel"] = 1;
    programChangeMap["key9_modline6_device"] = "None";
    programChangeMap["key9_modline6_ledgreen"] = "None";
    programChangeMap["key9_modline6_ledred"] = "None";
    programChangeMap["key9_modline6_displaylinked"] = 0;

    //------------------------------------------------ Key10
    programChangeMap["key10_name"] = "0KEY";
    programChangeMap["key10_displaymode"] = 4;
    programChangeMap["key10_prefix"] = "PG";

    //Modline 1
    programChangeMap["key10_modline1_enable"] = 1;
    programChangeMap["key10_modline1_source"] = "Nav Yx10 & Key";
    programChangeMap["key10_modline1_gain"] = 1.00;
    programChangeMap["key10_modline1_offset"] = 0.00;
    programChangeMap["key10_modline1_table"] = "1_Lin";
    programChangeMap["key10_modline1_min"] = 0;
    programChangeMap["key10_modline1_max"] = 127;
    programChangeMap["key10_modline1_slew"] = 0;
    programChangeMap["key10_modline1_destination"] = "Program";
    programChangeMap["key10_modline1_channel"] = 1;
    programChangeMap["key10_modline1_device"] = "SSCOM_Port_1";
    programChangeMap["key10_modline1_ledgreen"] = "None";
    programChangeMap["key10_modline1_ledred"] = "None";
    programChangeMap["key10_modline1_displaylinked"] = 1;

    //Modline 2
    programChangeMap["key10_modline2_enable"] = 1;
    programChangeMap["key10_modline2_source"] = "Nav Yx10 & Key";
    programChangeMap["key10_modline2_gain"] = 1.00;
    programChangeMap["key10_modline2_offset"] = 0.00;
    programChangeMap["key10_modline2_table"] = "1_Lin";
    programChangeMap["key10_modline2_min"] = 0;
    programChangeMap["key10_modline2_max"] = 127;
    programChangeMap["key10_modline2_slew"] = 0;
    programChangeMap["key10_modline2_destination"] = "Program";
    programChangeMap["key10_modline2_channel"] = 1;
    programChangeMap["key10_modline2_device"] = "SoftStep_Expander";
    programChangeMap["key10_modline2_ledgreen"] = "None";
    programChangeMap["key10_modline2_ledred"] = "None";
    programChangeMap["key10_modline2_displaylinked"] = 0;

    //Modline 3
    programChangeMap["key10_modline3_enable"] = 1;
    programChangeMap["key10_modline3_source"] = "Key 0 Pressed";
    programChangeMap["key10_modline3_gain"] = 1.00;
    programChangeMap["key10_modline3_offset"] = 0.00;
    programChangeMap["key10_modline3_table"] = "1_Lin";
    programChangeMap["key10_modline3_min"] = 0;
    programChangeMap["key10_modline3_max"] = 127;
    programChangeMap["key10_modline3_slew"] = 0;
    programChangeMap["key10_modline3_destination"] = "None";
    programChangeMap["key10_modline3_channel"] = 1;
    programChangeMap["key10_modline3_device"] = "None";
    programChangeMap["key10_modline3_ledgreen"] = "True";
    programChangeMap["key10_modline3_ledred"] = "None";
    programChangeMap["key10_modline3_displaylinked"] = 0;

    //Modline 4
    programChangeMap["key10_modline4_enable"] = 1;
    programChangeMap["key10_modline4_source"] = "Other Key Pressed";
    programChangeMap["key10_modline4_gain"] = 1.00;
    programChangeMap["key10_modline4_offset"] = 0.00;
    programChangeMap["key10_modline4_table"] = "1_Lin";
    programChangeMap["key10_modline4_min"] = 0;
    programChangeMap["key10_modline4_max"] = 127;
    programChangeMap["key10_modline4_slew"] = 0;
    programChangeMap["key10_modline4_destination"] = "None";
    programChangeMap["key10_modline4_channel"] = 1;
    programChangeMap["key10_modline4_device"] = "None";
    programChangeMap["key10_modline4_ledgreen"] = "Off";
    programChangeMap["key10_modline4_ledred"] = "None";
    programChangeMap["key10_modline4_displaylinked"] = 0;

    //Modline 5
    programChangeMap["key10_modline5_enable"] = 0;
    programChangeMap["key10_modline5_source"] = "None";
    programChangeMap["key10_modline5_gain"] = 1.00;
    programChangeMap["key10_modline5_offset"] = 0.00;
    programChangeMap["key10_modline5_table"] = "1_Lin";
    programChangeMap["key10_modline5_min"] = 0;
    programChangeMap["key10_modline5_max"] = 127;
    programChangeMap["key10_modline5_slew"] = 0;
    programChangeMap["key10_modline5_destination"] = "None";
    programChangeMap["key10_modline5_channel"] = 1;
    programChangeMap["key10_modline5_device"] = "None";
    programChangeMap["key10_modline5_ledgreen"] = "None";
    programChangeMap["key10_modline5_ledred"] = "None";
    programChangeMap["key10_modline5_displaylinked"] = 0;

    //Modline 6
    programChangeMap["key10_modline6_enable"] = 0;
    programChangeMap["key10_modline6_source"] = "None";
    programChangeMap["key10_modline6_gain"] = 1.00;
    programChangeMap["key10_modline6_offset"] = 0.00;
    programChangeMap["key10_modline6_table"] = "1_Lin";
    programChangeMap["key10_modline6_min"] = 0;
    programChangeMap["key10_modline6_max"] = 127;
    programChangeMap["key10_modline6_slew"] = 0;
    programChangeMap["key10_modline6_destination"] = "None";
    programChangeMap["key10_modline6_channel"] = 1;
    programChangeMap["key10_modline6_device"] = "None";
    programChangeMap["key10_modline6_ledgreen"] = "None";
    programChangeMap["key10_modline6_ledred"] = "None";
    programChangeMap["key10_modline6_displaylinked"] = 0;

    //------------------------------------------------ Nav Pad 11
    programChangeMap["nav_modlinemode"] = 0;

}

void FactoryPresets::createElevenRackMap(){

    factoryElevenRackMap["displayname"] = "11RK";

    factoryElevenRackMap["useFactory"] = "ElevenRack Control";

    //------------------------ Key 1 ------------------------//
    factoryElevenRackMap["key1_name"] = "STMP";
    factoryElevenRackMap["key1_displaymode"] = 4;
    factoryElevenRackMap["key1_prefix"] = "";
    factoryElevenRackMap["key1_counter_min"] = 0;
    factoryElevenRackMap["key1_counter_max"] = 127;
    factoryElevenRackMap["key1_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryElevenRackMap["key1_modline1_enable"] = 1;
    factoryElevenRackMap["key1_modline1_source"] = "Y_Increment";
    factoryElevenRackMap["key1_modline1_gain"] = 1.00;
    factoryElevenRackMap["key1_modline1_offset"] = 0.00;
    factoryElevenRackMap["key1_modline1_table"] = "1_Lin";
    factoryElevenRackMap["key1_modline1_min"] = 0;
    factoryElevenRackMap["key1_modline1_max"] = 127;
    factoryElevenRackMap["key1_modline1_slew"] = 0;
    factoryElevenRackMap["key1_modline1_destination"] = "CC";
    factoryElevenRackMap["key1_modline1_note"] = 60;
    factoryElevenRackMap["key1_modline1_velocity"] = 127;
    factoryElevenRackMap["key1_modline1_cc"] = 78;
    factoryElevenRackMap["key1_modline1_mmcid"] = 0;
    factoryElevenRackMap["key1_modline1_mmcfunction"] = "Stop";
    factoryElevenRackMap["key1_modline1_channel"] = 1;
    factoryElevenRackMap["key1_modline1_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key1_modline1_ledgreen"] = "None";
    factoryElevenRackMap["key1_modline1_ledred"] = "None";
    factoryElevenRackMap["key1_modline1_displaylinked"] = 1;
    factoryElevenRackMap["key1_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryElevenRackMap["key1_modline2_enable"] = 1;
    factoryElevenRackMap["key1_modline2_source"] = "Y_Increment";
    factoryElevenRackMap["key1_modline2_gain"] = 1.00;
    factoryElevenRackMap["key1_modline2_offset"] = 0.00;
    factoryElevenRackMap["key1_modline2_table"] = "1_Lin";
    factoryElevenRackMap["key1_modline2_min"] = 0;
    factoryElevenRackMap["key1_modline2_max"] = 127;
    factoryElevenRackMap["key1_modline2_slew"] = 0;
    factoryElevenRackMap["key1_modline2_destination"] = "CC";
    factoryElevenRackMap["key1_modline2_note"] = 60;
    factoryElevenRackMap["key1_modline2_velocity"] = 127;
    factoryElevenRackMap["key1_modline2_cc"] = 78;
    factoryElevenRackMap["key1_modline2_mmcid"] = 0;
    factoryElevenRackMap["key1_modline2_mmcfunction"] = "Stop";
    factoryElevenRackMap["key1_modline2_channel"] = 1;
    factoryElevenRackMap["key1_modline2_device"] = "SoftStep_Expander";
    factoryElevenRackMap["key1_modline2_ledgreen"] = "None";
    factoryElevenRackMap["key1_modline2_ledred"] = "None";
    factoryElevenRackMap["key1_modline2_displaylinked"] = 0;
    factoryElevenRackMap["key1_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryElevenRackMap["key1_modline3_enable"] = 0;
    factoryElevenRackMap["key1_modline3_source"] = "None";
    factoryElevenRackMap["key1_modline3_gain"] = 0.00;
    factoryElevenRackMap["key1_modline3_offset"] = 0.00;
    factoryElevenRackMap["key1_modline3_table"] = "1_Lin";
    factoryElevenRackMap["key1_modline3_min"] = 0;
    factoryElevenRackMap["key1_modline3_max"] = 127;
    factoryElevenRackMap["key1_modline3_slew"] = 0;
    factoryElevenRackMap["key1_modline3_destination"] = "None";
    factoryElevenRackMap["key1_modline3_note"] = 60;
    factoryElevenRackMap["key1_modline3_velocity"] = 127;
    factoryElevenRackMap["key1_modline3_cc"] = 1;
    factoryElevenRackMap["key1_modline3_mmcid"] = 0;
    factoryElevenRackMap["key1_modline3_mmcfunction"] = "Stop";
    factoryElevenRackMap["key1_modline3_channel"] = 0;
    factoryElevenRackMap["key1_modline3_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key1_modline3_ledgreen"] = "None";
    factoryElevenRackMap["key1_modline3_ledred"] = "None";
    factoryElevenRackMap["key1_modline3_displaylinked"] = 0;
    factoryElevenRackMap["key1_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryElevenRackMap["key1_modline4_enable"] = 0;
    factoryElevenRackMap["key1_modline4_source"] = "None";
    factoryElevenRackMap["key1_modline4_gain"] = 0.00;
    factoryElevenRackMap["key1_modline4_offset"] = 0.00;
    factoryElevenRackMap["key1_modline4_table"] = "1_Lin";
    factoryElevenRackMap["key1_modline4_min"] = 0;
    factoryElevenRackMap["key1_modline4_max"] = 127;
    factoryElevenRackMap["key1_modline4_slew"] = 0;
    factoryElevenRackMap["key1_modline4_destination"] = "None";
    factoryElevenRackMap["key1_modline4_note"] = 60;
    factoryElevenRackMap["key1_modline4_velocity"] = 127;
    factoryElevenRackMap["key1_modline4_cc"] = 1;
    factoryElevenRackMap["key1_modline4_mmcid"] = 0;
    factoryElevenRackMap["key1_modline4_mmcfunction"] = "Stop";
    factoryElevenRackMap["key1_modline4_channel"] = 0;
    factoryElevenRackMap["key1_modline4_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key1_modline4_ledgreen"] = "None";
    factoryElevenRackMap["key1_modline4_ledred"] = "None";
    factoryElevenRackMap["key1_modline4_displaylinked"] = 0;
    factoryElevenRackMap["key1_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryElevenRackMap["key1_modline5_enable"] = 0;
    factoryElevenRackMap["key1_modline5_source"] = "None";
    factoryElevenRackMap["key1_modline5_gain"] = 0.00;
    factoryElevenRackMap["key1_modline5_offset"] = 0.00;
    factoryElevenRackMap["key1_modline5_table"] = "1_Lin";
    factoryElevenRackMap["key1_modline5_min"] = 0;
    factoryElevenRackMap["key1_modline5_max"] = 127;
    factoryElevenRackMap["key1_modline5_slew"] = 0;
    factoryElevenRackMap["key1_modline5_destination"] = "None";
    factoryElevenRackMap["key1_modline5_note"] = 60;
    factoryElevenRackMap["key1_modline5_velocity"] = 127;
    factoryElevenRackMap["key1_modline5_cc"] = 1;
    factoryElevenRackMap["key1_modline5_mmcid"] = 0;
    factoryElevenRackMap["key1_modline5_mmcfunction"] = "Stop";
    factoryElevenRackMap["key1_modline5_channel"] = 0;
    factoryElevenRackMap["key1_modline5_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key1_modline5_ledgreen"] = "None";
    factoryElevenRackMap["key1_modline5_ledred"] = "None";
    factoryElevenRackMap["key1_modline5_displaylinked"] = 0;
    factoryElevenRackMap["key1_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryElevenRackMap["key1_modline6_enable"] = 0;
    factoryElevenRackMap["key1_modline6_source"] = "None";
    factoryElevenRackMap["key1_modline6_gain"] = 0.00;
    factoryElevenRackMap["key1_modline6_offset"] = 0.00;
    factoryElevenRackMap["key1_modline6_table"] = "1_Lin";
    factoryElevenRackMap["key1_modline6_min"] = 0;
    factoryElevenRackMap["key1_modline6_max"] = 127;
    factoryElevenRackMap["key1_modline6_slew"] = 0;
    factoryElevenRackMap["key1_modline6_destination"] = "None";
    factoryElevenRackMap["key1_modline6_note"] = 60;
    factoryElevenRackMap["key1_modline6_velocity"] = 127;
    factoryElevenRackMap["key1_modline6_cc"] = 1;
    factoryElevenRackMap["key1_modline6_mmcid"] = 0;
    factoryElevenRackMap["key1_modline6_mmcfunction"] = "Stop";
    factoryElevenRackMap["key1_modline6_channel"] = 0;
    factoryElevenRackMap["key1_modline6_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key1_modline6_ledgreen"] = "None";
    factoryElevenRackMap["key1_modline6_ledred"] = "None";
    factoryElevenRackMap["key1_modline6_displaylinked"] = 0;
    factoryElevenRackMap["key1_modline6_reminder"] = "";


    //------------------------ Key 2 ------------------------//
    factoryElevenRackMap["key2_name"] = "MODX";
    factoryElevenRackMap["key2_displaymode"] = 4;
    factoryElevenRackMap["key2_prefix"] = "";
    factoryElevenRackMap["key2_counter_min"] = 0;
    factoryElevenRackMap["key2_counter_max"] = 127;
    factoryElevenRackMap["key2_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryElevenRackMap["key2_modline1_enable"] = 1;
    factoryElevenRackMap["key2_modline1_source"] = "Pressure_Live";
    factoryElevenRackMap["key2_modline1_gain"] = 1.00;
    factoryElevenRackMap["key2_modline1_offset"] = 0.00;
    factoryElevenRackMap["key2_modline1_table"] = "1_Lin";
    factoryElevenRackMap["key2_modline1_min"] = 20;
    factoryElevenRackMap["key2_modline1_max"] = 127;
    factoryElevenRackMap["key2_modline1_slew"] = 0;
    factoryElevenRackMap["key2_modline1_destination"] = "CC";
    factoryElevenRackMap["key2_modline1_note"] = 60;
    factoryElevenRackMap["key2_modline1_velocity"] = 127;
    factoryElevenRackMap["key2_modline1_cc"] = 54;
    factoryElevenRackMap["key2_modline1_mmcid"] = 0;
    factoryElevenRackMap["key2_modline1_mmcfunction"] = "Stop";
    factoryElevenRackMap["key2_modline1_channel"] = 1;
    factoryElevenRackMap["key2_modline1_device"] = "SoftStep_Expander";
    factoryElevenRackMap["key2_modline1_ledgreen"] = "None";
    factoryElevenRackMap["key2_modline1_ledred"] = "None";
    factoryElevenRackMap["key2_modline1_displaylinked"] = 1;
    factoryElevenRackMap["key2_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryElevenRackMap["key2_modline2_enable"] = 1;
    factoryElevenRackMap["key2_modline2_source"] = "Pressure_Live";
    factoryElevenRackMap["key2_modline2_gain"] = 1.00;
    factoryElevenRackMap["key2_modline2_offset"] = 0.00;
    factoryElevenRackMap["key2_modline2_table"] = "1_Lin";
    factoryElevenRackMap["key2_modline2_min"] = 20;
    factoryElevenRackMap["key2_modline2_max"] = 127;
    factoryElevenRackMap["key2_modline2_slew"] = 0;
    factoryElevenRackMap["key2_modline2_destination"] = "CC";
    factoryElevenRackMap["key2_modline2_note"] = 60;
    factoryElevenRackMap["key2_modline2_velocity"] = 127;
    factoryElevenRackMap["key2_modline2_cc"] = 52;
    factoryElevenRackMap["key2_modline2_mmcid"] = 0;
    factoryElevenRackMap["key2_modline2_mmcfunction"] = "Stop";
    factoryElevenRackMap["key2_modline2_channel"] = 1;
    factoryElevenRackMap["key2_modline2_device"] = "SoftStep_Expander";
    factoryElevenRackMap["key2_modline2_ledgreen"] = "None";
    factoryElevenRackMap["key2_modline2_ledred"] = "None";
    factoryElevenRackMap["key2_modline2_displaylinked"] = 0;
    factoryElevenRackMap["key2_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryElevenRackMap["key2_modline3_enable"] = 1;
    factoryElevenRackMap["key2_modline3_source"] = "Pressure_Live";
    factoryElevenRackMap["key2_modline3_gain"] = 1.00;
    factoryElevenRackMap["key2_modline3_offset"] = 0.00;
    factoryElevenRackMap["key2_modline3_table"] = "1_Lin";
    factoryElevenRackMap["key2_modline3_min"] = 20;
    factoryElevenRackMap["key2_modline3_max"] = 127;
    factoryElevenRackMap["key2_modline3_slew"] = 0;
    factoryElevenRackMap["key2_modline3_destination"] = "CC";
    factoryElevenRackMap["key2_modline3_note"] = 60;
    factoryElevenRackMap["key2_modline3_velocity"] = 127;
    factoryElevenRackMap["key2_modline3_cc"] = 54;
    factoryElevenRackMap["key2_modline3_mmcid"] = 0;
    factoryElevenRackMap["key2_modline3_mmcfunction"] = "Stop";
    factoryElevenRackMap["key2_modline3_channel"] = 1;
    factoryElevenRackMap["key2_modline3_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key2_modline3_ledgreen"] = "None";
    factoryElevenRackMap["key2_modline3_ledred"] = "None";
    factoryElevenRackMap["key2_modline3_displaylinked"] = 0;
    factoryElevenRackMap["key2_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryElevenRackMap["key2_modline4_enable"] = 1;
    factoryElevenRackMap["key2_modline4_source"] = "Pressure_Live";
    factoryElevenRackMap["key2_modline4_gain"] = 1.00;
    factoryElevenRackMap["key2_modline4_offset"] = 0.00;
    factoryElevenRackMap["key2_modline4_table"] = "1_Lin";
    factoryElevenRackMap["key2_modline4_min"] = 20;
    factoryElevenRackMap["key2_modline4_max"] = 127;
    factoryElevenRackMap["key2_modline4_slew"] = 0;
    factoryElevenRackMap["key2_modline4_destination"] = "CC";
    factoryElevenRackMap["key2_modline4_note"] = 60;
    factoryElevenRackMap["key2_modline4_velocity"] = 127;
    factoryElevenRackMap["key2_modline4_cc"] = 52;
    factoryElevenRackMap["key2_modline4_mmcid"] = 0;
    factoryElevenRackMap["key2_modline4_mmcfunction"] = "Stop";
    factoryElevenRackMap["key2_modline4_channel"] = 1;
    factoryElevenRackMap["key2_modline4_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key2_modline4_ledgreen"] = "None";
    factoryElevenRackMap["key2_modline4_ledred"] = "None";
    factoryElevenRackMap["key2_modline4_displaylinked"] = 0;
    factoryElevenRackMap["key2_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryElevenRackMap["key2_modline5_enable"] = 0;
    factoryElevenRackMap["key2_modline5_source"] = "None";
    factoryElevenRackMap["key2_modline5_gain"] = 0.00;
    factoryElevenRackMap["key2_modline5_offset"] = 0.00;
    factoryElevenRackMap["key2_modline5_table"] = "1_Lin";
    factoryElevenRackMap["key2_modline5_min"] = 0;
    factoryElevenRackMap["key2_modline5_max"] = 127;
    factoryElevenRackMap["key2_modline5_slew"] = 0;
    factoryElevenRackMap["key2_modline5_destination"] = "None";
    factoryElevenRackMap["key2_modline5_note"] = 60;
    factoryElevenRackMap["key2_modline5_velocity"] = 127;
    factoryElevenRackMap["key2_modline5_cc"] = 1;
    factoryElevenRackMap["key2_modline5_mmcid"] = 0;
    factoryElevenRackMap["key2_modline5_mmcfunction"] = "Stop";
    factoryElevenRackMap["key2_modline5_channel"] = 0;
    factoryElevenRackMap["key2_modline5_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key2_modline5_ledgreen"] = "None";
    factoryElevenRackMap["key2_modline5_ledred"] = "None";
    factoryElevenRackMap["key2_modline5_displaylinked"] = 0;
    factoryElevenRackMap["key2_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryElevenRackMap["key2_modline6_enable"] = 0;
    factoryElevenRackMap["key2_modline6_source"] = "None";
    factoryElevenRackMap["key2_modline6_gain"] = 0.00;
    factoryElevenRackMap["key2_modline6_offset"] = 0.00;
    factoryElevenRackMap["key2_modline6_table"] = "1_Lin";
    factoryElevenRackMap["key2_modline6_min"] = 0;
    factoryElevenRackMap["key2_modline6_max"] = 127;
    factoryElevenRackMap["key2_modline6_slew"] = 0;
    factoryElevenRackMap["key2_modline6_destination"] = "None";
    factoryElevenRackMap["key2_modline6_note"] = 60;
    factoryElevenRackMap["key2_modline6_velocity"] = 127;
    factoryElevenRackMap["key2_modline6_cc"] = 1;
    factoryElevenRackMap["key2_modline6_mmcid"] = 0;
    factoryElevenRackMap["key2_modline6_mmcfunction"] = "Stop";
    factoryElevenRackMap["key2_modline6_channel"] = 0;
    factoryElevenRackMap["key2_modline6_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key2_modline6_ledgreen"] = "None";
    factoryElevenRackMap["key2_modline6_ledred"] = "None";
    factoryElevenRackMap["key2_modline6_displaylinked"] = 0;
    factoryElevenRackMap["key2_modline6_reminder"] = "";


    //------------------------ Key 3 ------------------------//
    factoryElevenRackMap["key3_name"] = "DLYX";
    factoryElevenRackMap["key3_displaymode"] = 4;
    factoryElevenRackMap["key3_prefix"] = "";
    factoryElevenRackMap["key3_counter_min"] = 0;
    factoryElevenRackMap["key3_counter_max"] = 127;
    factoryElevenRackMap["key3_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryElevenRackMap["key3_modline1_enable"] = 1;
    factoryElevenRackMap["key3_modline1_source"] = "Y_Increment";
    factoryElevenRackMap["key3_modline1_gain"] = 0.40;
    factoryElevenRackMap["key3_modline1_offset"] = 20.00;
    factoryElevenRackMap["key3_modline1_table"] = "1_Lin";
    factoryElevenRackMap["key3_modline1_min"] = 0;
    factoryElevenRackMap["key3_modline1_max"] = 127;
    factoryElevenRackMap["key3_modline1_slew"] = 0;
    factoryElevenRackMap["key3_modline1_destination"] = "CC";
    factoryElevenRackMap["key3_modline1_note"] = 60;
    factoryElevenRackMap["key3_modline1_velocity"] = 127;
    factoryElevenRackMap["key3_modline1_cc"] = 85;
    factoryElevenRackMap["key3_modline1_mmcid"] = 0;
    factoryElevenRackMap["key3_modline1_mmcfunction"] = "Stop";
    factoryElevenRackMap["key3_modline1_channel"] = 1;
    factoryElevenRackMap["key3_modline1_device"] = "SoftStep_Expander";
    factoryElevenRackMap["key3_modline1_ledgreen"] = "None";
    factoryElevenRackMap["key3_modline1_ledred"] = "None";
    factoryElevenRackMap["key3_modline1_displaylinked"] = 1;
    factoryElevenRackMap["key3_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryElevenRackMap["key3_modline2_enable"] = 1;
    factoryElevenRackMap["key3_modline2_source"] = "Y_Increment";
    factoryElevenRackMap["key3_modline2_gain"] = 0.40;
    factoryElevenRackMap["key3_modline2_offset"] = 20.00;
    factoryElevenRackMap["key3_modline2_table"] = "1_Lin";
    factoryElevenRackMap["key3_modline2_min"] = 0;
    factoryElevenRackMap["key3_modline2_max"] = 127;
    factoryElevenRackMap["key3_modline2_slew"] = 0;
    factoryElevenRackMap["key3_modline2_destination"] = "CC";
    factoryElevenRackMap["key3_modline2_note"] = 60;
    factoryElevenRackMap["key3_modline2_velocity"] = 127;
    factoryElevenRackMap["key3_modline2_cc"] = 85;
    factoryElevenRackMap["key3_modline2_mmcid"] = 0;
    factoryElevenRackMap["key3_modline2_mmcfunction"] = "Stop";
    factoryElevenRackMap["key3_modline2_channel"] = 1;
    factoryElevenRackMap["key3_modline2_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key3_modline2_ledgreen"] = "None";
    factoryElevenRackMap["key3_modline2_ledred"] = "None";
    factoryElevenRackMap["key3_modline2_displaylinked"] = 0;
    factoryElevenRackMap["key3_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryElevenRackMap["key3_modline3_enable"] = 0;
    factoryElevenRackMap["key3_modline3_source"] = "None";
    factoryElevenRackMap["key3_modline3_gain"] = 0.00;
    factoryElevenRackMap["key3_modline3_offset"] = 0.00;
    factoryElevenRackMap["key3_modline3_table"] = "1_Lin";
    factoryElevenRackMap["key3_modline3_min"] = 0;
    factoryElevenRackMap["key3_modline3_max"] = 127;
    factoryElevenRackMap["key3_modline3_slew"] = 0;
    factoryElevenRackMap["key3_modline3_destination"] = "None";
    factoryElevenRackMap["key3_modline3_note"] = 60;
    factoryElevenRackMap["key3_modline3_velocity"] = 127;
    factoryElevenRackMap["key3_modline3_cc"] = 1;
    factoryElevenRackMap["key3_modline3_mmcid"] = 0;
    factoryElevenRackMap["key3_modline3_mmcfunction"] = "Stop";
    factoryElevenRackMap["key3_modline3_channel"] = 0;
    factoryElevenRackMap["key3_modline3_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key3_modline3_ledgreen"] = "None";
    factoryElevenRackMap["key3_modline3_ledred"] = "None";
    factoryElevenRackMap["key3_modline3_displaylinked"] = 0;
    factoryElevenRackMap["key3_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryElevenRackMap["key3_modline4_enable"] = 0;
    factoryElevenRackMap["key3_modline4_source"] = "None";
    factoryElevenRackMap["key3_modline4_gain"] = 0.00;
    factoryElevenRackMap["key3_modline4_offset"] = 0.00;
    factoryElevenRackMap["key3_modline4_table"] = "1_Lin";
    factoryElevenRackMap["key3_modline4_min"] = 0;
    factoryElevenRackMap["key3_modline4_max"] = 127;
    factoryElevenRackMap["key3_modline4_slew"] = 0;
    factoryElevenRackMap["key3_modline4_destination"] = "None";
    factoryElevenRackMap["key3_modline4_note"] = 60;
    factoryElevenRackMap["key3_modline4_velocity"] = 127;
    factoryElevenRackMap["key3_modline4_cc"] = 1;
    factoryElevenRackMap["key3_modline4_mmcid"] = 0;
    factoryElevenRackMap["key3_modline4_mmcfunction"] = "Stop";
    factoryElevenRackMap["key3_modline4_channel"] = 0;
    factoryElevenRackMap["key3_modline4_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key3_modline4_ledgreen"] = "None";
    factoryElevenRackMap["key3_modline4_ledred"] = "None";
    factoryElevenRackMap["key3_modline4_displaylinked"] = 0;
    factoryElevenRackMap["key3_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryElevenRackMap["key3_modline5_enable"] = 0;
    factoryElevenRackMap["key3_modline5_source"] = "None";
    factoryElevenRackMap["key3_modline5_gain"] = 0.00;
    factoryElevenRackMap["key3_modline5_offset"] = 0.00;
    factoryElevenRackMap["key3_modline5_table"] = "1_Lin";
    factoryElevenRackMap["key3_modline5_min"] = 0;
    factoryElevenRackMap["key3_modline5_max"] = 127;
    factoryElevenRackMap["key3_modline5_slew"] = 0;
    factoryElevenRackMap["key3_modline5_destination"] = "None";
    factoryElevenRackMap["key3_modline5_note"] = 60;
    factoryElevenRackMap["key3_modline5_velocity"] = 127;
    factoryElevenRackMap["key3_modline5_cc"] = 1;
    factoryElevenRackMap["key3_modline5_mmcid"] = 0;
    factoryElevenRackMap["key3_modline5_mmcfunction"] = "Stop";
    factoryElevenRackMap["key3_modline5_channel"] = 0;
    factoryElevenRackMap["key3_modline5_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key3_modline5_ledgreen"] = "None";
    factoryElevenRackMap["key3_modline5_ledred"] = "None";
    factoryElevenRackMap["key3_modline5_displaylinked"] = 0;
    factoryElevenRackMap["key3_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryElevenRackMap["key3_modline6_enable"] = 0;
    factoryElevenRackMap["key3_modline6_source"] = "None";
    factoryElevenRackMap["key3_modline6_gain"] = 0.00;
    factoryElevenRackMap["key3_modline6_offset"] = 0.00;
    factoryElevenRackMap["key3_modline6_table"] = "1_Lin";
    factoryElevenRackMap["key3_modline6_min"] = 0;
    factoryElevenRackMap["key3_modline6_max"] = 127;
    factoryElevenRackMap["key3_modline6_slew"] = 0;
    factoryElevenRackMap["key3_modline6_destination"] = "None";
    factoryElevenRackMap["key3_modline6_note"] = 60;
    factoryElevenRackMap["key3_modline6_velocity"] = 127;
    factoryElevenRackMap["key3_modline6_cc"] = 1;
    factoryElevenRackMap["key3_modline6_mmcid"] = 0;
    factoryElevenRackMap["key3_modline6_mmcfunction"] = "Stop";
    factoryElevenRackMap["key3_modline6_channel"] = 0;
    factoryElevenRackMap["key3_modline6_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key3_modline6_ledgreen"] = "None";
    factoryElevenRackMap["key3_modline6_ledred"] = "None";
    factoryElevenRackMap["key3_modline6_displaylinked"] = 0;
    factoryElevenRackMap["key3_modline6_reminder"] = "";


    //------------------------ Key 4 ------------------------//
    factoryElevenRackMap["key4_name"] = "TAP";
    factoryElevenRackMap["key4_displaymode"] = 1;
    factoryElevenRackMap["key4_prefix"] = "";
    factoryElevenRackMap["key4_counter_min"] = 0;
    factoryElevenRackMap["key4_counter_max"] = 127;
    factoryElevenRackMap["key4_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryElevenRackMap["key4_modline1_enable"] = 1;
    factoryElevenRackMap["key4_modline1_source"] = "Foot_On";
    factoryElevenRackMap["key4_modline1_gain"] = 1.00;
    factoryElevenRackMap["key4_modline1_offset"] = 0.00;
    factoryElevenRackMap["key4_modline1_table"] = "1_Lin";
    factoryElevenRackMap["key4_modline1_min"] = 60;
    factoryElevenRackMap["key4_modline1_max"] = 60;
    factoryElevenRackMap["key4_modline1_slew"] = 0;
    factoryElevenRackMap["key4_modline1_destination"] = "CC";
    factoryElevenRackMap["key4_modline1_note"] = 60;
    factoryElevenRackMap["key4_modline1_velocity"] = 127;
    factoryElevenRackMap["key4_modline1_cc"] = 33;
    factoryElevenRackMap["key4_modline1_mmcid"] = 0;
    factoryElevenRackMap["key4_modline1_mmcfunction"] = "Stop";
    factoryElevenRackMap["key4_modline1_channel"] = 1;
    factoryElevenRackMap["key4_modline1_device"] = "SoftStep_Expander";
    factoryElevenRackMap["key4_modline1_ledgreen"] = "None";
    factoryElevenRackMap["key4_modline1_ledred"] = "None";
    factoryElevenRackMap["key4_modline1_displaylinked"] = 1;
    factoryElevenRackMap["key4_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryElevenRackMap["key4_modline2_enable"] = 1;
    factoryElevenRackMap["key4_modline2_source"] = "Foot_On";
    factoryElevenRackMap["key4_modline2_gain"] = 1.00;
    factoryElevenRackMap["key4_modline2_offset"] = 0.00;
    factoryElevenRackMap["key4_modline2_table"] = "Toggle_127";
    factoryElevenRackMap["key4_modline2_min"] = 0;
    factoryElevenRackMap["key4_modline2_max"] = 127;
    factoryElevenRackMap["key4_modline2_slew"] = 0;
    factoryElevenRackMap["key4_modline2_destination"] = "CC";
    factoryElevenRackMap["key4_modline2_note"] = 60;
    factoryElevenRackMap["key4_modline2_velocity"] = 127;
    factoryElevenRackMap["key4_modline2_cc"] = 64;
    factoryElevenRackMap["key4_modline2_mmcid"] = 0;
    factoryElevenRackMap["key4_modline2_mmcfunction"] = "Stop";
    factoryElevenRackMap["key4_modline2_channel"] = 1;
    factoryElevenRackMap["key4_modline2_device"] = "SoftStep_Expander";
    factoryElevenRackMap["key4_modline2_ledgreen"] = "None";
    factoryElevenRackMap["key4_modline2_ledred"] = "None";
    factoryElevenRackMap["key4_modline2_displaylinked"] = 0;
    factoryElevenRackMap["key4_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryElevenRackMap["key4_modline3_enable"] = 1;
    factoryElevenRackMap["key4_modline3_source"] = "Foot_On";
    factoryElevenRackMap["key4_modline3_gain"] = 1.00;
    factoryElevenRackMap["key4_modline3_offset"] = 0.00;
    factoryElevenRackMap["key4_modline3_table"] = "1_Lin";
    factoryElevenRackMap["key4_modline3_min"] = 60;
    factoryElevenRackMap["key4_modline3_max"] = 60;
    factoryElevenRackMap["key4_modline3_slew"] = 0;
    factoryElevenRackMap["key4_modline3_destination"] = "CC";
    factoryElevenRackMap["key4_modline3_note"] = 60;
    factoryElevenRackMap["key4_modline3_velocity"] = 127;
    factoryElevenRackMap["key4_modline3_cc"] = 33;
    factoryElevenRackMap["key4_modline3_mmcid"] = 0;
    factoryElevenRackMap["key4_modline3_mmcfunction"] = "Stop";
    factoryElevenRackMap["key4_modline3_channel"] = 1;
    factoryElevenRackMap["key4_modline3_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key4_modline3_ledgreen"] = "None";
    factoryElevenRackMap["key4_modline3_ledred"] = "None";
    factoryElevenRackMap["key4_modline3_displaylinked"] = 0;
    factoryElevenRackMap["key4_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryElevenRackMap["key4_modline4_enable"] = 1;
    factoryElevenRackMap["key4_modline4_source"] = "Foot_On";
    factoryElevenRackMap["key4_modline4_gain"] = 1.00;
    factoryElevenRackMap["key4_modline4_offset"] = 0.00;
    factoryElevenRackMap["key4_modline4_table"] = "Toggle_127";
    factoryElevenRackMap["key4_modline4_min"] = 0;
    factoryElevenRackMap["key4_modline4_max"] = 127;
    factoryElevenRackMap["key4_modline4_slew"] = 0;
    factoryElevenRackMap["key4_modline4_destination"] = "CC";
    factoryElevenRackMap["key4_modline4_note"] = 60;
    factoryElevenRackMap["key4_modline4_velocity"] = 127;
    factoryElevenRackMap["key4_modline4_cc"] = 64;
    factoryElevenRackMap["key4_modline4_mmcid"] = 0;
    factoryElevenRackMap["key4_modline4_mmcfunction"] = "Stop";
    factoryElevenRackMap["key4_modline4_channel"] = 1;
    factoryElevenRackMap["key4_modline4_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key4_modline4_ledgreen"] = "None";
    factoryElevenRackMap["key4_modline4_ledred"] = "None";
    factoryElevenRackMap["key4_modline4_displaylinked"] = 0;
    factoryElevenRackMap["key4_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryElevenRackMap["key4_modline5_enable"] = 0;
    factoryElevenRackMap["key4_modline5_source"] = "None";
    factoryElevenRackMap["key4_modline5_gain"] = 0.00;
    factoryElevenRackMap["key4_modline5_offset"] = 0.00;
    factoryElevenRackMap["key4_modline5_table"] = "1_Lin";
    factoryElevenRackMap["key4_modline5_min"] = 0;
    factoryElevenRackMap["key4_modline5_max"] = 127;
    factoryElevenRackMap["key4_modline5_slew"] = 0;
    factoryElevenRackMap["key4_modline5_destination"] = "None";
    factoryElevenRackMap["key4_modline5_note"] = 60;
    factoryElevenRackMap["key4_modline5_velocity"] = 127;
    factoryElevenRackMap["key4_modline5_cc"] = 1;
    factoryElevenRackMap["key4_modline5_mmcid"] = 0;
    factoryElevenRackMap["key4_modline5_mmcfunction"] = "Stop";
    factoryElevenRackMap["key4_modline5_channel"] = 0;
    factoryElevenRackMap["key4_modline5_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key4_modline5_ledgreen"] = "None";
    factoryElevenRackMap["key4_modline5_ledred"] = "None";
    factoryElevenRackMap["key4_modline5_displaylinked"] = 0;
    factoryElevenRackMap["key4_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryElevenRackMap["key4_modline6_enable"] = 0;
    factoryElevenRackMap["key4_modline6_source"] = "None";
    factoryElevenRackMap["key4_modline6_gain"] = 0.00;
    factoryElevenRackMap["key4_modline6_offset"] = 0.00;
    factoryElevenRackMap["key4_modline6_table"] = "1_Lin";
    factoryElevenRackMap["key4_modline6_min"] = 0;
    factoryElevenRackMap["key4_modline6_max"] = 127;
    factoryElevenRackMap["key4_modline6_slew"] = 0;
    factoryElevenRackMap["key4_modline6_destination"] = "None";
    factoryElevenRackMap["key4_modline6_note"] = 60;
    factoryElevenRackMap["key4_modline6_velocity"] = 127;
    factoryElevenRackMap["key4_modline6_cc"] = 1;
    factoryElevenRackMap["key4_modline6_mmcid"] = 0;
    factoryElevenRackMap["key4_modline6_mmcfunction"] = "Stop";
    factoryElevenRackMap["key4_modline6_channel"] = 0;
    factoryElevenRackMap["key4_modline6_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key4_modline6_ledgreen"] = "None";
    factoryElevenRackMap["key4_modline6_ledred"] = "None";
    factoryElevenRackMap["key4_modline6_displaylinked"] = 0;
    factoryElevenRackMap["key4_modline6_reminder"] = "";


    //------------------------ Key 5 ------------------------//
    factoryElevenRackMap["key5_name"] = "WAH";
    factoryElevenRackMap["key5_displaymode"] = 4;
    factoryElevenRackMap["key5_prefix"] = "";
    factoryElevenRackMap["key5_counter_min"] = 0;
    factoryElevenRackMap["key5_counter_max"] = 127;
    factoryElevenRackMap["key5_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryElevenRackMap["key5_modline1_enable"] = 1;
    factoryElevenRackMap["key5_modline1_source"] = "Pressure_Live";
    factoryElevenRackMap["key5_modline1_gain"] = 1.60;
    factoryElevenRackMap["key5_modline1_offset"] = 0.00;
    factoryElevenRackMap["key5_modline1_table"] = "1_Lin";
    factoryElevenRackMap["key5_modline1_min"] = 20;
    factoryElevenRackMap["key5_modline1_max"] = 110;
    factoryElevenRackMap["key5_modline1_slew"] = 150;
    factoryElevenRackMap["key5_modline1_destination"] = "CC";
    factoryElevenRackMap["key5_modline1_note"] = 60;
    factoryElevenRackMap["key5_modline1_velocity"] = 127;
    factoryElevenRackMap["key5_modline1_cc"] = 4;
    factoryElevenRackMap["key5_modline1_mmcid"] = 0;
    factoryElevenRackMap["key5_modline1_mmcfunction"] = "Stop";
    factoryElevenRackMap["key5_modline1_channel"] = 1;
    factoryElevenRackMap["key5_modline1_device"] = "SoftStep_Expander";
    factoryElevenRackMap["key5_modline1_ledgreen"] = "None";
    factoryElevenRackMap["key5_modline1_ledred"] = "None";
    factoryElevenRackMap["key5_modline1_displaylinked"] = 1;
    factoryElevenRackMap["key5_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryElevenRackMap["key5_modline2_enable"] = 1;
    factoryElevenRackMap["key5_modline2_source"] = "Pressure_Live";
    factoryElevenRackMap["key5_modline2_gain"] = 1.60;
    factoryElevenRackMap["key5_modline2_offset"] = 0.00;
    factoryElevenRackMap["key5_modline2_table"] = "1_Lin";
    factoryElevenRackMap["key5_modline2_min"] = 20;
    factoryElevenRackMap["key5_modline2_max"] = 110;
    factoryElevenRackMap["key5_modline2_slew"] = 150;
    factoryElevenRackMap["key5_modline2_destination"] = "CC";
    factoryElevenRackMap["key5_modline2_note"] = 60;
    factoryElevenRackMap["key5_modline2_velocity"] = 127;
    factoryElevenRackMap["key5_modline2_cc"] = 4;
    factoryElevenRackMap["key5_modline2_mmcid"] = 0;
    factoryElevenRackMap["key5_modline2_mmcfunction"] = "Stop";
    factoryElevenRackMap["key5_modline2_channel"] = 1;
    factoryElevenRackMap["key5_modline2_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key5_modline2_ledgreen"] = "None";
    factoryElevenRackMap["key5_modline2_ledred"] = "None";
    factoryElevenRackMap["key5_modline2_displaylinked"] = 0;
    factoryElevenRackMap["key5_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryElevenRackMap["key5_modline3_enable"] = 0;
    factoryElevenRackMap["key5_modline3_source"] = "None";
    factoryElevenRackMap["key5_modline3_gain"] = 0.00;
    factoryElevenRackMap["key5_modline3_offset"] = 0.00;
    factoryElevenRackMap["key5_modline3_table"] = "1_Lin";
    factoryElevenRackMap["key5_modline3_min"] = 0;
    factoryElevenRackMap["key5_modline3_max"] = 127;
    factoryElevenRackMap["key5_modline3_slew"] = 0;
    factoryElevenRackMap["key5_modline3_destination"] = "None";
    factoryElevenRackMap["key5_modline3_note"] = 60;
    factoryElevenRackMap["key5_modline3_velocity"] = 127;
    factoryElevenRackMap["key5_modline3_cc"] = 1;
    factoryElevenRackMap["key5_modline3_mmcid"] = 0;
    factoryElevenRackMap["key5_modline3_mmcfunction"] = "Stop";
    factoryElevenRackMap["key5_modline3_channel"] = 0;
    factoryElevenRackMap["key5_modline3_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key5_modline3_ledgreen"] = "None";
    factoryElevenRackMap["key5_modline3_ledred"] = "None";
    factoryElevenRackMap["key5_modline3_displaylinked"] = 0;
    factoryElevenRackMap["key5_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryElevenRackMap["key5_modline4_enable"] = 0;
    factoryElevenRackMap["key5_modline4_source"] = "None";
    factoryElevenRackMap["key5_modline4_gain"] = 0.00;
    factoryElevenRackMap["key5_modline4_offset"] = 0.00;
    factoryElevenRackMap["key5_modline4_table"] = "1_Lin";
    factoryElevenRackMap["key5_modline4_min"] = 0;
    factoryElevenRackMap["key5_modline4_max"] = 127;
    factoryElevenRackMap["key5_modline4_slew"] = 0;
    factoryElevenRackMap["key5_modline4_destination"] = "None";
    factoryElevenRackMap["key5_modline4_note"] = 60;
    factoryElevenRackMap["key5_modline4_velocity"] = 127;
    factoryElevenRackMap["key5_modline4_cc"] = 1;
    factoryElevenRackMap["key5_modline4_mmcid"] = 0;
    factoryElevenRackMap["key5_modline4_mmcfunction"] = "Stop";
    factoryElevenRackMap["key5_modline4_channel"] = 0;
    factoryElevenRackMap["key5_modline4_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key5_modline4_ledgreen"] = "None";
    factoryElevenRackMap["key5_modline4_ledred"] = "None";
    factoryElevenRackMap["key5_modline4_displaylinked"] = 0;
    factoryElevenRackMap["key5_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryElevenRackMap["key5_modline5_enable"] = 0;
    factoryElevenRackMap["key5_modline5_source"] = "None";
    factoryElevenRackMap["key5_modline5_gain"] = 0.00;
    factoryElevenRackMap["key5_modline5_offset"] = 0.00;
    factoryElevenRackMap["key5_modline5_table"] = "1_Lin";
    factoryElevenRackMap["key5_modline5_min"] = 0;
    factoryElevenRackMap["key5_modline5_max"] = 127;
    factoryElevenRackMap["key5_modline5_slew"] = 0;
    factoryElevenRackMap["key5_modline5_destination"] = "None";
    factoryElevenRackMap["key5_modline5_note"] = 60;
    factoryElevenRackMap["key5_modline5_velocity"] = 127;
    factoryElevenRackMap["key5_modline5_cc"] = 1;
    factoryElevenRackMap["key5_modline5_mmcid"] = 0;
    factoryElevenRackMap["key5_modline5_mmcfunction"] = "Stop";
    factoryElevenRackMap["key5_modline5_channel"] = 0;
    factoryElevenRackMap["key5_modline5_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key5_modline5_ledgreen"] = "None";
    factoryElevenRackMap["key5_modline5_ledred"] = "None";
    factoryElevenRackMap["key5_modline5_displaylinked"] = 0;
    factoryElevenRackMap["key5_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryElevenRackMap["key5_modline6_enable"] = 0;
    factoryElevenRackMap["key5_modline6_source"] = "None";
    factoryElevenRackMap["key5_modline6_gain"] = 0.00;
    factoryElevenRackMap["key5_modline6_offset"] = 0.00;
    factoryElevenRackMap["key5_modline6_table"] = "1_Lin";
    factoryElevenRackMap["key5_modline6_min"] = 0;
    factoryElevenRackMap["key5_modline6_max"] = 127;
    factoryElevenRackMap["key5_modline6_slew"] = 0;
    factoryElevenRackMap["key5_modline6_destination"] = "None";
    factoryElevenRackMap["key5_modline6_note"] = 60;
    factoryElevenRackMap["key5_modline6_velocity"] = 127;
    factoryElevenRackMap["key5_modline6_cc"] = 1;
    factoryElevenRackMap["key5_modline6_mmcid"] = 0;
    factoryElevenRackMap["key5_modline6_mmcfunction"] = "Stop";
    factoryElevenRackMap["key5_modline6_channel"] = 0;
    factoryElevenRackMap["key5_modline6_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key5_modline6_ledgreen"] = "None";
    factoryElevenRackMap["key5_modline6_ledred"] = "None";
    factoryElevenRackMap["key5_modline6_displaylinked"] = 0;
    factoryElevenRackMap["key5_modline6_reminder"] = "";


    //------------------------ Key 6 ------------------------//
    factoryElevenRackMap["key6_name"] = "DIST";
    factoryElevenRackMap["key6_displaymode"] = 1;
    factoryElevenRackMap["key6_prefix"] = "";
    factoryElevenRackMap["key6_counter_min"] = 0;
    factoryElevenRackMap["key6_counter_max"] = 127;
    factoryElevenRackMap["key6_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryElevenRackMap["key6_modline1_enable"] = 1;
    factoryElevenRackMap["key6_modline1_source"] = "Foot_On";
    factoryElevenRackMap["key6_modline1_gain"] = 1.00;
    factoryElevenRackMap["key6_modline1_offset"] = 0.00;
    factoryElevenRackMap["key6_modline1_table"] = "Toggle_127";
    factoryElevenRackMap["key6_modline1_min"] = 0;
    factoryElevenRackMap["key6_modline1_max"] = 127;
    factoryElevenRackMap["key6_modline1_slew"] = 0;
    factoryElevenRackMap["key6_modline1_destination"] = "CC";
    factoryElevenRackMap["key6_modline1_note"] = 60;
    factoryElevenRackMap["key6_modline1_velocity"] = 127;
    factoryElevenRackMap["key6_modline1_cc"] = 25;
    factoryElevenRackMap["key6_modline1_mmcid"] = 0;
    factoryElevenRackMap["key6_modline1_mmcfunction"] = "Stop";
    factoryElevenRackMap["key6_modline1_channel"] = 1;
    factoryElevenRackMap["key6_modline1_device"] = "SoftStep_Expander";
    factoryElevenRackMap["key6_modline1_ledgreen"] = "True";
    factoryElevenRackMap["key6_modline1_ledred"] = "None";
    factoryElevenRackMap["key6_modline1_displaylinked"] = 1;
    factoryElevenRackMap["key6_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryElevenRackMap["key6_modline2_enable"] = 1;
    factoryElevenRackMap["key6_modline2_source"] = "Foot_On";
    factoryElevenRackMap["key6_modline2_gain"] = 1.00;
    factoryElevenRackMap["key6_modline2_offset"] = 0.00;
    factoryElevenRackMap["key6_modline2_table"] = "Toggle_127";
    factoryElevenRackMap["key6_modline2_min"] = 0;
    factoryElevenRackMap["key6_modline2_max"] = 127;
    factoryElevenRackMap["key6_modline2_slew"] = 0;
    factoryElevenRackMap["key6_modline2_destination"] = "CC";
    factoryElevenRackMap["key6_modline2_note"] = 60;
    factoryElevenRackMap["key6_modline2_velocity"] = 127;
    factoryElevenRackMap["key6_modline2_cc"] = 25;
    factoryElevenRackMap["key6_modline2_mmcid"] = 0;
    factoryElevenRackMap["key6_modline2_mmcfunction"] = "Stop";
    factoryElevenRackMap["key6_modline2_channel"] = 1;
    factoryElevenRackMap["key6_modline2_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key6_modline2_ledgreen"] = "None";
    factoryElevenRackMap["key6_modline2_ledred"] = "None";
    factoryElevenRackMap["key6_modline2_displaylinked"] = 0;
    factoryElevenRackMap["key6_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryElevenRackMap["key6_modline3_enable"] = 0;
    factoryElevenRackMap["key6_modline3_source"] = "None";
    factoryElevenRackMap["key6_modline3_gain"] = 0.00;
    factoryElevenRackMap["key6_modline3_offset"] = 0.00;
    factoryElevenRackMap["key6_modline3_table"] = "1_Lin";
    factoryElevenRackMap["key6_modline3_min"] = 0;
    factoryElevenRackMap["key6_modline3_max"] = 127;
    factoryElevenRackMap["key6_modline3_slew"] = 0;
    factoryElevenRackMap["key6_modline3_destination"] = "None";
    factoryElevenRackMap["key6_modline3_note"] = 60;
    factoryElevenRackMap["key6_modline3_velocity"] = 127;
    factoryElevenRackMap["key6_modline3_cc"] = 1;
    factoryElevenRackMap["key6_modline3_mmcid"] = 0;
    factoryElevenRackMap["key6_modline3_mmcfunction"] = "Stop";
    factoryElevenRackMap["key6_modline3_channel"] = 0;
    factoryElevenRackMap["key6_modline3_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key6_modline3_ledgreen"] = "None";
    factoryElevenRackMap["key6_modline3_ledred"] = "None";
    factoryElevenRackMap["key6_modline3_displaylinked"] = 0;
    factoryElevenRackMap["key6_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryElevenRackMap["key6_modline4_enable"] = 0;
    factoryElevenRackMap["key6_modline4_source"] = "None";
    factoryElevenRackMap["key6_modline4_gain"] = 0.00;
    factoryElevenRackMap["key6_modline4_offset"] = 0.00;
    factoryElevenRackMap["key6_modline4_table"] = "1_Lin";
    factoryElevenRackMap["key6_modline4_min"] = 0;
    factoryElevenRackMap["key6_modline4_max"] = 127;
    factoryElevenRackMap["key6_modline4_slew"] = 0;
    factoryElevenRackMap["key6_modline4_destination"] = "None";
    factoryElevenRackMap["key6_modline4_note"] = 60;
    factoryElevenRackMap["key6_modline4_velocity"] = 127;
    factoryElevenRackMap["key6_modline4_cc"] = 1;
    factoryElevenRackMap["key6_modline4_mmcid"] = 0;
    factoryElevenRackMap["key6_modline4_mmcfunction"] = "Stop";
    factoryElevenRackMap["key6_modline4_channel"] = 0;
    factoryElevenRackMap["key6_modline4_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key6_modline4_ledgreen"] = "None";
    factoryElevenRackMap["key6_modline4_ledred"] = "None";
    factoryElevenRackMap["key6_modline4_displaylinked"] = 0;
    factoryElevenRackMap["key6_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryElevenRackMap["key6_modline5_enable"] = 0;
    factoryElevenRackMap["key6_modline5_source"] = "None";
    factoryElevenRackMap["key6_modline5_gain"] = 0.00;
    factoryElevenRackMap["key6_modline5_offset"] = 0.00;
    factoryElevenRackMap["key6_modline5_table"] = "1_Lin";
    factoryElevenRackMap["key6_modline5_min"] = 0;
    factoryElevenRackMap["key6_modline5_max"] = 127;
    factoryElevenRackMap["key6_modline5_slew"] = 0;
    factoryElevenRackMap["key6_modline5_destination"] = "None";
    factoryElevenRackMap["key6_modline5_note"] = 60;
    factoryElevenRackMap["key6_modline5_velocity"] = 127;
    factoryElevenRackMap["key6_modline5_cc"] = 1;
    factoryElevenRackMap["key6_modline5_mmcid"] = 0;
    factoryElevenRackMap["key6_modline5_mmcfunction"] = "Stop";
    factoryElevenRackMap["key6_modline5_channel"] = 0;
    factoryElevenRackMap["key6_modline5_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key6_modline5_ledgreen"] = "None";
    factoryElevenRackMap["key6_modline5_ledred"] = "None";
    factoryElevenRackMap["key6_modline5_displaylinked"] = 0;
    factoryElevenRackMap["key6_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryElevenRackMap["key6_modline6_enable"] = 0;
    factoryElevenRackMap["key6_modline6_source"] = "None";
    factoryElevenRackMap["key6_modline6_gain"] = 0.00;
    factoryElevenRackMap["key6_modline6_offset"] = 0.00;
    factoryElevenRackMap["key6_modline6_table"] = "1_Lin";
    factoryElevenRackMap["key6_modline6_min"] = 0;
    factoryElevenRackMap["key6_modline6_max"] = 127;
    factoryElevenRackMap["key6_modline6_slew"] = 0;
    factoryElevenRackMap["key6_modline6_destination"] = "None";
    factoryElevenRackMap["key6_modline6_note"] = 60;
    factoryElevenRackMap["key6_modline6_velocity"] = 127;
    factoryElevenRackMap["key6_modline6_cc"] = 1;
    factoryElevenRackMap["key6_modline6_mmcid"] = 0;
    factoryElevenRackMap["key6_modline6_mmcfunction"] = "Stop";
    factoryElevenRackMap["key6_modline6_channel"] = 0;
    factoryElevenRackMap["key6_modline6_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key6_modline6_ledgreen"] = "None";
    factoryElevenRackMap["key6_modline6_ledred"] = "None";
    factoryElevenRackMap["key6_modline6_displaylinked"] = 0;
    factoryElevenRackMap["key6_modline6_reminder"] = "";


    //------------------------ Key 7 ------------------------//
    factoryElevenRackMap["key7_name"] = "MOD";
    factoryElevenRackMap["key7_displaymode"] = 1;
    factoryElevenRackMap["key7_prefix"] = "P";
    factoryElevenRackMap["key7_counter_min"] = 0;
    factoryElevenRackMap["key7_counter_max"] = 127;
    factoryElevenRackMap["key7_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryElevenRackMap["key7_modline1_enable"] = 1;
    factoryElevenRackMap["key7_modline1_source"] = "Foot_On";
    factoryElevenRackMap["key7_modline1_gain"] = 1.00;
    factoryElevenRackMap["key7_modline1_offset"] = 0.00;
    factoryElevenRackMap["key7_modline1_table"] = "Toggle_127";
    factoryElevenRackMap["key7_modline1_min"] = 0;
    factoryElevenRackMap["key7_modline1_max"] = 127;
    factoryElevenRackMap["key7_modline1_slew"] = 0;
    factoryElevenRackMap["key7_modline1_destination"] = "CC";
    factoryElevenRackMap["key7_modline1_note"] = 60;
    factoryElevenRackMap["key7_modline1_velocity"] = 127;
    factoryElevenRackMap["key7_modline1_cc"] = 50;
    factoryElevenRackMap["key7_modline1_mmcid"] = 0;
    factoryElevenRackMap["key7_modline1_mmcfunction"] = "Stop";
    factoryElevenRackMap["key7_modline1_channel"] = 1;
    factoryElevenRackMap["key7_modline1_device"] = "SoftStep_Expander";
    factoryElevenRackMap["key7_modline1_ledgreen"] = "True";
    factoryElevenRackMap["key7_modline1_ledred"] = "None";
    factoryElevenRackMap["key7_modline1_displaylinked"] = 1;
    factoryElevenRackMap["key7_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryElevenRackMap["key7_modline2_enable"] = 1;
    factoryElevenRackMap["key7_modline2_source"] = "Foot_On";
    factoryElevenRackMap["key7_modline2_gain"] = 1.00;
    factoryElevenRackMap["key7_modline2_offset"] = 0.00;
    factoryElevenRackMap["key7_modline2_table"] = "Toggle_127";
    factoryElevenRackMap["key7_modline2_min"] = 0;
    factoryElevenRackMap["key7_modline2_max"] = 127;
    factoryElevenRackMap["key7_modline2_slew"] = 0;
    factoryElevenRackMap["key7_modline2_destination"] = "CC";
    factoryElevenRackMap["key7_modline2_note"] = 60;
    factoryElevenRackMap["key7_modline2_velocity"] = 127;
    factoryElevenRackMap["key7_modline2_cc"] = 50;
    factoryElevenRackMap["key7_modline2_mmcid"] = 0;
    factoryElevenRackMap["key7_modline2_mmcfunction"] = "Stop";
    factoryElevenRackMap["key7_modline2_channel"] = 1;
    factoryElevenRackMap["key7_modline2_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key7_modline2_ledgreen"] = "None";
    factoryElevenRackMap["key7_modline2_ledred"] = "None";
    factoryElevenRackMap["key7_modline2_displaylinked"] = 0;
    factoryElevenRackMap["key7_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryElevenRackMap["key7_modline3_enable"] = 0;
    factoryElevenRackMap["key7_modline3_source"] = "None";
    factoryElevenRackMap["key7_modline3_gain"] = 0.00;
    factoryElevenRackMap["key7_modline3_offset"] = 0.00;
    factoryElevenRackMap["key7_modline3_table"] = "1_Lin";
    factoryElevenRackMap["key7_modline3_min"] = 0;
    factoryElevenRackMap["key7_modline3_max"] = 127;
    factoryElevenRackMap["key7_modline3_slew"] = 0;
    factoryElevenRackMap["key7_modline3_destination"] = "None";
    factoryElevenRackMap["key7_modline3_note"] = 60;
    factoryElevenRackMap["key7_modline3_velocity"] = 127;
    factoryElevenRackMap["key7_modline3_cc"] = 1;
    factoryElevenRackMap["key7_modline3_mmcid"] = 0;
    factoryElevenRackMap["key7_modline3_mmcfunction"] = "Stop";
    factoryElevenRackMap["key7_modline3_channel"] = 0;
    factoryElevenRackMap["key7_modline3_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key7_modline3_ledgreen"] = "None";
    factoryElevenRackMap["key7_modline3_ledred"] = "None";
    factoryElevenRackMap["key7_modline3_displaylinked"] = 0;
    factoryElevenRackMap["key7_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryElevenRackMap["key7_modline4_enable"] = 0;
    factoryElevenRackMap["key7_modline4_source"] = "None";
    factoryElevenRackMap["key7_modline4_gain"] = 0.00;
    factoryElevenRackMap["key7_modline4_offset"] = 0.00;
    factoryElevenRackMap["key7_modline4_table"] = "1_Lin";
    factoryElevenRackMap["key7_modline4_min"] = 0;
    factoryElevenRackMap["key7_modline4_max"] = 127;
    factoryElevenRackMap["key7_modline4_slew"] = 0;
    factoryElevenRackMap["key7_modline4_destination"] = "None";
    factoryElevenRackMap["key7_modline4_note"] = 60;
    factoryElevenRackMap["key7_modline4_velocity"] = 127;
    factoryElevenRackMap["key7_modline4_cc"] = 1;
    factoryElevenRackMap["key7_modline4_mmcid"] = 0;
    factoryElevenRackMap["key7_modline4_mmcfunction"] = "Stop";
    factoryElevenRackMap["key7_modline4_channel"] = 0;
    factoryElevenRackMap["key7_modline4_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key7_modline4_ledgreen"] = "None";
    factoryElevenRackMap["key7_modline4_ledred"] = "None";
    factoryElevenRackMap["key7_modline4_displaylinked"] = 0;
    factoryElevenRackMap["key7_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryElevenRackMap["key7_modline5_enable"] = 0;
    factoryElevenRackMap["key7_modline5_source"] = "None";
    factoryElevenRackMap["key7_modline5_gain"] = 0.00;
    factoryElevenRackMap["key7_modline5_offset"] = 0.00;
    factoryElevenRackMap["key7_modline5_table"] = "1_Lin";
    factoryElevenRackMap["key7_modline5_min"] = 0;
    factoryElevenRackMap["key7_modline5_max"] = 127;
    factoryElevenRackMap["key7_modline5_slew"] = 0;
    factoryElevenRackMap["key7_modline5_destination"] = "None";
    factoryElevenRackMap["key7_modline5_note"] = 60;
    factoryElevenRackMap["key7_modline5_velocity"] = 127;
    factoryElevenRackMap["key7_modline5_cc"] = 1;
    factoryElevenRackMap["key7_modline5_mmcid"] = 0;
    factoryElevenRackMap["key7_modline5_mmcfunction"] = "Stop";
    factoryElevenRackMap["key7_modline5_channel"] = 0;
    factoryElevenRackMap["key7_modline5_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key7_modline5_ledgreen"] = "None";
    factoryElevenRackMap["key7_modline5_ledred"] = "None";
    factoryElevenRackMap["key7_modline5_displaylinked"] = 0;
    factoryElevenRackMap["key7_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryElevenRackMap["key7_modline6_enable"] = 0;
    factoryElevenRackMap["key7_modline6_source"] = "None";
    factoryElevenRackMap["key7_modline6_gain"] = 0.00;
    factoryElevenRackMap["key7_modline6_offset"] = 0.00;
    factoryElevenRackMap["key7_modline6_table"] = "1_Lin";
    factoryElevenRackMap["key7_modline6_min"] = 0;
    factoryElevenRackMap["key7_modline6_max"] = 127;
    factoryElevenRackMap["key7_modline6_slew"] = 0;
    factoryElevenRackMap["key7_modline6_destination"] = "None";
    factoryElevenRackMap["key7_modline6_note"] = 60;
    factoryElevenRackMap["key7_modline6_velocity"] = 127;
    factoryElevenRackMap["key7_modline6_cc"] = 1;
    factoryElevenRackMap["key7_modline6_mmcid"] = 0;
    factoryElevenRackMap["key7_modline6_mmcfunction"] = "Stop";
    factoryElevenRackMap["key7_modline6_channel"] = 0;
    factoryElevenRackMap["key7_modline6_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key7_modline6_ledgreen"] = "None";
    factoryElevenRackMap["key7_modline6_ledred"] = "None";
    factoryElevenRackMap["key7_modline6_displaylinked"] = 0;
    factoryElevenRackMap["key7_modline6_reminder"] = "";


    //------------------------ Key 8 ------------------------//
    factoryElevenRackMap["key8_name"] = "DLY";
    factoryElevenRackMap["key8_displaymode"] = 1;
    factoryElevenRackMap["key8_prefix"] = "";
    factoryElevenRackMap["key8_counter_min"] = 0;
    factoryElevenRackMap["key8_counter_max"] = 127;
    factoryElevenRackMap["key8_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryElevenRackMap["key8_modline1_enable"] = 1;
    factoryElevenRackMap["key8_modline1_source"] = "Foot_On";
    factoryElevenRackMap["key8_modline1_gain"] = 1.00;
    factoryElevenRackMap["key8_modline1_offset"] = 0.00;
    factoryElevenRackMap["key8_modline1_table"] = "Toggle_127";
    factoryElevenRackMap["key8_modline1_min"] = 0;
    factoryElevenRackMap["key8_modline1_max"] = 127;
    factoryElevenRackMap["key8_modline1_slew"] = 0;
    factoryElevenRackMap["key8_modline1_destination"] = "CC";
    factoryElevenRackMap["key8_modline1_note"] = 60;
    factoryElevenRackMap["key8_modline1_velocity"] = 127;
    factoryElevenRackMap["key8_modline1_cc"] = 28;
    factoryElevenRackMap["key8_modline1_mmcid"] = 0;
    factoryElevenRackMap["key8_modline1_mmcfunction"] = "Stop";
    factoryElevenRackMap["key8_modline1_channel"] = 1;
    factoryElevenRackMap["key8_modline1_device"] = "SoftStep_Expander";
    factoryElevenRackMap["key8_modline1_ledgreen"] = "True";
    factoryElevenRackMap["key8_modline1_ledred"] = "None";
    factoryElevenRackMap["key8_modline1_displaylinked"] = 1;
    factoryElevenRackMap["key8_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryElevenRackMap["key8_modline2_enable"] = 1;
    factoryElevenRackMap["key8_modline2_source"] = "Foot_On";
    factoryElevenRackMap["key8_modline2_gain"] = 1.00;
    factoryElevenRackMap["key8_modline2_offset"] = 0.00;
    factoryElevenRackMap["key8_modline2_table"] = "Toggle_127";
    factoryElevenRackMap["key8_modline2_min"] = 0;
    factoryElevenRackMap["key8_modline2_max"] = 127;
    factoryElevenRackMap["key8_modline2_slew"] = 0;
    factoryElevenRackMap["key8_modline2_destination"] = "CC";
    factoryElevenRackMap["key8_modline2_note"] = 60;
    factoryElevenRackMap["key8_modline2_velocity"] = 127;
    factoryElevenRackMap["key8_modline2_cc"] = 28;
    factoryElevenRackMap["key8_modline2_mmcid"] = 0;
    factoryElevenRackMap["key8_modline2_mmcfunction"] = "Stop";
    factoryElevenRackMap["key8_modline2_channel"] = 1;
    factoryElevenRackMap["key8_modline2_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key8_modline2_ledgreen"] = "None";
    factoryElevenRackMap["key8_modline2_ledred"] = "None";
    factoryElevenRackMap["key8_modline2_displaylinked"] = 0;
    factoryElevenRackMap["key8_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryElevenRackMap["key8_modline3_enable"] = 0;
    factoryElevenRackMap["key8_modline3_source"] = "None";
    factoryElevenRackMap["key8_modline3_gain"] = 0.00;
    factoryElevenRackMap["key8_modline3_offset"] = 0.00;
    factoryElevenRackMap["key8_modline3_table"] = "1_Lin";
    factoryElevenRackMap["key8_modline3_min"] = 0;
    factoryElevenRackMap["key8_modline3_max"] = 127;
    factoryElevenRackMap["key8_modline3_slew"] = 0;
    factoryElevenRackMap["key8_modline3_destination"] = "None";
    factoryElevenRackMap["key8_modline3_note"] = 60;
    factoryElevenRackMap["key8_modline3_velocity"] = 127;
    factoryElevenRackMap["key8_modline3_cc"] = 1;
    factoryElevenRackMap["key8_modline3_mmcid"] = 0;
    factoryElevenRackMap["key8_modline3_mmcfunction"] = "Stop";
    factoryElevenRackMap["key8_modline3_channel"] = 0;
    factoryElevenRackMap["key8_modline3_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key8_modline3_ledgreen"] = "None";
    factoryElevenRackMap["key8_modline3_ledred"] = "None";
    factoryElevenRackMap["key8_modline3_displaylinked"] = 0;
    factoryElevenRackMap["key8_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryElevenRackMap["key8_modline4_enable"] = 0;
    factoryElevenRackMap["key8_modline4_source"] = "None";
    factoryElevenRackMap["key8_modline4_gain"] = 0.00;
    factoryElevenRackMap["key8_modline4_offset"] = 0.00;
    factoryElevenRackMap["key8_modline4_table"] = "1_Lin";
    factoryElevenRackMap["key8_modline4_min"] = 0;
    factoryElevenRackMap["key8_modline4_max"] = 127;
    factoryElevenRackMap["key8_modline4_slew"] = 0;
    factoryElevenRackMap["key8_modline4_destination"] = "None";
    factoryElevenRackMap["key8_modline4_note"] = 60;
    factoryElevenRackMap["key8_modline4_velocity"] = 127;
    factoryElevenRackMap["key8_modline4_cc"] = 1;
    factoryElevenRackMap["key8_modline4_mmcid"] = 0;
    factoryElevenRackMap["key8_modline4_mmcfunction"] = "Stop";
    factoryElevenRackMap["key8_modline4_channel"] = 0;
    factoryElevenRackMap["key8_modline4_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key8_modline4_ledgreen"] = "None";
    factoryElevenRackMap["key8_modline4_ledred"] = "None";
    factoryElevenRackMap["key8_modline4_displaylinked"] = 0;
    factoryElevenRackMap["key8_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryElevenRackMap["key8_modline5_enable"] = 0;
    factoryElevenRackMap["key8_modline5_source"] = "None";
    factoryElevenRackMap["key8_modline5_gain"] = 0.00;
    factoryElevenRackMap["key8_modline5_offset"] = 0.00;
    factoryElevenRackMap["key8_modline5_table"] = "1_Lin";
    factoryElevenRackMap["key8_modline5_min"] = 0;
    factoryElevenRackMap["key8_modline5_max"] = 127;
    factoryElevenRackMap["key8_modline5_slew"] = 0;
    factoryElevenRackMap["key8_modline5_destination"] = "None";
    factoryElevenRackMap["key8_modline5_note"] = 60;
    factoryElevenRackMap["key8_modline5_velocity"] = 127;
    factoryElevenRackMap["key8_modline5_cc"] = 1;
    factoryElevenRackMap["key8_modline5_mmcid"] = 0;
    factoryElevenRackMap["key8_modline5_mmcfunction"] = "Stop";
    factoryElevenRackMap["key8_modline5_channel"] = 0;
    factoryElevenRackMap["key8_modline5_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key8_modline5_ledgreen"] = "None";
    factoryElevenRackMap["key8_modline5_ledred"] = "None";
    factoryElevenRackMap["key8_modline5_displaylinked"] = 0;
    factoryElevenRackMap["key8_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryElevenRackMap["key8_modline6_enable"] = 0;
    factoryElevenRackMap["key8_modline6_source"] = "None";
    factoryElevenRackMap["key8_modline6_gain"] = 0.00;
    factoryElevenRackMap["key8_modline6_offset"] = 0.00;
    factoryElevenRackMap["key8_modline6_table"] = "1_Lin";
    factoryElevenRackMap["key8_modline6_min"] = 0;
    factoryElevenRackMap["key8_modline6_max"] = 127;
    factoryElevenRackMap["key8_modline6_slew"] = 0;
    factoryElevenRackMap["key8_modline6_destination"] = "None";
    factoryElevenRackMap["key8_modline6_note"] = 60;
    factoryElevenRackMap["key8_modline6_velocity"] = 127;
    factoryElevenRackMap["key8_modline6_cc"] = 1;
    factoryElevenRackMap["key8_modline6_mmcid"] = 0;
    factoryElevenRackMap["key8_modline6_mmcfunction"] = "Stop";
    factoryElevenRackMap["key8_modline6_channel"] = 0;
    factoryElevenRackMap["key8_modline6_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key8_modline6_ledgreen"] = "None";
    factoryElevenRackMap["key8_modline6_ledred"] = "None";
    factoryElevenRackMap["key8_modline6_displaylinked"] = 0;
    factoryElevenRackMap["key8_modline6_reminder"] = "";


    //------------------------ Key 9 ------------------------//
    factoryElevenRackMap["key9_name"] = "REVB";
    factoryElevenRackMap["key9_displaymode"] = 1;
    factoryElevenRackMap["key9_prefix"] = "";
    factoryElevenRackMap["key9_counter_min"] = 0;
    factoryElevenRackMap["key9_counter_max"] = 127;
    factoryElevenRackMap["key9_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryElevenRackMap["key9_modline1_enable"] = 1;
    factoryElevenRackMap["key9_modline1_source"] = "Foot_On";
    factoryElevenRackMap["key9_modline1_gain"] = 1.00;
    factoryElevenRackMap["key9_modline1_offset"] = 0.00;
    factoryElevenRackMap["key9_modline1_table"] = "Toggle_127";
    factoryElevenRackMap["key9_modline1_min"] = 0;
    factoryElevenRackMap["key9_modline1_max"] = 127;
    factoryElevenRackMap["key9_modline1_slew"] = 0;
    factoryElevenRackMap["key9_modline1_destination"] = "CC";
    factoryElevenRackMap["key9_modline1_note"] = 60;
    factoryElevenRackMap["key9_modline1_velocity"] = 127;
    factoryElevenRackMap["key9_modline1_cc"] = 36;
    factoryElevenRackMap["key9_modline1_mmcid"] = 0;
    factoryElevenRackMap["key9_modline1_mmcfunction"] = "Stop";
    factoryElevenRackMap["key9_modline1_channel"] = 1;
    factoryElevenRackMap["key9_modline1_device"] = "SoftStep_Expander";
    factoryElevenRackMap["key9_modline1_ledgreen"] = "True";
    factoryElevenRackMap["key9_modline1_ledred"] = "None";
    factoryElevenRackMap["key9_modline1_displaylinked"] = 1;
    factoryElevenRackMap["key9_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryElevenRackMap["key9_modline2_enable"] = 1;
    factoryElevenRackMap["key9_modline2_source"] = "Foot_On";
    factoryElevenRackMap["key9_modline2_gain"] = 1.00;
    factoryElevenRackMap["key9_modline2_offset"] = 0.00;
    factoryElevenRackMap["key9_modline2_table"] = "Toggle_127";
    factoryElevenRackMap["key9_modline2_min"] = 0;
    factoryElevenRackMap["key9_modline2_max"] = 127;
    factoryElevenRackMap["key9_modline2_slew"] = 0;
    factoryElevenRackMap["key9_modline2_destination"] = "CC";
    factoryElevenRackMap["key9_modline2_note"] = 60;
    factoryElevenRackMap["key9_modline2_velocity"] = 127;
    factoryElevenRackMap["key9_modline2_cc"] = 36;
    factoryElevenRackMap["key9_modline2_mmcid"] = 0;
    factoryElevenRackMap["key9_modline2_mmcfunction"] = "Stop";
    factoryElevenRackMap["key9_modline2_channel"] = 1;
    factoryElevenRackMap["key9_modline2_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key9_modline2_ledgreen"] = "None";
    factoryElevenRackMap["key9_modline2_ledred"] = "None";
    factoryElevenRackMap["key9_modline2_displaylinked"] = 0;
    factoryElevenRackMap["key9_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryElevenRackMap["key9_modline3_enable"] = 0;
    factoryElevenRackMap["key9_modline3_source"] = "None";
    factoryElevenRackMap["key9_modline3_gain"] = 0.00;
    factoryElevenRackMap["key9_modline3_offset"] = 0.00;
    factoryElevenRackMap["key9_modline3_table"] = "1_Lin";
    factoryElevenRackMap["key9_modline3_min"] = 0;
    factoryElevenRackMap["key9_modline3_max"] = 127;
    factoryElevenRackMap["key9_modline3_slew"] = 0;
    factoryElevenRackMap["key9_modline3_destination"] = "None";
    factoryElevenRackMap["key9_modline3_note"] = 60;
    factoryElevenRackMap["key9_modline3_velocity"] = 127;
    factoryElevenRackMap["key9_modline3_cc"] = 1;
    factoryElevenRackMap["key9_modline3_mmcid"] = 0;
    factoryElevenRackMap["key9_modline3_mmcfunction"] = "Stop";
    factoryElevenRackMap["key9_modline3_channel"] = 0;
    factoryElevenRackMap["key9_modline3_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key9_modline3_ledgreen"] = "None";
    factoryElevenRackMap["key9_modline3_ledred"] = "None";
    factoryElevenRackMap["key9_modline3_displaylinked"] = 0;
    factoryElevenRackMap["key9_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryElevenRackMap["key9_modline4_enable"] = 0;
    factoryElevenRackMap["key9_modline4_source"] = "None";
    factoryElevenRackMap["key9_modline4_gain"] = 0.00;
    factoryElevenRackMap["key9_modline4_offset"] = 0.00;
    factoryElevenRackMap["key9_modline4_table"] = "1_Lin";
    factoryElevenRackMap["key9_modline4_min"] = 0;
    factoryElevenRackMap["key9_modline4_max"] = 127;
    factoryElevenRackMap["key9_modline4_slew"] = 0;
    factoryElevenRackMap["key9_modline4_destination"] = "None";
    factoryElevenRackMap["key9_modline4_note"] = 60;
    factoryElevenRackMap["key9_modline4_velocity"] = 127;
    factoryElevenRackMap["key9_modline4_cc"] = 1;
    factoryElevenRackMap["key9_modline4_mmcid"] = 0;
    factoryElevenRackMap["key9_modline4_mmcfunction"] = "Stop";
    factoryElevenRackMap["key9_modline4_channel"] = 0;
    factoryElevenRackMap["key9_modline4_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key9_modline4_ledgreen"] = "None";
    factoryElevenRackMap["key9_modline4_ledred"] = "None";
    factoryElevenRackMap["key9_modline4_displaylinked"] = 0;
    factoryElevenRackMap["key9_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryElevenRackMap["key9_modline5_enable"] = 0;
    factoryElevenRackMap["key9_modline5_source"] = "None";
    factoryElevenRackMap["key9_modline5_gain"] = 0.00;
    factoryElevenRackMap["key9_modline5_offset"] = 0.00;
    factoryElevenRackMap["key9_modline5_table"] = "1_Lin";
    factoryElevenRackMap["key9_modline5_min"] = 0;
    factoryElevenRackMap["key9_modline5_max"] = 127;
    factoryElevenRackMap["key9_modline5_slew"] = 0;
    factoryElevenRackMap["key9_modline5_destination"] = "None";
    factoryElevenRackMap["key9_modline5_note"] = 60;
    factoryElevenRackMap["key9_modline5_velocity"] = 127;
    factoryElevenRackMap["key9_modline5_cc"] = 1;
    factoryElevenRackMap["key9_modline5_mmcid"] = 0;
    factoryElevenRackMap["key9_modline5_mmcfunction"] = "Stop";
    factoryElevenRackMap["key9_modline5_channel"] = 0;
    factoryElevenRackMap["key9_modline5_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key9_modline5_ledgreen"] = "None";
    factoryElevenRackMap["key9_modline5_ledred"] = "None";
    factoryElevenRackMap["key9_modline5_displaylinked"] = 0;
    factoryElevenRackMap["key9_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryElevenRackMap["key9_modline6_enable"] = 0;
    factoryElevenRackMap["key9_modline6_source"] = "None";
    factoryElevenRackMap["key9_modline6_gain"] = 0.00;
    factoryElevenRackMap["key9_modline6_offset"] = 0.00;
    factoryElevenRackMap["key9_modline6_table"] = "1_Lin";
    factoryElevenRackMap["key9_modline6_min"] = 0;
    factoryElevenRackMap["key9_modline6_max"] = 127;
    factoryElevenRackMap["key9_modline6_slew"] = 0;
    factoryElevenRackMap["key9_modline6_destination"] = "None";
    factoryElevenRackMap["key9_modline6_note"] = 60;
    factoryElevenRackMap["key9_modline6_velocity"] = 127;
    factoryElevenRackMap["key9_modline6_cc"] = 1;
    factoryElevenRackMap["key9_modline6_mmcid"] = 0;
    factoryElevenRackMap["key9_modline6_mmcfunction"] = "Stop";
    factoryElevenRackMap["key9_modline6_channel"] = 0;
    factoryElevenRackMap["key9_modline6_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key9_modline6_ledgreen"] = "None";
    factoryElevenRackMap["key9_modline6_ledred"] = "None";
    factoryElevenRackMap["key9_modline6_displaylinked"] = 0;
    factoryElevenRackMap["key9_modline6_reminder"] = "";


    //------------------------ Key 10 ------------------------//
    factoryElevenRackMap["key10_name"] = "WAH";
    factoryElevenRackMap["key10_displaymode"] = 1;
    factoryElevenRackMap["key10_prefix"] = "";
    factoryElevenRackMap["key10_counter_min"] = 0;
    factoryElevenRackMap["key10_counter_max"] = 127;
    factoryElevenRackMap["key10_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryElevenRackMap["key10_modline1_enable"] = 1;
    factoryElevenRackMap["key10_modline1_source"] = "Foot_On";
    factoryElevenRackMap["key10_modline1_gain"] = 1.00;
    factoryElevenRackMap["key10_modline1_offset"] = 0.00;
    factoryElevenRackMap["key10_modline1_table"] = "Toggle_127";
    factoryElevenRackMap["key10_modline1_min"] = 0;
    factoryElevenRackMap["key10_modline1_max"] = 127;
    factoryElevenRackMap["key10_modline1_slew"] = 0;
    factoryElevenRackMap["key10_modline1_destination"] = "CC";
    factoryElevenRackMap["key10_modline1_note"] = 60;
    factoryElevenRackMap["key10_modline1_velocity"] = 127;
    factoryElevenRackMap["key10_modline1_cc"] = 43;
    factoryElevenRackMap["key10_modline1_mmcid"] = 0;
    factoryElevenRackMap["key10_modline1_mmcfunction"] = "Stop";
    factoryElevenRackMap["key10_modline1_channel"] = 1;
    factoryElevenRackMap["key10_modline1_device"] = "SoftStep_Expander";
    factoryElevenRackMap["key10_modline1_ledgreen"] = "True";
    factoryElevenRackMap["key10_modline1_ledred"] = "None";
    factoryElevenRackMap["key10_modline1_displaylinked"] = 1;
    factoryElevenRackMap["key10_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryElevenRackMap["key10_modline2_enable"] = 1;
    factoryElevenRackMap["key10_modline2_source"] = "Foot_On";
    factoryElevenRackMap["key10_modline2_gain"] = 1.00;
    factoryElevenRackMap["key10_modline2_offset"] = 0.00;
    factoryElevenRackMap["key10_modline2_table"] = "Toggle_127";
    factoryElevenRackMap["key10_modline2_min"] = 0;
    factoryElevenRackMap["key10_modline2_max"] = 127;
    factoryElevenRackMap["key10_modline2_slew"] = 0;
    factoryElevenRackMap["key10_modline2_destination"] = "CC";
    factoryElevenRackMap["key10_modline2_note"] = 60;
    factoryElevenRackMap["key10_modline2_velocity"] = 127;
    factoryElevenRackMap["key10_modline2_cc"] = 43;
    factoryElevenRackMap["key10_modline2_mmcid"] = 0;
    factoryElevenRackMap["key10_modline2_mmcfunction"] = "Stop";
    factoryElevenRackMap["key10_modline2_channel"] = 1;
    factoryElevenRackMap["key10_modline2_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key10_modline2_ledgreen"] = "None";
    factoryElevenRackMap["key10_modline2_ledred"] = "None";
    factoryElevenRackMap["key10_modline2_displaylinked"] = 0;
    factoryElevenRackMap["key10_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryElevenRackMap["key10_modline3_enable"] = 0;
    factoryElevenRackMap["key10_modline3_source"] = "None";
    factoryElevenRackMap["key10_modline3_gain"] = 0.00;
    factoryElevenRackMap["key10_modline3_offset"] = 0.00;
    factoryElevenRackMap["key10_modline3_table"] = "1_Lin";
    factoryElevenRackMap["key10_modline3_min"] = 0;
    factoryElevenRackMap["key10_modline3_max"] = 127;
    factoryElevenRackMap["key10_modline3_slew"] = 0;
    factoryElevenRackMap["key10_modline3_destination"] = "None";
    factoryElevenRackMap["key10_modline3_note"] = 60;
    factoryElevenRackMap["key10_modline3_velocity"] = 127;
    factoryElevenRackMap["key10_modline3_cc"] = 1;
    factoryElevenRackMap["key10_modline3_mmcid"] = 0;
    factoryElevenRackMap["key10_modline3_mmcfunction"] = "Stop";
    factoryElevenRackMap["key10_modline3_channel"] = 0;
    factoryElevenRackMap["key10_modline3_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key10_modline3_ledgreen"] = "None";
    factoryElevenRackMap["key10_modline3_ledred"] = "None";
    factoryElevenRackMap["key10_modline3_displaylinked"] = 0;
    factoryElevenRackMap["key10_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryElevenRackMap["key10_modline4_enable"] = 0;
    factoryElevenRackMap["key10_modline4_source"] = "None";
    factoryElevenRackMap["key10_modline4_gain"] = 0.00;
    factoryElevenRackMap["key10_modline4_offset"] = 0.00;
    factoryElevenRackMap["key10_modline4_table"] = "1_Lin";
    factoryElevenRackMap["key10_modline4_min"] = 0;
    factoryElevenRackMap["key10_modline4_max"] = 127;
    factoryElevenRackMap["key10_modline4_slew"] = 0;
    factoryElevenRackMap["key10_modline4_destination"] = "None";
    factoryElevenRackMap["key10_modline4_note"] = 60;
    factoryElevenRackMap["key10_modline4_velocity"] = 127;
    factoryElevenRackMap["key10_modline4_cc"] = 1;
    factoryElevenRackMap["key10_modline4_mmcid"] = 0;
    factoryElevenRackMap["key10_modline4_mmcfunction"] = "Stop";
    factoryElevenRackMap["key10_modline4_channel"] = 0;
    factoryElevenRackMap["key10_modline4_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key10_modline4_ledgreen"] = "None";
    factoryElevenRackMap["key10_modline4_ledred"] = "None";
    factoryElevenRackMap["key10_modline4_displaylinked"] = 0;
    factoryElevenRackMap["key10_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryElevenRackMap["key10_modline5_enable"] = 0;
    factoryElevenRackMap["key10_modline5_source"] = "None";
    factoryElevenRackMap["key10_modline5_gain"] = 0.00;
    factoryElevenRackMap["key10_modline5_offset"] = 0.00;
    factoryElevenRackMap["key10_modline5_table"] = "1_Lin";
    factoryElevenRackMap["key10_modline5_min"] = 0;
    factoryElevenRackMap["key10_modline5_max"] = 127;
    factoryElevenRackMap["key10_modline5_slew"] = 0;
    factoryElevenRackMap["key10_modline5_destination"] = "None";
    factoryElevenRackMap["key10_modline5_note"] = 60;
    factoryElevenRackMap["key10_modline5_velocity"] = 127;
    factoryElevenRackMap["key10_modline5_cc"] = 1;
    factoryElevenRackMap["key10_modline5_mmcid"] = 0;
    factoryElevenRackMap["key10_modline5_mmcfunction"] = "Stop";
    factoryElevenRackMap["key10_modline5_channel"] = 0;
    factoryElevenRackMap["key10_modline5_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key10_modline5_ledgreen"] = "None";
    factoryElevenRackMap["key10_modline5_ledred"] = "None";
    factoryElevenRackMap["key10_modline5_displaylinked"] = 0;
    factoryElevenRackMap["key10_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryElevenRackMap["key10_modline6_enable"] = 0;
    factoryElevenRackMap["key10_modline6_source"] = "None";
    factoryElevenRackMap["key10_modline6_gain"] = 0.00;
    factoryElevenRackMap["key10_modline6_offset"] = 0.00;
    factoryElevenRackMap["key10_modline6_table"] = "1_Lin";
    factoryElevenRackMap["key10_modline6_min"] = 0;
    factoryElevenRackMap["key10_modline6_max"] = 127;
    factoryElevenRackMap["key10_modline6_slew"] = 0;
    factoryElevenRackMap["key10_modline6_destination"] = "None";
    factoryElevenRackMap["key10_modline6_note"] = 60;
    factoryElevenRackMap["key10_modline6_velocity"] = 127;
    factoryElevenRackMap["key10_modline6_cc"] = 1;
    factoryElevenRackMap["key10_modline6_mmcid"] = 0;
    factoryElevenRackMap["key10_modline6_mmcfunction"] = "Stop";
    factoryElevenRackMap["key10_modline6_channel"] = 0;
    factoryElevenRackMap["key10_modline6_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["key10_modline6_ledgreen"] = "None";
    factoryElevenRackMap["key10_modline6_ledred"] = "None";
    factoryElevenRackMap["key10_modline6_displaylinked"] = 0;
    factoryElevenRackMap["key10_modline6_reminder"] = "";


    //------------------------ Nav ------------------------//
    factoryElevenRackMap["nav_name"] = "";
    factoryElevenRackMap["nav_displaymode"] = 4;
    factoryElevenRackMap["nav_modlinemode"] = 1;
    factoryElevenRackMap["nav_prefix"] = "";
    factoryElevenRackMap["nav_counter_min"] = 0;
    factoryElevenRackMap["nav_counter_max"] = 127;
    factoryElevenRackMap["nav_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryElevenRackMap["nav_modline1_enable"] = 1;
    factoryElevenRackMap["nav_modline1_source"] = "Pedal";
    factoryElevenRackMap["nav_modline1_gain"] = 1.00;
    factoryElevenRackMap["nav_modline1_offset"] = 0.00;
    factoryElevenRackMap["nav_modline1_table"] = "1_Lin";
    factoryElevenRackMap["nav_modline1_min"] = 0;
    factoryElevenRackMap["nav_modline1_max"] = 127;
    factoryElevenRackMap["nav_modline1_slew"] = 0;
    factoryElevenRackMap["nav_modline1_destination"] = "CC";
    factoryElevenRackMap["nav_modline1_note"] = 60;
    factoryElevenRackMap["nav_modline1_velocity"] = 127;
    factoryElevenRackMap["nav_modline1_cc"] = 7;
    factoryElevenRackMap["nav_modline1_mmcid"] = 0;
    factoryElevenRackMap["nav_modline1_mmcfunction"] = "Stop";
    factoryElevenRackMap["nav_modline1_channel"] = 1;
    factoryElevenRackMap["nav_modline1_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["nav_modline1_displaylinked"] = 1;
    factoryElevenRackMap["nav_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryElevenRackMap["nav_modline2_enable"] = 1;
    factoryElevenRackMap["nav_modline2_source"] = "Pedal";
    factoryElevenRackMap["nav_modline2_gain"] = 1.00;
    factoryElevenRackMap["nav_modline2_offset"] = 0.00;
    factoryElevenRackMap["nav_modline2_table"] = "1_Lin";
    factoryElevenRackMap["nav_modline2_min"] = 0;
    factoryElevenRackMap["nav_modline2_max"] = 127;
    factoryElevenRackMap["nav_modline2_slew"] = 0;
    factoryElevenRackMap["nav_modline2_destination"] = "CC";
    factoryElevenRackMap["nav_modline2_note"] = 60;
    factoryElevenRackMap["nav_modline2_velocity"] = 127;
    factoryElevenRackMap["nav_modline2_cc"] = 7;
    factoryElevenRackMap["nav_modline2_mmcid"] = 0;
    factoryElevenRackMap["nav_modline2_mmcfunction"] = "Stop";
    factoryElevenRackMap["nav_modline2_channel"] = 1;
    factoryElevenRackMap["nav_modline2_device"] = "SoftStep_Expander";
    factoryElevenRackMap["nav_modline2_displaylinked"] = 0;
    factoryElevenRackMap["nav_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryElevenRackMap["nav_modline3_enable"] = 0;
    factoryElevenRackMap["nav_modline3_source"] = "None";
    factoryElevenRackMap["nav_modline3_gain"] = 0.00;
    factoryElevenRackMap["nav_modline3_offset"] = 0.00;
    factoryElevenRackMap["nav_modline3_table"] = "1_Lin";
    factoryElevenRackMap["nav_modline3_min"] = 0;
    factoryElevenRackMap["nav_modline3_max"] = 127;
    factoryElevenRackMap["nav_modline3_slew"] = 0;
    factoryElevenRackMap["nav_modline3_destination"] = "None";
    factoryElevenRackMap["nav_modline3_note"] = 60;
    factoryElevenRackMap["nav_modline3_velocity"] = 127;
    factoryElevenRackMap["nav_modline3_cc"] = 1;
    factoryElevenRackMap["nav_modline3_mmcid"] = 0;
    factoryElevenRackMap["nav_modline3_mmcfunction"] = "Stop";
    factoryElevenRackMap["nav_modline3_channel"] = 0;
    factoryElevenRackMap["nav_modline3_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["nav_modline3_displaylinked"] = 0;
    factoryElevenRackMap["nav_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryElevenRackMap["nav_modline4_enable"] = 0;
    factoryElevenRackMap["nav_modline4_source"] = "None";
    factoryElevenRackMap["nav_modline4_gain"] = 0.00;
    factoryElevenRackMap["nav_modline4_offset"] = 0.00;
    factoryElevenRackMap["nav_modline4_table"] = "1_Lin";
    factoryElevenRackMap["nav_modline4_min"] = 0;
    factoryElevenRackMap["nav_modline4_max"] = 127;
    factoryElevenRackMap["nav_modline4_slew"] = 0;
    factoryElevenRackMap["nav_modline4_destination"] = "None";
    factoryElevenRackMap["nav_modline4_note"] = 60;
    factoryElevenRackMap["nav_modline4_velocity"] = 127;
    factoryElevenRackMap["nav_modline4_cc"] = 1;
    factoryElevenRackMap["nav_modline4_mmcid"] = 0;
    factoryElevenRackMap["nav_modline4_mmcfunction"] = "Stop";
    factoryElevenRackMap["nav_modline4_channel"] = 0;
    factoryElevenRackMap["nav_modline4_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["nav_modline4_displaylinked"] = 0;
    factoryElevenRackMap["nav_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryElevenRackMap["nav_modline5_enable"] = 0;
    factoryElevenRackMap["nav_modline5_source"] = "None";
    factoryElevenRackMap["nav_modline5_gain"] = 0.00;
    factoryElevenRackMap["nav_modline5_offset"] = 0.00;
    factoryElevenRackMap["nav_modline5_table"] = "1_Lin";
    factoryElevenRackMap["nav_modline5_min"] = 0;
    factoryElevenRackMap["nav_modline5_max"] = 127;
    factoryElevenRackMap["nav_modline5_slew"] = 0;
    factoryElevenRackMap["nav_modline5_destination"] = "None";
    factoryElevenRackMap["nav_modline5_note"] = 60;
    factoryElevenRackMap["nav_modline5_velocity"] = 127;
    factoryElevenRackMap["nav_modline5_cc"] = 1;
    factoryElevenRackMap["nav_modline5_mmcid"] = 0;
    factoryElevenRackMap["nav_modline5_mmcfunction"] = "Stop";
    factoryElevenRackMap["nav_modline5_channel"] = 0;
    factoryElevenRackMap["nav_modline5_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["nav_modline5_displaylinked"] = 0;
    factoryElevenRackMap["nav_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryElevenRackMap["nav_modline6_enable"] = 0;
    factoryElevenRackMap["nav_modline6_source"] = "None";
    factoryElevenRackMap["nav_modline6_gain"] = 0.00;
    factoryElevenRackMap["nav_modline6_offset"] = 0.00;
    factoryElevenRackMap["nav_modline6_table"] = "1_Lin";
    factoryElevenRackMap["nav_modline6_min"] = 0;
    factoryElevenRackMap["nav_modline6_max"] = 127;
    factoryElevenRackMap["nav_modline6_slew"] = 0;
    factoryElevenRackMap["nav_modline6_destination"] = "None";
    factoryElevenRackMap["nav_modline6_note"] = 60;
    factoryElevenRackMap["nav_modline6_velocity"] = 127;
    factoryElevenRackMap["nav_modline6_cc"] = 1;
    factoryElevenRackMap["nav_modline6_mmcid"] = 0;
    factoryElevenRackMap["nav_modline6_mmcfunction"] = "Stop";
    factoryElevenRackMap["nav_modline6_channel"] = 0;
    factoryElevenRackMap["nav_modline6_device"] = "SSCOM_Port_1";
    factoryElevenRackMap["nav_modline6_displaylinked"] = 0;
    factoryElevenRackMap["nav_modline6_reminder"] = "";

}

void FactoryPresets::createPodMap(){

    factoryPodMap["displayname"] = "POD";

    factoryPodMap["useFactory"] = "Line6 Pod Control";

    //------------------------ Key 1 ------------------------//
    factoryPodMap["key1_name"] = "PRES";
    factoryPodMap["key1_displaymode"] = 4;
    factoryPodMap["key1_prefix"] = "";
    factoryPodMap["key1_counter_min"] = 0;
    factoryPodMap["key1_counter_max"] = 127;
    factoryPodMap["key1_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryPodMap["key1_modline1_enable"] = 1;
    factoryPodMap["key1_modline1_source"] = "Y_Increment";
    factoryPodMap["key1_modline1_gain"] = 0.80;
    factoryPodMap["key1_modline1_offset"] = 30.00;
    factoryPodMap["key1_modline1_table"] = "1_Lin";
    factoryPodMap["key1_modline1_min"] = 0;
    factoryPodMap["key1_modline1_max"] = 127;
    factoryPodMap["key1_modline1_slew"] = 0;
    factoryPodMap["key1_modline1_destination"] = "CC";
    factoryPodMap["key1_modline1_note"] = 60;
    factoryPodMap["key1_modline1_velocity"] = 127;
    factoryPodMap["key1_modline1_cc"] = 13;
    factoryPodMap["key1_modline1_mmcid"] = 0;
    factoryPodMap["key1_modline1_mmcfunction"] = "Stop";
    factoryPodMap["key1_modline1_channel"] = 1;
    factoryPodMap["key1_modline1_device"] = "SSCOM_Port_1";
    factoryPodMap["key1_modline1_ledgreen"] = "None";
    factoryPodMap["key1_modline1_ledred"] = "None";
    factoryPodMap["key1_modline1_displaylinked"] = 1;
    factoryPodMap["key1_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryPodMap["key1_modline2_enable"] = 1;
    factoryPodMap["key1_modline2_source"] = "Y_Increment";
    factoryPodMap["key1_modline2_gain"] = 0.80;
    factoryPodMap["key1_modline2_offset"] = 30.00;
    factoryPodMap["key1_modline2_table"] = "1_Lin";
    factoryPodMap["key1_modline2_min"] = 0;
    factoryPodMap["key1_modline2_max"] = 127;
    factoryPodMap["key1_modline2_slew"] = 0;
    factoryPodMap["key1_modline2_destination"] = "CC";
    factoryPodMap["key1_modline2_note"] = 60;
    factoryPodMap["key1_modline2_velocity"] = 127;
    factoryPodMap["key1_modline2_cc"] = 13;
    factoryPodMap["key1_modline2_mmcid"] = 0;
    factoryPodMap["key1_modline2_mmcfunction"] = "Stop";
    factoryPodMap["key1_modline2_channel"] = 1;
    factoryPodMap["key1_modline2_device"] = "SoftStep_Expander";
    factoryPodMap["key1_modline2_ledgreen"] = "None";
    factoryPodMap["key1_modline2_ledred"] = "None";
    factoryPodMap["key1_modline2_displaylinked"] = 0;
    factoryPodMap["key1_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryPodMap["key1_modline3_enable"] = 0;
    factoryPodMap["key1_modline3_source"] = "None";
    factoryPodMap["key1_modline3_gain"] = 0.00;
    factoryPodMap["key1_modline3_offset"] = 0.00;
    factoryPodMap["key1_modline3_table"] = "1_Lin";
    factoryPodMap["key1_modline3_min"] = 0;
    factoryPodMap["key1_modline3_max"] = 127;
    factoryPodMap["key1_modline3_slew"] = 0;
    factoryPodMap["key1_modline3_destination"] = "None";
    factoryPodMap["key1_modline3_note"] = 60;
    factoryPodMap["key1_modline3_velocity"] = 127;
    factoryPodMap["key1_modline3_cc"] = 1;
    factoryPodMap["key1_modline3_mmcid"] = 0;
    factoryPodMap["key1_modline3_mmcfunction"] = "Stop";
    factoryPodMap["key1_modline3_channel"] = 0;
    factoryPodMap["key1_modline3_device"] = "SSCOM_Port_1";
    factoryPodMap["key1_modline3_ledgreen"] = "None";
    factoryPodMap["key1_modline3_ledred"] = "None";
    factoryPodMap["key1_modline3_displaylinked"] = 0;
    factoryPodMap["key1_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryPodMap["key1_modline4_enable"] = 0;
    factoryPodMap["key1_modline4_source"] = "None";
    factoryPodMap["key1_modline4_gain"] = 0.00;
    factoryPodMap["key1_modline4_offset"] = 0.00;
    factoryPodMap["key1_modline4_table"] = "1_Lin";
    factoryPodMap["key1_modline4_min"] = 0;
    factoryPodMap["key1_modline4_max"] = 127;
    factoryPodMap["key1_modline4_slew"] = 0;
    factoryPodMap["key1_modline4_destination"] = "None";
    factoryPodMap["key1_modline4_note"] = 60;
    factoryPodMap["key1_modline4_velocity"] = 127;
    factoryPodMap["key1_modline4_cc"] = 1;
    factoryPodMap["key1_modline4_mmcid"] = 0;
    factoryPodMap["key1_modline4_mmcfunction"] = "Stop";
    factoryPodMap["key1_modline4_channel"] = 0;
    factoryPodMap["key1_modline4_device"] = "SSCOM_Port_1";
    factoryPodMap["key1_modline4_ledgreen"] = "None";
    factoryPodMap["key1_modline4_ledred"] = "None";
    factoryPodMap["key1_modline4_displaylinked"] = 0;
    factoryPodMap["key1_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryPodMap["key1_modline5_enable"] = 0;
    factoryPodMap["key1_modline5_source"] = "None";
    factoryPodMap["key1_modline5_gain"] = 0.00;
    factoryPodMap["key1_modline5_offset"] = 0.00;
    factoryPodMap["key1_modline5_table"] = "1_Lin";
    factoryPodMap["key1_modline5_min"] = 0;
    factoryPodMap["key1_modline5_max"] = 127;
    factoryPodMap["key1_modline5_slew"] = 0;
    factoryPodMap["key1_modline5_destination"] = "None";
    factoryPodMap["key1_modline5_note"] = 60;
    factoryPodMap["key1_modline5_velocity"] = 127;
    factoryPodMap["key1_modline5_cc"] = 1;
    factoryPodMap["key1_modline5_mmcid"] = 0;
    factoryPodMap["key1_modline5_mmcfunction"] = "Stop";
    factoryPodMap["key1_modline5_channel"] = 0;
    factoryPodMap["key1_modline5_device"] = "SSCOM_Port_1";
    factoryPodMap["key1_modline5_ledgreen"] = "None";
    factoryPodMap["key1_modline5_ledred"] = "None";
    factoryPodMap["key1_modline5_displaylinked"] = 0;
    factoryPodMap["key1_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryPodMap["key1_modline6_enable"] = 0;
    factoryPodMap["key1_modline6_source"] = "None";
    factoryPodMap["key1_modline6_gain"] = 0.00;
    factoryPodMap["key1_modline6_offset"] = 0.00;
    factoryPodMap["key1_modline6_table"] = "1_Lin";
    factoryPodMap["key1_modline6_min"] = 0;
    factoryPodMap["key1_modline6_max"] = 127;
    factoryPodMap["key1_modline6_slew"] = 0;
    factoryPodMap["key1_modline6_destination"] = "None";
    factoryPodMap["key1_modline6_note"] = 60;
    factoryPodMap["key1_modline6_velocity"] = 127;
    factoryPodMap["key1_modline6_cc"] = 1;
    factoryPodMap["key1_modline6_mmcid"] = 0;
    factoryPodMap["key1_modline6_mmcfunction"] = "Stop";
    factoryPodMap["key1_modline6_channel"] = 0;
    factoryPodMap["key1_modline6_device"] = "SSCOM_Port_1";
    factoryPodMap["key1_modline6_ledgreen"] = "None";
    factoryPodMap["key1_modline6_ledred"] = "None";
    factoryPodMap["key1_modline6_displaylinked"] = 0;
    factoryPodMap["key1_modline6_reminder"] = "";


    //------------------------ Key 2 ------------------------//
    factoryPodMap["key2_name"] = "MODX";
    factoryPodMap["key2_displaymode"] = 4;
    factoryPodMap["key2_prefix"] = "";
    factoryPodMap["key2_counter_min"] = 0;
    factoryPodMap["key2_counter_max"] = 127;
    factoryPodMap["key2_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryPodMap["key2_modline1_enable"] = 1;
    factoryPodMap["key2_modline1_source"] = "Pressure_Live";
    factoryPodMap["key2_modline1_gain"] = 1.00;
    factoryPodMap["key2_modline1_offset"] = 0.00;
    factoryPodMap["key2_modline1_table"] = "1_Lin";
    factoryPodMap["key2_modline1_min"] = 0;
    factoryPodMap["key2_modline1_max"] = 80;
    factoryPodMap["key2_modline1_slew"] = 0;
    factoryPodMap["key2_modline1_destination"] = "CC";
    factoryPodMap["key2_modline1_note"] = 60;
    factoryPodMap["key2_modline1_velocity"] = 127;
    factoryPodMap["key2_modline1_cc"] = 29;
    factoryPodMap["key2_modline1_mmcid"] = 0;
    factoryPodMap["key2_modline1_mmcfunction"] = "Stop";
    factoryPodMap["key2_modline1_channel"] = 1;
    factoryPodMap["key2_modline1_device"] = "SoftStep_Expander";
    factoryPodMap["key2_modline1_ledgreen"] = "None";
    factoryPodMap["key2_modline1_ledred"] = "None";
    factoryPodMap["key2_modline1_displaylinked"] = 1;
    factoryPodMap["key2_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryPodMap["key2_modline2_enable"] = 1;
    factoryPodMap["key2_modline2_source"] = "Pressure_Live";
    factoryPodMap["key2_modline2_gain"] = 1.00;
    factoryPodMap["key2_modline2_offset"] = 0.00;
    factoryPodMap["key2_modline2_table"] = "1_Lin";
    factoryPodMap["key2_modline2_min"] = 0;
    factoryPodMap["key2_modline2_max"] = 127;
    factoryPodMap["key2_modline2_slew"] = 0;
    factoryPodMap["key2_modline2_destination"] = "CC";
    factoryPodMap["key2_modline2_note"] = 60;
    factoryPodMap["key2_modline2_velocity"] = 127;
    factoryPodMap["key2_modline2_cc"] = 29;
    factoryPodMap["key2_modline2_mmcid"] = 0;
    factoryPodMap["key2_modline2_mmcfunction"] = "Stop";
    factoryPodMap["key2_modline2_channel"] = 1;
    factoryPodMap["key2_modline2_device"] = "SSCOM_Port_1";
    factoryPodMap["key2_modline2_ledgreen"] = "None";
    factoryPodMap["key2_modline2_ledred"] = "None";
    factoryPodMap["key2_modline2_displaylinked"] = 0;
    factoryPodMap["key2_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryPodMap["key2_modline3_enable"] = 0;
    factoryPodMap["key2_modline3_source"] = "None";
    factoryPodMap["key2_modline3_gain"] = 0.00;
    factoryPodMap["key2_modline3_offset"] = 0.00;
    factoryPodMap["key2_modline3_table"] = "1_Lin";
    factoryPodMap["key2_modline3_min"] = 0;
    factoryPodMap["key2_modline3_max"] = 127;
    factoryPodMap["key2_modline3_slew"] = 0;
    factoryPodMap["key2_modline3_destination"] = "None";
    factoryPodMap["key2_modline3_note"] = 60;
    factoryPodMap["key2_modline3_velocity"] = 127;
    factoryPodMap["key2_modline3_cc"] = 1;
    factoryPodMap["key2_modline3_mmcid"] = 0;
    factoryPodMap["key2_modline3_mmcfunction"] = "Stop";
    factoryPodMap["key2_modline3_channel"] = 0;
    factoryPodMap["key2_modline3_device"] = "SSCOM_Port_1";
    factoryPodMap["key2_modline3_ledgreen"] = "None";
    factoryPodMap["key2_modline3_ledred"] = "None";
    factoryPodMap["key2_modline3_displaylinked"] = 0;
    factoryPodMap["key2_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryPodMap["key2_modline4_enable"] = 0;
    factoryPodMap["key2_modline4_source"] = "None";
    factoryPodMap["key2_modline4_gain"] = 0.00;
    factoryPodMap["key2_modline4_offset"] = 0.00;
    factoryPodMap["key2_modline4_table"] = "1_Lin";
    factoryPodMap["key2_modline4_min"] = 0;
    factoryPodMap["key2_modline4_max"] = 127;
    factoryPodMap["key2_modline4_slew"] = 0;
    factoryPodMap["key2_modline4_destination"] = "None";
    factoryPodMap["key2_modline4_note"] = 60;
    factoryPodMap["key2_modline4_velocity"] = 127;
    factoryPodMap["key2_modline4_cc"] = 1;
    factoryPodMap["key2_modline4_mmcid"] = 0;
    factoryPodMap["key2_modline4_mmcfunction"] = "Stop";
    factoryPodMap["key2_modline4_channel"] = 0;
    factoryPodMap["key2_modline4_device"] = "SSCOM_Port_1";
    factoryPodMap["key2_modline4_ledgreen"] = "None";
    factoryPodMap["key2_modline4_ledred"] = "None";
    factoryPodMap["key2_modline4_displaylinked"] = 0;
    factoryPodMap["key2_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryPodMap["key2_modline5_enable"] = 0;
    factoryPodMap["key2_modline5_source"] = "None";
    factoryPodMap["key2_modline5_gain"] = 0.00;
    factoryPodMap["key2_modline5_offset"] = 0.00;
    factoryPodMap["key2_modline5_table"] = "1_Lin";
    factoryPodMap["key2_modline5_min"] = 0;
    factoryPodMap["key2_modline5_max"] = 127;
    factoryPodMap["key2_modline5_slew"] = 0;
    factoryPodMap["key2_modline5_destination"] = "None";
    factoryPodMap["key2_modline5_note"] = 60;
    factoryPodMap["key2_modline5_velocity"] = 127;
    factoryPodMap["key2_modline5_cc"] = 1;
    factoryPodMap["key2_modline5_mmcid"] = 0;
    factoryPodMap["key2_modline5_mmcfunction"] = "Stop";
    factoryPodMap["key2_modline5_channel"] = 0;
    factoryPodMap["key2_modline5_device"] = "SSCOM_Port_1";
    factoryPodMap["key2_modline5_ledgreen"] = "None";
    factoryPodMap["key2_modline5_ledred"] = "None";
    factoryPodMap["key2_modline5_displaylinked"] = 0;
    factoryPodMap["key2_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryPodMap["key2_modline6_enable"] = 0;
    factoryPodMap["key2_modline6_source"] = "None";
    factoryPodMap["key2_modline6_gain"] = 0.00;
    factoryPodMap["key2_modline6_offset"] = 0.00;
    factoryPodMap["key2_modline6_table"] = "1_Lin";
    factoryPodMap["key2_modline6_min"] = 0;
    factoryPodMap["key2_modline6_max"] = 127;
    factoryPodMap["key2_modline6_slew"] = 0;
    factoryPodMap["key2_modline6_destination"] = "None";
    factoryPodMap["key2_modline6_note"] = 60;
    factoryPodMap["key2_modline6_velocity"] = 127;
    factoryPodMap["key2_modline6_cc"] = 1;
    factoryPodMap["key2_modline6_mmcid"] = 0;
    factoryPodMap["key2_modline6_mmcfunction"] = "Stop";
    factoryPodMap["key2_modline6_channel"] = 0;
    factoryPodMap["key2_modline6_device"] = "SSCOM_Port_1";
    factoryPodMap["key2_modline6_ledgreen"] = "None";
    factoryPodMap["key2_modline6_ledred"] = "None";
    factoryPodMap["key2_modline6_displaylinked"] = 0;
    factoryPodMap["key2_modline6_reminder"] = "";


    //------------------------ Key 3 ------------------------//
    factoryPodMap["key3_name"] = "DLYX";
    factoryPodMap["key3_displaymode"] = 4;
    factoryPodMap["key3_prefix"] = "";
    factoryPodMap["key3_counter_min"] = 0;
    factoryPodMap["key3_counter_max"] = 127;
    factoryPodMap["key3_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryPodMap["key3_modline1_enable"] = 1;
    factoryPodMap["key3_modline1_source"] = "Y_Increment";
    factoryPodMap["key3_modline1_gain"] = 0.40;
    factoryPodMap["key3_modline1_offset"] = 20.00;
    factoryPodMap["key3_modline1_table"] = "1_Lin";
    factoryPodMap["key3_modline1_min"] = 0;
    factoryPodMap["key3_modline1_max"] = 127;
    factoryPodMap["key3_modline1_slew"] = 0;
    factoryPodMap["key3_modline1_destination"] = "CC";
    factoryPodMap["key3_modline1_note"] = 60;
    factoryPodMap["key3_modline1_velocity"] = 127;
    factoryPodMap["key3_modline1_cc"] = 32;
    factoryPodMap["key3_modline1_mmcid"] = 0;
    factoryPodMap["key3_modline1_mmcfunction"] = "Stop";
    factoryPodMap["key3_modline1_channel"] = 1;
    factoryPodMap["key3_modline1_device"] = "SoftStep_Expander";
    factoryPodMap["key3_modline1_ledgreen"] = "None";
    factoryPodMap["key3_modline1_ledred"] = "None";
    factoryPodMap["key3_modline1_displaylinked"] = 1;
    factoryPodMap["key3_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryPodMap["key3_modline2_enable"] = 1;
    factoryPodMap["key3_modline2_source"] = "Y_Increment";
    factoryPodMap["key3_modline2_gain"] = 0.40;
    factoryPodMap["key3_modline2_offset"] = 20.00;
    factoryPodMap["key3_modline2_table"] = "1_Lin";
    factoryPodMap["key3_modline2_min"] = 0;
    factoryPodMap["key3_modline2_max"] = 127;
    factoryPodMap["key3_modline2_slew"] = 0;
    factoryPodMap["key3_modline2_destination"] = "CC";
    factoryPodMap["key3_modline2_note"] = 60;
    factoryPodMap["key3_modline2_velocity"] = 127;
    factoryPodMap["key3_modline2_cc"] = 32;
    factoryPodMap["key3_modline2_mmcid"] = 0;
    factoryPodMap["key3_modline2_mmcfunction"] = "Stop";
    factoryPodMap["key3_modline2_channel"] = 1;
    factoryPodMap["key3_modline2_device"] = "SSCOM_Port_1";
    factoryPodMap["key3_modline2_ledgreen"] = "None";
    factoryPodMap["key3_modline2_ledred"] = "None";
    factoryPodMap["key3_modline2_displaylinked"] = 0;
    factoryPodMap["key3_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryPodMap["key3_modline3_enable"] = 0;
    factoryPodMap["key3_modline3_source"] = "None";
    factoryPodMap["key3_modline3_gain"] = 0.00;
    factoryPodMap["key3_modline3_offset"] = 0.00;
    factoryPodMap["key3_modline3_table"] = "1_Lin";
    factoryPodMap["key3_modline3_min"] = 0;
    factoryPodMap["key3_modline3_max"] = 127;
    factoryPodMap["key3_modline3_slew"] = 0;
    factoryPodMap["key3_modline3_destination"] = "None";
    factoryPodMap["key3_modline3_note"] = 60;
    factoryPodMap["key3_modline3_velocity"] = 127;
    factoryPodMap["key3_modline3_cc"] = 1;
    factoryPodMap["key3_modline3_mmcid"] = 0;
    factoryPodMap["key3_modline3_mmcfunction"] = "Stop";
    factoryPodMap["key3_modline3_channel"] = 0;
    factoryPodMap["key3_modline3_device"] = "SSCOM_Port_1";
    factoryPodMap["key3_modline3_ledgreen"] = "None";
    factoryPodMap["key3_modline3_ledred"] = "None";
    factoryPodMap["key3_modline3_displaylinked"] = 0;
    factoryPodMap["key3_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryPodMap["key3_modline4_enable"] = 0;
    factoryPodMap["key3_modline4_source"] = "None";
    factoryPodMap["key3_modline4_gain"] = 0.00;
    factoryPodMap["key3_modline4_offset"] = 0.00;
    factoryPodMap["key3_modline4_table"] = "1_Lin";
    factoryPodMap["key3_modline4_min"] = 0;
    factoryPodMap["key3_modline4_max"] = 127;
    factoryPodMap["key3_modline4_slew"] = 0;
    factoryPodMap["key3_modline4_destination"] = "None";
    factoryPodMap["key3_modline4_note"] = 60;
    factoryPodMap["key3_modline4_velocity"] = 127;
    factoryPodMap["key3_modline4_cc"] = 1;
    factoryPodMap["key3_modline4_mmcid"] = 0;
    factoryPodMap["key3_modline4_mmcfunction"] = "Stop";
    factoryPodMap["key3_modline4_channel"] = 0;
    factoryPodMap["key3_modline4_device"] = "SSCOM_Port_1";
    factoryPodMap["key3_modline4_ledgreen"] = "None";
    factoryPodMap["key3_modline4_ledred"] = "None";
    factoryPodMap["key3_modline4_displaylinked"] = 0;
    factoryPodMap["key3_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryPodMap["key3_modline5_enable"] = 0;
    factoryPodMap["key3_modline5_source"] = "None";
    factoryPodMap["key3_modline5_gain"] = 0.00;
    factoryPodMap["key3_modline5_offset"] = 0.00;
    factoryPodMap["key3_modline5_table"] = "1_Lin";
    factoryPodMap["key3_modline5_min"] = 0;
    factoryPodMap["key3_modline5_max"] = 127;
    factoryPodMap["key3_modline5_slew"] = 0;
    factoryPodMap["key3_modline5_destination"] = "None";
    factoryPodMap["key3_modline5_note"] = 60;
    factoryPodMap["key3_modline5_velocity"] = 127;
    factoryPodMap["key3_modline5_cc"] = 1;
    factoryPodMap["key3_modline5_mmcid"] = 0;
    factoryPodMap["key3_modline5_mmcfunction"] = "Stop";
    factoryPodMap["key3_modline5_channel"] = 0;
    factoryPodMap["key3_modline5_device"] = "SSCOM_Port_1";
    factoryPodMap["key3_modline5_ledgreen"] = "None";
    factoryPodMap["key3_modline5_ledred"] = "None";
    factoryPodMap["key3_modline5_displaylinked"] = 0;
    factoryPodMap["key3_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryPodMap["key3_modline6_enable"] = 0;
    factoryPodMap["key3_modline6_source"] = "None";
    factoryPodMap["key3_modline6_gain"] = 0.00;
    factoryPodMap["key3_modline6_offset"] = 0.00;
    factoryPodMap["key3_modline6_table"] = "1_Lin";
    factoryPodMap["key3_modline6_min"] = 0;
    factoryPodMap["key3_modline6_max"] = 127;
    factoryPodMap["key3_modline6_slew"] = 0;
    factoryPodMap["key3_modline6_destination"] = "None";
    factoryPodMap["key3_modline6_note"] = 60;
    factoryPodMap["key3_modline6_velocity"] = 127;
    factoryPodMap["key3_modline6_cc"] = 1;
    factoryPodMap["key3_modline6_mmcid"] = 0;
    factoryPodMap["key3_modline6_mmcfunction"] = "Stop";
    factoryPodMap["key3_modline6_channel"] = 0;
    factoryPodMap["key3_modline6_device"] = "SSCOM_Port_1";
    factoryPodMap["key3_modline6_ledgreen"] = "None";
    factoryPodMap["key3_modline6_ledred"] = "None";
    factoryPodMap["key3_modline6_displaylinked"] = 0;
    factoryPodMap["key3_modline6_reminder"] = "";


    //------------------------ Key 4 ------------------------//
    factoryPodMap["key4_name"] = "TAP";
    factoryPodMap["key4_displaymode"] = 1;
    factoryPodMap["key4_prefix"] = "";
    factoryPodMap["key4_counter_min"] = 0;
    factoryPodMap["key4_counter_max"] = 127;
    factoryPodMap["key4_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryPodMap["key4_modline1_enable"] = 1;
    factoryPodMap["key4_modline1_source"] = "Foot_On";
    factoryPodMap["key4_modline1_gain"] = 1.00;
    factoryPodMap["key4_modline1_offset"] = 0.00;
    factoryPodMap["key4_modline1_table"] = "Toggle_127";
    factoryPodMap["key4_modline1_min"] = 0;
    factoryPodMap["key4_modline1_max"] = 127;
    factoryPodMap["key4_modline1_slew"] = 0;
    factoryPodMap["key4_modline1_destination"] = "CC";
    factoryPodMap["key4_modline1_note"] = 60;
    factoryPodMap["key4_modline1_velocity"] = 127;
    factoryPodMap["key4_modline1_cc"] = 33;
    factoryPodMap["key4_modline1_mmcid"] = 0;
    factoryPodMap["key4_modline1_mmcfunction"] = "Stop";
    factoryPodMap["key4_modline1_channel"] = 1;
    factoryPodMap["key4_modline1_device"] = "SoftStep_Expander";
    factoryPodMap["key4_modline1_ledgreen"] = "None";
    factoryPodMap["key4_modline1_ledred"] = "None";
    factoryPodMap["key4_modline1_displaylinked"] = 1;
    factoryPodMap["key4_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryPodMap["key4_modline2_enable"] = 1;
    factoryPodMap["key4_modline2_source"] = "Foot_On";
    factoryPodMap["key4_modline2_gain"] = 1.00;
    factoryPodMap["key4_modline2_offset"] = 0.00;
    factoryPodMap["key4_modline2_table"] = "Toggle_127";
    factoryPodMap["key4_modline2_min"] = 0;
    factoryPodMap["key4_modline2_max"] = 127;
    factoryPodMap["key4_modline2_slew"] = 0;
    factoryPodMap["key4_modline2_destination"] = "CC";
    factoryPodMap["key4_modline2_note"] = 60;
    factoryPodMap["key4_modline2_velocity"] = 127;
    factoryPodMap["key4_modline2_cc"] = 33;
    factoryPodMap["key4_modline2_mmcid"] = 0;
    factoryPodMap["key4_modline2_mmcfunction"] = "Stop";
    factoryPodMap["key4_modline2_channel"] = 1;
    factoryPodMap["key4_modline2_device"] = "SSCOM_Port_1";
    factoryPodMap["key4_modline2_ledgreen"] = "None";
    factoryPodMap["key4_modline2_ledred"] = "None";
    factoryPodMap["key4_modline2_displaylinked"] = 0;
    factoryPodMap["key4_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryPodMap["key4_modline3_enable"] = 0;
    factoryPodMap["key4_modline3_source"] = "None";
    factoryPodMap["key4_modline3_gain"] = 0.00;
    factoryPodMap["key4_modline3_offset"] = 0.00;
    factoryPodMap["key4_modline3_table"] = "1_Lin";
    factoryPodMap["key4_modline3_min"] = 0;
    factoryPodMap["key4_modline3_max"] = 127;
    factoryPodMap["key4_modline3_slew"] = 0;
    factoryPodMap["key4_modline3_destination"] = "None";
    factoryPodMap["key4_modline3_note"] = 60;
    factoryPodMap["key4_modline3_velocity"] = 127;
    factoryPodMap["key4_modline3_cc"] = 1;
    factoryPodMap["key4_modline3_mmcid"] = 0;
    factoryPodMap["key4_modline3_mmcfunction"] = "Stop";
    factoryPodMap["key4_modline3_channel"] = 0;
    factoryPodMap["key4_modline3_device"] = "SSCOM_Port_1";
    factoryPodMap["key4_modline3_ledgreen"] = "None";
    factoryPodMap["key4_modline3_ledred"] = "None";
    factoryPodMap["key4_modline3_displaylinked"] = 0;
    factoryPodMap["key4_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryPodMap["key4_modline4_enable"] = 0;
    factoryPodMap["key4_modline4_source"] = "None";
    factoryPodMap["key4_modline4_gain"] = 0.00;
    factoryPodMap["key4_modline4_offset"] = 0.00;
    factoryPodMap["key4_modline4_table"] = "1_Lin";
    factoryPodMap["key4_modline4_min"] = 0;
    factoryPodMap["key4_modline4_max"] = 127;
    factoryPodMap["key4_modline4_slew"] = 0;
    factoryPodMap["key4_modline4_destination"] = "None";
    factoryPodMap["key4_modline4_note"] = 60;
    factoryPodMap["key4_modline4_velocity"] = 127;
    factoryPodMap["key4_modline4_cc"] = 1;
    factoryPodMap["key4_modline4_mmcid"] = 0;
    factoryPodMap["key4_modline4_mmcfunction"] = "Stop";
    factoryPodMap["key4_modline4_channel"] = 0;
    factoryPodMap["key4_modline4_device"] = "SSCOM_Port_1";
    factoryPodMap["key4_modline4_ledgreen"] = "None";
    factoryPodMap["key4_modline4_ledred"] = "None";
    factoryPodMap["key4_modline4_displaylinked"] = 0;
    factoryPodMap["key4_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryPodMap["key4_modline5_enable"] = 0;
    factoryPodMap["key4_modline5_source"] = "None";
    factoryPodMap["key4_modline5_gain"] = 0.00;
    factoryPodMap["key4_modline5_offset"] = 0.00;
    factoryPodMap["key4_modline5_table"] = "1_Lin";
    factoryPodMap["key4_modline5_min"] = 0;
    factoryPodMap["key4_modline5_max"] = 127;
    factoryPodMap["key4_modline5_slew"] = 0;
    factoryPodMap["key4_modline5_destination"] = "None";
    factoryPodMap["key4_modline5_note"] = 60;
    factoryPodMap["key4_modline5_velocity"] = 127;
    factoryPodMap["key4_modline5_cc"] = 1;
    factoryPodMap["key4_modline5_mmcid"] = 0;
    factoryPodMap["key4_modline5_mmcfunction"] = "Stop";
    factoryPodMap["key4_modline5_channel"] = 0;
    factoryPodMap["key4_modline5_device"] = "SSCOM_Port_1";
    factoryPodMap["key4_modline5_ledgreen"] = "None";
    factoryPodMap["key4_modline5_ledred"] = "None";
    factoryPodMap["key4_modline5_displaylinked"] = 0;
    factoryPodMap["key4_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryPodMap["key4_modline6_enable"] = 0;
    factoryPodMap["key4_modline6_source"] = "None";
    factoryPodMap["key4_modline6_gain"] = 0.00;
    factoryPodMap["key4_modline6_offset"] = 0.00;
    factoryPodMap["key4_modline6_table"] = "1_Lin";
    factoryPodMap["key4_modline6_min"] = 0;
    factoryPodMap["key4_modline6_max"] = 127;
    factoryPodMap["key4_modline6_slew"] = 0;
    factoryPodMap["key4_modline6_destination"] = "None";
    factoryPodMap["key4_modline6_note"] = 60;
    factoryPodMap["key4_modline6_velocity"] = 127;
    factoryPodMap["key4_modline6_cc"] = 1;
    factoryPodMap["key4_modline6_mmcid"] = 0;
    factoryPodMap["key4_modline6_mmcfunction"] = "Stop";
    factoryPodMap["key4_modline6_channel"] = 0;
    factoryPodMap["key4_modline6_device"] = "SSCOM_Port_1";
    factoryPodMap["key4_modline6_ledgreen"] = "None";
    factoryPodMap["key4_modline6_ledred"] = "None";
    factoryPodMap["key4_modline6_displaylinked"] = 0;
    factoryPodMap["key4_modline6_reminder"] = "";


    //------------------------ Key 5 ------------------------//
    factoryPodMap["key5_name"] = "WAH";
    factoryPodMap["key5_displaymode"] = 4;
    factoryPodMap["key5_prefix"] = "";
    factoryPodMap["key5_counter_min"] = 0;
    factoryPodMap["key5_counter_max"] = 127;
    factoryPodMap["key5_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryPodMap["key5_modline1_enable"] = 1;
    factoryPodMap["key5_modline1_source"] = "Pressure_Live";
    factoryPodMap["key5_modline1_gain"] = 1.70;
    factoryPodMap["key5_modline1_offset"] = 0.00;
    factoryPodMap["key5_modline1_table"] = "1_Lin";
    factoryPodMap["key5_modline1_min"] = 20;
    factoryPodMap["key5_modline1_max"] = 127;
    factoryPodMap["key5_modline1_slew"] = 150;
    factoryPodMap["key5_modline1_destination"] = "CC";
    factoryPodMap["key5_modline1_note"] = 60;
    factoryPodMap["key5_modline1_velocity"] = 127;
    factoryPodMap["key5_modline1_cc"] = 4;
    factoryPodMap["key5_modline1_mmcid"] = 0;
    factoryPodMap["key5_modline1_mmcfunction"] = "Stop";
    factoryPodMap["key5_modline1_channel"] = 1;
    factoryPodMap["key5_modline1_device"] = "SoftStep_Expander";
    factoryPodMap["key5_modline1_ledgreen"] = "None";
    factoryPodMap["key5_modline1_ledred"] = "None";
    factoryPodMap["key5_modline1_displaylinked"] = 1;
    factoryPodMap["key5_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryPodMap["key5_modline2_enable"] = 1;
    factoryPodMap["key5_modline2_source"] = "Pressure_Live";
    factoryPodMap["key5_modline2_gain"] = 1.70;
    factoryPodMap["key5_modline2_offset"] = 0.00;
    factoryPodMap["key5_modline2_table"] = "1_Lin";
    factoryPodMap["key5_modline2_min"] = 20;
    factoryPodMap["key5_modline2_max"] = 127;
    factoryPodMap["key5_modline2_slew"] = 150;
    factoryPodMap["key5_modline2_destination"] = "CC";
    factoryPodMap["key5_modline2_note"] = 60;
    factoryPodMap["key5_modline2_velocity"] = 127;
    factoryPodMap["key5_modline2_cc"] = 4;
    factoryPodMap["key5_modline2_mmcid"] = 0;
    factoryPodMap["key5_modline2_mmcfunction"] = "Stop";
    factoryPodMap["key5_modline2_channel"] = 1;
    factoryPodMap["key5_modline2_device"] = "SSCOM_Port_1";
    factoryPodMap["key5_modline2_ledgreen"] = "None";
    factoryPodMap["key5_modline2_ledred"] = "None";
    factoryPodMap["key5_modline2_displaylinked"] = 0;
    factoryPodMap["key5_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryPodMap["key5_modline3_enable"] = 0;
    factoryPodMap["key5_modline3_source"] = "None";
    factoryPodMap["key5_modline3_gain"] = 0.00;
    factoryPodMap["key5_modline3_offset"] = 0.00;
    factoryPodMap["key5_modline3_table"] = "1_Lin";
    factoryPodMap["key5_modline3_min"] = 0;
    factoryPodMap["key5_modline3_max"] = 127;
    factoryPodMap["key5_modline3_slew"] = 0;
    factoryPodMap["key5_modline3_destination"] = "None";
    factoryPodMap["key5_modline3_note"] = 60;
    factoryPodMap["key5_modline3_velocity"] = 127;
    factoryPodMap["key5_modline3_cc"] = 1;
    factoryPodMap["key5_modline3_mmcid"] = 0;
    factoryPodMap["key5_modline3_mmcfunction"] = "Stop";
    factoryPodMap["key5_modline3_channel"] = 0;
    factoryPodMap["key5_modline3_device"] = "SSCOM_Port_1";
    factoryPodMap["key5_modline3_ledgreen"] = "None";
    factoryPodMap["key5_modline3_ledred"] = "None";
    factoryPodMap["key5_modline3_displaylinked"] = 0;
    factoryPodMap["key5_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryPodMap["key5_modline4_enable"] = 0;
    factoryPodMap["key5_modline4_source"] = "None";
    factoryPodMap["key5_modline4_gain"] = 0.00;
    factoryPodMap["key5_modline4_offset"] = 0.00;
    factoryPodMap["key5_modline4_table"] = "1_Lin";
    factoryPodMap["key5_modline4_min"] = 0;
    factoryPodMap["key5_modline4_max"] = 127;
    factoryPodMap["key5_modline4_slew"] = 0;
    factoryPodMap["key5_modline4_destination"] = "None";
    factoryPodMap["key5_modline4_note"] = 60;
    factoryPodMap["key5_modline4_velocity"] = 127;
    factoryPodMap["key5_modline4_cc"] = 1;
    factoryPodMap["key5_modline4_mmcid"] = 0;
    factoryPodMap["key5_modline4_mmcfunction"] = "Stop";
    factoryPodMap["key5_modline4_channel"] = 0;
    factoryPodMap["key5_modline4_device"] = "SSCOM_Port_1";
    factoryPodMap["key5_modline4_ledgreen"] = "None";
    factoryPodMap["key5_modline4_ledred"] = "None";
    factoryPodMap["key5_modline4_displaylinked"] = 0;
    factoryPodMap["key5_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryPodMap["key5_modline5_enable"] = 0;
    factoryPodMap["key5_modline5_source"] = "None";
    factoryPodMap["key5_modline5_gain"] = 0.00;
    factoryPodMap["key5_modline5_offset"] = 0.00;
    factoryPodMap["key5_modline5_table"] = "1_Lin";
    factoryPodMap["key5_modline5_min"] = 0;
    factoryPodMap["key5_modline5_max"] = 127;
    factoryPodMap["key5_modline5_slew"] = 0;
    factoryPodMap["key5_modline5_destination"] = "None";
    factoryPodMap["key5_modline5_note"] = 60;
    factoryPodMap["key5_modline5_velocity"] = 127;
    factoryPodMap["key5_modline5_cc"] = 1;
    factoryPodMap["key5_modline5_mmcid"] = 0;
    factoryPodMap["key5_modline5_mmcfunction"] = "Stop";
    factoryPodMap["key5_modline5_channel"] = 0;
    factoryPodMap["key5_modline5_device"] = "SSCOM_Port_1";
    factoryPodMap["key5_modline5_ledgreen"] = "None";
    factoryPodMap["key5_modline5_ledred"] = "None";
    factoryPodMap["key5_modline5_displaylinked"] = 0;
    factoryPodMap["key5_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryPodMap["key5_modline6_enable"] = 0;
    factoryPodMap["key5_modline6_source"] = "None";
    factoryPodMap["key5_modline6_gain"] = 0.00;
    factoryPodMap["key5_modline6_offset"] = 0.00;
    factoryPodMap["key5_modline6_table"] = "1_Lin";
    factoryPodMap["key5_modline6_min"] = 0;
    factoryPodMap["key5_modline6_max"] = 127;
    factoryPodMap["key5_modline6_slew"] = 0;
    factoryPodMap["key5_modline6_destination"] = "None";
    factoryPodMap["key5_modline6_note"] = 60;
    factoryPodMap["key5_modline6_velocity"] = 127;
    factoryPodMap["key5_modline6_cc"] = 1;
    factoryPodMap["key5_modline6_mmcid"] = 0;
    factoryPodMap["key5_modline6_mmcfunction"] = "Stop";
    factoryPodMap["key5_modline6_channel"] = 0;
    factoryPodMap["key5_modline6_device"] = "SSCOM_Port_1";
    factoryPodMap["key5_modline6_ledgreen"] = "None";
    factoryPodMap["key5_modline6_ledred"] = "None";
    factoryPodMap["key5_modline6_displaylinked"] = 0;
    factoryPodMap["key5_modline6_reminder"] = "";


    //------------------------ Key 6 ------------------------//
    factoryPodMap["key6_name"] = "STMP";
    factoryPodMap["key6_displaymode"] = 1;
    factoryPodMap["key6_prefix"] = "";
    factoryPodMap["key6_counter_min"] = 0;
    factoryPodMap["key6_counter_max"] = 127;
    factoryPodMap["key6_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryPodMap["key6_modline1_enable"] = 1;
    factoryPodMap["key6_modline1_source"] = "Foot_On";
    factoryPodMap["key6_modline1_gain"] = 1.00;
    factoryPodMap["key6_modline1_offset"] = 0.00;
    factoryPodMap["key6_modline1_table"] = "Toggle_127";
    factoryPodMap["key6_modline1_min"] = 0;
    factoryPodMap["key6_modline1_max"] = 127;
    factoryPodMap["key6_modline1_slew"] = 0;
    factoryPodMap["key6_modline1_destination"] = "CC";
    factoryPodMap["key6_modline1_note"] = 60;
    factoryPodMap["key6_modline1_velocity"] = 127;
    factoryPodMap["key6_modline1_cc"] = 25;
    factoryPodMap["key6_modline1_mmcid"] = 0;
    factoryPodMap["key6_modline1_mmcfunction"] = "Stop";
    factoryPodMap["key6_modline1_channel"] = 1;
    factoryPodMap["key6_modline1_device"] = "SoftStep_Expander";
    factoryPodMap["key6_modline1_ledgreen"] = "True";
    factoryPodMap["key6_modline1_ledred"] = "None";
    factoryPodMap["key6_modline1_displaylinked"] = 1;
    factoryPodMap["key6_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryPodMap["key6_modline2_enable"] = 1;
    factoryPodMap["key6_modline2_source"] = "Foot_On";
    factoryPodMap["key6_modline2_gain"] = 1.00;
    factoryPodMap["key6_modline2_offset"] = 0.00;
    factoryPodMap["key6_modline2_table"] = "Toggle_127";
    factoryPodMap["key6_modline2_min"] = 0;
    factoryPodMap["key6_modline2_max"] = 127;
    factoryPodMap["key6_modline2_slew"] = 0;
    factoryPodMap["key6_modline2_destination"] = "CC";
    factoryPodMap["key6_modline2_note"] = 60;
    factoryPodMap["key6_modline2_velocity"] = 127;
    factoryPodMap["key6_modline2_cc"] = 25;
    factoryPodMap["key6_modline2_mmcid"] = 0;
    factoryPodMap["key6_modline2_mmcfunction"] = "Stop";
    factoryPodMap["key6_modline2_channel"] = 1;
    factoryPodMap["key6_modline2_device"] = "SSCOM_Port_1";
    factoryPodMap["key6_modline2_ledgreen"] = "None";
    factoryPodMap["key6_modline2_ledred"] = "None";
    factoryPodMap["key6_modline2_displaylinked"] = 0;
    factoryPodMap["key6_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryPodMap["key6_modline3_enable"] = 0;
    factoryPodMap["key6_modline3_source"] = "None";
    factoryPodMap["key6_modline3_gain"] = 0.00;
    factoryPodMap["key6_modline3_offset"] = 0.00;
    factoryPodMap["key6_modline3_table"] = "1_Lin";
    factoryPodMap["key6_modline3_min"] = 0;
    factoryPodMap["key6_modline3_max"] = 127;
    factoryPodMap["key6_modline3_slew"] = 0;
    factoryPodMap["key6_modline3_destination"] = "None";
    factoryPodMap["key6_modline3_note"] = 60;
    factoryPodMap["key6_modline3_velocity"] = 127;
    factoryPodMap["key6_modline3_cc"] = 1;
    factoryPodMap["key6_modline3_mmcid"] = 0;
    factoryPodMap["key6_modline3_mmcfunction"] = "Stop";
    factoryPodMap["key6_modline3_channel"] = 0;
    factoryPodMap["key6_modline3_device"] = "SSCOM_Port_1";
    factoryPodMap["key6_modline3_ledgreen"] = "None";
    factoryPodMap["key6_modline3_ledred"] = "None";
    factoryPodMap["key6_modline3_displaylinked"] = 0;
    factoryPodMap["key6_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryPodMap["key6_modline4_enable"] = 0;
    factoryPodMap["key6_modline4_source"] = "None";
    factoryPodMap["key6_modline4_gain"] = 0.00;
    factoryPodMap["key6_modline4_offset"] = 0.00;
    factoryPodMap["key6_modline4_table"] = "1_Lin";
    factoryPodMap["key6_modline4_min"] = 0;
    factoryPodMap["key6_modline4_max"] = 127;
    factoryPodMap["key6_modline4_slew"] = 0;
    factoryPodMap["key6_modline4_destination"] = "None";
    factoryPodMap["key6_modline4_note"] = 60;
    factoryPodMap["key6_modline4_velocity"] = 127;
    factoryPodMap["key6_modline4_cc"] = 1;
    factoryPodMap["key6_modline4_mmcid"] = 0;
    factoryPodMap["key6_modline4_mmcfunction"] = "Stop";
    factoryPodMap["key6_modline4_channel"] = 0;
    factoryPodMap["key6_modline4_device"] = "SSCOM_Port_1";
    factoryPodMap["key6_modline4_ledgreen"] = "None";
    factoryPodMap["key6_modline4_ledred"] = "None";
    factoryPodMap["key6_modline4_displaylinked"] = 0;
    factoryPodMap["key6_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryPodMap["key6_modline5_enable"] = 0;
    factoryPodMap["key6_modline5_source"] = "None";
    factoryPodMap["key6_modline5_gain"] = 0.00;
    factoryPodMap["key6_modline5_offset"] = 0.00;
    factoryPodMap["key6_modline5_table"] = "1_Lin";
    factoryPodMap["key6_modline5_min"] = 0;
    factoryPodMap["key6_modline5_max"] = 127;
    factoryPodMap["key6_modline5_slew"] = 0;
    factoryPodMap["key6_modline5_destination"] = "None";
    factoryPodMap["key6_modline5_note"] = 60;
    factoryPodMap["key6_modline5_velocity"] = 127;
    factoryPodMap["key6_modline5_cc"] = 1;
    factoryPodMap["key6_modline5_mmcid"] = 0;
    factoryPodMap["key6_modline5_mmcfunction"] = "Stop";
    factoryPodMap["key6_modline5_channel"] = 0;
    factoryPodMap["key6_modline5_device"] = "SSCOM_Port_1";
    factoryPodMap["key6_modline5_ledgreen"] = "None";
    factoryPodMap["key6_modline5_ledred"] = "None";
    factoryPodMap["key6_modline5_displaylinked"] = 0;
    factoryPodMap["key6_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryPodMap["key6_modline6_enable"] = 0;
    factoryPodMap["key6_modline6_source"] = "None";
    factoryPodMap["key6_modline6_gain"] = 0.00;
    factoryPodMap["key6_modline6_offset"] = 0.00;
    factoryPodMap["key6_modline6_table"] = "1_Lin";
    factoryPodMap["key6_modline6_min"] = 0;
    factoryPodMap["key6_modline6_max"] = 127;
    factoryPodMap["key6_modline6_slew"] = 0;
    factoryPodMap["key6_modline6_destination"] = "None";
    factoryPodMap["key6_modline6_note"] = 60;
    factoryPodMap["key6_modline6_velocity"] = 127;
    factoryPodMap["key6_modline6_cc"] = 1;
    factoryPodMap["key6_modline6_mmcid"] = 0;
    factoryPodMap["key6_modline6_mmcfunction"] = "Stop";
    factoryPodMap["key6_modline6_channel"] = 0;
    factoryPodMap["key6_modline6_device"] = "SSCOM_Port_1";
    factoryPodMap["key6_modline6_ledgreen"] = "None";
    factoryPodMap["key6_modline6_ledred"] = "None";
    factoryPodMap["key6_modline6_displaylinked"] = 0;
    factoryPodMap["key6_modline6_reminder"] = "";


    //------------------------ Key 7 ------------------------//
    factoryPodMap["key7_name"] = "MOD";
    factoryPodMap["key7_displaymode"] = 1;
    factoryPodMap["key7_prefix"] = "P";
    factoryPodMap["key7_counter_min"] = 0;
    factoryPodMap["key7_counter_max"] = 127;
    factoryPodMap["key7_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryPodMap["key7_modline1_enable"] = 1;
    factoryPodMap["key7_modline1_source"] = "Foot_On";
    factoryPodMap["key7_modline1_gain"] = 1.00;
    factoryPodMap["key7_modline1_offset"] = 0.00;
    factoryPodMap["key7_modline1_table"] = "Toggle_127";
    factoryPodMap["key7_modline1_min"] = 0;
    factoryPodMap["key7_modline1_max"] = 127;
    factoryPodMap["key7_modline1_slew"] = 0;
    factoryPodMap["key7_modline1_destination"] = "CC";
    factoryPodMap["key7_modline1_note"] = 60;
    factoryPodMap["key7_modline1_velocity"] = 127;
    factoryPodMap["key7_modline1_cc"] = 50;
    factoryPodMap["key7_modline1_mmcid"] = 0;
    factoryPodMap["key7_modline1_mmcfunction"] = "Stop";
    factoryPodMap["key7_modline1_channel"] = 1;
    factoryPodMap["key7_modline1_device"] = "SoftStep_Expander";
    factoryPodMap["key7_modline1_ledgreen"] = "True";
    factoryPodMap["key7_modline1_ledred"] = "None";
    factoryPodMap["key7_modline1_displaylinked"] = 1;
    factoryPodMap["key7_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryPodMap["key7_modline2_enable"] = 1;
    factoryPodMap["key7_modline2_source"] = "Foot_On";
    factoryPodMap["key7_modline2_gain"] = 1.00;
    factoryPodMap["key7_modline2_offset"] = 0.00;
    factoryPodMap["key7_modline2_table"] = "Toggle_127";
    factoryPodMap["key7_modline2_min"] = 0;
    factoryPodMap["key7_modline2_max"] = 127;
    factoryPodMap["key7_modline2_slew"] = 0;
    factoryPodMap["key7_modline2_destination"] = "CC";
    factoryPodMap["key7_modline2_note"] = 60;
    factoryPodMap["key7_modline2_velocity"] = 127;
    factoryPodMap["key7_modline2_cc"] = 50;
    factoryPodMap["key7_modline2_mmcid"] = 0;
    factoryPodMap["key7_modline2_mmcfunction"] = "Stop";
    factoryPodMap["key7_modline2_channel"] = 1;
    factoryPodMap["key7_modline2_device"] = "SSCOM_Port_1";
    factoryPodMap["key7_modline2_ledgreen"] = "None";
    factoryPodMap["key7_modline2_ledred"] = "None";
    factoryPodMap["key7_modline2_displaylinked"] = 0;
    factoryPodMap["key7_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryPodMap["key7_modline3_enable"] = 0;
    factoryPodMap["key7_modline3_source"] = "None";
    factoryPodMap["key7_modline3_gain"] = 0.00;
    factoryPodMap["key7_modline3_offset"] = 0.00;
    factoryPodMap["key7_modline3_table"] = "1_Lin";
    factoryPodMap["key7_modline3_min"] = 0;
    factoryPodMap["key7_modline3_max"] = 127;
    factoryPodMap["key7_modline3_slew"] = 0;
    factoryPodMap["key7_modline3_destination"] = "None";
    factoryPodMap["key7_modline3_note"] = 60;
    factoryPodMap["key7_modline3_velocity"] = 127;
    factoryPodMap["key7_modline3_cc"] = 1;
    factoryPodMap["key7_modline3_mmcid"] = 0;
    factoryPodMap["key7_modline3_mmcfunction"] = "Stop";
    factoryPodMap["key7_modline3_channel"] = 0;
    factoryPodMap["key7_modline3_device"] = "SSCOM_Port_1";
    factoryPodMap["key7_modline3_ledgreen"] = "None";
    factoryPodMap["key7_modline3_ledred"] = "None";
    factoryPodMap["key7_modline3_displaylinked"] = 0;
    factoryPodMap["key7_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryPodMap["key7_modline4_enable"] = 0;
    factoryPodMap["key7_modline4_source"] = "None";
    factoryPodMap["key7_modline4_gain"] = 0.00;
    factoryPodMap["key7_modline4_offset"] = 0.00;
    factoryPodMap["key7_modline4_table"] = "1_Lin";
    factoryPodMap["key7_modline4_min"] = 0;
    factoryPodMap["key7_modline4_max"] = 127;
    factoryPodMap["key7_modline4_slew"] = 0;
    factoryPodMap["key7_modline4_destination"] = "None";
    factoryPodMap["key7_modline4_note"] = 60;
    factoryPodMap["key7_modline4_velocity"] = 127;
    factoryPodMap["key7_modline4_cc"] = 1;
    factoryPodMap["key7_modline4_mmcid"] = 0;
    factoryPodMap["key7_modline4_mmcfunction"] = "Stop";
    factoryPodMap["key7_modline4_channel"] = 0;
    factoryPodMap["key7_modline4_device"] = "SSCOM_Port_1";
    factoryPodMap["key7_modline4_ledgreen"] = "None";
    factoryPodMap["key7_modline4_ledred"] = "None";
    factoryPodMap["key7_modline4_displaylinked"] = 0;
    factoryPodMap["key7_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryPodMap["key7_modline5_enable"] = 0;
    factoryPodMap["key7_modline5_source"] = "None";
    factoryPodMap["key7_modline5_gain"] = 0.00;
    factoryPodMap["key7_modline5_offset"] = 0.00;
    factoryPodMap["key7_modline5_table"] = "1_Lin";
    factoryPodMap["key7_modline5_min"] = 0;
    factoryPodMap["key7_modline5_max"] = 127;
    factoryPodMap["key7_modline5_slew"] = 0;
    factoryPodMap["key7_modline5_destination"] = "None";
    factoryPodMap["key7_modline5_note"] = 60;
    factoryPodMap["key7_modline5_velocity"] = 127;
    factoryPodMap["key7_modline5_cc"] = 1;
    factoryPodMap["key7_modline5_mmcid"] = 0;
    factoryPodMap["key7_modline5_mmcfunction"] = "Stop";
    factoryPodMap["key7_modline5_channel"] = 0;
    factoryPodMap["key7_modline5_device"] = "SSCOM_Port_1";
    factoryPodMap["key7_modline5_ledgreen"] = "None";
    factoryPodMap["key7_modline5_ledred"] = "None";
    factoryPodMap["key7_modline5_displaylinked"] = 0;
    factoryPodMap["key7_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryPodMap["key7_modline6_enable"] = 0;
    factoryPodMap["key7_modline6_source"] = "None";
    factoryPodMap["key7_modline6_gain"] = 0.00;
    factoryPodMap["key7_modline6_offset"] = 0.00;
    factoryPodMap["key7_modline6_table"] = "1_Lin";
    factoryPodMap["key7_modline6_min"] = 0;
    factoryPodMap["key7_modline6_max"] = 127;
    factoryPodMap["key7_modline6_slew"] = 0;
    factoryPodMap["key7_modline6_destination"] = "None";
    factoryPodMap["key7_modline6_note"] = 60;
    factoryPodMap["key7_modline6_velocity"] = 127;
    factoryPodMap["key7_modline6_cc"] = 1;
    factoryPodMap["key7_modline6_mmcid"] = 0;
    factoryPodMap["key7_modline6_mmcfunction"] = "Stop";
    factoryPodMap["key7_modline6_channel"] = 0;
    factoryPodMap["key7_modline6_device"] = "SSCOM_Port_1";
    factoryPodMap["key7_modline6_ledgreen"] = "None";
    factoryPodMap["key7_modline6_ledred"] = "None";
    factoryPodMap["key7_modline6_displaylinked"] = 0;
    factoryPodMap["key7_modline6_reminder"] = "";


    //------------------------ Key 8 ------------------------//
    factoryPodMap["key8_name"] = "DLY";
    factoryPodMap["key8_displaymode"] = 1;
    factoryPodMap["key8_prefix"] = "";
    factoryPodMap["key8_counter_min"] = 0;
    factoryPodMap["key8_counter_max"] = 127;
    factoryPodMap["key8_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryPodMap["key8_modline1_enable"] = 1;
    factoryPodMap["key8_modline1_source"] = "Foot_On";
    factoryPodMap["key8_modline1_gain"] = 1.00;
    factoryPodMap["key8_modline1_offset"] = 0.00;
    factoryPodMap["key8_modline1_table"] = "Toggle_127";
    factoryPodMap["key8_modline1_min"] = 0;
    factoryPodMap["key8_modline1_max"] = 127;
    factoryPodMap["key8_modline1_slew"] = 0;
    factoryPodMap["key8_modline1_destination"] = "CC";
    factoryPodMap["key8_modline1_note"] = 60;
    factoryPodMap["key8_modline1_velocity"] = 127;
    factoryPodMap["key8_modline1_cc"] = 28;
    factoryPodMap["key8_modline1_mmcid"] = 0;
    factoryPodMap["key8_modline1_mmcfunction"] = "Stop";
    factoryPodMap["key8_modline1_channel"] = 1;
    factoryPodMap["key8_modline1_device"] = "SoftStep_Expander";
    factoryPodMap["key8_modline1_ledgreen"] = "True";
    factoryPodMap["key8_modline1_ledred"] = "None";
    factoryPodMap["key8_modline1_displaylinked"] = 1;
    factoryPodMap["key8_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryPodMap["key8_modline2_enable"] = 1;
    factoryPodMap["key8_modline2_source"] = "Foot_On";
    factoryPodMap["key8_modline2_gain"] = 1.00;
    factoryPodMap["key8_modline2_offset"] = 0.00;
    factoryPodMap["key8_modline2_table"] = "Toggle_127";
    factoryPodMap["key8_modline2_min"] = 0;
    factoryPodMap["key8_modline2_max"] = 127;
    factoryPodMap["key8_modline2_slew"] = 0;
    factoryPodMap["key8_modline2_destination"] = "CC";
    factoryPodMap["key8_modline2_note"] = 60;
    factoryPodMap["key8_modline2_velocity"] = 127;
    factoryPodMap["key8_modline2_cc"] = 28;
    factoryPodMap["key8_modline2_mmcid"] = 0;
    factoryPodMap["key8_modline2_mmcfunction"] = "Stop";
    factoryPodMap["key8_modline2_channel"] = 1;
    factoryPodMap["key8_modline2_device"] = "SSCOM_Port_1";
    factoryPodMap["key8_modline2_ledgreen"] = "None";
    factoryPodMap["key8_modline2_ledred"] = "None";
    factoryPodMap["key8_modline2_displaylinked"] = 0;
    factoryPodMap["key8_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryPodMap["key8_modline3_enable"] = 0;
    factoryPodMap["key8_modline3_source"] = "None";
    factoryPodMap["key8_modline3_gain"] = 0.00;
    factoryPodMap["key8_modline3_offset"] = 0.00;
    factoryPodMap["key8_modline3_table"] = "1_Lin";
    factoryPodMap["key8_modline3_min"] = 0;
    factoryPodMap["key8_modline3_max"] = 127;
    factoryPodMap["key8_modline3_slew"] = 0;
    factoryPodMap["key8_modline3_destination"] = "None";
    factoryPodMap["key8_modline3_note"] = 60;
    factoryPodMap["key8_modline3_velocity"] = 127;
    factoryPodMap["key8_modline3_cc"] = 1;
    factoryPodMap["key8_modline3_mmcid"] = 0;
    factoryPodMap["key8_modline3_mmcfunction"] = "Stop";
    factoryPodMap["key8_modline3_channel"] = 0;
    factoryPodMap["key8_modline3_device"] = "SSCOM_Port_1";
    factoryPodMap["key8_modline3_ledgreen"] = "None";
    factoryPodMap["key8_modline3_ledred"] = "None";
    factoryPodMap["key8_modline3_displaylinked"] = 0;
    factoryPodMap["key8_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryPodMap["key8_modline4_enable"] = 0;
    factoryPodMap["key8_modline4_source"] = "None";
    factoryPodMap["key8_modline4_gain"] = 0.00;
    factoryPodMap["key8_modline4_offset"] = 0.00;
    factoryPodMap["key8_modline4_table"] = "1_Lin";
    factoryPodMap["key8_modline4_min"] = 0;
    factoryPodMap["key8_modline4_max"] = 127;
    factoryPodMap["key8_modline4_slew"] = 0;
    factoryPodMap["key8_modline4_destination"] = "None";
    factoryPodMap["key8_modline4_note"] = 60;
    factoryPodMap["key8_modline4_velocity"] = 127;
    factoryPodMap["key8_modline4_cc"] = 1;
    factoryPodMap["key8_modline4_mmcid"] = 0;
    factoryPodMap["key8_modline4_mmcfunction"] = "Stop";
    factoryPodMap["key8_modline4_channel"] = 0;
    factoryPodMap["key8_modline4_device"] = "SSCOM_Port_1";
    factoryPodMap["key8_modline4_ledgreen"] = "None";
    factoryPodMap["key8_modline4_ledred"] = "None";
    factoryPodMap["key8_modline4_displaylinked"] = 0;
    factoryPodMap["key8_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryPodMap["key8_modline5_enable"] = 0;
    factoryPodMap["key8_modline5_source"] = "None";
    factoryPodMap["key8_modline5_gain"] = 0.00;
    factoryPodMap["key8_modline5_offset"] = 0.00;
    factoryPodMap["key8_modline5_table"] = "1_Lin";
    factoryPodMap["key8_modline5_min"] = 0;
    factoryPodMap["key8_modline5_max"] = 127;
    factoryPodMap["key8_modline5_slew"] = 0;
    factoryPodMap["key8_modline5_destination"] = "None";
    factoryPodMap["key8_modline5_note"] = 60;
    factoryPodMap["key8_modline5_velocity"] = 127;
    factoryPodMap["key8_modline5_cc"] = 1;
    factoryPodMap["key8_modline5_mmcid"] = 0;
    factoryPodMap["key8_modline5_mmcfunction"] = "Stop";
    factoryPodMap["key8_modline5_channel"] = 0;
    factoryPodMap["key8_modline5_device"] = "SSCOM_Port_1";
    factoryPodMap["key8_modline5_ledgreen"] = "None";
    factoryPodMap["key8_modline5_ledred"] = "None";
    factoryPodMap["key8_modline5_displaylinked"] = 0;
    factoryPodMap["key8_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryPodMap["key8_modline6_enable"] = 0;
    factoryPodMap["key8_modline6_source"] = "None";
    factoryPodMap["key8_modline6_gain"] = 0.00;
    factoryPodMap["key8_modline6_offset"] = 0.00;
    factoryPodMap["key8_modline6_table"] = "1_Lin";
    factoryPodMap["key8_modline6_min"] = 0;
    factoryPodMap["key8_modline6_max"] = 127;
    factoryPodMap["key8_modline6_slew"] = 0;
    factoryPodMap["key8_modline6_destination"] = "None";
    factoryPodMap["key8_modline6_note"] = 60;
    factoryPodMap["key8_modline6_velocity"] = 127;
    factoryPodMap["key8_modline6_cc"] = 1;
    factoryPodMap["key8_modline6_mmcid"] = 0;
    factoryPodMap["key8_modline6_mmcfunction"] = "Stop";
    factoryPodMap["key8_modline6_channel"] = 0;
    factoryPodMap["key8_modline6_device"] = "SSCOM_Port_1";
    factoryPodMap["key8_modline6_ledgreen"] = "None";
    factoryPodMap["key8_modline6_ledred"] = "None";
    factoryPodMap["key8_modline6_displaylinked"] = 0;
    factoryPodMap["key8_modline6_reminder"] = "";


    //------------------------ Key 9 ------------------------//
    factoryPodMap["key9_name"] = "REVB";
    factoryPodMap["key9_displaymode"] = 1;
    factoryPodMap["key9_prefix"] = "";
    factoryPodMap["key9_counter_min"] = 0;
    factoryPodMap["key9_counter_max"] = 127;
    factoryPodMap["key9_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryPodMap["key9_modline1_enable"] = 1;
    factoryPodMap["key9_modline1_source"] = "Foot_On";
    factoryPodMap["key9_modline1_gain"] = 1.00;
    factoryPodMap["key9_modline1_offset"] = 0.00;
    factoryPodMap["key9_modline1_table"] = "Toggle_127";
    factoryPodMap["key9_modline1_min"] = 0;
    factoryPodMap["key9_modline1_max"] = 127;
    factoryPodMap["key9_modline1_slew"] = 0;
    factoryPodMap["key9_modline1_destination"] = "CC";
    factoryPodMap["key9_modline1_note"] = 60;
    factoryPodMap["key9_modline1_velocity"] = 127;
    factoryPodMap["key9_modline1_cc"] = 36;
    factoryPodMap["key9_modline1_mmcid"] = 0;
    factoryPodMap["key9_modline1_mmcfunction"] = "Stop";
    factoryPodMap["key9_modline1_channel"] = 1;
    factoryPodMap["key9_modline1_device"] = "SoftStep_Expander";
    factoryPodMap["key9_modline1_ledgreen"] = "True";
    factoryPodMap["key9_modline1_ledred"] = "None";
    factoryPodMap["key9_modline1_displaylinked"] = 1;
    factoryPodMap["key9_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryPodMap["key9_modline2_enable"] = 1;
    factoryPodMap["key9_modline2_source"] = "Foot_On";
    factoryPodMap["key9_modline2_gain"] = 1.00;
    factoryPodMap["key9_modline2_offset"] = 0.00;
    factoryPodMap["key9_modline2_table"] = "Toggle_127";
    factoryPodMap["key9_modline2_min"] = 0;
    factoryPodMap["key9_modline2_max"] = 127;
    factoryPodMap["key9_modline2_slew"] = 0;
    factoryPodMap["key9_modline2_destination"] = "CC";
    factoryPodMap["key9_modline2_note"] = 60;
    factoryPodMap["key9_modline2_velocity"] = 127;
    factoryPodMap["key9_modline2_cc"] = 36;
    factoryPodMap["key9_modline2_mmcid"] = 0;
    factoryPodMap["key9_modline2_mmcfunction"] = "Stop";
    factoryPodMap["key9_modline2_channel"] = 1;
    factoryPodMap["key9_modline2_device"] = "SSCOM_Port_1";
    factoryPodMap["key9_modline2_ledgreen"] = "None";
    factoryPodMap["key9_modline2_ledred"] = "None";
    factoryPodMap["key9_modline2_displaylinked"] = 0;
    factoryPodMap["key9_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryPodMap["key9_modline3_enable"] = 0;
    factoryPodMap["key9_modline3_source"] = "None";
    factoryPodMap["key9_modline3_gain"] = 0.00;
    factoryPodMap["key9_modline3_offset"] = 0.00;
    factoryPodMap["key9_modline3_table"] = "1_Lin";
    factoryPodMap["key9_modline3_min"] = 0;
    factoryPodMap["key9_modline3_max"] = 127;
    factoryPodMap["key9_modline3_slew"] = 0;
    factoryPodMap["key9_modline3_destination"] = "None";
    factoryPodMap["key9_modline3_note"] = 60;
    factoryPodMap["key9_modline3_velocity"] = 127;
    factoryPodMap["key9_modline3_cc"] = 1;
    factoryPodMap["key9_modline3_mmcid"] = 0;
    factoryPodMap["key9_modline3_mmcfunction"] = "Stop";
    factoryPodMap["key9_modline3_channel"] = 0;
    factoryPodMap["key9_modline3_device"] = "SSCOM_Port_1";
    factoryPodMap["key9_modline3_ledgreen"] = "None";
    factoryPodMap["key9_modline3_ledred"] = "None";
    factoryPodMap["key9_modline3_displaylinked"] = 0;
    factoryPodMap["key9_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryPodMap["key9_modline4_enable"] = 0;
    factoryPodMap["key9_modline4_source"] = "None";
    factoryPodMap["key9_modline4_gain"] = 0.00;
    factoryPodMap["key9_modline4_offset"] = 0.00;
    factoryPodMap["key9_modline4_table"] = "1_Lin";
    factoryPodMap["key9_modline4_min"] = 0;
    factoryPodMap["key9_modline4_max"] = 127;
    factoryPodMap["key9_modline4_slew"] = 0;
    factoryPodMap["key9_modline4_destination"] = "None";
    factoryPodMap["key9_modline4_note"] = 60;
    factoryPodMap["key9_modline4_velocity"] = 127;
    factoryPodMap["key9_modline4_cc"] = 1;
    factoryPodMap["key9_modline4_mmcid"] = 0;
    factoryPodMap["key9_modline4_mmcfunction"] = "Stop";
    factoryPodMap["key9_modline4_channel"] = 0;
    factoryPodMap["key9_modline4_device"] = "SSCOM_Port_1";
    factoryPodMap["key9_modline4_ledgreen"] = "None";
    factoryPodMap["key9_modline4_ledred"] = "None";
    factoryPodMap["key9_modline4_displaylinked"] = 0;
    factoryPodMap["key9_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryPodMap["key9_modline5_enable"] = 0;
    factoryPodMap["key9_modline5_source"] = "None";
    factoryPodMap["key9_modline5_gain"] = 0.00;
    factoryPodMap["key9_modline5_offset"] = 0.00;
    factoryPodMap["key9_modline5_table"] = "1_Lin";
    factoryPodMap["key9_modline5_min"] = 0;
    factoryPodMap["key9_modline5_max"] = 127;
    factoryPodMap["key9_modline5_slew"] = 0;
    factoryPodMap["key9_modline5_destination"] = "None";
    factoryPodMap["key9_modline5_note"] = 60;
    factoryPodMap["key9_modline5_velocity"] = 127;
    factoryPodMap["key9_modline5_cc"] = 1;
    factoryPodMap["key9_modline5_mmcid"] = 0;
    factoryPodMap["key9_modline5_mmcfunction"] = "Stop";
    factoryPodMap["key9_modline5_channel"] = 0;
    factoryPodMap["key9_modline5_device"] = "SSCOM_Port_1";
    factoryPodMap["key9_modline5_ledgreen"] = "None";
    factoryPodMap["key9_modline5_ledred"] = "None";
    factoryPodMap["key9_modline5_displaylinked"] = 0;
    factoryPodMap["key9_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryPodMap["key9_modline6_enable"] = 0;
    factoryPodMap["key9_modline6_source"] = "None";
    factoryPodMap["key9_modline6_gain"] = 0.00;
    factoryPodMap["key9_modline6_offset"] = 0.00;
    factoryPodMap["key9_modline6_table"] = "1_Lin";
    factoryPodMap["key9_modline6_min"] = 0;
    factoryPodMap["key9_modline6_max"] = 127;
    factoryPodMap["key9_modline6_slew"] = 0;
    factoryPodMap["key9_modline6_destination"] = "None";
    factoryPodMap["key9_modline6_note"] = 60;
    factoryPodMap["key9_modline6_velocity"] = 127;
    factoryPodMap["key9_modline6_cc"] = 1;
    factoryPodMap["key9_modline6_mmcid"] = 0;
    factoryPodMap["key9_modline6_mmcfunction"] = "Stop";
    factoryPodMap["key9_modline6_channel"] = 0;
    factoryPodMap["key9_modline6_device"] = "SSCOM_Port_1";
    factoryPodMap["key9_modline6_ledgreen"] = "None";
    factoryPodMap["key9_modline6_ledred"] = "None";
    factoryPodMap["key9_modline6_displaylinked"] = 0;
    factoryPodMap["key9_modline6_reminder"] = "";


    //------------------------ Key 10 ------------------------//
    factoryPodMap["key10_name"] = "WAH";
    factoryPodMap["key10_displaymode"] = 1;
    factoryPodMap["key10_prefix"] = "";
    factoryPodMap["key10_counter_min"] = 0;
    factoryPodMap["key10_counter_max"] = 127;
    factoryPodMap["key10_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryPodMap["key10_modline1_enable"] = 1;
    factoryPodMap["key10_modline1_source"] = "Foot_On";
    factoryPodMap["key10_modline1_gain"] = 1.00;
    factoryPodMap["key10_modline1_offset"] = 0.00;
    factoryPodMap["key10_modline1_table"] = "Toggle_127";
    factoryPodMap["key10_modline1_min"] = 0;
    factoryPodMap["key10_modline1_max"] = 127;
    factoryPodMap["key10_modline1_slew"] = 0;
    factoryPodMap["key10_modline1_destination"] = "CC";
    factoryPodMap["key10_modline1_note"] = 60;
    factoryPodMap["key10_modline1_velocity"] = 127;
    factoryPodMap["key10_modline1_cc"] = 43;
    factoryPodMap["key10_modline1_mmcid"] = 0;
    factoryPodMap["key10_modline1_mmcfunction"] = "Stop";
    factoryPodMap["key10_modline1_channel"] = 1;
    factoryPodMap["key10_modline1_device"] = "SoftStep_Expander";
    factoryPodMap["key10_modline1_ledgreen"] = "True";
    factoryPodMap["key10_modline1_ledred"] = "None";
    factoryPodMap["key10_modline1_displaylinked"] = 1;
    factoryPodMap["key10_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryPodMap["key10_modline2_enable"] = 1;
    factoryPodMap["key10_modline2_source"] = "Foot_On";
    factoryPodMap["key10_modline2_gain"] = 1.00;
    factoryPodMap["key10_modline2_offset"] = 0.00;
    factoryPodMap["key10_modline2_table"] = "Toggle_127";
    factoryPodMap["key10_modline2_min"] = 0;
    factoryPodMap["key10_modline2_max"] = 127;
    factoryPodMap["key10_modline2_slew"] = 0;
    factoryPodMap["key10_modline2_destination"] = "CC";
    factoryPodMap["key10_modline2_note"] = 60;
    factoryPodMap["key10_modline2_velocity"] = 127;
    factoryPodMap["key10_modline2_cc"] = 43;
    factoryPodMap["key10_modline2_mmcid"] = 0;
    factoryPodMap["key10_modline2_mmcfunction"] = "Stop";
    factoryPodMap["key10_modline2_channel"] = 1;
    factoryPodMap["key10_modline2_device"] = "SSCOM_Port_1";
    factoryPodMap["key10_modline2_ledgreen"] = "None";
    factoryPodMap["key10_modline2_ledred"] = "None";
    factoryPodMap["key10_modline2_displaylinked"] = 0;
    factoryPodMap["key10_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryPodMap["key10_modline3_enable"] = 0;
    factoryPodMap["key10_modline3_source"] = "None";
    factoryPodMap["key10_modline3_gain"] = 0.00;
    factoryPodMap["key10_modline3_offset"] = 0.00;
    factoryPodMap["key10_modline3_table"] = "1_Lin";
    factoryPodMap["key10_modline3_min"] = 0;
    factoryPodMap["key10_modline3_max"] = 127;
    factoryPodMap["key10_modline3_slew"] = 0;
    factoryPodMap["key10_modline3_destination"] = "None";
    factoryPodMap["key10_modline3_note"] = 60;
    factoryPodMap["key10_modline3_velocity"] = 127;
    factoryPodMap["key10_modline3_cc"] = 1;
    factoryPodMap["key10_modline3_mmcid"] = 0;
    factoryPodMap["key10_modline3_mmcfunction"] = "Stop";
    factoryPodMap["key10_modline3_channel"] = 0;
    factoryPodMap["key10_modline3_device"] = "SSCOM_Port_1";
    factoryPodMap["key10_modline3_ledgreen"] = "None";
    factoryPodMap["key10_modline3_ledred"] = "None";
    factoryPodMap["key10_modline3_displaylinked"] = 0;
    factoryPodMap["key10_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryPodMap["key10_modline4_enable"] = 0;
    factoryPodMap["key10_modline4_source"] = "None";
    factoryPodMap["key10_modline4_gain"] = 0.00;
    factoryPodMap["key10_modline4_offset"] = 0.00;
    factoryPodMap["key10_modline4_table"] = "1_Lin";
    factoryPodMap["key10_modline4_min"] = 0;
    factoryPodMap["key10_modline4_max"] = 127;
    factoryPodMap["key10_modline4_slew"] = 0;
    factoryPodMap["key10_modline4_destination"] = "None";
    factoryPodMap["key10_modline4_note"] = 60;
    factoryPodMap["key10_modline4_velocity"] = 127;
    factoryPodMap["key10_modline4_cc"] = 1;
    factoryPodMap["key10_modline4_mmcid"] = 0;
    factoryPodMap["key10_modline4_mmcfunction"] = "Stop";
    factoryPodMap["key10_modline4_channel"] = 0;
    factoryPodMap["key10_modline4_device"] = "SSCOM_Port_1";
    factoryPodMap["key10_modline4_ledgreen"] = "None";
    factoryPodMap["key10_modline4_ledred"] = "None";
    factoryPodMap["key10_modline4_displaylinked"] = 0;
    factoryPodMap["key10_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryPodMap["key10_modline5_enable"] = 0;
    factoryPodMap["key10_modline5_source"] = "None";
    factoryPodMap["key10_modline5_gain"] = 0.00;
    factoryPodMap["key10_modline5_offset"] = 0.00;
    factoryPodMap["key10_modline5_table"] = "1_Lin";
    factoryPodMap["key10_modline5_min"] = 0;
    factoryPodMap["key10_modline5_max"] = 127;
    factoryPodMap["key10_modline5_slew"] = 0;
    factoryPodMap["key10_modline5_destination"] = "None";
    factoryPodMap["key10_modline5_note"] = 60;
    factoryPodMap["key10_modline5_velocity"] = 127;
    factoryPodMap["key10_modline5_cc"] = 1;
    factoryPodMap["key10_modline5_mmcid"] = 0;
    factoryPodMap["key10_modline5_mmcfunction"] = "Stop";
    factoryPodMap["key10_modline5_channel"] = 0;
    factoryPodMap["key10_modline5_device"] = "SSCOM_Port_1";
    factoryPodMap["key10_modline5_ledgreen"] = "None";
    factoryPodMap["key10_modline5_ledred"] = "None";
    factoryPodMap["key10_modline5_displaylinked"] = 0;
    factoryPodMap["key10_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryPodMap["key10_modline6_enable"] = 0;
    factoryPodMap["key10_modline6_source"] = "None";
    factoryPodMap["key10_modline6_gain"] = 0.00;
    factoryPodMap["key10_modline6_offset"] = 0.00;
    factoryPodMap["key10_modline6_table"] = "1_Lin";
    factoryPodMap["key10_modline6_min"] = 0;
    factoryPodMap["key10_modline6_max"] = 127;
    factoryPodMap["key10_modline6_slew"] = 0;
    factoryPodMap["key10_modline6_destination"] = "None";
    factoryPodMap["key10_modline6_note"] = 60;
    factoryPodMap["key10_modline6_velocity"] = 127;
    factoryPodMap["key10_modline6_cc"] = 1;
    factoryPodMap["key10_modline6_mmcid"] = 0;
    factoryPodMap["key10_modline6_mmcfunction"] = "Stop";
    factoryPodMap["key10_modline6_channel"] = 0;
    factoryPodMap["key10_modline6_device"] = "SSCOM_Port_1";
    factoryPodMap["key10_modline6_ledgreen"] = "None";
    factoryPodMap["key10_modline6_ledred"] = "None";
    factoryPodMap["key10_modline6_displaylinked"] = 0;
    factoryPodMap["key10_modline6_reminder"] = "";


    //------------------------ Nav ------------------------//
    factoryPodMap["nav_name"] = "";
    factoryPodMap["nav_displaymode"] = 4;
    factoryPodMap["nav_modlinemode"] = 1;
    factoryPodMap["nav_prefix"] = "";
    factoryPodMap["nav_counter_min"] = 0;
    factoryPodMap["nav_counter_max"] = 127;
    factoryPodMap["nav_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryPodMap["nav_modline1_enable"] = 1;
    factoryPodMap["nav_modline1_source"] = "Pedal";
    factoryPodMap["nav_modline1_gain"] = 1.00;
    factoryPodMap["nav_modline1_offset"] = 0.00;
    factoryPodMap["nav_modline1_table"] = "1_Lin";
    factoryPodMap["nav_modline1_min"] = 0;
    factoryPodMap["nav_modline1_max"] = 127;
    factoryPodMap["nav_modline1_slew"] = 0;
    factoryPodMap["nav_modline1_destination"] = "CC";
    factoryPodMap["nav_modline1_note"] = 60;
    factoryPodMap["nav_modline1_velocity"] = 127;
    factoryPodMap["nav_modline1_cc"] = 7;
    factoryPodMap["nav_modline1_mmcid"] = 0;
    factoryPodMap["nav_modline1_mmcfunction"] = "Stop";
    factoryPodMap["nav_modline1_channel"] = 1;
    factoryPodMap["nav_modline1_device"] = "SSCOM_Port_1";
    factoryPodMap["nav_modline1_displaylinked"] = 1;
    factoryPodMap["nav_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryPodMap["nav_modline2_enable"] = 1;
    factoryPodMap["nav_modline2_source"] = "Pedal";
    factoryPodMap["nav_modline2_gain"] = 1.00;
    factoryPodMap["nav_modline2_offset"] = 0.00;
    factoryPodMap["nav_modline2_table"] = "1_Lin";
    factoryPodMap["nav_modline2_min"] = 0;
    factoryPodMap["nav_modline2_max"] = 127;
    factoryPodMap["nav_modline2_slew"] = 0;
    factoryPodMap["nav_modline2_destination"] = "CC";
    factoryPodMap["nav_modline2_note"] = 60;
    factoryPodMap["nav_modline2_velocity"] = 127;
    factoryPodMap["nav_modline2_cc"] = 7;
    factoryPodMap["nav_modline2_mmcid"] = 0;
    factoryPodMap["nav_modline2_mmcfunction"] = "Stop";
    factoryPodMap["nav_modline2_channel"] = 1;
    factoryPodMap["nav_modline2_device"] = "SoftStep_Expander";
    factoryPodMap["nav_modline2_displaylinked"] = 0;
    factoryPodMap["nav_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryPodMap["nav_modline3_enable"] = 0;
    factoryPodMap["nav_modline3_source"] = "None";
    factoryPodMap["nav_modline3_gain"] = 0.00;
    factoryPodMap["nav_modline3_offset"] = 0.00;
    factoryPodMap["nav_modline3_table"] = "1_Lin";
    factoryPodMap["nav_modline3_min"] = 0;
    factoryPodMap["nav_modline3_max"] = 127;
    factoryPodMap["nav_modline3_slew"] = 0;
    factoryPodMap["nav_modline3_destination"] = "None";
    factoryPodMap["nav_modline3_note"] = 60;
    factoryPodMap["nav_modline3_velocity"] = 127;
    factoryPodMap["nav_modline3_cc"] = 1;
    factoryPodMap["nav_modline3_mmcid"] = 0;
    factoryPodMap["nav_modline3_mmcfunction"] = "Stop";
    factoryPodMap["nav_modline3_channel"] = 0;
    factoryPodMap["nav_modline3_device"] = "SSCOM_Port_1";
    factoryPodMap["nav_modline3_displaylinked"] = 0;
    factoryPodMap["nav_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryPodMap["nav_modline4_enable"] = 0;
    factoryPodMap["nav_modline4_source"] = "None";
    factoryPodMap["nav_modline4_gain"] = 0.00;
    factoryPodMap["nav_modline4_offset"] = 0.00;
    factoryPodMap["nav_modline4_table"] = "1_Lin";
    factoryPodMap["nav_modline4_min"] = 0;
    factoryPodMap["nav_modline4_max"] = 127;
    factoryPodMap["nav_modline4_slew"] = 0;
    factoryPodMap["nav_modline4_destination"] = "None";
    factoryPodMap["nav_modline4_note"] = 60;
    factoryPodMap["nav_modline4_velocity"] = 127;
    factoryPodMap["nav_modline4_cc"] = 1;
    factoryPodMap["nav_modline4_mmcid"] = 0;
    factoryPodMap["nav_modline4_mmcfunction"] = "Stop";
    factoryPodMap["nav_modline4_channel"] = 0;
    factoryPodMap["nav_modline4_device"] = "SSCOM_Port_1";
    factoryPodMap["nav_modline4_displaylinked"] = 0;
    factoryPodMap["nav_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryPodMap["nav_modline5_enable"] = 0;
    factoryPodMap["nav_modline5_source"] = "None";
    factoryPodMap["nav_modline5_gain"] = 0.00;
    factoryPodMap["nav_modline5_offset"] = 0.00;
    factoryPodMap["nav_modline5_table"] = "1_Lin";
    factoryPodMap["nav_modline5_min"] = 0;
    factoryPodMap["nav_modline5_max"] = 127;
    factoryPodMap["nav_modline5_slew"] = 0;
    factoryPodMap["nav_modline5_destination"] = "None";
    factoryPodMap["nav_modline5_note"] = 60;
    factoryPodMap["nav_modline5_velocity"] = 127;
    factoryPodMap["nav_modline5_cc"] = 1;
    factoryPodMap["nav_modline5_mmcid"] = 0;
    factoryPodMap["nav_modline5_mmcfunction"] = "Stop";
    factoryPodMap["nav_modline5_channel"] = 0;
    factoryPodMap["nav_modline5_device"] = "SSCOM_Port_1";
    factoryPodMap["nav_modline5_displaylinked"] = 0;
    factoryPodMap["nav_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryPodMap["nav_modline6_enable"] = 0;
    factoryPodMap["nav_modline6_source"] = "None";
    factoryPodMap["nav_modline6_gain"] = 0.00;
    factoryPodMap["nav_modline6_offset"] = 0.00;
    factoryPodMap["nav_modline6_table"] = "1_Lin";
    factoryPodMap["nav_modline6_min"] = 0;
    factoryPodMap["nav_modline6_max"] = 127;
    factoryPodMap["nav_modline6_slew"] = 0;
    factoryPodMap["nav_modline6_destination"] = "None";
    factoryPodMap["nav_modline6_note"] = 60;
    factoryPodMap["nav_modline6_velocity"] = 127;
    factoryPodMap["nav_modline6_cc"] = 1;
    factoryPodMap["nav_modline6_mmcid"] = 0;
    factoryPodMap["nav_modline6_mmcfunction"] = "Stop";
    factoryPodMap["nav_modline6_channel"] = 0;
    factoryPodMap["nav_modline6_device"] = "SSCOM_Port_1";
    factoryPodMap["nav_modline6_displaylinked"] = 0;
    factoryPodMap["nav_modline6_reminder"] = "";

}

void FactoryPresets::createLiveMap(){

    factoryLiveMap["displayname"] = "LIVE";

    factoryLiveMap["useFactory"] = "Ableton Live Control";

    //------------------------ Key 1 ------------------------//
    factoryLiveMap["key1_name"] = "1FDR";
    factoryLiveMap["key1_displaymode"] = 4;
    factoryLiveMap["key1_prefix"] = "";
    factoryLiveMap["key1_counter_min"] = 0;
    factoryLiveMap["key1_counter_max"] = 127;
    factoryLiveMap["key1_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryLiveMap["key1_modline1_enable"] = 1;
    factoryLiveMap["key1_modline1_source"] = "Y_Increment";
    factoryLiveMap["key1_modline1_gain"] = 1.00;
    factoryLiveMap["key1_modline1_offset"] = 0.00;
    factoryLiveMap["key1_modline1_table"] = "1_Lin";
    factoryLiveMap["key1_modline1_min"] = 0;
    factoryLiveMap["key1_modline1_max"] = 127;
    factoryLiveMap["key1_modline1_slew"] = 0;
    factoryLiveMap["key1_modline1_destination"] = "CC";
    factoryLiveMap["key1_modline1_note"] = 60;
    factoryLiveMap["key1_modline1_velocity"] = 127;
    factoryLiveMap["key1_modline1_cc"] = 61;
    factoryLiveMap["key1_modline1_mmcid"] = 0;
    factoryLiveMap["key1_modline1_mmcfunction"] = "Stop";
    factoryLiveMap["key1_modline1_channel"] = 1;
    factoryLiveMap["key1_modline1_device"] = "SSCOM_Port_1";
    factoryLiveMap["key1_modline1_ledgreen"] = "None";
    factoryLiveMap["key1_modline1_ledred"] = "None";
    factoryLiveMap["key1_modline1_displaylinked"] = 1;
    factoryLiveMap["key1_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryLiveMap["key1_modline2_enable"] = 1;
    factoryLiveMap["key1_modline2_source"] = "Y_Increment";
    factoryLiveMap["key1_modline2_gain"] = 1.00;
    factoryLiveMap["key1_modline2_offset"] = 0.00;
    factoryLiveMap["key1_modline2_table"] = "1_Lin";
    factoryLiveMap["key1_modline2_min"] = 0;
    factoryLiveMap["key1_modline2_max"] = 127;
    factoryLiveMap["key1_modline2_slew"] = 0;
    factoryLiveMap["key1_modline2_destination"] = "CC";
    factoryLiveMap["key1_modline2_note"] = 60;
    factoryLiveMap["key1_modline2_velocity"] = 127;
    factoryLiveMap["key1_modline2_cc"] = 61;
    factoryLiveMap["key1_modline2_mmcid"] = 0;
    factoryLiveMap["key1_modline2_mmcfunction"] = "Stop";
    factoryLiveMap["key1_modline2_channel"] = 1;
    factoryLiveMap["key1_modline2_device"] = "SoftStep_Expander";
    factoryLiveMap["key1_modline2_ledgreen"] = "None";
    factoryLiveMap["key1_modline2_ledred"] = "None";
    factoryLiveMap["key1_modline2_displaylinked"] = 0;
    factoryLiveMap["key1_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryLiveMap["key1_modline3_enable"] = 0;
    factoryLiveMap["key1_modline3_source"] = "None";
    factoryLiveMap["key1_modline3_gain"] = 0.00;
    factoryLiveMap["key1_modline3_offset"] = 0.00;
    factoryLiveMap["key1_modline3_table"] = "1_Lin";
    factoryLiveMap["key1_modline3_min"] = 0;
    factoryLiveMap["key1_modline3_max"] = 127;
    factoryLiveMap["key1_modline3_slew"] = 0;
    factoryLiveMap["key1_modline3_destination"] = "None";
    factoryLiveMap["key1_modline3_note"] = 60;
    factoryLiveMap["key1_modline3_velocity"] = 127;
    factoryLiveMap["key1_modline3_cc"] = 1;
    factoryLiveMap["key1_modline3_mmcid"] = 0;
    factoryLiveMap["key1_modline3_mmcfunction"] = "Stop";
    factoryLiveMap["key1_modline3_channel"] = 0;
    factoryLiveMap["key1_modline3_device"] = "SSCOM_Port_1";
    factoryLiveMap["key1_modline3_ledgreen"] = "None";
    factoryLiveMap["key1_modline3_ledred"] = "None";
    factoryLiveMap["key1_modline3_displaylinked"] = 0;
    factoryLiveMap["key1_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryLiveMap["key1_modline4_enable"] = 0;
    factoryLiveMap["key1_modline4_source"] = "None";
    factoryLiveMap["key1_modline4_gain"] = 0.00;
    factoryLiveMap["key1_modline4_offset"] = 0.00;
    factoryLiveMap["key1_modline4_table"] = "1_Lin";
    factoryLiveMap["key1_modline4_min"] = 0;
    factoryLiveMap["key1_modline4_max"] = 127;
    factoryLiveMap["key1_modline4_slew"] = 0;
    factoryLiveMap["key1_modline4_destination"] = "None";
    factoryLiveMap["key1_modline4_note"] = 60;
    factoryLiveMap["key1_modline4_velocity"] = 127;
    factoryLiveMap["key1_modline4_cc"] = 1;
    factoryLiveMap["key1_modline4_mmcid"] = 0;
    factoryLiveMap["key1_modline4_mmcfunction"] = "Stop";
    factoryLiveMap["key1_modline4_channel"] = 0;
    factoryLiveMap["key1_modline4_device"] = "SSCOM_Port_1";
    factoryLiveMap["key1_modline4_ledgreen"] = "None";
    factoryLiveMap["key1_modline4_ledred"] = "None";
    factoryLiveMap["key1_modline4_displaylinked"] = 0;
    factoryLiveMap["key1_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryLiveMap["key1_modline5_enable"] = 0;
    factoryLiveMap["key1_modline5_source"] = "None";
    factoryLiveMap["key1_modline5_gain"] = 0.00;
    factoryLiveMap["key1_modline5_offset"] = 0.00;
    factoryLiveMap["key1_modline5_table"] = "1_Lin";
    factoryLiveMap["key1_modline5_min"] = 0;
    factoryLiveMap["key1_modline5_max"] = 127;
    factoryLiveMap["key1_modline5_slew"] = 0;
    factoryLiveMap["key1_modline5_destination"] = "None";
    factoryLiveMap["key1_modline5_note"] = 60;
    factoryLiveMap["key1_modline5_velocity"] = 127;
    factoryLiveMap["key1_modline5_cc"] = 1;
    factoryLiveMap["key1_modline5_mmcid"] = 0;
    factoryLiveMap["key1_modline5_mmcfunction"] = "Stop";
    factoryLiveMap["key1_modline5_channel"] = 0;
    factoryLiveMap["key1_modline5_device"] = "SSCOM_Port_1";
    factoryLiveMap["key1_modline5_ledgreen"] = "None";
    factoryLiveMap["key1_modline5_ledred"] = "None";
    factoryLiveMap["key1_modline5_displaylinked"] = 0;
    factoryLiveMap["key1_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryLiveMap["key1_modline6_enable"] = 0;
    factoryLiveMap["key1_modline6_source"] = "None";
    factoryLiveMap["key1_modline6_gain"] = 0.00;
    factoryLiveMap["key1_modline6_offset"] = 0.00;
    factoryLiveMap["key1_modline6_table"] = "1_Lin";
    factoryLiveMap["key1_modline6_min"] = 0;
    factoryLiveMap["key1_modline6_max"] = 127;
    factoryLiveMap["key1_modline6_slew"] = 0;
    factoryLiveMap["key1_modline6_destination"] = "None";
    factoryLiveMap["key1_modline6_note"] = 60;
    factoryLiveMap["key1_modline6_velocity"] = 127;
    factoryLiveMap["key1_modline6_cc"] = 1;
    factoryLiveMap["key1_modline6_mmcid"] = 0;
    factoryLiveMap["key1_modline6_mmcfunction"] = "Stop";
    factoryLiveMap["key1_modline6_channel"] = 0;
    factoryLiveMap["key1_modline6_device"] = "SSCOM_Port_1";
    factoryLiveMap["key1_modline6_ledgreen"] = "None";
    factoryLiveMap["key1_modline6_ledred"] = "None";
    factoryLiveMap["key1_modline6_displaylinked"] = 0;
    factoryLiveMap["key1_modline6_reminder"] = "";


    //------------------------ Key 2 ------------------------//
    factoryLiveMap["key2_name"] = "2FDR";
    factoryLiveMap["key2_displaymode"] = 4;
    factoryLiveMap["key2_prefix"] = "";
    factoryLiveMap["key2_counter_min"] = 0;
    factoryLiveMap["key2_counter_max"] = 127;
    factoryLiveMap["key2_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryLiveMap["key2_modline1_enable"] = 1;
    factoryLiveMap["key2_modline1_source"] = "Y_Increment";
    factoryLiveMap["key2_modline1_gain"] = 1.00;
    factoryLiveMap["key2_modline1_offset"] = 0.00;
    factoryLiveMap["key2_modline1_table"] = "1_Lin";
    factoryLiveMap["key2_modline1_min"] = 0;
    factoryLiveMap["key2_modline1_max"] = 127;
    factoryLiveMap["key2_modline1_slew"] = 0;
    factoryLiveMap["key2_modline1_destination"] = "CC";
    factoryLiveMap["key2_modline1_note"] = 60;
    factoryLiveMap["key2_modline1_velocity"] = 127;
    factoryLiveMap["key2_modline1_cc"] = 62;
    factoryLiveMap["key2_modline1_mmcid"] = 0;
    factoryLiveMap["key2_modline1_mmcfunction"] = "Stop";
    factoryLiveMap["key2_modline1_channel"] = 1;
    factoryLiveMap["key2_modline1_device"] = "SSCOM_Port_1";
    factoryLiveMap["key2_modline1_ledgreen"] = "None";
    factoryLiveMap["key2_modline1_ledred"] = "None";
    factoryLiveMap["key2_modline1_displaylinked"] = 1;
    factoryLiveMap["key2_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryLiveMap["key2_modline2_enable"] = 1;
    factoryLiveMap["key2_modline2_source"] = "Y_Increment";
    factoryLiveMap["key2_modline2_gain"] = 1.00;
    factoryLiveMap["key2_modline2_offset"] = 0.00;
    factoryLiveMap["key2_modline2_table"] = "1_Lin";
    factoryLiveMap["key2_modline2_min"] = 0;
    factoryLiveMap["key2_modline2_max"] = 127;
    factoryLiveMap["key2_modline2_slew"] = 0;
    factoryLiveMap["key2_modline2_destination"] = "CC";
    factoryLiveMap["key2_modline2_note"] = 60;
    factoryLiveMap["key2_modline2_velocity"] = 127;
    factoryLiveMap["key2_modline2_cc"] = 62;
    factoryLiveMap["key2_modline2_mmcid"] = 0;
    factoryLiveMap["key2_modline2_mmcfunction"] = "Stop";
    factoryLiveMap["key2_modline2_channel"] = 1;
    factoryLiveMap["key2_modline2_device"] = "SoftStep_Expander";
    factoryLiveMap["key2_modline2_ledgreen"] = "None";
    factoryLiveMap["key2_modline2_ledred"] = "None";
    factoryLiveMap["key2_modline2_displaylinked"] = 0;
    factoryLiveMap["key2_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryLiveMap["key2_modline3_enable"] = 0;
    factoryLiveMap["key2_modline3_source"] = "None";
    factoryLiveMap["key2_modline3_gain"] = 0.00;
    factoryLiveMap["key2_modline3_offset"] = 0.00;
    factoryLiveMap["key2_modline3_table"] = "1_Lin";
    factoryLiveMap["key2_modline3_min"] = 0;
    factoryLiveMap["key2_modline3_max"] = 127;
    factoryLiveMap["key2_modline3_slew"] = 0;
    factoryLiveMap["key2_modline3_destination"] = "None";
    factoryLiveMap["key2_modline3_note"] = 60;
    factoryLiveMap["key2_modline3_velocity"] = 127;
    factoryLiveMap["key2_modline3_cc"] = 1;
    factoryLiveMap["key2_modline3_mmcid"] = 0;
    factoryLiveMap["key2_modline3_mmcfunction"] = "Stop";
    factoryLiveMap["key2_modline3_channel"] = 0;
    factoryLiveMap["key2_modline3_device"] = "SSCOM_Port_1";
    factoryLiveMap["key2_modline3_ledgreen"] = "None";
    factoryLiveMap["key2_modline3_ledred"] = "None";
    factoryLiveMap["key2_modline3_displaylinked"] = 0;
    factoryLiveMap["key2_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryLiveMap["key2_modline4_enable"] = 0;
    factoryLiveMap["key2_modline4_source"] = "None";
    factoryLiveMap["key2_modline4_gain"] = 0.00;
    factoryLiveMap["key2_modline4_offset"] = 0.00;
    factoryLiveMap["key2_modline4_table"] = "1_Lin";
    factoryLiveMap["key2_modline4_min"] = 0;
    factoryLiveMap["key2_modline4_max"] = 127;
    factoryLiveMap["key2_modline4_slew"] = 0;
    factoryLiveMap["key2_modline4_destination"] = "None";
    factoryLiveMap["key2_modline4_note"] = 60;
    factoryLiveMap["key2_modline4_velocity"] = 127;
    factoryLiveMap["key2_modline4_cc"] = 1;
    factoryLiveMap["key2_modline4_mmcid"] = 0;
    factoryLiveMap["key2_modline4_mmcfunction"] = "Stop";
    factoryLiveMap["key2_modline4_channel"] = 0;
    factoryLiveMap["key2_modline4_device"] = "SSCOM_Port_1";
    factoryLiveMap["key2_modline4_ledgreen"] = "None";
    factoryLiveMap["key2_modline4_ledred"] = "None";
    factoryLiveMap["key2_modline4_displaylinked"] = 0;
    factoryLiveMap["key2_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryLiveMap["key2_modline5_enable"] = 0;
    factoryLiveMap["key2_modline5_source"] = "None";
    factoryLiveMap["key2_modline5_gain"] = 0.00;
    factoryLiveMap["key2_modline5_offset"] = 0.00;
    factoryLiveMap["key2_modline5_table"] = "1_Lin";
    factoryLiveMap["key2_modline5_min"] = 0;
    factoryLiveMap["key2_modline5_max"] = 127;
    factoryLiveMap["key2_modline5_slew"] = 0;
    factoryLiveMap["key2_modline5_destination"] = "None";
    factoryLiveMap["key2_modline5_note"] = 60;
    factoryLiveMap["key2_modline5_velocity"] = 127;
    factoryLiveMap["key2_modline5_cc"] = 1;
    factoryLiveMap["key2_modline5_mmcid"] = 0;
    factoryLiveMap["key2_modline5_mmcfunction"] = "Stop";
    factoryLiveMap["key2_modline5_channel"] = 0;
    factoryLiveMap["key2_modline5_device"] = "SSCOM_Port_1";
    factoryLiveMap["key2_modline5_ledgreen"] = "None";
    factoryLiveMap["key2_modline5_ledred"] = "None";
    factoryLiveMap["key2_modline5_displaylinked"] = 0;
    factoryLiveMap["key2_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryLiveMap["key2_modline6_enable"] = 0;
    factoryLiveMap["key2_modline6_source"] = "None";
    factoryLiveMap["key2_modline6_gain"] = 0.00;
    factoryLiveMap["key2_modline6_offset"] = 0.00;
    factoryLiveMap["key2_modline6_table"] = "1_Lin";
    factoryLiveMap["key2_modline6_min"] = 0;
    factoryLiveMap["key2_modline6_max"] = 127;
    factoryLiveMap["key2_modline6_slew"] = 0;
    factoryLiveMap["key2_modline6_destination"] = "None";
    factoryLiveMap["key2_modline6_note"] = 60;
    factoryLiveMap["key2_modline6_velocity"] = 127;
    factoryLiveMap["key2_modline6_cc"] = 1;
    factoryLiveMap["key2_modline6_mmcid"] = 0;
    factoryLiveMap["key2_modline6_mmcfunction"] = "Stop";
    factoryLiveMap["key2_modline6_channel"] = 0;
    factoryLiveMap["key2_modline6_device"] = "SSCOM_Port_1";
    factoryLiveMap["key2_modline6_ledgreen"] = "None";
    factoryLiveMap["key2_modline6_ledred"] = "None";
    factoryLiveMap["key2_modline6_displaylinked"] = 0;
    factoryLiveMap["key2_modline6_reminder"] = "";


    //------------------------ Key 3 ------------------------//
    factoryLiveMap["key3_name"] = "3FDR";
    factoryLiveMap["key3_displaymode"] = 4;
    factoryLiveMap["key3_prefix"] = "";
    factoryLiveMap["key3_counter_min"] = 0;
    factoryLiveMap["key3_counter_max"] = 127;
    factoryLiveMap["key3_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryLiveMap["key3_modline1_enable"] = 1;
    factoryLiveMap["key3_modline1_source"] = "Y_Increment";
    factoryLiveMap["key3_modline1_gain"] = 1.00;
    factoryLiveMap["key3_modline1_offset"] = 0.00;
    factoryLiveMap["key3_modline1_table"] = "1_Lin";
    factoryLiveMap["key3_modline1_min"] = 0;
    factoryLiveMap["key3_modline1_max"] = 127;
    factoryLiveMap["key3_modline1_slew"] = 0;
    factoryLiveMap["key3_modline1_destination"] = "CC";
    factoryLiveMap["key3_modline1_note"] = 60;
    factoryLiveMap["key3_modline1_velocity"] = 127;
    factoryLiveMap["key3_modline1_cc"] = 63;
    factoryLiveMap["key3_modline1_mmcid"] = 0;
    factoryLiveMap["key3_modline1_mmcfunction"] = "Stop";
    factoryLiveMap["key3_modline1_channel"] = 1;
    factoryLiveMap["key3_modline1_device"] = "SSCOM_Port_1";
    factoryLiveMap["key3_modline1_ledgreen"] = "None";
    factoryLiveMap["key3_modline1_ledred"] = "None";
    factoryLiveMap["key3_modline1_displaylinked"] = 1;
    factoryLiveMap["key3_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryLiveMap["key3_modline2_enable"] = 1;
    factoryLiveMap["key3_modline2_source"] = "Y_Increment";
    factoryLiveMap["key3_modline2_gain"] = 1.00;
    factoryLiveMap["key3_modline2_offset"] = 0.00;
    factoryLiveMap["key3_modline2_table"] = "1_Lin";
    factoryLiveMap["key3_modline2_min"] = 0;
    factoryLiveMap["key3_modline2_max"] = 127;
    factoryLiveMap["key3_modline2_slew"] = 0;
    factoryLiveMap["key3_modline2_destination"] = "CC";
    factoryLiveMap["key3_modline2_note"] = 60;
    factoryLiveMap["key3_modline2_velocity"] = 127;
    factoryLiveMap["key3_modline2_cc"] = 63;
    factoryLiveMap["key3_modline2_mmcid"] = 0;
    factoryLiveMap["key3_modline2_mmcfunction"] = "Stop";
    factoryLiveMap["key3_modline2_channel"] = 1;
    factoryLiveMap["key3_modline2_device"] = "SoftStep_Expander";
    factoryLiveMap["key3_modline2_ledgreen"] = "None";
    factoryLiveMap["key3_modline2_ledred"] = "None";
    factoryLiveMap["key3_modline2_displaylinked"] = 0;
    factoryLiveMap["key3_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryLiveMap["key3_modline3_enable"] = 0;
    factoryLiveMap["key3_modline3_source"] = "None";
    factoryLiveMap["key3_modline3_gain"] = 0.00;
    factoryLiveMap["key3_modline3_offset"] = 0.00;
    factoryLiveMap["key3_modline3_table"] = "1_Lin";
    factoryLiveMap["key3_modline3_min"] = 0;
    factoryLiveMap["key3_modline3_max"] = 127;
    factoryLiveMap["key3_modline3_slew"] = 0;
    factoryLiveMap["key3_modline3_destination"] = "None";
    factoryLiveMap["key3_modline3_note"] = 60;
    factoryLiveMap["key3_modline3_velocity"] = 127;
    factoryLiveMap["key3_modline3_cc"] = 1;
    factoryLiveMap["key3_modline3_mmcid"] = 0;
    factoryLiveMap["key3_modline3_mmcfunction"] = "Stop";
    factoryLiveMap["key3_modline3_channel"] = 0;
    factoryLiveMap["key3_modline3_device"] = "SSCOM_Port_1";
    factoryLiveMap["key3_modline3_ledgreen"] = "None";
    factoryLiveMap["key3_modline3_ledred"] = "None";
    factoryLiveMap["key3_modline3_displaylinked"] = 0;
    factoryLiveMap["key3_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryLiveMap["key3_modline4_enable"] = 0;
    factoryLiveMap["key3_modline4_source"] = "None";
    factoryLiveMap["key3_modline4_gain"] = 0.00;
    factoryLiveMap["key3_modline4_offset"] = 0.00;
    factoryLiveMap["key3_modline4_table"] = "1_Lin";
    factoryLiveMap["key3_modline4_min"] = 0;
    factoryLiveMap["key3_modline4_max"] = 127;
    factoryLiveMap["key3_modline4_slew"] = 0;
    factoryLiveMap["key3_modline4_destination"] = "None";
    factoryLiveMap["key3_modline4_note"] = 60;
    factoryLiveMap["key3_modline4_velocity"] = 127;
    factoryLiveMap["key3_modline4_cc"] = 1;
    factoryLiveMap["key3_modline4_mmcid"] = 0;
    factoryLiveMap["key3_modline4_mmcfunction"] = "Stop";
    factoryLiveMap["key3_modline4_channel"] = 0;
    factoryLiveMap["key3_modline4_device"] = "SSCOM_Port_1";
    factoryLiveMap["key3_modline4_ledgreen"] = "None";
    factoryLiveMap["key3_modline4_ledred"] = "None";
    factoryLiveMap["key3_modline4_displaylinked"] = 0;
    factoryLiveMap["key3_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryLiveMap["key3_modline5_enable"] = 0;
    factoryLiveMap["key3_modline5_source"] = "None";
    factoryLiveMap["key3_modline5_gain"] = 0.00;
    factoryLiveMap["key3_modline5_offset"] = 0.00;
    factoryLiveMap["key3_modline5_table"] = "1_Lin";
    factoryLiveMap["key3_modline5_min"] = 0;
    factoryLiveMap["key3_modline5_max"] = 127;
    factoryLiveMap["key3_modline5_slew"] = 0;
    factoryLiveMap["key3_modline5_destination"] = "None";
    factoryLiveMap["key3_modline5_note"] = 60;
    factoryLiveMap["key3_modline5_velocity"] = 127;
    factoryLiveMap["key3_modline5_cc"] = 1;
    factoryLiveMap["key3_modline5_mmcid"] = 0;
    factoryLiveMap["key3_modline5_mmcfunction"] = "Stop";
    factoryLiveMap["key3_modline5_channel"] = 0;
    factoryLiveMap["key3_modline5_device"] = "SSCOM_Port_1";
    factoryLiveMap["key3_modline5_ledgreen"] = "None";
    factoryLiveMap["key3_modline5_ledred"] = "None";
    factoryLiveMap["key3_modline5_displaylinked"] = 0;
    factoryLiveMap["key3_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryLiveMap["key3_modline6_enable"] = 0;
    factoryLiveMap["key3_modline6_source"] = "None";
    factoryLiveMap["key3_modline6_gain"] = 0.00;
    factoryLiveMap["key3_modline6_offset"] = 0.00;
    factoryLiveMap["key3_modline6_table"] = "1_Lin";
    factoryLiveMap["key3_modline6_min"] = 0;
    factoryLiveMap["key3_modline6_max"] = 127;
    factoryLiveMap["key3_modline6_slew"] = 0;
    factoryLiveMap["key3_modline6_destination"] = "None";
    factoryLiveMap["key3_modline6_note"] = 60;
    factoryLiveMap["key3_modline6_velocity"] = 127;
    factoryLiveMap["key3_modline6_cc"] = 1;
    factoryLiveMap["key3_modline6_mmcid"] = 0;
    factoryLiveMap["key3_modline6_mmcfunction"] = "Stop";
    factoryLiveMap["key3_modline6_channel"] = 0;
    factoryLiveMap["key3_modline6_device"] = "SSCOM_Port_1";
    factoryLiveMap["key3_modline6_ledgreen"] = "None";
    factoryLiveMap["key3_modline6_ledred"] = "None";
    factoryLiveMap["key3_modline6_displaylinked"] = 0;
    factoryLiveMap["key3_modline6_reminder"] = "";


    //------------------------ Key 4 ------------------------//
    factoryLiveMap["key4_name"] = "4FDR";
    factoryLiveMap["key4_displaymode"] = 4;
    factoryLiveMap["key4_prefix"] = "";
    factoryLiveMap["key4_counter_min"] = 0;
    factoryLiveMap["key4_counter_max"] = 127;
    factoryLiveMap["key4_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryLiveMap["key4_modline1_enable"] = 1;
    factoryLiveMap["key4_modline1_source"] = "Y_Increment";
    factoryLiveMap["key4_modline1_gain"] = 1.00;
    factoryLiveMap["key4_modline1_offset"] = 0.00;
    factoryLiveMap["key4_modline1_table"] = "1_Lin";
    factoryLiveMap["key4_modline1_min"] = 0;
    factoryLiveMap["key4_modline1_max"] = 127;
    factoryLiveMap["key4_modline1_slew"] = 0;
    factoryLiveMap["key4_modline1_destination"] = "CC";
    factoryLiveMap["key4_modline1_note"] = 60;
    factoryLiveMap["key4_modline1_velocity"] = 127;
    factoryLiveMap["key4_modline1_cc"] = 64;
    factoryLiveMap["key4_modline1_mmcid"] = 0;
    factoryLiveMap["key4_modline1_mmcfunction"] = "Stop";
    factoryLiveMap["key4_modline1_channel"] = 1;
    factoryLiveMap["key4_modline1_device"] = "SSCOM_Port_1";
    factoryLiveMap["key4_modline1_ledgreen"] = "None";
    factoryLiveMap["key4_modline1_ledred"] = "None";
    factoryLiveMap["key4_modline1_displaylinked"] = 1;
    factoryLiveMap["key4_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryLiveMap["key4_modline2_enable"] = 1;
    factoryLiveMap["key4_modline2_source"] = "Y_Increment";
    factoryLiveMap["key4_modline2_gain"] = 1.00;
    factoryLiveMap["key4_modline2_offset"] = 0.00;
    factoryLiveMap["key4_modline2_table"] = "1_Lin";
    factoryLiveMap["key4_modline2_min"] = 0;
    factoryLiveMap["key4_modline2_max"] = 127;
    factoryLiveMap["key4_modline2_slew"] = 0;
    factoryLiveMap["key4_modline2_destination"] = "CC";
    factoryLiveMap["key4_modline2_note"] = 60;
    factoryLiveMap["key4_modline2_velocity"] = 127;
    factoryLiveMap["key4_modline2_cc"] = 64;
    factoryLiveMap["key4_modline2_mmcid"] = 0;
    factoryLiveMap["key4_modline2_mmcfunction"] = "Stop";
    factoryLiveMap["key4_modline2_channel"] = 1;
    factoryLiveMap["key4_modline2_device"] = "SoftStep_Expander";
    factoryLiveMap["key4_modline2_ledgreen"] = "None";
    factoryLiveMap["key4_modline2_ledred"] = "None";
    factoryLiveMap["key4_modline2_displaylinked"] = 0;
    factoryLiveMap["key4_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryLiveMap["key4_modline3_enable"] = 0;
    factoryLiveMap["key4_modline3_source"] = "None";
    factoryLiveMap["key4_modline3_gain"] = 0.00;
    factoryLiveMap["key4_modline3_offset"] = 0.00;
    factoryLiveMap["key4_modline3_table"] = "1_Lin";
    factoryLiveMap["key4_modline3_min"] = 0;
    factoryLiveMap["key4_modline3_max"] = 127;
    factoryLiveMap["key4_modline3_slew"] = 0;
    factoryLiveMap["key4_modline3_destination"] = "None";
    factoryLiveMap["key4_modline3_note"] = 60;
    factoryLiveMap["key4_modline3_velocity"] = 127;
    factoryLiveMap["key4_modline3_cc"] = 1;
    factoryLiveMap["key4_modline3_mmcid"] = 0;
    factoryLiveMap["key4_modline3_mmcfunction"] = "Stop";
    factoryLiveMap["key4_modline3_channel"] = 0;
    factoryLiveMap["key4_modline3_device"] = "SSCOM_Port_1";
    factoryLiveMap["key4_modline3_ledgreen"] = "None";
    factoryLiveMap["key4_modline3_ledred"] = "None";
    factoryLiveMap["key4_modline3_displaylinked"] = 0;
    factoryLiveMap["key4_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryLiveMap["key4_modline4_enable"] = 0;
    factoryLiveMap["key4_modline4_source"] = "None";
    factoryLiveMap["key4_modline4_gain"] = 0.00;
    factoryLiveMap["key4_modline4_offset"] = 0.00;
    factoryLiveMap["key4_modline4_table"] = "1_Lin";
    factoryLiveMap["key4_modline4_min"] = 0;
    factoryLiveMap["key4_modline4_max"] = 127;
    factoryLiveMap["key4_modline4_slew"] = 0;
    factoryLiveMap["key4_modline4_destination"] = "None";
    factoryLiveMap["key4_modline4_note"] = 60;
    factoryLiveMap["key4_modline4_velocity"] = 127;
    factoryLiveMap["key4_modline4_cc"] = 1;
    factoryLiveMap["key4_modline4_mmcid"] = 0;
    factoryLiveMap["key4_modline4_mmcfunction"] = "Stop";
    factoryLiveMap["key4_modline4_channel"] = 0;
    factoryLiveMap["key4_modline4_device"] = "SSCOM_Port_1";
    factoryLiveMap["key4_modline4_ledgreen"] = "None";
    factoryLiveMap["key4_modline4_ledred"] = "None";
    factoryLiveMap["key4_modline4_displaylinked"] = 0;
    factoryLiveMap["key4_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryLiveMap["key4_modline5_enable"] = 0;
    factoryLiveMap["key4_modline5_source"] = "None";
    factoryLiveMap["key4_modline5_gain"] = 0.00;
    factoryLiveMap["key4_modline5_offset"] = 0.00;
    factoryLiveMap["key4_modline5_table"] = "1_Lin";
    factoryLiveMap["key4_modline5_min"] = 0;
    factoryLiveMap["key4_modline5_max"] = 127;
    factoryLiveMap["key4_modline5_slew"] = 0;
    factoryLiveMap["key4_modline5_destination"] = "None";
    factoryLiveMap["key4_modline5_note"] = 60;
    factoryLiveMap["key4_modline5_velocity"] = 127;
    factoryLiveMap["key4_modline5_cc"] = 1;
    factoryLiveMap["key4_modline5_mmcid"] = 0;
    factoryLiveMap["key4_modline5_mmcfunction"] = "Stop";
    factoryLiveMap["key4_modline5_channel"] = 0;
    factoryLiveMap["key4_modline5_device"] = "SSCOM_Port_1";
    factoryLiveMap["key4_modline5_ledgreen"] = "None";
    factoryLiveMap["key4_modline5_ledred"] = "None";
    factoryLiveMap["key4_modline5_displaylinked"] = 0;
    factoryLiveMap["key4_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryLiveMap["key4_modline6_enable"] = 0;
    factoryLiveMap["key4_modline6_source"] = "None";
    factoryLiveMap["key4_modline6_gain"] = 0.00;
    factoryLiveMap["key4_modline6_offset"] = 0.00;
    factoryLiveMap["key4_modline6_table"] = "1_Lin";
    factoryLiveMap["key4_modline6_min"] = 0;
    factoryLiveMap["key4_modline6_max"] = 127;
    factoryLiveMap["key4_modline6_slew"] = 0;
    factoryLiveMap["key4_modline6_destination"] = "None";
    factoryLiveMap["key4_modline6_note"] = 60;
    factoryLiveMap["key4_modline6_velocity"] = 127;
    factoryLiveMap["key4_modline6_cc"] = 1;
    factoryLiveMap["key4_modline6_mmcid"] = 0;
    factoryLiveMap["key4_modline6_mmcfunction"] = "Stop";
    factoryLiveMap["key4_modline6_channel"] = 0;
    factoryLiveMap["key4_modline6_device"] = "SSCOM_Port_1";
    factoryLiveMap["key4_modline6_ledgreen"] = "None";
    factoryLiveMap["key4_modline6_ledred"] = "None";
    factoryLiveMap["key4_modline6_displaylinked"] = 0;
    factoryLiveMap["key4_modline6_reminder"] = "";


    //------------------------ Key 5 ------------------------//
    factoryLiveMap["key5_name"] = "5FDR";
    factoryLiveMap["key5_displaymode"] = 4;
    factoryLiveMap["key5_prefix"] = "";
    factoryLiveMap["key5_counter_min"] = 0;
    factoryLiveMap["key5_counter_max"] = 127;
    factoryLiveMap["key5_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryLiveMap["key5_modline1_enable"] = 1;
    factoryLiveMap["key5_modline1_source"] = "Y_Increment";
    factoryLiveMap["key5_modline1_gain"] = 1.00;
    factoryLiveMap["key5_modline1_offset"] = 0.00;
    factoryLiveMap["key5_modline1_table"] = "1_Lin";
    factoryLiveMap["key5_modline1_min"] = 0;
    factoryLiveMap["key5_modline1_max"] = 127;
    factoryLiveMap["key5_modline1_slew"] = 0;
    factoryLiveMap["key5_modline1_destination"] = "CC";
    factoryLiveMap["key5_modline1_note"] = 60;
    factoryLiveMap["key5_modline1_velocity"] = 127;
    factoryLiveMap["key5_modline1_cc"] = 65;
    factoryLiveMap["key5_modline1_mmcid"] = 0;
    factoryLiveMap["key5_modline1_mmcfunction"] = "Stop";
    factoryLiveMap["key5_modline1_channel"] = 1;
    factoryLiveMap["key5_modline1_device"] = "SSCOM_Port_1";
    factoryLiveMap["key5_modline1_ledgreen"] = "None";
    factoryLiveMap["key5_modline1_ledred"] = "None";
    factoryLiveMap["key5_modline1_displaylinked"] = 1;
    factoryLiveMap["key5_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryLiveMap["key5_modline2_enable"] = 1;
    factoryLiveMap["key5_modline2_source"] = "Y_Increment";
    factoryLiveMap["key5_modline2_gain"] = 1.00;
    factoryLiveMap["key5_modline2_offset"] = 0.00;
    factoryLiveMap["key5_modline2_table"] = "1_Lin";
    factoryLiveMap["key5_modline2_min"] = 0;
    factoryLiveMap["key5_modline2_max"] = 127;
    factoryLiveMap["key5_modline2_slew"] = 0;
    factoryLiveMap["key5_modline2_destination"] = "CC";
    factoryLiveMap["key5_modline2_note"] = 60;
    factoryLiveMap["key5_modline2_velocity"] = 127;
    factoryLiveMap["key5_modline2_cc"] = 65;
    factoryLiveMap["key5_modline2_mmcid"] = 0;
    factoryLiveMap["key5_modline2_mmcfunction"] = "Stop";
    factoryLiveMap["key5_modline2_channel"] = 1;
    factoryLiveMap["key5_modline2_device"] = "SoftStep_Expander";
    factoryLiveMap["key5_modline2_ledgreen"] = "None";
    factoryLiveMap["key5_modline2_ledred"] = "None";
    factoryLiveMap["key5_modline2_displaylinked"] = 0;
    factoryLiveMap["key5_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryLiveMap["key5_modline3_enable"] = 0;
    factoryLiveMap["key5_modline3_source"] = "None";
    factoryLiveMap["key5_modline3_gain"] = 0.00;
    factoryLiveMap["key5_modline3_offset"] = 0.00;
    factoryLiveMap["key5_modline3_table"] = "1_Lin";
    factoryLiveMap["key5_modline3_min"] = 0;
    factoryLiveMap["key5_modline3_max"] = 127;
    factoryLiveMap["key5_modline3_slew"] = 0;
    factoryLiveMap["key5_modline3_destination"] = "None";
    factoryLiveMap["key5_modline3_note"] = 60;
    factoryLiveMap["key5_modline3_velocity"] = 127;
    factoryLiveMap["key5_modline3_cc"] = 1;
    factoryLiveMap["key5_modline3_mmcid"] = 0;
    factoryLiveMap["key5_modline3_mmcfunction"] = "Stop";
    factoryLiveMap["key5_modline3_channel"] = 0;
    factoryLiveMap["key5_modline3_device"] = "SSCOM_Port_1";
    factoryLiveMap["key5_modline3_ledgreen"] = "None";
    factoryLiveMap["key5_modline3_ledred"] = "None";
    factoryLiveMap["key5_modline3_displaylinked"] = 0;
    factoryLiveMap["key5_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryLiveMap["key5_modline4_enable"] = 0;
    factoryLiveMap["key5_modline4_source"] = "None";
    factoryLiveMap["key5_modline4_gain"] = 0.00;
    factoryLiveMap["key5_modline4_offset"] = 0.00;
    factoryLiveMap["key5_modline4_table"] = "1_Lin";
    factoryLiveMap["key5_modline4_min"] = 0;
    factoryLiveMap["key5_modline4_max"] = 127;
    factoryLiveMap["key5_modline4_slew"] = 0;
    factoryLiveMap["key5_modline4_destination"] = "None";
    factoryLiveMap["key5_modline4_note"] = 60;
    factoryLiveMap["key5_modline4_velocity"] = 127;
    factoryLiveMap["key5_modline4_cc"] = 1;
    factoryLiveMap["key5_modline4_mmcid"] = 0;
    factoryLiveMap["key5_modline4_mmcfunction"] = "Stop";
    factoryLiveMap["key5_modline4_channel"] = 0;
    factoryLiveMap["key5_modline4_device"] = "SSCOM_Port_1";
    factoryLiveMap["key5_modline4_ledgreen"] = "None";
    factoryLiveMap["key5_modline4_ledred"] = "None";
    factoryLiveMap["key5_modline4_displaylinked"] = 0;
    factoryLiveMap["key5_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryLiveMap["key5_modline5_enable"] = 0;
    factoryLiveMap["key5_modline5_source"] = "None";
    factoryLiveMap["key5_modline5_gain"] = 0.00;
    factoryLiveMap["key5_modline5_offset"] = 0.00;
    factoryLiveMap["key5_modline5_table"] = "1_Lin";
    factoryLiveMap["key5_modline5_min"] = 0;
    factoryLiveMap["key5_modline5_max"] = 127;
    factoryLiveMap["key5_modline5_slew"] = 0;
    factoryLiveMap["key5_modline5_destination"] = "None";
    factoryLiveMap["key5_modline5_note"] = 60;
    factoryLiveMap["key5_modline5_velocity"] = 127;
    factoryLiveMap["key5_modline5_cc"] = 1;
    factoryLiveMap["key5_modline5_mmcid"] = 0;
    factoryLiveMap["key5_modline5_mmcfunction"] = "Stop";
    factoryLiveMap["key5_modline5_channel"] = 0;
    factoryLiveMap["key5_modline5_device"] = "SSCOM_Port_1";
    factoryLiveMap["key5_modline5_ledgreen"] = "None";
    factoryLiveMap["key5_modline5_ledred"] = "None";
    factoryLiveMap["key5_modline5_displaylinked"] = 0;
    factoryLiveMap["key5_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryLiveMap["key5_modline6_enable"] = 0;
    factoryLiveMap["key5_modline6_source"] = "None";
    factoryLiveMap["key5_modline6_gain"] = 0.00;
    factoryLiveMap["key5_modline6_offset"] = 0.00;
    factoryLiveMap["key5_modline6_table"] = "1_Lin";
    factoryLiveMap["key5_modline6_min"] = 0;
    factoryLiveMap["key5_modline6_max"] = 127;
    factoryLiveMap["key5_modline6_slew"] = 0;
    factoryLiveMap["key5_modline6_destination"] = "None";
    factoryLiveMap["key5_modline6_note"] = 60;
    factoryLiveMap["key5_modline6_velocity"] = 127;
    factoryLiveMap["key5_modline6_cc"] = 1;
    factoryLiveMap["key5_modline6_mmcid"] = 0;
    factoryLiveMap["key5_modline6_mmcfunction"] = "Stop";
    factoryLiveMap["key5_modline6_channel"] = 0;
    factoryLiveMap["key5_modline6_device"] = "SSCOM_Port_1";
    factoryLiveMap["key5_modline6_ledgreen"] = "None";
    factoryLiveMap["key5_modline6_ledred"] = "None";
    factoryLiveMap["key5_modline6_displaylinked"] = 0;
    factoryLiveMap["key5_modline6_reminder"] = "";


    //------------------------ Key 6 ------------------------//
    factoryLiveMap["key6_name"] = "PLAY";
    factoryLiveMap["key6_displaymode"] = 1;
    factoryLiveMap["key6_prefix"] = "";
    factoryLiveMap["key6_counter_min"] = 0;
    factoryLiveMap["key6_counter_max"] = 127;
    factoryLiveMap["key6_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryLiveMap["key6_modline1_enable"] = 1;
    factoryLiveMap["key6_modline1_source"] = "Foot_On";
    factoryLiveMap["key6_modline1_gain"] = 1.00;
    factoryLiveMap["key6_modline1_offset"] = 0.00;
    factoryLiveMap["key6_modline1_table"] = "1_Lin";
    factoryLiveMap["key6_modline1_min"] = 0;
    factoryLiveMap["key6_modline1_max"] = 127;
    factoryLiveMap["key6_modline1_slew"] = 0;
    factoryLiveMap["key6_modline1_destination"] = "CC";
    factoryLiveMap["key6_modline1_note"] = 60;
    factoryLiveMap["key6_modline1_velocity"] = 127;
    factoryLiveMap["key6_modline1_cc"] = 66;
    factoryLiveMap["key6_modline1_mmcid"] = 0;
    factoryLiveMap["key6_modline1_mmcfunction"] = "Stop";
    factoryLiveMap["key6_modline1_channel"] = 1;
    factoryLiveMap["key6_modline1_device"] = "SSCOM_Port_1";
    factoryLiveMap["key6_modline1_ledgreen"] = "None";
    factoryLiveMap["key6_modline1_ledred"] = "None";
    factoryLiveMap["key6_modline1_displaylinked"] = 1;
    factoryLiveMap["key6_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryLiveMap["key6_modline2_enable"] = 1;
    factoryLiveMap["key6_modline2_source"] = "Foot_On";
    factoryLiveMap["key6_modline2_gain"] = 1.00;
    factoryLiveMap["key6_modline2_offset"] = 0.00;
    factoryLiveMap["key6_modline2_table"] = "1_Lin";
    factoryLiveMap["key6_modline2_min"] = 0;
    factoryLiveMap["key6_modline2_max"] = 127;
    factoryLiveMap["key6_modline2_slew"] = 0;
    factoryLiveMap["key6_modline2_destination"] = "CC";
    factoryLiveMap["key6_modline2_note"] = 60;
    factoryLiveMap["key6_modline2_velocity"] = 127;
    factoryLiveMap["key6_modline2_cc"] = 66;
    factoryLiveMap["key6_modline2_mmcid"] = 0;
    factoryLiveMap["key6_modline2_mmcfunction"] = "Stop";
    factoryLiveMap["key6_modline2_channel"] = 1;
    factoryLiveMap["key6_modline2_device"] = "SoftStep_Expander";
    factoryLiveMap["key6_modline2_ledgreen"] = "None";
    factoryLiveMap["key6_modline2_ledred"] = "None";
    factoryLiveMap["key6_modline2_displaylinked"] = 0;
    factoryLiveMap["key6_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryLiveMap["key6_modline3_enable"] = 1;
    factoryLiveMap["key6_modline3_source"] = "Key 6 Pressed";
    factoryLiveMap["key6_modline3_gain"] = 1.00;
    factoryLiveMap["key6_modline3_offset"] = 0.00;
    factoryLiveMap["key6_modline3_table"] = "1_Lin";
    factoryLiveMap["key6_modline3_min"] = 0;
    factoryLiveMap["key6_modline3_max"] = 127;
    factoryLiveMap["key6_modline3_slew"] = 0;
    factoryLiveMap["key6_modline3_destination"] = "None";
    factoryLiveMap["key6_modline3_note"] = 60;
    factoryLiveMap["key6_modline3_velocity"] = 127;
    factoryLiveMap["key6_modline3_cc"] = 1;
    factoryLiveMap["key6_modline3_mmcid"] = 0;
    factoryLiveMap["key6_modline3_mmcfunction"] = "Stop";
    factoryLiveMap["key6_modline3_channel"] = 0;
    factoryLiveMap["key6_modline3_device"] = "SSCOM_Port_1";
    factoryLiveMap["key6_modline3_ledgreen"] = "True";
    factoryLiveMap["key6_modline3_ledred"] = "None";
    factoryLiveMap["key6_modline3_displaylinked"] = 0;
    factoryLiveMap["key6_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryLiveMap["key6_modline4_enable"] = 1;
    factoryLiveMap["key6_modline4_source"] = "Key 7 Pressed";
    factoryLiveMap["key6_modline4_gain"] = 1.00;
    factoryLiveMap["key6_modline4_offset"] = 0.00;
    factoryLiveMap["key6_modline4_table"] = "1_Lin";
    factoryLiveMap["key6_modline4_min"] = 0;
    factoryLiveMap["key6_modline4_max"] = 127;
    factoryLiveMap["key6_modline4_slew"] = 0;
    factoryLiveMap["key6_modline4_destination"] = "None";
    factoryLiveMap["key6_modline4_note"] = 60;
    factoryLiveMap["key6_modline4_velocity"] = 127;
    factoryLiveMap["key6_modline4_cc"] = 1;
    factoryLiveMap["key6_modline4_mmcid"] = 0;
    factoryLiveMap["key6_modline4_mmcfunction"] = "Stop";
    factoryLiveMap["key6_modline4_channel"] = 0;
    factoryLiveMap["key6_modline4_device"] = "SSCOM_Port_1";
    factoryLiveMap["key6_modline4_ledgreen"] = "Off";
    factoryLiveMap["key6_modline4_ledred"] = "None";
    factoryLiveMap["key6_modline4_displaylinked"] = 0;
    factoryLiveMap["key6_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryLiveMap["key6_modline5_enable"] = 0;
    factoryLiveMap["key6_modline5_source"] = "None";
    factoryLiveMap["key6_modline5_gain"] = 0.00;
    factoryLiveMap["key6_modline5_offset"] = 0.00;
    factoryLiveMap["key6_modline5_table"] = "1_Lin";
    factoryLiveMap["key6_modline5_min"] = 0;
    factoryLiveMap["key6_modline5_max"] = 127;
    factoryLiveMap["key6_modline5_slew"] = 0;
    factoryLiveMap["key6_modline5_destination"] = "None";
    factoryLiveMap["key6_modline5_note"] = 60;
    factoryLiveMap["key6_modline5_velocity"] = 127;
    factoryLiveMap["key6_modline5_cc"] = 1;
    factoryLiveMap["key6_modline5_mmcid"] = 0;
    factoryLiveMap["key6_modline5_mmcfunction"] = "Stop";
    factoryLiveMap["key6_modline5_channel"] = 0;
    factoryLiveMap["key6_modline5_device"] = "SSCOM_Port_1";
    factoryLiveMap["key6_modline5_ledgreen"] = "None";
    factoryLiveMap["key6_modline5_ledred"] = "None";
    factoryLiveMap["key6_modline5_displaylinked"] = 0;
    factoryLiveMap["key6_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryLiveMap["key6_modline6_enable"] = 0;
    factoryLiveMap["key6_modline6_source"] = "None";
    factoryLiveMap["key6_modline6_gain"] = 0.00;
    factoryLiveMap["key6_modline6_offset"] = 0.00;
    factoryLiveMap["key6_modline6_table"] = "1_Lin";
    factoryLiveMap["key6_modline6_min"] = 0;
    factoryLiveMap["key6_modline6_max"] = 127;
    factoryLiveMap["key6_modline6_slew"] = 0;
    factoryLiveMap["key6_modline6_destination"] = "None";
    factoryLiveMap["key6_modline6_note"] = 60;
    factoryLiveMap["key6_modline6_velocity"] = 127;
    factoryLiveMap["key6_modline6_cc"] = 1;
    factoryLiveMap["key6_modline6_mmcid"] = 0;
    factoryLiveMap["key6_modline6_mmcfunction"] = "Stop";
    factoryLiveMap["key6_modline6_channel"] = 0;
    factoryLiveMap["key6_modline6_device"] = "SSCOM_Port_1";
    factoryLiveMap["key6_modline6_ledgreen"] = "None";
    factoryLiveMap["key6_modline6_ledred"] = "None";
    factoryLiveMap["key6_modline6_displaylinked"] = 0;
    factoryLiveMap["key6_modline6_reminder"] = "";


    //------------------------ Key 7 ------------------------//
    factoryLiveMap["key7_name"] = "STOP";
    factoryLiveMap["key7_displaymode"] = 1;
    factoryLiveMap["key7_prefix"] = "";
    factoryLiveMap["key7_counter_min"] = 0;
    factoryLiveMap["key7_counter_max"] = 127;
    factoryLiveMap["key7_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryLiveMap["key7_modline1_enable"] = 1;
    factoryLiveMap["key7_modline1_source"] = "Foot_On";
    factoryLiveMap["key7_modline1_gain"] = 1.00;
    factoryLiveMap["key7_modline1_offset"] = 0.00;
    factoryLiveMap["key7_modline1_table"] = "1_Lin";
    factoryLiveMap["key7_modline1_min"] = 0;
    factoryLiveMap["key7_modline1_max"] = 127;
    factoryLiveMap["key7_modline1_slew"] = 0;
    factoryLiveMap["key7_modline1_destination"] = "CC";
    factoryLiveMap["key7_modline1_note"] = 60;
    factoryLiveMap["key7_modline1_velocity"] = 127;
    factoryLiveMap["key7_modline1_cc"] = 67;
    factoryLiveMap["key7_modline1_mmcid"] = 0;
    factoryLiveMap["key7_modline1_mmcfunction"] = "Stop";
    factoryLiveMap["key7_modline1_channel"] = 1;
    factoryLiveMap["key7_modline1_device"] = "SSCOM_Port_1";
    factoryLiveMap["key7_modline1_ledgreen"] = "None";
    factoryLiveMap["key7_modline1_ledred"] = "None";
    factoryLiveMap["key7_modline1_displaylinked"] = 1;
    factoryLiveMap["key7_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryLiveMap["key7_modline2_enable"] = 1;
    factoryLiveMap["key7_modline2_source"] = "Foot_On";
    factoryLiveMap["key7_modline2_gain"] = 1.00;
    factoryLiveMap["key7_modline2_offset"] = 0.00;
    factoryLiveMap["key7_modline2_table"] = "1_Lin";
    factoryLiveMap["key7_modline2_min"] = 0;
    factoryLiveMap["key7_modline2_max"] = 127;
    factoryLiveMap["key7_modline2_slew"] = 0;
    factoryLiveMap["key7_modline2_destination"] = "CC";
    factoryLiveMap["key7_modline2_note"] = 60;
    factoryLiveMap["key7_modline2_velocity"] = 127;
    factoryLiveMap["key7_modline2_cc"] = 67;
    factoryLiveMap["key7_modline2_mmcid"] = 0;
    factoryLiveMap["key7_modline2_mmcfunction"] = "Stop";
    factoryLiveMap["key7_modline2_channel"] = 1;
    factoryLiveMap["key7_modline2_device"] = "SoftStep_Expander";
    factoryLiveMap["key7_modline2_ledgreen"] = "None";
    factoryLiveMap["key7_modline2_ledred"] = "None";
    factoryLiveMap["key7_modline2_displaylinked"] = 0;
    factoryLiveMap["key7_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryLiveMap["key7_modline3_enable"] = 0;
    factoryLiveMap["key7_modline3_source"] = "None";
    factoryLiveMap["key7_modline3_gain"] = 0.00;
    factoryLiveMap["key7_modline3_offset"] = 0.00;
    factoryLiveMap["key7_modline3_table"] = "1_Lin";
    factoryLiveMap["key7_modline3_min"] = 0;
    factoryLiveMap["key7_modline3_max"] = 127;
    factoryLiveMap["key7_modline3_slew"] = 0;
    factoryLiveMap["key7_modline3_destination"] = "None";
    factoryLiveMap["key7_modline3_note"] = 60;
    factoryLiveMap["key7_modline3_velocity"] = 127;
    factoryLiveMap["key7_modline3_cc"] = 1;
    factoryLiveMap["key7_modline3_mmcid"] = 0;
    factoryLiveMap["key7_modline3_mmcfunction"] = "Stop";
    factoryLiveMap["key7_modline3_channel"] = 0;
    factoryLiveMap["key7_modline3_device"] = "SSCOM_Port_1";
    factoryLiveMap["key7_modline3_ledgreen"] = "None";
    factoryLiveMap["key7_modline3_ledred"] = "None";
    factoryLiveMap["key7_modline3_displaylinked"] = 0;
    factoryLiveMap["key7_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryLiveMap["key7_modline4_enable"] = 0;
    factoryLiveMap["key7_modline4_source"] = "None";
    factoryLiveMap["key7_modline4_gain"] = 0.00;
    factoryLiveMap["key7_modline4_offset"] = 0.00;
    factoryLiveMap["key7_modline4_table"] = "1_Lin";
    factoryLiveMap["key7_modline4_min"] = 0;
    factoryLiveMap["key7_modline4_max"] = 127;
    factoryLiveMap["key7_modline4_slew"] = 0;
    factoryLiveMap["key7_modline4_destination"] = "None";
    factoryLiveMap["key7_modline4_note"] = 60;
    factoryLiveMap["key7_modline4_velocity"] = 127;
    factoryLiveMap["key7_modline4_cc"] = 1;
    factoryLiveMap["key7_modline4_mmcid"] = 0;
    factoryLiveMap["key7_modline4_mmcfunction"] = "Stop";
    factoryLiveMap["key7_modline4_channel"] = 0;
    factoryLiveMap["key7_modline4_device"] = "SSCOM_Port_1";
    factoryLiveMap["key7_modline4_ledgreen"] = "None";
    factoryLiveMap["key7_modline4_ledred"] = "None";
    factoryLiveMap["key7_modline4_displaylinked"] = 0;
    factoryLiveMap["key7_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryLiveMap["key7_modline5_enable"] = 0;
    factoryLiveMap["key7_modline5_source"] = "None";
    factoryLiveMap["key7_modline5_gain"] = 0.00;
    factoryLiveMap["key7_modline5_offset"] = 0.00;
    factoryLiveMap["key7_modline5_table"] = "1_Lin";
    factoryLiveMap["key7_modline5_min"] = 0;
    factoryLiveMap["key7_modline5_max"] = 127;
    factoryLiveMap["key7_modline5_slew"] = 0;
    factoryLiveMap["key7_modline5_destination"] = "None";
    factoryLiveMap["key7_modline5_note"] = 60;
    factoryLiveMap["key7_modline5_velocity"] = 127;
    factoryLiveMap["key7_modline5_cc"] = 1;
    factoryLiveMap["key7_modline5_mmcid"] = 0;
    factoryLiveMap["key7_modline5_mmcfunction"] = "Stop";
    factoryLiveMap["key7_modline5_channel"] = 0;
    factoryLiveMap["key7_modline5_device"] = "SSCOM_Port_1";
    factoryLiveMap["key7_modline5_ledgreen"] = "None";
    factoryLiveMap["key7_modline5_ledred"] = "None";
    factoryLiveMap["key7_modline5_displaylinked"] = 0;
    factoryLiveMap["key7_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryLiveMap["key7_modline6_enable"] = 0;
    factoryLiveMap["key7_modline6_source"] = "None";
    factoryLiveMap["key7_modline6_gain"] = 0.00;
    factoryLiveMap["key7_modline6_offset"] = 0.00;
    factoryLiveMap["key7_modline6_table"] = "1_Lin";
    factoryLiveMap["key7_modline6_min"] = 0;
    factoryLiveMap["key7_modline6_max"] = 127;
    factoryLiveMap["key7_modline6_slew"] = 0;
    factoryLiveMap["key7_modline6_destination"] = "None";
    factoryLiveMap["key7_modline6_note"] = 60;
    factoryLiveMap["key7_modline6_velocity"] = 127;
    factoryLiveMap["key7_modline6_cc"] = 1;
    factoryLiveMap["key7_modline6_mmcid"] = 0;
    factoryLiveMap["key7_modline6_mmcfunction"] = "Stop";
    factoryLiveMap["key7_modline6_channel"] = 0;
    factoryLiveMap["key7_modline6_device"] = "SSCOM_Port_1";
    factoryLiveMap["key7_modline6_ledgreen"] = "None";
    factoryLiveMap["key7_modline6_ledred"] = "None";
    factoryLiveMap["key7_modline6_displaylinked"] = 0;
    factoryLiveMap["key7_modline6_reminder"] = "";


    //------------------------ Key 8 ------------------------//
    factoryLiveMap["key8_name"] = "REC";
    factoryLiveMap["key8_displaymode"] = 1;
    factoryLiveMap["key8_prefix"] = "";
    factoryLiveMap["key8_counter_min"] = 0;
    factoryLiveMap["key8_counter_max"] = 127;
    factoryLiveMap["key8_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryLiveMap["key8_modline1_enable"] = 1;
    factoryLiveMap["key8_modline1_source"] = "Foot_On";
    factoryLiveMap["key8_modline1_gain"] = 1.00;
    factoryLiveMap["key8_modline1_offset"] = 0.00;
    factoryLiveMap["key8_modline1_table"] = "1_Lin";
    factoryLiveMap["key8_modline1_min"] = 0;
    factoryLiveMap["key8_modline1_max"] = 127;
    factoryLiveMap["key8_modline1_slew"] = 0;
    factoryLiveMap["key8_modline1_destination"] = "CC";
    factoryLiveMap["key8_modline1_note"] = 60;
    factoryLiveMap["key8_modline1_velocity"] = 127;
    factoryLiveMap["key8_modline1_cc"] = 68;
    factoryLiveMap["key8_modline1_mmcid"] = 0;
    factoryLiveMap["key8_modline1_mmcfunction"] = "Stop";
    factoryLiveMap["key8_modline1_channel"] = 1;
    factoryLiveMap["key8_modline1_device"] = "SSCOM_Port_1";
    factoryLiveMap["key8_modline1_ledgreen"] = "None";
    factoryLiveMap["key8_modline1_ledred"] = "None";
    factoryLiveMap["key8_modline1_displaylinked"] = 1;
    factoryLiveMap["key8_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryLiveMap["key8_modline2_enable"] = 1;
    factoryLiveMap["key8_modline2_source"] = "Foot_On";
    factoryLiveMap["key8_modline2_gain"] = 1.00;
    factoryLiveMap["key8_modline2_offset"] = 0.00;
    factoryLiveMap["key8_modline2_table"] = "1_Lin";
    factoryLiveMap["key8_modline2_min"] = 0;
    factoryLiveMap["key8_modline2_max"] = 127;
    factoryLiveMap["key8_modline2_slew"] = 0;
    factoryLiveMap["key8_modline2_destination"] = "CC";
    factoryLiveMap["key8_modline2_note"] = 60;
    factoryLiveMap["key8_modline2_velocity"] = 127;
    factoryLiveMap["key8_modline2_cc"] = 68;
    factoryLiveMap["key8_modline2_mmcid"] = 0;
    factoryLiveMap["key8_modline2_mmcfunction"] = "Stop";
    factoryLiveMap["key8_modline2_channel"] = 1;
    factoryLiveMap["key8_modline2_device"] = "SoftStep_Expander";
    factoryLiveMap["key8_modline2_ledgreen"] = "None";
    factoryLiveMap["key8_modline2_ledred"] = "None";
    factoryLiveMap["key8_modline2_displaylinked"] = 0;
    factoryLiveMap["key8_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryLiveMap["key8_modline3_enable"] = 1;
    factoryLiveMap["key8_modline3_source"] = "Key 8 Pressed";
    factoryLiveMap["key8_modline3_gain"] = 1.00;
    factoryLiveMap["key8_modline3_offset"] = 0.00;
    factoryLiveMap["key8_modline3_table"] = "1_Lin";
    factoryLiveMap["key8_modline3_min"] = 0;
    factoryLiveMap["key8_modline3_max"] = 127;
    factoryLiveMap["key8_modline3_slew"] = 0;
    factoryLiveMap["key8_modline3_destination"] = "None";
    factoryLiveMap["key8_modline3_note"] = 60;
    factoryLiveMap["key8_modline3_velocity"] = 127;
    factoryLiveMap["key8_modline3_cc"] = 1;
    factoryLiveMap["key8_modline3_mmcid"] = 0;
    factoryLiveMap["key8_modline3_mmcfunction"] = "Stop";
    factoryLiveMap["key8_modline3_channel"] = 0;
    factoryLiveMap["key8_modline3_device"] = "SSCOM_Port_1";
    factoryLiveMap["key8_modline3_ledgreen"] = "None";
    factoryLiveMap["key8_modline3_ledred"] = "True";
    factoryLiveMap["key8_modline3_displaylinked"] = 0;
    factoryLiveMap["key8_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryLiveMap["key8_modline4_enable"] = 1;
    factoryLiveMap["key8_modline4_source"] = "Key 7 Pressed";
    factoryLiveMap["key8_modline4_gain"] = 1.00;
    factoryLiveMap["key8_modline4_offset"] = 0.00;
    factoryLiveMap["key8_modline4_table"] = "1_Lin";
    factoryLiveMap["key8_modline4_min"] = 0;
    factoryLiveMap["key8_modline4_max"] = 127;
    factoryLiveMap["key8_modline4_slew"] = 0;
    factoryLiveMap["key8_modline4_destination"] = "None";
    factoryLiveMap["key8_modline4_note"] = 60;
    factoryLiveMap["key8_modline4_velocity"] = 127;
    factoryLiveMap["key8_modline4_cc"] = 1;
    factoryLiveMap["key8_modline4_mmcid"] = 0;
    factoryLiveMap["key8_modline4_mmcfunction"] = "Stop";
    factoryLiveMap["key8_modline4_channel"] = 0;
    factoryLiveMap["key8_modline4_device"] = "SSCOM_Port_1";
    factoryLiveMap["key8_modline4_ledgreen"] = "None";
    factoryLiveMap["key8_modline4_ledred"] = "Off";
    factoryLiveMap["key8_modline4_displaylinked"] = 0;
    factoryLiveMap["key8_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryLiveMap["key8_modline5_enable"] = 1;
    factoryLiveMap["key8_modline5_source"] = "Key 9 Pressed";
    factoryLiveMap["key8_modline5_gain"] = 1.00;
    factoryLiveMap["key8_modline5_offset"] = 0.00;
    factoryLiveMap["key8_modline5_table"] = "1_Lin";
    factoryLiveMap["key8_modline5_min"] = 0;
    factoryLiveMap["key8_modline5_max"] = 127;
    factoryLiveMap["key8_modline5_slew"] = 0;
    factoryLiveMap["key8_modline5_destination"] = "None";
    factoryLiveMap["key8_modline5_note"] = 60;
    factoryLiveMap["key8_modline5_velocity"] = 127;
    factoryLiveMap["key8_modline5_cc"] = 1;
    factoryLiveMap["key8_modline5_mmcid"] = 0;
    factoryLiveMap["key8_modline5_mmcfunction"] = "Stop";
    factoryLiveMap["key8_modline5_channel"] = 0;
    factoryLiveMap["key8_modline5_device"] = "SSCOM_Port_1";
    factoryLiveMap["key8_modline5_ledgreen"] = "None";
    factoryLiveMap["key8_modline5_ledred"] = "Off";
    factoryLiveMap["key8_modline5_displaylinked"] = 0;
    factoryLiveMap["key8_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryLiveMap["key8_modline6_enable"] = 1;
    factoryLiveMap["key8_modline6_source"] = "Key 0 Pressed";
    factoryLiveMap["key8_modline6_gain"] = 1.00;
    factoryLiveMap["key8_modline6_offset"] = 0.00;
    factoryLiveMap["key8_modline6_table"] = "1_Lin";
    factoryLiveMap["key8_modline6_min"] = 0;
    factoryLiveMap["key8_modline6_max"] = 127;
    factoryLiveMap["key8_modline6_slew"] = 0;
    factoryLiveMap["key8_modline6_destination"] = "None";
    factoryLiveMap["key8_modline6_note"] = 60;
    factoryLiveMap["key8_modline6_velocity"] = 127;
    factoryLiveMap["key8_modline6_cc"] = 1;
    factoryLiveMap["key8_modline6_mmcid"] = 0;
    factoryLiveMap["key8_modline6_mmcfunction"] = "Stop";
    factoryLiveMap["key8_modline6_channel"] = 0;
    factoryLiveMap["key8_modline6_device"] = "SSCOM_Port_1";
    factoryLiveMap["key8_modline6_ledgreen"] = "None";
    factoryLiveMap["key8_modline6_ledred"] = "Off";
    factoryLiveMap["key8_modline6_displaylinked"] = 0;
    factoryLiveMap["key8_modline6_reminder"] = "";


    //------------------------ Key 9 ------------------------//
    factoryLiveMap["key9_name"] = "RWND";
    factoryLiveMap["key9_displaymode"] = 1;
    factoryLiveMap["key9_prefix"] = "";
    factoryLiveMap["key9_counter_min"] = 0;
    factoryLiveMap["key9_counter_max"] = 127;
    factoryLiveMap["key9_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryLiveMap["key9_modline1_enable"] = 1;
    factoryLiveMap["key9_modline1_source"] = "Foot_On";
    factoryLiveMap["key9_modline1_gain"] = 1.00;
    factoryLiveMap["key9_modline1_offset"] = 0.00;
    factoryLiveMap["key9_modline1_table"] = "1_Lin";
    factoryLiveMap["key9_modline1_min"] = 0;
    factoryLiveMap["key9_modline1_max"] = 127;
    factoryLiveMap["key9_modline1_slew"] = 0;
    factoryLiveMap["key9_modline1_destination"] = "CC";
    factoryLiveMap["key9_modline1_note"] = 60;
    factoryLiveMap["key9_modline1_velocity"] = 127;
    factoryLiveMap["key9_modline1_cc"] = 69;
    factoryLiveMap["key9_modline1_mmcid"] = 0;
    factoryLiveMap["key9_modline1_mmcfunction"] = "Stop";
    factoryLiveMap["key9_modline1_channel"] = 1;
    factoryLiveMap["key9_modline1_device"] = "SSCOM_Port_1";
    factoryLiveMap["key9_modline1_ledgreen"] = "True";
    factoryLiveMap["key9_modline1_ledred"] = "None";
    factoryLiveMap["key9_modline1_displaylinked"] = 1;
    factoryLiveMap["key9_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryLiveMap["key9_modline2_enable"] = 1;
    factoryLiveMap["key9_modline2_source"] = "Foot_On";
    factoryLiveMap["key9_modline2_gain"] = 1.00;
    factoryLiveMap["key9_modline2_offset"] = 0.00;
    factoryLiveMap["key9_modline2_table"] = "1_Lin";
    factoryLiveMap["key9_modline2_min"] = 0;
    factoryLiveMap["key9_modline2_max"] = 127;
    factoryLiveMap["key9_modline2_slew"] = 0;
    factoryLiveMap["key9_modline2_destination"] = "CC";
    factoryLiveMap["key9_modline2_note"] = 60;
    factoryLiveMap["key9_modline2_velocity"] = 127;
    factoryLiveMap["key9_modline2_cc"] = 69;
    factoryLiveMap["key9_modline2_mmcid"] = 0;
    factoryLiveMap["key9_modline2_mmcfunction"] = "Stop";
    factoryLiveMap["key9_modline2_channel"] = 1;
    factoryLiveMap["key9_modline2_device"] = "SoftStep_Expander";
    factoryLiveMap["key9_modline2_ledgreen"] = "None";
    factoryLiveMap["key9_modline2_ledred"] = "None";
    factoryLiveMap["key9_modline2_displaylinked"] = 0;
    factoryLiveMap["key9_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryLiveMap["key9_modline3_enable"] = 0;
    factoryLiveMap["key9_modline3_source"] = "None";
    factoryLiveMap["key9_modline3_gain"] = 0.00;
    factoryLiveMap["key9_modline3_offset"] = 0.00;
    factoryLiveMap["key9_modline3_table"] = "1_Lin";
    factoryLiveMap["key9_modline3_min"] = 0;
    factoryLiveMap["key9_modline3_max"] = 127;
    factoryLiveMap["key9_modline3_slew"] = 0;
    factoryLiveMap["key9_modline3_destination"] = "None";
    factoryLiveMap["key9_modline3_note"] = 60;
    factoryLiveMap["key9_modline3_velocity"] = 127;
    factoryLiveMap["key9_modline3_cc"] = 1;
    factoryLiveMap["key9_modline3_mmcid"] = 0;
    factoryLiveMap["key9_modline3_mmcfunction"] = "Stop";
    factoryLiveMap["key9_modline3_channel"] = 0;
    factoryLiveMap["key9_modline3_device"] = "SSCOM_Port_1";
    factoryLiveMap["key9_modline3_ledgreen"] = "None";
    factoryLiveMap["key9_modline3_ledred"] = "None";
    factoryLiveMap["key9_modline3_displaylinked"] = 0;
    factoryLiveMap["key9_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryLiveMap["key9_modline4_enable"] = 0;
    factoryLiveMap["key9_modline4_source"] = "None";
    factoryLiveMap["key9_modline4_gain"] = 0.00;
    factoryLiveMap["key9_modline4_offset"] = 0.00;
    factoryLiveMap["key9_modline4_table"] = "1_Lin";
    factoryLiveMap["key9_modline4_min"] = 0;
    factoryLiveMap["key9_modline4_max"] = 127;
    factoryLiveMap["key9_modline4_slew"] = 0;
    factoryLiveMap["key9_modline4_destination"] = "None";
    factoryLiveMap["key9_modline4_note"] = 60;
    factoryLiveMap["key9_modline4_velocity"] = 127;
    factoryLiveMap["key9_modline4_cc"] = 1;
    factoryLiveMap["key9_modline4_mmcid"] = 0;
    factoryLiveMap["key9_modline4_mmcfunction"] = "Stop";
    factoryLiveMap["key9_modline4_channel"] = 0;
    factoryLiveMap["key9_modline4_device"] = "SSCOM_Port_1";
    factoryLiveMap["key9_modline4_ledgreen"] = "None";
    factoryLiveMap["key9_modline4_ledred"] = "None";
    factoryLiveMap["key9_modline4_displaylinked"] = 0;
    factoryLiveMap["key9_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryLiveMap["key9_modline5_enable"] = 0;
    factoryLiveMap["key9_modline5_source"] = "None";
    factoryLiveMap["key9_modline5_gain"] = 0.00;
    factoryLiveMap["key9_modline5_offset"] = 0.00;
    factoryLiveMap["key9_modline5_table"] = "1_Lin";
    factoryLiveMap["key9_modline5_min"] = 0;
    factoryLiveMap["key9_modline5_max"] = 127;
    factoryLiveMap["key9_modline5_slew"] = 0;
    factoryLiveMap["key9_modline5_destination"] = "None";
    factoryLiveMap["key9_modline5_note"] = 60;
    factoryLiveMap["key9_modline5_velocity"] = 127;
    factoryLiveMap["key9_modline5_cc"] = 1;
    factoryLiveMap["key9_modline5_mmcid"] = 0;
    factoryLiveMap["key9_modline5_mmcfunction"] = "Stop";
    factoryLiveMap["key9_modline5_channel"] = 0;
    factoryLiveMap["key9_modline5_device"] = "SSCOM_Port_1";
    factoryLiveMap["key9_modline5_ledgreen"] = "None";
    factoryLiveMap["key9_modline5_ledred"] = "None";
    factoryLiveMap["key9_modline5_displaylinked"] = 0;
    factoryLiveMap["key9_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryLiveMap["key9_modline6_enable"] = 0;
    factoryLiveMap["key9_modline6_source"] = "None";
    factoryLiveMap["key9_modline6_gain"] = 0.00;
    factoryLiveMap["key9_modline6_offset"] = 0.00;
    factoryLiveMap["key9_modline6_table"] = "1_Lin";
    factoryLiveMap["key9_modline6_min"] = 0;
    factoryLiveMap["key9_modline6_max"] = 127;
    factoryLiveMap["key9_modline6_slew"] = 0;
    factoryLiveMap["key9_modline6_destination"] = "None";
    factoryLiveMap["key9_modline6_note"] = 60;
    factoryLiveMap["key9_modline6_velocity"] = 127;
    factoryLiveMap["key9_modline6_cc"] = 1;
    factoryLiveMap["key9_modline6_mmcid"] = 0;
    factoryLiveMap["key9_modline6_mmcfunction"] = "Stop";
    factoryLiveMap["key9_modline6_channel"] = 0;
    factoryLiveMap["key9_modline6_device"] = "SSCOM_Port_1";
    factoryLiveMap["key9_modline6_ledgreen"] = "None";
    factoryLiveMap["key9_modline6_ledred"] = "None";
    factoryLiveMap["key9_modline6_displaylinked"] = 0;
    factoryLiveMap["key9_modline6_reminder"] = "";


    //------------------------ Key 10 ------------------------//
    factoryLiveMap["key10_name"] = "FFW";
    factoryLiveMap["key10_displaymode"] = 1;
    factoryLiveMap["key10_prefix"] = "";
    factoryLiveMap["key10_counter_min"] = 0;
    factoryLiveMap["key10_counter_max"] = 127;
    factoryLiveMap["key10_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryLiveMap["key10_modline1_enable"] = 1;
    factoryLiveMap["key10_modline1_source"] = "Foot_On";
    factoryLiveMap["key10_modline1_gain"] = 1.00;
    factoryLiveMap["key10_modline1_offset"] = 0.00;
    factoryLiveMap["key10_modline1_table"] = "1_Lin";
    factoryLiveMap["key10_modline1_min"] = 0;
    factoryLiveMap["key10_modline1_max"] = 127;
    factoryLiveMap["key10_modline1_slew"] = 0;
    factoryLiveMap["key10_modline1_destination"] = "CC";
    factoryLiveMap["key10_modline1_note"] = 60;
    factoryLiveMap["key10_modline1_velocity"] = 127;
    factoryLiveMap["key10_modline1_cc"] = 70;
    factoryLiveMap["key10_modline1_mmcid"] = 0;
    factoryLiveMap["key10_modline1_mmcfunction"] = "Stop";
    factoryLiveMap["key10_modline1_channel"] = 1;
    factoryLiveMap["key10_modline1_device"] = "SSCOM_Port_1";
    factoryLiveMap["key10_modline1_ledgreen"] = "True";
    factoryLiveMap["key10_modline1_ledred"] = "None";
    factoryLiveMap["key10_modline1_displaylinked"] = 1;
    factoryLiveMap["key10_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryLiveMap["key10_modline2_enable"] = 1;
    factoryLiveMap["key10_modline2_source"] = "Foot_On";
    factoryLiveMap["key10_modline2_gain"] = 1.00;
    factoryLiveMap["key10_modline2_offset"] = 0.00;
    factoryLiveMap["key10_modline2_table"] = "1_Lin";
    factoryLiveMap["key10_modline2_min"] = 0;
    factoryLiveMap["key10_modline2_max"] = 127;
    factoryLiveMap["key10_modline2_slew"] = 0;
    factoryLiveMap["key10_modline2_destination"] = "CC";
    factoryLiveMap["key10_modline2_note"] = 60;
    factoryLiveMap["key10_modline2_velocity"] = 127;
    factoryLiveMap["key10_modline2_cc"] = 70;
    factoryLiveMap["key10_modline2_mmcid"] = 0;
    factoryLiveMap["key10_modline2_mmcfunction"] = "Stop";
    factoryLiveMap["key10_modline2_channel"] = 1;
    factoryLiveMap["key10_modline2_device"] = "SoftStep_Expander";
    factoryLiveMap["key10_modline2_ledgreen"] = "None";
    factoryLiveMap["key10_modline2_ledred"] = "None";
    factoryLiveMap["key10_modline2_displaylinked"] = 0;
    factoryLiveMap["key10_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryLiveMap["key10_modline3_enable"] = 0;
    factoryLiveMap["key10_modline3_source"] = "None";
    factoryLiveMap["key10_modline3_gain"] = 0.00;
    factoryLiveMap["key10_modline3_offset"] = 0.00;
    factoryLiveMap["key10_modline3_table"] = "1_Lin";
    factoryLiveMap["key10_modline3_min"] = 0;
    factoryLiveMap["key10_modline3_max"] = 127;
    factoryLiveMap["key10_modline3_slew"] = 0;
    factoryLiveMap["key10_modline3_destination"] = "None";
    factoryLiveMap["key10_modline3_note"] = 60;
    factoryLiveMap["key10_modline3_velocity"] = 127;
    factoryLiveMap["key10_modline3_cc"] = 1;
    factoryLiveMap["key10_modline3_mmcid"] = 0;
    factoryLiveMap["key10_modline3_mmcfunction"] = "Stop";
    factoryLiveMap["key10_modline3_channel"] = 0;
    factoryLiveMap["key10_modline3_device"] = "SSCOM_Port_1";
    factoryLiveMap["key10_modline3_ledgreen"] = "None";
    factoryLiveMap["key10_modline3_ledred"] = "None";
    factoryLiveMap["key10_modline3_displaylinked"] = 0;
    factoryLiveMap["key10_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryLiveMap["key10_modline4_enable"] = 0;
    factoryLiveMap["key10_modline4_source"] = "None";
    factoryLiveMap["key10_modline4_gain"] = 0.00;
    factoryLiveMap["key10_modline4_offset"] = 0.00;
    factoryLiveMap["key10_modline4_table"] = "1_Lin";
    factoryLiveMap["key10_modline4_min"] = 0;
    factoryLiveMap["key10_modline4_max"] = 127;
    factoryLiveMap["key10_modline4_slew"] = 0;
    factoryLiveMap["key10_modline4_destination"] = "None";
    factoryLiveMap["key10_modline4_note"] = 60;
    factoryLiveMap["key10_modline4_velocity"] = 127;
    factoryLiveMap["key10_modline4_cc"] = 1;
    factoryLiveMap["key10_modline4_mmcid"] = 0;
    factoryLiveMap["key10_modline4_mmcfunction"] = "Stop";
    factoryLiveMap["key10_modline4_channel"] = 0;
    factoryLiveMap["key10_modline4_device"] = "SSCOM_Port_1";
    factoryLiveMap["key10_modline4_ledgreen"] = "None";
    factoryLiveMap["key10_modline4_ledred"] = "None";
    factoryLiveMap["key10_modline4_displaylinked"] = 0;
    factoryLiveMap["key10_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryLiveMap["key10_modline5_enable"] = 0;
    factoryLiveMap["key10_modline5_source"] = "None";
    factoryLiveMap["key10_modline5_gain"] = 0.00;
    factoryLiveMap["key10_modline5_offset"] = 0.00;
    factoryLiveMap["key10_modline5_table"] = "1_Lin";
    factoryLiveMap["key10_modline5_min"] = 0;
    factoryLiveMap["key10_modline5_max"] = 127;
    factoryLiveMap["key10_modline5_slew"] = 0;
    factoryLiveMap["key10_modline5_destination"] = "None";
    factoryLiveMap["key10_modline5_note"] = 60;
    factoryLiveMap["key10_modline5_velocity"] = 127;
    factoryLiveMap["key10_modline5_cc"] = 1;
    factoryLiveMap["key10_modline5_mmcid"] = 0;
    factoryLiveMap["key10_modline5_mmcfunction"] = "Stop";
    factoryLiveMap["key10_modline5_channel"] = 0;
    factoryLiveMap["key10_modline5_device"] = "SSCOM_Port_1";
    factoryLiveMap["key10_modline5_ledgreen"] = "None";
    factoryLiveMap["key10_modline5_ledred"] = "None";
    factoryLiveMap["key10_modline5_displaylinked"] = 0;
    factoryLiveMap["key10_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryLiveMap["key10_modline6_enable"] = 0;
    factoryLiveMap["key10_modline6_source"] = "None";
    factoryLiveMap["key10_modline6_gain"] = 0.00;
    factoryLiveMap["key10_modline6_offset"] = 0.00;
    factoryLiveMap["key10_modline6_table"] = "1_Lin";
    factoryLiveMap["key10_modline6_min"] = 0;
    factoryLiveMap["key10_modline6_max"] = 127;
    factoryLiveMap["key10_modline6_slew"] = 0;
    factoryLiveMap["key10_modline6_destination"] = "None";
    factoryLiveMap["key10_modline6_note"] = 60;
    factoryLiveMap["key10_modline6_velocity"] = 127;
    factoryLiveMap["key10_modline6_cc"] = 1;
    factoryLiveMap["key10_modline6_mmcid"] = 0;
    factoryLiveMap["key10_modline6_mmcfunction"] = "Stop";
    factoryLiveMap["key10_modline6_channel"] = 0;
    factoryLiveMap["key10_modline6_device"] = "SSCOM_Port_1";
    factoryLiveMap["key10_modline6_ledgreen"] = "None";
    factoryLiveMap["key10_modline6_ledred"] = "None";
    factoryLiveMap["key10_modline6_displaylinked"] = 0;
    factoryLiveMap["key10_modline6_reminder"] = "";


    //------------------------ Nav ------------------------//
    factoryLiveMap["nav_name"] = "MSTR";
    factoryLiveMap["nav_displaymode"] = 4;
    factoryLiveMap["nav_modlinemode"] = 1;
    factoryLiveMap["nav_prefix"] = "M";
    factoryLiveMap["nav_counter_min"] = 0;
    factoryLiveMap["nav_counter_max"] = 127;
    factoryLiveMap["nav_counter_wrap"] = 1;

    //------ Modline 1 ------//
    factoryLiveMap["nav_modline1_enable"] = 1;
    factoryLiveMap["nav_modline1_source"] = "Nav_Y_Inc-Dec";
    factoryLiveMap["nav_modline1_gain"] = 1.00;
    factoryLiveMap["nav_modline1_offset"] = 0.00;
    factoryLiveMap["nav_modline1_table"] = "1_Lin";
    factoryLiveMap["nav_modline1_min"] = 0;
    factoryLiveMap["nav_modline1_max"] = 127;
    factoryLiveMap["nav_modline1_slew"] = 0;
    factoryLiveMap["nav_modline1_destination"] = "CC";
    factoryLiveMap["nav_modline1_note"] = 60;
    factoryLiveMap["nav_modline1_velocity"] = 127;
    factoryLiveMap["nav_modline1_cc"] = 60;
    factoryLiveMap["nav_modline1_mmcid"] = 0;
    factoryLiveMap["nav_modline1_mmcfunction"] = "Stop";
    factoryLiveMap["nav_modline1_channel"] = 1;
    factoryLiveMap["nav_modline1_device"] = "SSCOM_Port_1";
    factoryLiveMap["nav_modline1_displaylinked"] = 1;
    factoryLiveMap["nav_modline1_reminder"] = "";

    //------ Modline 2 ------//
    factoryLiveMap["nav_modline2_enable"] = 1;
    factoryLiveMap["nav_modline2_source"] = "Nav_Y_Inc-Dec";
    factoryLiveMap["nav_modline2_gain"] = 1.00;
    factoryLiveMap["nav_modline2_offset"] = 0.00;
    factoryLiveMap["nav_modline2_table"] = "1_Lin";
    factoryLiveMap["nav_modline2_min"] = 0;
    factoryLiveMap["nav_modline2_max"] = 127;
    factoryLiveMap["nav_modline2_slew"] = 0;
    factoryLiveMap["nav_modline2_destination"] = "CC";
    factoryLiveMap["nav_modline2_note"] = 60;
    factoryLiveMap["nav_modline2_velocity"] = 127;
    factoryLiveMap["nav_modline2_cc"] = 60;
    factoryLiveMap["nav_modline2_mmcid"] = 0;
    factoryLiveMap["nav_modline2_mmcfunction"] = "Stop";
    factoryLiveMap["nav_modline2_channel"] = 1;
    factoryLiveMap["nav_modline2_device"] = "SoftStep_Expander";
    factoryLiveMap["nav_modline2_displaylinked"] = 0;
    factoryLiveMap["nav_modline2_reminder"] = "";

    //------ Modline 3 ------//
    factoryLiveMap["nav_modline3_enable"] = 1;
    factoryLiveMap["nav_modline3_source"] = "Pedal";
    factoryLiveMap["nav_modline3_gain"] = 1.00;
    factoryLiveMap["nav_modline3_offset"] = 0.00;
    factoryLiveMap["nav_modline3_table"] = "1_Lin";
    factoryLiveMap["nav_modline3_min"] = 0;
    factoryLiveMap["nav_modline3_max"] = 127;
    factoryLiveMap["nav_modline3_slew"] = 0;
    factoryLiveMap["nav_modline3_destination"] = "CC";
    factoryLiveMap["nav_modline3_note"] = 60;
    factoryLiveMap["nav_modline3_velocity"] = 127;
    factoryLiveMap["nav_modline3_cc"] = 76;
    factoryLiveMap["nav_modline3_mmcid"] = 0;
    factoryLiveMap["nav_modline3_mmcfunction"] = "Stop";
    factoryLiveMap["nav_modline3_channel"] = 1;
    factoryLiveMap["nav_modline3_device"] = "SSCOM_Port_1";
    factoryLiveMap["nav_modline3_displaylinked"] = 0;
    factoryLiveMap["nav_modline3_reminder"] = "";

    //------ Modline 4 ------//
    factoryLiveMap["nav_modline4_enable"] = 1;
    factoryLiveMap["nav_modline4_source"] = "Pedal";
    factoryLiveMap["nav_modline4_gain"] = 1.00;
    factoryLiveMap["nav_modline4_offset"] = 0.00;
    factoryLiveMap["nav_modline4_table"] = "1_Lin";
    factoryLiveMap["nav_modline4_min"] = 0;
    factoryLiveMap["nav_modline4_max"] = 127;
    factoryLiveMap["nav_modline4_slew"] = 0;
    factoryLiveMap["nav_modline4_destination"] = "CC";
    factoryLiveMap["nav_modline4_note"] = 60;
    factoryLiveMap["nav_modline4_velocity"] = 127;
    factoryLiveMap["nav_modline4_cc"] = 76;
    factoryLiveMap["nav_modline4_mmcid"] = 0;
    factoryLiveMap["nav_modline4_mmcfunction"] = "Stop";
    factoryLiveMap["nav_modline4_channel"] = 1;
    factoryLiveMap["nav_modline4_device"] = "SoftStep_Expander";
    factoryLiveMap["nav_modline4_displaylinked"] = 0;
    factoryLiveMap["nav_modline4_reminder"] = "";

    //------ Modline 5 ------//
    factoryLiveMap["nav_modline5_enable"] = 0;
    factoryLiveMap["nav_modline5_source"] = "None";
    factoryLiveMap["nav_modline5_gain"] = 0.00;
    factoryLiveMap["nav_modline5_offset"] = 0.00;
    factoryLiveMap["nav_modline5_table"] = "1_Lin";
    factoryLiveMap["nav_modline5_min"] = 0;
    factoryLiveMap["nav_modline5_max"] = 127;
    factoryLiveMap["nav_modline5_slew"] = 0;
    factoryLiveMap["nav_modline5_destination"] = "None";
    factoryLiveMap["nav_modline5_note"] = 60;
    factoryLiveMap["nav_modline5_velocity"] = 127;
    factoryLiveMap["nav_modline5_cc"] = 1;
    factoryLiveMap["nav_modline5_mmcid"] = 0;
    factoryLiveMap["nav_modline5_mmcfunction"] = "Stop";
    factoryLiveMap["nav_modline5_channel"] = 0;
    factoryLiveMap["nav_modline5_device"] = "SSCOM_Port_1";
    factoryLiveMap["nav_modline5_displaylinked"] = 0;
    factoryLiveMap["nav_modline5_reminder"] = "";

    //------ Modline 6 ------//
    factoryLiveMap["nav_modline6_enable"] = 0;
    factoryLiveMap["nav_modline6_source"] = "None";
    factoryLiveMap["nav_modline6_gain"] = 0.00;
    factoryLiveMap["nav_modline6_offset"] = 0.00;
    factoryLiveMap["nav_modline6_table"] = "1_Lin";
    factoryLiveMap["nav_modline6_min"] = 0;
    factoryLiveMap["nav_modline6_max"] = 127;
    factoryLiveMap["nav_modline6_slew"] = 0;
    factoryLiveMap["nav_modline6_destination"] = "None";
    factoryLiveMap["nav_modline6_note"] = 60;
    factoryLiveMap["nav_modline6_velocity"] = 127;
    factoryLiveMap["nav_modline6_cc"] = 1;
    factoryLiveMap["nav_modline6_mmcid"] = 0;
    factoryLiveMap["nav_modline6_mmcfunction"] = "Stop";
    factoryLiveMap["nav_modline6_channel"] = 0;
    factoryLiveMap["nav_modline6_device"] = "SSCOM_Port_1";
    factoryLiveMap["nav_modline6_displaylinked"] = 0;
    factoryLiveMap["nav_modline6_reminder"] = "";

}
