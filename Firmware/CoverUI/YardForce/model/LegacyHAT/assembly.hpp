/**
 * @file model_LEGACYHAT.h
 * @author V1pr <viper @ vipernet (dot) hu>
 * @brief YardForce SA600ECO with non-uC UI panel + HAT module model header for OpenMower https://github.com/ClemensElflein/OpenMower
 * @version 0.1
 * @date 2025-04-15
 *
 * @copyright Copyright (c) 2023, 2024, 2025
 *
 */
#ifndef YARDFORCE_MDL_LEGACYHAT_ASSEMBLY_HPP
#define YARDFORCE_MDL_LEGACYHAT_ASSEMBLY_HPP

#include "../../include/Buttons.hpp"
#include "../../include/main.h"
#include "LEDcontrol.hpp"

#ifdef MOD_EMERGENCY
#include "../../include/Emergency.hpp"
#endif

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

/*
S1 - play
S2 - 10H
S3 - 4h
S4 - Home
S5 - 6H
S6 - 8H
S7 - lock
S8 - S1
S9 - S2
*/

#define BTN_S1_PIN PA15
#define BTN_S2_PIN PB3
#define BTN_PLAY_PIN PB5
#define BTN_HOME_PIN PA12
#define BTN_LOCK_PIN PB4 // lock icon

//#define BTN_MENU_PIN PB4

#define BTN_4H_PIN PA6 // S3 - 4H
#define BTN_6H_PIN PB0 // S5 - 6H
#define BTN_8H_PIN PA10 // S6 - 8H
#define BTN_10H_PIN PB9 // S2 - 10H
//#define BTN_5_PIN PC12
//#define BTN_6_PIN PC11
//#define BTN_7_PIN PC10
//#define BTN_8_PIN PB14
//#define BTN_9_PIN PC6
//#define BTN_BACK_PIN PA15
//#define BTN_0_PIN PB9
//#define BTN_OK_PIN PB13

#define PIN_ESTOP1 PB12 // ESTOP1 from original CoverUI
#define PIN_ESTOP2 PB13 // ESTOP2 from original CoverUI

#define PIN_HANDLE_BTN_1 PA8 // Handle Button1
#define PIN_HANDLE_BTN_2 PA11 // Handle Button2 (if not serial connected with Button1)

#define PIN_HALL1 PB6 // LiftX
#define PIN_HALL2 PA9 // Left bumper
#define PIN_HALL3 PB15 // Lift
#define PIN_HALL4 PB14 // Right bumper

// checkme
#define PIN_RAIN PB1             // Need to be soldered with a cable bridge from FB2/JP2 to R79/PB1
#define RAIN_ADC_THRESHOLD 700   // Why a threshold? Cause it could be made configurable on (Stock-)CoverUI (if i.e. required due to inaccuracy)
#define RAIN_PROCESS_PERIOD 5000 // c.ez proposed "once a second or every 10 seconds"

extern LEDcontrolLegacyHAT leds;

class ButtonsLegacyHAT : public Buttons {
    public:
     ButtonsLegacyHAT(const std::map<uint8_t, ButtonDef> &t_kBtnDefByNumMap) : Buttons(t_kBtnDefByNumMap) {};
 
     /**
      * @brief Check if one of the "magic buttons" got pressed and do his function.
      * LOCK + 4H = Display FW version
      * LOCK + 10H = LED animation
      */
     void handle_sys_req() override {
         if (!is_pressed(BTN_LOCK_NUM))
             return;
 
         if (is_pressed(BTN_10H_NUM))
             leds.sequence_start(&LEDcontrol::sequence_animate_handler);
         else if (is_pressed(BTN_4H_NUM))
             leds.show_num(FIRMWARE_VERSION);
         return;
     };
};
 
extern ButtonsLegacyHAT buttons;

// leds and buttons are needed!
#include "Hatch.hpp"

#ifdef MOD_RAIN
#include "../../include/Rain.hpp"
#endif

// LowLevel Serial Pins
#define UART_LL_RX PA3
#define UART_LL_TX PA2

#endif // YARDFORCE_MDL_LEGACYHAT_ASSEMBLY_HPP
