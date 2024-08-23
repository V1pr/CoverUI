/**
 * @file LEDcontrol_LEGACYHAT.hpp
 * @author V1pr < viper (at) vipernet (dot) hu >
 * @brief YardForce LED driver SC600ECO non-uC CoverUI + HAT header for OpenMower https://github.com/ClemensElflein/OpenMower
 * @version 0.1
 * @date 2024-08-18
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef YARDFORCE_LEDCONTROL_LEGACYHAT_HPP
#define YARDFORCE_LEDCONTROL_LEGACYHAT_HPP

#include <Arduino.h>
#include "../LEDcontrol.hpp"

// 1st row: Lifted, Wire (WLAN), Battery empty, Charge
#define LED_PIN_LIFTED PC13
#define LED_PIN_WIRE PC15
#define LED_PIN_BAT PC14
#define LED_PIN_CHARGE PA1

// 2nd row: 4,6,8,10HR
#define LED_PIN_4HR PA4
#define LED_PIN_6HR PA5
#define LED_PIN_8HR PA7
#define LED_PIN_10HR PA0

// 3rd row: S1, S2 + LOCK
#define LED_PIN_S1 PB8
#define LED_PIN_S2 PB10
#define LED_PIN_LOCK PB2


//#define LED_NUM_BACKLIGHT 20

#define LED_ANIMATE_DELAY 20 // Delay (ms) between LEDs of animate sequence (boot/power-on anim)

class LEDcontrolLegacyHAT : public LEDcontrol
{
public:
    LEDcontrolLegacyHAT(const uint32_t *t_kPinByLedNumPtr, const size_t t_kNumLeds, void (LEDcontrol::*t_set_base10_leds_callback)(char digit)) : LEDcontrol(t_kPinByLedNumPtr, t_kNumLeds, t_set_base10_leds_callback){};

    void sequence_animate_handler() override;
    void sequence_countdown_handler() override;

    unsigned int boot_animation() override; // A short boot animation which return the amount of ms it will take
    void set_base10_leds(char digit) override;
    void force_off_num_seq_leds(bool force) override;

private:
    void show_countdown_state(unsigned int sec, LED_state state);
};

extern LEDcontrolLegacyHAT leds;

#endif // YARDFORCE_LEDCONTROL_LegacyHAT_HPP
