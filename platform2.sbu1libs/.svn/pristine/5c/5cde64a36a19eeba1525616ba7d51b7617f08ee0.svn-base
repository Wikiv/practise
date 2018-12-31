#ifndef __TA_ENGINE_H__
#define __TA_ENGINE_H__

#include <math.h>
#include <exception>
#include <ta-lib/ta_libc.h>

#include <ubacutils/IFHelper.h>
#include <jsonparser/JsonParser.h>

#include "GenericCache.h"
#include "HistoryPrice.h"

#define DEFAULT_MA_PERIOD	10

typedef struct stRCINode {
	double value;
	float rank;
	int pos;
} RCI_NODE;



namespace UBACTA
{

	/// Class TAEngine for technical indicators.
	class TAEngine
	{
		public:
			TAEngine();
			~TAEngine() {};

			enum {
				TAEngine_SMA=1,
				TAEngine_EMA=2,
				TAEngine_KAMA,
				TAEngine_SMMA,
				TAEngine_TRIMA,
				TAEngine_MOM,
				TAEngine_T3,
				TAEngine_WMA,
				TAEngine_VMA,
				TAEngine_WILDER_MA,
				TAEngine_DOUBLE_EMA,
				TAEngine_TRIPLE_EMA,
				TAEngine_TRIX,
				TAEngine_SINE_MA,
				TAEngine_ROC,
                TAEngine_ROCV,
				TAEngine_KELTNER,
				TAEngine_PSAR,
				TAEngine_MACD,
				TAEngine_TMACD,
				TAEngine_CMO,
				TAEngine_TYPPRICE,
				TAEngine_TYPPRICE_MA,
				TAEngine_AVGPRICE,
				TAEngine_MEDPRICE,
				TAEngine_OBV,
				TAEngine_MONEY_FLOW_INDEX,
				TAEngine_VOLUME_SMA,
				TAEngine_VOLUME_EMA,
				TAEngine_WILLIAM_R,
				TAEngine_CCI,
				TAEngine_ATR,
				TAEngine_BBANDS,
				TAEngine_ULTOSC,
				TAEngine_DONCHIAN_CHANNEL,
				TAEngine_RSI,
				TAEngine_FAST_STOCHASTIC,
				TAEngine_SLOW_STOCHASTIC,
				TAEngine_STOCHASTIC_RSI,
				TAEngine_AVG_DIRECTIONAL_MOVEMENT,
				TAEngine_ACCUMULATION_DISTRIBUTION,
				TAEngine_ADOSC,
				TAEngine_AROON,
				TAEngine_AO,
				TAEngine_OSC,
				TAEngine_CHO,
				TAEngine_CMF,

				TAEngine_SMA_ENVELOPE,
				TAEngine_EMA_ENVELOPE,
				TAEngine_TRIMA_ENVELOPE,
				TAEngine_VMA_ENVELOPE,
				TAEngine_WMA_ENVELOPE,
				TAEngine_TYPPRICE_ENVELOPE,
				TAEngine_AMA_ENVELOPE,
				TAEngine_WILDER_MA_ENVELOPE,
				TAEngine_OVERBOUGHT_OVERSOLD,
				TAEngine_VOLUME_RATIO,
				TAEngine_PRICE_CHANNEL,
				TAEngine_PIVOT_POINT,
				TAEngine_TSI,
				TAEngine_BUYP,
				TAEngine_GANN_HI_LO_ACTIVATOR,
				TAEngine_WALLIGATOR,
				TAEngine_AC,
				TAEngine_HA,
				TAEngine_ICH,
				TAEngine_VIDYA,
				TAEngine_EWO,
				TAEngine_MD,
				TAEngine_GATOR,
				TAEngine_LREG,
				TAEngine_KRI,
				TAEngine_ASI,
				TAEngine_WFRACTAL,
				TAEngine_RCI,
				TAEngine_MI,
				TAEngine_NVI,
				TAEngine_STARCBAND,
				TAEngine_VHF,
				TAEngine_WCLPRICE,
				TAEngine_SMMA_ENVELOPE,
				TAEngine_TSF,
				TAEngine_SROC,
				TAEngine_VWAP,
				TAEngine_WAD,
				TAEngine_COG,
				TAEngine_STDDEV_EB,
				TAEngine_DYNAMIC_MI,
				TAEngine_WWSMA,
				TAEngine_ZIGZAG,
				TAEngine_STC,
				TAEngine_PCR,
                TAEngine_CSI,
                TAEngine_FORECASTOSC,
                TAEngine_INERTIA,
                TAEngine_HTDCPERIOD,
                TAEngine_HTDCPHASE,
                TAEngine_HTTRENDMODE,
                TAEngine_HTTRENDLINE,
                TAEngine_HTSINE,
                TAEngine_HTPHASOR,
                TAEngine_MIDPRICE,
                TAEngine_MIDPOINT,
                TAEngine_TRANGE,
                TAEngine_PFE,
                TAEngine_VARIANCE,
                TAEngine_MAMA,
                TAEngine_FAMA,
                TAEngine_MINUSDI,
                TAEngine_PLUSDI,
                TAEngine_MINUSDM,
                TAEngine_PLUSDM,
                TAEngine_NATR,
                TAEngine_VOMA,
                TAEngine_HARMONIC,
                TAEngine_CLV,
                TAEngine_QSTICK,
                TAEngine_PVT,
                TAEngine_BOMP,
                TAEngine_VA,
                TAEngine_PVI,
                TAEngine_AVGDEV,
                TAEngine_MASD,
                TAEngine_MAOSC,
                TAEngine_PI,
                TAEngine_SLOPE,
                TAEngine_RSQUARE,
                TAEngine_MACD_HIST
            };

