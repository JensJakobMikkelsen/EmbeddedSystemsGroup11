#ifndef PRODUCER
#define PRODUCER
#include <systemc.h>
#include "TCPHeader.h"

SC_MODULE(producer) {
	sc_fifo_out<TCPHeader*> out;

	SC_CTOR(producer) {
		SC_THREAD(produce);
	}

	void produce(void);
};

#endif
