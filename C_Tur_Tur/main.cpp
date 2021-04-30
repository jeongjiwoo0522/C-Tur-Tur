#define _CRT_SECURE_NO_WARNINGS

#include "lib/CTurtle.hpp"
#include "src/keyboard_event_listener.cpp"

using namespace cturtle;

KeyboardEventListener* KeyboardEventListener::_instance = 0;

int main() {
    KeyboardEventListener* k = KeyboardEventListener::getInstance();
    char ch;
    while (1) {
        if (k->GetProcessKey()) {
            std::cout << std::endl;
        }
    }

    TurtleScreen scr;
    Turtle turtle(scr);

    turtle.shape("square");
    turtle.speed(TS_SLOWEST);
    turtle.fillcolor({ "purple" });
    turtle.begin_fill();

    for (int i = 0; i < 4; i++) {
        turtle.forward(50);
        turtle.right(90);
    }

    turtle.end_fill();
    while (1) {
        
    }
    scr.bye();

    return 0;
}