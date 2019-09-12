#include "DataSource.h"

dataSource::~dataSource() {
	fclose(fp_data);
}


void dataSource::execute(void) {
	int tmp_value;
	int channel_output = 0;
	int error_output = fopen_s(&fp_data, INPUT_DATA_ARCH, "r");
	int data_output;
	error.write(error_output);

	while (1) {
		do { wait(); } while (ready != SC_LOGIC_1);

		channel.write(channel_output);

		if (error_output != 0) {
			valid = SC_LOGIC_0;
		}
		else {
			data_output = fscanf_s(fp_data, "%d", &tmp_value);

			if (data_output == EOF) {
				valid = SC_LOGIC_0;
				sc_stop();
			}
			else {
				valid = SC_LOGIC_1;
				data.write(tmp_value);
			}
		}
	}
}