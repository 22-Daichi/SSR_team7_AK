#include "ak/device/Arm.hpp"

ak::device::Arm::Arm()
    : lift(ak::assign::LIFT_PWM_PIN, ak::assign::LIFT_PWM_CH), hand(ak::assign::HAND_PWM_PIN, ak::assign::HAND_PWM_CH) {
}
ak::device::Arm::Arm(ak::device::Servo lift, ak::device::Servo hand) : lift(lift), hand(hand) {
}

auto ak::device::Arm::setup() -> void {
    this->hand.setup();
    this->lift.setup();

    this->stop();
}

auto ak::device::Arm::stop() -> void {
    this->set_value(ak::output::Arm::stop());
}

auto ak::device::Arm::set_value(const ak::output::Arm &value) -> void {
    this->hand.set_value(value.hand);
    this->lift.set_value(value.lift);
}
