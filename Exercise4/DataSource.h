#ifndef DATA_SOURCE
#define DATA_SOURCE
#include <systemc.h>
#include "Definitions.h"

SC_MODULE(dataSource) {
	sc_in_clk CLK;
	sc_in<bool> ready;
	sc_out<bool> valid;
	sc_out<sc_uint<DATA_BITS>> data;
	sc_out<sc_uint<ERROR_BITS>> error;
	sc_out<sc_uint<CHANNEL_BITS>> channel;

	SC_CTOR(dataSource) {
		SC_THREAD(execute);
		sensitive << CLK.pos();
		dont_initialize();
	}

	void execute(void);
};

#endif
