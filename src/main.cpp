#include <Arduino.h>

#include "ak/Delay.hpp"
#include "ak/Device.hpp"
#include "ak/Input.hpp"
#include "ak/Output.hpp"
#include "ak/System.hpp"

ak::Device dev;
ak::System sys;

void on_recieved() {
    auto input  = dev.get_input();
    auto output = sys.update(input);
    dev.set_value(output);
}

void setup() {
    Serial.begin(9600);
    dev.setup();
    sys.init();
    sys.set_forward_launcher(true, false);
    sys.set_forward_stearing(true, true, true);
    sys.set_pulse_width_arm(0, 100, 0, 90);
    sys.set_pulse_width_launcher(150, 0);
    dev.controller_attach_on_recieved(on_recieved);
}

void loop() {
}