            /** Indicator map to store indicator names. */
            map <string , int> indicator_map;

            /** Process Indicator request upon history data in JsonObject */
            void process(multimap<string, string> &, vector<HistoryPrice>,
                    vector<JsonObject> & , int precision = 4);

            /** Process moving average indicators. */
            bool moving_averages(uint32_t iIndicatorType, double *dInputPrices,
                    size_t inputLength, map<string, vector<double> > & output, int maPeriod);

            /** Get number of points to be requested for history data. */
            size_t getNoOfPoints(multimap<string, string>, size_t points);

        private:
            GenericCache <string, string>supportedIndicators;

            const static string TAEngine_INDICATOR_HL;
            const static string TAEngine_INDICATOR_INERTIA;
            const static string TAEngine_INDICATOR_RVI;
            const static string TAEngine_INDICATOR_BWMFI;
            const static string TAEngine_INDICATOR_FORCE;
            const static string TAEngine_INDICATOR_DEM;
            const static string TAEngine_INDICATOR_BULLR;
            const static string TAEngine_INDICATOR_BEARS;
            const static string TAEngine_INDICATOR_INTRADAY;
            const static string TAEngine_INDICATOR_ARSI;
            const static string TAEngine_INDICATOR_STO;
            const static string TAEngine_INDICATOR_SMA;
            const static string TAEngine_INDICATOR_EMA;
            const static string TAEngine_INDICATOR_SMMA;
            const static string TAEngine_INDICATOR_TRIMA;
            const static string TAEngine_INDICATOR_TEMA;
            const static string TAEngine_INDICATOR_T3;
            const static string TAEngine_INDICATOR_DEMA;
            const static string TAEngine_INDICATOR_WMA;
            const static string TAEngine_INDICATOR_PSAR;
            const static string TAEngine_INDICATOR_MACD;
            const static string TAEngine_INDICATOR_TMACD;
            const static string TAEngine_INDICATOR_ROC;
            const static string TAEngine_INDICATOR_ROCP;
            const static string TAEngine_INDICATOR_ROCV;
            const static string TAEngine_INDICATOR_ROCR;
            const static string TAEngine_INDICATOR_ROCR100;
            const static string TAEngine_INDICATOR_MFI;
            const static string TAEngine_INDICATOR_DX;
            const static string TAEngine_INDICATOR_FSTOCH;
            const static string TAEngine_INDICATOR_SSTOCH;
            const static string TAEngine_INDICATOR_WILLR;
            const static string TAEngine_INDICATOR_AD;
            const static string TAEngine_INDICATOR_ADOSC;
            const static string TAEngine_INDICATOR_AROON;
            const static string TAEngine_INDICATOR_AO;
            const static string TAEngine_INDICATOR_OSC;
            const static string TAEngine_INDICATOR_ELDERRAY;
            const static string TAEngine_INDICATOR_CHO;
            const static string TAEngine_INDICATOR_AROONOSC;
            const static string TAEngine_INDICATOR_FORECASTOSC;
            const static string TAEngine_INDICATOR_ADX;
            const static string TAEngine_INDICATOR_ADXR;
            const static string TAEngine_INDICATOR_ATR;
            const static string TAEngine_INDICATOR_BBANDS;
            const static string TAEngine_INDICATOR_CCI;
            const static string TAEngine_INDICATOR_MOM;
            const static string TAEngine_INDICATOR_OBV;
            const static string TAEngine_INDICATOR_PPO;
            const static string TAEngine_INDICATOR_APO;
            const static string TAEngine_INDICATOR_TRIX;
            const static string TAEngine_INDICATOR_ULTOSC;
            const static string TAEngine_INDICATOR_RSI;
            const static string TAEngine_INDICATOR_STDDEV;
            const static string TAEngine_INDICATOR_AVGPRICE;
            const static string TAEngine_INDICATOR_BETA;
            const static string TAEngine_INDICATOR_CORREL;
            const static string TAEngine_INDICATOR_FAMA;
            const static string TAEngine_INDICATOR_MAMA;
            const static string TAEngine_INDICATOR_HTDCPERIOD;
            const static string TAEngine_INDICATOR_HTDCPHASE;
            const static string TAEngine_INDICATOR_HTTRENDMODE;
            const static string TAEngine_INDICATOR_HTTRENDLINE;
            const static string TAEngine_INDICATOR_HTSINE;
            const static string TAEngine_INDICATOR_HTPHASOR;
            const static string TAEngine_INDICATOR_KAMA;
            const static string TAEngine_INDICATOR_LREGCURVE;
            const static string TAEngine_INDICATOR_LREGANGLE;
            const static string TAEngine_INDICATOR_LREGINTERCEPT;
            const static string TAEngine_INDICATOR_LREGSLOPE;	
            const static string TAEngine_INDICATOR_MEDPRICE;
            const static string TAEngine_INDICATOR_MIDPOINT;
            const static string TAEngine_INDICATOR_MIDPRICE;
            const static string TAEngine_INDICATOR_MINUSDI;
            const static string TAEngine_INDICATOR_PLUSDI;
            const static string TAEngine_INDICATOR_MINUSDM;
            const static string TAEngine_INDICATOR_PLUSDM;
            const static string TAEngine_INDICATOR_NATR;
            const static string TAEngine_INDICATOR_TRANGE;
            const static string TAEngine_INDICATOR_TSF;
            const static string TAEngine_INDICATOR_TYPPRICE;
            const static string TAEngine_INDICATOR_TYPPRICE_MA;
            const static string TAEngine_INDICATOR_VARIANCE;
            const static string TAEngine_INDICATOR_WCLPRICE;
            const static string TAEngine_INDICATOR_FI;
            const static string TAEngine_INDICATOR_SLOPE;
            const static string TAEngine_INDICATOR_CLV;
            const static string TAEngine_INDICATOR_CMF;
            const static string TAEngine_INDICATOR_DPO;
            const static string TAEngine_INDICATOR_EOM;
            const static string TAEngine_INDICATOR_DOC;
            const static string TAEngine_INDICATOR_CVI;
            const static string TAEngine_INDICATOR_MI;
            const static string TAEngine_INDICATOR_NVI;
            const static string TAEngine_INDICATOR_PI;
            const static string TAEngine_INDICATOR_PVI;
            const static string TAEngine_INDICATOR_PVO;
            const static string TAEngine_INDICATOR_PVT;
            const static string TAEngine_INDICATOR_MASD;
            const static string TAEngine_INDICATOR_VA;
            const static string TAEngine_INDICATOR_DMI;
            const static string TAEngine_INDICATOR_VF;
            const static string TAEngine_INDICATOR_VS;
            const static string TAEngine_INDICATOR_AMA;
            const static string TAEngine_INDICATOR_SWING;
            const static string TAEngine_INDICATOR_ASWING;
            const static string TAEngine_INDICATOR_AVGDEV;
            const static string TAEngine_INDICATOR_BOMP;
            const static string TAEngine_INDICATOR_CMO;
            const static string TAEngine_INDICATOR_KELTNER;
            const static string TAEngine_INDICATOR_WWMA;
            const static string TAEngine_INDICATOR_VWMA;
            const static string TAEngine_INDICATOR_VMA;
            const static string TAEngine_INDICATOR_SWMA;
            const static string TAEngine_INDICATOR_RSQUARE;
            const static string TAEngine_INDICATOR_QSTICK;
            const static string TAEngine_INDICATOR_MAENV;
            const static string TAEngine_INDICATOR_MAOSC;
            const static string TAEngine_INDICATOR_HARMONIC;
            const static string TAEngine_INDICATOR_PFE;
            const static string TAEngine_INDICATOR_VOMA;
            const static string TAEngine_INDICATOR_STOCHRSI;
            const static string TAEngine_INDICATOR_SMA_ENVELOPE;
            const static string TAEngine_INDICATOR_EMA_ENVELOPE;
            const static string TAEngine_INDICATOR_TRIMA_ENVELOPE;
            const static string TAEngine_INDICATOR_VMA_ENVELOPE;
            const static string TAEngine_INDICATOR_WMA_ENVELOPE;
            const static string TAEngine_INDICATOR_TYPPRICE_ENVELOPE;
            const static string TAEngine_INDICATOR_AMA_ENVELOPE;
            const static string TAEngine_INDICATOR_WWMA_ENVELOPE;
            const static string TAEngine_INDICATOR_OVERBOUGHT_OVERSOLD;
            const static string TAEngine_INDICATOR_VOLUME_RATIO;
            const static string TAEngine_INDICATOR_PRICE_CHANNEL;
            const static string TAEngine_INDICATOR_HISTORIC_VOLATILITY;
            const static string TAEngine_INDICATOR_PIVOT_POINT;
            const static string TAEngine_INDICATOR_TSI;
            const static string TAEngine_INDICATOR_BUYP;
            const static string TAEngine_INDICATOR_GANN_HI_LO_ACTIVATOR;
            const static string TAEngine_INDICATOR_VEMA;
            const static string TAEngine_INDICATOR_VSMA;
            const static string TAEngine_INDICATOR_WALLIGATOR;
            const static string TAEngine_INDICATOR_AC;
            const static string TAEngine_INDICATOR_HA;
            const static string TAEngine_INDICATOR_ICH;
            const static string TAEngine_INDICATOR_VIDYA;
            const static string TAEngine_INDICATOR_EWO;
            const static string TAEngine_INDICATOR_MD;
            const static string TAEngine_INDICATOR_GATOR;
            const static string TAEngine_INDICATOR_LREG;
            const static string TAEngine_INDICATOR_KRI;
            const static string TAEngine_INDICATOR_ASI;
            const static string TAEngine_INDICATOR_WFRACTAL;
            const static string TAEngine_INDICATOR_RCI;	
            const static string TAEngine_INDICATOR_STARCBAND;
            const static string TAEngine_INDICATOR_VHF;
            const static string TAEngine_INDICATOR_SMMA_ENVELOPE;
            const static string TAEngine_INDICATOR_SROC;
            const static string TAEngine_INDICATOR_VWAP;
            const static string TAEngine_INDICATOR_WAD;
            const static string TAEngine_INDICATOR_COG;
            const static string TAEngine_INDICATOR_STDDEV_EB;
            const static string TAEngine_INDICATOR_DYNAMIC_MI;
            const static string TAEngine_INDICATOR_WWSMA;	
            const static string TAEngine_INDICATOR_ZIGZAG;
            const static string TAEngine_INDICATOR_STC;
            const static string TAEngine_INDICATOR_PCR;
            const static string TAEngine_INDICATOR_CSI;
            const static string TAEngine_INDICATOR_MACD_HIST;

