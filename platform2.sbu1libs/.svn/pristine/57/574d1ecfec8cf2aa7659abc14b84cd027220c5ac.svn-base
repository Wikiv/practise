#ifndef __SBU2_HTTP_SERVER_H__
#define __SBU2_HTTP_SERVER_H__

#include <iostream>

#include <ubacipc/EventFax.h>
#include <ubacipc/HTTPServer.h>
#include <ubacipc/HTTPClient.h>
#include <ubacipc/Thread.h>
#include <ubacipc/Mutex.h>

#include "SBU2WebService.h"
#include "SBU2MessageQueue.h"


namespace SBU2
{
	/// Class SBU2MessageActor
	class SBU2MessageActor :
		public UBACIPC::Thread
	{
		public:
			/** Create SBU2MessageActor, which will receive all requests to be handled by the
			  * respective application service */
			SBU2MessageActor(map<string, SBU2WebService *> *mJsonWebservice);
			~SBU2MessageActor();

			/// Add message to the queue.
			void addMessage(HTTPServerRequest *message, void *ptr);
			/// Run in loop. Keep waiting for requests and process as and when received.
			void run();

		private:
			MessageQueue< map<HTTPServerRequest *, void *> > *messageQ;
			Mutex *mutex;
			map<string, SBU2WebService *> *mJsonWebservice;
	};

	/// Class SBU2LoadBalancer
	class SBU2LoadBalancer
	{
		public:
			/// Create LoadBalancer.
			SBU2LoadBalancer(int poolSize, map<string, SBU2WebService *> *mJsonWebservice);
			~SBU2LoadBalancer();

			/** Add Actor, which will be added to the available list for round-robin.
			  * Soon after creating the LoadBalancer, add the available `actor' objects
			  * before starting to handle messages. */
			void addActor(SBU2MessageActor * actor);
			/// Add a request to the next `Actor. `ptr' is the data to be handled after processing the request.
			void addMessage(HTTPServerRequest *message, void *ptr);

		private:
			vector<SBU2MessageActor *>actorList;
			size_t loadItem;
	};

	/// Class SBU2HTTPListner
        class SBU2HTTPListner:
            public HTTPListner
        {   
        	public:
			/** Create SBU2HTTPListner. */
            		SBU2HTTPListner(SBU2LoadBalancer * lBalancer);
	               ~SBU2HTTPListner();

			/** Adds the get request to the load balancer. */
           		void onGetRequest(HTTPServerRequest * request,
                    		HTTPConnection *client);

			/** Adds the post request to the load balancer. */
            		void onPostRequest(HTTPServerRequest * request,
                    		HTTPConnection *client);

        	private:
            		SBU2LoadBalancer * lBalancer;    

    	};

    	/// Wrapper class for SBU2HTTPServer
    	class SBU2HTTPServer :
        	public Thread
    	{
        	public:
			/// Create SBU2HTTPServer. */
            		SBU2HTTPServer(int port, SBU2LoadBalancer *lBalancer, bool bForceHTTPS = false);

            		~SBU2HTTPServer();
			/** Adds the http server to the event fax. */
            		void run();
                    EventFax *getEventFax();

        	private:
            		EventFax *fax;
            		HTTPServer * httpServer;
            		SBU2HTTPListner * httpListner;

    	};

};

#endif /* __SBU2_HTTP_SERVER_H__ */
