#pragma once
#include<iostream>
#ifndef reg
#include"regist.hpp"
#endif // !reg
#define rbe
#include "classes.h"
namespace lab4 {
	/*!
	\brief class of a block of registers
	contains an array of registers and is characterized by their number as well as the number of the first unlocked register
	*/
	class registers_block {
	private:
		regist* regs;
		int f_free;
		int size;	
	public:
		registers_block() :f_free(0), size(2) { regs = new regist[2]; }
		registers_block(int a) : f_free(0), size(a) { regs = new regist[size]; }
		int return_f_free() const;
		int AddValue(int i);
		 regist& operator [](int i);
		registers_block& mod(int);
		int get_size() { return size; }
		~registers_block() { delete[] regs; }
	};
}
