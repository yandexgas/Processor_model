#pragma once
#include"uno_cmd.hpp"
#include"inv.h"
#include "PRINT.hpp"
namespace lab4 {
	uno_cmd::uno_cmd(std::string o, std::string n, std::string l) :command(l) {
		op = o;
		if (n == "INV") {
			oper = new inv(o);
			return;
		}
		if (n == "PRINT") {
			oper = new print(o);
			return;
		}
		throw exception("Invalid command");
	}
}