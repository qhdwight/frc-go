package main

// #cgo CFLAGS: -g -Wall -Iinclude
// #cgo LDFLAGS: -Llib/simulated -lwpiHal -lwpilibc -lwpiutil -lstdc++
// #include "hal/HAL.h"
import "C"
import (
	"fmt"
	"os"
	"runtime"
	"unsafe"
)

const (
	FEnabled = 1 << iota
	FAutonomous
	FTest
	FEStop
	FFMSAttached
	FDSAttached
)

const (
	None = iota
	Disabled
	Autonomous
	Teleop
	Test
)

const (
	Period = 0.02
)

func hasFlag(b, i byte) bool {
	return b & i != 0
}

func handleErrorStatus(status C.int32_t) {
	if status != 0 {
		panic(status)
	}
}

func getHalStatusFlags() byte {
	var cControlWord C.HAL_ControlWord
	C.HAL_GetControlWord(&cControlWord)
	flags := C.GoBytes(unsafe.Pointer(&cControlWord), C.sizeof_HAL_ControlWord)[0]
	return flags
}

func getFPGATime() float64 {
	status := C.int32_t(0)
	time := float64(C.HAL_GetFPGATime(&status)) * 1e-6
	handleErrorStatus(status)
	return time
}

func getJoystickAxis(port, axis int) float64 {
	var cAxes C.HAL_JoystickAxes
	C.HAL_GetJoystickAxes(C.int32_t(port), &cAxes)
	return float64(cAxes.axes[axis])
}

func init() {
	runtime.LockOSThread()
}

func main() {
	if C.HAL_Initialize(500, 0) == 0 {
		os.Exit(-1)
	}
	fmt.Println("HAL Initialized")
	C.HAL_ObserveUserProgramStarting()
	status := C.int32_t(0)
	notifier := C.HAL_InitializeNotifier(&status)
	handleErrorStatus(status)

	expirationTime := getFPGATime() + Period
	C.HAL_UpdateNotifierAlarm(notifier, C.uint64_t(expirationTime * 1e6), &status)
	handleErrorStatus(status)

	lastMode := None
	modeFunc := func(mode int, init, periodic func()) {
		if lastMode != mode {
			init()
		}
		periodic()
	}
	for {
		currentTime := C.HAL_WaitForNotifierAlarm(notifier, &status)
		if currentTime == 0 || status != 0 {
			break
		}
		expirationTime += Period
		C.HAL_UpdateNotifierAlarm(notifier, C.uint64_t(expirationTime * 1e6), &status)
		handleErrorStatus(status)

		flags := getHalStatusFlags()
		isDisabled := !hasFlag(flags, FEnabled) || !hasFlag(flags, FDSAttached)
		if isDisabled {
			modeFunc(Disabled, disabledInit, func() {
				C.HAL_ObserveUserProgramDisabled()
				disabledPeriodic()
			})
		} else if isAutonomous := hasFlag(flags, FAutonomous); isAutonomous {
			modeFunc(Autonomous, autonomousInit, func() {
				C.HAL_ObserveUserProgramAutonomous()
				autonomousPeriodic()
			})
		} else if isOperatorControl := !hasFlag(flags, FAutonomous) && !hasFlag(flags, FTest); isOperatorControl {
			modeFunc(Teleop, teleopInit, func() {
				C.HAL_ObserveUserProgramTeleop()
				teleopPeriodic()
			})
		} else {
			modeFunc(Test, testInit, func() {
				C.HAL_ObserveUserProgramTest()
				testPeriodic()
			})
		}
		robotPeriodic()
	}
	C.HAL_StopNotifier(notifier, &status)
	C.HAL_CleanNotifier(notifier, &status)
}

func disabledInit() {

}

func disabledPeriodic() {

}

func robotPeriodic() {

}

func testInit() {

}

func testPeriodic() {

}

func autonomousInit() {

}

func autonomousPeriodic() {

}

func teleopInit() {

}

func teleopPeriodic() {

}
