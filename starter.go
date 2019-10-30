package main

import (
	"go-frc/frc"
	"runtime"
)

func init() {
	runtime.LockOSThread()
}

func main() {
	frc.Start()
}
