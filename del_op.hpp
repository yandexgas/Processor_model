#pragma once
#include<iostream>
#include"command.hpp"
#include "operation.hpp"
#include"data_memory.hpp"
#include "classes.h"
namespace lab4 {
	/*!
	\brief class descriptor of the operation to delete data
	stores the name of the variable to delete and performs the function of deleting data
	*/
	class del_op :public operation {
	private:

		std::string name;
		void mainFunc() {
			var->free_var(name);
		}
	public:
		del_op(std::string s1) :operation( "DEL"), name(s1) {};
		del_op() :operation( ":=") {};
		del_op& operator()() override { mainFunc();return *this; }
	};
}

