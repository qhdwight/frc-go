#pragma once
#include <stdint.h>

#include "nlohmann/json.hpp"
#include "ctre/configparams/ConfigTypes.h"

/**
 * Tuner uses a JSON library that does not explicitely support unsigned integers.
 * So when Tuner receives json values, even though its meant to be unsigned, Tuner
 * will parse as an Int32.  This can fire a cast exception if there is a config value
 * that is unsigned and exceeds 0x7FffFFff.  This should be unlikely but
 * cap the value to ensure we don't trip Tuner.
 */
static uint32_t TunerUnsignedWorkaround(uint32_t value)
{
	if (value > 0x7fffffff)
		return 0x7fffffff;
	return value;
}
