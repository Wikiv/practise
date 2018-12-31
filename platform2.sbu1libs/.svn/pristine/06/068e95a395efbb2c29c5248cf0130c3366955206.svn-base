#ifndef __SOCKET_DESCRIPTOR_H__
#define __SOCKET_DESCRIPTOR_H__

#ifdef _WIN32
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <io.h>
#include <stdio.h>
#else
#include <sys/epoll.h>
#endif

namespace UBACIPC
{
	/// class SocketDescriptor
	class SocketDescriptor
	{
			// Attributes
		public:
			/// Create SocketDescriptor with descriptor `fd'.
			SocketDescriptor(int fd)
			{
				descriptor = fd;
			};
			SocketDescriptor() {}
#ifndef _WIN32
			struct epoll_event epollEventData;
#endif
			/// Descriptor member.
			int descriptor;
	};
};

using namespace UBACIPC;

#endif /* __SOCKET_DESCRIPTOR_H__ */
