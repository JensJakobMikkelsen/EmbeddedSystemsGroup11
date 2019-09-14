#ifndef DATA_SINK
#define DATA_SINK
#include <systemc.h>
#include "Definitions.h"

SC_MODULE(dataSink) {
	sc_in<sc_logic> CLK;
	sc_out<sc_logic> ready;
	sc_in<sc_logic> valid;
	sc_in<sc_int<DATA_BITS>> data;
	sc_in<sc_int<ERROR_BITS>> error;
	sc_in<sc_uint<CHANNEL_BITS>> channel;
	FILE *fp_data;

	SC_CTOR(dataSink) {
		SC_THREAD(execute);
		sensitive << CLK.pos();
		dont_initialize();
	}
	~dataSink(void);

	void execute(void);
};

#endif
