#ifndef MODULE_DOUBLE_H
#define MODULE_DOUBLE_H
#include <systemc.h>

SC_MODULE(module_double) {
	sc_event event_A, event_B, event_Aack, event_Back;
	bool latestEventProcessedWasA;

	enum Event {A, B
	} eventListenedOn = A;

	SC_CTOR(module_double) {
		SC_METHOD(method_A);
		//dont_initialize(); Method must be initialized in order to set initial trigger
		SC_THREAD(thread_A);
		SC_THREAD(thread_B);
	}

	void thread_A(void);
	void thread_B(void);
	void method_A(void);
};

#endif
