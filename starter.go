package main

import (
	"go-frc/frc"
	"go-frc/frc/wpi"
	"runtime"
)

func init() {
	runtime.LockOSThread()
}

func main() {
	wpi.StartTimed(frc.Robot{})
}
