#pragma once
#include<iostream>
#define comnd
#include <string>
#ifndef ope
#include "operation.hpp"
#endif // !ope
#include"vector.hpp"
#include "classes.h"

namespace lab4 {
	/*!
	\brief abstract class descriptor - commands
	specific operators, as well as binary and unary commands are inherited from it
	*/
	class command {
	protected:
		std::string link;
		operation* oper;
	public:
		command() :link(), oper(nullptr) {};
		command(std::string l) : link(l), oper(nullptr) {};
		command(command& a) :link(a.link), oper(a.oper) 	{}
		command(command&& a) :link(a.link), oper(a.oper) {
			a.oper = nullptr;
		}
		virtual void operator()() = 0;
		/*!
		\brief an absolutely virtual function that is overloaded in all derived classes and displays commands on the console screen
		*/
		void virtual show() = 0;
		/*!
	\brief method for defining the operation of a given command
	\return reference to an instance of the operation performed by this command
	*/
		operation& get_oper_code() const { return *oper; }
		/*!
	\brief getter method for label field
	\return returns the label value of the given command
	*/
		std::string getstr() const { return link; }
		/*!
		\brief static function for verbose initialization of a conditional statement
		subject to link availability.  Like the following methods, the command name determines which operator to create
		*/
		static command* if_crt( gya::vector<std::string>& comanda, bool link);
		/*!
	\brief static function to create a jump statement
	*/

		static command* goto_crt( gya::vector<std::string>& comanda, bool link);
		/*! 
		\brief static function for configuring a binary command
		*/
		static command* bin_crt( gya::vector<std::string>& comanda, bool link);
		/*!
		\brief static function for configuring a unary command
		*/
		static command* uno_crt( gya::vector<std::string>& comanda, bool link);
		/*!
		\brief static function for configuring a data declaration statement
		*/
		static command* dec_crt(gya::vector<std::string>& comanda, bool link);
		/*!
		\brief static function for setting up a console read statement
		*/
		static command* read_crt(gya::vector<std::string>& comanda, bool link);
		~command() { delete oper; }
	};
}
