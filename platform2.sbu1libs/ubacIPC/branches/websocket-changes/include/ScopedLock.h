#ifndef __UBAC_SCOPED_LOCK_H_
#define __UBAC_SCOPED_LOCK_H_

#include "Mutex.h"

namespace UBACIPC {

	class ScopedLock
	{
	public:
		ScopedLock( Mutex* mutex ): m_Mutex(mutex)
		{
			m_Mutex->lock();
		}

		~ScopedLock()
		{
			m_Mutex->unlock();
		}
	private:
		Mutex *m_Mutex;
		//Non Copyable
		ScopedLock( const ScopedLock& ); 
		ScopedLock& operator= ( const ScopedLock& );
	};
}

#endif