            void inertia(  double *dHighPrice, double *dLowPrice,double *dOpenPrice,
                    double *dClosePrice ,size_t inputLength,map<string, vector<double> > & output, 
                    int maPeriod1, int maPeriod2 ,int maPeriod3);

            void keltner_channel(double *dHighPrice, double *dLowPrice,
                    double *dClosePrice, size_t inputLength, int maPeriod,
                    map<string, vector<double> > & output);
            void psar(double *dHighPrice, double *dLowPrice, size_t inputLength,
                    map<string, vector<double> > & output, double dStep = TA_REAL_DEFAULT,
                    double dMax = TA_REAL_DEFAULT);
            void macd(double *dClosePrice, size_t inputLength, int iFastPeriod,
                    int iSlowPeriod, int iSignalPeriod, map<string, vector<double> > & output);
            void macd_hist(double *dClosePrice, size_t inputLength, int iFastPeriod,
                    int iSlowPeriod, int iSignalPeriod, map<string, vector<double> > & output);
            void tri_macd(double *dClosePrice, size_t inputLength, int iFastPeriod,
                    int iSlowPeriod, map<string, vector<double> > & output);
            void typrice(double *dHighPrice, double *dLowPrice, double *dClosePrice,
                    size_t inputLength, map<string, vector<double> > & output);
            void wclprice(double *dHighPrice, double *dLowPrice, double *dClosePrice,
                    size_t inputLength, map<string, vector<double> > & output);
            void avgprice(double *dOpenPrice, double *dHighPrice, double *dLowPrice,
                    double *dClosePrice, size_t inputLength,
                    map<string, vector<double> > & output);
            void median_price(double *dHighPrice, double *dLowPrice, size_t inputLength,
                    map<string, vector<double> > & output);
            void obv(double *dClosePrice, uint32_t *lVolume, size_t inputLength,
                    map<string, vector<double> > & output);
            void money_flow_index(double *dHighPrice, double *dLowPrice,
                    double *dClosePrice, uint32_t *lVolume, size_t inputLength, int maPeriod,
                    map<string, vector<double> > & output);
            bool volume_ma(uint32_t iIndicatorType, uint32_t *lVolume, size_t inputLength,
                    int maPeriod, map<string, vector<double> > & output);
            void william_r(double *dHighPrice, double *dLowPrice, double *dClosePrice,
                    size_t inputLength, int maPeriod, map<string, vector<double> > & output);
            void cci(double *dHighPrice, double *dLowPrice, double *dClosePrice,
                    size_t inputLength, int maPeriod, map<string, vector<double> > & output);
            void atr(double *dHighPrice, double *dLowPrice, double *dClosePrice,
                    size_t inputLength, int maPeriod, map<string, vector<double> > & output);
            void bbands(double *dClosePrice, size_t inputLength, int maPeriod,
                    map<string, vector<double> > & output, double dStndDeviation = 2.0 );
            void ultimate_osc(double *dHighPrice, double *dLowPrice, double *dClosePrice,
                    size_t inputLength, int maPeriod1, int maPeriod2, int maPeriod3,
                    map<string, vector<double> > & output);
            void donchian_channel(double *dHighPrice, double *dLowPrice,
                    size_t inputLength, int maPeriod, 	map<string, vector<double> > & output);
            void fast_stochastic(double *dHighPrice, double *dLowPrice,
                    double *dClosePrice, size_t inputLength, int maFastKPeriod, int maFastDPeriod,
                    map<string, vector<double> > & output);
            void slow_stochastic(double *dHighPrice, double *dLowPrice,
                    double *dClosePrice, size_t inputLength, int maFastKPeriod, int maSlowKPeriod,
                    int maSlowDPeriod, map<string, vector<double> > & output);
            void stochastic_rsi(double *dClosePrice, size_t inputLength, int maPeriod,
                    int maFastKPeriod, int maFastDPeriod, map<string, vector<double> > & output);
            void avg_directional_movt(double *dHighPrice, double *dLowPrice,
                    double *dClosePrice, size_t inputLength, int maPeriod,
                    map<string, vector<double> > & output);
            void accumulation_distribution_index(double *dHighPrice, double *dLowPrice,
                    double *dClosePrice, uint32_t *lVolume, size_t inputLength,
                    map<string, vector <double> > & output);
            void ad_osc(double *dHighPrice, double *dLowPrice, double *dClosePrice,
                    uint32_t *lVolume, size_t inputLength, int maPeriod1, int maPeriod2,
                    map<string, vector<double> > & output);
            void aroon(double *dHighPrice, double *dLowPrice, size_t inputLength,
                    int maPeriod, map<string, vector<double> > & output);
            void aroonosc(double *dHighPrice, double *dLowPrice, size_t inputLength,
                    int maPeriod, map<string, vector<double> > & output);

