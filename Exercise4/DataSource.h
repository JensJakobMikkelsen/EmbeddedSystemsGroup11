#ifndef DATA_SOURCE
#define DATA_SOURCE
#include <systemc.h>
#include "Definitions.h"

SC_MODULE(dataSource) {
	sc_in<sc_logic> CLK;
	sc_in<sc_logic> ready;
	sc_out<sc_logic> valid;
	sc_out<sc_int<DATA_BITS>> data;
	sc_out<sc_int<ERROR_BITS>> error;
	sc_out<sc_uint<CHANNEL_BITS>> channel;
	FILE *fp_data;

	SC_CTOR(dataSource) {
		SC_THREAD(execute);
		sensitive << CLK.pos();
		dont_initialize();
	}
	~dataSource(void);

	void execute(void);
};

#endif
