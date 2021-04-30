#pragma once

#include "../lib/CTurtle.hpp"

class CTurTurBuilder {
public:
	virtual void BuildScreen(cturtle::TurtleScreen* scr) {}
	virtual void BuildTurtle(cturtle::Turtle* turtle) {}
	virtual void BuildShape(std::string str) {}
	virtual cturtle::Turtle* Build() = 0;

protected: 
	CTurTurBuilder() {}

private:
	cturtle::TurtleScreen* _scr = nullptr;
	cturtle::Turtle* turtle = nullptr;
};


class TestCTurTurBuilder : public CTurTurBuilder {
public:
	TestCTurTurBuilder() {}

	void BuildScreen(cturtle::TurtleScreen* scr) override {
		std::cout << "screan build";
	}

	void BuildTurtle(cturtle::Turtle* turtle) override {
		std::cout << "turtle build";
	}

	void BuildShape(std::string str) override {
		std::cout << "shape build";
	}

	cturtle::Turtle* Build() override {
		std::cout << "build turtle";
		return nullptr;
	}
};