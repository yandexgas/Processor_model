#pragma once
#include "data_memory.hpp"
#include <stdexcept>

namespace lab4 {
	using dm = data_memory;
	dm& dm::add_var(std::string name, int value) {
		if (opers.count(name) == 0 && opers.size() < max_size) {
			opers[name] = value;
			return *this;
		}
		if (opers.count(name) > 0)
			throw std::logic_error("overriding a variable");
		if (opers.size() >= max_size)
			throw std::overflow_error("memory is full");
	}
	data_memory& dm::free_var(std::string name) {
		if (opers.count(name) > 0) {
			opers.erase(name);
			return*this;
		}
		else throw std::logic_error("the variable does not exist");
	}
	data_memory& dm::mod(int a) {
		if (a > 0) {
			opers.clear();
			max_size = a;
			return*this;
		}
		else throw std::underflow_error("incorrect size");////////
	}
	int& dm::operator[](std::string name) {
		if (opers.count(name) > 0) {
			return opers[name];
		}
		else throw std::logic_error("the variable is not inicialized");
	}
}