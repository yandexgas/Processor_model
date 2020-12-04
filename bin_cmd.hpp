#pragma once
#include<iostream>
#include"command.hpp"
#include <string>
namespace lab4 {
	/*!
	\brief Class - a descriptor of a binary command
characterized by the names of operands in data memory
	*/
	class bin_cmd :public command {
	protected:
			std::string op1,op2;
	public:
		/*!
		\brief is the only knostructor used in other classes and applications
		initializes an instance of the class with the names of the operands, defines the type of the command by the argument, initializes the base class field with the label value
		(empty string by default)
	*/
		bin_cmd(std::string,std::string, std::string, std::string l="");
		/*!
	\brief command output to screen
	\warning the form in which the command is displayed is slightly different from the one in which it should be entered (due to a version conflict)
	prints the command to the screen in the desired format, an overridden virtual function of the base class
	*/
		void show() override { std::cout << command::oper->get_name() << " " << op1 << " " << op2 << " : " << command::getstr() << std::endl; }
		/*!
		\brief functor object
		this object, when called as a function, calls the operation corresponding to this command
		*/
		void operator()() override { (*oper)(); }
		
	};
}
