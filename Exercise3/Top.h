#ifndef TOP
#define TOP
#include "Producer.h"
#include "Consumer.h"

SC_MODULE(top) {
	sc_fifo<TCPHeader*> io_1;
	sc_fifo<TCPHeader*> io_2;
	producer producer;
	consumer consumer_1;
	consumer consumer_2;

	SC_CTOR(top);
};

#endif