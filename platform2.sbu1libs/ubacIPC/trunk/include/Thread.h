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

namespace UBACIPC
{
	//! Thread Interface Class.Avoid Using pthread_create 
	/*!
	  This Class acts as an Interface for thread Creation,It Provides all the basic thread functionality for creatring,running threads 
	 */
	class Thread
	{
		public:
			//! Thread Constructor.
			Thread();
#ifdef _WIN32
			//! Starts the Thread with  data passed .
			/*!
			  \param data is the parameter  passed to the  thread which is going to run.
			  The data  is stored as public member variable . 
			  This data can be accessed by public member  th_data.
			  \sa th_data
			 */
			HANDLE start(void *data);
#else
			//! Starts the Thread with  data passed .
			/*!
			  \param data is the parameter passed to the  thread which is going to run.
			  The data  is stored as public member variable . 
			  This data can be accessed by public member  th_data.
			  \sa th_data
			 */

			pthread_t start(void *data);
			//! Used to get the thread id of thread created
			pthread_t getThreadID();
#endif
			//! Virtual Funtion run 
			/*!
			  Implement this method to run in the thread. 
			 */
			virtual void run() {};
			//! User data passed to Thread's refernce 
			/*!
			  The data passed by user is stored as public member variable . 
			  \sa start()
			 */
			void *th_data; 

		private:
#ifdef _WIN32
			//! Thread id of the thread created.
			HANDLE tid;
#else
			//! Thread id of the thread created.
			pthread_t tid;
#endif
	};
};

using namespace UBACIPC;

#endif /* __UBAC_THREAD_H__ */
