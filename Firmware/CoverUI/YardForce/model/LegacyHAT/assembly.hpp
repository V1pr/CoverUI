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

/*
*
* PA11/PA12 is needed for USB CDC debug to work! Don't use it while debugging!
*
*/

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
SW1 - play
SW2 - 10H
SW3 - 4h
SW4 - Home
SW5 - 6H
SW6 - 8H
SW7 - lock
SW8 - S1
SW9 - S2
*/

#define BTN_S1_PIN PA15 // SW8 - D10; PA15
#define BTN_S2_PIN PB3 // SW9 - D11; PB3
#define BTN_PLAY_PIN PB5 // SW1; PB5
#ifdef USBD_USE_CDC
#define BTN_HOME_PIN PB7 // SW4; PA12 // we fake it to other pin, since PA12 is used by CDC
#else
#define BTN_HOME_PIN PA12 // SW4; PA12
#endif
#define BTN_LOCK_PIN PB4 // SW7 - D9; PB4

#define BTN_4H_PIN PA6 // SW3 - 4H
#define BTN_6H_PIN PB0 // SW5 - 6H
#define BTN_8H_PIN PA10 // SW6 - 8H
#define BTN_10H_PIN PB9 // SW2 - 10H

// STOP button on the outer cover
#define PIN_ESTOP1 PB12 // ESTOP1 from original CoverUI - JP10 on LegacyHAT - 9 pin connector + LevelShift
#define PIN_ESTOP2 PB13 // ESTOP2 from original CoverUI - JP10 on LegacyHAT - 9 pin connector + LevelShift

// handle with 2 switches on either sidesx
#define PIN_HANDLE_BTN_1 PA8 // Handle Button1 - on the LegacyHAT, PB15 if on OEM-CoverUI
#ifndef USBD_USE_CDC // usb CDC debug uses PA11
#define PIN_HANDLE_BTN_2 PA11 // Handle Button2 - on the LegacyHAT, always routed to PA11
#endif

#define PIN_HALL1 PB6 // LiftX - JP1 pin 10 on OEM CoverUI
#define PIN_HALL2 PA9 // Left bumper - JP1 pin 7 on OEM CoverUI
#define PIN_HALL3 PB14 // Lift - JP1 pin 4 on OEM CoverUI
#define PIN_HALL4 PB13 // Right bumper - JP1 pin 1 on OEM CoverUI

// checkme
#define PIN_RAIN PB1             
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
