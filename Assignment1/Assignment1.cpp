// Assignment1.cpp : Defines the entry point for the console application.
//

#include "ModuleSingle.h"
#include "ModuleDouble.h"
#include "simple_process_ex.h"

int sc_main(int argc, char* argv[])
{
	//module_single instModuleSingle("instModuleSingle");
	module_double instModuleDouble("instModuleDouble");
	simple_process_ex instSimpleProcess("instSimpleProcessojojojojo");

	sc_start(200, SC_MS);
	
    return 0;
}

