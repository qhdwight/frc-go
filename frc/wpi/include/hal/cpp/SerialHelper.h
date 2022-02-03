// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <stdint.h>

#include <string>
#include <vector>

#include <wpi/SmallString.h>
#include <wpi/SmallVector.h>
#include <wpi/mutex.h>

#include "hal/SerialPort.h"

namespace hal {
/**
 * A class for deterministically getting information about Serial Ports.
 */
class SerialHelper {
 public:
  SerialHelper();

  /**
   * Get the VISA name of a serial port.
   *
   * @param[in] port    the serial port index
   * @param[out] status status check
   * @return the VISA name
   */
  std::string GetVISASerialPortName(HAL_SerialPort port, int32_t* status);

  /**
   * Get the OS name of a serial port.
   *
   * @param[in] port    the serial port index
   * @param[out] status status check
   * @return the OS name
   */
  std::string GetOSSerialPortName(HAL_SerialPort port, int32_t* status);

  /**
   * Get a vector of all serial port VISA names.
   *
   * @param[out] status status check
   * @return vector of serial port VISA names
   */
  std::vector<std::string> GetVISASerialPortList(int32_t* status);

  /**
   * Get a vector of all serial port OS names.
   *
   * @param[out] status status check
   * @return vector of serial port OS names
   */
  std::vector<std::string> GetOSSerialPortList(int32_t* status);

 private:
  void SortHubPathVector();
  void CoiteratedSort(wpi::SmallVectorImpl<wpi::SmallString<16>>& vec);
  void QueryHubPaths(int32_t* status);

  int32_t GetIndexForPort(HAL_SerialPort port, int32_t* status);

  // Vectors to hold data before sorting.
  // Note we will most likely have at max 2 instances, and the longest string
  // is around 12, so these should never touch the heap;
  wpi::SmallVector<wpi::SmallString<16>, 4> m_visaResource;
  wpi::SmallVector<wpi::SmallString<16>, 4> m_osResource;
  wpi::SmallVector<wpi::SmallString<16>, 4> m_unsortedHubPath;
  wpi::SmallVector<wpi::SmallString<16>, 4> m_sortedHubPath;

  int32_t m_resourceHandle;

  static wpi::mutex m_nameMutex;
  static std::string m_usbNames[2];
};
}  // namespace hal
