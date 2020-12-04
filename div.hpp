#pragma once
#include<iostream>
#include"command.hpp"
#include "operation.hpp"
#include"bin_cmd.hpp"
#include "data_memory.hpp"
#include "classes.h"
namespace lab4 {
	/*!
	\brief class descriptor of integer division operation
	stores the names of the operands and performs the function of dividing the first operand by the second, storing the result in the first
	*/
	class div : public operation {
	private:
		std::string op1, op2;
		void mainFunc() {
			*regi=((*var)[op1]);
			(*regi) /= (*var)[op2];
			(*var)[op1] = regi->get_value();
		}
	public:
		div(std::string s1, std::string s2) :operation( "DIV",1), op1(s1), op2(s2) {};
		div() :operation("DIV",1) {};
		div& operator()() override { mainFunc();return *this; }
	};
}