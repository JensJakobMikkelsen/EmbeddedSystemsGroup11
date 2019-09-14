#ifndef TOP
#define TOP
#include "DataSource.h"
#include "DataSink.h"

SC_MODULE(top) {
	sc_clock clock;
	sc_signal<sc_logic> clk;
	sc_signal<sc_logic> ready;
	sc_signal<sc_logic> valid;
	sc_signal<sc_int<DATA_BITS>> data;
	sc_signal<sc_int<ERROR_BITS>> error;
	sc_signal<sc_uint<CHANNEL_BITS>> channel;
	dataSource dataSource;
	dataSink dataSink;
	sc_trace_file *tracefile;

	SC_CTOR(top);
	~top();

	void clock_signal(void);
};

#endif
