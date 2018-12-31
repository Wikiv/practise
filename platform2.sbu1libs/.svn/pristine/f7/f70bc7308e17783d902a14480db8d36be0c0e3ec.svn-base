#ifndef __UBAC_MESSAGE_QUEUE_H__
#define __UBAC_MESSAGE_QUEUE_H__

#include <queue>
#include <ubacipc/Mutex.h>

namespace UBAC
{
	using namespace std;
	/// Generic MessageQueue.
	template <class MessageQueueItem>
	class MessageQueue :
		public Mutex
	{
		public:
			MessageQueue() {}
			~MessageQueue() {}

			/** Insert a message into the queue. */
			void enqueue(const MessageQueueItem item)
			{
				lock();
				msgQ.push(item);
				unlock();
			}

			/** Delete the first message from the queue. */
			MessageQueueItem dequeue()
			{
				lock();
				MessageQueueItem item = msgQ.front();

				if( !isEmpty() )
					msgQ.pop();

				unlock();
				return item;
			}

			/** Check if the queue is empty. */
			bool isEmpty()
			{
				return msgQ.empty();
			}

			/** Get the size of the queue. */
			size_t size()
			{
				return msgQ.size();
			}

		private:
			queue<MessageQueueItem> msgQ;
	};
};


#endif /* __UBAC_MESSAGE_QUEUE_H__ */
