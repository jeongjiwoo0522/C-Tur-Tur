#pragma once

#include <conio.h>
#include <iostream>
#include "lib/CTurtle.hpp"

enum class KeyInputType {
    LEFT = 75,
    RIGHT = 77,
    UP = 72,
    ESC = 27,
    OtherKey = -1
};

class KeyboardEventListener {
public:
    static KeyboardEventListener* getInstance() {
        if (_instance == 0) {
            _instance = new KeyboardEventListener();
        }
        return _instance;
    }

    bool GetProcessKey(cturtle::Turtle* t) {
        int ch;
        if (_kbhit()) {
            ch = _getch();
            if (ch == 0xE0 || ch == 0) {
                ch = _getch();
                switch ((KeyInputType)ch) {
                case KeyInputType::LEFT:
                    std::cout << "Left";
                    t->forward(10);
                    break;
                case KeyInputType::RIGHT:
                    std::cout << "Right";
                    t->forward(10);
                    break;
                case KeyInputType::ESC:
                    exit(1);
                default:
                    return false;
                }
                return true;
            }
            else {
                return false;
            }
        }
    }

protected:
    KeyboardEventListener() {}

private:
    static KeyboardEventListener* _instance;
};

KeyboardEventListener* KeyboardEventListener::_instance = 0;

int main() {
    KeyboardEventListener* k = KeyboardEventListener::getInstance();

    cturtle::TurtleScreen scr;
    cturtle::Turtle turtle(scr);

    turtle.shape("square");
    turtle.speed(cturtle::TS_SLOWEST);
    turtle.fillcolor({ "purple" });
    turtle.begin_fill();

    while (1) {
        if (k->GetProcessKey(&turtle)) {
            std::cout << std::endl;
        }
    }

    turtle.end_fill();
    scr.bye();

    return 0;
}