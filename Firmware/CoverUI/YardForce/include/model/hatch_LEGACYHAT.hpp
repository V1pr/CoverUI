/**
 * @file hatch_LEGACYHAT.hpp
 * @author V1pr < viper (at) vipernet (dot) hu >
 * @brief YardForce SC600ECO non-uC CoverUI + HAT CoverUI Hatch header for OpenMower https://github.com/ClemensElflein/OpenMower
 * @version 0.1
 * @date 2024-08-18
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef YARDFORCE_HATCH_LEGACYHAT_HPP
#define YARDFORCE_HATCH_LEGACYHAT_HPP

#include <Arduino.h>
#include "../Hatch.hpp"

class HatchLEGACYHAT : public Hatch
{
public:

    unsigned int handle_button(unsigned int button_id, unsigned int press_cnt);
};

extern HatchLEGACYHAT hatch;

#endif // YARDFORCE_HATCH_LEGACYHAT_HPP
