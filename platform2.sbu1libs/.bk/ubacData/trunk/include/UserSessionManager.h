#ifndef __UBAC_USER_SESSION_MANAGER_H__
#define __UBAC_USER_SESSION_MANAGER_H__

#include <map>

using namespace std;

#include "UserSession.h"
#include <ubacipc/Mutex.h>

namespace UBAC {
	/// Class UserSessionManager to manage a set of sessions managed by `Application'.
	class UserSessionManager :
		public Mutex,
		public map<string, UserSession>
	{
		public:
			/// Create UserSessionManager. Usually this is inherited by `Application'.
			UserSessionManager();
			~UserSessionManager();

			/** Create a user session and store in local program memory. */
			void createSession(string username, string sessionID);
			/** Delete a user session from the local program memory. */
			void deleteSession(string sessionID);
			/** Check if the user session already exists. */
			bool hasUserSession(string sessionID);
			/** Retrieve the user session for the session 'sessionID'. */
			UserSession * getUserSession(string sessionID);

		private:
			map<string, string>sessionToUserMap;
	};
};

using namespace UBAC;

#endif /* __UBAC_USER_SESSION_MANAGER_H__ */
