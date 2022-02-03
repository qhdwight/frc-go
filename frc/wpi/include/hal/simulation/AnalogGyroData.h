// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "hal/Types.h"
#include "hal/simulation/NotifyListener.h"

#ifdef __cplusplus
extern "C" {
#endif

void HALSIM_ResetAnalogGyroData(int32_t index);
int32_t HALSIM_RegisterAnalogGyroAngleCallback(int32_t index,
                                               HAL_NotifyCallback callback,
                                               void* param,
                                               HAL_Bool initialNotify);
void HALSIM_CancelAnalogGyroAngleCallback(int32_t index, int32_t uid);
double HALSIM_GetAnalogGyroAngle(int32_t index);
void HALSIM_SetAnalogGyroAngle(int32_t index, double angle);

int32_t HALSIM_RegisterAnalogGyroRateCallback(int32_t index,
                                              HAL_NotifyCallback callback,
                                              void* param,
                                              HAL_Bool initialNotify);
void HALSIM_CancelAnalogGyroRateCallback(int32_t index, int32_t uid);
double HALSIM_GetAnalogGyroRate(int32_t index);
void HALSIM_SetAnalogGyroRate(int32_t index, double rate);

int32_t HALSIM_RegisterAnalogGyroInitializedCallback(
    int32_t index, HAL_NotifyCallback callback, void* param,
    HAL_Bool initialNotify);
void HALSIM_CancelAnalogGyroInitializedCallback(int32_t index, int32_t uid);
HAL_Bool HALSIM_GetAnalogGyroInitialized(int32_t index);
void HALSIM_SetAnalogGyroInitialized(int32_t index, HAL_Bool initialized);

void HALSIM_RegisterAnalogGyroAllCallbacks(int32_t index,
                                           HAL_NotifyCallback callback,
                                           void* param, HAL_Bool initialNotify);

#ifdef __cplusplus
}  // extern "C"
#endif
