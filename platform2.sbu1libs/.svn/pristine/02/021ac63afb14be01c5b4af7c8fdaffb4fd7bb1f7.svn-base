//============================================================================
// Name        : variable_buffer.cpp
// Author      :vijayakanth 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ubacipc/VariableBuffer.h>
#include <stdio.h>

using namespace std;

#define MAX_BUFFER_SIZE = 16*1024;

void custom_cpy(char *start, char *end, char *res)
{
	while(start < end){
		*res = *(start);
		start++;
		res++;
	}
}

void custom_print(char *start, size_t len)
{
	while(len > 0 ){
		printf("%c", *(start));
		start++;
		len--;
	}
	printf("\n");
}

class Client:
		public VariableBuffer
{
public:
	Client(size_t s):VariableBuffer::VariableBuffer(s, 10)
	{
	}

	~Client(){}

	size_t determine_packet_size(void *data)
	{
		int size = 10 + 5 * (random()%4);
		return size;
	}

	void handleBufferedData(void *data, size_t len)
	{
		printf("in HandleBuffered data len: %ld \n" , len);
		custom_print((char*) data , len);
	}
};

#include <stdio.h>

#include <time.h>


int main() {
	Client nClient(100);
	char alph[30] = "abcdefghijklmnopqrstuvwxyz";
	char recv[30] = {0};
	char *start = alph;
	char *end = start;
	char *END_OF_INPUT = alph + 26;

	while(1){
		while(start < END_OF_INPUT && end < END_OF_INPUT){
			int seed = random()%15;
			end += seed;
			if (end >= END_OF_INPUT){
				end = END_OF_INPUT;
			}

			custom_cpy(start,end,recv);

			printf("recv: %s, len: %ld\n", recv , strlen(recv));
			nClient.align_data(recv, strlen(recv));

			bzero(recv, sizeof(recv));
			start = end;
			sleep(1);
		}

		start = alph;
		end = start;
	}
	return 0;
}
