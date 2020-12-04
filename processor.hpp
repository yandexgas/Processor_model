#pragma once
#include <iostream>
#ifndef cde
#include "control_device.hpp"
#endif
#ifndef pme
#include"programs_memory.hpp"
#endif
#ifndef ede
#include "execution_device.hpp"
#endif
#ifndef dme
#include"data_memory.hpp"
#endif
#ifndef rbe
#include"registers_block.hpp"
#endif
#include "if_op.hpp"
#include "classes.h"
#include "operation.hpp"
#include "add.hpp"
#include "vector.hpp"
namespace lab4 {
	using namespace std;
	/*!
	\brief class processor
	contains all the components of the processor - memory, registers, control and execution device, allows you to modify
	the amount of memory and registers, as well as start the execution of the program and load it into the program memory.
	*/
	class processor {
	private:
			control_device cd;
			programs_memory pm;
			execution_device exe_d;
			data_memory dm;
			registers_block rb;
	public:
		/*!
	\brief default constructor
	the main feature is that it will initialize static fields for data memory and a conditional operator immediately upon creating a processor.
	*/
		processor() :rb(), exe_d(&rb), pm(), dm(), cd(&pm, &exe_d) { operation::set_memory(&dm);if_op::set_proga_mem(&pm); }
		/*!
	\brief method for modifying a program in the processor
	\bug is unstable at the moment, so to change the program it is recommended to rewrite it and load it entirely into the processor using the driver*/
		processor& mod_prog() { pm.redact();return*this; }
		/*!
	\brief changes the amount of available RAM
	\param i parameter to call the data memory function, new amount of memory
	*/
		processor& mod_RAM(int i) { dm.mod(i);return *this; }
		/*!
	\brief changes the number of available registers
	\param i parameter for calling the function in the register block, the new value of the number of registers
	*/
		processor& mod_REGS(int i) { rb.mod(i); return *this; }
		/*!
	\brief processor startup
	before starting, clears the RAM and calls the go method of the control device
	*/
		processor& start() { dm.clear();cd.go();return *this; }
		/*!
	\brief loads a program as a vector of instructions into program memory
	*/
		processor& add_command(gya::vector<command*> a) { pm.add_cmd(a);return *this; }
		/*!
	\brief displays the currently executable program to the console
	called as a rule when execution errors occur, to indicate in which line of the program they occurred
	*/
		processor& now_cmd() { (*(pm.now())).show(); return*this; };
		/*!
	\brief displays complete information about the processor
	*/
		processor& show_info();
		/*!
	\brief displays the entire program in program memory
	*/
		processor& show_prog() { pm.show();return *this; }

	};
}