#ifndef __TIMER_EVENTS_H__
#define __TIMER_EVENTS_H__

#include <iostream>
#include <map>
#include <string>
#include <vector>
#ifndef WIN32
#include <sys/time.h>
#endif
#include <ubacutils/IFHelper.h>

using namespace std;

namespace UBACIPC
{

	/** Structure to define a timed event. `event_callback' is the function
	  * which is invoked with user data as `data'.
	  */
	struct ubac_timed_event_t {
		void (*event_callback)(void *);
		void *data;
		bool isPeriodic;
		uint32_t timer;
	};

	/** Class to manage timed events. */
	class TimerEvents
	{
		public:
			TimerEvents();
			virtual ~TimerEvents() {}

			/** Check for events and invoke them. */
			void check_for_events();

			/** Add an event with callback as `f', user data as `data' and timer as time in seconds,
			  * after which the event needs to be invoked. */
			void addEvent( void (*f)(void *), void *data, uint32_t timer);
			/** Add a periodic event with callback as `f', user data as `data' and timer as time in seconds,
			  * after which the event needs to be invoked. */
			void addPeriodicEvent( void (*f)(void *), void *data, uint32_t timer);

		private:
			map<time_t, vector<struct ubac_timed_event_t> >timed_events;

			void addEvent(struct ubac_timed_event_t event);
	};
};

using namespace UBACIPC;

#endif /* __TIMER_EVENT_H__ */
