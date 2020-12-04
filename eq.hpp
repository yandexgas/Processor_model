
#pragma once
#include<iostream>
#include"command.hpp"
#include "operation.hpp"
#include"bin_cmd.hpp"
#include"data_memory.hpp"
#include "classes.h"
namespace lab4 {
	/*!
	\brief assignment descriptor class
	stores variable names from data memory and assigns to the first variable the value of the second
	*/
	class eq:public operation {
	private:

		std::string op1, op2;
		void mainFunc() {
			
			(*regi) = (*var)[op2];
			(*var)[op1] = regi->get_value();
		}
	public:
		eq(std::string s1, std::string s2) :operation( "EQ",1), op1(s1), op2(s2) {};
		eq() :operation("EQ",1) {};
		eq& operator()() override { mainFunc();return *this; }
	};
}
