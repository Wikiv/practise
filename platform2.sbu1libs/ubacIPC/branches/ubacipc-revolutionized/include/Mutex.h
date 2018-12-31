#ifndef __UBAC_MUTEX_H__
#define __UBAC_MUTEX_H__

#ifdef _WIN32
#include <windows.h>
#else
#include <pthread.h>
#endif


//! class PThreadMutex - Wrapper for pthread_mutex
namespace UBACIPC
{
	//! Class Mutex for critical sections.
	class Mutex
	{
		private:
#ifdef _WIN32
			HANDLE mutex;
#else
			pthread_mutex_t mutex;
			pthread_mutexattr_t mutexAttr;
			pthread_cond_t condition;
			pthread_condattr_t condAttr;
#endif

		public:
			Mutex();
			~Mutex();
			//! Acquire a lock through a critical section. 
			void lock ();
			//! Release the lock. 
			void unlock ();
			//! Suspend the current thread until some other thread awakens this. 
			void wait();
			//! Suspend the current thread for a few seconds as in 'timeInSeconds'. 
			int wait(int timeInSeconds);
			//! Notify one of the suspended threads. 
			void notify();
			//! Notify all suspended thread. This results in the 'wait' call to return. 
			void notifyAll();
	};
};

using namespace UBACIPC;

#endif /* __UBAC_MUTEX_H__ */
