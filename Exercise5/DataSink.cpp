#include "DataSink.h"

void dataSink::execute() {
	int counter = 0;
	int data_input;
	int file_error = fopen_s(&fp_data, OUTPUT_DATA_ARCH, "w");

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

			std::cout << "data output" << data_input << endl;
			fprintf(fp_data, "%d\n", data_input);
		}
	}
}

dataSink::~dataSink(void) {
	fclose(fp_data);
}

