package main

// #cgo CFLAGS: -g -Wall -Iinclude
// #cgo LDFLAGS: -Llib/simulated -lwpiHal -lwpilibc -lwpiutil -lstdc++
// #include "hal/HAL.h"
import "C"
import (
	"fmt"
	"os"
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
	flags := C.GoBytes(unsafe.Pointer(&cControlWord), 4)[0]
	return flags
}

func main() {
	if C.HAL_Initialize(500, 0) == 0 {
		os.Exit(-1)
	}
	fmt.Println("HAL Initialized")
	C.HAL_ObserveUserProgramStarting()
	lastMode := None
	for {
		flags := getHalStatusFlags()
		isDisabled := !hasFlag(flags, FEnabled) || !hasFlag(flags, FDSAttached)
		if isDisabled {
			if lastMode != Disabled {
				disabledInit()
				lastMode = Disabled
			}
			disabledPeriodic()
		} else if isAutonomous := hasFlag(flags, Autonomous); isAutonomous {
			if lastMode != Autonomous {
				autonomousInit()
				lastMode = Autonomous
			}
			autonomousPeriodic()
		} else if isOperatorControl := !hasFlag(flags, Autonomous) && !hasFlag(flags, Test); isOperatorControl {
			if lastMode != Teleop {
				teleopInit()
				lastMode = Teleop
			}
			teleopPeriodic()
		} else {
			if lastMode != Test {
				testInit()
				lastMode = Test
			}
			testPeriodic()
		}
		periodic()
	}
}

func disabledInit() {

}

func disabledPeriodic() {

}

func periodic() {

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
