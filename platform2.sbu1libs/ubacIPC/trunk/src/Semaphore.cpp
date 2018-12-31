#include "Semaphore.h"

// Initializes the sembuf structure which inturn performs semaphore operation
Semaphore::Semaphore()
{
    lockSemaphore.sem_num = unlockSemaphore.sem_num = 0; /* Semaphore number */
    lockSemaphore.sem_op = -1; /* Semaphore operation */
    unlockSemaphore.sem_op = 1; /*Semaphore operation */
    lockSemaphore.sem_flg = unlockSemaphore.sem_num = 0; /* Operation flags */    
}

// Removes the semaphore
Semaphore::~Semaphore()
{
    removeSemaphore();
}

// Initializes or gains access to semaphore
void Semaphore::initSemaphore(int nKey, int nNoOfSem)
{
    nSemaphoreID = semget(nKey, nNoOfSem, IPC_CREAT | 0666);
    if(nSemaphoreID < 0)
    {
        perror("Error creating semaphore\n");
    }
}

// Controls Semaphores. Changes permissions and other characteristics of semaphore
void Semaphore::setSemaphoreValue()
{
    union semun semopts;
    semopts.val = 1;
    semctl(nSemaphoreID, 0, SETVAL, semopts);
}

// Performs lock operation on the semaphore set defined by the sembuf structure
int Semaphore::semaphoreLock(int nFlag)
{
     lockSemaphore.sem_num = nFlag;
     int nReturnValue = semop(nSemaphoreID, &lockSemaphore, 1);
     if(nReturnValue == -1)
     {
        perror("Error in locking\n");
     }
     return nReturnValue;
}

// Performs unlock operation on the semaphore set defined by the sembuf structure
int Semaphore::semaphoreUnLock(int nFlag)
{
     unlockSemaphore.sem_num = nFlag;
     int nReturnValue = semop(nSemaphoreID, &unlockSemaphore, 1);
     if(nReturnValue == -1)
     {
        perror("Error in unlocking\n");
     }
     return nReturnValue;
}

// Removes the specified semaphore set
void Semaphore::removeSemaphore()
{
    semctl(nSemaphoreID, 0, IPC_RMID);
}
