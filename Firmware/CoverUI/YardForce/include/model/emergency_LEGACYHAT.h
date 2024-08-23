/**
 * @file emergency_LEGACYHAT.h
 * @author V1pr
 * @brief YardForce SC600ECO non-uC CoverUI + HAT CoverUI Emergency header for OpenMower https://github.com/ClemensElflein/OpenMower
 * @version 0.1
 * @date 2024-08-18
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef YARDFORCE_EMERGENCY_LEGACYHAT_H
#define YARDFORCE_EMERGENCY_LEGACYHAT_H

#include <Arduino.h>
#include "../Emergency.hpp"

#define PIN_STOP1 PB12 // ESTOP1
#define PIN_STOP2 PB13 // ESTOP2

#define PIN_HALL1 PB6 // LiftX
#define PIN_HALL2 PA9 // Left bumper
#define PIN_HALL3 PB15 // Lift
#define PIN_HALL4 PB14 // Right bumper

extern Emergency emergency;

#endif // YARDFORCE_EMERGENCY_LEGACYHAT_H
