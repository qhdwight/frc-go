package rev

// #cgo CFLAGS: -I${SRCDIR}/include
// #cgo CXXFLAGS: -I${SRCDIR}/include
// #cgo LDFLAGS: -L${SRCDIR}/lib -lREVLib -lREVLibDriver -L${SRCDIR}/../../build -lwpiHal -lwpiutil -lstdc++ -ldl -lm -lFRC_NetworkCommunication -lembcanshim -lfpgalvshim -lRoboRIO_FRC_ChipObject -lvisa
// #include "rev.h"
import "C"
import "unsafe"

type Spark struct {
	port   int
	handle unsafe.Pointer
}

func NewSpark(port int) *Spark {
	return &Spark{port, C.REV_CreateSpark(C.int(port))}
}

func (talon *Spark) Set(output float64) {
	C.REV_Set(talon.handle, C.double(output))
}
