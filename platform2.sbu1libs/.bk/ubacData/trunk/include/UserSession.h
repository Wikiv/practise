#ifndef __UBAC_USER_SESSION_H__
#define __UBAC_USER_SESSION_H__

#include <iostream>
#include <string>
#include <vector>
#include "UBACData.h"
using namespace std;

namespace UBAC {
	/// Class UserSession - Represents a session created for a user.
	class UserSession {
		public:
			/** Create the user session. 'm_session' is the session id of the user. */
			UserSession(string m_session);
			~UserSession();

			/** Set the default Account ID. */
			void setDefaultAccountID(string m_accountID);
			/** Set linked account. User can have more than 1 linked account. */
			void setLinkedAccountID(string m_accountID);
			/** Set the default account number. */
			void setDefaultAccountNumber(string m_accountNumber);
			/** Set the linked account's account number. */
			void setLinkedAccountNumber(string m_accountNumber);
			/** Ser the default display name for the user. */
			void setDisplayName(string m_displayName);
			/** Get the default Account ID. */
			string getDefaultAccountID();
			/** Get the default Account Number. */
			string getDefaultAccountNumber();
			/** Get the user session id. */
			string getSessionID();
			/** Get the default display name for the user. */
			string getDisplayName();
			/** Get the list of account ids. This will also include the default account id as the 
			  * first account in the list. */
			vector<string> getAccountIDList();
			/** Get the list of account numbers. This will also include the default account number as the 
			  * first account in the list. */
			vector<string> getAccountNumberList();

			/** Set the unique identifier for the user.*/
			void setUniqueID(string m_uniqueID);
			/** Get the unique identifier for the user. */
			string getUniqueID();
			/** Get the account number from the account id. */
			void getAccountNumberFromAccountID(string m_accountID, string & m_accountNumber);

			/** Set all the accounts as mentioned in 'allAccounts'. */
			void setAllAccounts(vector<AccountDetails> allAccounts);
			/** Get the account details for the account 'accountId'. */
			AccountDetails & getAccountDetails( string accountId );

		private:
			vector<AccountDetails>accountList;
			vector<string>accountIDList;
			vector<string>accountNumberList;
			string defaultAccountID, defaultAccountNumber;
			string sessionID;
			string displayName;
			string uniqueID;
	};
};

using namespace UBAC;
#endif /* __UBAC_USER_SESSION_H__ */
