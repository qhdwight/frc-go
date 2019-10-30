/*
 * Copyright (c) 2018-2019 REV Robotics
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of REV Robotics nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

extern "C" {

#ifdef __GNUC__
#define __FORMAT_TEXT(A,B) __attribute__((__format__ (__printf__, (A), (B))))
#else
#define __FORMAT_TEXT(A,B) 
#endif

typedef enum _c_SparkMax_ErrorCode {
    c_SparkMax_ErrorNone = 0,
    c_SparkMax_ErrorGeneral,
    c_SparkMax_ErrorCANTimeout,
    c_SparkMax_ErrorNotImplmented,
    c_SparkMax_ErrorHAL,
    c_SparkMax_ErrorCantFindFirmware,
    c_SparkMax_ErrorFirmwareTooOld,
    c_SparkMax_ErrorFirmwareTooNew,
    c_SparkMax_ErrorParamInvalidID,
    c_SparkMax_ErrorParamMismatchType,
    c_SparkMax_ErrorParamAccessMode,
    c_SparkMax_ErrorParamInvalid,
    c_SparkMax_ErrorParamNotImplementedDeprecated,
    c_SparkMax_ErrorFollowConfigMismatch,
    c_SparkMax_ErrorInvalid,
    c_SparkMax_ErrorSetpointOutOfRange,
    c_SparkMax_NumErrorCodes
} c_SparkMax_ErrorCode;

void c_SparkMax_SendErrorText(c_SparkMax_ErrorCode code, const char* context) __FORMAT_TEXT(2,0);
void c_SparkMax_SendErrorTextFmt(c_SparkMax_ErrorCode code, const char* context, ...) __FORMAT_TEXT(2,0);
void c_SparkMax_FlushErrors();
int c_SparkMax_ErrorSize();

} // extern "C"
