#pragma once
#include<iostream>
#define reg
#ifndef oper
#include"operation.hpp"
#endif
#include <exception>
#include "classes.h"
namespace lab4 {
	/*!
	\brief general register class
	it stores temporary data during and after some operations (arithmetic, comparisons and reading from the console)
	the values ​​are also read from it by the catch operator
	*/
	class regist {
	private:
		int value;
		bool block;
	public:
		regist() :value(0), block(false) {}
		int get_value() const { return value; }
		bool get_block() const { return block; }
		regist& set_value(int a) { if (!block) value = a;return *this;}
		regist& inv_block() { block = !block;return *this; }
		regist& operator +=(int a) { value += a; return*this; }
		regist& operator -=(int a) { value -= a;return*this; }
		regist& operator *=(int a) { value *= a;return*this; }
		regist& operator /=(int a) { value /= a; return*this;}
		regist& operator %=(int a) { value %= a; return*this;}
		regist& operator=(int a) { value = a; return*this;}
	};
}
