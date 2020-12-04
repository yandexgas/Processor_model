#pragma once
#include<iostream>
#ifndef comnd
#include"command.hpp"
#endif
#include "classes.h"
#include "PRINT.hpp"
#include "inv.h"
#include "del_op.hpp"
#include <stdexcept>
namespace lab4 {

	/*!
	\brief class a descriptor of a unary command
	which stores the values ​​of the operand and, by the name of the operation, creates an instance of the operation and places it in the base class as specified
*/
	class uno_cmd :public command {
	protected:
		std::string op;
	public:
		uno_cmd(std::string o , std::string n,std::string l ="") :command(l){
			op = o;
			if(o.length()>8)
				throw std::length_error("too long identificator");
			if(l.length()>8)
				throw std::length_error("too long lenth");
			if (n == "PRINT") {
				oper = new print(o);
				return;
			}
			if (n == "INV") {
				oper = new inv(o);
				return;
			}			
			if (n == "DEL") {
				oper = new del_op(o);
				return;
			}
			throw std::domain_error("Invalid command");
		}
		void show() override { std::cout << oper->get_name() << " " << op << ":" << command::getstr() << std::endl; }
		void operator()() override { (*oper)(); }
	};
}