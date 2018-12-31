#include "MiniLZO.h"

MiniLZO::MiniLZO()
{
}

bool MiniLZO::decompress(void *ptr_src, size_t len_src, unsigned char **ptr_dest, size_t * len_dest)
{
	lzo_uint output_size = (len_src * 10 *1024) + 1;
	*ptr_dest = (unsigned char *) malloc (output_size);
	unsigned char *input = (unsigned char *)ptr_src;
	lzo_uint input_size = len_src;
	int r = lzo1x_decompress(input, input_size, *ptr_dest, &output_size, NULL);
	if( r == LZO_E_OK ) {
		*len_dest = output_size;
		return true;
	} else {
		return false;
	}
}

bool MiniLZO::decompress(void *ptr_src, size_t len_src, string & dest)
{
	lzo_uint output_size = (len_src * 10 * 1024) + 1;
	unsigned char *output = (unsigned char *) malloc(output_size);
	unsigned char *input = (unsigned char *)ptr_src;
	lzo_uint input_size = len_src;
	int r = lzo1x_decompress(input, input_size, output, &output_size, NULL);
	if( r == LZO_E_OK ) {
		dest.append((char *)output, (size_t)output_size);
		free(output);
		output = NULL;
		return true;
	} else {
		return false;
	}
}
