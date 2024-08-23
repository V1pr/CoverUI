/**
 * @file Rain.cpp
 * @author Apehaenger (joerg@ebeling.ws) & V1pr
 * @brief YardForce CoverUI Rain-Sensor class for OpenMower https://github.com/ClemensElflein/OpenMower
 * @version 0.1
 * @date 2024-08-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <map>
#include <cstring>
#include "include/Rain.hpp"
#include "../BttnCtl.h" // LED_state is defined in BttnCtl.h

extern void sendMessage(void *message, size_t size);

/**
 * @brief Send 'rain' message via COBS with last read rain-sensor- value (together with (currently static) threshold)
 *
 */
void Rain::send()
{
    msg_event_rain msg = {
        .type = Get_Rain,
        .value = val_,
        .threshold = RAIN_ADC_THRESHOLD};
    sendMessage(&msg, sizeof(msg));
}

/**
 * @brief Process (read & send) rain-sensor- value together with (currently static) threshold
 *
 */
void Rain::process()
{
    if (millis() < next_period_)
        return;

    next_period_ += RAIN_PROCESS_PERIOD;
    read();
    send();
}
