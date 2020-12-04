#pragma once
#include "processor.hpp"
#include<iostream>
#include"command.hpp"
#include"operation.hpp"
#include"add.hpp"
#include"bin_cmd.hpp"
#include"control_device.hpp"
#include"data_memory.hpp"
#include"dec_op.hpp"
#include"declarator.hpp"
#include"div.hpp"
#include"eq.hpp"
#include"execution_device.hpp"
#include"goto.hpp"
#include"if.hpp"
#include"if_op.hpp"
#include"inv.h"
#include"mod.hpp"
#include"more.hpp"
#include"MULT.hpp"
#include"PRINT.hpp"
#include"programs_memory.hpp"
#include"regist.hpp"
#include"registers_block.hpp"
#include"sravnit.hpp"
#include"sub.hpp"
#include"uno_cmd.hpp"
#include <stdexcept>
#include <limits>
#include "read.hpp"
#include "read_op.hpp"
#include"vector.hpp"
void parser(lab4::processor&);
void if_crt(gya::vector<lab4::command*>& program, gya::vector<std::string>& comanda, bool link);
void goto_crt(gya::vector<lab4::command*>& program, gya::vector<std::string>& comanda, bool link);
void dec_crt(gya::vector<lab4::command*>& program, gya::vector<std::string>& comanda, bool link);
void bin_crt(gya::vector<lab4::command*>& program, gya::vector<std::string>& comanda, bool link);
void uno_crt(gya::vector<lab4::command*>& program, gya::vector<std::string>& comanda, bool link);
void go(lab4::processor& GYA);
int main() {
	lab4::processor GYA;
	parser(GYA);
	return 1;
}
void go(lab4::processor& GYA) {
	try {
		GYA.start();
	}
	catch (std::logic_error e) {
		std::cout << "!!!!!! " << e.what() << std::endl;
		GYA.now_cmd();
		std::cout<<std::endl << "-------------" << std::endl;
	}
	catch (std::overflow_error e) {
		std::cout << "!!!!!!" << e.what() << std::endl << "-------------" << std::endl;
	}
	catch (std::out_of_range e) {
		std::cout << "!!!!!!" << e.what() << std::endl << "-------------" << std::endl;
	}
}
void if_crt(gya::vector<lab4::command*>& program, gya::vector<std::string>& comanda, bool link) {
	if (link) {
		lab4::If *cm = new lab4::If(comanda[1], comanda[3]);
		program.push_back(cm);
		comanda.clear();
		return;
	}
	lab4::If *cm = new lab4::If(comanda[1]);
	program.push_back(cm);
	comanda.clear();
}
void read_crt(gya::vector<lab4::command*>& program, gya::vector<std::string>& comanda, bool link) {
	if (link) {
		lab4::read* cm = new lab4::read(comanda[1], comanda[3]);
		program.push_back(cm);
		comanda.clear();
		return;
	}
	lab4::read* cm = new lab4::read(comanda[1]);
	program.push_back(cm);
	comanda.clear();
}
void goto_crt(gya::vector<lab4::command*>& program, gya::vector<std::string>& comanda, bool link) {
	if (link) {
		lab4::Goto* cm= new lab4::Goto(comanda[1], comanda[3]);
		program.push_back(cm);
		comanda.clear();
		return;
	}
	lab4::Goto *cm= new lab4::Goto(comanda[1]);
	program.push_back(cm);
	comanda.clear();
}
void bin_crt(gya::vector<lab4::command*>& program, gya::vector<std::string>& comanda, bool link) {
	try {
		if (link) {
			lab4::bin_cmd* cm = new lab4::bin_cmd(comanda[1], comanda[2], comanda[0], comanda[4]);
			program.push_back(cm);
			comanda.clear();
			return;
		}
		lab4::bin_cmd* cm = new lab4::bin_cmd(comanda[1], comanda[2], comanda[0]);
		program.push_back(cm);
		comanda.clear();
	}
	catch (std::domain_error e) {
		std::cout <<"!!!!!!!!! "<< e.what()<< std::endl;
		comanda.clear();
	}
	catch (std::length_error e) {
		std::cout << "!!!!!!!!! " << e.what() << std::endl;
		comanda.clear();
	}
}

