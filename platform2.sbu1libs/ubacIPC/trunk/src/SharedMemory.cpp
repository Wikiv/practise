#include "SharedMemory.h"

int SharedMemory::initSharedMemory(int nKey, int nSize, bool bIsServer)
{
    if(bIsServer)
    {
        nSharedMemoryID = shmget(nKey, nSize, IPC_CREAT | 0666);
    }
    else
    {
        nSharedMemoryID = shmget(nKey, nSize, 0444);
    }
    if(nSharedMemoryID < 0)
    {
        perror("Error creating shared memory\n");
        return -1;
    }
    return nSharedMemoryID;
}

void *SharedMemory::attachSharedMemory(int nSID, bool bIsServer)
{
    if(bIsServer)
    {
        sSharedMemoryRegionName = shmat(nSID, NULL, 0);
    }
    else
    {
        sSharedMemoryRegionName = shmat(nSID, NULL, SHM_RDONLY);
    }
    if(sSharedMemoryRegionName < 0)
    {
        perror("Error in shared memory attach\n");
    }
    return sSharedMemoryRegionName;
}

int SharedMemory::detachSharedMemory(void *sSMRName)
{
    if(shmdt(sSMRName))
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int SharedMemory::destroySharedMemory(int nSID)
{
    if(shmctl(nSID, IPC_RMID, NULL))
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

void *SharedMemory::getSharedMemoryRegion()
{
    return sSharedMemoryRegionName;
}
