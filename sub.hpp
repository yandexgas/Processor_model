#pragma once
#include<iostream>
#include"command.hpp"
#include "operation.hpp"
#include"bin_cmd.hpp"
#include "data_memory.hpp"
#include "classes.h"
namespace lab4 {
	/*!
	\brief class descriptor of the subtraction operation
	stores the value in the first operand and leaves it in the register
	*/
	class sub : public operation {
	private:
		std::string op1, op2;
		void mainFunc() {
			*regi=((*var)[op1]);
			(*regi) -= (*var)[op2];
			(*var)[op1] = regi->get_value();
		}
	public:
		sub(std::string s1, std::string s2) :operation("SUB",1), op1(s1), op2(s2) {};
		sub() :operation("SUB",1) {};
		sub& operator()() override { mainFunc();return *this; }
	};
}
