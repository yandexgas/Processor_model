#pragma once
#include "programs_memory.hpp"
namespace lab4 {
	using pm = programs_memory;
	programs_memory& pm::redact(int a) {
		command* ki = parcer();
		if (ki == nullptr)
			return*this;
		delete (memory[a]);////////////////////////////////////////////////////////////////
		memory[a] = ki;
		return *this;
	}
	programs_memory& pm::redact() {
		show();
		for (int i = 0;i < memory.size();i++)
			redact(i);
		std::string i;
		std::cin >> i;
		while (i!= ".")
		{
			command* km = parcer();
			if (km != nullptr)
				this->add_cmd(km);
		}
		return *this;
	}
	programs_memory& pm::show()  {
		auto it = memory.begin();
		for (it;it != memory.end();it++)
			(*(*it)).show();
		return*this;
	}
	int pm::next_cmd(int a) {
		if (a < memory.size())
			cmd = a;
		else return 0;
		return 1;
	}
	int pm::next_cmd() {
		cmd++;
		if (cmd >= memory.size())
			return 0;
		return 1;
	}
	int& pm::num_by_link(std::string s) const {
		gya::Itvector<command*> it = memory.begin();
		int k = 0;
		for (it;it != memory.end();it++) {
			if ((*(*it)).getstr() == s) return k;
			std::string kf = (*(*it)).getstr();
			k++;
		}
		throw std::logic_error( "Incorrect link");
	}
	command* pm::parcer() {
		command* ki = nullptr;
		gya::vector<std::string> comanda;
		std::string i = "";
		int k = 0;
		while (ki == nullptr)
		{
			while (i != ";" && i != ":" && i != ".") {
				std::cin >> i;
				comanda.push_back(i);
				k++;
				if (k > 5) throw std::exception("invalid command line");//////////////////////////////
			}
			if (i == ".")
				return nullptr;
			k = 0;
			if (i == ":") {
				std::cin >> i;
				comanda.push_back(i);
				if (comanda[0] == "?") {
					ki = lab4::command::if_crt(comanda, true);
					continue;
				}
				if (comanda[0] == ":="){
					ki = lab4::command::dec_crt(comanda, true);
					continue;
				}

				if (comanda[0] == "->"){
					ki = lab4::command::goto_crt(comanda, true);
					continue;
				}
				if (comanda.size() == 5){
					ki = lab4::command::bin_crt(comanda, true);
					continue;
				}
				if (comanda.size() == 4){
					ki = lab4::command::uno_crt(comanda, true);
					continue;
				}
			}
			else {
				if (comanda[0] == "?"){
					ki = lab4::command::if_crt(comanda, false);
					continue;
				}
				if (comanda[0] == ":="){
					ki = lab4::command::dec_crt(comanda, false);
					continue;
				}
				if (comanda[0] == "->"){
					ki = lab4::command::goto_crt(comanda, false);
					continue;
				}
				if (comanda.size() == 4){
					ki = lab4::command::bin_crt(comanda, false);
					continue;
				}
				if (comanda.size() == 3){
					ki = lab4::command::uno_crt(comanda, false);
					continue;
				}
			}
		}
		return ki;
	}
}