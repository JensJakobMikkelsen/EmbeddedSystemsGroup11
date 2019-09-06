#include "ModuleDouble.h"

void module_double::thread_A(void) {
	while (1) {
		wait(3, SC_MS);
		cout << "Calling from A: " << sc_time_stamp() << endl;
		event_A.notify();
		wait(3, SC_MS, event_Aack);
		if (event_Aack.triggered()) {
			cout << "Calling from Aack: " << sc_time_stamp() << endl;
			return;
		}
	}
}

void module_double::thread_B(void) {
	while (1) {
		wait(2, SC_MS);
		cout << "Calling from B: " << sc_time_stamp() << endl;
		event_B.notify();
		wait(2, SC_MS, event_Back);
		if (event_Back.triggered()) {
			cout << "Calling from Back: " << sc_time_stamp() << endl;
			return;
		}
	}
}

void module_double::method_A(void) {
	next_trigger(event_A);

	if (event_A.triggered()) {
		cout << "Calling from method A" << endl;
		event_Aack.notify();
		next_trigger(event_B);
	}
	else if (event_B.triggered()) {
		cout << "Calling from method B" << endl;
		event_Back.notify();
		next_trigger(event_A);
	}
}
