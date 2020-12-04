#pragma once
#include"registers_block.hpp"
namespace lab4 {
	using rb = registers_block;
	int rb::return_f_free() const {
		for (int i = 0;i < size;i++)
			if (!regs[i].get_block())return i;
		throw std::out_of_range("no free registers");
	}
	regist& rb::operator [](int i)
	{
		if (i < size && i >= 0)
			return (regs[i]);
		else throw std::out_of_range("incorrect index");
	}
	int rb::AddValue(int i) {
		if (return_f_free() < size) {
			regs[return_f_free()].set_value(i);
			return return_f_free();
		}
		else throw std::out_of_range("no free registers");
	}
	registers_block& rb::mod(int sz) {
		if (sz > 0) {
			delete[]regs;
			regs = new regist[sz];
			size = sz;
		}
		else throw std::underflow_error("Incorrect block size");///Œ¡–¿¡Œ“¿“‹
	}
}