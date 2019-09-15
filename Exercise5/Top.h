#ifndef TOP
#define TOP
#include "DataSource.h"
#include "DataSink.h"
#include "InAdapter.h"

SC_MODULE(top) {
	sc_clock clock;
	sc_signal<sc_logic> clk;
	sc_signal<sc_logic> ready;
	sc_signal<sc_logic> valid;
	sc_signal<sc_logic> reset;
	//sc_fifo<sc_uint<DATA_BITS>> master2inadapter2;
	//sc_signal<sc_fifo<int>> master2inadapter;
	sc_signal<sc_int<DATA_BITS>> data;
	sc_signal<sc_int<DATA_BITS>> out;
	sc_signal<sc_int<ERROR_BITS>> error;
	sc_signal<sc_int<CHANNEL_BITS>> channel;
	dataSource dataSource;
	dataSink dataSink;
	InAdapter<sc_int<DATA_BITS>> inAdapter;
	sc_trace_file *tracefile;

	//SC_HAS_PROCESS(top);

	SC_CTOR(top);
	~top();

	void clock_signal(void);
};

#endif
