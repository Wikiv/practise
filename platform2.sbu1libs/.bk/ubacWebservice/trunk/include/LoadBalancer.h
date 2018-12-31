#ifndef __UBAC_LOAD_BALANCER_H__
#define __UBAC_LOAD_BALANCER_H__

#include "MessageActor.h"

namespace UBAC
{
	/// Class LoadBalancer. Implemente a simple round-robin load balancing.
	class LoadBalancer
	{
		public:
			/// Create LoadBalancer.
			LoadBalancer();
			LoadBalancer(int poolSize, Application *app);
			~LoadBalancer();

			/** Add Actor, which will be added to the available list for round-robin.
			  * Soon after creating the LoadBalancer, add the available `actor' objects
			  * before starting to handle messages. */
			void addActor(MessageActor actor);
			/// Add a request to the next `Actor. `ptr' is the data to be handled after processing the request.
			void addMessage(string message, void *ptr);

		private:
			vector<MessageActor>actorList;
			size_t loadItem;
	};
};

using namespace UBAC;

#endif /* __UBAC_LOAD_BALANCER_H__ */
