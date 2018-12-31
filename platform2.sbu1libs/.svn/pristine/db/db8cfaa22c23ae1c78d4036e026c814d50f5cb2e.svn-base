#ifndef __UBAC_MESSAGE_ACTOR_H__
#define __UBAC_MESSAGE_ACTOR_H__

#include <iostream>
#include <string>

#include <ubacipc/Thread.h>
#include <ubacipc/Mutex.h>

#include "Application.h"
#include "MessageQueue.h"

namespace UBAC
{

	using namespace std;
	/// Class MessageActor.
	class MessageActor :
		public Thread
	{
		public:
			/** Create MessageActor, which will receive all requests to be handled by the
			  * application handler `m_app'. */
			MessageActor(Application *m_app);
			~MessageActor();

			/// Add message to the queue.
			void addMessage(string message, void *ptr);
			/// Run in loop. Keep waiting for requests and process as and when received.
			void run();

		private:
			MessageQueue< map<string, void *> > *messageQ;
			Mutex *mutex;
			Application *app;
	};
};

#endif /* __UBAC_MESSAGE_ACTOR_H__ */
