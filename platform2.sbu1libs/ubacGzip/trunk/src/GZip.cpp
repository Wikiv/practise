#include "GZip.h"

const size_t GZip::CHUNK = 16384;
const size_t GZip::GZIP_WINDOWS_SIZE = 40;
const size_t GZip::ZLIB_WINDOWS_SIZE = 15;

GZip::GZip()
{
	nWindowsSize = GZIP_WINDOWS_SIZE;
	p_data = NULL;
}

GZip::GZip(void *ptr, size_t len, int nDecompressionType)
{
	SetWindowsSize(nDecompressionType);
	p_data = (char *)calloc(1, len+1);
	memcpy(p_data, ptr, len);
	length = len;
}


GZip::GZip(string fileName, int nDecompressionType)
{
	SetWindowsSize(nDecompressionType);
	int fd = open(fileName.c_str(), O_RDONLY);
	if( fd > 0 ) {
		struct stat stat_buf;
		memset(&stat_buf, '\0', sizeof(struct stat));
		fstat(fd, &stat_buf);
		length = stat_buf.st_size;
		p_data = (char *)calloc(1, length+1);
		int read_stat = read(fd, p_data, length);
		cout << "read_stat = " << read_stat << endl;
		for(size_t i = 0; i < length; i++)
			printf("%d, ", *( (char *)p_data + i ));
		cout << endl;
	} else {
		cout << "unable to open file" << endl;
	}
	close(fd);
}

GZip::~GZip()
{
	if( p_data )
		free(p_data);
	p_data = NULL;
}

void GZip::SetWindowsSize(int nDecompressionType)
{
	if(nDecompressionType == GZIP)
	{
		nWindowsSize = GZIP_WINDOWS_SIZE;
	}
	else if(nDecompressionType == ZLIB)
	{
		nWindowsSize = ZLIB_WINDOWS_SIZE;
	}
}

bool GZip::inflateGet(string & response)
{
	unsigned char *ptr = NULL;
	size_t length = 0;
	bool flag = inflateGet((void *)ptr, &length);
	if( flag ) 
		response.append((char *)ptr, length);
	return flag;
}

bool GZip::inflateGet(unsigned char *ptr, size_t len, string & output)
{
	int ret;
	unsigned have;
	z_stream strm;
	unsigned char in[CHUNK];
	unsigned char out[CHUNK];

	/* allocate inflate state */
	strm.zalloc = Z_NULL;
	strm.zfree = Z_NULL;
	strm.opaque = Z_NULL;
	strm.avail_in = 0;
	strm.next_in = Z_NULL;
	ret = inflateInit(&strm);
	if (ret != Z_OK) 
		return ret;

	/* decompress until deflate stream ends or end of file */
	do {
		memcpy(in, ptr, len);
		strm.avail_in = len;
		strm.next_in = in;
		/* run inflate() on input until output buffer not full */
		do {
			strm.avail_out = CHUNK;
			strm.next_out = out;
			ret = inflate(&strm, Z_NO_FLUSH);
			assert(ret != Z_STREAM_ERROR);  /* state not clobbered */
			switch (ret) {
				case Z_NEED_DICT:
					ret = Z_DATA_ERROR;     /* and fall through */
				case Z_DATA_ERROR:
				case Z_MEM_ERROR:
					(void)inflateEnd(&strm);
					return ret;
			}
			have = CHUNK - strm.avail_out;
			output.append((char *)&out[0], have);
		} while (strm.avail_out == 0);
		/* done when inflate() says it's done */
	} while (ret != Z_STREAM_END);
	/* clean up and return */
	(void)inflateEnd(&strm);
	return ret == Z_STREAM_END ? Z_OK : Z_DATA_ERROR;
}

