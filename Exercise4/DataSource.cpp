#include "DataSource.h"

void dataSource::execute(void) {
	FILE *fp_data;
	int tmp_value;
	int channel_output = 0;
	int error_output;
	int data_output;

	while (1) {
		do { wait(); } while (!ready);

		channel.write(channel_output);
		error_output = fopen_s(&fp_data, INPUT_DATA_ARCH, "r");
		error.write(error_output);

		if (error_output != 0) {
			valid = false;
			fclose(fp_data);
		}
		else {
			data_output = fscanf_s(fp_data, "%d", &tmp_value);
			fclose(fp_data);

			if (data_output == EOF) {
				valid = false;
				sc_stop();
			}
			else {
				valid = true;
				data.write(tmp_value);
			}
		}
	}
}