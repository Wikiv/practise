/*
 * VariableBuffer.cpp
 *
 *  Created on: 11-Dec-2013
 *      Author: vijayakanth
 */

#include "VariableBuffer.h"

namespace UBACIPC
{

	VariableBuffer::VariableBuffer(size_t max_size, int hdr_size)
	{
		//printf("init buffer: %ld\n", max_size);
		this->buffer = malloc(max_size);
		bzero(buffer, max_size);

		this->buffer_max_size = max_size;
		this->unprocessed_bytes = 0;
		this->current_packet_size = 0;
		this->header_size = hdr_size;
		this->current_packet_size = 0;
		// buffer should be initialized with max data size from the connection.
	}

	VariableBuffer::~VariableBuffer()
	{
		free(buffer);
	}

	void VariableBuffer::align_data(void *data, size_t len)
	{

		//printf("buffer: %s, current_packet_size: %ld, unprocessed_bytes: %ld \n", (char*) this->buffer, this->current_packet_size, this->unprocessed_bytes);
		if (unprocessed_bytes == 0) {
			//TODO: consider header size here.
			bzero(this->buffer, this->buffer_max_size);
			this->_determinePacketSize();
		}

//	len+= unprocessed_bytes;

		if (current_packet_size == 0) {
			// concatenate the string in buffer.
			// the header size is critical for the operation.
			memcpy(((uint8_t*)buffer)+unprocessed_bytes, data, len);
			unprocessed_bytes += len;
			this->_determinePacketSize();

			//printf("determined packet_size: %u",this->current_packet_size  ) ;
			// the virtual determine_packet_size() should return a positive integer for practical operations.
			// or zero for avoiding crash.
			if (this->current_packet_size ==  0 )
				return;

		} else {
			memcpy(((uint8_t *)this->buffer )+ unprocessed_bytes, data , len);
			unprocessed_bytes += len  ;// len -current pos is the actual length
			//printf("known packet : buffer: %s, current_packet_size: %ld, unprocessed_bytes: %ld \n", (char*)this->buffer, this->current_packet_size, unprocessed_bytes);
		}

		while(this->current_packet_size
				&& unprocessed_bytes >= this->current_packet_size) {

			//printf("0: buffer: %s, current_packet_size: %ld, unprocessed_bytes: %ld \n", (char*)this->buffer, this->current_packet_size, unprocessed_bytes);

			this->handleBufferedData(this->buffer, this->current_packet_size);

			//printf("1: buffer: %s, current_packet_size: %ld, unprocessed_bytes: %ld \n", (char*)this->buffer, this->current_packet_size, unprocessed_bytes);

			memcpy(this->buffer, ((uint8_t*)this->buffer)+ this->current_packet_size ,
				   this->unprocessed_bytes - this->current_packet_size );
			//printf("2: buffer: %s, current_packet_size: %ld, unprocessed_bytes: %ld \n", (char*)this->buffer, this->current_packet_size, unprocessed_bytes);

			bzero(((uint8_t*)this->buffer)+unprocessed_bytes,
				  this->unprocessed_bytes-current_packet_size);
			//printf("3: buffer: %s, current_packet_size: %ld, unprocessed_bytes: %ld \n", (char*)this->buffer, this->current_packet_size, unprocessed_bytes);
			unprocessed_bytes -= this->current_packet_size;
			this->_determinePacketSize();
			//printf("4: buffer: %s, current_packet_size: %ld, unprocessed_bytes: %ld \n", (char*)this->buffer, this->current_packet_size, unprocessed_bytes);
			bzero(((uint8_t*)this->buffer)+unprocessed_bytes,
				  this->buffer_max_size-unprocessed_bytes );
			//printf("5: buffer: %s, current_packet_size: %ld, unprocessed_bytes: %ld \n", (char*)this->buffer, this->current_packet_size, unprocessed_bytes);
		}

	}

	size_t VariableBuffer::determine_packet_size(void *data)
	{
		// should implement this function rightfully for all udp packet types possible.
		return this->current_packet_size;
	}

	void VariableBuffer::_determinePacketSize()
	{
		if (this->unprocessed_bytes >= header_size) {
			this->current_packet_size = this->determine_packet_size(this->buffer);

		} else {
			this->current_packet_size = 0;
		}

		//printf("packetsize: %ld\n", this->current_packet_size);
	}

} /* namespace OPX */
