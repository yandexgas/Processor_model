#pragma once
#include<iostream>
#include"command.hpp"
#include "operation.hpp"
#include"bin_cmd.hpp"
#include"data_memory.hpp"
#include "classes.h"
namespace lab4 {
	/*!
	\brief class descriptor of the comparison (equivalence) operation
	puts in register "1" if the operands are equal and "0" if not equal
	*/
	class sravnit :public operation {
	private:
		std::string op1, op2;
		void mainFunc() {
			if ((*var)[op1] == (*var)[op2])
				*regi=1;
			else *regi=0;
		}
	public:
		sravnit(std::string s1, std::string s2) :operation("=",1), op1(s1), op2(s2) {};
		sravnit() :operation( "=",1) {};
		sravnit& operator()() override { mainFunc();return *this; }
	};
}