
#pragma once

#include <stdint.h>

typedef struct _GET_INFO_RESPONSE
{	
	uint8_t app_version_major;
	uint8_t app_version_minor;
	uint8_t bl_version_major;
	uint8_t bl_version_minor;
	uint8_t device_serial_L8[8];
	uint8_t date_day;
	uint8_t date_month;
	uint8_t date_year_l;
	uint8_t date_year_h;
	uint8_t man_rev_major;
	uint8_t man_rev_minor;
	uint8_t chip_id;
	/* getInfoApiVersion = 2 or 3 extensions */
	uint8_t getInfoApiVersion; // technically it is int8_t in the diag server.
	uint8_t man_rev2_major;
	uint8_t man_rev2_minor;
	/* getInfoApiVersion = 4 extensions */
	uint8_t app_version_bugfix;
	uint8_t app_version_build;
	uint8_t device_serial_H8[8]; // upper byte is typically zero
    #define GET_INFO_STRING_CAPACITY            (32)
    uint8_t model[GET_INFO_STRING_CAPACITY];
    uint8_t vendr[GET_INFO_STRING_CAPACITY];
} GET_INFO_RESPONSE;


/* --------------------------- DIAGNOSTIC CODES --------------------------- */
//9.2 Diagnostic and communication control functional unit
#define DIAG_DiagnosticSessionControl 	0x10	 		// enter bootloader(1)
	#define DIAG_SubFunc_defaultSession		 	(1)		// enter bootloader(1)
	#define DIAG_SubFunc_ECUProgrammingSession 	(2)
	
#define DIAG_ECUReset 					0x11
#define DIAG_SecurityAccess 			0x27
#define DIAG_CommunicationControl 		0x28
#define DIAG_TesterPresent 				0x3E
#define DIAG_SecuredDataTransmission 	0x84
#define DIAG_ControlDTCSetting			0x85
#define DIAG_ResponseOnEvent 			0x86
#define DIAG_LinkControl 				0x87

//9.3  Data transmission functional unit 
#define DIAG_ReadDataByIdentifier 				0x22
#define DIAG_ReadMemoryByAddress 				0x23
#define DIAG_ReadScalingDataByIdentifier 		0x24
#define DIAG_ReadDataByPeriodicIdentifier 		0x2A
#define DIAG_DynamicallyDefineDataIdentifier 	0x2C
#define DIAG_WriteDataByIdentifier 				0x2E
#define DIAG_WriteMemoryByAddress 				0x3D

//9.4  Stored data transmission functional unit
#define DIAG_ReadDTCInformation 			0x19 
#define DIAG_ClearDiagnosticInformation 	0x14

//9.5  Input/Output control functional unit
#define DIAG_InputOutputControlByIdentifier 0x2F

//9.6  Remote activation of routine functional unit
#define DIAG_RoutineControl 				0x31		// erase firmware(2)
	#define DIAG_SubFunc_startRoutine	(1)				// erase firmware(2)
	#define DIAG_SubFunc_stopRoutine	(2)
	
	#define DIAG_Parameter_eraseMemory						0xFF00  		// erase firmware(2)
	#define DIAG_Parameter_checkProgrammingDependencies		0xFF01   

//9.7  Upload/Download functional unit
#define DIAG_RequestDownload 				0x34 
#define DIAG_RequestUpload 					0x35 
#define DIAG_TransferData 					0x36 
#define DIAG_RequestTransferExit 			0x37 

//Custom Services
#define DIAG_GetInfo 					0xB0 
#define DIAG_WriteEncryptedSector		0xB1 
//#define DIAG_ReadEncryptedSector		0xB2 /* because these are not secure, no longer supported */
//#define DIAG_WriteSector				0xB3 /* because these are not secure, no longer supported */
//#define DIAG_ReadSector				0xB4 /* because these are not secure, no longer supported */
#define DIAG_Validate					0xB5
#define DIAG_Authenticate				0xB6
#define DIAG_Erase						0xB7
#define DIAG_RunApp						0xB8
#define DIAG_EnterBootloader			0xB9
#define DIAG_Notused					0xBA
#define DIAG_Status						0xBB
#define DIAG_Reset						0xBC
#define DIAG_SetId						0xBD
//#define DIAG_ReadSettingsSector			0xBE  /* because these do not delineate EOL/MOL, will be deprecated */
//#define DIAG_WriteSettingsSector		0xBF  /* because these do not delineate EOL/MOL, will be deprecated */
//#define DIAG_ReadCalSector				0xC0  /* because these do not delineate EOL/MOL, will be deprecated */
//#define DIAG_WriteCalSector				0xC1  /* because these do not delineate EOL/MOL, will be deprecated */
//#define DIAG_WritePartialCalSector		0xC2  /* because these do not delineate EOL/MOL, will be deprecated */
#define DIAG_GetAllConfigs		0xC3        /* Application: Get All Configs */
#define DIAG_SetAllConfigs		0xC4        /* Application: Set All Configs */
#define DIAG_AppDiagServices    0xC5        /* Application: FaultLog (clearing) */
    #define DIAG_AppDiagServices_SubCmdClearFaults		0x00
    #define DIAG_AppDiagServices_SubCmdFactoryDefault	0x01
    #define DIAG_AppDiagServices_SubCmdGetConfig		0x02
    #define DIAG_AppDiagServices_SubCmdSetConfig		0x03
    #define DIAG_AppDiagServices_SubCmdPgnRates 		0x04
    #define DIAG_AppDiagServices_SubCmdAutoSetID 		0x05

