#include "Mutex.h"

Mutex::Mutex()
{
#ifdef _WIN32
#else
	pthread_mutexattr_init( &mutexAttr );
	pthread_condattr_init( &condAttr );

	pthread_mutex_init( &mutex, &mutexAttr );
	pthread_cond_init( &condition, &condAttr );
#endif
}

Mutex::~Mutex()
{
#ifdef _WIN32
#else
	pthread_mutex_destroy( &mutex );
	pthread_mutexattr_destroy( &mutexAttr );

	pthread_cond_destroy( &condition );
	pthread_condattr_destroy( &condAttr );
#endif
}

void Mutex::lock()
{
#ifdef _WIN32
	WaitForSingleObject(mutex, 0);
#else
	pthread_mutex_lock( &mutex );
#endif
}

void Mutex::unlock()
{
#ifdef _WIN32
	ReleaseMutex(mutex);
#else
	pthread_mutex_unlock( &mutex );
#endif
}

void Mutex::wait()
{
#ifdef _WIN32
	WaitForSingleObject(mutex, 0);
#else
	pthread_cond_wait( &condition, &mutex );
#endif
}

int Mutex::wait(int timeInSeconds)
{
	int status = 0;
#ifdef _WIN32
	status = WaitForSingleObject(mutex, (timeInSeconds*1000));
#else
	time_t t = time(NULL);
	struct timespec timeSpec = { t + timeInSeconds, 0 };
	lock();
	status = pthread_cond_timedwait( &condition, &mutex, &timeSpec );
	unlock();
	return status;
#endif
	return status;
}

void Mutex::notify()
{
#ifdef _WIN32
	ReleaseMutex(mutex);
#else
	pthread_cond_signal( &condition );
#endif
}

void Mutex::notifyAll()
{
#ifdef _WIN32
	ReleaseMutex(mutex);
#else
	pthread_cond_broadcast( &condition );
#endif
}

