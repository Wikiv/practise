#ifndef __UBAC_SHAREDMEMORY_H__
#define __UBAC_SHAREDMEMORY_H__

#include <sys/shm.h>
#include <stdio.h>

using namespace std;

//! class SharedMemory
namespace UBACIPC
{
	//! Class Shared Memory.
	class SharedMemory
	{
		private:
            int nSharedMemoryID;
            void *sSharedMemoryRegionName;
		public:
            int initSharedMemory(int nKey,int nSize, bool bIsServer);
            void *attachSharedMemory(int nSID, bool bIsServer);
            int detachSharedMemory(void *sRegionName);
            int destroySharedMemory(int nSID);
            void *getSharedMemoryRegion();
	};
};

using namespace UBACIPC;

#endif /* __UBAC_SHAREDMEMORY_H__ */
