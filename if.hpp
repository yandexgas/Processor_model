#pragma once
#include<iostream>
#include"command.hpp"
#include"goto.hpp"
#include"if_op.hpp"
#include "classes.h"
namespace lab4 {
	/*!
	\brief class conditional statement handle
	stores a label field for transition if the condition is true
	
	*/
	class If :public command{
		std::string link;
	public:
		If(std::string l, std::string k = "") :command(k), link(l) { command::oper = new if_op(l); }
		void show() override { std::cout << "?" << link << ";" << command::link << std::endl; }
		void operator()() override { (*oper)(); };
		/*!
	\brief getter
	\return label field for transition if the condition is met
	*/
		std::string getLink() const { return link; }
	};
}
