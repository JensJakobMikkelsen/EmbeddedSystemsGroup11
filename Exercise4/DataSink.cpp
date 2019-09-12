#include "DataSink.h"

void dataSink::execute() {
	int counter = 0;
	int data_input;
	int error_input;

	while (1) {
		wait();
		if (++counter == 3) {
			counter = 0;
			ready = SC_LOGIC_0;
		}
		else {
			ready = SC_LOGIC_1;
		}

		if (valid == SC_LOGIC_1) {
			data_input = data.read();

			std::cout << data_input << endl;
		}
	}
}
