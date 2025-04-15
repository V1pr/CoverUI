/**
 * @file Rain.hpp
 * @author Apehaenger (joerg@ebeling.ws)
 * @brief YardForce Classic 500 CoverUI Rain-Sensor class for OpenMower https://github.com/ClemensElflein/OpenMower
 * @version 0.1
 * @date 2023-05-09
 *
 * @copyright Copyright (c) 2023
 *
 */

/*
 * Some measurements (AH20230509):
 *
 *                     | Simulate  |  Rain   | Still   |  Dry  |
 * MCU/Board | 23°C EU | APEC 35°C |  Water  |  Wet    | again |
 * ----------|---------|-----------|---------|---------|-------|
 * STM32F030 | 812-883 |  ~ 730    |  ~ 300  |         |       |
 * GD32F330  | 930-950 | 928-932   | 350-387 | 445-466 | >800  |
 */

#include <Arduino.h>
#include "../model_LEGACYHAT.h"
#include "Rain_LEGACYHAT.hpp"

    /**
     * @brief Read ADC of rain-sensor (with previous C8 charge impulse)
     *
     */
    void RainLEGACYHAT::read()
    {
        pinMode(PIN_RAIN, INPUT_PULLUP); // Charge C8 (FB1+FB2)
        delay(1);                        // Need a consistent delay for our different MCU clocks
        val_ = analogRead(PIN_RAIN);

        // LED_NUM 11 = LED_PIN_LOCK
        if ( val_ > RAIN_ADC_THRESHOLD ) {    
            leds.set(11, LED_on);
        } else if ( val_ > ( RAIN_ADC_THRESHOLD / 2 ) ) {    
            leds.set(11, LED_blink_fast);
        } else if ( val_ > ( RAIN_ADC_THRESHOLD / 3 ) ) {
            leds.set(11, LED_blink_slow);
        } else {
            leds.set(11, LED_off);
        }
    }

RainLEGACYHAT rain;