//                      		0xC6        /* reserved for application */
#define DIAG_SetUserDescription			0xC7
#define DIAG_GetUserDescription			0xC8
#define DIAG_SetCustomDescription			0xC9   // was renamed from DIAG_SetOemDescription
#define DIAG_GetCustomDescription			0xCA   // was renamed from DIAG_GetOemDescription
//#define DIAG_SoleClient					0xCB /* enable a time period where diag server only serves one client */
//	#define DIAG_SoleClient_SubCmd0		(0)
//	#define DIAG_SoleClient_SubCmd1		(1)
//	#define DIAG_SoleClient_NoAccessErroCode	(-30)
//	#define DIAG_SoleClient_BadRequest			(-31)
//	#define DIAG_SoleClient_InvalidAction		(-32)
//	#define DIAG_SoleClient_Busy				(-33)
//#define DIAG_CacheEncryptedSector		0xCC    /* not supported */
//#define DIAG_WriteCachedEncryptedSector	0xCD    /* not supported */
//#define DIAG_ReadPartialCalSector		0xCE    /* deprecated ? */
//#define DIAG_EraseCalSector			0xCF    /* deprecated ? */
#define DIAG_AskVerifierChallenge		0xD0
#define DIAG_WriteEnumeratedBlock		0xD1
#define DIAG_ReadEnumeratedBlock		0xD2
    /* sub commands for read and write enumerated blocks */

#define DIAGRESP_NegativeResp 					0x7F
    /* the error codes can be found in ctre/error/error.h */
//#define DIAGRESP_RespCode_ResponsePending			0x78
//#define DIAGRESP_RespCode_ServiceNotSupported		0x11
//#define DIAGRESP_RespCode_CannotBeBroadcast			0x01
//#define DIAGRESP_RespCode_NoSetRequestPresent		0x02
//#define DIAGRESP_RespCode_UnknownSubCmd				0x03
//#define DIAGRESP_RespCode_SetAllSettings_ZeroSz		(uint8_t)(-1) // 0xFF
//#define DIAGRESP_RespCode_SetAllSettings_SzTooSmall	(uint8_t)(-2) // 0xFE
//#define DIAGRESP_RespCode_SetAllSettings_BadVers	(uint8_t)(-3) // 0xFD
//#define DIAGRESP_RespCode_OnlyAvailInApp			(uint8_t)(-4) // 0xFC
//#define DIAGRESP_RespCode_InsuffAccessLevel			(uint8_t)(-5) // 0xFB
//#define DIAGRESP_RespCode_InvalidParam				(uint8_t)(-6) // 0xFA
//#define DIAGRESP_RespCode_InvalidAccessLevel		(uint8_t)(-7) // 0xFF
//#define DIAGRESP_RespCode_InvalidLen				(uint8_t)(-10) // 0xF6
//#define DIAGRESP_RespCode_InvalidSectorSz			DIAGRESP_RespCode_InvalidLen
//#define DIAGRESP_RespCode_SectorSzTooBig			(uint8_t)(-11) // 0xF5
//#define DIAGRESP_RespCode_ServiceNotAllowed			(uint8_t)(-12) // 0xF4
//#define DIAGRESP_RespCode_InvalidSerializedBlockSz	(uint8_t)(-13) // 0xF3, block size in the sector is invalid.
//// -30s are for soleClient stuff in BL
//#define DIAGRESP_RespCode_GadgeteerUart_NotPresent	(uint8_t)(0x20)
//#define DIAGRESP_RespCode_GadgeteerUart_SerFull		(uint8_t)(0x21)
