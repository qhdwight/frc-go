package phoenix

// #cgo CFLAGS: -I${SRCDIR}/include -I/Users/quintin/.gradle/toolchains/frc/2019/roborio/arm-frc2019-linux-gnueabi/usr/include/c++/7.3.0 -I/Users/quintin/.gradle/toolchains/frc/2019/roborio/arm-frc2019-linux-gnueabi/usr/include/c++/7.3.0/arm-frc2019-linux-gnueabi
// #cgo CXXFLAGS: -I${SRCDIR}/include
// #cgo LDFLAGS: -L${SRCDIR}/../lib/athena -lwpiHal -lwpiutil -lstdc++ -lm -lFRC_NetworkCommunication -lNiFpga -lNiFpgaLv -lniriodevenum -lniriosession -lNiRioSrv -lRoboRIO_FRC_ChipObject -lvisa -Llib/athena -lCTRE_Phoenix -lCTRE_PhoenixCCI
// #include "phoenix.h"
import "C"
import "unsafe"

type Talon struct {
	port   int
	handle unsafe.Pointer
}

func NewTalon(port int) *Talon {
	return &Talon{port, C.CTRE_CreateTalon(C.int(port))}
}

func NewSlaveTalon(port int, talon *Talon) *Talon {
	slave := NewTalon(port)
	C.CTRE_Follow(talon.handle, slave.handle)
	return slave
}

func (talon *Talon) Set(output float64) {
	C.CTRE_Set(talon.handle, C.double(output))
}

