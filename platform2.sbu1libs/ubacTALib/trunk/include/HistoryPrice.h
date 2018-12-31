#ifndef __HISTORY_PRICE_H__
#define __HISTORY_PRICE_H__

#include <ubacutils/IFHelper.h>

namespace UBACTA
{
	/// Class HistoryPrice to set history data.
	class HistoryPrice
	{
		public:
			HistoryPrice();
			~HistoryPrice();

			/** Set Open price for the time frame. */
			void setOpen(double mOpen);
			/** Set High price for the time frame. */
			void setHigh(double mHigh);
			/** Set Low price for the time frame. */
			void setLow(double mLow);
			/** Set Close price for the time frame. */
			void setClose(double mClose);
			/** Set Volume for the time frame. */
			void setVolume(uint32_t mVolume);
			/** Set timestamp ending for the time frame. */
			void setDate(time_t mTimestamp);

			/** Set Open price for the time frame. */
			void setOpen(string mOpen);
			/** Set High price for the time frame. */
			void setHigh(string mHigh);
			/** Set Low price for the time frame. */
			void setLow(string mLow);
			/** Set Close price for the time frame. */
			void setClose(string mClose);
			/** Set Volume for the time frame. */
			void setVolume(string mVolume);

			/** Set Open price for the time frame with precision. */
			void setOpen(double mOpen, int precision);
			/** Set High price for the time frame with precision. */
			void setHigh(double mHigh, int precision);
			/** Set Low price for the time frame with precision. */
			void setLow(double mLow, int precision);
			/** Set Close price for the time frame with precision. */
			void setClose(double mClose, int precision);

			/** Return the symbol. */
			string getSymbol();
			/** Returns the Open price for the time frame. */
			double getOpen();
			/** Returns the High price for the time frame. */
			double getHigh();
			/** Returns the Low price for the time frame. */
			double getLow();
			/** Returns the Close price for the time frame. */
			double getClose();
			/** Returns the Volume for the time frame. */
			uint32_t getVolume();
			/** Returns the timestamp for the time frame. */
			time_t getTime();

		private:
			string open, high, low, close, volume;
			time_t timestamp;
			IFHelper ifHelper;
	};
}

#endif /* __HISTORY_PRICE_H__ */
