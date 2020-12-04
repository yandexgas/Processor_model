#pragma once
#include"execution_device.hpp"
namespace lab4 {
	using ed = execution_device;
	void ed::ask_regs() {
		int i = cmd->get_oper_code().get_regs_numb();
		if (i > 0) regs = new int[i];
		else return;
		for(i;i>0;i--){
			regs[i - 1] = rb->return_f_free();
			((*rb)[regs[i - 1]]).inv_block();
		}
		cmd->get_oper_code().set_regi(&(*rb)[regs[0]]);

	}
	void ed::inverse_Block()const {
		for (int i = 0; i < cmd->get_oper_code().get_regs_numb();i++)
			(*rb)[regs[i]].inv_block();
	}
	execution_device& ed::go() {
		process = true;
		ask_regs();
		(*cmd)();///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		inverse_Block();
		delete[] regs;
		regs = nullptr;
		process = false;
		return *this;
	}
}