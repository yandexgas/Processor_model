#pragma once
#include<iostream>
#include"command.hpp"
#include "operation.hpp"
#include"data_memory.hpp"
#include "programs_memory.hpp"
#include "classes.h"
namespace lab4 {
	/*!
	\brief class handle of the branch operation
	the only operation that has direct access to program memory to jump to the desired label
	has a static field - a pointer to program memory
	and a static function to set program memory
 \warning if the requested register contains a nonzero number, the operator considers the condition to be true, ATTENTION, such operations as addition, multiplication, etc. also leave values ​​in the register, so it is most correct to call this operator only after comparison operations
 */
	class if_op :public operation {
	private:
		std::string link;
		static programs_memory* prog;
		void mainFunc();
	public:
		if_op(std::string s1) :operation("?",1), link(s1){};
		static void set_proga_mem(programs_memory* d) { prog = d; }
		if_op() :operation( ":=",1) {};
		if_op& operator()() override { mainFunc();return *this; }
	};
}