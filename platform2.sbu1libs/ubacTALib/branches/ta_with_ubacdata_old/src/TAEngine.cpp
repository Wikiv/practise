#include "TAEngine.h"

const string TAEngine::TAEngine_INDICATOR_BEARS = "BEARS";
const string TAEngine::TAEngine_INDICATOR_BULLR = "BULLR";
const string TAEngine::TAEngine_INDICATOR_DEM = "DEM";
const string TAEngine::TAEngine_INDICATOR_FORCE = "FORCE";
const string TAEngine::TAEngine_INDICATOR_BWMFI = "BWMFI";
const string TAEngine::TAEngine_INDICATOR_RVI = "RVI";
const string TAEngine::TAEngine_INDICATOR_ARSI = "ARSI";
const string TAEngine::TAEngine_INDICATOR_STO = "STO";
const string TAEngine::TAEngine_INDICATOR_SMA = "SMA";
const string TAEngine::TAEngine_INDICATOR_EMA = "EMA";
const string TAEngine::TAEngine_INDICATOR_SMMA = "SMMA";
const string TAEngine::TAEngine_INDICATOR_TRIMA = "TRIMA";
const string TAEngine::TAEngine_INDICATOR_TEMA = "TEMA";
const string TAEngine::TAEngine_INDICATOR_T3 = "T3";
const string TAEngine::TAEngine_INDICATOR_DEMA = "DEMA";
const string TAEngine::TAEngine_INDICATOR_WMA = "WMA";
const string TAEngine::TAEngine_INDICATOR_PSAR = "PSAR";
const string TAEngine::TAEngine_INDICATOR_MACD = "MACD";
const string TAEngine::TAEngine_INDICATOR_TMACD = "TMACD";
const string TAEngine::TAEngine_INDICATOR_ROC = "ROC";
const string TAEngine::TAEngine_INDICATOR_ROCP = "ROCP";
const string TAEngine::TAEngine_INDICATOR_ROCR = "ROCR";
const string TAEngine::TAEngine_INDICATOR_ROCR100 = "ROCR100";
const string TAEngine::TAEngine_INDICATOR_MFI = "MFI";
const string TAEngine::TAEngine_INDICATOR_DX = "DX";
const string TAEngine::TAEngine_INDICATOR_FSTOCH = "FSTOCH";
const string TAEngine::TAEngine_INDICATOR_SSTOCH = "SSTOCH";
const string TAEngine::TAEngine_INDICATOR_WILLR = "WILLR";
const string TAEngine::TAEngine_INDICATOR_AD = "AD";
const string TAEngine::TAEngine_INDICATOR_ADOSC = "ADOSC";
const string TAEngine::TAEngine_INDICATOR_AROON = "AROON";
const string TAEngine::TAEngine_INDICATOR_AO = "AO";
const string TAEngine::TAEngine_INDICATOR_OSC = "OSC";
const string TAEngine::TAEngine_INDICATOR_CHO = "CHO";
const string TAEngine::TAEngine_INDICATOR_AROONOSC = "AROONOSC";
const string TAEngine::TAEngine_INDICATOR_ADX = "ADX";
const string TAEngine::TAEngine_INDICATOR_ADXR = "ADXR";
const string TAEngine::TAEngine_INDICATOR_ATR = "ATR";
const string TAEngine::TAEngine_INDICATOR_BBANDS = "BBANDS";
const string TAEngine::TAEngine_INDICATOR_CCI = "CCI";
const string TAEngine::TAEngine_INDICATOR_MOM = "MOM";
const string TAEngine::TAEngine_INDICATOR_OBV = "OBV";
const string TAEngine::TAEngine_INDICATOR_PPO = "PPO";
const string TAEngine::TAEngine_INDICATOR_APO = "APO";
const string TAEngine::TAEngine_INDICATOR_TRIX = "TRIX";
const string TAEngine::TAEngine_INDICATOR_ULTOSC = "ULTOSC";
const string TAEngine::TAEngine_INDICATOR_RSI = "RSI";
const string TAEngine::TAEngine_INDICATOR_STDDEV = "STDDEV";
const string TAEngine::TAEngine_INDICATOR_AVGPRICE = "AVGPRICE";
const string TAEngine::TAEngine_INDICATOR_BETA = "BETA";
const string TAEngine::TAEngine_INDICATOR_CORREL = "CORREL";
const string TAEngine::TAEngine_INDICATOR_FAMA = "FAMA";
const string TAEngine::TAEngine_INDICATOR_MAMA = "MAMA";
const string TAEngine::TAEngine_INDICATOR_HTDCPERIOD = "HTDCPERIOD";
const string TAEngine::TAEngine_INDICATOR_HTDCPHASE = "HTDCPHASE";
const string TAEngine::TAEngine_INDICATOR_HTTRENDMODE = "HTTRENDMODE";
const string TAEngine::TAEngine_INDICATOR_HTTRENDLINE = "HTTRENDLINE";
const string TAEngine::TAEngine_INDICATOR_HTSINE = "HTSINE";
const string TAEngine::TAEngine_INDICATOR_HTPHASOR = "HTPHASOR";
const string TAEngine::TAEngine_INDICATOR_KAMA = "KAMA";
const string TAEngine::TAEngine_INDICATOR_LREG = "LREG";
const string TAEngine::TAEngine_INDICATOR_LREGANGLE = "LREGANGLE";
const string TAEngine::TAEngine_INDICATOR_LREGINTERCEPT = "LREGINTERCEPT";
const string TAEngine::TAEngine_INDICATOR_LREGSLOPE = "LREGSLOPE";
const string TAEngine::TAEngine_INDICATOR_MEDPRICE = "MEDPRICE";
const string TAEngine::TAEngine_INDICATOR_MIDPOINT = "MIDPOINT";
const string TAEngine::TAEngine_INDICATOR_MIDPRICE = "MIDPRICE";
const string TAEngine::TAEngine_INDICATOR_MINUSDI = "MINUSDI";
const string TAEngine::TAEngine_INDICATOR_PLUSDI = "PLUSDI";
const string TAEngine::TAEngine_INDICATOR_MINUSDM = "MINUSDM";
const string TAEngine::TAEngine_INDICATOR_PLUSDM = "PLUSDM";
const string TAEngine::TAEngine_INDICATOR_NATR = "NATR";
const string TAEngine::TAEngine_INDICATOR_TRANGE = "TRANGE";
const string TAEngine::TAEngine_INDICATOR_TSF = "TSF";
const string TAEngine::TAEngine_INDICATOR_TYPPRICE = "TYPPRICE";
const string TAEngine::TAEngine_INDICATOR_TYPPRICE_MA = "TYPPRICE_MA";
const string TAEngine::TAEngine_INDICATOR_VARIANCE = "VARIANCE";
const string TAEngine::TAEngine_INDICATOR_WCLPRICE = "WCLPRICE";
const string TAEngine::TAEngine_INDICATOR_FI = "FI";
const string TAEngine::TAEngine_INDICATOR_SLOPE = "SLOPE";
const string TAEngine::TAEngine_INDICATOR_CLV = "CLV";
const string TAEngine::TAEngine_INDICATOR_CMF = "CMF";
const string TAEngine::TAEngine_INDICATOR_DPO = "DPO";
const string TAEngine::TAEngine_INDICATOR_EOM = "EOM";
const string TAEngine::TAEngine_INDICATOR_DOC = "DOC";
const string TAEngine::TAEngine_INDICATOR_CVI = "CVI";
const string TAEngine::TAEngine_INDICATOR_MI = "MI";
const string TAEngine::TAEngine_INDICATOR_NVI = "NVI";
const string TAEngine::TAEngine_INDICATOR_PI = "PI";
const string TAEngine::TAEngine_INDICATOR_PVI = "PVI";
const string TAEngine::TAEngine_INDICATOR_PVO = "PVO";
const string TAEngine::TAEngine_INDICATOR_PVT = "PVT";
const string TAEngine::TAEngine_INDICATOR_MASD = "MASD";
const string TAEngine::TAEngine_INDICATOR_VA = "VA";
const string TAEngine::TAEngine_INDICATOR_DMI = "DMI";
const string TAEngine::TAEngine_INDICATOR_VF = "VF";
const string TAEngine::TAEngine_INDICATOR_VS = "VS";
const string TAEngine::TAEngine_INDICATOR_AMA = "AMA";
const string TAEngine::TAEngine_INDICATOR_SWING = "SWING";
const string TAEngine::TAEngine_INDICATOR_ASWING = "ASWING";
const string TAEngine::TAEngine_INDICATOR_AVGDEV = "AVGDEV";
const string TAEngine::TAEngine_INDICATOR_BOMP = "BOMP";
const string TAEngine::TAEngine_INDICATOR_CMO = "CMO";
const string TAEngine::TAEngine_INDICATOR_KELTNER = "KELTNER";
const string TAEngine::TAEngine_INDICATOR_WWMA = "WWMA";
const string TAEngine::TAEngine_INDICATOR_VWMA = "VWMA";
const string TAEngine::TAEngine_INDICATOR_VMA = "VMA";
const string TAEngine::TAEngine_INDICATOR_SWMA = "SWMA";
const string TAEngine::TAEngine_INDICATOR_RSQUARE = "RSQUARE";
const string TAEngine::TAEngine_INDICATOR_QSTICK = "QSTICK";
const string TAEngine::TAEngine_INDICATOR_MAENV = "MAENV";
const string TAEngine::TAEngine_INDICATOR_MAOSC = "MAOSC";
const string TAEngine::TAEngine_INDICATOR_HARMONIC = "HARMONIC";
const string TAEngine::TAEngine_INDICATOR_PFE = "PFE";
const string TAEngine::TAEngine_INDICATOR_VOMA = "VOMA";
const string TAEngine::TAEngine_INDICATOR_STOCHRSI = "STOCHRSI";
const string TAEngine::TAEngine_INDICATOR_SMA_ENVELOPE = "SMAENV";
const string TAEngine::TAEngine_INDICATOR_EMA_ENVELOPE = "EMAENV";
const string TAEngine::TAEngine_INDICATOR_TRIMA_ENVELOPE = "TRIMAENV";
const string TAEngine::TAEngine_INDICATOR_VMA_ENVELOPE = "VMAENV";
const string TAEngine::TAEngine_INDICATOR_WMA_ENVELOPE = "WMAENV";
const string TAEngine::TAEngine_INDICATOR_TYPPRICE_ENVELOPE = "TYPPRICEENV";
const string TAEngine::TAEngine_INDICATOR_AMA_ENVELOPE = "AMAENV";
const string TAEngine::TAEngine_INDICATOR_WWMA_ENVELOPE = "WWMAENV";
const string TAEngine::TAEngine_INDICATOR_OVERBOUGHT_OVERSOLD = "OBOS";
const string TAEngine::TAEngine_INDICATOR_VOLUME_RATIO = "VOLUME_RATIO";
const string TAEngine::TAEngine_INDICATOR_PRICE_CHANNEL = "PRICE_CHANNEL";
const string TAEngine::TAEngine_INDICATOR_HISTORIC_VOLATILITY = "HISTORIC_VOLATILITY";
const string TAEngine::TAEngine_INDICATOR_PIVOT_POINT = "PIVOT_POINT";
const string TAEngine::TAEngine_INDICATOR_TSI = "TSI";
const string TAEngine::TAEngine_INDICATOR_BUYP = "BUYP";
const string TAEngine::TAEngine_INDICATOR_GANN_HI_LO_ACTIVATOR = "GANN_HI_LO";
const string TAEngine::TAEngine_INDICATOR_VEMA = "VEMA";
const string TAEngine::TAEngine_INDICATOR_VSMA = "VSMA";
const string TAEngine::TAEngine_INDICATOR_ALLIGATOR = "ALLIGATOR";
const string TAEngine::TAEngine_INDICATOR_AC = "AC";
const string TAEngine::TAEngine_INDICATOR_HA = "HA";
const string TAEngine::TAEngine_INDICATOR_ICH = "ICH";
const string TAEngine::TAEngine_INDICATOR_VIDYA = "VIDYA";
const string TAEngine::TAEngine_INDICATOR_EWO = "EWO";
const string TAEngine::TAEngine_INDICATOR_MD = "MD";
const string TAEngine::TAEngine_INDICATOR_GATOR = "GATOR";
const string TAEngine::TAEngine_INDICATOR_LINEARREG = "LINEARREG";
const string TAEngine::TAEngine_INDICATOR_KRI = "KRI";
const string TAEngine::TAEngine_INDICATOR_ASI = "ASI";
const string TAEngine::TAEngine_INDICATOR_FRACTAL = "FRACTAL";

