#include "rev.h"

#include "rev/CANSparkMaxDriver.h"

#define SPARK(spark) ((c_SparkMax_handle) spark)

extern "C" {
    CSpark* REV_CreateSpark(int port) {
        return (CSpark*) c_SparkMax_Create(port, c_SparkMax_kBrushless);
    }

    void REV_Set(CSpark* spark, double output) {
        c_SparkMax_SetpointCommand(SPARK(spark), output, c_SparkMax_kDutyCycle, 0, 0.0f, 0);
    }
}