#include "Producer.h"
#include <time.h>

void producer::produce(void) {
	TCPHeader tcpHeader;
	srand(time(NULL));
	while (1) {
		wait(rand() % 9 + 2, SC_MS);
		++tcpHeader.SequenceNumber;
		for (int i = 0; i < out.size(); ++i) {
			out[i]->write(&tcpHeader);
		}
	}
}