#pragma once
#include<iostream>
#include"command.hpp"
#include "operation.hpp"
#include"bin_cmd.hpp"
#include"data_memory.hpp"
#include "classes.h"
namespace lab4 {
	/*!
	\brief Class - declarator of ADD operation
	The class-functor, which make an addition of 2 operands in privat area and the result is placed in the 1st operand (in data memory)
	*/
	class add :public operation {
	private:	
		 std::string op1, op2;
		void mainFunc()  {
			*regi=((*var)[op1]);
			(*regi) += (*var)[op2];
			(*var)[op1] = regi->get_value();
		 }
	public:
		/*!
			\brief initializing constructor
			\param s1, s2 names of operand variables in data memory
			calls the constructor for the parent class, initializing it with the number of general - purpose registers needed for this operationand the name of the operation
			*/
		add(std::string s1, std::string s2) :operation("ADD",1), op1(s1), op2(s2) {};
		/*!
		\brief Default constructor
		\version 0.1.2
		In older versions of the program, it is not used anywhere, remained as a rudiment
		*/
		add() :operation("ADD",1) {};
		/*!
	\brief is an overloaded function call statement

	 \return reference to the current instance
	overridden base class function, calls the function for adding arguments
	*/
		add& operator()() override { mainFunc();return *this; }
	};
}
