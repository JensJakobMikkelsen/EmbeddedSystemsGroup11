#ifndef MODULE_SINGLE_H
#define MODULE_SINGLE_H
#include <systemc.h>

SC_MODULE(module_single) {
	sc_event event1;
	sc_uint<4> counter;

	SC_CTOR(module_single) {
		SC_METHOD(my_method);
		sensitive << event1;
		dont_initialize();
		SC_THREAD(my_thread_process);
	}

	void my_thread_process(void);
	void my_method(void);
};

#endif
