// Exercise1.cpp : Defines the entry point for the console application.
//

#include "ModuleSingle.h"

int sc_main(int argc, char* argv[])
{
	module_single instModuleSingle("instModuleSingle");

	sc_start(200, SC_MS);
	
    return 0;
}

