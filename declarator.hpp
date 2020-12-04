#pragma once
#include<iostream>
#include"command.hpp"
#include"dec_op.hpp"
#include "classes.h"
namespace lab4 {
	/*!
	\brief class - descriptor of the data declaration statement
	harnesses the name and value of the variable for the declaration
	*/
	class declarator:public command {
	private:
			std::string name;
			int value;
	public:
		declarator(std::string n, int v, std::string l = "") :name(n), value(v), command(l) { command::oper = new dec_op(name, value); }
		void show() override { std::cout << ":= " << name << " " << value << ": " << command::link << std::endl; }
		void operator()() override { (*oper)(); }
	};
}