            void forecast_oscillator(double *dClosePrice, size_t inputLength,int maPeriod, map<string, vector<double> > & output);

            void elder_ray(uint32_t iIndicatorType , double *dClosePrice, double *dHighPrice, double *dLowPrice,size_t inputLength,int maPeriod, map<string, vector<double> > & output);   

            void ao(double *dHighPrice, double *dLowPrice, size_t inputLength,
                    int maPeriod1, int maPeriod2, map<string, vector<double> > & output);
            void chande_momentum_oscillator(double *dClosePrice, size_t inputLength,
                    int maPeriod,  map<string, vector<double> > & output);
            void smoothed_moving_average(double *dClosePrice, size_t inputLength,
                    int maPeriod,  map<string, vector<double> > & output);
            void variable_moving_average(double *dClosePrice, size_t inputLength,
                    int maPeriod,  map<string, vector<double> > & output);
            void envelope(string sEnvelopeName, map<string, vector<double> > input,
                    map<string, vector<double> > & output, double dEnvelopePercentage);

            void price_channel(double *dHighPrice, double *dLowPrice, size_t inputLength,
                    int maPeriod, map<string, vector<double> > & output);
            void stddev(double *dClosePrice, size_t inputLength, int maPeriod,
                    map<string, vector<double> > &output);
            void pivot_point(double *dHighPrice, double *dLowPrice, double *dClosePrice, size_t inputLength,
                    map<string, vector<double> > & output);
            void buying_pressure(double *dClosePrice, double *dLowPrice,
                    size_t inputLength, int maPeriod, map<string, vector<double> > & output);
            void gann_hi_lo_activator(double *dClosePrice, double *dHighPrice,
                    double *dLowPrice, size_t inputLength, int maPeriod,
                    map<string, vector<double> > & output);
            void volume_average(string sIndicatorName, uint32_t *lVolume,
                    size_t inputLength, int maPeriod, map<string, vector<double> > & output);
            void williams_alligator(double *dHighPrice, double *dLowPrice, size_t inputLength,
                    map<string, vector<double> > & output);
            void ac(double *dHighPrice, double *dLowPrice, size_t inputLength,
                    int maPeriod1, int maPeriod2, int maPeriod3,
                    map<string, vector<double> > & output);
            void ha(double *dOpenPrice, double *dHighPrice, double *dLowPrice,
                    double *dClosePrice, size_t inputLength,
                    map<string, vector<double> > & output);
            void ichimoku(double *dHighPrice, double *dLowPrice, double *dClosePrice,
                    size_t inputLength, int maPeriod1, int maPeriod2, int maPeriod3,
                    map<string, vector<double> > & output);
            void vidya(double *dClosePrice, size_t inputLength, int maPeriod,
                    map<string, vector<double> > & output);
            void ewo(double *dHighPrice, double *dLowPrice, size_t inputLength,
                    map<string, vector<double> > & output);
            void mcginley(double *dClosePrice, size_t inputLength, int maPeriod,
                    map<string, vector<double> > & output);
            void gator_osc(double *dHighPrice, double *dLowPrice, size_t inputLength,
                    map<string, vector<double> > & output);
            void osc(double *dClosePrice, size_t inputLength, int maPeriod1, int maPeriod2,
                    map<string, vector<double> > & output);
            void cho(double *dHighPrice, double *dLowPrice, double *dClosePrice,
                    uint32_t *lVolume, size_t inputLength, int maPeriod1, int maPeriod2,
                    map<string, vector<double> > & output);
            void cmf(double *dHighPrice, double *dLowPrice, double *dClosePrice,
                    uint32_t *lVolume, size_t inputLength, int maPeriod,
                    map<string, vector<double> > & output);
            void tsi(double *dClosePrice, size_t inputLength, int maPeriod1, int maPeriod2,
                    map<string, vector<double> > & output);
            void dmi(double *dHighPrice, double *dLowPrice, double *dClosePrice,
                    size_t inputLength, int maPeriod, map<string, vector<double> > & output);	
            void kairi(double *dClosePrice, size_t inputLength, int maPeriod,
                    map<string, vector<double> > & output);
            void asi(double *dOpenPrice, double *dHighPrice, double *dLowPrice,
                    double *dClosePrice, size_t inputLength, double dMaxPriceChange,
                    map<string, vector<double> > & output);
            void fractal(double *dHighPrice, double *dLowPrice, size_t inputLength,
                    map<string, vector<double> > & output);
            void adaptive_rsi(double *dClosePrice,size_t inputLength,
                    map<string, vector<double> > & output,int maPeriod);
            void stochastic_oscillator(double *dHighPrice,double *dLowPrice,
                    double *dClosePrice,size_t inputLength,map<string,vector<double> > & output,
                    int maPeriod,int maPeriod2,int maPeriod3);

