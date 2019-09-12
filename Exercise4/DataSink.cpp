#include "DataSink.h"

void dataSink::execute() {
	FILE *fp_data;
	int counter = 0;
	int data_input;
	int error_input;
	int file_error;

	while (1) {
		wait();
		if (++counter == 3) {
			counter = 0;
			ready = false;
		}
		else {
			ready = true;
		}

		if (valid == true) {
			data_input = data.read();

			file_error = fopen_s(&fp_data, OUTPUT_DATA_ARCH, "w");
			fprintf(fp_data, "%d", data_input);
		}
	}
}
