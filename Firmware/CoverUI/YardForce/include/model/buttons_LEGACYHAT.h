/**
 * @file buttons_LEGACYHAT.h
 * @author V1pr < viper (at) vipernet (dot) hu >
 * @brief YardForce SA600ECO non-uC CoverUI + HAT CoverUI Buttons header for OpenMower https://github.com/ClemensElflein/OpenMower
 * @version 0.1
 * @date 2024-08-18
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef YARDFORCE_BUTTONS_LEGACYHAT_H
#define YARDFORCE_BUTTONS_LEGACYHAT_H

#include <Arduino.h>
#include "../Buttons.hpp"

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

extern Buttons buttons;

#define HAS_MAGIC_BUTTONS
extern void magic_buttons();

#endif // YARDFORCE_BUTTONS_LEGACYHAT_H