            void rvi(double *dHighPrice,double *dLowPrice,double *dOpenPrice,
                    double *dClosePrice,size_t inputLength,map<string, vector<double> > & output,
                    int maPeriod1,int maPeriod2 );
            void market_facilitation_index(double *dHighPrice,double *dLowPrice,
                    uint32_t *volume,size_t inputLength,map<string, vector<double> > & output);
            bool force_index(double *dInputPrices,uint32_t *volume,size_t inputLength,
                    map<string, vector<double> > & output,int  maPeriod);
            bool dem(uint32_t iIndicatorType, double *dHighPrices,double *dLowPrice,
                    size_t inputLength, map<string, vector<double> > & output, int maPeriod);
            void find_DeMax_DeMin(double *dHighPrices,double *dLowPrice,double *DeMax,
                    double *DeMin,size_t inp_len);
            bool bulls_power(uint32_t iIndicatorType, double *dInputPrices,
                    double *dHighprice , size_t inputLength, map<string, vector<double> > & output,
                    int maPeriod);
            bool  bears_power(uint32_t iIndicatorType, double *dInputPrices,
                    double *dLowprice , size_t inputLength, map<string, vector<double> > & output,
                    int maPeriod);


            void high_low(double *dHighPrice, double *dLowPrice,size_t inputLength, int maPeriod,map<string, vector<double> > & output);
            void intraday_momentum( double *dClosePrice,double *dOpenPrice,size_t inputLength,
                    int maPeriod,map<string, vector<double> > & output);
            void cvi(double *dHighPrice, double *dLowPrice, size_t inputLength, int maPeriod, int maPeriod2, map<string, vector<double> > &output);
            void dpo(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > &output);
            void avg_directional_movt_index_rating(double *dHighPrice, double *dLowPrice, double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output);
            void swing_index(double *dHighPrice, double *dLowPrice,double *dClosePrice,double *dOpenPrice, size_t inputLength, int maPeriod,map<string, vector<double> > & output);
            double maxRforSI(double *dHighPrice, double *dLowPrice,double *dOpenPrice,double *dClosePrice,int i);
            void accumulated_swing_index(double *dHighPrice, double *dLowPrice,double *dClosePrice,double *dOpenPrice,     size_t inputLength, int maPeriod,map<string, vector<double> > & output);

