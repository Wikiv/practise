#ifndef __UBAC_SEMAPHORE_H__
#define __UBAC_SEMAPHORE_H__

#include <stdio.h>
#include <sys/sem.h>

using namespace std;

//! class Semaphore
namespace UBACIPC
{
	//! Class Semaphore for critical sections.
	class Semaphore
	{
		private:
            union semun {
                    int val;
                    struct semid_ds *buf;
                    unsigned short int *array;
                    struct seminfo *__buf;
            };
            int nSemaphoreID;
            struct sembuf lockSemaphore;
            struct sembuf unlockSemaphore;
		public:
            Semaphore();
            ~Semaphore();
            void initSemaphore(int nKey, int nNoOfSem);
            void setSemaphoreValue();
            int semaphoreLock(int nFlag);
            int semaphoreUnLock(int nFlag);
            void removeSemaphore();
	};
};

using namespace UBACIPC;

#endif /* __UBAC_SEMAPHORE_H__ */
