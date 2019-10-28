#include "phoenix.h"

#include "ctre/phoenix/motorcontrol/can/TalonSRX.h"

#define TALON(ctalon) ((ctre::TalonSRX*) ctalon)

namespace ctre {
    using ctre::phoenix::motorcontrol::ControlMode;
    using ctre::phoenix::motorcontrol::can::TalonSRX;
}

extern "C" {
    CTalon* CTRE_CreateTalon(int port) {
        return (CTalon*) new ctre::TalonSRX(port);
    }

    void CTRE_Set(CTalon* talon, double output) {
        TALON(talon)->Set(ctre::ControlMode::PercentOutput, output);
    }

    void CTRE_Follow(CTalon* slave, CTalon* master) {
        TALON(slave)->Follow(*(TALON(master)));
    }
}
