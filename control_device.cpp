#pragma once
#include <typeinfo>
#include "control_device.hpp"
#include "goto.hpp"
#include <conio.h>

namespace lab4 {
	using cd = control_device;
	int cd::pop_cmd() {
		if (strcmp(typeid(*(pm->now())).name(), "class lab4::Goto") == 0 || strcmp(typeid(pm->now()).name(), "class Goto") == 0)
			return(pm->next_cmd(pm->num_by_link(((Goto*)(pm->now()))->getLink())));
		
		else {
			ed->set_cmd(pm->now());
			ed->go();
			return(pm->next_cmd());
		}
		
	}
	cd& cd::go() {
		pm->next_cmd(0);
		while (pop_cmd() > 0) {
			if (_kbhit()) {
				if (_getch() == 27)
					break;
			}
		}
		pm->next_cmd(0);
		return *this;
	}
}