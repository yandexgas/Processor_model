#pragma once
#include<iostream>
#include"command.hpp"
#include "operation.hpp"
#include"bin_cmd.hpp"
#include"data_memory.hpp"
#include "classes.h"
namespace lab4 {
	/*!
	\brief class handle of the "more" comparison operation
	if 1 operand is greater than the second, it leaves the value "1" in the requested register, otherwise "0", which then
	are interpreted by a conditional operator.  CLass functor
	\warning this operation must be followed by a conditional operator, otherwise it will not make sense
	*/
	class more :public operation {
	private:
		std::string op1, op2;
		void mainFunc() {
			if ((*var)[op1] > (*var)[op2])
				*regi=1;
			else *regi=0;
		}
	public:
		more(std::string s1, std::string s2) :operation(">",1), op1(s1), op2(s2) {};
		more() :operation(">",1) {};
		more& operator()() override { mainFunc();return *this; }
	};
}