void uno_crt(gya::vector<lab4::command*>& program, gya::vector<std::string>& comanda, bool link) {
	try {
		if (link) {
			lab4::uno_cmd* cm = new lab4::uno_cmd(comanda[1], comanda[0], comanda[3]);
			program.push_back(cm);
			comanda.clear();
			return;
		}
		lab4::uno_cmd* cm = new lab4::uno_cmd(comanda[1], comanda[0]);
		program.push_back(cm);
		comanda.clear();
	}
	catch (std::domain_error e) {
		std::cout << "!!!!!!!!! " << e.what() << std::endl;
		comanda.clear();
	}
	catch (std::length_error e) {
		std::cout << "!!!!!!!!! " << e.what() << std::endl;
		comanda.clear();
	}
}
void dec_crt(gya::vector<lab4::command*>& program, gya::vector<std::string>& comanda, bool link) {
	try {
		if (link) {
			lab4::declarator *cm= new lab4::declarator(comanda[1], std::stoi(comanda[2]), comanda[4]);
			program.push_back(cm);
			comanda.clear();
			return;
		}
		lab4::declarator *cm= new lab4::declarator(comanda[1], std::stoi(comanda[2]));
		program.push_back(cm);
		comanda.clear();
	}
	catch (std::invalid_argument e) {
		std::cout << e.what() << std::endl;
		comanda.clear();
	}
}

void parser(lab4::processor& GYA) {
	gya::vector<std::string> comanda;
	gya::vector<lab4::command*> program;
	int k = 0;
	std::string i;
	bool prg = false;
	do {
		std::cin >> i;
		if (i == "begin") {
			while (i != "end") {
				i = "";
				try {
					while (i != ";" && i != ":" && i != "end") {
						std::cin >> i;
						comanda.push_back(i);
						k++;
						if (k > 5) throw std::exception("invalid command line");//////////////////////////////
					}
				}
				catch (std::exception e) {
					std::cout << e.what() << std::endl;
					i = "";
				}
				k = 0;
				if (i == ":") {
					std::cin >> i;
					comanda.push_back(i);
					if (comanda[0] == "READ")
					{
						read_crt(program, comanda, true);
						continue;
					}
					if (comanda[0] == "?") {
						if_crt(program, comanda, true);
						continue;
					}

					if (comanda[0] == ":=") {
						dec_crt(program, comanda, true);
						continue;
					}
					if (comanda[0] == "->") {
						goto_crt(program, comanda, true);
						continue;
					}
					if (comanda.size() == 5) {
						bin_crt(program, comanda, true);
						continue;
					}
					if (comanda.size() == 4) {
						uno_crt(program, comanda, true);
						continue;
					}
				}
				else {
					if (comanda[0] == "READ") {
						read_crt(program, comanda, false);
						continue;
					}
					if (comanda[0] == "?") {
						if_crt(program, comanda, false);
						continue;
					}
					if (comanda[0] == ":=") {
						dec_crt(program, comanda, false);
						continue;
					}
					if (comanda[0] == "->") {
						goto_crt(program, comanda, false);
						continue;
					}
					if (comanda.size() == 4) {
						bin_crt(program, comanda, false);
						continue;
					}
					if (comanda.size() == 3) {
						uno_crt(program, comanda, false);
						continue;
					}
				}
			}
			if (program.size() > 0)
				prg = true;
			else prg = false;
			GYA.add_command(program);
			program.clear();
			comanda.clear();
		}
		if (i == "start") {
			if (prg)
				go(GYA);
				else std::cout << "Invalid program";
		}
		if (i == "info")
			GYA.show_info();
		if (i == "program")
			GYA.show_prog();
		if (i == "modif") {
			std::cin >> i;
			if (i == "program")
				GYA.mod_prog();
			try {
				if (i == "reg") {
					int k;
					std::cin >> k;
					GYA.mod_REGS(k);
				}
				if (i == "RAM") {
					int k;
					std::cin >> k;
					GYA.mod_RAM(k);
				}
			}
			catch (std::underflow_error e) {
				std::cout << e.what()<<std::endl;
			}
		}
	} while (i != "close");

}


