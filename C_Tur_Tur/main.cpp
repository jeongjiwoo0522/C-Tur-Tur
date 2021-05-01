#pragma once

#include <conio.h>
#include <iostream>
#include "lib/CTurtle.hpp"

enum class KeyInputType {
    LEFT = 75,
    RIGHT = 77,
    UP = 72,
    ESC = 27,
    DOWN = 80,
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

    KeyInputType GetProcessKey() {
        int ch;
        if (_kbhit()) {
            ch = _getch();
            if (ch == 0xE0 || ch == 0) {
                ch = _getch();
                return static_cast<KeyInputType>(ch);
            }
            else {
                return KeyInputType::OtherKey;
            }
        } 
        else {
            return KeyInputType::OtherKey;
        }
    }

protected:
    KeyboardEventListener() {}

private:
    static KeyboardEventListener* _instance;
};

KeyboardEventListener* KeyboardEventListener::_instance = 0;

class CTurTurMover {
public:
    virtual void Left() = 0;
    virtual void Right() = 0;
    virtual void Up() = 0;
    virtual void Down() = 0;
};

class TestCTurTurMover : CTurTurMover {
public:
    void Left() override {
        std::cout << "left";
    }

    void Right() override {
        std::cout << "right";
    }

    void Up() override {
        std::cout << "up";
    }

    void Down() override {
        std::cout << "down";
    }
};

int main() {
    KeyboardEventListener* k = KeyboardEventListener::getInstance();
    TestCTurTurMover mover;

    cturtle::TurtleScreen scr;
    cturtle::Turtle turtle(scr);

    turtle.speed(cturtle::TS_SLOWEST);
    turtle.fillcolor({ "purple" });
    turtle.begin_fill();

    while (1) {
        KeyInputType keyInput = k->GetProcessKey();

        switch (keyInput) {
        case KeyInputType::LEFT:
            mover.Left();
            break;
        case KeyInputType::RIGHT:
            mover.Right();
            break;
        case KeyInputType::UP:
            mover.Up();
            turtle.forward(10);
            break;
        case KeyInputType::DOWN:
            mover.Down();
            break;
        case KeyInputType::ESC:
            exit(1);
        default:
            continue;
        }

        std::cout << std::endl;
    }

    turtle.end_fill();
    scr.bye();

    return 0;
}