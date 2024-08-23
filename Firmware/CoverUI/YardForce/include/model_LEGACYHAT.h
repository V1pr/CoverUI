/**
 * @file model_LEGACYHAT.h
 * @author V1pr <viper @ vipernet (dot) hu>
 * @brief YardForce SA600ECO with non-uC UI panel + HAT module model header for OpenMower https://github.com/ClemensElflein/OpenMower
 * @version 0.1
 * @date 2024-08-18
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef YARDFORCE_MDL_LEGACYHAT_H
#define YARDFORCE_MDL_LEGACYHAT_H

#include "model/LEDcontrol_LEGACYHAT.hpp"
#include "model/buttons_LEGACYHAT.h"
#include "model/hatch_LEGACYHAT.hpp"

#ifdef MOD_RAIN
#include "model/Rain_LEGACYHAT.hpp"
#endif

#ifdef MOD_EMERGENCY
#include "model/emergency_LEGACYHAT.h"
#endif

// LowLevel Serial Pins
#define UART_LL_RX PA3
#define UART_LL_TX PA2

#endif // YARDFORCE_MDL_LEGACYHAT_H
