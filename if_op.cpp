#pragma once
#include"if_op.hpp"
namespace lab4 {
	programs_memory* if_op::prog = nullptr;
	void if_op::mainFunc() {
		if (operation::regi->get_value() != 0)
			prog->next_cmd(prog->num_by_link(link)-1);
	}
}