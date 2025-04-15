/**
 * @file emergency_LEGACYHAT.cpp
 * @author V1pr < viper (at) vipernet (dot) hu >
 * @brief YardForce SC600ECO non-uC CoverUI + HAT CoverUI Emergency class for OpenMower https://github.com/ClemensElflein/OpenMower
 * @version 0.1
 * @date 2024-08-18
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <Arduino.h>
#include "emergency_LEGACYHAT.h"
#include "../Emergency.hpp"

const EmergencyPinStateDef kEmergencyPinStateDefs[] = {
#ifdef MOD_HALL
    {PIN_HALL1, INPUT_PULLUP, Emergency_state::Emergency_lift1},
    {PIN_HALL2, INPUT_PULLUP, Emergency_state::Emergency_lift1},
    {PIN_HALL3, INPUT_PULLUP, Emergency_state::Emergency_lift2},
    {PIN_HALL4, INPUT_PULLUP, Emergency_state::Emergency_lift2},
#endif
#ifdef MOD_STOP
    {PIN_ESTOP1, INPUT_PULLUP, Emergency_state::Emergency_stop1},
    {PIN_ESTOP2, INPUT_PULLUP, Emergency_state::Emergency_stop2},
    {PIN_HANDLE_BTN_1, INPUT, Emergency_state::Emergency_handle},
    #ifdef PIN_HANDLE_BTN_2
    {PIN_HANDLE_BTN_2, INPUT, Emergency_state::Emergency_handle},
    #endif
#endif
};

Emergency emergency(kEmergencyPinStateDefs, sizeof(kEmergencyPinStateDefs) / sizeof(EmergencyPinStateDef));
