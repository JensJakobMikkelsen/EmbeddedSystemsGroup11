#include "Top.h"

const char *trace_file_name = "Exercise4Top";

top::top(sc_module_name) :
	clock("instDataSource", 20, SC_NS),
	clk("instClk"),
	ready("instReady",sc_logic_0),
	valid("instValid",sc_logic_0),
	reset("reset",SC_LOGIC_0),
	//master2inadapter2("master2inadapter"),
	data("instData"),
	error("instError"),
	channel("instChannel"),
	dataSource("insDataSource"),
	dataSink("instDataSink"),
	inAdapter("inAdapter"){
	/*dataSource.CLK(clk);
	dataSource.ready(ready);
	dataSource.valid(valid);
	dataSource.data(data);
	dataSource.error(error);
	dataSource.channel(channel);*/
	//dataSource(out);
	//dataSource.CLK(clk);
	dataSource.out(inAdapter);
	//inAdapter.out_from_master(master2inadapter2);
	inAdapter.clock(clock);
	inAdapter.ready(ready);
	inAdapter.reset(reset);
	inAdapter.channel(channel);
	inAdapter.error(error);
	inAdapter.valid(valid);
	inAdapter.data(data);
	dataSink.CLK(clock);
	dataSink.ready(ready);
	dataSink.reset(reset);
	dataSink.valid(valid);
	dataSink.data(data);
	dataSink.error(error);
	dataSink.channel(channel);

	//cout << "top1" << endl;
	SC_METHOD(clock_signal);
	sensitive << clock;
	dont_initialize();
	//cout << "top2" << endl;
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
	//cout << "top_clk" << endl;
}