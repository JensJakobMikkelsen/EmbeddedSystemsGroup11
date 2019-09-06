#include "ModuleSingle.h"

void module_single::my_thread_process(void) {
	while (1) {
		wait(2, SC_MS);
		event1.notify();
	}
}

void module_single::my_method(void) {
	std::cout
		<< "From "
		<< name()
		<< " - Counter: "
		<< ++counter
		<< ", Current Simulation Time: "
		<< sc_time_stamp()
		<< endl;
}