bool GZip::inflateGet(void *ptr, size_t * ptr_length)
{
	int ret;
	unsigned have;
	z_stream strm;
	unsigned char in[CHUNK];
	unsigned char out[CHUNK];

	/* allocate inflate state */
	strm.zalloc = Z_NULL;
	strm.zfree = Z_NULL;
	strm.opaque = Z_NULL;
	strm.avail_in = 0;
	strm.next_in = Z_NULL;

	ret = inflateInit2(&strm, nWindowsSize);

	printf("%d: inflate ret = %d\n", __LINE__, ret);
	if (ret != Z_OK)
		return false;

	/* decompress until deflate stream ends or end of file */
	//	do {
	memcpy(in, p_data, length);
	strm.avail_in = length;
	//		strm.avail_in = fread(in, 1, CHUNK, source);
	printf("avail_in = %d\n", strm.avail_in);
	/*
	   if (ferror(source)) {
	   (void)inflateEnd(&strm);
	   return false;
	   }

	   if (strm.avail_in == 0)
	   break;
	 */

	strm.next_in = in;

	/* run inflate() on input until output buffer not full */

	do {
		strm.avail_out = CHUNK;
		strm.next_out = out;
		ret = inflate(&strm, Z_NO_FLUSH);
		printf("%d: inflate ret = %d\n", __LINE__, ret);

		if( ret == Z_STREAM_ERROR )
			cout << "Z_STREAM_ERROR" << endl;
		else if( ret == Z_NEED_DICT )
			cout << "Z_NEED_DICT" << endl;
		else if( ret == Z_DATA_ERROR )
			cout << "Z_DATA_ERROR" << endl;
		else if( ret == Z_MEM_ERROR )
			cout << "Z_MEM_ERROR" << endl;

		assert(ret != Z_STREAM_ERROR);  /* state not clobbered */
		switch (ret) {
			case Z_NEED_DICT: ret = Z_DATA_ERROR;     /* and fall through */
			case Z_DATA_ERROR:
			case Z_MEM_ERROR: (void)inflateEnd(&strm);
					  return false;
		}
		have = CHUNK - strm.avail_out;
		memcpy((char *)ptr+(*ptr_length), out, have);
		*ptr_length = *ptr_length + have;
		//			response.append((char *)out, have);
	} while (strm.avail_out == 0);
	/* done when inflate() says it's done */
	//	} while (ret != Z_STREAM_END);

	/* clean up and return */
	(void)inflateEnd(&strm);
	return ret == Z_STREAM_END ? true : false;
}

bool GZip::deflateGet(unsigned char *data,size_t len,
		unsigned char **destPtr, size_t *dLen, int level)
{
	int ret;
	unsigned have;
	z_stream strm;
	unsigned char out[CHUNK];

	unsigned char *comData=NULL;
	/* allocate deflate state */
	strm.zalloc = Z_NULL;
	strm.zfree = Z_NULL;
	strm.opaque = Z_NULL;
	ret = deflateInit(&strm, level);
	if (ret != Z_OK)
		return false;

	strm.avail_in = len;
	//  memcpy(in,data,len);
	strm.next_in = data;

	/* run deflate() on input until output buffer not full, finish
	   compression if all of source has been read in */
	size_t ind = 0;
	do {
		strm.avail_out = CHUNK;
		strm.next_out = out;
		ret = deflate(&strm, Z_FINISH);    /* no bad return value */
		assert(ret != Z_STREAM_ERROR);  /* state not clobbered */
		have = CHUNK - strm.avail_out;

		if(have != 0)
		{
			comData = (unsigned char *) realloc(comData,ind+have);
			memcpy( (char *)comData+ind, out, have);
			ind +=have;
		}
		/*          for(int i =0; i<have;i++)
			    {
			    printf("%c",out[i]);
			    } */
		cout<<"inside do while\n";
	} while (strm.avail_out == 0);
	assert(strm.avail_in == 0);     /* all input will be used */

	*dLen = ind;
	assert(ret == Z_STREAM_END);        /* stream will be complete */
	*destPtr = comData;
	/* clean up and return */
	(void)deflateEnd(&strm);
	return true;
}


void GZip::zerr(int ret)
{
	fputs("zpipe: ", stderr);
	switch (ret) {
		case Z_ERRNO:
			if (ferror(stdin))
				fputs("error reading stdin\n", stderr);
			if (ferror(stdout))
				fputs("error writing stdout\n", stderr);
			break;
		case Z_STREAM_ERROR:
			fputs("invalid compression level\n", stderr);
			break;
		case Z_DATA_ERROR:
			fputs("invalid or incomplete deflate data\n", stderr);
			break;
		case Z_MEM_ERROR:
			fputs("out of memory\n", stderr);
			break;
		case Z_VERSION_ERROR:
			fputs("zlib version mismatch!\n", stderr);
	}
}

