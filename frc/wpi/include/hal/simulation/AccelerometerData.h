// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "hal/Accelerometer.h"
#include "hal/Types.h"
#include "hal/simulation/NotifyListener.h"

#ifdef __cplusplus
extern "C" {
#endif

void HALSIM_ResetAccelerometerData(int32_t index);
int32_t HALSIM_RegisterAccelerometerActiveCallback(int32_t index,
                                                   HAL_NotifyCallback callback,
                                                   void* param,
                                                   HAL_Bool initialNotify);
void HALSIM_CancelAccelerometerActiveCallback(int32_t index, int32_t uid);
HAL_Bool HALSIM_GetAccelerometerActive(int32_t index);
void HALSIM_SetAccelerometerActive(int32_t index, HAL_Bool active);

int32_t HALSIM_RegisterAccelerometerRangeCallback(int32_t index,
                                                  HAL_NotifyCallback callback,
                                                  void* param,
                                                  HAL_Bool initialNotify);
void HALSIM_CancelAccelerometerRangeCallback(int32_t index, int32_t uid);
HAL_AccelerometerRange HALSIM_GetAccelerometerRange(int32_t index);
void HALSIM_SetAccelerometerRange(int32_t index, HAL_AccelerometerRange range);

int32_t HALSIM_RegisterAccelerometerXCallback(int32_t index,
                                              HAL_NotifyCallback callback,
                                              void* param,
                                              HAL_Bool initialNotify);
void HALSIM_CancelAccelerometerXCallback(int32_t index, int32_t uid);
double HALSIM_GetAccelerometerX(int32_t index);
void HALSIM_SetAccelerometerX(int32_t index, double x);

int32_t HALSIM_RegisterAccelerometerYCallback(int32_t index,
                                              HAL_NotifyCallback callback,
                                              void* param,
                                              HAL_Bool initialNotify);
void HALSIM_CancelAccelerometerYCallback(int32_t index, int32_t uid);
double HALSIM_GetAccelerometerY(int32_t index);
void HALSIM_SetAccelerometerY(int32_t index, double y);

int32_t HALSIM_RegisterAccelerometerZCallback(int32_t index,
                                              HAL_NotifyCallback callback,
                                              void* param,
                                              HAL_Bool initialNotify);
void HALSIM_CancelAccelerometerZCallback(int32_t index, int32_t uid);
double HALSIM_GetAccelerometerZ(int32_t index);
void HALSIM_SetAccelerometerZ(int32_t index, double z);

void HALSIM_RegisterAccelerometerAllCallbacks(int32_t index,
                                              HAL_NotifyCallback callback,
                                              void* param,
                                              HAL_Bool initialNotify);

#ifdef __cplusplus
}  // extern "C"
#endif
