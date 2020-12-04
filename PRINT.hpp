#pragma once
#include<iostream>
#include"command.hpp"
#include "operation.hpp"
#include"data_memory.hpp"
#include "classes.h"
namespace lab4 {
	/*!
	\brief class descriptor of the console output operation
	prints the value of a variable to the console and moves to the next line
	*/
	class print :public operation {
	private:

		std::string op;
		void mainFunc() {
			std::cout << (*var)[op]<<std::endl;
		}
	public:
		print(std::string s1) :operation("PRINT"), op(s1) {};
		print() :operation("PRINT") {};
		print& operator()() override { mainFunc();return *this; }
	};
}