            void ppo(double *dClosePrice, size_t inputLength, int maPeriod1, int maPeriod2, map<string, vector<double> > & output);

            void apo(double *dClosePrice, size_t inputLength, int maPeriod1, int maPeriod2, map<string, vector<double> > & output);

            void lregCurve(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output);
            void lregAngle(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output);
            void lregIntercept(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output);
            void lregSlope(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output);

            void dx(double *dHighPrice, double *dLowPrice, double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output);
            void rocp(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output);
            void rocv(uint32_t *volume, size_t inputLength, int maPeriod, map<string, vector<double> >&output);
            void rocr(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output);
            void rocr100(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output);

            void rci(double *dClosePrice, time_t *timeList, size_t inputLength, int maPeriod, map<string, vector<double> > & output);
            void rci_makeRanks(RCI_NODE *old, RCI_NODE *_new, int len);
            double calculate_rci(RCI_NODE *p, RCI_NODE *q, int dur);
            void mass_index(double *dHighPrice, double *dLowPrice, size_t inputLength, int maPeriod1, 
                    int maPeriod2, map<string, vector<double> > & output);
            void nvi(double *dClosePrice, uint32_t *volume, size_t inputLength, map<string, vector<double> > & output);
            void starc_band(double *dClosePrice, double *dHighPrice, double *dLowPrice, size_t inputLength, int maPeriod1, 
                    int maPeriod2, double dK, map<string, vector<double> > & output);
            void vhf(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output);
            void time_series_forecast(double *dClosePrice, size_t inputLength, int maPeriod,
                    map<string, vector<double> > & output);
            void sroc(double *dClosePrice, size_t inputLength, int maPeriod1, int maPeriod2, map<string, vector<double> > & output);
            void vwap(double *dHighPrice, double *dLowPrice, double *dClosePrice,
                    uint32_t *volume, size_t inputLength, map<string, vector<double> > & output);
            void wad(double *dHighPrice, double *dLowPrice, double *dClosePrice, size_t inputLength, map<string, vector<double> > & output);
            void cog(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output);
            void stddev_error_bands(double *dClosePrice, size_t inputLength, int maPeriod1, int maPeriod2, map<string, vector<double> > & output);
            void dynamic_mi(double *dClosePrice, size_t inputLength, int maPeriod1, int maPeriod2, int maPeriod3, 
                    map<string, vector<double> > & output);
            void wilders_smoothing(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output);
            void zigzag(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output);
            void schaff_trend_cycle(double *dClosePrice, size_t inputLength, int maPeriod1, int maPeriod2, int maPeriod3,
                    map<string, vector<double> > & output);
            void pcr(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output);
            void lreg(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output);
            void csi(double *dHighPrice, double *dLowPrice, double *dClosePrice, size_t inputLength, 
                    int maPeriod, map<string, vector<double> > & output);
            void htdcperiod(double *dClosePrice, size_t inputLength, map<string, vector<double> > &output);
            void htdcphase(double *dClosePrice, size_t inputLength, map<string, vector<double> > &output);
            void httrendmode(double *dCLosePrice, size_t inputLength, map<string, vector<double> > &output);
            void httrendline(double *dClosePrice, size_t inputLength, map<string, vector<double> > &output);
            void htsine(double *dClosePrice, size_t inputLength, map<string, vector<double> > &output);
            void htphasor(double *dClosePrice, size_t inputLength, map<string, vector<double> > &output);
            void midprice(double *dHighPrice, double *dLowPrice, size_t inputLength, int maPeriod, map<string, vector<double> > &output);
            void midpoint(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > &output);
            void trange(double *dClosePrice, double *dHighPrice, double *dLowPice, size_t inputLength, map<string, vector<double> > &output);
            void pfe(double *dClosePrice, size_t inputLength, int maPeriod, int maPeriod2, map<string, vector<double> > &output);
            void variance(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > &output);
            void tsf(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > &output);
            void mama(double *dClosePrice, size_t inputLength, map<string, vector<double> > & output);
            void fama(double *dClosePrice, size_t inputLength, map<string, vector<double> > & output);
            void minusdi(double *dHighPrice, double *dLowPrice, double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output);
            void plusdi(double *dHighPrice, double *dLowPrice, double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output);
            void minusdm(double *dHighPrice, double *dLowPrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output);
            void plusdm(double *dHighPrice, double *dLowPrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output);
            void natr(double *dHighPrice, double *dLowPrice, double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output);
            void harmonic(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output);
            void clv(double *dHighPrice, double *dLowPrice, double *dClosePrice, size_t inputLength, map<string, vector<double> > & output);
            void qstick(double *dClosePrice, double *dOpenPrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output);
            void pvt(double *dClosePrice, uint32_t *volume, size_t inputLength, map<string, vector<double> > & output);
            void bomp(double *dClosePrice, double *dOpenPrice, double *dHighPrice, double *dLowPrice, size_t inputLength, map<string, vector<double> > & output);
            void va(double *dClosePrice, double *HighPrice, double *dLowPrice, uint32_t *volume, size_t inputLength, map<string, vector<double> > & output);
            void pvi(double *dClosePrice, uint32_t *volume, size_t inputLength, map<string, vector<double> > & output);
            void masd(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > &output);
            void maosc(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > &output);
            void pi(double *dClosePrice, size_t inputLength, map<string, vector<double> > &output);
            void avgdev(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > &output);
            void slope(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > &output);
            void rsquare(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > &output);





    };
}


#endif /* __TA_ENGINE_H__ */
