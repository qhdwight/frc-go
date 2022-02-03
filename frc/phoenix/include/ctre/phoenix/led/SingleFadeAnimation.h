#pragma once

#include "ctre/phoenix/led/BaseTwoSizeAnimation.h"

namespace ctre {namespace phoenix {namespace led {

/**
 * Animation that fades into and out of a specified color
 */
class SingleFadeAnimation : public BaseTwoSizeAnimation {
public:
    /**
     * Constructor for a SingleFadeAnimation
     * @param r How much red should the color have [0, 255]
     * @param g How much green should the color have [0, 255]
     * @param b How much blue should the color have [0, 255]
     * @param w How much white should the color have [0, 255]
     * @param speed How fast should the color travel the strip [0, 1]
     * @param numLed How many LEDs the CANdle controls
     */
    SingleFadeAnimation(int r, int g, int b, int w = 0, double speed = 1, int numLed = -1);
};

} // namespace led
} // namespace phoenix
} // namespace ctre
