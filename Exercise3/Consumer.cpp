#include "Consumer.h"

void consumer::consume(void) {
	TCPHeader* tcpHeader;
	while (1) {
		tcpHeader = in.read();
		std::cout
			<< "From: "
			<< name()
			<< " - Sequence number: "
			<< tcpHeader->SequenceNumber
			<< ", Current Simulation Time: "
			<< sc_time_stamp()
			<< endl << endl;
	}
}