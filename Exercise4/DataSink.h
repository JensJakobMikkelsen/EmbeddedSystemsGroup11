#ifndef DATA_SINK
#define DATA_SINK
#include <systemc.h>
#include "Definitions.h"

SC_MODULE(dataSink) {
	sc_in_clk CLK;
	sc_out<bool> ready;
	sc_in<bool> valid;
	sc_in<sc_uint<DATA_BITS>> data;
	sc_in<sc_uint<ERROR_BITS>> error;
	sc_in<sc_uint<CHANNEL_BITS>> channel;

	SC_CTOR(dataSink) {
		SC_THREAD(execute);
		sensitive_pos << CLK;
		dont_initialize();
	}

	void execute(void);
};

#endif
