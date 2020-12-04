#pragma once
#include<iostream>
#include"command.hpp"
#include "operation.hpp"
#include"data_memory.hpp"
#include "classes.h"
namespace lab4 {
	/*!
	\brief class descriptor of the console read operation
	if an attempt was made to enter a non-integer value - the console will be cleared and the register will remain "0", if the entry is successful - "1"
	thus, using the condition operator, you can protect the input from incorrect data
	\warning reads the value only if the variable has already been initialized
	*/
	class read_op :public operation {
	private:

		std::string name;
		int val;
		void mainFunc() {
			std::cin >> val;
			if(!std::cin.good()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
				*regi= 0;
			}
			else {
				(*var)[name] = val;
				*regi=1;
			}
		}
	public:
		read_op(std::string s1) :operation("READ",1), name(s1), val(0) {};
		read_op() :operation("READ",1) {};
		read_op& operator()() override { mainFunc();return *this; }
	};
}