#pragma once
#include <stdint.h>
#include "ctre/packing.h"

/**
 * Simple adapter to go from bytes to formatted value.  4-byte values only.
 */
PACK_PREFIX
typedef union _RawValue_t
{
	uint32_t u32;
	int32_t i32;
	float f;
	uint8_t b[4];
} PACK_ATTRIB RawValue_t; PACK_SUFFIX;


static inline void FillRawValue_4B(RawValue_t* toFill, const uint8_t* source_4B)
{
	toFill->b[0] = source_4B[0];
	toFill->b[1] = source_4B[1];
	toFill->b[2] = source_4B[2];
	toFill->b[3] = source_4B[3];
}

/**
 * Six byte format that stores a 2 byte spn and 4 byte value.
 * This are used in the configall frame.
 */
PACK_PREFIX
typedef union _ConfigAllElement
{
	struct
	{
		uint16_t spn;
		RawValue_t value;
	};
	uint8_t bytes[6];

} PACK_ATTRIB ConfigAllElement; PACK_SUFFIX;

static inline void ZeroConfigAllElement(ConfigAllElement * elem)
{
    elem->spn = 0;
    elem->value.u32 = 0;
}

typedef ConfigAllElement ConfigParamValue_t;
