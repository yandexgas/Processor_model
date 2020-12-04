#include"processor.hpp"
namespace lab4 {
	processor& processor::show_info() {
		std::cout << "---------- GYA processor series 2.4.0 info ----------" << std::endl;
		std::cout << ">>> Memory size : " << this->dm.mx_sz() * 4 << " bytes." << std::endl;
		std::cout << ">>> General registers count : " <<rb.get_size() << "." << std::endl;
		std::cout << ">>> Execution devices count : 1" << "." << std::endl;
		std::cout << ">>> Program memory size : inf" << " bytes." << std::endl;
		std::cout<< "-----------------------------------------------------" << std::endl;
		return *this;
	}
}