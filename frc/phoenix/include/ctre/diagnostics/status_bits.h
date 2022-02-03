/**
 * Bit definitions for all the signals we get from the Diag_Status command.
 */
#pragma once

#define DIAG_Status_Byte1_Mask_ApplicationMode        0x01 // BIT0

#define DIAG_Status_Byte2_Mask_UserString             0x01 // BIT0
#define DIAG_Status_Byte2_Mask_ConfigParams           0x02 // BIT1
#define DIAG_Status_Byte2_Mask_OffsetCache            0x04 // BIT2
#define DIAG_Status_Byte2_Mask_Gadgeteer              0x08 // BIT3
#define DIAG_Status_Byte2_Mask_GadgeteerAtt           0x10 // BIT4
#define DIAG_Status_Byte2_Mask_ExplicBlink            0x20 // BIT5
#define DIAG_Status_Byte2_Mask_Simulation             0x40 // BIT6
#define DIAG_Status_Byte2_Mask_DecoratedConfigParams  0x80 // BIT7

#define DIAG_Status_Byte3_Mask_Reserved0              0x01 // BIT0
#define DIAG_Status_Byte3_Mask_Reserved1              0x02 // BIT1
#define DIAG_Status_Byte3_Mask_Reserved2              0x04 // BIT2
#define DIAG_Status_Byte3_Mask_Reserved3              0x08 // BIT3
#define DIAG_Status_Byte3_Mask_Reserved4              0x10 // BIT4
#define DIAG_Status_Byte3_Mask_Reserved5              0x20 // BIT5
#define DIAG_Status_Byte3_Mask_Reserved6              0x40 // BIT6
#define DIAG_Status_Byte3_Mask_Reserved7              0x80 // BIT7

#define DIAG_Status_Byte4_Mask_Reserved0              0x01 // BIT0
#define DIAG_Status_Byte4_Mask_Reserved1              0x02 // BIT1
#define DIAG_Status_Byte4_Mask_Reserved2              0x04 // BIT2
#define DIAG_Status_Byte4_Mask_Reserved3              0x08 // BIT3
#define DIAG_Status_Byte4_Mask_Reserved4              0x10 // BIT4
#define DIAG_Status_Byte4_Mask_Reserved5              0x20 // BIT5
#define DIAG_Status_Byte4_Mask_Reserved6              0x40 // BIT6
#define DIAG_Status_Byte4_Mask_Reserved7              0x80 // BIT7

#define DIAG_Status_Byte5_Mask_Reserved0              0x01 // BIT0
#define DIAG_Status_Byte5_Mask_Reserved1              0x02 // BIT1
#define DIAG_Status_Byte5_Mask_Reserved2              0x04 // BIT2
#define DIAG_Status_Byte5_Mask_Reserved3              0x08 // BIT3
#define DIAG_Status_Byte5_Mask_Reserved4              0x10 // BIT4
#define DIAG_Status_Byte5_Mask_Reserved5              0x20 // BIT5
#define DIAG_Status_Byte5_Mask_Reserved6              0x40 // BIT6
#define DIAG_Status_Byte5_Mask_Reserved7              0x80 // BIT7
