SoftStep firmware versions 94 and below did not use a bootloader. This would occasionally allow some units to become corrupted/bricked. A bootloader protects firmware from corruption, so we have opted to upgrade all units. This process is done automatically with the new 2.1.0 editor, but can be done manually as well.

The following files are included in this package:

##########################################
Softstep-99-bootloader-trojan-horse.syx
##########################################
this file contains a "trojan horse" bootloader image, disguised in the older firmware format. Sending this image to a version 94 or older SoftStep will install the new bootloader. This change cannot be undone.

##########################################
Softstep-enter-bootloader.syx 
##########################################
Once the bootloader is installed, send this file to the SoftStep to put it into bootloader mode. This is required prior to sending any of the below updates. 


##########################################
Softstep_Firmware_v0.9.8.syx
##########################################
Firmware verion 0.9.8 uses the old "SSCOM" port names, and is compatible with older editors. This is useful if you're using an older version of MacOS and cannot run the 2.1.0 editor, which requires the new port names.

##########################################
Softstep_Firmware_v1.0.x.syx
##########################################
Firmware version 1.0.x uses the new "SoftStep Control Surface" and "SoftStep Expander" port names, and is required in order to use editor version 2.1.0 or later. 

##########################################
Softstep_Firmware_v2.0.x.syx
##########################################
Firmware version 2.0.x was released with SoftStep3, and includes bug fixes and new features for all SoftStep users.


Note: Windows does not properly display USB MIDI portname descriptors, and some applications will report "SoftStep" for the control surface, and "MIDIIN2 (SoftStep)" for the expander.