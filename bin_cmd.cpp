#pragma once
#include"bin_cmd.hpp"
#include <string>
#include "add.hpp"
#include "sub.hpp"
#include"MULT.hpp"
#include "div.hpp"
#include"mod.hpp"
#include"eq.hpp"
#include "sravnit.hpp"
#include"more.hpp"
#include <stdexcept>
namespace lab4 {
	using bc = bin_cmd;
	bc::bin_cmd(std::string s1, std::string s2, std::string op, std::string l): command(l){
		op1 = s1;
		op2 = s2;
		if (s1.length() > 8 || s2.length() > 8)
			throw std::length_error("too long identificator");
		if(l.length()>8)
			throw std::length_error("too long link");
		if (op == "ADD") {
			oper = new add(s1, s2);
			return;
		}
		if (op == "SUB") {
			oper = new sub(s1, s2);
			return;
		}
		if (op == "MULT") {
			oper = new mult(s1, s2);
			return;
		}

		if (op == "DIV") {
			oper = new div(s1, s2);
			return;
		}
		if (op == "MOD") {
			oper = new mod(s1, s2);
			return;
		}
		if (op == "EQ") {
			oper = new eq(s1, s2);
			return;
		}
		if (op == "=") {
			oper = new sravnit(s1, s2);
			return;
		}
		if (op == ">") {
			oper = new more(s1, s2);
			return;
		}
		throw std::domain_error("Invalid command");
	}
}