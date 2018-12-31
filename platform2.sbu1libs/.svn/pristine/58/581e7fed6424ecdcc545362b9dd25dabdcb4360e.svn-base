#include "LZO.h"

LZO::LZO()
{
}

bool LZO::decompress(void *ptr_src, size_t len_src, unsigned char **ptr_dest, size_t * len_dest, size_t multiplier)
{
	lzo_uint output_size = (len_src * multiplier) + 1;
	*ptr_dest = (unsigned char *) malloc( output_size);
	if( *ptr_dest == NULL ) {
		return false;
	}
	unsigned char *input = (unsigned char *)ptr_src;
	lzo_uint input_size = len_src;
	int r = lzo1z_decompress(input, input_size, *ptr_dest, &output_size, NULL);
	if( r == LZO_E_OK ) {
		*len_dest = output_size;
		return true;
	} else {
		return false;
	}
}

bool LZO::decompress(void *ptr_src, size_t len_src, string & dest, size_t multiplier)
{
	lzo_uint output_size = (len_src * multiplier) + 1;
	unsigned char *output = (unsigned char *) malloc (output_size);
	unsigned char *input = (unsigned char *) ptr_src;
	lzo_uint input_size = len_src;
	int r = lzo1z_decompress(input, input_size, output, &output_size, NULL);
	if( r == LZO_E_OK ) {
		dest.append((char *)output, (size_t)output_size);
		free(output);
		output = NULL;
		return true;
	} else {
		return false;
	}
}

bool LZO::compress(void *ptr_src, size_t len_src, unsigned char **ptr_dest, size_t * len_dest)
{
	unsigned char *output;
	lzo_uint output_size = len_src + 1;
	output = (unsigned char *) malloc(output_size);
	unsigned char *input = (unsigned char *) ptr_src;
	unsigned char *workingMemory = (unsigned char *) malloc (LZO1Z_999_MEM_COMPRESS);
	lzo_uint input_size = len_src;
	lzo_uint compressed_size;
	int r = lzo1z_999_compress(input, input_size, output, &compressed_size, workingMemory);
	if( r == LZO_E_OK ) {
		*ptr_dest = (unsigned char *) malloc (compressed_size);
		memcpy((void *)(*ptr_dest), (const void *) output, compressed_size);
		*len_dest = compressed_size;

		free(output);
		free(workingMemory);
		return true;
	} else {

        if ( workingMemory != NULL) free(workingMemory);
        if ( output != NULL) free(output);

		return false;
	}
}

bool LZO::compress(string input, unsigned char **ptr_dest, size_t * len_dest)
{
	bool flag = false;
	size_t len_src = input.length();
	unsigned char *ptr_src;
	ptr_src = (unsigned char *) malloc (len_src + 1);
	strcpy((char *)ptr_src, input.c_str());
	flag = compress((void *)ptr_src, len_src, ptr_dest, len_dest);
	free(ptr_src);
	return flag;
}
