#ifndef __UBAC_THREAD_H__
#define __UBAC_THREAD_H__

#ifdef _WIN32
#include <windows.h>
#else
#include <pthread.h>
#include <signal.h>
#endif
#include <iostream>

using namespace std;

namespace UBACIPC {
	/// Generic Thread interface. Avoid using pthread_create.
	class Thread {
		public:
			Thread();
#ifdef _WIN32
			HANDLE start(void *data);
#else
			/** Start the thread. Pass a user specific data in 'data'. */
			pthread_t start(void *data);
			/** Do not use this method. */
			pthread_t getThreadID();
#endif
			/** Implement this method to run in the thread. */
			virtual void run() {};
			void *th_data; ///< User data passed for thread's reference. 

		private:
#ifdef _WIN32
			HANDLE tid;
#else
			pthread_t tid;
#endif
	};
};

using namespace UBACIPC;

#endif /* __UBAC_THREAD_H__ */
