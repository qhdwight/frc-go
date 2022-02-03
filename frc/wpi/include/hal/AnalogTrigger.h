// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <stdint.h>

#include "hal/Types.h"

/**
 * @defgroup hal_analogtrigger Analog Trigger Functions
 * @ingroup hal_capi
 * @{
 */

// clang-format off
/**
 * The type of analog trigger to trigger on.
 */
HAL_ENUM(HAL_AnalogTriggerType) {
  HAL_Trigger_kInWindow = 0,
  HAL_Trigger_kState = 1,
  HAL_Trigger_kRisingPulse = 2,
  HAL_Trigger_kFallingPulse = 3
};
// clang-format on

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initializes an analog trigger.
 *
 * @param[in] portHandle the analog input to use for triggering
 * @param[out] status     Error status variable. 0 on success.
 * @return the created analog trigger handle
 */
HAL_AnalogTriggerHandle HAL_InitializeAnalogTrigger(
    HAL_AnalogInputHandle portHandle, int32_t* status);

/**
 * Initializes an analog trigger with a Duty Cycle input
 *
 * @param[in] dutyCycleHandle the analog input to use for duty cycle
 * @param[out] status          Error status variable. 0 on success.
 */
HAL_AnalogTriggerHandle HAL_InitializeAnalogTriggerDutyCycle(
    HAL_DutyCycleHandle dutyCycleHandle, int32_t* status);

/**
 * Frees an analog trigger.
 *
 * @param[in] analogTriggerHandle the trigger handle
 * @param[out] status Error status variable. 0 on success.
 */
void HAL_CleanAnalogTrigger(HAL_AnalogTriggerHandle analogTriggerHandle,
                            int32_t* status);

/**
 * Sets the raw ADC upper and lower limits of the analog trigger.
 *
 * HAL_SetAnalogTriggerLimitsVoltage or HAL_SetAnalogTriggerLimitsDutyCycle
 * is likely better in most cases.
 *
 * @param[in] analogTriggerHandle the trigger handle
 * @param[in] lower               the lower ADC value
 * @param[in] upper               the upper ADC value
 * @param[out] status              Error status variable. 0 on success.
 */
void HAL_SetAnalogTriggerLimitsRaw(HAL_AnalogTriggerHandle analogTriggerHandle,
                                   int32_t lower, int32_t upper,
                                   int32_t* status);

/**
 * Sets the upper and lower limits of the analog trigger.
 *
 * The limits are given as floating point voltage values.
 *
 * @param[in] analogTriggerHandle the trigger handle
 * @param[in] lower               the lower voltage value
 * @param[in] upper               the upper voltage value
 * @param[out] status              Error status variable. 0 on success.
 */
void HAL_SetAnalogTriggerLimitsVoltage(
    HAL_AnalogTriggerHandle analogTriggerHandle, double lower, double upper,
    int32_t* status);

/**
 * Sets the upper and lower limits of the analog trigger.
 *
 * The limits are given as floating point duty cycle values.
 *
 * @param[in] analogTriggerHandle the trigger handle
 * @param[in] lower               the lower duty cycle value
 * @param[in] upper               the upper duty cycle value
 * @param[out] status              Error status variable. 0 on success.
 */
void HAL_SetAnalogTriggerLimitsDutyCycle(
    HAL_AnalogTriggerHandle analogTriggerHandle, double lower, double upper,
    int32_t* status);

/**
 * Configures the analog trigger to use the averaged vs. raw values.
 *
 * If the value is true, then the averaged value is selected for the analog
 * trigger, otherwise the immediate value is used.
 *
 * This is not allowed to be used if filtered mode is set.
 * This is not allowed to be used with Duty Cycle based inputs.
 *
 * @param[in] analogTriggerHandle the trigger handle
 * @param[in] useAveragedValue    true to use averaged values, false for raw
 * @param[out] status              Error status variable. 0 on success.
 */
void HAL_SetAnalogTriggerAveraged(HAL_AnalogTriggerHandle analogTriggerHandle,
                                  HAL_Bool useAveragedValue, int32_t* status);

/**
 * Configures the analog trigger to use a filtered value.
 *
 * The analog trigger will operate with a 3 point average rejection filter. This
 * is designed to help with 360 degree pot applications for the period where the
 * pot crosses through zero.
 *
 * This is not allowed to be used if averaged mode is set.
 *
 * @param[in] analogTriggerHandle the trigger handle
 * @param[in] useFilteredValue    true to use filtered values, false for average
 *                                or raw
 * @param[out] status             Error status variable. 0 on success.
 */
void HAL_SetAnalogTriggerFiltered(HAL_AnalogTriggerHandle analogTriggerHandle,
                                  HAL_Bool useFilteredValue, int32_t* status);

/**
 * Returns the InWindow output of the analog trigger.
 *
 * True if the analog input is between the upper and lower limits.
 *
 * @param[in] analogTriggerHandle the trigger handle
 * @param[out] status Error status variable. 0 on success.
 * @return the InWindow output of the analog trigger
 */
HAL_Bool HAL_GetAnalogTriggerInWindow(
    HAL_AnalogTriggerHandle analogTriggerHandle, int32_t* status);

/**
 * Returns the TriggerState output of the analog trigger.
 *
 * True if above upper limit.
 * False if below lower limit.
 * If in Hysteresis, maintain previous state.
 *
 * @param[in] analogTriggerHandle the trigger handle
 * @param[out] status              Error status variable. 0 on success.
 * @return the TriggerState output of the analog trigger
 */
HAL_Bool HAL_GetAnalogTriggerTriggerState(
    HAL_AnalogTriggerHandle analogTriggerHandle, int32_t* status);

/**
 * Gets the state of the analog trigger output.
 *
 * @param[in] analogTriggerHandle the trigger handle
 * @param[in] type                the type of trigger to trigger on
 * @param[out] status              Error status variable. 0 on success.
 * @return the state of the analog trigger output
 */
HAL_Bool HAL_GetAnalogTriggerOutput(HAL_AnalogTriggerHandle analogTriggerHandle,
                                    HAL_AnalogTriggerType type,
                                    int32_t* status);

/**
 * Get the FPGA index for the AnlogTrigger.
 *
 * @param[in] analogTriggerHandle the trigger handle
 * @param[out] status              Error status variable. 0 on success.
 * @return the FPGA index
 */
int32_t HAL_GetAnalogTriggerFPGAIndex(
    HAL_AnalogTriggerHandle analogTriggerHandle, int32_t* status);
#ifdef __cplusplus
}  // extern "C"
#endif
/** @} */
