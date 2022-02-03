#pragma once

/**
 * Expected frame version of the config all frame.  
 * Normally this is a small value, typically 3 or less.
 * But starting with the new global config api,
 * the version starts at 1.0.0.0.
 * 
 * This means the firmware will send the decorated 6byte config values.
 * 
 * 
 */
#define kConfig_FrameVersion	0x01000000 /* 1.0.0.0. */

#define kConfigFrameVersionSize	(4) /* bytes */

/**
 * Does config version support new api?
 */
static inline int DoesVersionSupportNewConfigs(uint32_t vers)
{
	/* should this be equal or >= ? */
	return vers == kConfig_FrameVersion;
}

/**
 * Error codes, basically pulled from ErrorCodes.h
 * Once we move error codes to a central location, this can be improved.
 */
#define kConfig_InvalidParamValue	(-2)  /* InvalidParamValue */
#define kConfig_InsufficientSz		(-134) /* CTRE_DI_InsufficientSz */
#define kConfig_InvalidModel		(-135) /* CTRE_DI_InvalidModel */

