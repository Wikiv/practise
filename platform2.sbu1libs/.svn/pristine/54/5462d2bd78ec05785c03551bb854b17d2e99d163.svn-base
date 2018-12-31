#ifndef __UBAC_EXCEPTIONS_H__
#define __UBAC_EXCEPTIONS_H__

#include <iostream>
#include <exception>

using namespace std;

namespace UBAC {
	/// Class Exceptions for custom exceptions.
	class Exceptions :
		public exception
	{
		public:
			~Exceptions() throw() {}
			/** Set the error message causing the exception. */
			void setMessage(string message)
			{
				exceptionStr.append( message );
			}

			/** Returns the error message. */
			virtual const char* what() const throw() {
				return exceptionStr.c_str();
			}

		private:
			string exceptionStr;
	};
};

using namespace UBAC;

#endif /* __UBAC_EXCEPTIONS_H__ 8 */
