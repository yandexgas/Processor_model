#pragma once
#include<iostream>
#include"command.hpp"
#include "classes.h"
namespace lab4 {
	/*!
	\brief class of the transition command descriptor
	stores a label field for later navigation
	*/
	class Goto:public command {
	protected:
		std::string link;
		void operator()() override {};
	public:
		Goto(std::string l,std::string k ="") : link(l),command(k){}
		void show() override { std::cout << "-> " << link << ";" << command::link << std::endl; }
		/*!
	\brief getter
	\return name of the label to jump
	*/
		std::string getLink() const { return link; }
	};
}
