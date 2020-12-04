#pragma once
#include <iostream>
#ifndef com
#include"command.hpp"
#endif
#ifndef ede
#include "execution_device.hpp"
#endif
#ifndef pme
#include "programs_memory.hpp"
#endif
#define cde
#include "classes.h"
namespace lab4 {
	/*!
	\brief master class
	extracts the next command from program memory and places it in the executing device
	*/
	class control_device{
	private:
		programs_memory* pm;
		execution_device* ed;
	public:/*!
	\brief initializes the instance with pointers to program memory and the control device
	*/
		control_device(programs_memory* p, execution_device* e) :pm(p), ed(e) {};
		/*!
	\brief retrieves the next command from program memory
	\return sequence number in program memory for the next command
	executes the jump command on the label independently, changing the value of the next command in the program memory, places the remaining commands in the control device
	after release, changes the value of the next command in the program memory
	*/
		int pop_cmd();
		/*!
	\brief starts the processor and program execution
	\return reference to the current instance
	at the beginning and end of the processor, the value "next command" equates to zero, in order to avoid the fact that at the end of the program execution
	its next launch will start from the middle, which may lead to an incorrect result
	*/
		control_device& go();
	};
}
