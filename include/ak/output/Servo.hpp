#pragma once

#include <Arduino.h>

namespace ak::output {
struct Servo
{
    int16_t duty;

    static auto stop() -> Servo;
};
}  // namespace ak::output
