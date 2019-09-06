#include "Top.h"

top::top(sc_module_name) :
	sc_module(),
	io_1("io_1"),
	io_2("io_2"),
	producer("producer"),
	consumer_1("consumer_1"),
    consumer_2("consumer_2") {
	producer.out(io_1);
	producer.out(io_2);
	consumer_1.in(io_1);
	consumer_2.in(io_2);
}