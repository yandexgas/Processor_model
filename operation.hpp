#pragma once
#include<iostream>
#define ope
#include "regist.hpp"
#include "data_memory.hpp"
namespace lab4 {
	/*!
	\brief abstract base class for all operation handles
	has constant fields for the operation name and the number of registers for the operation, which are initialized in the constructors of derived classes
	stores a pointer to the requested registers
	has a static member - a pointer to data memory, since it is common for all bases
	*/
	class operation {
	protected:
		const std::string name;
		const int regs_numb;
		regist* regi;
		static data_memory* var;
	public:
		/*!
	\brief constructor filling the default number of registers with zero and the name of the operation
	\params l operation name
	\params a number of optional registers
	*/

		operation( std::string l,int a =0) : regs_numb(a),name(l) {};
		/*!
	\briefgetter
	\return the number of required registers for the operation
	*/
		int get_regs_numb() const { return regs_numb; }
		/*!
	all derived classes are functors
	*/
		virtual operation& operator()() = 0;
		/*!
	\brief register setter
	\param r pointer to array of registers allocated for this operation
	*/
		operation& set_regi(regist* r) { regi = r;return *this; }
		/*!
	\brief name getter
	\return operation name
	*/
		std::string get_name() const { return name; }
		/*!
	\brief memory getter
	a static function that sets a pointer to data memory
	*/
		static void set_memory(data_memory* m) { var = m; }
	};
}
