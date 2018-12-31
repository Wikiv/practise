#include "Thread.h"

#ifdef _WIN32
uint32_t __start_thread(void *data)
#else
static void *__start_thread(void *data)
#endif
{
	Thread *th = static_cast<Thread *>(data);
	th->run();
#ifdef _WIN32
	return NULL;
#else
	return data;
#endif
}

Thread::Thread()
{
	th_data = NULL;
}

#ifdef _WIN32
HANDLE Thread::start(void *data)
#else
pthread_t Thread::start(void *data)
#endif
{
	//printf("%lu, %p\n", pthread_self(), data);
	th_data = data;
#ifdef _WIN32
	DWORD dwThreadId;
	tid = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)__start_thread,
					   (void *)this, 0, &dwThreadId);
#else
	pthread_create(&tid, NULL, __start_thread, (void *)this);
#endif
	return tid;
}

#ifndef _WIN32
pthread_t Thread::getThreadID()
{
	return tid;
}
#endif
