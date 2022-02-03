package phoenix

// #cgo CFLAGS: -I${SRCDIR}/include
// #cgo CXXFLAGS: -I${SRCDIR}/include
// #cgo LDFLAGS: -L${SRCDIR}/lib -lCTRE_Phoenix -lCTRE_PhoenixCCI -L${SRCDIR}/../../build -lwpiHal -lwpiutil -lstdc++ -ldl -lm -lFRC_NetworkCommunication -lembcanshim -lfpgalvshim -lRoboRIO_FRC_ChipObject -lvisa
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
