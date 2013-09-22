// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "factorypresets.h"

FactoryPresets::FactoryPresets()
{
    createProgramChange();
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
    programChangeMap["displayName"] = "PRGM";

    programChangeMap["useFactory"] = "Program Change";


    //------------------------------------------------ Key1
    programChangeMap["1_key_name"] = "1KEY";
    programChangeMap["1_key_displayMode"] = 4;
    programChangeMap["1_key_prefix"] = "PG";

    //Modline 1
    programChangeMap["1_key_modline1_on"] = 1;
    programChangeMap["1_key_modline1_source"] = "Nav Yx10 & Key";
    programChangeMap["1_key_modline1_gain"] = 1.00;
    programChangeMap["1_key_modline1_offset"] = 0.00;
    programChangeMap["1_key_modline1_table"] = "1_Lin";
    programChangeMap["1_key_modline1_min"] = 0;
    programChangeMap["1_key_modline1_max"] = 127;
    programChangeMap["1_key_modline1_slew"] = 0;
    programChangeMap["1_key_modline1_destination"] = "Program";
    programChangeMap["1_key_modline1_channel"] = 1;
    programChangeMap["1_key_modline1_device"] = "SSCOM_Port_1";
    programChangeMap["1_key_modline1_led_green"] = "None";
    programChangeMap["1_key_modline1_led_red"] = "None";
    programChangeMap["1_key_modline1_displayLinked"] = 1;

    //Modline 2
    programChangeMap["1_key_modline2_on"] = 1;
    programChangeMap["1_key_modline2_source"] = "Nav Yx10 & Key";
    programChangeMap["1_key_modline2_gain"] = 1.00;
    programChangeMap["1_key_modline2_offset"] = 0.00;
    programChangeMap["1_key_modline2_table"] = "1_Lin";
    programChangeMap["1_key_modline2_min"] = 0;
    programChangeMap["1_key_modline2_max"] = 127;
    programChangeMap["1_key_modline2_slew"] = 0;
    programChangeMap["1_key_modline2_destination"] = "Program";
    programChangeMap["1_key_modline2_channel"] = 1;
    programChangeMap["1_key_modline2_device"] = "SoftStep_Expander";
    programChangeMap["1_key_modline2_led_green"] = "None";
    programChangeMap["1_key_modline2_led_red"] = "None";
    programChangeMap["1_key_modline2_displayLinked"] = 0;

    //Modline 3
    programChangeMap["1_key_modline3_on"] = 1;
    programChangeMap["1_key_modline3_source"] = "Key 1 Pressed";
    programChangeMap["1_key_modline3_gain"] = 1.00;
    programChangeMap["1_key_modline3_offset"] = 0.00;
    programChangeMap["1_key_modline3_table"] = "1_Lin";
    programChangeMap["1_key_modline3_min"] = 0;
    programChangeMap["1_key_modline3_max"] = 127;
    programChangeMap["1_key_modline3_slew"] = 0;
    programChangeMap["1_key_modline3_destination"] = "None";
    programChangeMap["1_key_modline3_channel"] = 1;
    programChangeMap["1_key_modline3_device"] = "None";
    programChangeMap["1_key_modline3_led_green"] = "True";
    programChangeMap["1_key_modline3_led_red"] = "None";
    programChangeMap["1_key_modline3_displayLinked"] = 0;

    //Modline 4
    programChangeMap["1_key_modline4_on"] = 1;
    programChangeMap["1_key_modline4_source"] = "Other Key Pressed";
    programChangeMap["1_key_modline4_gain"] = 1.00;
    programChangeMap["1_key_modline4_offset"] = 0.00;
    programChangeMap["1_key_modline4_table"] = "1_Lin";
    programChangeMap["1_key_modline4_min"] = 0;
    programChangeMap["1_key_modline4_max"] = 127;
    programChangeMap["1_key_modline4_slew"] = 0;
    programChangeMap["1_key_modline4_destination"] = "None";
    programChangeMap["1_key_modline4_channel"] = 1;
    programChangeMap["1_key_modline4_device"] = "None";
    programChangeMap["1_key_modline4_led_green"] = "Off";
    programChangeMap["1_key_modline4_led_red"] = "None";
    programChangeMap["1_key_modline4_displayLinked"] = 0;

    //Modline 5
    programChangeMap["1_key_modline5_on"] = 1;
    programChangeMap["1_key_modline5_source"] = "Init";
    programChangeMap["1_key_modline5_gain"] = 1.00;
    programChangeMap["1_key_modline5_offset"] = 127.00;
    programChangeMap["1_key_modline5_table"] = "1_Lin";
    programChangeMap["1_key_modline5_min"] = 0;
    programChangeMap["1_key_modline5_max"] = 127;
    programChangeMap["1_key_modline5_slew"] = 0;
    programChangeMap["1_key_modline5_destination"] = "CC";
    programChangeMap["1_key_modline5_channel"] = 1;
    programChangeMap["1_key_modline5_device"] = "SSCOM_Port_1";
    programChangeMap["1_key_modline5_led_green"] = "None";
    programChangeMap["1_key_modline5_led_red"] = "None";
    programChangeMap["1_key_modline5_displayLinked"] = 0;

    //Modline 6
    programChangeMap["1_key_modline6_on"] = 1;
    programChangeMap["1_key_modline6_source"] = "Pedal";
    programChangeMap["1_key_modline6_gain"] = 1.00;
    programChangeMap["1_key_modline6_offset"] = 0.00;
    programChangeMap["1_key_modline6_table"] = "1_Lin";
    programChangeMap["1_key_modline6_min"] = 0;
    programChangeMap["1_key_modline6_max"] = 127;
    programChangeMap["1_key_modline6_slew"] = 0;
    programChangeMap["1_key_modline6_destination"] = "CC";
    programChangeMap["1_key_modline6_channel"] = 1;
    programChangeMap["1_key_modline6_device"] = "SSCOM_Port_1";
    programChangeMap["1_key_modline6_led_green"] = "None";
    programChangeMap["1_key_modline6_led_red"] = "None";
    programChangeMap["1_key_modline6_displayLinked"] = 0;

    //------------------------------------------------ Key2
    programChangeMap["2_key_name"] = "2KEY";
    programChangeMap["2_key_displayMode"] = 4;
    programChangeMap["2_key_prefix"] = "PG";

    //Modline 1
    programChangeMap["2_key_modline1_on"] = 1;
    programChangeMap["2_key_modline1_source"] = "Nav Yx10 & Key";
    programChangeMap["2_key_modline1_gain"] = 1.00;
    programChangeMap["2_key_modline1_offset"] = 0.00;
    programChangeMap["2_key_modline1_table"] = "1_Lin";
    programChangeMap["2_key_modline1_min"] = 0;
    programChangeMap["2_key_modline1_max"] = 127;
    programChangeMap["2_key_modline1_slew"] = 0;
    programChangeMap["2_key_modline1_destination"] = "Program";
    programChangeMap["2_key_modline1_channel"] = 1;
    programChangeMap["2_key_modline1_device"] = "SSCOM_Port_1";
    programChangeMap["2_key_modline1_led_green"] = "None";
    programChangeMap["2_key_modline1_led_red"] = "None";
    programChangeMap["2_key_modline1_displayLinked"] = 1;

    //Modline 2
    programChangeMap["2_key_modline2_on"] = 1;
    programChangeMap["2_key_modline2_source"] = "Nav Yx10 & Key";
    programChangeMap["2_key_modline2_gain"] = 1.00;
    programChangeMap["2_key_modline2_offset"] = 0.00;
    programChangeMap["2_key_modline2_table"] = "1_Lin";
    programChangeMap["2_key_modline2_min"] = 0;
    programChangeMap["2_key_modline2_max"] = 127;
    programChangeMap["2_key_modline2_slew"] = 0;
    programChangeMap["2_key_modline2_destination"] = "Program";
    programChangeMap["2_key_modline2_channel"] = 1;
    programChangeMap["2_key_modline2_device"] = "SoftStep_Expander";
    programChangeMap["2_key_modline2_led_green"] = "None";
    programChangeMap["2_key_modline2_led_red"] = "None";
    programChangeMap["2_key_modline2_displayLinked"] = 0;

    //Modline 3
    programChangeMap["2_key_modline3_on"] = 1;
    programChangeMap["2_key_modline3_source"] = "Key 2 Pressed";
    programChangeMap["2_key_modline3_gain"] = 1.00;
    programChangeMap["2_key_modline3_offset"] = 0.00;
    programChangeMap["2_key_modline3_table"] = "1_Lin";
    programChangeMap["2_key_modline3_min"] = 0;
    programChangeMap["2_key_modline3_max"] = 127;
    programChangeMap["2_key_modline3_slew"] = 0;
    programChangeMap["2_key_modline3_destination"] = "None";
    programChangeMap["2_key_modline3_channel"] = 1;
    programChangeMap["2_key_modline3_device"] = "None";
    programChangeMap["2_key_modline3_led_green"] = "True";
    programChangeMap["2_key_modline3_led_red"] = "None";
    programChangeMap["2_key_modline3_displayLinked"] = 0;

    //Modline 4
    programChangeMap["2_key_modline4_on"] = 1;
    programChangeMap["2_key_modline4_source"] = "Other Key Pressed";
    programChangeMap["2_key_modline4_gain"] = 1.00;
    programChangeMap["2_key_modline4_offset"] = 0.00;
    programChangeMap["2_key_modline4_table"] = "1_Lin";
    programChangeMap["2_key_modline4_min"] = 0;
    programChangeMap["2_key_modline4_max"] = 127;
    programChangeMap["2_key_modline4_slew"] = 0;
    programChangeMap["2_key_modline4_destination"] = "None";
    programChangeMap["2_key_modline4_channel"] = 1;
    programChangeMap["2_key_modline4_device"] = "None";
    programChangeMap["2_key_modline4_led_green"] = "Off";
    programChangeMap["2_key_modline4_led_red"] = "None";
    programChangeMap["2_key_modline4_displayLinked"] = 0;

    //Modline 5
    programChangeMap["2_key_modline5_on"] = 0;
    programChangeMap["2_key_modline5_source"] = "None";
    programChangeMap["2_key_modline5_gain"] = 1.00;
    programChangeMap["2_key_modline5_offset"] = 0.00;
    programChangeMap["2_key_modline5_table"] = "1_Lin";
    programChangeMap["2_key_modline5_min"] = 0;
    programChangeMap["2_key_modline5_max"] = 127;
    programChangeMap["2_key_modline5_slew"] = 0;
    programChangeMap["2_key_modline5_destination"] = "None";
    programChangeMap["2_key_modline5_channel"] = 1;
    programChangeMap["2_key_modline5_device"] = "None";
    programChangeMap["2_key_modline5_led_green"] = "None";
    programChangeMap["2_key_modline5_led_red"] = "None";
    programChangeMap["2_key_modline5_displayLinked"] = 0;

    //Modline 6
    programChangeMap["2_key_modline6_on"] = 0;
    programChangeMap["2_key_modline6_source"] = "None";
    programChangeMap["2_key_modline6_gain"] = 1.00;
    programChangeMap["2_key_modline6_offset"] = 0.00;
    programChangeMap["2_key_modline6_table"] = "1_Lin";
    programChangeMap["2_key_modline6_min"] = 0;
    programChangeMap["2_key_modline6_max"] = 127;
    programChangeMap["2_key_modline6_slew"] = 0;
    programChangeMap["2_key_modline6_destination"] = "None";
    programChangeMap["2_key_modline6_channel"] = 1;
    programChangeMap["2_key_modline6_device"] = "None";
    programChangeMap["2_key_modline6_led_green"] = "None";
    programChangeMap["2_key_modline6_led_red"] = "None";
    programChangeMap["2_key_modline6_displayLinked"] = 0;

    //------------------------------------------------ Key3
    programChangeMap["3_key_name"] = "3KEY";
    programChangeMap["3_key_displayMode"] = 4;
    programChangeMap["3_key_prefix"] = "PG";

    //Modline 1
    programChangeMap["3_key_modline1_on"] = 1;
    programChangeMap["3_key_modline1_source"] = "Nav Yx10 & Key";
    programChangeMap["3_key_modline1_gain"] = 1.00;
    programChangeMap["3_key_modline1_offset"] = 0.00;
    programChangeMap["3_key_modline1_table"] = "1_Lin";
    programChangeMap["3_key_modline1_min"] = 0;
    programChangeMap["3_key_modline1_max"] = 127;
    programChangeMap["3_key_modline1_slew"] = 0;
    programChangeMap["3_key_modline1_destination"] = "Program";
    programChangeMap["3_key_modline1_channel"] = 1;
    programChangeMap["3_key_modline1_device"] = "SSCOM_Port_1";
    programChangeMap["3_key_modline1_led_green"] = "None";
    programChangeMap["3_key_modline1_led_red"] = "None";
    programChangeMap["3_key_modline1_displayLinked"] = 1;

    //Modline 2
    programChangeMap["3_key_modline2_on"] = 1;
    programChangeMap["3_key_modline2_source"] = "Nav Yx10 & Key";
    programChangeMap["3_key_modline2_gain"] = 1.00;
    programChangeMap["3_key_modline2_offset"] = 0.00;
    programChangeMap["3_key_modline2_table"] = "1_Lin";
    programChangeMap["3_key_modline2_min"] = 0;
    programChangeMap["3_key_modline2_max"] = 127;
    programChangeMap["3_key_modline2_slew"] = 0;
    programChangeMap["3_key_modline2_destination"] = "Program";
    programChangeMap["3_key_modline2_channel"] = 1;
    programChangeMap["3_key_modline2_device"] = "SoftStep_Expander";
    programChangeMap["3_key_modline2_led_green"] = "None";
    programChangeMap["3_key_modline2_led_red"] = "None";
    programChangeMap["3_key_modline2_displayLinked"] = 0;

    //Modline 3
    programChangeMap["3_key_modline3_on"] = 1;
    programChangeMap["3_key_modline3_source"] = "Key 3 Pressed";
    programChangeMap["3_key_modline3_gain"] = 1.00;
    programChangeMap["3_key_modline3_offset"] = 0.00;
    programChangeMap["3_key_modline3_table"] = "1_Lin";
    programChangeMap["3_key_modline3_min"] = 0;
    programChangeMap["3_key_modline3_max"] = 127;
    programChangeMap["3_key_modline3_slew"] = 0;
    programChangeMap["3_key_modline3_destination"] = "None";
    programChangeMap["3_key_modline3_channel"] = 1;
    programChangeMap["3_key_modline3_device"] = "None";
    programChangeMap["3_key_modline3_led_green"] = "True";
    programChangeMap["3_key_modline3_led_red"] = "None";
    programChangeMap["3_key_modline3_displayLinked"] = 0;

    //Modline 4
    programChangeMap["3_key_modline4_on"] = 1;
    programChangeMap["3_key_modline4_source"] = "Other Key Pressed";
    programChangeMap["3_key_modline4_gain"] = 1.00;
    programChangeMap["3_key_modline4_offset"] = 0.00;
    programChangeMap["3_key_modline4_table"] = "1_Lin";
    programChangeMap["3_key_modline4_min"] = 0;
    programChangeMap["3_key_modline4_max"] = 127;
    programChangeMap["3_key_modline4_slew"] = 0;
    programChangeMap["3_key_modline4_destination"] = "None";
    programChangeMap["3_key_modline4_channel"] = 1;
    programChangeMap["3_key_modline4_device"] = "None";
    programChangeMap["3_key_modline4_led_green"] = "Off";
    programChangeMap["3_key_modline4_led_red"] = "None";
    programChangeMap["3_key_modline4_displayLinked"] = 0;

    //Modline 5
    programChangeMap["3_key_modline5_on"] = 0;
    programChangeMap["3_key_modline5_source"] = "None";
    programChangeMap["3_key_modline5_gain"] = 1.00;
    programChangeMap["3_key_modline5_offset"] = 0.00;
    programChangeMap["3_key_modline5_table"] = "1_Lin";
    programChangeMap["3_key_modline5_min"] = 0;
    programChangeMap["3_key_modline5_max"] = 127;
    programChangeMap["3_key_modline5_slew"] = 0;
    programChangeMap["3_key_modline5_destination"] = "None";
    programChangeMap["3_key_modline5_channel"] = 1;
    programChangeMap["3_key_modline5_device"] = "None";
    programChangeMap["3_key_modline5_led_green"] = "None";
    programChangeMap["3_key_modline5_led_red"] = "None";
    programChangeMap["3_key_modline5_displayLinked"] = 0;

    //Modline 6
    programChangeMap["3_key_modline6_on"] = 0;
    programChangeMap["3_key_modline6_source"] = "None";
    programChangeMap["3_key_modline6_gain"] = 1.00;
    programChangeMap["3_key_modline6_offset"] = 0.00;
    programChangeMap["3_key_modline6_table"] = "1_Lin";
    programChangeMap["3_key_modline6_min"] = 0;
    programChangeMap["3_key_modline6_max"] = 127;
    programChangeMap["3_key_modline6_slew"] = 0;
    programChangeMap["3_key_modline6_destination"] = "None";
    programChangeMap["3_key_modline6_channel"] = 1;
    programChangeMap["3_key_modline6_device"] = "None";
    programChangeMap["3_key_modline6_led_green"] = "None";
    programChangeMap["3_key_modline6_led_red"] = "None";
    programChangeMap["3_key_modline6_displayLinked"] = 0;

    //------------------------------------------------ Key4
    programChangeMap["4_key_name"] = "4KEY";
    programChangeMap["4_key_displayMode"] = 4;
    programChangeMap["4_key_prefix"] = "PG";

    //Modline 1
    programChangeMap["4_key_modline1_on"] = 1;
    programChangeMap["4_key_modline1_source"] = "Nav Yx10 & Key";
    programChangeMap["4_key_modline1_gain"] = 1.00;
    programChangeMap["4_key_modline1_offset"] = 0.00;
    programChangeMap["4_key_modline1_table"] = "1_Lin";
    programChangeMap["4_key_modline1_min"] = 0;
    programChangeMap["4_key_modline1_max"] = 127;
    programChangeMap["4_key_modline1_slew"] = 0;
    programChangeMap["4_key_modline1_destination"] = "Program";
    programChangeMap["4_key_modline1_channel"] = 1;
    programChangeMap["4_key_modline1_device"] = "SSCOM_Port_1";
    programChangeMap["4_key_modline1_led_green"] = "None";
    programChangeMap["4_key_modline1_led_red"] = "None";
    programChangeMap["4_key_modline1_displayLinked"] = 1;

    //Modline 2
    programChangeMap["4_key_modline2_on"] = 1;
    programChangeMap["4_key_modline2_source"] = "Nav Yx10 & Key";
    programChangeMap["4_key_modline2_gain"] = 1.00;
    programChangeMap["4_key_modline2_offset"] = 0.00;
    programChangeMap["4_key_modline2_table"] = "1_Lin";
    programChangeMap["4_key_modline2_min"] = 0;
    programChangeMap["4_key_modline2_max"] = 127;
    programChangeMap["4_key_modline2_slew"] = 0;
    programChangeMap["4_key_modline2_destination"] = "Program";
    programChangeMap["4_key_modline2_channel"] = 1;
    programChangeMap["4_key_modline2_device"] = "SoftStep_Expander";
    programChangeMap["4_key_modline2_led_green"] = "None";
    programChangeMap["4_key_modline2_led_red"] = "None";
    programChangeMap["4_key_modline2_displayLinked"] = 0;

    //Modline 3
    programChangeMap["4_key_modline3_on"] = 1;
    programChangeMap["4_key_modline3_source"] = "Key 4 Pressed";
    programChangeMap["4_key_modline3_gain"] = 1.00;
    programChangeMap["4_key_modline3_offset"] = 0.00;
    programChangeMap["4_key_modline3_table"] = "1_Lin";
    programChangeMap["4_key_modline3_min"] = 0;
    programChangeMap["4_key_modline3_max"] = 127;
    programChangeMap["4_key_modline3_slew"] = 0;
    programChangeMap["4_key_modline3_destination"] = "None";
    programChangeMap["4_key_modline3_channel"] = 1;
    programChangeMap["4_key_modline3_device"] = "None";
    programChangeMap["4_key_modline3_led_green"] = "True";
    programChangeMap["4_key_modline3_led_red"] = "None";
    programChangeMap["4_key_modline3_displayLinked"] = 0;

    //Modline 4
    programChangeMap["4_key_modline4_on"] = 1;
    programChangeMap["4_key_modline4_source"] = "Other Key Pressed";
    programChangeMap["4_key_modline4_gain"] = 1.00;
    programChangeMap["4_key_modline4_offset"] = 0.00;
    programChangeMap["4_key_modline4_table"] = "1_Lin";
    programChangeMap["4_key_modline4_min"] = 0;
    programChangeMap["4_key_modline4_max"] = 127;
    programChangeMap["4_key_modline4_slew"] = 0;
    programChangeMap["4_key_modline4_destination"] = "None";
    programChangeMap["4_key_modline4_channel"] = 1;
    programChangeMap["4_key_modline4_device"] = "None";
    programChangeMap["4_key_modline4_led_green"] = "Off";
    programChangeMap["4_key_modline4_led_red"] = "None";
    programChangeMap["4_key_modline4_displayLinked"] = 0;

    //Modline 5
    programChangeMap["4_key_modline5_on"] = 0;
    programChangeMap["4_key_modline5_source"] = "None";
    programChangeMap["4_key_modline5_gain"] = 1.00;
    programChangeMap["4_key_modline5_offset"] = 0.00;
    programChangeMap["4_key_modline5_table"] = "1_Lin";
    programChangeMap["4_key_modline5_min"] = 0;
    programChangeMap["4_key_modline5_max"] = 127;
    programChangeMap["4_key_modline5_slew"] = 0;
    programChangeMap["4_key_modline5_destination"] = "None";
    programChangeMap["4_key_modline5_channel"] = 1;
    programChangeMap["4_key_modline5_device"] = "None";
    programChangeMap["4_key_modline5_led_green"] = "None";
    programChangeMap["4_key_modline5_led_red"] = "None";
    programChangeMap["4_key_modline5_displayLinked"] = 0;

    //Modline 6
    programChangeMap["4_key_modline6_on"] = 0;
    programChangeMap["4_key_modline6_source"] = "None";
    programChangeMap["4_key_modline6_gain"] = 1.00;
    programChangeMap["4_key_modline6_offset"] = 0.00;
    programChangeMap["4_key_modline6_table"] = "1_Lin";
    programChangeMap["4_key_modline6_min"] = 0;
    programChangeMap["4_key_modline6_max"] = 127;
    programChangeMap["4_key_modline6_slew"] = 0;
    programChangeMap["4_key_modline6_destination"] = "None";
    programChangeMap["4_key_modline6_channel"] = 1;
    programChangeMap["4_key_modline6_device"] = "None";
    programChangeMap["4_key_modline6_led_green"] = "None";
    programChangeMap["4_key_modline6_led_red"] = "None";
    programChangeMap["4_key_modline6_displayLinked"] = 0;

    //------------------------------------------------ Key5
    programChangeMap["5_key_name"] = "5KEY";
    programChangeMap["5_key_displayMode"] = 4;
    programChangeMap["5_key_prefix"] = "PG";

    //Modline 1
    programChangeMap["5_key_modline1_on"] = 1;
    programChangeMap["5_key_modline1_source"] = "Nav Yx10 & Key";
    programChangeMap["5_key_modline1_gain"] = 1.00;
    programChangeMap["5_key_modline1_offset"] = 0.00;
    programChangeMap["5_key_modline1_table"] = "1_Lin";
    programChangeMap["5_key_modline1_min"] = 0;
    programChangeMap["5_key_modline1_max"] = 127;
    programChangeMap["5_key_modline1_slew"] = 0;
    programChangeMap["5_key_modline1_destination"] = "Program";
    programChangeMap["5_key_modline1_channel"] = 1;
    programChangeMap["5_key_modline1_device"] = "SSCOM_Port_1";
    programChangeMap["5_key_modline1_led_green"] = "None";
    programChangeMap["5_key_modline1_led_red"] = "None";
    programChangeMap["5_key_modline1_displayLinked"] = 1;

    //Modline 2
    programChangeMap["5_key_modline2_on"] = 1;
    programChangeMap["5_key_modline2_source"] = "Nav Yx10 & Key";
    programChangeMap["5_key_modline2_gain"] = 1.00;
    programChangeMap["5_key_modline2_offset"] = 0.00;
    programChangeMap["5_key_modline2_table"] = "1_Lin";
    programChangeMap["5_key_modline2_min"] = 0;
    programChangeMap["5_key_modline2_max"] = 127;
    programChangeMap["5_key_modline2_slew"] = 0;
    programChangeMap["5_key_modline2_destination"] = "Program";
    programChangeMap["5_key_modline2_channel"] = 1;
    programChangeMap["5_key_modline2_device"] = "SoftStep_Expander";
    programChangeMap["5_key_modline2_led_green"] = "None";
    programChangeMap["5_key_modline2_led_red"] = "None";
    programChangeMap["5_key_modline2_displayLinked"] = 0;

    //Modline 3
    programChangeMap["5_key_modline3_on"] = 1;
    programChangeMap["5_key_modline3_source"] = "Key 5 Pressed";
    programChangeMap["5_key_modline3_gain"] = 1.00;
    programChangeMap["5_key_modline3_offset"] = 0.00;
    programChangeMap["5_key_modline3_table"] = "1_Lin";
    programChangeMap["5_key_modline3_min"] = 0;
    programChangeMap["5_key_modline3_max"] = 127;
    programChangeMap["5_key_modline3_slew"] = 0;
    programChangeMap["5_key_modline3_destination"] = "None";
    programChangeMap["5_key_modline3_channel"] = 1;
    programChangeMap["5_key_modline3_device"] = "None";
    programChangeMap["5_key_modline3_led_green"] = "True";
    programChangeMap["5_key_modline3_led_red"] = "None";
    programChangeMap["5_key_modline3_displayLinked"] = 0;

    //Modline 4
    programChangeMap["5_key_modline4_on"] = 1;
    programChangeMap["5_key_modline4_source"] = "Other Key Pressed";
    programChangeMap["5_key_modline4_gain"] = 1.00;
    programChangeMap["5_key_modline4_offset"] = 0.00;
    programChangeMap["5_key_modline4_table"] = "1_Lin";
    programChangeMap["5_key_modline4_min"] = 0;
    programChangeMap["5_key_modline4_max"] = 127;
    programChangeMap["5_key_modline4_slew"] = 0;
    programChangeMap["5_key_modline4_destination"] = "None";
    programChangeMap["5_key_modline4_channel"] = 1;
    programChangeMap["5_key_modline4_device"] = "None";
    programChangeMap["5_key_modline4_led_green"] = "Off";
    programChangeMap["5_key_modline4_led_red"] = "None";
    programChangeMap["5_key_modline4_displayLinked"] = 0;

    //Modline 5
    programChangeMap["5_key_modline5_on"] = 0;
    programChangeMap["5_key_modline5_source"] = "None";
    programChangeMap["5_key_modline5_gain"] = 1.00;
    programChangeMap["5_key_modline5_offset"] = 0.00;
    programChangeMap["5_key_modline5_table"] = "1_Lin";
    programChangeMap["5_key_modline5_min"] = 0;
    programChangeMap["5_key_modline5_max"] = 127;
    programChangeMap["5_key_modline5_slew"] = 0;
    programChangeMap["5_key_modline5_destination"] = "None";
    programChangeMap["5_key_modline5_channel"] = 1;
    programChangeMap["5_key_modline5_device"] = "None";
    programChangeMap["5_key_modline5_led_green"] = "None";
    programChangeMap["5_key_modline5_led_red"] = "None";
    programChangeMap["5_key_modline5_displayLinked"] = 0;

    //Modline 6
    programChangeMap["5_key_modline6_on"] = 0;
    programChangeMap["5_key_modline6_source"] = "None";
    programChangeMap["5_key_modline6_gain"] = 1.00;
    programChangeMap["5_key_modline6_offset"] = 0.00;
    programChangeMap["5_key_modline6_table"] = "1_Lin";
    programChangeMap["5_key_modline6_min"] = 0;
    programChangeMap["5_key_modline6_max"] = 127;
    programChangeMap["5_key_modline6_slew"] = 0;
    programChangeMap["5_key_modline6_destination"] = "None";
    programChangeMap["5_key_modline6_channel"] = 1;
    programChangeMap["5_key_modline6_device"] = "None";
    programChangeMap["5_key_modline6_led_green"] = "None";
    programChangeMap["5_key_modline6_led_red"] = "None";
    programChangeMap["5_key_modline6_displayLinked"] = 0;

    //------------------------------------------------ Key6
    programChangeMap["6_key_name"] = "6KEY";
    programChangeMap["6_key_displayMode"] = 4;
    programChangeMap["6_key_prefix"] = "PG";

    //Modline 1
    programChangeMap["6_key_modline1_on"] = 1;
    programChangeMap["6_key_modline1_source"] = "Nav Yx10 & Key";
    programChangeMap["6_key_modline1_gain"] = 1.00;
    programChangeMap["6_key_modline1_offset"] = 0.00;
    programChangeMap["6_key_modline1_table"] = "1_Lin";
    programChangeMap["6_key_modline1_min"] = 0;
    programChangeMap["6_key_modline1_max"] = 127;
    programChangeMap["6_key_modline1_slew"] = 0;
    programChangeMap["6_key_modline1_destination"] = "Program";
    programChangeMap["6_key_modline1_channel"] = 1;
    programChangeMap["6_key_modline1_device"] = "SSCOM_Port_1";
    programChangeMap["6_key_modline1_led_green"] = "None";
    programChangeMap["6_key_modline1_led_red"] = "None";
    programChangeMap["6_key_modline1_displayLinked"] = 1;

    //Modline 2
    programChangeMap["6_key_modline2_on"] = 1;
    programChangeMap["6_key_modline2_source"] = "Nav Yx10 & Key";
    programChangeMap["6_key_modline2_gain"] = 1.00;
    programChangeMap["6_key_modline2_offset"] = 0.00;
    programChangeMap["6_key_modline2_table"] = "1_Lin";
    programChangeMap["6_key_modline2_min"] = 0;
    programChangeMap["6_key_modline2_max"] = 127;
    programChangeMap["6_key_modline2_slew"] = 0;
    programChangeMap["6_key_modline2_destination"] = "Program";
    programChangeMap["6_key_modline2_channel"] = 1;
    programChangeMap["6_key_modline2_device"] = "SoftStep_Expander";
    programChangeMap["6_key_modline2_led_green"] = "None";
    programChangeMap["6_key_modline2_led_red"] = "None";
    programChangeMap["6_key_modline2_displayLinked"] = 0;

    //Modline 3
    programChangeMap["6_key_modline3_on"] = 1;
    programChangeMap["6_key_modline3_source"] = "Key 6 Pressed";
    programChangeMap["6_key_modline3_gain"] = 1.00;
    programChangeMap["6_key_modline3_offset"] = 0.00;
    programChangeMap["6_key_modline3_table"] = "1_Lin";
    programChangeMap["6_key_modline3_min"] = 0;
    programChangeMap["6_key_modline3_max"] = 127;
    programChangeMap["6_key_modline3_slew"] = 0;
    programChangeMap["6_key_modline3_destination"] = "None";
    programChangeMap["6_key_modline3_channel"] = 1;
    programChangeMap["6_key_modline3_device"] = "None";
    programChangeMap["6_key_modline3_led_green"] = "True";
    programChangeMap["6_key_modline3_led_red"] = "None";
    programChangeMap["6_key_modline3_displayLinked"] = 0;

    //Modline 4
    programChangeMap["6_key_modline4_on"] = 1;
    programChangeMap["6_key_modline4_source"] = "Other Key Pressed";
    programChangeMap["6_key_modline4_gain"] = 1.00;
    programChangeMap["6_key_modline4_offset"] = 0.00;
    programChangeMap["6_key_modline4_table"] = "1_Lin";
    programChangeMap["6_key_modline4_min"] = 0;
    programChangeMap["6_key_modline4_max"] = 127;
    programChangeMap["6_key_modline4_slew"] = 0;
    programChangeMap["6_key_modline4_destination"] = "None";
    programChangeMap["6_key_modline4_channel"] = 1;
    programChangeMap["6_key_modline4_device"] = "None";
    programChangeMap["6_key_modline4_led_green"] = "Off";
    programChangeMap["6_key_modline4_led_red"] = "None";
    programChangeMap["6_key_modline4_displayLinked"] = 0;

    //Modline 5
    programChangeMap["6_key_modline5_on"] = 0;
    programChangeMap["6_key_modline5_source"] = "None";
    programChangeMap["6_key_modline5_gain"] = 1.00;
    programChangeMap["6_key_modline5_offset"] = 0.00;
    programChangeMap["6_key_modline5_table"] = "1_Lin";
    programChangeMap["6_key_modline5_min"] = 0;
    programChangeMap["6_key_modline5_max"] = 127;
    programChangeMap["6_key_modline5_slew"] = 0;
    programChangeMap["6_key_modline5_destination"] = "None";
    programChangeMap["6_key_modline5_channel"] = 1;
    programChangeMap["6_key_modline5_device"] = "None";
    programChangeMap["6_key_modline5_led_green"] = "None";
    programChangeMap["6_key_modline5_led_red"] = "None";
    programChangeMap["6_key_modline5_displayLinked"] = 0;

    //Modline 6
    programChangeMap["6_key_modline6_on"] = 0;
    programChangeMap["6_key_modline6_source"] = "None";
    programChangeMap["6_key_modline6_gain"] = 1.00;
    programChangeMap["6_key_modline6_offset"] = 0.00;
    programChangeMap["6_key_modline6_table"] = "1_Lin";
    programChangeMap["6_key_modline6_min"] = 0;
    programChangeMap["6_key_modline6_max"] = 127;
    programChangeMap["6_key_modline6_slew"] = 0;
    programChangeMap["6_key_modline6_destination"] = "None";
    programChangeMap["6_key_modline6_channel"] = 1;
    programChangeMap["6_key_modline6_device"] = "None";
    programChangeMap["6_key_modline6_led_green"] = "None";
    programChangeMap["6_key_modline6_led_red"] = "None";
    programChangeMap["6_key_modline6_displayLinked"] = 0;

    //------------------------------------------------ Key7
    programChangeMap["7_key_name"] = "7KEY";
    programChangeMap["7_key_displayMode"] = 4;
    programChangeMap["7_key_prefix"] = "PG";

    //Modline 1
    programChangeMap["7_key_modline1_on"] = 1;
    programChangeMap["7_key_modline1_source"] = "Nav Yx10 & Key";
    programChangeMap["7_key_modline1_gain"] = 1.00;
    programChangeMap["7_key_modline1_offset"] = 0.00;
    programChangeMap["7_key_modline1_table"] = "1_Lin";
    programChangeMap["7_key_modline1_min"] = 0;
    programChangeMap["7_key_modline1_max"] = 127;
    programChangeMap["7_key_modline1_slew"] = 0;
    programChangeMap["7_key_modline1_destination"] = "Program";
    programChangeMap["7_key_modline1_channel"] = 1;
    programChangeMap["7_key_modline1_device"] = "SSCOM_Port_1";
    programChangeMap["7_key_modline1_led_green"] = "None";
    programChangeMap["7_key_modline1_led_red"] = "None";
    programChangeMap["7_key_modline1_displayLinked"] = 1;

    //Modline 2
    programChangeMap["7_key_modline2_on"] = 1;
    programChangeMap["7_key_modline2_source"] = "Nav Yx10 & Key";
    programChangeMap["7_key_modline2_gain"] = 1.00;
    programChangeMap["7_key_modline2_offset"] = 0.00;
    programChangeMap["7_key_modline2_table"] = "1_Lin";
    programChangeMap["7_key_modline2_min"] = 0;
    programChangeMap["7_key_modline2_max"] = 127;
    programChangeMap["7_key_modline2_slew"] = 0;
    programChangeMap["7_key_modline2_destination"] = "Program";
    programChangeMap["7_key_modline2_channel"] = 1;
    programChangeMap["7_key_modline2_device"] = "SoftStep_Expander";
    programChangeMap["7_key_modline2_led_green"] = "None";
    programChangeMap["7_key_modline2_led_red"] = "None";
    programChangeMap["7_key_modline2_displayLinked"] = 0;

    //Modline 3
    programChangeMap["7_key_modline3_on"] = 1;
    programChangeMap["7_key_modline3_source"] = "Key 7 Pressed";
    programChangeMap["7_key_modline3_gain"] = 1.00;
    programChangeMap["7_key_modline3_offset"] = 0.00;
    programChangeMap["7_key_modline3_table"] = "1_Lin";
    programChangeMap["7_key_modline3_min"] = 0;
    programChangeMap["7_key_modline3_max"] = 127;
    programChangeMap["7_key_modline3_slew"] = 0;
    programChangeMap["7_key_modline3_destination"] = "None";
    programChangeMap["7_key_modline3_channel"] = 1;
    programChangeMap["7_key_modline3_device"] = "None";
    programChangeMap["7_key_modline3_led_green"] = "True";
    programChangeMap["7_key_modline3_led_red"] = "None";
    programChangeMap["7_key_modline3_displayLinked"] = 0;

    //Modline 4
    programChangeMap["7_key_modline4_on"] = 1;
    programChangeMap["7_key_modline4_source"] = "Other Key Pressed";
    programChangeMap["7_key_modline4_gain"] = 1.00;
    programChangeMap["7_key_modline4_offset"] = 0.00;
    programChangeMap["7_key_modline4_table"] = "1_Lin";
    programChangeMap["7_key_modline4_min"] = 0;
    programChangeMap["7_key_modline4_max"] = 127;
    programChangeMap["7_key_modline4_slew"] = 0;
    programChangeMap["7_key_modline4_destination"] = "None";
    programChangeMap["7_key_modline4_channel"] = 1;
    programChangeMap["7_key_modline4_device"] = "None";
    programChangeMap["7_key_modline4_led_green"] = "Off";
    programChangeMap["7_key_modline4_led_red"] = "None";
    programChangeMap["7_key_modline4_displayLinked"] = 0;

    //Modline 5
    programChangeMap["7_key_modline5_on"] = 0;
    programChangeMap["7_key_modline5_source"] = "None";
    programChangeMap["7_key_modline5_gain"] = 1.00;
    programChangeMap["7_key_modline5_offset"] = 0.00;
    programChangeMap["7_key_modline5_table"] = "1_Lin";
    programChangeMap["7_key_modline5_min"] = 0;
    programChangeMap["7_key_modline5_max"] = 127;
    programChangeMap["7_key_modline5_slew"] = 0;
    programChangeMap["7_key_modline5_destination"] = "None";
    programChangeMap["7_key_modline5_channel"] = 1;
    programChangeMap["7_key_modline5_device"] = "None";
    programChangeMap["7_key_modline5_led_green"] = "None";
    programChangeMap["7_key_modline5_led_red"] = "None";
    programChangeMap["7_key_modline5_displayLinked"] = 0;

    //Modline 6
    programChangeMap["7_key_modline6_on"] = 0;
    programChangeMap["7_key_modline6_source"] = "None";
    programChangeMap["7_key_modline6_gain"] = 1.00;
    programChangeMap["7_key_modline6_offset"] = 0.00;
    programChangeMap["7_key_modline6_table"] = "1_Lin";
    programChangeMap["7_key_modline6_min"] = 0;
    programChangeMap["7_key_modline6_max"] = 127;
    programChangeMap["7_key_modline6_slew"] = 0;
    programChangeMap["7_key_modline6_destination"] = "None";
    programChangeMap["7_key_modline6_channel"] = 1;
    programChangeMap["7_key_modline6_device"] = "None";
    programChangeMap["7_key_modline6_led_green"] = "None";
    programChangeMap["7_key_modline6_led_red"] = "None";
    programChangeMap["7_key_modline6_displayLinked"] = 0;

    //------------------------------------------------ Key8
    programChangeMap["8_key_name"] = "8KEY";
    programChangeMap["8_key_displayMode"] = 4;
    programChangeMap["8_key_prefix"] = "PG";

    //Modline 1
    programChangeMap["8_key_modline1_on"] = 1;
    programChangeMap["8_key_modline1_source"] = "Nav Yx10 & Key";
    programChangeMap["8_key_modline1_gain"] = 1.00;
    programChangeMap["8_key_modline1_offset"] = 0.00;
    programChangeMap["8_key_modline1_table"] = "1_Lin";
    programChangeMap["8_key_modline1_min"] = 0;
    programChangeMap["8_key_modline1_max"] = 127;
    programChangeMap["8_key_modline1_slew"] = 0;
    programChangeMap["8_key_modline1_destination"] = "Program";
    programChangeMap["8_key_modline1_channel"] = 1;
    programChangeMap["8_key_modline1_device"] = "SSCOM_Port_1";
    programChangeMap["8_key_modline1_led_green"] = "None";
    programChangeMap["8_key_modline1_led_red"] = "None";
    programChangeMap["8_key_modline1_displayLinked"] = 1;

    //Modline 2
    programChangeMap["8_key_modline2_on"] = 1;
    programChangeMap["8_key_modline2_source"] = "Nav Yx10 & Key";
    programChangeMap["8_key_modline2_gain"] = 1.00;
    programChangeMap["8_key_modline2_offset"] = 0.00;
    programChangeMap["8_key_modline2_table"] = "1_Lin";
    programChangeMap["8_key_modline2_min"] = 0;
    programChangeMap["8_key_modline2_max"] = 127;
    programChangeMap["8_key_modline2_slew"] = 0;
    programChangeMap["8_key_modline2_destination"] = "Program";
    programChangeMap["8_key_modline2_channel"] = 1;
    programChangeMap["8_key_modline2_device"] = "SoftStep_Expander";
    programChangeMap["8_key_modline2_led_green"] = "None";
    programChangeMap["8_key_modline2_led_red"] = "None";
    programChangeMap["8_key_modline2_displayLinked"] = 0;

    //Modline 3
    programChangeMap["8_key_modline3_on"] = 1;
    programChangeMap["8_key_modline3_source"] = "Key 8 Pressed";
    programChangeMap["8_key_modline3_gain"] = 1.00;
    programChangeMap["8_key_modline3_offset"] = 0.00;
    programChangeMap["8_key_modline3_table"] = "1_Lin";
    programChangeMap["8_key_modline3_min"] = 0;
    programChangeMap["8_key_modline3_max"] = 127;
    programChangeMap["8_key_modline3_slew"] = 0;
    programChangeMap["8_key_modline3_destination"] = "None";
    programChangeMap["8_key_modline3_channel"] = 1;
    programChangeMap["8_key_modline3_device"] = "None";
    programChangeMap["8_key_modline3_led_green"] = "True";
    programChangeMap["8_key_modline3_led_red"] = "None";
    programChangeMap["8_key_modline3_displayLinked"] = 0;

    //Modline 4
    programChangeMap["8_key_modline4_on"] = 1;
    programChangeMap["8_key_modline4_source"] = "Other Key Pressed";
    programChangeMap["8_key_modline4_gain"] = 1.00;
    programChangeMap["8_key_modline4_offset"] = 0.00;
    programChangeMap["8_key_modline4_table"] = "1_Lin";
    programChangeMap["8_key_modline4_min"] = 0;
    programChangeMap["8_key_modline4_max"] = 127;
    programChangeMap["8_key_modline4_slew"] = 0;
    programChangeMap["8_key_modline4_destination"] = "None";
    programChangeMap["8_key_modline4_channel"] = 1;
    programChangeMap["8_key_modline4_device"] = "None";
    programChangeMap["8_key_modline4_led_green"] = "Off";
    programChangeMap["8_key_modline4_led_red"] = "None";
    programChangeMap["8_key_modline4_displayLinked"] = 0;

    //Modline 5
    programChangeMap["8_key_modline5_on"] = 0;
    programChangeMap["8_key_modline5_source"] = "None";
    programChangeMap["8_key_modline5_gain"] = 1.00;
    programChangeMap["8_key_modline5_offset"] = 0.00;
    programChangeMap["8_key_modline5_table"] = "1_Lin";
    programChangeMap["8_key_modline5_min"] = 0;
    programChangeMap["8_key_modline5_max"] = 127;
    programChangeMap["8_key_modline5_slew"] = 0;
    programChangeMap["8_key_modline5_destination"] = "None";
    programChangeMap["8_key_modline5_channel"] = 1;
    programChangeMap["8_key_modline5_device"] = "None";
    programChangeMap["8_key_modline5_led_green"] = "None";
    programChangeMap["8_key_modline5_led_red"] = "None";
    programChangeMap["8_key_modline5_displayLinked"] = 0;

    //Modline 6
    programChangeMap["8_key_modline6_on"] = 0;
    programChangeMap["8_key_modline6_source"] = "None";
    programChangeMap["8_key_modline6_gain"] = 1.00;
    programChangeMap["8_key_modline6_offset"] = 0.00;
    programChangeMap["8_key_modline6_table"] = "1_Lin";
    programChangeMap["8_key_modline6_min"] = 0;
    programChangeMap["8_key_modline6_max"] = 127;
    programChangeMap["8_key_modline6_slew"] = 0;
    programChangeMap["8_key_modline6_destination"] = "None";
    programChangeMap["8_key_modline6_channel"] = 1;
    programChangeMap["8_key_modline6_device"] = "None";
    programChangeMap["8_key_modline6_led_green"] = "None";
    programChangeMap["8_key_modline6_led_red"] = "None";
    programChangeMap["8_key_modline6_displayLinked"] = 0;

    //------------------------------------------------ Key9
    programChangeMap["9_key_name"] = "9KEY";
    programChangeMap["9_key_displayMode"] = 4;
    programChangeMap["9_key_prefix"] = "PG";

    //Modline 1
    programChangeMap["9_key_modline1_on"] = 1;
    programChangeMap["9_key_modline1_source"] = "Nav Yx10 & Key";
    programChangeMap["9_key_modline1_gain"] = 1.00;
    programChangeMap["9_key_modline1_offset"] = 0.00;
    programChangeMap["9_key_modline1_table"] = "1_Lin";
    programChangeMap["9_key_modline1_min"] = 0;
    programChangeMap["9_key_modline1_max"] = 127;
    programChangeMap["9_key_modline1_slew"] = 0;
    programChangeMap["9_key_modline1_destination"] = "Program";
    programChangeMap["9_key_modline1_channel"] = 1;
    programChangeMap["9_key_modline1_device"] = "SSCOM_Port_1";
    programChangeMap["9_key_modline1_led_green"] = "None";
    programChangeMap["9_key_modline1_led_red"] = "None";
    programChangeMap["9_key_modline1_displayLinked"] = 1;

    //Modline 2
    programChangeMap["9_key_modline2_on"] = 1;
    programChangeMap["9_key_modline2_source"] = "Nav Yx10 & Key";
    programChangeMap["9_key_modline2_gain"] = 1.00;
    programChangeMap["9_key_modline2_offset"] = 0.00;
    programChangeMap["9_key_modline2_table"] = "1_Lin";
    programChangeMap["9_key_modline2_min"] = 0;
    programChangeMap["9_key_modline2_max"] = 127;
    programChangeMap["9_key_modline2_slew"] = 0;
    programChangeMap["9_key_modline2_destination"] = "Program";
    programChangeMap["9_key_modline2_channel"] = 1;
    programChangeMap["9_key_modline2_device"] = "SoftStep_Expander";
    programChangeMap["9_key_modline2_led_green"] = "None";
    programChangeMap["9_key_modline2_led_red"] = "None";
    programChangeMap["9_key_modline2_displayLinked"] = 0;

    //Modline 3
    programChangeMap["9_key_modline3_on"] = 1;
    programChangeMap["9_key_modline3_source"] = "Key 9 Pressed";
    programChangeMap["9_key_modline3_gain"] = 1.00;
    programChangeMap["9_key_modline3_offset"] = 0.00;
    programChangeMap["9_key_modline3_table"] = "1_Lin";
    programChangeMap["9_key_modline3_min"] = 0;
    programChangeMap["9_key_modline3_max"] = 127;
    programChangeMap["9_key_modline3_slew"] = 0;
    programChangeMap["9_key_modline3_destination"] = "None";
    programChangeMap["9_key_modline3_channel"] = 1;
    programChangeMap["9_key_modline3_device"] = "None";
    programChangeMap["9_key_modline3_led_green"] = "True";
    programChangeMap["9_key_modline3_led_red"] = "None";
    programChangeMap["9_key_modline3_displayLinked"] = 0;

    //Modline 4
    programChangeMap["9_key_modline4_on"] = 1;
    programChangeMap["9_key_modline4_source"] = "Other Key Pressed";
    programChangeMap["9_key_modline4_gain"] = 1.00;
    programChangeMap["9_key_modline4_offset"] = 0.00;
    programChangeMap["9_key_modline4_table"] = "1_Lin";
    programChangeMap["9_key_modline4_min"] = 0;
    programChangeMap["9_key_modline4_max"] = 127;
    programChangeMap["9_key_modline4_slew"] = 0;
    programChangeMap["9_key_modline4_destination"] = "None";
    programChangeMap["9_key_modline4_channel"] = 1;
    programChangeMap["9_key_modline4_device"] = "None";
    programChangeMap["9_key_modline4_led_green"] = "Off";
    programChangeMap["9_key_modline4_led_red"] = "None";
    programChangeMap["9_key_modline4_displayLinked"] = 0;

    //Modline 5
    programChangeMap["9_key_modline5_on"] = 0;
    programChangeMap["9_key_modline5_source"] = "None";
    programChangeMap["9_key_modline5_gain"] = 1.00;
    programChangeMap["9_key_modline5_offset"] = 0.00;
    programChangeMap["9_key_modline5_table"] = "1_Lin";
    programChangeMap["9_key_modline5_min"] = 0;
    programChangeMap["9_key_modline5_max"] = 127;
    programChangeMap["9_key_modline5_slew"] = 0;
    programChangeMap["9_key_modline5_destination"] = "None";
    programChangeMap["9_key_modline5_channel"] = 1;
    programChangeMap["9_key_modline5_device"] = "None";
    programChangeMap["9_key_modline5_led_green"] = "None";
    programChangeMap["9_key_modline5_led_red"] = "None";
    programChangeMap["9_key_modline5_displayLinked"] = 0;

    //Modline 6
    programChangeMap["9_key_modline6_on"] = 0;
    programChangeMap["9_key_modline6_source"] = "None";
    programChangeMap["9_key_modline6_gain"] = 1.00;
    programChangeMap["9_key_modline6_offset"] = 0.00;
    programChangeMap["9_key_modline6_table"] = "1_Lin";
    programChangeMap["9_key_modline6_min"] = 0;
    programChangeMap["9_key_modline6_max"] = 127;
    programChangeMap["9_key_modline6_slew"] = 0;
    programChangeMap["9_key_modline6_destination"] = "None";
    programChangeMap["9_key_modline6_channel"] = 1;
    programChangeMap["9_key_modline6_device"] = "None";
    programChangeMap["9_key_modline6_led_green"] = "None";
    programChangeMap["9_key_modline6_led_red"] = "None";
    programChangeMap["9_key_modline6_displayLinked"] = 0;

    //------------------------------------------------ Key10
    programChangeMap["10_key_name"] = "0KEY";
    programChangeMap["10_key_displayMode"] = 4;
    programChangeMap["10_key_prefix"] = "PG";

    //Modline 1
    programChangeMap["10_key_modline1_on"] = 1;
    programChangeMap["10_key_modline1_source"] = "Nav Yx10 & Key";
    programChangeMap["10_key_modline1_gain"] = 1.00;
    programChangeMap["10_key_modline1_offset"] = 0.00;
    programChangeMap["10_key_modline1_table"] = "1_Lin";
    programChangeMap["10_key_modline1_min"] = 0;
    programChangeMap["10_key_modline1_max"] = 127;
    programChangeMap["10_key_modline1_slew"] = 0;
    programChangeMap["10_key_modline1_destination"] = "Program";
    programChangeMap["10_key_modline1_channel"] = 1;
    programChangeMap["10_key_modline1_device"] = "SSCOM_Port_1";
    programChangeMap["10_key_modline1_led_green"] = "None";
    programChangeMap["10_key_modline1_led_red"] = "None";
    programChangeMap["10_key_modline1_displayLinked"] = 1;

    //Modline 2
    programChangeMap["10_key_modline2_on"] = 1;
    programChangeMap["10_key_modline2_source"] = "Nav Yx10 & Key";
    programChangeMap["10_key_modline2_gain"] = 1.00;
    programChangeMap["10_key_modline2_offset"] = 0.00;
    programChangeMap["10_key_modline2_table"] = "1_Lin";
    programChangeMap["10_key_modline2_min"] = 0;
    programChangeMap["10_key_modline2_max"] = 127;
    programChangeMap["10_key_modline2_slew"] = 0;
    programChangeMap["10_key_modline2_destination"] = "Program";
    programChangeMap["10_key_modline2_channel"] = 1;
    programChangeMap["10_key_modline2_device"] = "SoftStep_Expander";
    programChangeMap["10_key_modline2_led_green"] = "None";
    programChangeMap["10_key_modline2_led_red"] = "None";
    programChangeMap["10_key_modline2_displayLinked"] = 0;

    //Modline 3
    programChangeMap["10_key_modline3_on"] = 1;
    programChangeMap["10_key_modline3_source"] = "Key 0 Pressed";
    programChangeMap["10_key_modline3_gain"] = 1.00;
    programChangeMap["10_key_modline3_offset"] = 0.00;
    programChangeMap["10_key_modline3_table"] = "1_Lin";
    programChangeMap["10_key_modline3_min"] = 0;
    programChangeMap["10_key_modline3_max"] = 127;
    programChangeMap["10_key_modline3_slew"] = 0;
    programChangeMap["10_key_modline3_destination"] = "None";
    programChangeMap["10_key_modline3_channel"] = 1;
    programChangeMap["10_key_modline3_device"] = "None";
    programChangeMap["10_key_modline3_led_green"] = "True";
    programChangeMap["10_key_modline3_led_red"] = "None";
    programChangeMap["10_key_modline3_displayLinked"] = 0;

    //Modline 4
    programChangeMap["10_key_modline4_on"] = 1;
    programChangeMap["10_key_modline4_source"] = "Other Key Pressed";
    programChangeMap["10_key_modline4_gain"] = 1.00;
    programChangeMap["10_key_modline4_offset"] = 0.00;
    programChangeMap["10_key_modline4_table"] = "1_Lin";
    programChangeMap["10_key_modline4_min"] = 0;
    programChangeMap["10_key_modline4_max"] = 127;
    programChangeMap["10_key_modline4_slew"] = 0;
    programChangeMap["10_key_modline4_destination"] = "None";
    programChangeMap["10_key_modline4_channel"] = 1;
    programChangeMap["10_key_modline4_device"] = "None";
    programChangeMap["10_key_modline4_led_green"] = "Off";
    programChangeMap["10_key_modline4_led_red"] = "None";
    programChangeMap["10_key_modline4_displayLinked"] = 0;

    //Modline 5
    programChangeMap["10_key_modline5_on"] = 0;
    programChangeMap["10_key_modline5_source"] = "None";
    programChangeMap["10_key_modline5_gain"] = 1.00;
    programChangeMap["10_key_modline5_offset"] = 0.00;
    programChangeMap["10_key_modline5_table"] = "1_Lin";
    programChangeMap["10_key_modline5_min"] = 0;
    programChangeMap["10_key_modline5_max"] = 127;
    programChangeMap["10_key_modline5_slew"] = 0;
    programChangeMap["10_key_modline5_destination"] = "None";
    programChangeMap["10_key_modline5_channel"] = 1;
    programChangeMap["10_key_modline5_device"] = "None";
    programChangeMap["10_key_modline5_led_green"] = "None";
    programChangeMap["10_key_modline5_led_red"] = "None";
    programChangeMap["10_key_modline5_displayLinked"] = 0;

    //Modline 6
    programChangeMap["10_key_modline6_on"] = 0;
    programChangeMap["10_key_modline6_source"] = "None";
    programChangeMap["10_key_modline6_gain"] = 1.00;
    programChangeMap["10_key_modline6_offset"] = 0.00;
    programChangeMap["10_key_modline6_table"] = "1_Lin";
    programChangeMap["10_key_modline6_min"] = 0;
    programChangeMap["10_key_modline6_max"] = 127;
    programChangeMap["10_key_modline6_slew"] = 0;
    programChangeMap["10_key_modline6_destination"] = "None";
    programChangeMap["10_key_modline6_channel"] = 1;
    programChangeMap["10_key_modline6_device"] = "None";
    programChangeMap["10_key_modline6_led_green"] = "None";
    programChangeMap["10_key_modline6_led_red"] = "None";
    programChangeMap["10_key_modline6_displayLinked"] = 0;

    //------------------------------------------------ Nav Pad 11
    programChangeMap["nav_modlineMode"] = 0;

}
