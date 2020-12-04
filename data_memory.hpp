#pragma once
#include<iostream>
#define dme
#include <vector>
#include <map>
#include <string>
#include "classes.h"
namespace lab4 {
	/*!
	\brief memory class for storing data
	data is stored as an associative array name - value, access will be obtained by the name of the operand
	*/
	class data_memory {
	private:
		std::map< std::string,int> opers;
		int max_size;
	public:
/*!
	\brief constructor initializing the maximum memory value.
	\param a memory size in units of integers (1 = 4 bytes)
	default memory = 15
	*/
		data_memory(int a=15) :max_size(a), opers() {}
		/*!
	\brief allocates memory for a new variable
	\throw std :: logic_error when trying to override a variable
	\throw std :: overflow_error if memory is full
	accepts the name and value of a variable as input, checks whether the name of the variable is occupied and whether the memory is full
	*/
		data_memory& add_var(std::string,int);
		/*!
	\brief frees memory allocated for a variable named
	\return reference to the current instance
	\throw std :: logic_error if no such variable exists (or has already been removed)
	*/
		data_memory& free_var(std::string);
		/*!
	\brief changes the amount of memory
	\return reference to the current instance
	\throw std :: underflow_error if an attempt is made to make the memory less or = 0
	*/
		data_memory& mod(int);
		/*!
	\brief access to the value of a variable by its name
	\return reference to variable value
	\throw std :: logic_error if a variable with the same name is not defined
	*/
		int& operator[](std::string);
		/*!
	\brief clear data memory completely
	\return reference to the current instance
	*/
		data_memory& clear() { opers.clear(); return *this; }
		/*!
	\brief getter
	\return memory size
	*/
		int mx_sz()const { return max_size; }

	};
}
