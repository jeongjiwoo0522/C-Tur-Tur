#pragma once

#include "../lib/CTurtle.hpp"

using namespace cturtle;
using namespace std;

class CTurTurBuilder {
public:
	virtual void BuildScreen(TurtleScreen* scr) {}
	virtual void BuildTurtle(Turtle* turtle) {}
	virtual void BuildShape(string str) {}
	virtual void BuildSpeed(TurtleSpeed) {}
	virtual void BuildFillColor(Color c) {}

protected: 
	CTurTurBuilder() {}

private:
	TurtleScreen* _scr;
	Turtle* turtle;
};