package main

// #cgo CFLAGS: -g -Wall -Iinclude
// #cgo LDFLAGS: -Llib/simulated -lwpiHal -lwpilibc -lwpiutil -lstdc++
// #include "hal/HAL.h"
import "C"
import (
	"fmt"
	"os"
	"runtime"
	"time"
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

func hasFlag(b byte, i byte) bool {
	return b & i != 0
}

func getHalStatusFlags() byte {
	var cControlWord C.HAL_ControlWord
	C.HAL_GetControlWord(&cControlWord)
	flags := C.GoBytes(unsafe.Pointer(&cControlWord), C.sizeof_HAL_ControlWord)[0]
	return flags
}

func getJoystickAxes() {
	var cAxes C.HAL_JoystickAxes
	C.HAL_GetJoystickAxes(0, &cAxes)
	fmt.Printf("%+v\n", cAxes)
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
	lastMode := None
	modeFunc := func(mode int, init, periodic func()) {
		if lastMode != mode {
			init()
		}
		periodic()
	}
	for {
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
		time.Sleep(500 * time.Millisecond)
	}
}

func disabledInit() {

}

func disabledPeriodic() {

}

func robotPeriodic() {
	getJoystickAxes()
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
	var cAxes C.HAL_JoystickAxes
	C.HAL_GetJoystickAxes(0, &cAxes)
	fmt.Printf("%+v\n", cAxes)
}
