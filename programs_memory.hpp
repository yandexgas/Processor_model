
#pragma once
#include <iostream>
#ifndef com
#include "command.hpp"
#endif
#define pme
#include "vector.hpp"
#include <string>
#include "classes.h"
namespace lab4 {
	/*!
	\brief program memory class
	here, in the form of a vector, a sequence of commands for execution is stored
	*/
	class programs_memory {
	private:
		gya::vector<command*> memory;
		int cmd;
		programs_memory& redact(int);
		command* parcer();
	public:
		programs_memory() : memory(),cmd(0) {};
		/*!
	\brief add a new command to memory at the command pointer
	*/
		programs_memory& add_cmd(command* a) { memory.push_back(a); return *this; }
		/*!
	\brief adding new commands to memory by command vector
	*/
		programs_memory& add_cmd(gya::vector<command*> a) { memory= a; return *this; }
		/*!
	\brief method for modifying the current program
	\bug in this version is unstable, to change the program it is recommended to load the new program into the memory via the driver
	*/
		programs_memory& redact();
		/*!
	\brief displays the entire program on the screen
	*/
		programs_memory& show();
		/*!
	\return pointer to the currently executing command
	*/
		command* now() { return memory[cmd]; }
		/*!
	\brief sets for execution the next command by its number in the array
	*/
		int next_cmd(int);
		/*!
	\brief устанавливает на исполнение следующую команду по  порядку
	*/
		int next_cmd();
		/*!
	\brief get command number by label
	*/
		int& num_by_link(std::string) const;
	};
}
