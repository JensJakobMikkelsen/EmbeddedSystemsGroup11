#ifndef TOP
#define TOP
#include "DataSource.h"
#include "DataSink.h"

SC_MODULE(top) {
	dataSource dataSource;
	dataSink dataSink;

	SC_CTOR(top);
};

#endif
