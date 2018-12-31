#ifndef __FILE_DESCRIPTOR_H__
#define __FILE_DESCRIPTOR_H__

#include <sys/epoll.h>

namespace UBACIPC
{
    class EventFax;

	/// class FileDescriptor
	class FileDescriptor
	{
			// Attributes
		public:
			/// Create FileDescriptor with descriptor `fd'.
			FileDescriptor(int fd);
            FileDescriptor();

            virtual ~FileDescriptor() {}

            int getDescriptor() { return this->descriptor; }

            virtual int handleIN() = 0;
            virtual void handleOUT() = 0;
            virtual void handleERROR() = 0;


            void markForRemovalFromEventFax();

            bool isMarkedForRemovalFromEventFax();

            bool isRemFromEFax();

            bool isDataAvailForRead();

            friend class UBACIPC::EventFax;

        protected:
            void addOUTEvent();
            void delOUTEvent();

           /// Descriptor member.
            int descriptor;

            void setDataAvailForRead(bool flag);

        private:
            EventFax * eventFax;

            bool bMarkRemFromEFax;

            bool bRemovedFromEFax;

            bool bDataAvailForRead;
        #ifndef _WIN32
            /// epoll event structure
            struct epoll_event epollEventData;
        #endif

            void init();
 
    };
};

#endif /* __FILE_DESCRIPTOR_H__ */
