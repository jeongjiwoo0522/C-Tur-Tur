#pragma once

#include <conio.h>
#include <iostream>

enum class KeyType {
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

    bool GetProcessKey() {
        int ch;
        if (_kbhit()) {
            ch = _getche();
            if (ch == 0xE0 || ch == 0){
                ch = _getch();
                switch ((KeyType)ch) {
                case KeyType::LEFT:
                    std::cout << "Left";
                    break;
                case KeyType::RIGHT:
                    std::cout << "Right";
                    break;
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