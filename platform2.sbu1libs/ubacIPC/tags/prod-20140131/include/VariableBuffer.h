/*
 * VariableBuffer.h
 *
 *  Created on: 11-Dec-2013
 *      Author: vijayakanth
 */

#ifndef VARIABLEBUFFER_H_
#define VARIABLEBUFFER_H_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

namespace UBACIPC {

class VariableBuffer {
	public:
		VariableBuffer(size_t max_size, int hdr_size);
		virtual ~VariableBuffer();

		void align_data(void *data, size_t len);

		void *buffer;

		size_t current_packet_size;// current packet max_size;
		size_t unprocessed_bytes;// this indicates position from where we can start appending the buffer also
		size_t buffer_max_size;

		virtual void handleBufferedData(void *data, size_t packet_len){};
		virtual size_t determine_packet_size(void *data);

		size_t header_size;

	private:

		void _determinePacketSize();
};

} /* namespace OPX */
using namespace UBACIPC;
#endif /* VARIABLEBUFFER_H_ */
