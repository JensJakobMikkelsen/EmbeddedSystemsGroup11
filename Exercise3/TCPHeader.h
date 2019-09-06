#pragma once
#define PACKET_SIZE	512
#define DATA_SIZE   (PACKET_SIZE - 20)

#include <systemc.h>

typedef struct {
	sc_uint<16> SourcePort;
	sc_uint<16> DestinationPort;
	sc_uint<32> SequenceNumber;
	sc_uint<32> AcknowledgementNumber;
	sc_uint<16> StatusBits;
	sc_uint<16> WindowSize;
	sc_uint<16> Checksum;
	sc_uint<16> UrgentPointer;
	char		Data[DATA_SIZE];
} TCPHeader;
