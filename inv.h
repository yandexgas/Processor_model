#pragma once
#include<iostream>
#include"command.hpp"
#include "operation.hpp"
#include"data_memory.hpp"
#include "classes.h"
namespace lab4 {
	/*!
	\brief class handle of the inversion operation
	changes the sign of the operand.  Functor class
	*/
	class inv :public operation {
	private:

		std::string op;
		void mainFunc() {
			(*var)[op] *= -1;
		}
	public:
		inv(std::string s1) :operation("INV"), op(s1) {};
		inv() :operation("INV") {};
		inv& operator()() override { mainFunc();return *this; }
	};
}