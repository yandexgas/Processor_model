#pragma once
#include<iostream>
#include"command.hpp"
#include "read_op.hpp"
#include "classes.h"
namespace lab4 {
	/*!
	\brief class descriptor of command to read from console
	stores the variable name to read
	*/
	class read :public command {
	private:
		std::string name;
	public:
		read(std::string n, std::string l = "") :name(n), command(l) { command::oper = new read_op(name); }
		void show() override { std::cout << "READ " << name << " "  << "; " << command::link << std::endl; }
		void operator()() override { (*oper)(); }
	};
}