#include "command.hpp"
#include<iostream>
#include"if.hpp"
#include"bin_cmd.hpp"
#include"uno_cmd.hpp"
#include"goto.hpp"
#include"declarator.hpp"
#include "read.hpp"

namespace lab4 {
	command* command::read_crt(gya::vector<std::string>& comanda, bool link) {
		if (link) {
			lab4::read* cm = new lab4::read(comanda[1], comanda[3]);
			comanda.clear();
			return cm;
		}
		lab4::read* cm = new lab4::read(comanda[1]);
		comanda.clear();
		return cm;
	 }
	command* command::if_crt(gya::vector<std::string>& comanda, bool link) {
		if (link) {
			lab4::If* cm = new lab4::If(comanda[1], comanda[3]);
			comanda.clear();
			return cm;
		}
		lab4::If* cm = new lab4::If(comanda[1]);
		comanda.clear();
		return cm;
	}
	command* command::goto_crt(gya::vector<std::string>& comanda, bool link) {
		if (link) {
			lab4::Goto* cm = new lab4::Goto(comanda[1], comanda[3]);
			comanda.clear();
			return cm;
		}
		lab4::Goto* cm = new lab4::Goto(comanda[1]);
		comanda.clear();
		return cm;
	}
	command* command::bin_crt( gya::vector<std::string>& comanda, bool link) {
		try {
			if (link) {
				lab4::bin_cmd* cm = new lab4::bin_cmd(comanda[1], comanda[2], comanda[0], comanda[4]);
				comanda.clear();
				return cm;
			}
			lab4::bin_cmd* cm = new lab4::bin_cmd(comanda[1], comanda[2], comanda[0]);
			comanda.clear();
			return cm;
		}
		catch (std::domain_error e) {
			std::cout << "!!!!!!!!! " << e.what() << std::endl;
			comanda.clear();
			return nullptr;
		}
		catch (std::length_error e) {
			std::cout << "!!!!!!!!! " << e.what() << std::endl;
			comanda.clear();
			return nullptr;
		}
	}

	command* command::uno_crt( gya::vector<std::string>& comanda, bool link) {
		try {
			if (link) {
				lab4::uno_cmd* cm = new lab4::uno_cmd(comanda[1], comanda[0], comanda[3]);
				comanda.clear();
				return cm;
			}
			lab4::uno_cmd* cm = new lab4::uno_cmd(comanda[1], comanda[0]);
			comanda.clear();
			return cm;
		}
		catch (std::domain_error e) {
			std::cout << "!!!!!!!!! " << e.what() << std::endl;
			comanda.clear();
			return nullptr;
		}
		catch (std::length_error e) {
			std::cout << "!!!!!!!!! " << e.what() << std::endl;
			comanda.clear();
			return nullptr;
		}
	}
	command* command::dec_crt(gya::vector<std::string>& comanda, bool link) {
		try {
			if (link) {
				lab4::declarator* cm = new lab4::declarator(comanda[1], std::stoi(comanda[2]), comanda[4]);
				comanda.clear();
				return cm;
			}
			lab4::declarator* cm = new lab4::declarator(comanda[1], std::stoi(comanda[2]));
			comanda.clear();
			return cm;
		}
		catch (std::invalid_argument e) {
			std::cout << e.what() << std::endl;
			comanda.clear();
			return nullptr;
		}
	}
}