TAEngine::TAEngine()
{   	
    
        
        indicator_map.insert(make_pair(TAEngine_INDICATOR_SMA,(int)TAEngine_SMA));
	indicator_map.insert(make_pair(TAEngine_INDICATOR_EMA,(int)TAEngine_EMA));
	indicator_map.insert(make_pair(TAEngine_INDICATOR_SMMA,(int)TAEngine_SMMA));
	indicator_map.insert(make_pair(TAEngine_INDICATOR_TRIMA,(int)TAEngine_TRIMA));
	indicator_map.insert(make_pair(TAEngine_INDICATOR_TEMA,(int)TAEngine_TRIPLE_EMA));
	indicator_map.insert(make_pair(TAEngine_INDICATOR_T3,(int)TAEngine_T3));
	indicator_map.insert(make_pair(TAEngine_INDICATOR_DEMA,(int)TAEngine_DOUBLE_EMA));
	indicator_map.insert(make_pair(TAEngine_INDICATOR_WMA,(int)TAEngine_WMA));
	indicator_map.insert(make_pair(TAEngine_INDICATOR_PSAR,(int)TAEngine_PSAR));
	indicator_map.insert(make_pair(TAEngine_INDICATOR_MACD,(int)TAEngine_MACD));
	indicator_map.insert(make_pair(TAEngine_INDICATOR_TMACD,(int)TAEngine_TMACD));
	indicator_map.insert(make_pair(TAEngine_INDICATOR_ROC,(int)TAEngine_ROC));	
	indicator_map.insert(make_pair(TAEngine_INDICATOR_MOM,(int)TAEngine_MOM));	
	indicator_map.insert(make_pair(TAEngine_INDICATOR_TRIX,(int)TAEngine_TRIX));
	indicator_map.insert(make_pair(TAEngine_INDICATOR_RSI,(int)TAEngine_RSI));
	indicator_map.insert(make_pair(TAEngine_INDICATOR_KAMA,(int)TAEngine_KAMA));
	indicator_map.insert(make_pair(TAEngine_INDICATOR_WWMA,(int)TAEngine_WILDER_MA));
	indicator_map.insert(make_pair(TAEngine_INDICATOR_SWMA,(int)TAEngine_SINE_MA));
	indicator_map.insert(make_pair(TAEngine_INDICATOR_SMA_ENVELOPE, (int)TAEngine_SMA));
	indicator_map.insert(make_pair(TAEngine_INDICATOR_EMA_ENVELOPE, (int)TAEngine_EMA));
	indicator_map.insert(make_pair(TAEngine_INDICATOR_TRIMA_ENVELOPE, (int)TAEngine_TRIMA));
	indicator_map.insert(make_pair(TAEngine_INDICATOR_WWMA_ENVELOPE, (int)TAEngine_WILDER_MA));
	indicator_map.insert(make_pair(TAEngine_INDICATOR_WMA_ENVELOPE, (int)TAEngine_WMA));
	
        
        supportedIndicators.set(TAEngine_INDICATOR_RVI,"RVI|Relative Vigor Index|time period1,time Period2|outline,outline");
        supportedIndicators.set(TAEngine_INDICATOR_BWMFI,"BWMFI|Market Facilitation Index|none|outline");
	supportedIndicators.set(TAEngine_INDICATOR_FORCE,"FORCE|Force Index|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_DEM,"DEM|DeMarker|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_BULLR,"BULLR|Bulls Power|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_BEARS, "BEARS|Bears Power|time period|outline");
  
	supportedIndicators.set(TAEngine_INDICATOR_ARSI,"ARSI|Adaptive Relative Strength Index|time period|inline");
        supportedIndicators.set(TAEngine_INDICATOR_STO,"STO|Stochastic Oscillator|time period 1,time period 2,time period 3|outline,outline");
	supportedIndicators.set(TAEngine_INDICATOR_SMA, "SMA|Simple Moving Average|time period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_EMA, "EMA|Exponential Moving Average|time period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_SMMA, "SMMA|Smoothed Moving Average|time period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_TRIMA, "TRIMA|Triangular Moving Average|time period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_TEMA, "TEMA|Triple Exponential Moving Average|time period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_T3, "T3|Triple EMA|time period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_DEMA, "DEMA|Double EMA|time period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_WMA, "WMA|Weighted Moving Average|time period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_PSAR, "PSAR|Parabolic SAR|none|inline");
	supportedIndicators.set(TAEngine_INDICATOR_MACD, "MACD|Moving Average Convergence Divergence|fast time period, slow time period, signal time period|outline, outline, outline");
	supportedIndicators.set(TAEngine_INDICATOR_TMACD, "TMACD|Triangular Moving Average Convergence Divergence|fast time period, slow time period|outline, outline");
	supportedIndicators.set(TAEngine_INDICATOR_ROC, "ROC|Rate of Change - Percentage|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_ROCP, "ROCP|Rate of Change|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_ROCR, "ROCR|Rage of Change - Ratio|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_ROCR100, "ROCR100|Rate of Change = Ratio Percentage|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_MFI, "MFI|Money Flow Index|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_DX, "DX|Directional Movement Index|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_FSTOCH, "FSTOCH|Fast Stochastics|fast K period, fast D period|outline, outline");
	supportedIndicators.set(TAEngine_INDICATOR_SSTOCH, "SSTOCH|Slow Stochastics|fast K period, slow K period, slow D period|outline, outline");
	supportedIndicators.set(TAEngine_INDICATOR_WILLR, "WILLR|William's %R|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_AD, "AD|Accumulation/Distribution Line|none|outline");
	supportedIndicators.set(TAEngine_INDICATOR_ADOSC, "ADOSC|Accumulation/Distribution Oscillator|fast time period, slow time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_AROON, "AROON|Aroon|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_AO, "AO|Awesome Oscillator|none|outline");
	supportedIndicators.set(TAEngine_INDICATOR_OSC, "OSC|OSC Oscillator|short time period, long time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_AROONOSC, "AROONOSC|Aroon Oscillator|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_ADX, "ADX|Directional Movement - Average Index|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_ADXR, "ADXR|Directional Movement - Average Index Rating|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_ATR, "ATR|Average True Range|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_BBANDS, "BBANDS|Bollinger Bands|time period|inline, inline, inline");
	supportedIndicators.set(TAEngine_INDICATOR_CCI, "CCI|Commodity Channel Index|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_MOM, "MOM|Momentum|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_OBV, "OBV|On Balance Volume|none|outline");
	supportedIndicators.set(TAEngine_INDICATOR_PPO, "PPO|Price Oscillator - Percentage|fast time period, slow time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_APO, "APO|Price Oscillator - Absolute|fast time period, slow time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_TRIX, "TRIX|TRIX|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_ULTOSC, "ULTOSC|Ultimate Oscillator|time period 1,time period 2, time period 3|outline");
	supportedIndicators.set(TAEngine_INDICATOR_RSI, "RSI|Relative Strength Index|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_STDDEV, "STDDEV|Standard Deviation|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_AVGPRICE, "AVGPRICE|Average Price|none|inline");
	
	supportedIndicators.set(TAEngine_INDICATOR_BETA, "BETA|Beta Coefficient|symbol, time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_CORREL, "CORREL|Coefficient of Correlation|symbol, time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_FAMA, "FAMA|Following Adaptive Moving Average|none|outline");
	supportedIndicators.set(TAEngine_INDICATOR_MAMA, "MAMA|Mesa Adaptive Moving Average|none|outline");
	supportedIndicators.set(TAEngine_INDICATOR_HTDCPERIOD, "HTDCPERIOD|Hilbert Transform - Dominant Cycle Period|none|outline");
	supportedIndicators.set(TAEngine_INDICATOR_HTDCPHASE, "HTDCPHASE|Hilbert Transform - Dominant Cycle Phase|none|outline");
	supportedIndicators.set(TAEngine_INDICATOR_HTTRENDMODE, "HTTRENDMODE|Hilbert Transform - Market Mode|none|outline");
	supportedIndicators.set(TAEngine_INDICATOR_HTTRENDLINE, "HTTRENDLINE|Hilbert Transform - Instantaneous Trend Line|none|outline");
	supportedIndicators.set(TAEngine_INDICATOR_HTSINE, "HTSINE|Hilbert Transform - Sinewave Indicator|none|outline, outline");
	supportedIndicators.set(TAEngine_INDICATOR_HTPHASOR, "HTPHASOR|Hilbert Transform - In Phase Indicator|none|outline, outline");
	supportedIndicators.set(TAEngine_INDICATOR_KAMA, "KAMA|Kaufman's Adaptive Moving Average|time period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_LREG, "LREG|Linear Regression|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_LREGANGLE, "LREGANGLE|Linear Regression Angle|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_LREGINTERCEPT, "LREGINTERCEPT|Linear Regression Intercept|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_LREGSLOPE, "LREGSLOPE|Linear Regression Slope|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_MEDPRICE, "MEDPRICE|Median Price|none|inline");
	supportedIndicators.set(TAEngine_INDICATOR_MIDPOINT, "MIDPOINT|Midpoint|time period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_MIDPRICE, "MIDPRICE|Midprice|time period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_MINUSDI, "MINUSDI|Directional Indicator - Minus|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_PLUSDI, "PLUSDI|Directional Indicator - Plus|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_MINUSDM, "MINUSDM|Directional Movement - Minus|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_PLUSDM, "PLUSDM|Directional Movement - Plus|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_NATR, "NATR|Normalized Average True Range|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_TRANGE, "TRANGE|True Range|none|outline");
	supportedIndicators.set(TAEngine_INDICATOR_TSF, "TSF|Time Series Forecast|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_TYPPRICE, "TYPPRICE|Typical Price|none|outline");
	supportedIndicators.set(TAEngine_INDICATOR_TYPPRICE_MA, "TYPPRICE_MA|Typical Price Moving Average|none|outline");
	supportedIndicators.set(TAEngine_INDICATOR_VARIANCE, "VARIANCE|Variance|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_WCLPRICE, "WCLPRICE|Weighted Close|none|outline");
	supportedIndicators.set(TAEngine_INDICATOR_FI, "FI|Force Index|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_SLOPE, "SLOPE|Slope|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_CLV, "CLV|Close Location Value|none|outline");
	supportedIndicators.set(TAEngine_INDICATOR_CMF, "CMF|Chaikin Money Flow Indicator|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_DPO, "DPO|Detrended Price Oscillator|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_EOM, "EOM|Ease of Movement|none|outline");
	supportedIndicators.set(TAEngine_INDICATOR_DOC, "DOC|Donchian Channel|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_CVI, "CVI|Chaikin Volatility Indicator|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_MI, "MI|Mass Index|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_NVI, "NVI|Negative Volume Index|none|outline");
	supportedIndicators.set(TAEngine_INDICATOR_PI, "PI|Performance Indicator|none|outline");
	supportedIndicators.set(TAEngine_INDICATOR_PVI, "PVI|Positive Volume Index|none|outline");
	supportedIndicators.set(TAEngine_INDICATOR_PVO, "PVO|Percentage Volume Oscillator|fast time period, slow time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_PVT, "PVT|Price Volume Trend|none|outline");
	supportedIndicators.set(TAEngine_INDICATOR_MASD, "MASD|Moving Average Standard Deviation|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_VA, "VA|Volume Accumulation|none|outline");
	supportedIndicators.set(TAEngine_INDICATOR_DMI, "DMI|Directional Movement Index|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_VF, "VF|Volatility Fast|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_VS, "VS|Volatility Slow|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_AMA, "AMA|Adaptive Moving Average|time period, fast smoothing period, slow smoothing period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_SWING, "SWING|Swing Index|limit value|outline");
	supportedIndicators.set(TAEngine_INDICATOR_ASWING, "ASWING|Accumulation Swing Index|limit value|outline");
	supportedIndicators.set(TAEngine_INDICATOR_AVGDEV, "AVGDEV|Average Deviation|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_BOMP, "BOMP|Balance Of Market Power|none|outline");
	supportedIndicators.set(TAEngine_INDICATOR_CMO, "CMO|Chande Momentum Oscillator|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_KELTNER, "KELTNER|Keltner Channel|time period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_WWMA, "WWMA|Welles Wilder's Moving Average|time period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_VWMA, "VWMA|Volume-Weighted Moving Average|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_VMA, "VMA|Variable Moving Average|time period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_SWMA, "SWMA|Sine-Weighted Moving Average|time period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_RSQUARE, "RSQUARE|R Square|symbol, time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_QSTICK, "QSTICK|QStick|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_MAENV, "MAENV|Moving Average Envelope|time period|inline, inline");
	supportedIndicators.set(TAEngine_INDICATOR_MAOSC, "MAOSC|Moving Average Oscillator|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_HARMONIC, "HARMONIC|Harmonic Mean|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_PFE, "PFE|Polarize Fractal Efficiency|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_VOMA, "VOMA|Volume Moving Average|time period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_STOCHRSI, "STOCHRSI|Stochastic RSI|time period,Fast K-Period,Fast D-Period|outline, outline");
	supportedIndicators.set(TAEngine_INDICATOR_SMA_ENVELOPE, "SMAENV|Simple Moving Average Envelope|time period,envelope %|inline, inline, inline");
	supportedIndicators.set(TAEngine_INDICATOR_EMA_ENVELOPE, "EMAENV|Exponential Moving Average Envelope|time period,envelope %|inline, inline, inline");
	supportedIndicators.set(TAEngine_INDICATOR_TRIMA_ENVELOPE, "TRIMAENV|Triangular Moving Average Envelope|time period,envelope %|inline, inline, inline");
	supportedIndicators.set(TAEngine_INDICATOR_VMA_ENVELOPE, "VMAENV|Variable Moving Average Envelope|time period,envelope %|inline, inline, inline");
	supportedIndicators.set(TAEngine_INDICATOR_WMA_ENVELOPE, "WMAENV|Weighted Moving Average Envelope|time period,envelope %|inline, inline, inline");
	supportedIndicators.set(TAEngine_INDICATOR_TYPPRICE_ENVELOPE, "TYPPRICEENV|Typical Price Moving Average Envelope|time period,envelope %|inline, inline, inline");
	supportedIndicators.set(TAEngine_INDICATOR_AMA_ENVELOPE, "AMAENV|Adaptive Moving Average Envelope|time period,envelope %|inline, inline, inline");
	supportedIndicators.set(TAEngine_INDICATOR_WWMA_ENVELOPE, "WWMAENV|Welles Wilder's Moving Average Envelope|time period,envelope %|inline, inline, inline");
	supportedIndicators.set(TAEngine_INDICATOR_OVERBOUGHT_OVERSOLD, "OBOS|Overbought Oversold|time period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_VOLUME_RATIO, "VOLUME_RATIO|Volume Ratio|time period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_PRICE_CHANNEL, "PRICE_CHANNEL|Price Channel|time period|inline, inline");
	supportedIndicators.set(TAEngine_INDICATOR_HISTORIC_VOLATILITY, "HISTORIC_VOLATILITY|Historic Volatility|time period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_PIVOT_POINT, "PIVOT_POINT|Pivot Point|time period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_TSI, "TSI|True Strength Index|time period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_BUYP, "BUYP|Buying Pressure|time period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_GANN_HI_LO_ACTIVATOR, "GANN_HI_LO|Gann Hi-Lo Activator|time period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_VEMA, "VEMA|Volume EMA|time period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_VSMA, "VSMA|Volume SMA|time period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_ALLIGATOR, "ALLIGATOR|Alligator|none|inline");
	supportedIndicators.set(TAEngine_INDICATOR_AC, "AC|Acceleration Deceleration|none|outline");
	supportedIndicators.set(TAEngine_INDICATOR_HA, "HA|Heikin-Ashi|none|inline");
	supportedIndicators.set(TAEngine_INDICATOR_ICH, "ICH|Ichimoku Kinko Hyo|time period 1,time period 2,time period 3|inline");
	supportedIndicators.set(TAEngine_INDICATOR_VIDYA, "VIDYA|Variable Index Dynamic Average|ema_period,cmo_period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_EWO, "EWO|Elliot Wave Oscillator|none|outline");
	supportedIndicators.set(TAEngine_INDICATOR_MD, "MD|McGinley Dynamic Indicator|time period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_GATOR, "GATOR|Gator Oscillator|none|outline");
	supportedIndicators.set(TAEngine_INDICATOR_CHO, "CHO|Chaikin Oscillator|short time period, long time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_LINEARREG, "LINEARREG|Linear Regression|time period|inline");
	supportedIndicators.set(TAEngine_INDICATOR_KRI, "KRI|Kairi Relative Index|time period|outline");
	supportedIndicators.set(TAEngine_INDICATOR_ASI, "ASI|Accumulation Swing Index|maximum price change|outline");
	supportedIndicators.set(TAEngine_INDICATOR_FRACTAL, "FRACTAL|Fractal|none|inline");
}

size_t TAEngine::getNoOfPoints( TechnicalIndicatorValueRequest tivRequest, size_t points )
{
	multimap<string, string>indicatorsList = tivRequest.getIndicators();
	vector<string> indicators;
	IFHelper helper;
	for(multimap<string, string>::iterator iIndicator = indicatorsList.begin(); iIndicator != indicatorsList.end(); iIndicator++) {
		string sIndicatorParam = iIndicator->second;
		if(sIndicatorParam.length() > 0)
			helper.newsplit(sIndicatorParam, ",", indicators);
	}
	size_t Max = 0;
	if(indicators.size() > 0) {
		Max = atoi(indicators[0].c_str());
		for(size_t i = 1; i < indicators.size(); i++) {
			size_t element = atoi(indicators[i].c_str());
			if(element > Max)
				Max = element;
		}
	}
	cout << "max = " << Max << " ,points = " << points << endl;
	if( (points > 0) || (Max > 0) )
		return Max + points;
	else
		return 100;
}

void TAEngine::process(TechnicalIndicatorValueRequest tivRequest, HistoryDataResponse histDataResponse, TechnicalIndicatorValueResponse & tivResponse, bool flag, int precision)
{
	double *dClosePrice, *dOpenPrice, *dHighPrice, *dLowPrice;
	uint32_t *volume;
	size_t inputLength = 0;
	struct tm *timeList;
	IFHelper helper;

	vector<HistoryData>dataList = histDataResponse.getHistoryData();

	if( dataList.size() == 0 )
		return;

	vector<HistoryData>::iterator iDataList = dataList.begin();

	tivResponse.setSymbol( (*iDataList).getSymbol() );
	dClosePrice = (double *)calloc(1, sizeof(double)*dataList.size());
	dOpenPrice = (double *)calloc(1, sizeof(double)*dataList.size());
	dHighPrice = (double *)calloc(1, sizeof(double)*dataList.size());
	dLowPrice = (double *)calloc(1, sizeof(double)*dataList.size());
	volume = (uint32_t *)calloc(1, sizeof(uint32_t)*dataList.size());
	timeList = (struct tm *)calloc(1, sizeof(struct tm)*dataList.size());
	size_t i = 0;
	while( iDataList != dataList.end() ) {
		*(dClosePrice + i) = (*iDataList).getClose();
		*(dOpenPrice + i) = (*iDataList).getOpen();
		*(dHighPrice + i) = (*iDataList).getHigh();
		*(dLowPrice + i) = (*iDataList).getLow();
		*(volume + i) = (*iDataList).getVolume();
		struct tm tmpTime = (*iDataList).getTime();
		memcpy(timeList+i, &tmpTime, sizeof(struct tm));
		iDataList++;
		i++;
	}
	inputLength = i;

	multimap<string, string>indicatorsList = tivRequest.getIndicators();
	for(multimap<string, string>::iterator iIndicator = indicatorsList.begin(); iIndicator != indicatorsList.end(); iIndicator++) {
		string sIndicator = iIndicator->first;
		string sIndicatorParam = iIndicator->second;

		cout << "sIndicator = " << sIndicator << ", sIndicatorParam = " << sIndicatorParam << endl;

		map<string, vector<double> > output;

		cout << sIndicator << endl;
		if( !supportedIndicators.isCached( sIndicator ) ) {
			throw "Unsupported indicator.";
		}

		vector<string>indicatorParamsList;
		helper.newsplit(sIndicatorParam, ",", indicatorParamsList);

		int maPeriod=0, maPeriod1, maPeriod2=0, maPeriod3=0;
		if( indicatorParamsList.size() > 0 )
			maPeriod = maPeriod1 = atoi(indicatorParamsList[0].c_str());
		if( indicatorParamsList.size() > 1 )
			maPeriod2 = atoi( indicatorParamsList[1].c_str() );
		if( indicatorParamsList.size() > 2 )
			maPeriod3 = atoi( indicatorParamsList[2].c_str() );

		cout << "maPeriod = " << maPeriod << ", maPeriod2 = " << maPeriod2 << ", maPeriod3 = " << maPeriod3 << endl;
		
		if ((sIndicator == TAEngine_INDICATOR_SMA) || (sIndicator == TAEngine_INDICATOR_EMA) || (sIndicator == TAEngine_INDICATOR_TRIMA) || 
			(sIndicator == TAEngine_INDICATOR_TEMA) || (sIndicator == TAEngine_INDICATOR_T3) || (sIndicator == TAEngine_INDICATOR_WMA) ||
			(sIndicator == TAEngine_INDICATOR_DEMA)|| ( sIndicator ==  TAEngine_INDICATOR_ROC ) || ( sIndicator ==  TAEngine_INDICATOR_MOM ) ||
			( sIndicator ==  TAEngine_INDICATOR_TRIX ) || ( sIndicator ==  TAEngine_INDICATOR_RSI ) || ( sIndicator ==  TAEngine_INDICATOR_KAMA ) ||
			( sIndicator ==  TAEngine_INDICATOR_WWMA ) || ( sIndicator ==  TAEngine_INDICATOR_SWMA ))
		{
			moving_averages(indicator_map.find(sIndicator)->second, dClosePrice, inputLength, output, maPeriod);
		}
		else if( sIndicator ==  TAEngine_INDICATOR_SMMA ) 
		{
			smoothed_moving_average(dClosePrice, inputLength, maPeriod, output);
		} 
		else if( sIndicator ==  TAEngine_INDICATOR_PSAR ) 
		{
			double dStep, dMax;
			if(indicatorParamsList.size() > 1) 
			{
				dStep = atof( indicatorParamsList[0].c_str() );
				dMax = atof( indicatorParamsList[1].c_str() );
				psar(dHighPrice, dLowPrice, inputLength, output, dStep, dMax);
			} 
			else
				psar(dHighPrice, dLowPrice, inputLength, output);
		} 
		else if( sIndicator ==  TAEngine_INDICATOR_MACD ) 
		{
			macd(dClosePrice, inputLength, maPeriod1, maPeriod2, maPeriod3, output);
		} 
		else if( sIndicator ==  TAEngine_INDICATOR_TMACD ) 
		{
			tri_macd(dClosePrice, inputLength, maPeriod1, maPeriod2, output);
		}  
		else if( sIndicator ==  TAEngine_INDICATOR_MFI ) 
		{
			money_flow_index(dHighPrice, dLowPrice, dClosePrice, volume, inputLength, maPeriod, output);
		} 		 
		else if( sIndicator ==  TAEngine_INDICATOR_FSTOCH ) 
		{
			fast_stochastic(dHighPrice, dLowPrice, dClosePrice, inputLength, maPeriod1, maPeriod2, output);
		} 
		else if( sIndicator ==  TAEngine_INDICATOR_SSTOCH ) 
		{
			slow_stochastic(dHighPrice, dLowPrice, dClosePrice, inputLength, maPeriod1, maPeriod2, maPeriod3, output);
		} 
		else if( sIndicator ==  TAEngine_INDICATOR_WILLR ) 
		{
			william_r(dHighPrice, dLowPrice, dClosePrice, inputLength, maPeriod, output);
		} 
		else if( sIndicator ==  TAEngine_INDICATOR_AD ) 
		{
			accumulation_distribution_index(dHighPrice, dLowPrice, dClosePrice, volume, inputLength, output);
		} 
		else if( sIndicator ==  TAEngine_INDICATOR_ADOSC ) 
		{
			ad_osc(dHighPrice, dLowPrice, dClosePrice, volume, inputLength, maPeriod1, maPeriod2, output);
		} 
		else if( sIndicator ==  TAEngine_INDICATOR_AROON ) 
		{
			aroon(dHighPrice, dLowPrice, inputLength, maPeriod, output);
		} 
		else if( sIndicator ==  TAEngine_INDICATOR_AO ) 
		{
			ao(dHighPrice, dLowPrice, inputLength, maPeriod1, maPeriod2, output);
		} 
		else if( sIndicator ==  TAEngine_INDICATOR_OSC )
		{
			osc(dClosePrice, inputLength, maPeriod1, maPeriod2, output);
		} 
		else if( sIndicator ==  TAEngine_INDICATOR_CHO ) 
		{
			cho(dHighPrice, dLowPrice, dClosePrice, volume, inputLength, maPeriod1, maPeriod2, output);
		}  
		else if( sIndicator ==  TAEngine_INDICATOR_ADX ) 
		{
			avg_directional_movt(dHighPrice, dLowPrice, dClosePrice, inputLength, maPeriod, output);
		} 
		else if( sIndicator ==  TAEngine_INDICATOR_ATR ) 
		{
			atr(dHighPrice, dLowPrice, dClosePrice, inputLength, maPeriod, output);
		} 
		else if( sIndicator ==  TAEngine_INDICATOR_BBANDS ) 
		{
			double dStandard_devn;
			if(indicatorParamsList.size() > 0) 
			{
				dStandard_devn = atof( indicatorParamsList[1].c_str() );
				bbands(dClosePrice, inputLength, maPeriod, output, dStandard_devn);
			} 
			else
				bbands(dClosePrice, inputLength, maPeriod, output);
		} 
		else if( sIndicator ==  TAEngine_INDICATOR_CCI ) 
		{
			cci(dHighPrice, dLowPrice, dClosePrice, inputLength, maPeriod, output);
		}
		else if( sIndicator ==  TAEngine_INDICATOR_OBV ) 
		{
			obv(dClosePrice, volume, inputLength, output);
		} 
		else if( sIndicator ==  TAEngine_INDICATOR_ULTOSC ) 
		{
			ultimate_osc(dHighPrice, dLowPrice, dClosePrice, inputLength, maPeriod1, maPeriod2, maPeriod3, output);
		} 
		else if( sIndicator ==  TAEngine_INDICATOR_STDDEV ) 
		{
			stddev(dClosePrice, inputLength, maPeriod, output);
		} 
		else if( sIndicator ==  TAEngine_INDICATOR_AVGPRICE ) 
		{
			avgprice(dOpenPrice, dHighPrice, dLowPrice, dClosePrice, inputLength, output);
		} 
		else if( sIndicator ==  TAEngine_INDICATOR_MEDPRICE ) 
		{
			median_price(dHighPrice, dLowPrice, inputLength, output);
		} 
		else if( sIndicator ==  TAEngine_INDICATOR_TYPPRICE ) 
		{
			typrice(dHighPrice, dLowPrice, dClosePrice, inputLength, output);
		} 
		else if( sIndicator ==  TAEngine_INDICATOR_TYPPRICE_MA ) 
		{
			map<string, vector<double> >input;
			typrice(dHighPrice, dLowPrice, dClosePrice, inputLength, input);
			for(map<string, vector<double> >::iterator iInput = input.begin(); iInput != input.end(); iInput++) 
			{
				double *dTypicalPrice = (double *)calloc(1, iInput->second.size() * sizeof(double));
				for(size_t i = 0; i < iInput->second.size(); i++)
					*(dTypicalPrice + i) = iInput->second[i];
				moving_averages(TAEngine_SMA, dTypicalPrice, iInput->second.size(), output, maPeriod);
				free(dTypicalPrice);
				output[TAEngine_INDICATOR_TYPPRICE_MA] = output[TAEngine_INDICATOR_SMA];
				output.erase( output.find(TAEngine_INDICATOR_SMA) );
			}
		} 
		else if( sIndicator ==  TAEngine_INDICATOR_CMF ) 
		{
			cmf(dHighPrice, dLowPrice, dClosePrice, volume, inputLength, maPeriod, output);
		} 
		else if( sIndicator ==  TAEngine_INDICATOR_DOC ) 
		{
			donchian_channel(dHighPrice, dLowPrice, inputLength, maPeriod, output);
		} 
		else if( sIndicator ==  TAEngine_INDICATOR_DMI ) 
		{
			dmi(dHighPrice, dLowPrice, dClosePrice, inputLength, maPeriod, output);
		} 
		else if( sIndicator ==  TAEngine_INDICATOR_CMO ) 
		{
			chande_momentum_oscillator(dClosePrice, inputLength, maPeriod, output);
		} 
		else if( sIndicator ==  TAEngine_INDICATOR_KELTNER ) 
		{
			keltner_channel(dHighPrice, dLowPrice, dClosePrice, inputLength, maPeriod, output);
		} 
		else if( sIndicator ==  TAEngine_INDICATOR_VMA ) 
		{
			variable_moving_average(dClosePrice, inputLength, maPeriod, output);
		} 
		else if( sIndicator ==  TAEngine_INDICATOR_STOCHRSI ) 
		{
			stochastic_rsi(dClosePrice, inputLength, maPeriod1, maPeriod2, maPeriod3, output);
		} 
		else if((sIndicator == TAEngine_INDICATOR_SMA_ENVELOPE) || (sIndicator == TAEngine_INDICATOR_EMA_ENVELOPE) ||  (sIndicator == TAEngine_INDICATOR_TRIMA_ENVELOPE) 
			      || (sIndicator == TAEngine_INDICATOR_WWMA_ENVELOPE) || (sIndicator == TAEngine_INDICATOR_WMA_ENVELOPE)) 
		{
			map<string, vector<double> >input;
			moving_averages(indicator_map.find(sIndicator)->second, dClosePrice, inputLength, input, maPeriod);
			double dEnvelopePercentage = atof( indicatorParamsList[1].c_str() );
			envelope(sIndicator, input, output, dEnvelopePercentage);
		} 
		else if( sIndicator == TAEngine_INDICATOR_VMA_ENVELOPE ) 
		{
			map<string, vector<double> >input;
			variable_moving_average(dClosePrice, inputLength, maPeriod, input);
			double dEnvelopePercentage = atof( indicatorParamsList[1].c_str() );
			envelope(TAEngine_INDICATOR_VMA_ENVELOPE, input, output, dEnvelopePercentage);
		} 
		else if( sIndicator == TAEngine_INDICATOR_TYPPRICE_ENVELOPE ) 
		{
			map<string, vector<double> >input;
			typrice(dHighPrice, dLowPrice, dClosePrice, inputLength, input);
			double dEnvelopePercentage = atof( indicatorParamsList[1].c_str() );
			envelope(TAEngine_INDICATOR_TYPPRICE_ENVELOPE, input, output, dEnvelopePercentage);
		} 
		else if( sIndicator == TAEngine_INDICATOR_OVERBOUGHT_OVERSOLD ) 
		{
			map<string, vector<double> >input;
			moving_averages(TAEngine_SMA, dClosePrice, inputLength, input, maPeriod);
			map<string, vector<double> >::iterator iInput = input.begin();
			vector<double>::iterator iValue;
			vector<double>obosValues;
			size_t iMa = maPeriod;
			for(iValue = iInput->second.begin(); iValue != iInput->second.end(); iValue++, iMa++) 
			{
				double obos_value = (*(dClosePrice + iMa) - *iValue)*100.0/(*iValue);
				obosValues.push_back( obos_value );
			}
			output.insert( make_pair("OBOS", obosValues) );
		} 
		else if( sIndicator == TAEngine_INDICATOR_VOLUME_RATIO ) 
		{
			map<string, vector<double> >input;
			volume_ma(TAEngine_VOLUME_SMA, volume, inputLength, maPeriod, input);
			map<string, vector<double> >::iterator iInput = input.begin();
			vector<double>::iterator iValue;
			size_t iMa = maPeriod;
			for(iValue = iInput->second.begin(); iValue != iInput->second.end(); iValue++, iMa++) 
			{
				double vr_value = (*dClosePrice + iMa)/(*iValue);
				output["VOLUME_RATIO"].push_back(vr_value);
			}
		} 
		else if ( sIndicator == TAEngine_INDICATOR_PRICE_CHANNEL ) 
		{
			price_channel(dHighPrice, dLowPrice, inputLength, maPeriod, output);
		} 
		else if ( sIndicator == TAEngine_INDICATOR_HISTORIC_VOLATILITY) 
		{
			stddev(dClosePrice, inputLength, maPeriod, output);
			output["HISTORIC_VOLATILITY"] = output["STDDEV"];
			output.erase( output.find("STDDEV") );
		} 
		else if ( sIndicator == TAEngine_INDICATOR_PIVOT_POINT) 
		{
			map<string, vector<double> >input;
			typrice(dHighPrice, dLowPrice, dClosePrice, inputLength, input);
			size_t length = inputLength - input["TYPPRICE"].size();
			pivot_point(dHighPrice + length, dLowPrice + length, input["TYPPRICE"], output);
		} 
		else if ( sIndicator == TAEngine_INDICATOR_TSI ) 
		{
			tsi(dClosePrice, inputLength, maPeriod1, maPeriod2, output);
		} 
		else if ( sIndicator == TAEngine_INDICATOR_BUYP ) 
		{
			buying_pressure(dClosePrice, dLowPrice, inputLength, maPeriod, output);
		} 
		else if ( sIndicator == TAEngine_INDICATOR_GANN_HI_LO_ACTIVATOR ) 
		{
			gann_hi_lo_activator(dClosePrice, dHighPrice, dLowPrice, inputLength, maPeriod, output);
		}
		else if ( sIndicator == TAEngine_INDICATOR_VEMA ) 
		{
			volume_average(TAEngine_INDICATOR_VEMA, volume, inputLength, maPeriod, output);
		} 
		else if ( sIndicator == TAEngine_INDICATOR_VSMA ) 
		{
			volume_average(TAEngine_INDICATOR_VSMA, volume, inputLength, maPeriod, output);
		} 
		else if ( sIndicator == TAEngine_INDICATOR_ALLIGATOR ) 
		{
			alligator(dHighPrice, dLowPrice, inputLength, output);
		} 
		else if ( sIndicator == TAEngine_INDICATOR_AC ) 
		{
			ac(dHighPrice, dLowPrice, inputLength, maPeriod1, maPeriod2, maPeriod3, output);
		} 
		else if ( sIndicator == TAEngine_INDICATOR_HA ) 
		{
			ha(dOpenPrice, dHighPrice, dLowPrice, dClosePrice, inputLength, output);
		}
		else if ( sIndicator == TAEngine_INDICATOR_ICH ) 
		{
			ichimoku(dHighPrice, dLowPrice, dClosePrice, inputLength, maPeriod1, maPeriod2, maPeriod3, output);
		} 
		else if ( sIndicator == TAEngine_INDICATOR_VIDYA ) 
		{
			vidya(dClosePrice, inputLength, maPeriod1, output);
		}
		else if ( sIndicator == TAEngine_INDICATOR_EWO ) 
		{
			ewo(dHighPrice, dLowPrice, inputLength, output);
		} 
		else if ( sIndicator == TAEngine_INDICATOR_MD ) 
		{
			mcginley(dClosePrice, inputLength, maPeriod, output);
		} 
		else if ( sIndicator == TAEngine_INDICATOR_GATOR ) 
		{
			gator_osc(dHighPrice, dLowPrice, inputLength, output);
		} 
		else if( sIndicator == TAEngine_INDICATOR_LINEARREG ) 
		{
			regression(dClosePrice, inputLength, maPeriod, output);
		} 
		else if( sIndicator == TAEngine_INDICATOR_KRI ) 
		{
			kairi(dClosePrice, inputLength, maPeriod, output);
		} 
		else if( sIndicator == TAEngine_INDICATOR_ASI ) 
		{
			double dMaxPriceChange = atof( indicatorParamsList[0].c_str() );
			asi(dOpenPrice, dHighPrice, dLowPrice, dClosePrice, inputLength, dMaxPriceChange, output);
		} 
		else if( sIndicator == TAEngine_INDICATOR_FRACTAL ) 
		{
			fractal(dHighPrice, dLowPrice, inputLength, output);
		} else if(sIndicator == TAEngine_INDICATOR_STO) {
            stochastic_oscillator(dHighPrice,dLowPrice,dClosePrice,inputLength,output,maPeriod,maPeriod2,maPeriod3);
                } else if(sIndicator == TAEngine_INDICATOR_ARSI) 	{                         
			adaptive_rsi(dClosePrice,inputLength,output,maPeriod);
                }  else if(sIndicator == TAEngine_INDICATOR_RVI) {
                        rvi(dHighPrice,dLowPrice,dOpenPrice,dClosePrice,inputLength,output,maPeriod,maPeriod2);
                } else if(sIndicator == TAEngine_INDICATOR_BWMFI) {
                         market_facilitation_index(dHighPrice,dLowPrice,volume,inputLength,output);
                }  else if(sIndicator == TAEngine_INDICATOR_FORCE) {
                        force_index(dClosePrice,volume, inputLength, output, maPeriod);
                }  else if(sIndicator == TAEngine_INDICATOR_DEM ) {
                        dem(TAEngine_SMA,dHighPrice,dLowPrice,inputLength, output, maPeriod);
                } else if(sIndicator == TAEngine_INDICATOR_BULLR ) {
                        bulls_power(TAEngine_EMA, dClosePrice,dHighPrice,inputLength, output, maPeriod);
                } else if(sIndicator == TAEngine_INDICATOR_BEARS) {
                        bears_power(TAEngine_EMA, dClosePrice,dLowPrice,inputLength, output, maPeriod);
                } 
        /* TODO
		else if( sIndicator ==  TAEngine_INDICATOR_PPO ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_APO ) {
		} else if(( sIndicator ==  TAEngine_INDICATOR_BETA ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_CORREL ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_FAMA ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_MAMA ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_HTDCPERIOD ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_HTDCPHASE ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_HTTRENDMODE ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_HTTRENDLINE ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_HTSINE ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_HTPHASOR ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_LREG ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_LREGANGLE ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_LREGINTERCEPT ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_LREGSLOPE ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_MIDPOINT ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_MIDPRICE ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_MINUSDI ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_PLUSDI ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_MINUSDM ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_PLUSDM ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_NATR ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_TRANGE ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_TSF ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_VARIANCE ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_WCLPRICE ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_FI ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_SLOPE ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_CLV ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_CVI ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_MI ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_NVI ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_PI ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_PVI ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_PVO ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_PVT ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_MASD ) {
		} eelse if( sIndicator ==  TAEngine_INDICATOR_VF ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_VS ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_AMA ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_SWING ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_ASWING ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_AVGDEV ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_BOMP ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_VA ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_RSQUARE ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_QSTICK ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_MAENV ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_MAOSC ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_HARMONIC ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_PFE ) {
		} else if( sIndicator ==  TAEngine_INDICATOR_VOMA ) {
		} */
		map<string, vector<double> >::iterator iOutput;
		for(iOutput = output.begin(); iOutput != output.end(); iOutput++) {
			vector<double>::iterator iValue = iOutput->second.begin();
			size_t iLength = 0;
			string sIndicatorNameWithParam(iOutput->first);
			cout << "indicator " << iOutput->first  << endl;
			cout << "count " << indicatorsList.count(iOutput->first) << endl;
			if(flag) {
				sIndicatorNameWithParam.append(":");
				for(size_t i = 0; i < indicatorParamsList.size(); i++) {
					sIndicatorNameWithParam.append(indicatorParamsList[i]);
					sIndicatorNameWithParam.append(":");
				}
				helper.rstrip(sIndicatorNameWithParam, ':', 1);
			} 
			while( iValue != iOutput->second.end() ) {
				stringstream sIndicatorValue;
				sIndicatorValue.setf(ios::fixed);
				sIndicatorValue.precision(6);
				sIndicatorValue << *iValue;
				tivResponse.addIndicatorCodeValue( sIndicatorNameWithParam, sIndicatorValue.str() );
				iValue++;
				iLength++;
			}
		}
	}
	for(size_t i = 0; i < inputLength;i++) {
		stringstream sOpen, sHigh, sLow, sClose, sVolume;
		string sTime;
		sVolume.setf(ios::fixed);
		sOpen.setf(ios::fixed, ios::floatfield);
		sOpen.precision(precision);
		sHigh.setf(ios::fixed, ios::floatfield);
		sHigh.precision(precision);
		sLow.setf(ios::fixed, ios::floatfield);
		sLow.precision(precision);
		sClose.setf(ios::fixed, ios::floatfield);
		sClose.precision(precision);
		sOpen << *(dOpenPrice + i);
		sHigh << *(dHighPrice + i);
		sLow << *(dLowPrice + i);
		sClose << *(dClosePrice + i);
		sVolume << *(volume + i);
		helper.formatTime(timeList + i, "%Y/%m/%d %H:%M:%S", sTime);

		tivResponse.addOpenValue( sOpen.str() );
		tivResponse.addHighValue( sHigh.str() );
		tivResponse.addLowValue( sLow.str() );
		tivResponse.addCloseValue( sClose.str() );
		tivResponse.addVolumeValue( sVolume.str() );
		tivResponse.addDateValue( sTime );
	}

	free( dClosePrice );
	free( dOpenPrice );
	free( dHighPrice );
	free( dLowPrice );
	free( volume );
	free( timeList );
}

void TAEngine::smoothed_moving_average(double *dClosePrice, size_t inputLength, int maPeriod,  map<string, vector<double> > & output)
{
//http://20minutetraders.com/learn/moving-averages/smoothed-moving-average-calculation
	vector<double> smma;
	double dSMA = 0, dSum = 0;
	for(int i = 0; i < maPeriod; i++)
		dSum += *(dClosePrice + i);
	dSMA = dSum / maPeriod;
	cout << "SMA is " << dSMA << endl;
	smma.push_back(dSMA);
	double prev_sum = dSum;
	double prev_average = dSMA;
	for(size_t i = maPeriod; i < inputLength; i++) {
		double sum = prev_sum - prev_average + *(dClosePrice + i);
		double element = sum / maPeriod;
		smma.push_back(element);
		prev_sum = sum;
		prev_average = element;
	}
	output["SMMA"] = smma;
}

void TAEngine::variable_moving_average(double *dClosePrice, size_t inputLength, int maPeriod,  map<string, vector<double> > & output)
{
	chande_momentum_oscillator(dClosePrice, inputLength, maPeriod, output);
	double smoothing_constant = 2.0/(maPeriod + 1.0);
	double cmo_value_d, vma_d;
	int iterator;

	map<string, vector<double> >::iterator iOutput = output.find("CMO");
	if( iOutput == output.end() )
		return;

	vector<double>vma;
	for(iterator = 0; (iterator+maPeriod) < (int)inputLength; iterator++) {
		cmo_value_d = iOutput->second[iterator];
		double dCurrentClose = *(dClosePrice + iterator + maPeriod - 1);
		double dPrevClose = *(dClosePrice + iterator + maPeriod - 2);
		vma_d = (smoothing_constant * cmo_value_d * dCurrentClose) + ( (1.0 - (smoothing_constant * cmo_value_d)) * dPrevClose );
		cout << "Current = " << dCurrentClose << ", Prev = " << dPrevClose << ", vma_d = " << vma_d << ", cmo_value_d = " << cmo_value_d << endl;
		vma.push_back(vma_d);
	}
	output.erase( iOutput );
	output["VMA"] = vma;
}

void TAEngine::chande_momentum_oscillator(double *dClosePrice, size_t inputLength, int maPeriod,  map<string, vector<double> > & output)
{
	double last_up, last_down, up_sum, down_sum, momentum;
	int start_idx, end_idx;

	up_sum = down_sum = (double)0;
	for(start_idx = 1; start_idx < maPeriod; start_idx++) {
		last_up = last_down = (double)0;
		double dDiff = *(dClosePrice + start_idx) - *(dClosePrice + (start_idx - 1));
		(dDiff > 0) ? last_up = dDiff : last_down = fabs(dDiff);
		up_sum += last_up;
		down_sum += last_down;
	}

	if( (up_sum + down_sum) != 0 )
		momentum = 100.0 * (up_sum - down_sum)/(up_sum + down_sum);
	else
		momentum = 0.0;
	output["CMO"].push_back(momentum);

	for(start_idx = 1, end_idx = maPeriod + 1; end_idx < (int)inputLength; start_idx++, end_idx++) {
		last_up = last_down = (double)0;
		double dDiff = *(dClosePrice + start_idx) - *(dClosePrice + (start_idx - 1));
		(dDiff > 0) ? last_up = dDiff : last_down = fabs(dDiff);
		up_sum -= last_up;
		down_sum -= last_down;

		dDiff = *(dClosePrice + end_idx) - *(dClosePrice + (end_idx - 1));
		last_up = last_down = (double)0;
		(dDiff > 0) ? last_up = dDiff : last_down = fabs(dDiff);
		up_sum += last_up;
		down_sum += last_down;

		if( (up_sum + down_sum) != 0 ) {
			momentum = 100.0 * (up_sum - down_sum)/(up_sum + down_sum);
			output["CMO"].push_back(momentum);
		} else {
			output["CMO"].push_back(0.0);
			cout << __LINE__ << " sum is zero" << " last_up = " << up_sum  << " last_down = " << down_sum << endl;
		}
	} 
}

void TAEngine::process(HistoryDataResponse histDataResponse, TechnicalIndicatorValueResponse & tivResponse, uint32_t iIndicatorType, int maPeriod)
{
	double *dClosePrice, *dOpenPrice, *dHighPrice, *dLowPrice, *dOutputPrices;
	uint32_t *volume;
//	size_t inputLength = 0;
	size_t outputLength = 0;
	struct tm *timeList;
	IFHelper helper;

	vector<HistoryData>dataList = histDataResponse.getHistoryData();

	if( dataList.size() == 0 )
		return;

	vector<HistoryData>::iterator iDataList = dataList.begin();

	tivResponse.setSymbol( (*iDataList).getSymbol() );
	dClosePrice = (double *)calloc(1, sizeof(double)*dataList.size());
	dOpenPrice = (double *)calloc(1, sizeof(double)*dataList.size());
	dHighPrice = (double *)calloc(1, sizeof(double)*dataList.size());
	dLowPrice = (double *)calloc(1, sizeof(double)*dataList.size());
	volume = (uint32_t *)calloc(1, sizeof(uint32_t)*dataList.size());
	timeList = (struct tm *)calloc(1, sizeof(struct tm)*dataList.size());
	size_t i = 0;
	while( iDataList != dataList.end() ) {
		*(dClosePrice + i) = (*iDataList).getClose();
		*(dOpenPrice + i) = (*iDataList).getOpen();
		*(dHighPrice + i) = (*iDataList).getHigh();
		*(dLowPrice + i) = (*iDataList).getLow();
		*(volume + i) = (*iDataList).getVolume();
		struct tm tmpTime = (*iDataList).getTime();
		memcpy(timeList+i, &tmpTime, sizeof(struct tm));
		iDataList++;
		i++;
	}
//	inputLength = i;
	dOutputPrices = (double *)calloc(1, sizeof(double)*dataList.size());
	string sIndicatorName;
//	moving_averages(iIndicatorType, dClosePrice, inputLength, dOutputPrices, &outputLength, maPeriod, sIndicatorName);
	cout << "outputLength = " << outputLength << endl;
	outputLength = dataList.size();
	for(size_t i = 0, j = dataList.size() - outputLength ; i < outputLength ;i++, j++) {
		stringstream sOpen, sHigh, sLow, sClose, sIndicator, sVolume;
		string sTime;
		sVolume.setf(ios::fixed);
		sOpen << *(dOpenPrice + j);
		sHigh << *(dHighPrice + j);
		sLow << *(dLowPrice + j);
		sClose << *(dClosePrice + j);
		sVolume << *(volume + j);
//		sIndicator << *(dOutputPrices + i);
		helper.formatTime(timeList + j, "%Y/%m/%d %H:%M:%S", sTime);

		tivResponse.addOpenValue( sOpen.str() );
		tivResponse.addHighValue( sHigh.str() );
		tivResponse.addLowValue( sLow.str() );
		tivResponse.addCloseValue( sClose.str() );
		tivResponse.addVolumeValue( sVolume.str() );
		tivResponse.addDateValue( sTime );
//		tivResponse.addIndicatorCodeValue( sIndicatorName, sIndicator.str() );
	}
	free( dClosePrice );
	free( dOpenPrice );
	free( dHighPrice );
	free( dLowPrice );
	free( volume );
	free( dOutputPrices );
	free( timeList );
}

void TAEngine::avgprice(double *dOpenPrice, double *dHighPrice, double *dLowPrice, double *dClosePrice, size_t inputLength, map<string, vector<double> > & output)
{
	double dOutput[4096] = {'\0'};
	int outBeg = 0, outNb = 0, i =0;
	
	TA_AVGPRICE(0, inputLength - 1, dOpenPrice, dHighPrice, dLowPrice, dClosePrice, &outBeg, &outNb, dOutput);
	
	for(i = 0 ; i < outNb; i++) {
		output["AVGPRICE"].push_back( *(dOutput + i) );
	}
}

void TAEngine::typrice(double *dHighPrice, double *dLowPrice, double *dClosePrice, size_t inputLength, map<string, vector<double> > & output)
{
	double dOutput[4096] = {'\0'};
	int outBeg = 0, outNb = 0, i =0;
	
	TA_TYPPRICE(0, inputLength - 1, dHighPrice, dLowPrice, dClosePrice, &outBeg, &outNb, dOutput);
	
	for(i = 0; i < outNb; i++) {
		output["TYPPRICE"].push_back( *(dOutput + i) );
	}
}

void TAEngine::macd(double *dClosePrice, size_t inputLength, int iFastPeriod, int iSlowPeriod, int iSignalPeriod, map<string, vector<double> > & output)
{
	double macd[4096] = {0};
	double macd_signal[4096] = {0};
	double macd_histogram[4096] = {0};

	int outBeg = 0, outNb = 0, i =0;
	TA_MACD(0, inputLength - 1, dClosePrice, iFastPeriod, iSlowPeriod, iSignalPeriod, &outBeg, &outNb, macd, macd_signal, macd_histogram);

	cout << "outBeg = " << outBeg << ", outNb = " << outNb << endl;
	for(i = 0; i < outNb; i++) {
		output["macd"].push_back( *(macd + i) );
		output["macd_signal"].push_back( *(macd_signal + i) );
		output["macd_histogram"].push_back( *(macd_histogram + i) );
	}
}

void TAEngine::tri_macd(double *dClosePrice, size_t inputLength, int iFastPeriod, int iSlowPeriod, map<string, vector<double> > & output)
{
// http://fxcodebase.com/wiki/index.php/Triangular_Moving_Average_Convergence/Divergence_(TMACD)
	cout << "inputLength ............... " << inputLength << endl;
	map<string, vector<double> >fastOutput;
   	map<string, vector<double> >slowOutput;
	moving_averages(TAEngine_TRIMA, dClosePrice, inputLength, fastOutput, iFastPeriod);
	moving_averages(TAEngine_TRIMA, dClosePrice, inputLength, slowOutput, iSlowPeriod);
	size_t fastOutputSize = fastOutput["TRIMA"].size();
	size_t slowOutputSize = slowOutput["TRIMA"].size();
	size_t minSize = (fastOutputSize <= slowOutputSize) ? fastOutputSize : slowOutputSize;
	cout << "fastOutput size " << fastOutput["TRIMA"].size() << endl;
	cout << "slowOutput size " << slowOutput["TRIMA"].size() << endl;
	cout << "minSize " << minSize << endl;
	for(size_t i = 0; i < minSize; i++) {
		double element = fastOutput["TRIMA"][i] - slowOutput["TRIMA"][i];
		output["TMACD"].push_back( element );
	}
}

void TAEngine::atr(double *dHighPrice, double *dLowPrice, double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output)
{
	double dOutput[4096] = {0};
	int outBeg = 0, outNb = 0, i =0;
	TA_ATR(0, inputLength - 1, dHighPrice, dLowPrice, dClosePrice, maPeriod, &outBeg, &outNb, dOutput);
	for(i = 0; i < outNb; i++) {
		output["atr"].push_back( *(dOutput + i) );
	}
}

void TAEngine::cci(double *dHighPrice, double *dLowPrice, double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output)
{
	double dOutput[4096] = {0};
	int outBeg = 0, outNb = 0, i =0;
	TA_CCI(0, inputLength - 1, dHighPrice, dLowPrice, dClosePrice, maPeriod, &outBeg, &outNb, dOutput);
	for(i = 0; i < outNb; i++) {
		output["CCI"].push_back( *(dOutput + i) );
	}
}

void TAEngine::william_r(double *dHighPrice, double *dLowPrice, double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output)
{
	double dOutput[4096] = {'\0'};
	int outBeg = 0, outNb = 0, i =0;
	TA_WILLR(0, inputLength - 1, dHighPrice, dLowPrice, dClosePrice, maPeriod, &outBeg, &outNb, dOutput);
	for(i = 0; i < outNb; i++) {
		output["WILLR"].push_back( *(dOutput + i) );
	}
}

bool TAEngine::volume_ma(uint32_t iIndicatorType, uint32_t *lVolume, size_t inputLength, int maPeriod, map<string, vector<double> > & output)
{
//	double *dOutputPrice = (double *)calloc(1, sizeof(inputLength)*sizeof(double));
	double *dVolume = (double *)calloc(1, sizeof(inputLength)*sizeof(double));
//	size_t outputLength = 0;
	int i = 0;
	for(  ; i < (int)inputLength; i++) {
		*(dVolume + i) = (double )(*(lVolume + i) * 1.0);
	}
	string sIndicatorName, sOldIndicator;
	if( iIndicatorType == TAEngine_VOLUME_SMA ) {
		moving_averages( TAEngine_SMA, dVolume, inputLength, output, maPeriod);
		sIndicatorName = "volume_sma";
		sOldIndicator = "SMA";
	} else if( iIndicatorType == TAEngine_VOLUME_EMA )  {
		moving_averages( TAEngine_EMA, dVolume, inputLength, output, maPeriod);
		sIndicatorName = "volume_ema";
		sOldIndicator = "EMA";
	}
	map<string, vector<double> >::iterator iOutput = output.find( sOldIndicator );
	if( iOutput != output.end() ) 
		output.insert( make_pair(sIndicatorName, iOutput->second) );
	iOutput = output.find( sOldIndicator );
	if( iOutput != output.end() ) 
		output.erase( iOutput );
	free( dVolume );
//	free( dOutputPrice );
	return true;
}

void TAEngine::money_flow_index(double *dHighPrice, double *dLowPrice, double *dClosePrice, uint32_t *lVolume, size_t inputLength, int maPeriod, map<string, vector<double> > & output)
{
	double dOutputPrice[4096] = {0};
	double dVolume[4096] = {0};
	int outBeg = 0, outNb = 0, i = 0;

	for(  ; i < (int)inputLength; i++) {
		dVolume[i] = (double )(*(lVolume + i) * 1.0);
	}

	TA_MFI(0, inputLength - 1, dHighPrice, dLowPrice, dClosePrice, dVolume, maPeriod, &outBeg, &outNb, dOutputPrice);
	for(i = 0; i < outNb; i++) {
		output["mfi"].push_back( *(dOutputPrice + i) );
	}
}

void TAEngine::obv(double *dClosePrice, uint32_t *lVolume, size_t inputLength, map<string, vector<double> > & output)
{
	double dOutputPrice[4096] = {0};
	double dVolume[4096] = {0};
	int outBeg = 0, outNb = 0, i = 0;

	for(  ; i < (int)inputLength; i++) {
		dVolume[i] = (double )(*(lVolume + i) * 1.0);
	}

	TA_OBV(0, inputLength - 1, dClosePrice, dVolume, &outBeg, &outNb, dOutputPrice);
	for(i = 0; i < outNb; i++) {
		output["OBV"].push_back( *(dOutputPrice + i) );
	}
}

void TAEngine::median_price(double *dHighPrice, double *dLowPrice, size_t inputLength, map<string, vector<double> > & output)
{
	double dOutputPrice[4096] = {0};
	int outBeg = 0, outNb = 0, i = 0;
	TA_MEDPRICE(0, inputLength - 1, dHighPrice, dLowPrice, &outBeg, &outNb, dOutputPrice);
	for(i = 0; i < outNb; i++) {
		output["MEDPRICE"].push_back( *(dOutputPrice + i) );
	}
}

void TAEngine::psar(double *dHighPrice, double *dLowPrice, size_t inputLength, map<string, vector<double> > & output, double dStep, double dMax)
{
	double dOutputPrice[4096] = {'\0'};
	int outBeg = 0, outNb = 0, i = 0;
	TA_SAR(0, inputLength - 1, dHighPrice, dLowPrice, dStep, dMax, &outBeg, &outNb, dOutputPrice);
	vector<double>tmpList;
	cout << "outBeg = " << outBeg << ", outNb = " << outNb << endl;
	for(i = 0; i < outNb; i++) {
		double d = *(dOutputPrice + i);
		cout << "value = " << d << ", i = " << i << endl;
		tmpList.push_back( *(dOutputPrice + i) );
	}
	cout << "size = " << tmpList.size() << endl;
	output.insert(make_pair("PSAR", tmpList));
}

void TAEngine::keltner_channel(double *dHighPrice, double *dLowPrice, double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output)
{
	double dInputAverage[4096] = {'\0'};
	double dInputDiff[4096] = {'\0'};
	double dOutputAverage[4096] = {'\0'};
	double dOutputDiffAverage[4096] = {'\0'};
	for(size_t i = 0; i < inputLength; i++) {
		double dHigh = *(dHighPrice + i);
		double dLow = *(dLowPrice + i);
		double dClose = *(dClosePrice + i);
		dInputAverage[i] = (dHigh + dLow + dClose)/3.0;
		dInputDiff[i] = (dHigh - dLow);
	}
	int outAvgBeg = 0, outAvgNb = 0, outDiffBeg = 0, outDiffNb = 0;
	TA_SMA(0, inputLength - 1, dInputAverage, maPeriod, &outAvgBeg, &outAvgNb, dOutputAverage);
	TA_SMA(0, inputLength - 1, dInputDiff, maPeriod, &outDiffBeg, &outDiffNb, dOutputDiffAverage);
	size_t length = outAvgNb - outAvgBeg;
	for(size_t i = 0; i < length; i++) {
		double dUpperBand = *(dOutputAverage + i) + *(dOutputDiffAverage + i);
		double dLowerBand = *(dOutputAverage + i) - *(dOutputDiffAverage + i);
		output["KELTNER"].push_back( (*(dOutputAverage + i)) );
		output["upper_keltner_band"].push_back( dUpperBand );
		output["lower_keltner_band"].push_back( dLowerBand );
	}
}

void TAEngine::bbands(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output, double dStndDeviation)
{
	double dUpperBand[4096] = {0};
	double dLowerBand[4096] = {0};
	double dMiddleBand[4096] = {0};

	int outBeg = 0, outNb = 0;

	if( dStndDeviation <= 1 )
		dStndDeviation = 2.0;

	TA_BBANDS(0, inputLength - 1, dClosePrice, maPeriod, dStndDeviation, dStndDeviation, (TA_MAType)0, &outBeg, &outNb, dUpperBand, dMiddleBand, dLowerBand);

	for(int i = 0; i < outNb; i++) {
		output["bband_upper"].push_back( *(dUpperBand + i) );
		output["bband_lower"].push_back( *(dLowerBand + i) );
		output["bband_middle"].push_back( *(dMiddleBand + i) );
	}
}

void TAEngine::stochastic_rsi(double *dClosePrice, size_t inputLength, int maPeriod, int maFastKPeriod, int maFastDPeriod, map<string, vector<double> > & output)
{
	double dOutOutFastK[4096] = {0};
	double dOutOutFastD[4096] = {0};

	int outBeg = 0, outNb = 0;
	TA_STOCHRSI(0, inputLength - 1, dClosePrice, maPeriod, maFastKPeriod, maFastDPeriod, (TA_MAType)0, &outBeg, &outNb, dOutOutFastK, dOutOutFastD);
	cout << "stochastic_rsi: outBeg = " << outBeg << ", outNb = " << outNb << endl;
	for(int i = 0; i < outNb; i++) {
		output["stochasticrsi_fast_k"].push_back( *(dOutOutFastK + i) );
		output["stochasticrsi_fast_d"].push_back( *(dOutOutFastD + i) );
	}
}

void TAEngine::slow_stochastic(double *dHighPrice, double *dLowPrice, double *dClosePrice, size_t inputLength, int maFastKPeriod, int maSlowKPeriod, int maSlowDPeriod, map<string, vector<double> > & output)
{
	double *dOutOutSlowK = (double *)calloc(1, sizeof(double)*inputLength);
	double *dOutOutSlowD = (double *)calloc(1, sizeof(double)*inputLength);

	int outBeg = 0, outNb = 0;
	TA_STOCH(0, inputLength - 1, dHighPrice, dLowPrice, dClosePrice, maFastKPeriod, maSlowKPeriod, (TA_MAType)0, maSlowDPeriod, (TA_MAType)0, &outBeg, &outNb, dOutOutSlowK, dOutOutSlowD);
	for(int i = 0; i < outNb; i++) {
		output["slow_stochastic_k"].push_back( *(dOutOutSlowK + i) );
		output["slow_stochastic_d"].push_back( *(dOutOutSlowD + i) );
	}
	free( dOutOutSlowK );
	free( dOutOutSlowD );
}

void TAEngine::fast_stochastic(double *dHighPrice, double *dLowPrice, double *dClosePrice, size_t inputLength, int maFastKPeriod, int maFastDPeriod, map<string, vector<double> > & output)
{
	double *dOutOutFastK = (double *)calloc(1, sizeof(double)*inputLength);
	double *dOutOutFastD = (double *)calloc(1, sizeof(double)*inputLength);

	int outBeg = 0, outNb = 0;
	TA_STOCHF(0, inputLength - 1, dHighPrice, dLowPrice, dClosePrice, maFastKPeriod, maFastDPeriod, (TA_MAType)0, &outBeg, &outNb, dOutOutFastK, dOutOutFastD);
	for(int i = 0; i < outNb; i++) {
		output["fast_stochastic_k"].push_back( *(dOutOutFastK + i) );
		output["fast_stochastic_d"].push_back( *(dOutOutFastD + i) );
	}
	free( dOutOutFastK );
	free( dOutOutFastD );
}

void TAEngine::donchian_channel(double *dHighPrice, double *dLowPrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output)
{
	size_t start_idx, end_idx, iterator;
	start_idx = 0; end_idx = start_idx + maPeriod;
	vector<double>list, doc_high, doc_low;

	for( ; end_idx < inputLength; start_idx++, end_idx++) {
		double dHigh = *(dHighPrice + start_idx);
		double dLow = *(dLowPrice + end_idx);
		for(iterator = start_idx+1; iterator < end_idx; iterator++) {
			double currHigh = *( dHighPrice + iterator );
			double currLow = *(dLowPrice + iterator);
			dHigh = (dHigh > currHigh) ? dHigh : currHigh;
			dLow = (dLow < currLow) ? dLow : currLow;
		}
		double dAvg = (dHigh + dLow)/2.0;
		doc_high.push_back(dHigh);
		doc_low.push_back(dLow);
		list.push_back( dAvg );
	}
	output["DOC"] = list;
	output["DOC_HIGH"] = doc_high;
	output["DOC_LOW"] = doc_low;
}

void TAEngine::ultimate_osc(double *dHighPrice, double *dLowPrice, double *dClosePrice, size_t inputLength, int maPeriod1, int maPeriod2, int maPeriod3, map<string, vector<double> > & output)
{
	double dOutputPrice[4096] = {0};
	int outBeg = 0, outNb = 0;

	TA_ULTOSC(0, inputLength - 1, dHighPrice, dLowPrice, dClosePrice, maPeriod1, maPeriod2, maPeriod3, &outBeg, &outNb, dOutputPrice);
	cout << "ultimate_osc: outBeg = " << outBeg << ", outNb = " << outNb << endl;
	for(int i = 0; i < outNb; i++) {
		output["ULTOSC"].push_back( *(dOutputPrice + i) );
	}
}

void TAEngine::stochastic_oscillator(double *dHighPrice,double *dLowPrice,double *dClosePrice,size_t inputLength,map<string,vector<double> > & output,int maPeriod,int maPeriod2,int maPeriod3)
{
        //http://stockcharts.com/school/doku.php?id=chart_school:technical_indicators:stochastic_oscillator
        maPeriod = maPeriod < 1 ? 14 : maPeriod ;
        maPeriod2 = maPeriod2 < 1 ? 3 :maPeriod2 ;
        maPeriod3 = maPeriod3 < 1 ? 3 :maPeriod3 ;
        double dOutputPrices[1024*10];
      //memset(&dOutputPrices, 0, inputLength); 
        dOutputPrices[0] = 0;
        int  outNb = 0,outBeg=0;
        size_t i =1;
        double H_high=0,L_low=0,*per_k,*full_k;
        full_k =(double *)malloc(sizeof(double)*(1024*10));
        per_k = (double *) malloc(sizeof(double)*(inputLength -maPeriod+1));
        H_high = *(dHighPrice+i);
        L_low = *(dLowPrice+i);
        while(i<maPeriod)
        {
                if(H_high < *(dHighPrice+i))
                   H_high = *(dHighPrice+i);
                if(L_low > *(dLowPrice+i))
                   L_low = *(dLowPrice+i);
                i++;
        }
        i--;
        int j=0;
        for(;i<inputLength;i++)
        {
                if(H_high < *(dHighPrice+i))
                   H_high = *(dHighPrice+i);
                if(L_low > *(dLowPrice+i))
                   L_low = *(dLowPrice+i);
                cout<<"highest high="<<H_high<<endl;
                cout<<"Lowest low  ="<<L_low <<endl;
                cout<<"Close Price ="<< (*(dClosePrice+i))<<endl;
        per_k[j++] =( ( (*(dClosePrice+i)) - L_low)/(H_high -L_low ) )* 100;
//         output["per_d"].push_back(per_k[j++] = ( *(dClosePrice+i) - L_low)/(H_high -L_low ) * 100);   
        }

        TA_RetCode retCode;
        retCode = TA_SMA(0,j-1 ,per_k,maPeriod2, &outBeg, &outNb,full_k);
        outNb = abs(outNb - outBeg);
         if(outNb)
        {
                for(int k=0;k<outNb;k++)
                    output["per_k"].push_back(full_k[k]);
        }


        int  outNb_d =0;
        int  outBeg_d=0;
        retCode = TA_SMA(0,outNb-1 ,full_k,maPeriod3, &outBeg_d, &outNb_d, dOutputPrices);

        outNb = abs(outNb_d - outBeg_d);
        if(outNb)
        {
                for(int k=0;k<outNb;k++)
                    output["per_d"].push_back(dOutputPrices[k]);
        }


}

void TAEngine::rvi(double *dHighPrice,double *dLowPrice,double *dOpenPrice,double *dClosePrice,size_t inputLength,map<string, vector<double> > & output,int maPeriod1,int maPeriod2 )
{
	vector<double> tmpValues;
    tmpValues.reserve( inputLength );
	double *noise = (double *) calloc( 1,sizeof(double)*inputLength );
	int outNb = 0, outBeg = 0, outputLength=0;
	TA_RetCode retCode;
	maPeriod1 = ( maPeriod1 > 0 ) ? maPeriod1 : 10;
	maPeriod2 = ( maPeriod2 > 0 ) ? maPeriod2 : 4;
	double dOutputPrices[1024*10] = {0}, dOutputPrices1[1024*10] = {0}; 
    for(size_t i=0;i<inputLength;i++) {
		double dCheckZero = ( *(dHighPrice+i) - *(dLowPrice+i) );
		if( dCheckZero == 0 ) {
			noise[i] = 0;
		} else {
			noise[i] = ( (*(dClosePrice+i) - *(dOpenPrice+i) ) / dCheckZero );
		}
	}
	retCode = TA_SMA( 0, inputLength - 1, noise, maPeriod1, &outBeg, &outNb, dOutputPrices );
	outputLength = outNb - outBeg;
    if(outputLength) {
		for(int i=0;i<outputLength;i++)
			output["RVI"].push_back(dOutputPrices[i]);
	}	
	outBeg = outNb = 0;
	retCode = TA_SMA(0,outputLength - 1, dOutputPrices, maPeriod2, &outBeg, &outNb, dOutputPrices1);
	outputLength = outNb - outBeg;
	if(outputLength) {
		for(int i=0;i<outputLength;i++)
	 		output["RVISignal"].push_back(dOutputPrices1[i]);
	}
	free(noise);           
}

void TAEngine::market_facilitation_index(double *dHighPrice,double *dLowPrice,uint32_t *volume,size_t inputLength,map<string, vector<double> > & output)
{
        //http://www.forexonlinelearning.com/market-facilitation-index/
        vector<double>mfi_values;
        mfi_values.reserve(inputLength);
        for(size_t i=0;i<inputLength;i++) {
		if ( (*(volume+i)) == 0 )
			mfi_values.push_back(0);
		else 
	        	mfi_values.push_back( (*(dHighPrice+i) - *(dLowPrice+i) ) / *(volume+i) );
	}
        output.insert( make_pair("BWMFI",mfi_values));
}


bool TAEngine::force_index(double *dInputPrices,uint32_t *volume,size_t inputLength,map<string, vector<double> > & output,int  maPeriod)
{
      //http://stockcharts.com/school/doku.php?id=chart_school:technical_indicators:force_index#introduction
      double dOutputPrices[1024*10];
     // memset(&dOutputPrices,0,inputLength);
      dOutputPrices[0]=0;
      vector<double>tmpValues;
      double *force = (double *) calloc(1,sizeof(double)*inputLength);
      tmpValues.reserve( inputLength );
      TA_RetCode retCode;
      int outNb = 0, outBeg = 0;
      maPeriod = maPeriod < 1 ? 13 : maPeriod ;
      for(size_t i=1,j=0;i<inputLength;i++,j++)
      {
        *(force+j) = ( *(dInputPrices+i) - *(dInputPrices+j) ) * (*(volume+i));
      }
      retCode = TA_EMA(0, inputLength - 2,force, maPeriod, &outBeg, &outNb, dOutputPrices);
      if( outNb =abs(outNb - outBeg) ) {
               int i;
               for( i = 0; i < outNb; i++)
                        tmpValues.push_back( *(dOutputPrices + i));
                output.insert(make_pair("FORCE", tmpValues));
                cout << "size = " << output.size() << ", entries = " << tmpValues.size() << endl;
       }
       free(force);	
       return (outNb > 0);

}

bool TAEngine::bears_power(uint32_t iIndicatorType, double *dInputPrices,double *dLowprice , size_t inputLength, map<string, vector<double> > & output, int maPeriod)
{
     //http://www.forex4you.com/metatrader/forex-indicators/bears-power/
      double dOutputPrices[1024*10];
      //memset(&dOutputPrices, 0, inputLength); 
      dOutputPrices[0] = 0;
      vector<double>tmpValues;
      tmpValues.reserve( inputLength );
      TA_RetCode retCode;
      int  outNb = 0,outBeg=0;
       maPeriod = (maPeriod < 1) ? 13 : maPeriod;
       retCode = TA_EMA(0, inputLength - 1, dInputPrices, maPeriod, &outBeg, &outNb, dOutputPrices);
       if( outNb = abs(outNb - outBeg)  ) {
               int i,j = inputLength - outNb;
               for( i = 0; i < outNb; i++, j++)
                        tmpValues.push_back( (*(dLowprice + j )) - (*(dOutputPrices + i)));
                output.insert(make_pair("BEARS", tmpValues));
                cout << "size = " << output.size() << ", entries = " << tmpValues.size() << endl;
       }
       return (outNb > 0);

}


bool TAEngine::bulls_power(uint32_t iIndicatorType, double *dInputPrices,double *dHighprice , size_t inputLength, map<string, vector<double> > & output, int maPeriod)
{
     //http://www.forex4you.com/metatrader/forex-indicators/bulls-power/
      double dOutputPrices[1024*10];
     // memset(&dOutputPrices, 0, inputLength);
      dOutputPrices[0] = 0;
      vector<double>tmpValues;
      tmpValues.reserve( inputLength );
      TA_RetCode retCode;
      int  outNb = 0,outBeg=0;
      maPeriod = (maPeriod < 1) ? 13 : maPeriod;
      retCode = TA_EMA(0, inputLength - 1, dInputPrices, maPeriod, &outBeg, &outNb, dOutputPrices);
      if( outNb =abs(outNb - outBeg) ) {
               int i,j = inputLength - outNb;
               for( i = 0; i < outNb; i++, j++)
                        tmpValues.push_back( (*(dHighprice + j )) - (*(dOutputPrices + i)));
                output.insert(make_pair("BULLR", tmpValues));
                cout << "size = " << output.size() << ", entries = " << tmpValues.size() << endl;
       }
       return (outNb > 0);

}


bool TAEngine::dem(uint32_t iIndicatorType, double *dHighPrices,double *dLowPrice, size_t inputLength, map<string, vector<double> > & output, int maPeriod)
{
    //http://ta.mql4.com/indicators/oscillators/DeMarker
             double dOutputPrices[1024*10] , dOutputPrices1[1024*10];
              dOutputPrices[0]=dOutputPrices1[0]=0;
             double *DeMax,*DeMin;
             vector<double>tmpValues;
             tmpValues.reserve( inputLength );
             size_t inp_len = inputLength-1;
             DeMax = (double *) calloc(1, sizeof(double)*inp_len);
             DeMin = (double *) calloc(1, sizeof(double)*inp_len);
             find_DeMax_DeMin(dHighPrices,dLowPrice,DeMax,DeMin,inp_len);
             TA_RetCode retCode;
             int  outNb = 0,outBeg=0,outNb1;
             maPeriod = maPeriod < 1 ? DEFAULT_MA_PERIOD : maPeriod;
             retCode = TA_SMA(0, inp_len-1, DeMax, maPeriod, &outBeg, &outNb, dOutputPrices);
             outNb1 = abs(outNb - outBeg);
             outNb=outBeg=0;
             retCode = TA_SMA(0, inp_len-1, DeMin, maPeriod, &outBeg, &outNb, dOutputPrices1);
             outNb = abs(outNb - outBeg);
            if (outNb > outNb1)
                  outNb = outNb1;
             if(outNb)
             {
                 for(int i=0;i<outNb;i++)
                                      tmpValues.push_back((*(dOutputPrices+i)) / ((*(dOutputPrices+i)) + (*(dOutputPrices1+i)) ));
                 output.insert(make_pair("DEM", tmpValues));
                 cout << "size = " << output.size() << ", entries = " << tmpValues.size() << endl;
             }
	     free(DeMax);
	     free(DeMin);
              return (outNb > 0);
}

void TAEngine::find_DeMax_DeMin(double *dHighPrices,double *dLowPrice,double *DeMax,double *DeMin,size_t inp_len)
{
     size_t i=1,j=0;
     while(i < inp_len)
     {
            *(DeMax+j) =  *(dHighPrices + i) > *(dHighPrices + j) ? *(dHighPrices + i) - *(dHighPrices + j)  :0 ;
            *(DeMin+j) = *(dLowPrice +i) < *(dLowPrice +j)  ?  *(dLowPrice + j) - *(dLowPrice + i)  : 0;
            j = i++;
     }
}


void TAEngine::adaptive_rsi(double *dClosePrice,size_t inputLength,map<string, vector<double> > & output,int maPeriod)
{
        //http://help.sspro.schwab.com/4.18/HELPFILE.htm#Chart_Studies.htm
        //http://www.fxcodebase.com/code/viewtopic.php?f=31&t=5119
        cout<<"\n-------------------\n\n\n";
        cout<<"---ADAPTIVE RSI called--------"<<endl;
        double dOutputPrices[1024*10];
     // memset(&dOutputPrices,0,inputLength);
        dOutputPrices[0]=0;
        double sc;
        double *arsi = (double *) malloc(sizeof(double)*inputLength);
        vector<double>tmpValues;
        double *force = (double *) calloc(1,sizeof(double)*inputLength);
        tmpValues.reserve( inputLength );
        TA_RetCode retCode;
        int outNb = 0, outBeg = 0;
        maPeriod = maPeriod < 1 ? 14 : maPeriod ;
        retCode = TA_RSI(0, inputLength - 1,dClosePrice, maPeriod, &outBeg, &outNb, dOutputPrices);
        int i,j=inputLength - outNb;
        for(i=0;i<j ; i++)
                arsi[i]= dClosePrice[i];

        for(j=0;i<inputLength;i++,j++)
        {
                sc = (dOutputPrices[j] / 100 - 0.5) * 2;
                output["ARSI"].push_back(arsi[i] = arsi[i-1] + sc *( (*(dClosePrice+i)) - arsi[i-1]));
        }
        free(force);
	free(arsi);
       
}


bool TAEngine::moving_averages(uint32_t iIndicatorType, double *dInputPrices, size_t inputLength, map<string, vector<double> > & output, int maPeriod)
{
	string sIndicatorName;
	vector<double>tmpValues;
	tmpValues.reserve( inputLength );
//	double *dOutputPrices = (double *)calloc(1, sizeof(inputLength) * sizeof(double));
	double dOutputPrices[1024*10];
	memset(&dOutputPrices, 0, inputLength);
	int outBeg = 0, outNb = 0, outputLength = 0;
	maPeriod = (maPeriod < 1) ? DEFAULT_MA_PERIOD : maPeriod;
	TA_RetCode retCode;
	if( iIndicatorType == TAEngine_SMA ) {
		retCode = TA_SMA(0, inputLength - 1, dInputPrices, maPeriod, &outBeg, &outNb, dOutputPrices);
		outputLength = outNb - outBeg;
		sIndicatorName = "SMA";
		cout << "Indicator Name = " << sIndicatorName << ", retCode = " << retCode << endl;
	} else if( iIndicatorType == TAEngine_EMA ) {
		retCode = TA_EMA(0, inputLength - 1, dInputPrices, maPeriod, &outBeg, &outNb, dOutputPrices);
		sIndicatorName = "EMA";
		outputLength = outNb;
	} else if( iIndicatorType == TAEngine_KAMA ) {
		retCode = TA_KAMA(0, inputLength - 1, dInputPrices, maPeriod, &outBeg, &outNb, dOutputPrices);
		sIndicatorName = "KAMA";
		outputLength = outNb;
	} else if( iIndicatorType == TAEngine_TRIMA ) {
		retCode = TA_TRIMA(0, inputLength - 1, dInputPrices, maPeriod, &outBeg, &outNb, dOutputPrices);
		sIndicatorName = "TRIMA";
		outputLength = outNb;
	} else if( iIndicatorType == TAEngine_WMA ) {
		sIndicatorName = "WMA";
		retCode = TA_WMA(0, inputLength - 1, dInputPrices, maPeriod, &outBeg, &outNb, dOutputPrices);
		outputLength = outNb;
	} else if( iIndicatorType == TAEngine_DOUBLE_EMA ) {
		sIndicatorName = "DEMA";
		retCode = TA_DEMA(0, inputLength - 1, dInputPrices, maPeriod, &outBeg, &outNb, dOutputPrices);
		outputLength = outNb;
	} else if( iIndicatorType == TAEngine_TRIPLE_EMA ) {
		sIndicatorName = "TEMA";
		retCode = TA_TEMA(0, inputLength - 1, dInputPrices, maPeriod, &outBeg, &outNb, dOutputPrices);
		outputLength = outNb;
	} else if( iIndicatorType == TAEngine_RSI ) {
		sIndicatorName = "RSI";
		retCode = TA_RSI(0, inputLength - 1, dInputPrices, maPeriod, &outBeg, &outNb, dOutputPrices);
		outputLength = outNb;
	} else if( iIndicatorType == TAEngine_T3 ) {
		sIndicatorName = "T3";
		retCode = TA_T3(0, inputLength - 1, dInputPrices, maPeriod, TA_REAL_DEFAULT, &outBeg, &outNb, dOutputPrices);
		outputLength = outNb;
	} else if( iIndicatorType == TAEngine_MOM ) {
		sIndicatorName = "MOM";
		retCode = TA_MOM(0, inputLength - 1, dInputPrices, maPeriod, &outBeg, &outNb, dOutputPrices);
		outputLength = outNb;
	} else if( iIndicatorType == TAEngine_TRIX ) {
		sIndicatorName = "TRIX";
		retCode = TA_TRIX(0, inputLength - 1, dInputPrices, maPeriod, &outBeg, &outNb, dOutputPrices);
		outputLength = outNb;
	} else if( iIndicatorType == TAEngine_RSI ) {
		sIndicatorName = "RSI";
		retCode = TA_RSI(0, inputLength - 1, dInputPrices, maPeriod, &outBeg, &outNb, dOutputPrices);
		outputLength = outNb;
	} else if( iIndicatorType == TAEngine_ROC ) {
		sIndicatorName = "ROC";
		retCode = TA_ROC(0, inputLength - 1, dInputPrices, maPeriod, &outBeg, &outNb, dOutputPrices);
		outputLength = outNb;
	} else if( iIndicatorType == TAEngine_WILDER_MA ) {
		sIndicatorName = "WWMA";
		double init_ma = 0;
		int iterator = 0, opIterator = 0;
		for(; iterator < maPeriod; iterator++) {
			init_ma += *(dInputPrices + iterator);
		}
		init_ma /= maPeriod;
		*(dOutputPrices + opIterator) = init_ma;
		opIterator++;
		for( ; iterator < (int)inputLength; iterator++ ) {
			init_ma = ((init_ma * (maPeriod - 1)) + *(dInputPrices + iterator))/maPeriod;
			*(dOutputPrices + opIterator) = init_ma;
			opIterator++;
		}
		outputLength = opIterator;
		outBeg = 0; outNb = outputLength;
	} else if( iIndicatorType == TAEngine_SINE_MA ) {
		sIndicatorName = "SWMA";
		const double thetaC = M_PI/(maPeriod + 2);
		double swmaNum = 0, swmaDenom = 0, thetaValue = 0;
		int iterator = 0, opIterator = 0;
		for( ; iterator < maPeriod; iterator++) {
			thetaValue = iterator * thetaC;
			swmaNum += *(dInputPrices + iterator) * sin(thetaValue);
			swmaDenom += sin(thetaValue);
		}
		*(dOutputPrices + opIterator) = swmaNum/swmaDenom;
		opIterator++;
		for( ; iterator < (int)inputLength; iterator++) {
			thetaValue = (iterator - maPeriod)*thetaC;
			swmaNum -= ( (*(dInputPrices + (iterator - maPeriod))) * sin(thetaValue) );
			swmaDenom -= sin(thetaValue);

			cout << __LINE__ << ": swmaNum = " << swmaNum << ", swmaDenom = " << swmaDenom << ", opIterator = " << opIterator << ", thetaValue = " << thetaValue << endl;
			thetaValue = iterator * thetaC;
			swmaNum += ((*(dInputPrices + iterator)) * sin(thetaValue));
			swmaDenom += sin(thetaValue);

			cout << __LINE__ << ": swmaNum = " << swmaNum << ", swmaDenom = " << swmaDenom << ", opIterator = " << opIterator << ", thetaValue = " << thetaValue << endl;
			*(dOutputPrices + opIterator) = swmaNum/swmaDenom;
			opIterator++;
		}
		outputLength = opIterator;
		outBeg = 0; outNb = outputLength;
	} else {
		cout << "Moving average not implemented." << endl;
	}
	outputLength = abs(outputLength);
	outBeg = 0;
	cout << "outNb = " << outNb << ", outBEg = " << outBeg << endl;
	cout << __LINE__ << " outputLength = " << outputLength << ", sIndicatorName = " << sIndicatorName << endl;
	if( outputLength > 0 ) {
		for(int i = 0, j = 0; i < outNb; i++, j++) {
			double dValue = *(dOutputPrices + i);
			printf("%f\n", dValue );
			tmpValues.push_back(dValue);
		}
		output.insert(make_pair(string(sIndicatorName), tmpValues));
		cout << "size = " << output.size() << ", entries = " << tmpValues.size() << endl;
//		free(dOutputPrices);
	}
	return (outputLength > 0);
}

void TAEngine::avg_directional_movt(double *dHighPrice, double *dLowPrice, double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output)
{
	double dOutputPrice[4096] = {0};
	int outBeg = 0, outNb = 0;

	TA_ADX(0, inputLength - 1, dHighPrice, dLowPrice, dClosePrice, maPeriod, &outBeg, &outNb, dOutputPrice);
	for(int i = 0; i < outNb; i++) {
		output["ADX"].push_back( *(dOutputPrice + i) );
	}
}

void TAEngine::accumulation_distribution_index(double *dHighPrice, double *dLowPrice, double *dClosePrice, uint32_t *lVolume, size_t inputLength, map<string, vector<double> > & output)
{
	double dOutputPrice[4096] = {'\0'};
	double dVolume[4096] = {'\0'};
	for(int i = 0; i < (int)inputLength; i++) {
		dVolume[i] = (double )(*(lVolume + i) * 1.0);
	}
	int outBeg = 0, outNb = 0;

	TA_AD(0, inputLength - 1, dHighPrice, dLowPrice, dClosePrice, dVolume, &outBeg, &outNb, dOutputPrice);
	for(int i = 0; i < outNb; i++) {
		output["AD"].push_back( *(dOutputPrice + i) );
	}
}

void TAEngine::ad_osc(double *dHighPrice, double *dLowPrice, double *dClosePrice, uint32_t *lVolume, size_t inputLength, int iFastPeriod, int iSlowPeriod, map<string, vector<double> > & output)
{
	double dOutputPrice[4096] = {'\0'};
	double dVolume[4096] = {'\0'};
	for(int i = 0; i < (int)inputLength; i++) {
		dVolume[i] = 0;
		*(dVolume + i) = (double )(*(lVolume + i) * 1.0);
	}
	int outBeg = 0, outNb = 0;
	TA_ADOSC(0, inputLength - 1, dHighPrice, dLowPrice, dClosePrice, dVolume, iFastPeriod, iSlowPeriod, &outBeg, &outNb, dOutputPrice);
	cout << "ad_osc: outBeg = " << outBeg << ", outNb = " << outNb << endl;
	for(int i = 0; i < outNb; i++) {
		output["ADOSC"].push_back( *(dOutputPrice + i) );
	}
}

void TAEngine::aroon(double *dHighPrice, double *dLowPrice, size_t inputLength, int maPeriod,  map<string, vector<double> > & output)
{
	double dAroonUp[4096] = {0};
	double dAroonDown[4096] = {0};
	int outBeg = 0, outNb = 0;
	TA_AROON(0, inputLength - 1, dHighPrice, dLowPrice, maPeriod, &outBeg, &outNb, dAroonUp, dAroonDown);
	for(int i = 0; i < outNb; i++) {
		output["aroon_up"].push_back( *(dAroonUp + i) );
		output["aroon_down"].push_back( *(dAroonDown + i) );
	}
}

void TAEngine::getIndicators(vector<string>vIndicatorList, TechnicalIndicatorListResponse & tilResponse)
{
	if( vIndicatorList.size() > 0 ) {
		vector<string>::iterator iIndicator = vIndicatorList.begin();
		while( iIndicator != vIndicatorList.end() ) {
			map<string, string>::iterator iCache;
			if( supportedIndicators.isCached( *iIndicator, iCache ) ) {
				tilResponse.addIndicator( iCache->second );
			}
			iIndicator++;
		}
	} else {
		map<string, string>::iterator iCache;
		for(iCache = supportedIndicators.begin(); iCache != supportedIndicators.end(); iCache++) {
			tilResponse.addIndicator( iCache->second );
		}
	}
}

void TAEngine::envelope(string sEnvelopeName, map<string, vector<double> >input, map<string, vector<double> > & output, double dEnvelopePercentage)
{
	map<string, vector<double> >::iterator iInput = input.begin();
	string sEnvelopeUpper = sEnvelopeName, sEnvelopeLower = sEnvelopeName;
	sEnvelopeUpper.append("_ENVELOPE_UPPER");
	sEnvelopeLower.append("_ENVELOPE_LOWER");
	vector<double>::iterator iValue;
	if( dEnvelopePercentage == 0 )
		dEnvelopePercentage = 10.0;
	if( dEnvelopePercentage == 100 )
		dEnvelopePercentage = 10.0;
	for(iValue = iInput->second.begin(); iValue != iInput->second.end(); iValue++) {
		double dEnvelopeValue = *iValue * dEnvelopePercentage/100.0;
		double dEnvelopeUpper = *iValue + dEnvelopeValue;
		double dEnvelopeLower = *iValue - dEnvelopeValue;
		output[sEnvelopeName].push_back( *iValue );
		output[sEnvelopeUpper].push_back( dEnvelopeUpper );
		output[sEnvelopeLower].push_back( dEnvelopeLower );
	}
}

void TAEngine::price_channel(double *dHighPrice, double *dLowPrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output)
{
	vector<double>vHigh, vLow;
	int i = 0;
	double dMax, dMin;
	for( ; i < maPeriod; i++) {
		double dHigh = *(dHighPrice + i);
		double dLow = *(dLowPrice + i);
		vHigh.push_back( dHigh );
		vLow.push_back( dLow );
	}
	cout << "vHigh = " << vHigh.size() << endl;
	cout << "vLow = " << vLow.size() << endl;
	string sHighChannel = "HIGH_CHANNEL";
	string sLowChannel = "LOW_CHANNEL";
	dMax = *(max_element(vHigh.begin(), vHigh.end()));
	dMin = *(min_element(vLow.begin(), vLow.end()));
	cout << "dMax = " << dMax << ", dMin = " << dMin << endl;
	output[sHighChannel].push_back( dMax );
	output[sLowChannel].push_back( dMin );
	for( ; i < (int)inputLength; i++) {
		double dHigh = *(dHighPrice + i);
		double dLow = *(dLowPrice + i);
		vHigh.erase( vHigh.begin() );
		vLow.erase( vLow.begin() );
		vHigh.push_back( dHigh );
		vLow.push_back( dLow );
		dMax = *(max_element(vHigh.begin(), vHigh.end()));
		dMin = *(min_element(vLow.begin(), vLow.end()));
		cout << "dMax = " << dMax << ", dMin = " << dMin << endl;
		output[sHighChannel].push_back( dMax );
		output[sLowChannel].push_back( dMin );
	}
}

void TAEngine::stddev(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > &output)
{
	int outBeg = 0, outNb = 0;
	double dOutput[4096] = {'\0'};
	TA_STDDEV(0, inputLength - 1, dClosePrice, maPeriod, 2.0, &outBeg, &outNb, dOutput);
	for(int i = 0; i < outNb; i++) {
		output["STDDEV"].push_back( dOutput[i] );
	}
}

void TAEngine::pivot_point(double *dHighPrice, double *dLowPrice, vector<double>input, map<string, vector<double> > & output)
{
	string sResistance1 = "RESISTANCE1", sResistance2 = "RESISTANCE2", sSupport1 = "SUPPORT1", sSupport2 = "SUPPORT2", sPivot = "PIVOT_POINT";
	for(size_t i = 0; i < input.size(); i++) {
		double dRange = *(dHighPrice + i) - *(dLowPrice + i);
		double resistance1 = (2.0 * input[i]) - *(dLowPrice + i);
		double resistance2 = input[i] + dRange;
		double support1 = (2.0 * input[i]) - *(dHighPrice + i);
		double support2 = input[i] - dRange;

		output[sResistance1].push_back( resistance1 );
		output[sResistance2].push_back( resistance2 );
		output[sSupport1].push_back( support1 );
		output[sSupport2].push_back( support2 );
		output[sPivot].push_back( input[i] );
	}
}

void TAEngine::buying_pressure(double *dClosePrice, double *dLowPrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output)
{
	vector<double>vLows;
	int i = 0;
	for(; i < maPeriod; i++)
		vLows.push_back( *(dLowPrice + i) );

	string sBuyp = "BUYP";
	vector<double>vBuyp;
	double dTrueLow = *(vLows.end() - 1) - *(dClosePrice + i - 2);
	double dBuyp = *(dClosePrice + i - 1) - dTrueLow;
	cout << "TrueLow = " << dTrueLow << ", dBuyp = " << dBuyp << ", vLows.end() = " << *(vLows.end() - 1) << ", dClose = " << *(dClosePrice + i - 2) << endl;
	vBuyp.push_back( dBuyp );
	for( ; i < (int)inputLength; i++) {
		vLows.erase( vLows.begin() );
		vLows.push_back( *(dLowPrice + i) );
		double dTrueLow = *( vLows.end() - 1 ) - *(dClosePrice + i - 1);
		double dBuyp = *(dClosePrice + i ) - dTrueLow;
		cout << "TrueLow = " << dTrueLow << ", dBuyp = " << dBuyp << ", vLows.end() = " << *(vLows.end() - 1) << ", dClose = " << *(dClosePrice + i - 1) << endl;
		vBuyp.push_back( dBuyp );
	}
	cout << "vBuyp = " << vBuyp.size() << endl;
	output.insert(make_pair(sBuyp, vBuyp));
}

void TAEngine::gann_hi_lo_activator(double *dClosePrice, double *dHighPrice, double *dLowPrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output)
{
	size_t i = 0;
	bool bActivator = false;
	double dGannHiLow;
	vector<double> tmp;
	map<string, vector<double> >smaHigh, smaLow;
	moving_averages(TAEngine_SMA, dHighPrice, inputLength, smaHigh, maPeriod);
	moving_averages(TAEngine_SMA, dLowPrice, inputLength, smaLow, maPeriod);

	i = inputLength - smaHigh[TAEngine_INDICATOR_SMA].size();
	cout << smaHigh[TAEngine_INDICATOR_SMA].size() << ", " <<  smaLow[TAEngine_INDICATOR_SMA].size() << ", " << i << endl;

	for(int j = 0 ; i < inputLength; i++, j++ ) {
		double dHighAverage = smaHigh[TAEngine_INDICATOR_SMA][j];
		double dLowAverage = smaLow[TAEngine_INDICATOR_SMA][j];
		if( bActivator ) {
			if( *(dClosePrice + i) > dHighAverage ) {
				bActivator = false;
				dGannHiLow = dLowAverage;
			} else {
				dGannHiLow = dHighAverage;
			}
		} else {
			if( *(dClosePrice + i) < dLowAverage ) {
				bActivator = true;
				dGannHiLow = dHighAverage;
			} else {
				dGannHiLow = dLowAverage;
			}
		}
		tmp.push_back( dGannHiLow );
	}
	output.insert( make_pair(TAEngine_INDICATOR_GANN_HI_LO_ACTIVATOR, tmp) );
}

void TAEngine::volume_average(string sIndicatorName, uint32_t *lVolume, size_t inputLength, int maPeriod, map<string, vector<double> > & output)
{
	double dVolume[4096] = {'\0'};
	for(size_t i = 0; i < inputLength; i++) {
		dVolume[i] = (*(lVolume + i) * 1.0);
	}
	if( sIndicatorName == TAEngine_INDICATOR_VEMA ) {
		moving_averages(TAEngine_EMA, dVolume, inputLength, output, maPeriod);
		output[TAEngine_INDICATOR_VEMA] = output[TAEngine_INDICATOR_EMA];
		output.erase( output.find(TAEngine_INDICATOR_EMA) );
	} else if( sIndicatorName == TAEngine_INDICATOR_VSMA ) {
		moving_averages(TAEngine_SMA, dVolume, inputLength, output, maPeriod);
		output[TAEngine_INDICATOR_VSMA] = output[TAEngine_INDICATOR_SMA];
		output.erase( output.find(TAEngine_INDICATOR_SMA) );
	}
}

void TAEngine::alligator(double *dHighPrice, double *dLowPrice, size_t inputLength, map<string, vector<double> > & output)
{
	map<string,vector<double> > jawSMMA, teethSMMA, lipsSMMA;
	double dInput[4096] = {'\0'};

	for(size_t i = 0; i < inputLength; i++) {
		dInput[i] = ( *(dHighPrice + i) + *(dLowPrice + i) ) / 2;
	}

	smoothed_moving_average( dInput, inputLength, 13, jawSMMA );
	smoothed_moving_average( dInput, inputLength, 8, teethSMMA );
	smoothed_moving_average( dInput, inputLength, 5, lipsSMMA );

	size_t jawSize = jawSMMA["SMMA"].size();
	size_t teethSize = teethSMMA["SMMA"].size();
	size_t lipsSize = lipsSMMA["SMMA"].size();

	for(size_t i = 7; i < jawSize; i++)
		output["JAWS"].push_back(jawSMMA["SMMA"][i]);
	for(size_t i = 4; i < teethSize; i++)
		output["TEETH"].push_back(teethSMMA["SMMA"][i]);
	for(size_t i = 2; i < lipsSize; i++)
		output["LIPS"].push_back(lipsSMMA["SMMA"][i]);
}

void TAEngine::ao(double *dHighPrice, double *dLowPrice, size_t inputLength, int maPeriod1, int maPeriod2, map<string, vector<double> > & output)
{
// http://ta.mql4.com/indicators/bills/awesome
	map<string, vector<double> > sma5, sma34;
	double dMedianPrice[4096] = {'\0'};
	for(size_t i = 0; i < inputLength; i++) {
		dMedianPrice[i] = ( *(dHighPrice + i) + *(dLowPrice + i) ) / 2;
	}

	moving_averages(TAEngine_SMA, dMedianPrice, inputLength, sma5, maPeriod1);
	moving_averages(TAEngine_SMA, dMedianPrice, inputLength, sma34, maPeriod2);

	size_t sma5OutputSize = sma5["SMA"].size();
	size_t sma34OutputSize = sma34["SMA"].size();

	cout << "sma5OutputSize " << sma5OutputSize << endl;
	cout << "sma34OutputSize " << sma34OutputSize << endl;
	size_t minSize = (sma5OutputSize <= sma34OutputSize) ? sma5OutputSize : sma34OutputSize;
	for(size_t i = 0; i < minSize; i++) {
		double element = sma5["SMA"][i] - sma34["SMA"][i];
		output["AO"].push_back(element);
	}
}

void TAEngine::ac(double *dHighPrice, double *dLowPrice, size_t inputLength, int maPeriod1, int maPeriod2, int maPeriod3, map<string, vector<double> > & output)
{
// http://ta.mql4.com/indicators/bills/acceleration_deceleration
	map<string, vector<double> > sma5, awesome;
	ao(dHighPrice, dLowPrice, inputLength, maPeriod1, maPeriod2, awesome);
	double dMedianPrice[4096] = {'\0'};
	for(size_t i = 0; i < awesome["AO"].size(); i++)
		dMedianPrice[i] = awesome["AO"][i];
	moving_averages(TAEngine_SMA, dMedianPrice, inputLength, sma5, maPeriod3);
	size_t awesomeSize = awesome["AO"].size();
	size_t sma5OutputSize = sma5["SMA"].size();
	size_t minSize = (awesomeSize <= sma5OutputSize) ? awesomeSize : sma5OutputSize;
	for(size_t i = 0; i < minSize; i++) {
		double element = awesome["AO"][i] - sma5["SMA"][i];
		output["AC"].push_back(element);
	}
}

void TAEngine::ha(double *dOpenPrice, double *dHighPrice, double *dLowPrice, double *dClosePrice, size_t inputLength, map<string, vector<double> > & output)
{
// http://www.investopedia.com/articles/technical/04/092204.asp#axzz1VwxMZLtw
	vector<double> ha_open, ha_high, ha_low, ha_close;
	ha_open.push_back( (*(dOpenPrice) + *(dClosePrice)) / 2 );
	for(size_t i = 0; i < inputLength; i++) {
		double element = ( *(dOpenPrice + i) + *(dHighPrice + i) + *(dLowPrice + i) + *(dClosePrice + i) ) / 4;
		ha_close.push_back(element);
	}
	for(size_t i = 1; i < inputLength; i++) {
		double element = (ha_open[i - 1] + *(dClosePrice + (i-1))) / 2;
		ha_open.push_back(element);
	}
	for(size_t i = 0; i < inputLength; i++) {
		double a = *(dHighPrice + i); double b = ha_open[i]; double c = ha_close[i]; double d = *(dLowPrice + i);
		double max = (a>=b)?((a>=c)?a:c):(c>=b)?c:b;
		double min = (d<=b)?((d<=c)?d:c):(c<=b)?c:b;
		ha_high.push_back( max );
		ha_low.push_back( min );
	}
	output["HA_OPEN"] = ha_open;
	output["HA_CLOSE"] = ha_close;
	output["HA_HIGH"] = ha_high;
	output["HA_LOW"] = ha_low;
}

void TAEngine::ichimoku(double *dHighPrice, double *dLowPrice, double *dClosePrice, size_t inputLength, int maPeriod1, int maPeriod2, int maPeriod3, map<string, vector<double> > & output)
{
// http://fxtrade.oanda.com/learn/forex-indicators/ichimoku-kinko-hyo
	vector<double> tenkan_sen, kijun_sen, chikou_span, senkou_spanA, senkou_spanB;
	double maxHigh1 = 0, maxHigh2 = 0, maxHigh3 = 0, minLow1 = 0, minLow2 = 0, minLow3 = 0;
	int count = 0;
	for(int i = 0; i < maPeriod2; i++)
		chikou_span.push_back(0.0);
	for(size_t i = maPeriod1, k = maPeriod2, p = maPeriod3; i < inputLength; i++, k++, p++) {
		count++;
		for(size_t j = i - maPeriod1; j < i; j++) {
			if( *(dHighPrice + j) > maxHigh1 )
				maxHigh1 = *(dHighPrice + j);
			if( *(dLowPrice + j) < minLow1 )
				minLow1 = *(dLowPrice + j);
		}
		for(size_t l = k - maPeriod2; l < k; l++) {
			if( *(dHighPrice + l) > maxHigh2 )
				maxHigh2 = *(dHighPrice + l);
			if( *(dLowPrice + l) < minLow2 )
				minLow2 = *(dLowPrice + l);
		}
		for(size_t q = p - maPeriod3; q < p; q++) {
			if( *(dHighPrice + q) > maxHigh3 )
				maxHigh3 = *(dHighPrice + q);
			if( *(dLowPrice + q) < minLow3 )
				minLow3 = *(dLowPrice + q);
		}
		double element = (maxHigh1 + minLow1) / 2;
		tenkan_sen.push_back( element );
		double element1 = (maxHigh2 + minLow2) / 2;
		kijun_sen.push_back( element1 );
		double element2 = *(dClosePrice + (k - maPeriod2));
		chikou_span.push_back( element2 );
		if( count > maPeriod2 ) {
			double element3 = (maxHigh3 + minLow3) / 2;
			senkou_spanB.push_back(element3);
		}
	}
	size_t tenkanSize = tenkan_sen.size(); size_t kijunSize = kijun_sen.size();
	size_t minSize = (tenkanSize <= kijunSize)? tenkanSize : kijunSize;
	for(size_t i = maPeriod2; i < minSize; i++) {
		double element = (tenkan_sen[i] + kijun_sen[i]) / 2;
		senkou_spanA.push_back( element );
	}
	output["TENKAN_SEN"] = tenkan_sen;
	output["KIJUN_SEN"] = kijun_sen;
	output["CHIKOU_SPAN"] = chikou_span;
	output["SENKOU_SPAN_A"] = senkou_spanA;
	output["SENKOU_SPAN_B"] = senkou_spanB;
}

void TAEngine::vidya(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output)
{
// http://www.fmlabs.com/reference/default.htm?url=VIDYA.htm
	vector<double> vidya_output;
	map<string, vector<double> > cmo;

	chande_momentum_oscillator(dClosePrice, inputLength, maPeriod, cmo);

	double smoothing_constant = 2.0 / ((double)maPeriod + 1.0);
	vidya_output.push_back(cmo["CMO"][0]);
	cout << "smoothing_constant " << smoothing_constant << endl;
	for(size_t i = 1; i < inputLength; i++) {
		double element = (*(dClosePrice + i) * smoothing_constant * cmo["CMO"][i]) + (1.0 - (smoothing_constant * cmo["CMO"][i])) * *(dClosePrice + (i - 1));
		vidya_output.push_back( element );
	}
	output["VIDYA"] = vidya_output; 
}

void TAEngine::ewo(double *dHighPrice, double *dLowPrice, size_t inputLength, map<string, vector<double> > & output)
{
	map<string, vector<double> > sma5, sma35;
	double dMedianPrice[4096] = {'\0'};
	for(size_t i = 0; i < inputLength; i++) {
		dMedianPrice[i] = ( *(dHighPrice + i) + *(dLowPrice + i) ) / 2;
	}

	moving_averages(TAEngine_SMA, dMedianPrice, inputLength, sma5, 5);
	moving_averages(TAEngine_SMA, dMedianPrice, inputLength, sma35, 35);

	size_t sma5OutputSize = sma5["SMA"].size();
	size_t sma35OutputSize = sma35["SMA"].size();

	cout << "sma5OutputSize " << sma5OutputSize << endl;
	cout << "sma35OutputSize " << sma35OutputSize << endl;
	size_t minSize = (sma5OutputSize <= sma35OutputSize) ? sma5OutputSize : sma35OutputSize;
	for(size_t i = 0; i < minSize; i++) {
		double element = sma5["SMA"][i] - sma35["SMA"][i];
		output["EWO"].push_back(element);
	}
}

void TAEngine::mcginley(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output)
{
	vector<double> md_output;
	map<string, vector<double> >ema;
	moving_averages(TAEngine_EMA, dClosePrice, inputLength, ema, maPeriod);
	md_output.push_back(ema["EMA"][0]);
	for(size_t i = 1; i < inputLength; i++) {
		double element = md_output[i - 1] + ( *(dClosePrice + i) - md_output[i - 1] ) / ( maPeriod * pow((*(dClosePrice + i) / md_output[i - 1]), 4));
		md_output.push_back( element );
	}
	output["MD"] = md_output;
}

void TAEngine::gator_osc(double *dHighPrice, double *dLowPrice, size_t inputLength, map<string, vector<double> > & output)
{
	map<string, vector<double> > alligator_output;
	alligator(dHighPrice, dLowPrice, inputLength, alligator_output);

	size_t jawSize = alligator_output["JAWS"].size();
	size_t teethSize = alligator_output["TEETH"].size();
	size_t lipsSize = alligator_output["LIPS"].size();

	cout << "jawSize " << jawSize << ", teethSize " << teethSize << ", lipsSize " << lipsSize << endl;
	size_t min = (jawSize <= teethSize)?((jawSize <= lipsSize)?jawSize:lipsSize):(lipsSize <= teethSize)?lipsSize:teethSize;
	cout << "min is " << min << endl;

	for(size_t i = 0; i < min; i++) {
		double up_element = alligator_output["JAWS"][i] - alligator_output["TEETH"][i];
		if(up_element < 0)
			up_element = 0.0 - up_element;
		double down_element = alligator_output["TEETH"][i] - alligator_output["LIPS"][i];
		if(down_element > 0)
			down_element = 0.0 - down_element;
		output["UP"].push_back(up_element);
		output["DN"].push_back(down_element);
	}
}

void TAEngine::osc(double *dClosePrice, size_t inputLength, int maPeriod1, int maPeriod2, map<string, vector<double> > & output)
{
	map<string, vector<double> >sma_short, sma_long;
	moving_averages(TAEngine_SMA, dClosePrice, inputLength, sma_short, maPeriod1);
	moving_averages(TAEngine_SMA, dClosePrice, inputLength, sma_long, maPeriod2);

	size_t sma_shortSize = sma_short["SMA"].size();
	size_t sma_longSize = sma_long["SMA"].size();

	size_t minSize = (sma_shortSize <= sma_longSize) ? sma_shortSize : sma_longSize;
//	while( sma_short["SMA"].size() > minSize)
//		sma_short["SMA"].erase(sma_short["SMA"].begin());
	for(size_t i = 0; i < minSize; i++) {
		double element = sma_long["SMA"][i] - sma_short["SMA"][i];
		output["OSC"].push_back(element);
	}
}

void TAEngine::cho(double *dHighPrice, double *dLowPrice, double *dClosePrice, uint32_t *lVolume, size_t inputLength, int maPeriod1, int maPeriod2, map<string, vector<double> > & output) 
{
// http://ta.mql4.com/indicators/oscillators/chaikin
	map<string, vector<double> >acc_dis, ema_short, ema_long;
	double dAccValues[4096] = {'\0'};

	accumulation_distribution_index(dHighPrice, dLowPrice, dClosePrice, lVolume, inputLength, acc_dis);
	for(size_t i = 0; i < acc_dis["AD"].size(); i++)
		dAccValues[i] = acc_dis["AD"][i];

	moving_averages(TAEngine_EMA, dAccValues, acc_dis["AD"].size(), ema_short, maPeriod1);
	moving_averages(TAEngine_EMA, dAccValues, acc_dis["AD"].size(), ema_long, maPeriod2);

	size_t ema_shortSize = ema_short["EMA"].size();
	size_t ema_longSize = ema_long["EMA"].size();

	size_t minSize = (ema_shortSize <= ema_longSize) ? ema_shortSize : ema_longSize;
	for(size_t i = 0; i < minSize; i++) {
		double element = ema_short["EMA"][i] - ema_long["EMA"][i];
		output["CHO"].push_back(element);
	}
}

void TAEngine::cmf(double *dHighPrice, double *dLowPrice, double *dClosePrice, uint32_t *lVolume, size_t inputLength, int maPeriod, map<string, vector<double> > & output) 
{
//http://www.fmlabs.com/reference/default.htm?url=ChaikinMoneyFlow.htm
	vector<double> clvVector;
	for(int i = 0; i < (int)inputLength; i++) {
		double clv = (( *(dClosePrice + i) - *(dLowPrice + i) ) - ( *(dHighPrice + i) - *(dClosePrice + i) )) / ( *(dHighPrice + i) - *(dLowPrice + i) );
		clvVector.push_back(clv);
		if(i >= maPeriod) {
			double dClvSum = 0.0, dVolumeSum = 0.0;
			for(int j = i - maPeriod; j < i; j++) {
				dClvSum += ( clvVector[j] * (double)lVolume[j] );
				dVolumeSum += (double)lVolume[j];
			}
			double element = dClvSum / dVolumeSum;
			output["CMF"].push_back(element);
		}
	}	
}	

void TAEngine::tsi(double *dClosePrice, size_t inputLength, int maPeriod1, int maPeriod2, map<string, vector<double> > & output)
{
	double dDifference[4096] = {'\0'}, dEma[4096] = {'\0'};
	double dDiff[4096] = {'\0'}, dAbsEma[4096] = {'\0'};
	map<string, vector<double> > ema1, ema2, ema_abs1, ema_abs2;

	size_t count = 0;
	for(size_t i = 1; i < inputLength; i++, count++) {
		dDifference[i - 1] = *(dClosePrice + i) - *(dClosePrice + (i-1));
		dDiff[i - 1] = fabs(*(dClosePrice + i) - *(dClosePrice + (i-1)));
	}
	moving_averages(TAEngine_EMA, dDifference, inputLength - 1, ema1, maPeriod2);
	size_t ema_size = ema1["EMA"].size();
	for(size_t i = 0; i < ema_size; i++) {
		dEma[i] = ema1["EMA"][i];
	}
	moving_averages(TAEngine_EMA, dEma, ema_size, ema2, maPeriod1);

	moving_averages(TAEngine_EMA, dDiff, inputLength - 1, ema_abs1, maPeriod2);
	size_t ema_abs_size = ema_abs1["EMA"].size();
	for(size_t i = 0; i < ema_abs_size; i++) {
		dAbsEma[i] = ema_abs1["EMA"][i];
	}
	moving_averages(TAEngine_EMA, dAbsEma, ema_abs_size, ema_abs2, maPeriod1);
	
	size_t ema2_size = ema2["EMA"].size();
	size_t minSize = (ema_size <= ema2_size) ? ema_size : ema2_size;
	for(size_t i = 0; i < minSize; i++) {
		double element = (ema2["EMA"][i] / ema_abs2["EMA"][i]) * 100;
		output["TSI"].push_back(element);
	}
}

void TAEngine::dmi(double *dHighPrice, double *dLowPrice, double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output)
{
	vector<double> plusDMSum, minusDMSum, dTR;
	plusDMSum.push_back(dClosePrice[0]);
	minusDMSum.push_back(dClosePrice[0]);
	dTR.push_back(dClosePrice[0]);

	for(size_t i = 1; i < inputLength; i++) {
		double dDeltaHigh = *(dHighPrice + (i - 1)) - *(dHighPrice + i);
		double dDeltaLow = *(dLowPrice + i) - *(dLowPrice + (i - 1));

		double dPlusDM, dMinusDM;
		if( ( (dDeltaHigh < 0) && (dDeltaLow < 0) ) || (dDeltaHigh == dDeltaLow) ) {
			dPlusDM = 0.0;
		   	dMinusDM = 0.0;
		}
		if(dDeltaHigh > dDeltaLow) {
			dPlusDM = dDeltaHigh;
		   	dMinusDM = 0.0;
		}
		if(dDeltaHigh < dDeltaLow) {
			dPlusDM = 0.0;
			dMinusDM = dDeltaLow;
		}
		double plus = plusDMSum[i - 1] - ( plusDMSum[i - 1] / maPeriod ) + dPlusDM;
		double minus = minusDMSum[i - 1] - ( minusDMSum[i - 1] / maPeriod ) + dMinusDM;
		plusDMSum.push_back(plus);
		minusDMSum.push_back(minus);

		double dTrueHigh = ( *(dHighPrice + i) >= *(dClosePrice + (i - 1)) ) ? *(dHighPrice + i) : *(dClosePrice + (i - 1));
		double dTrueLow = ( *(dLowPrice + i) <= *(dClosePrice + (i - 1)) ) ? *(dLowPrice + i) : *(dClosePrice + (i - 1));
		dTR.push_back(dTrueHigh - dTrueLow);
		double dTRSum = dTR[i - 1] - ( dTR[i - 1] / maPeriod ) + dTR[i];

		output["DI+"].push_back( 100.0 * ( plusDMSum[i] / dTRSum ) );
		output["DI-"].push_back( 100.0 * ( minusDMSum[i] / dTRSum ) );
	}
}

void TAEngine::regression(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output)
{
	double dOutput[4096] = {'\0'};
	int outBeg = 0, outNb = 0, i = 0;
	
	TA_LINEARREG(0, inputLength - 1, dClosePrice, maPeriod, &outBeg, &outNb, dOutput);
	
	for(i = 0 ; i < outNb; i++) {
		output["LINEARREG"].push_back( *(dOutput + i) );
	}
}

void TAEngine::kairi(double *dClosePrice, size_t inputLength, int maPeriod, map<string, vector<double> > & output)
{
//http://www.forex-trading-system-advisor.com/kairi.html
	map<string, vector<double> >sma;
	moving_averages(TAEngine_SMA, dClosePrice, inputLength, sma, maPeriod);
	size_t smaSize = sma["SMA"].size();
	for(size_t i = 0; i < smaSize; i++) {
		double element = ( ( *(dClosePrice + i) - sma["SMA"][i] ) / sma["SMA"][i] ) * 100;
		output["KRI"].push_back(element);
	}
}

void TAEngine::asi(double *dOpenPrice, double *dHighPrice, double *dLowPrice, double *dClosePrice, size_t inputLength, double dMaxPriceChange, map<string, vector<double> > & output)
{
//http://fmlabs.com/reference/default.htm
	output["ASI"].push_back(dClosePrice[0]);
	for(size_t i = 1; i < inputLength; i++) {
		double dHighDiff = *(dHighPrice + i) - *(dClosePrice + (i-1));
		cout << "dHighDiff is " << dHighDiff << endl;
		double dLowDiff = *(dLowPrice + i) - *(dClosePrice + (i-1));
		cout << "dLowDiff is " << dLowDiff << endl;
		double K = (dHighDiff >= dLowDiff) ? dHighDiff : dLowDiff;
		cout << "K is " << K << endl;
		double dDiff = *(dHighPrice + i) - *(dClosePrice + i);
		cout << "dDiff is " << dDiff << endl;
		double dMax = (dHighDiff >= dLowDiff) ? ((dHighDiff >= dDiff) ? dHighDiff : dDiff) : (dDiff >= dLowDiff) ? dDiff : dLowDiff;
		cout << "dMax is " << dMax << endl;
		double dOpenSum = *(dClosePrice + (i-1)) + *(dOpenPrice + (i-1));
		cout << "dOpenSum is " << dOpenSum << endl;

		double R;
		if(dMax - dHighDiff == 0) {
			cout << "high!!\n";
			R = dHighDiff + (0.5 * dLowDiff) + (0.25 * dOpenSum);
		} else if(dMax - dLowDiff == 0) {
			cout << "low!!\n";
			R = dLowDiff + (0.5 * dHighDiff) + (0.25 * dOpenSum);
		} else {
			cout << "diff\n";
			R = dDiff + (0.25 * dOpenSum);
		}
		double dNumerator = (dClosePrice[i] - dClosePrice[i - 1]) + (0.5 * (dClosePrice[i] - dOpenPrice[i])) + (0.25 * (dClosePrice[i - 1] + dOpenPrice[i - 1]));
		cout << "numerator is " << dNumerator << endl;
		cout << "R is " << R << endl;
		double dSI = 50 * (dNumerator / R) * (K/dMaxPriceChange);
		cout << "SI is " << dSI << endl;
		double element = output["ASI"][i-1] + dSI;
		output["ASI"].push_back(element);
	}	
}

void TAEngine::fractal(double *dHighPrice, double *dLowPrice, size_t inputLength, map<string, vector<double> > & output)
{
// http://www.fxcodebase.com/code/viewtopic.php?f=17&t=21
	for(size_t i = 2; i < inputLength; i++) {
		if( (dHighPrice[i - 2] < dHighPrice[i]) && (dHighPrice[i - 1] < dHighPrice[i]) && (dHighPrice[i + 1] < dHighPrice[i]) && (dHighPrice[i + 2] < dHighPrice[i]) ) {
			output["UP"].push_back(1.0);
		} else {
			output["UP"].push_back(0.0);
		}	
		if( (dLowPrice[i - 2] > dLowPrice[i]) && (dLowPrice[i - 1] > dLowPrice[i]) && (dLowPrice[i + 1] > dLowPrice[i]) && (dLowPrice[i + 2] > dLowPrice[i]) ) {
			output["DOWN"].push_back(1.0);
		} else {
			output["DOWN"].push_back(0.0);
		}	
	}
}

