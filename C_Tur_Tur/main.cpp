#define _CRT_SECURE_NO_WARNINGS

#include "headerfile/CTurtle.hpp"

namespace ct = cturtle;

int main() {
    ct::TurtleScreen scr;
    ct::Turtle turtle(scr);
    turtle.speed(ct::TS_SLOWEST);
    turtle.fillcolor({ "purple" });
    turtle.begin_fill();
    for (int i = 0; i < 4; i++) {
        turtle.forward(50);
        turtle.right(90);
    }
    turtle.end_fill();
    while (1) {}
    scr.bye();
    return 0;
}