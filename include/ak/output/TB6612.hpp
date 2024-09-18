#pragma once

#include <Arduino.h>

namespace ak::output {
struct TB6612
{
    uint8_t pwm1;
    uint8_t pwm2;
};
}  // namespace ak::output