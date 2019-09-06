#include "DataSource.h"

void dataSource::execute(void) {
	FILE *fp_data;
	int tmp_value;

	int error = fopen_s(&fp_data, INPUT_DATA_ARCH, "r");

	while (1) {
		do { wait(); } while (!ready);

		if (fscanf_s(fp_data, "%d", &tmp_value) == EOF) {

		}
	}
}