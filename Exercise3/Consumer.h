#ifndef CONSUMER
#define CONSUMER
#include <systemc.h>
#include "TCPHeader.h"

SC_MODULE(consumer) {
	sc_fifo_in<TCPHeader*> in;

	SC_CTOR(consumer) {
		SC_THREAD(consume);
	}

	void consume(void);
};

#endif
