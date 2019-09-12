#include "Top.h"

const char *trace_file_name = "Exercise4Top";

top::top(sc_module_name) :
	clock("instDataSource"),
	clk("instClk"),
	ready("instReady"),
	valid("instValid"),
	data("instData"),
	error("instError"),
	channel("instChannel"),
	dataSource("instDataSource"),
	dataSink("instDataSink") {
	dataSource.CLK(clk);
	dataSource.ready(ready);
	dataSource.valid(valid);
	dataSource.data(data);
	dataSource.error(error);
	dataSource.channel(channel);
	dataSink.CLK(clk);
	dataSink.ready(ready);
	dataSink.valid(valid);
	dataSink.data(data);
	dataSink.error(error);
	dataSink.channel(channel);

	SC_METHOD(clock_signal);
	sensitive << clock;
	dont_initialize();

	tracefile = sc_create_vcd_trace_file(trace_file_name);
	if (!tracefile) cout << "Could not create trace file." << endl;

	sc_trace(tracefile, clk, "clk");
	sc_trace(tracefile, ready, "ready");
	sc_trace(tracefile, valid, "valid");
	sc_trace(tracefile, data, "data");
	sc_trace(tracefile, error, "error");
	sc_trace(tracefile, channel, "channel");
}

top::~top() {
	sc_close_vcd_trace_file(tracefile);
	cout << "Created " << trace_file_name << ".vcd" << endl;
}

void top::clock_signal(void) {
	sc_logic clock_tmp(clock.read());
	clk.write(clock_tmp);
}