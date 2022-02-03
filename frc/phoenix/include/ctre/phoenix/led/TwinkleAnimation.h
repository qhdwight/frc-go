#pragma once

#include "ctre/phoenix/led/BaseTwoSizeAnimation.h"

namespace ctre {namespace phoenix {namespace led {

/**
 * Animation that randomly turns LEDs on and off to a certain color 
 */
class TwinkleAnimation : public BaseTwoSizeAnimation {
public:
    /**
     * The percentage of LEDs that are allowed to be on at any one point
     */
    enum TwinklePercent {
        /**
         * All the LEDs are allowed to turn on
         */
        Percent100 = 0,
        /**
         * 88% of LEDs are allowed to turn on
         */
        Percent88 = 1,
        /**
         * 76% of LEDs are allowed to turn on
         */
        Percent76 = 2,
        /**
         * 64% of LEDs are allowed to turn on
         */
        Percent64 = 3,
        /**
         * 42% of LEDs are allowed to turn on
         */
        Percent42 = 4,
        /**
         * 30% of LEDs are allowed to turn on
         */
        Percent30 = 5,
        /**
         * 18% of LEDs are allowed to turn on
         */
        Percent18 = 6,
        /**
         * 6% of LEDs are allowed to turn on
         */
        Percent6 = 7,
    };

    /**
     * Constructor for a TwinkleAnimation
     * @param r How much red should the color have [0, 255]
     * @param g How much green should the color have [0, 255]
     * @param b How much blue should the color have [0, 255]
     * @param w How much white should the color have [0, 255]
     * @param speed How fast should the color travel the strip [0, 1]
     * @param numLed How many LEDs the CANdle controls
     * @param divider What percentage of LEDs can be on at any point
     */
    TwinkleAnimation(int r, int g, int b, int w = 0, double speed = 1, int numLed = -1, TwinklePercent divider = TwinklePercent::Percent100);
    /**
     * Sets the percentage of LEDs that are allowed on
     * @param divider The percentage of LEDs that are allowed on at any point
     */
    void SetDivider(TwinklePercent divider);
};

} // namespace led
} // namespace phoenix
} // namespace ctre
