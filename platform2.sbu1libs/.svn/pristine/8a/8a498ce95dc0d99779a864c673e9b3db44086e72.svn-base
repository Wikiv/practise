#include "TimerEvents.h"

TimerEvents::TimerEvents()
{
}

void TimerEvents::check_for_events()
{
	time_t t = time(NULL);
	map<time_t, vector<struct ubac_timed_event_t> >::iterator iEvent = timed_events.begin();
	while( iEvent != timed_events.end() ) {
//		cout << "first = " << iEvent->first << ", Current = " << t << endl;
		if( iEvent->first > t )
			break;
		vector<struct ubac_timed_event_t>::iterator iEventList = iEvent->second.begin();
		while( iEventList != iEvent->second.end() ) {
			(*iEventList).event_callback( (*iEventList).data );
			if( (*iEventList).isPeriodic ) 
				addEvent( *iEventList );
			iEventList++;
		}
		timed_events.erase (iEvent);
		iEvent = timed_events.begin();
	}
}

void TimerEvents::addEvent( void (*f)(void *), void *data, uint32_t timer)
{
	struct ubac_timed_event_t timed_event;
	timed_event.event_callback = f;
	timed_event.data = data;
	timed_event.isPeriodic = false;
	timed_event.timer = timer;
	addEvent(timed_event);
}

void TimerEvents::addPeriodicEvent( void (*f)(void *), void *data, uint32_t timer)
{
	struct ubac_timed_event_t timed_event = {f, data, true, timer};
	/*
	timed_event.event_callback = f;
	timed_event.data = data;
	timed_event.isPeriodic = true;
	*/
	addEvent(timed_event);
}

void TimerEvents::addEvent(struct ubac_timed_event_t event)
{
	time_t t = time(NULL);
	t = t + (time_t)event.timer;

	timed_events[t].push_back( event );
}
