#pragma once

typedef enum _ConfigNumber_t {

	/* ---- config  ----- */
	eConfig_Bms_numTotalCells = 0x0100,
	eConfig_Bms_numLocalCells,
	eConfig_Bms_numTotalBMSes,
	eConfig_Bms_numCellsParallel,
	eConfig_Bms_balanceRangeThres_mV,
	eConfig_Bms_dischargeElecCurr1_tooHi_A,
	eConfig_Bms_dischargeElecCurr1_tooHi_ms,
	eConfig_Bms_dischargeElecCurr2_tooHi_A,
	eConfig_Bms_dischargeElecCurr2_tooHi_ms,
	eConfig_Bms_chargeElecCurr_tooHi_A,
	eConfig_Bms_chargeElecCurr_tooHi_ms,
	eConfig_Bms_vcell_tooLo_mV,
	eConfig_Bms_vcell_tooHi_mV,
	eConfig_Bms_balanceOffset_mV,
	eConfig_Bms_battTemp_tooLo_Celsius,
	eConfig_Bms_battTemp_tooLo_ms,
	eConfig_Bms_battTemp_tooHi_Celsius,
	eConfig_Bms_battTemp_tooHi_ms,
	eConfig_Bms_misc_A,
	eConfig_Bms_misc_B,
	eConfig_Bms_bDualDrive,
	eConfig_Bms_bDetectChargerUsingCurr,
	eConfig_Bms_bEnableBalanceFeatures,
	eConfig_Bms_bPriorCloseToCutoffCellsDurBal,
	eConfig_Bms_priorCloseToCutoffThreshold_mV,
	eConfig_Bms_balanceRestPeriod_Sec,

    eStatusFramePeriod = 0x12C, // Frame Period from Phoenix

    eClearFaults = 0x258, // Actual fault in Phoenix ParamEnum

    eChangeCompassUse = 800,
    eRestartKalman,
    eAccNoiseAmplificationGain,
    eMagNoiseAmplificationGain,
    eGyrNoiseAmplificationGain,
    eMaxAccKg,
    eMaxMagKg,
    eGyroBias,
    eAccelOffsets,
    eMagCal,
    eMagCalSlot,
    eMagCalRunning,
    eGyrResolution,
    eAccelKalmanBiasGain,
    eMagKalmanBiasGain,
    eTempCalRunning,
    eApplyTempCal,
    eClearTempCal,
    eDontRunThermComp,
    eChangeHeatOutput,
    eSetNoMotionCalDisable,
    eClearMagCal,
    eSetGyrSensitivity,
    eSetVsenseScalar,
    eConfigMountPoseYaw,
    eConfigMountPosePitch,
    eConfigMountPoseRoll,
    eConfigAccelScalar,


} ConfigNumber_t;


