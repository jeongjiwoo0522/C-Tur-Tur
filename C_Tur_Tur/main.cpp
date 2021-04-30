#define _CRT_SECURE_NO_WARNINGS

#include "lib/CTurtle.hpp"
#include "src/keyboard_event_listener.h"
#include "src/cturtur_builder.h"

KeyboardEventListener* KeyboardEventListener::_instance = 0;

cturtle::Turtle* createTurtle(CTurTurBuilder* builder, cturtle::TurtleScreen* scr, cturtle::Turtle* turtle, std::string turtle_shape) {
    builder->BuildScreen(scr);
    builder->BuildTurtle(turtle);
    builder->BuildShape(turtle_shape);
    return builder->Build();
}

int main() {
        KeyboardEventListener* k = KeyboardEventListener::getInstance();

        CTurTurBuilder* builder = new TestCTurTurBuilder;

        cturtle::Turtle* newTurtle = createTurtle(builder, nullptr, nullptr, "test_shape");

    return 0;
}