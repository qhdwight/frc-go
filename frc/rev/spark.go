package rev

// #cgo CFLAGS: -I${SRCDIR}/include -I/Users/quintin/.gradle/toolchains/frc/2019/roborio/arm-frc2019-linux-gnueabi/usr/include/c++/7.3.0 -I/Users/quintin/.gradle/toolchains/frc/2019/roborio/arm-frc2019-linux-gnueabi/usr/include/c++/7.3.0/arm-frc2019-linux-gnueabi
// #cgo CXXFLAGS: -I${SRCDIR}/include
// #cgo LDFLAGS: -L${SRCDIR}/../lib/athena -lwpiHal -lwpiutil -lstdc++ -lm -lFRC_NetworkCommunication -lNiFpga -lNiFpgaLv -lniriodevenum -lniriosession -lNiRioSrv -lRoboRIO_FRC_ChipObject -lvisa -Llib/athena -lSparkMaxDriver
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
