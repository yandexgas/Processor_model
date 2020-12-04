#pragma once
#include <iostream>
#define ede
#ifndef comnd
#include"command.hpp"
#endif
#ifndef rbe
#include "registers_block.hpp"
#include "classes.h"
#endif // !rb
namespace lab4 {
	/*!
	\brief class - executive device
	directly executes the commands given to it, calling the corresponding functor-operations
	queries the registers (if they are needed for the operation) and locks them
	*/
	class execution_device {
	private:
		command* cmd;
		registers_block* rb;
		int* regs;
		void inverse_Block()const;
		void ask_regs();
		bool process;
	public:
		execution_device(registers_block* a) :rb(a), regs(nullptr), cmd(nullptr), process(false) {};
		/*!
	\brief method for starting command execution
	also calls the function of requesting and locking registers, and after executing the command - unlocking
	*/
		execution_device& go();
		/*!
	\brief setter - sets the next command for subsequent execution
	*/
		execution_device& set_cmd(command* a) { cmd = a;return *this; }
		~execution_device() { delete[]regs; delete cmd; }
	};
}