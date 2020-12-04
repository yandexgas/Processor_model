#pragma once
#include<iostream>
#include"command.hpp"
#include "operation.hpp"
#include"data_memory.hpp"
#include "classes.h"
namespace lab4 {
	/*!
	\brief data declaration operation class
	performs the function of allocating memory for a new variable,
	functor class
	*/
	class dec_op :public operation {
	private:

		std::string name;
		int val;
		void mainFunc() {
			var->add_var(name, val);
		}
	public:
		/*!
	\brief constructor initializing the name of the variable and its value, as well as the base class
	value 0 - the number of required registers and: = operation name
	\param s1 variable name
	\param v variable value
	*/
		dec_op(std::string s1, int v) :operation(":="), name(s1), val(v) {};
		/*!
	\brief default constructor
	\version 0.1.2
	not used anywhere in newer versions of the program
	*/
		dec_op() :operation(":=") {};
		/*!
	\brief function call variable declaration
	overridden base class virtual function
	\return reference to the current instance
	*/
		dec_op& operator()() override { mainFunc();return *this; }
	};
}

