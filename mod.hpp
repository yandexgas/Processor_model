#pragma once
#include<iostream>
#include"command.hpp"
#include "operation.hpp"
#include"bin_cmd.hpp"
#include"data_memory.hpp"
#include "classes.h"
namespace lab4 {
	/*!
	\brief class handle for a division operation with remainder
	performs division with remainder and writes the result to the first operand, the functor class
	*/
	class mod:public operation {
	private:

		std::string op1, op2;
		void mainFunc() {
			*regi=((*var)[op1]);
			(*regi) %= (*var)[op2];
			(*var)[op1] = regi->get_value();
		}
	public:
		mod(std::string s1, std::string s2) :operation("MOD",1), op1(s1), op2(s2) {};
		mod() :operation("MOD",1) {};
		mod& operator()() override { mainFunc();return *this; }
	};
}