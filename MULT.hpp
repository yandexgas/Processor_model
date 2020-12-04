#pragma once
#include<iostream>
#include"command.hpp"
#include "operation.hpp"
#include"bin_cmd.hpp"
#include "data_memory.hpp"
#include "classes.h"
namespace lab4 {
	/*!
	\brief class a handle to the multiplication operation
	performs multiplication of 1 operand by the second, as with other arithmetic operations
	the result is written to the first operand, and also remains in the register
	*/
	class mult : public operation {
	private:
		std::string op1, op2;
		void mainFunc() {
			*regi=((*var)[op1]);
			(*regi) *= (*var)[op2];
			(*var)[op1] = regi->get_value();
		}
	public:
		mult(std::string s1, std::string s2) :operation("MULT",1), op1(s1), op2(s2) {};
		mult() :operation( "MULT",1) {};
		mult& operator()() override { mainFunc();return *this; }
	};
}