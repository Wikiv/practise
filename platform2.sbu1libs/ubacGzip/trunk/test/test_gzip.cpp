#include <iostream>
#include <ubacgzip/GZip.h>

int main(int argc, char *argv[])
{
	string data= "Market Simplified India Limited. dafs dddwfdf dwf ddsfdsg sddsdgs gfsgfg fgf fgf fgfgfg fgfgfdgd fgfdgdfgd dfdfgfdgfd dfdgfdgdf dfgfdgfdg dfgfdgdfgdf ssi <?xml version=\"1.0\" encoding=\"utf-8\"?><appData><maxScrips>100</maxScrips><maxScripsPerMW>20</maxScripsPerMW><maxTab>6</maxTab><maxMW>1</maxMW><allScrips><![CDATA[ALLSCRIPS]]></allScrips><portfolioMW><![CDATA[PORTFOLIO]]></portfolioMW><basePath><![CDATA[http://localhost]]></basePath><exchangeData><exchange><Name>NSE</Name><Allowed>Y</Allowed><Default>Y</Default></exchange><exchange><Name>BSE</Name><Allowed>N</Allowed><Default>N</Default></exchange></exchangeData><amo><exchange><ExchSeg>BSE</ExchSeg><ExchID>3</ExchID><AMO_Enabled>Y</AMO_Enabled><AMO_Start_Time>17:00</AMO_Start_Time><AMO_End_Time>23:00</AMO_End_Time></exchange><exchange><ExchSeg>NSE</ExchSeg><ExchID>1</ExchID><AMO_Enabled>Y</AMO_Enabled><AMO_Start_Time>17:30</AMO_Start_Time><AMO_End_Time>23:00</AMO_End_Time></exchange><exchange><ExchSeg>BSE Derivatives</ExchSeg><ExchID>4</ExchID><AMO_Enabled>N</AMO_Enabled><AMO_Start_Time></AMO_Start_Time><AMO_End_Time></AMO_End_Time></exchange><exchange><ExchSeg>NSE Derivatives</ExchSeg><ExchID>2</ExchID><AMO_Enabled>Y</AMO_Enabled><AMO_Start_Time>17:00</AMO_Start_Time><AMO_End_Time>23:00</AMO_End_Time></exchange><exchange><ExchSeg>MCX Futures</ExchSeg><ExchID>5</ExchID><AMO_Enabled>N</AMO_Enabled><AMO_Start_Time></AMO_Start_Time><AMO_End_Time></AMO_End_Time></exchange><exchange><ExchSeg>NCDEX Futures</ExchSeg><ExchID>7</ExchID><AMO_Enabled>N</AMO_Enabled><AMO_Start_Time></AMO_Start_Time><AMO_End_Time></AMO_End_Time></exchange><exchange><ExchSeg>MCX SX Curr Futures</ExchSeg><ExchID>11</ExchID><AMO_Enabled>N</AMO_Enabled><AMO_Start_Time></AMO_Start_Time><AMO_End_Time></AMO_End_Time></exchange><exchange><ExchSeg>NSECDS Futures</ExchSeg><ExchID>13</ExchID><AMO_Enabled>N</AMO_Enabled><AMO_Start_Time></AMO_Start_Time><AMO_End_Time></AMO_End_Time></exchange></amo></appData>!@#<?xml version=\"1.0\" encoding=\"utf-8\"?><preferenceData><defaultMW>Angel</defaultMW><orderType>Delivery</orderType></preferenceData> {\"config\":{\"app\":18,\"message\":4},\"response\":{\"msgID\":\"f62e45f1-682d-4595-bd08-ca1ebe506049\",\"infoID\":\"0\",\"data\":{\"summaryLst\":[{\"trd\":\"29975.00\",\"mf\":\"NA\",\"desc\":\"depo\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"funTrnsTday\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"collat\"},{\"trd\":\"-33453.00\",\"mf\":\"NA\",\"desc\":\"lmtUtil\"},{\"trd\":\"1887.33\",\"mf\":\"NA\",\"desc\":\"bkdPrft\"},{\"trd\":\"-160.00\",\"mf\":\"NA\",\"desc\":\"mtmPrft\"},{\"trd\":\"-1750.67\",\"mf\":\"NA\",\"desc\":\"netAvalFnds\"}],\"detailLst\":[{\"trd\":\"29975.00\",\"mf\":\"NA\",\"desc\":\"depo\",\"subList\":[{\"trd\":\"29975.00\",\"mf\":\"NA\",\"desc\":\"casDepo\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"adhocDepo\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"ovrDrftLmt\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"notiDepo\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"misDepo\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"manCollat\"}]},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"funTrnsTday\",\"subList\":[]},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"fundWithdrawalAlloc\",\"subList\":[]},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"collat\",\"subList\":[{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"dpCollat\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"poCollat\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"saCollat\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"dpPledgCollat\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"poPledgCollat\"},{\"trd\":\"99999999999.99\",\"mf\":\"NA\",\"desc\":\"maxCollatLmt\"}]},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"crditFrSale\",\"subList\":[{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"dpCFS\"},{\"trd\":\"99999999999.99\",\"mf\":\"NA\",\"desc\":\"maxCFSLmt\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"SARCFS\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"poCFS\"}]},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"optCFS\",\"subList\":[{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"optCFS\"},{\"trd\":\"99999999999.99\",\"mf\":\"NA\",\"desc\":\"maxOptCFS\"},{\"trd\":\"29975.00\",\"mf\":\"NA\",\"desc\":\"totTrdPowLmt\"},{\"trd\":\"2.00\",\"mf\":\"NA\",\"desc\":\"Multip\"}]},{\"trd\":\"-33453.00\",\"mf\":\"NA\",\"desc\":\"lmtUtil\",\"subList\":[{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"comPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"curPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"derPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"eqtyPos\"}]},{\"trd\":\"1887.33\",\"mf\":\"NA\",\"desc\":\"bkdPrft\",\"subList\":[{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"comPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"curPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"derPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"eqtyPos\"}]},{\"trd\":\"-160.00\",\"mf\":\"NA\",\"desc\":\"mtmPrft\",\"subList\":[{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"comPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"curPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"derPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"eqtyPos\"},{\"trd\":\"-31725.67\",\"mf\":\"NA\",\"desc\":\"totUtiliz\"}]},{\"trd\":\"-1750.67\",\"mf\":\"NA\",\"desc\":\"netAvalFnds\",\"subList\":[]},{\"trd\":\"-1750.67\",\"mf\":\"NA\",\"desc\":\"frTrd\",\"subList\":[]},{\"trd\":\"14112.17\",\"mf\":\"NA\",\"desc\":\"frAllocWithdrawal\",\"subList\":[]}]},\"svcGroup\":\"Funds\",\"svcName\":\"Limit\",\"svcVersion\":\"1.0.0\",\"serverTime\":\"1457016556952\",\"appID\":\"66c4833e3c7932ff5bfb8b19d75c686a\"},\"echo\":{\"SpinnerItem\":\"COMMODITIES\"}} {\"config\":{\"app\":18,\"message\":4},\"response\":{\"msgID\":\"f62e45f1-682d-4595-bd08-ca1ebe506049\",\"infoID\":\"0\",\"data\":{\"summaryLst\":[{\"trd\":\"29975.00\",\"mf\":\"NA\",\"desc\":\"depo\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"funTrnsTday\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"collat\"},{\"trd\":\"-33453.00\",\"mf\":\"NA\",\"desc\":\"lmtUtil\"},{\"trd\":\"1887.33\",\"mf\":\"NA\",\"desc\":\"bkdPrft\"},{\"trd\":\"-160.00\",\"mf\":\"NA\",\"desc\":\"mtmPrft\"},{\"trd\":\"-1750.67\",\"mf\":\"NA\",\"desc\":\"netAvalFnds\"}],\"detailLst\":[{\"trd\":\"29975.00\",\"mf\":\"NA\",\"desc\":\"depo\",\"subList\":[{\"trd\":\"29975.00\",\"mf\":\"NA\",\"desc\":\"casDepo\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"adhocDepo\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"ovrDrftLmt\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"notiDepo\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"misDepo\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"manCollat\"}]},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"funTrnsTday\",\"subList\":[]},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"fundWithdrawalAlloc\",\"subList\":[]},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"collat\",\"subList\":[{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"dpCollat\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"poCollat\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"saCollat\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"dpPledgCollat\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"poPledgCollat\"},{\"trd\":\"99999999999.99\",\"mf\":\"NA\",\"desc\":\"maxCollatLmt\"}]},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"crditFrSale\",\"subList\":[{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"dpCFS\"},{\"trd\":\"99999999999.99\",\"mf\":\"NA\",\"desc\":\"maxCFSLmt\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"SARCFS\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"poCFS\"}]},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"optCFS\",\"subList\":[{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"optCFS\"},{\"trd\":\"99999999999.99\",\"mf\":\"NA\",\"desc\":\"maxOptCFS\"},{\"trd\":\"29975.00\",\"mf\":\"NA\",\"desc\":\"totTrdPowLmt\"},{\"trd\":\"2.00\",\"mf\":\"NA\",\"desc\":\"Multip\"}]},{\"trd\":\"-33453.00\",\"mf\":\"NA\",\"desc\":\"lmtUtil\",\"subList\":[{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"comPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"curPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"derPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"eqtyPos\"}]},{\"trd\":\"1887.33\",\"mf\":\"NA\",\"desc\":\"bkdPrft\",\"subList\":[{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"comPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"curPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"derPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"eqtyPos\"}]},{\"trd\":\"-160.00\",\"mf\":\"NA\",\"desc\":\"mtmPrft\",\"subList\":[{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"comPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"curPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"derPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"eqtyPos\"},{\"trd\":\"-31725.67\",\"mf\":\"NA\",\"desc\":\"totUtiliz\"}]},{\"trd\":\"-1750.67\",\"mf\":\"NA\",\"desc\":\"netAvalFnds\",\"subList\":[]},{\"trd\":\"-1750.67\",\"mf\":\"NA\",\"desc\":\"frTrd\",\"subList\":[]},{\"trd\":\"14112.17\",\"mf\":\"NA\",\"desc\":\"frAllocWithdrawal\",\"subList\":[]}]},\"svcGroup\":\"Funds\",\"svcName\":\"Limit\",\"svcVersion\":\"1.0.0\",\"serverTime\":\"1457016556952\",\"appID\":\"66c4833e3c7932ff5bfb8b19d75c686a\"},\"echo\":{\"SpinnerItem\":\"COMMODITIES\"}} {\"config\":{\"app\":18,\"message\":4},\"response\":{\"msgID\":\"f62e45f1-682d-4595-bd08-ca1ebe506049\",\"infoID\":\"0\",\"data\":{\"summaryLst\":[{\"trd\":\"29975.00\",\"mf\":\"NA\",\"desc\":\"depo\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"funTrnsTday\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"collat\"},{\"trd\":\"-33453.00\",\"mf\":\"NA\",\"desc\":\"lmtUtil\"},{\"trd\":\"1887.33\",\"mf\":\"NA\",\"desc\":\"bkdPrft\"},{\"trd\":\"-160.00\",\"mf\":\"NA\",\"desc\":\"mtmPrft\"},{\"trd\":\"-1750.67\",\"mf\":\"NA\",\"desc\":\"netAvalFnds\"}],\"detailLst\":[{\"trd\":\"29975.00\",\"mf\":\"NA\",\"desc\":\"depo\",\"subList\":[{\"trd\":\"29975.00\",\"mf\":\"NA\",\"desc\":\"casDepo\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"adhocDepo\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"ovrDrftLmt\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"notiDepo\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"misDepo\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"manCollat\"}]},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"funTrnsTday\",\"subList\":[]},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"fundWithdrawalAlloc\",\"subList\":[]},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"collat\",\"subList\":[{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"dpCollat\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"poCollat\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"saCollat\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"dpPledgCollat\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"poPledgCollat\"},{\"trd\":\"99999999999.99\",\"mf\":\"NA\",\"desc\":\"maxCollatLmt\"}]},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"crditFrSale\",\"subList\":[{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"dpCFS\"},{\"trd\":\"99999999999.99\",\"mf\":\"NA\",\"desc\":\"maxCFSLmt\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"SARCFS\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"poCFS\"}]},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"optCFS\",\"subList\":[{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"optCFS\"},{\"trd\":\"99999999999.99\",\"mf\":\"NA\",\"desc\":\"maxOptCFS\"},{\"trd\":\"29975.00\",\"mf\":\"NA\",\"desc\":\"totTrdPowLmt\"},{\"trd\":\"2.00\",\"mf\":\"NA\",\"desc\":\"Multip\"}]},{\"trd\":\"-33453.00\",\"mf\":\"NA\",\"desc\":\"lmtUtil\",\"subList\":[{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"comPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"curPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"derPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"eqtyPos\"}]},{\"trd\":\"1887.33\",\"mf\":\"NA\",\"desc\":\"bkdPrft\",\"subList\":[{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"comPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"curPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"derPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"eqtyPos\"}]},{\"trd\":\"-160.00\",\"mf\":\"NA\",\"desc\":\"mtmPrft\",\"subList\":[{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"comPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"curPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"derPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"eqtyPos\"},{\"trd\":\"-31725.67\",\"mf\":\"NA\",\"desc\":\"totUtiliz\"}]},{\"trd\":\"-1750.67\",\"mf\":\"NA\",\"desc\":\"netAvalFnds\",\"subList\":[]},{\"trd\":\"-1750.67\",\"mf\":\"NA\",\"desc\":\"frTrd\",\"subList\":[]},{\"trd\":\"14112.17\",\"mf\":\"NA\",\"desc\":\"frAllocWithdrawal\",\"subList\":[]}]},\"svcGroup\":\"Funds\",\"svcName\":\"Limit\",\"svcVersion\":\"1.0.0\",\"serverTime\":\"1457016556952\",\"appID\":\"66c4833e3c7932ff5bfb8b19d75c686a\"},\"echo\":{\"SpinnerItem\":\"COMMODITIES\"}}{\"config\":{\"app\":18,\"message\":4},\"response\":{\"msgID\":\"f62e45f1-682d-4595-bd08-ca1ebe506049\",\"infoID\":\"0\",\"data\":{\"summaryLst\":[{\"trd\":\"29975.00\",\"mf\":\"NA\",\"desc\":\"depo\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"funTrnsTday\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"collat\"},{\"trd\":\"-33453.00\",\"mf\":\"NA\",\"desc\":\"lmtUtil\"},{\"trd\":\"1887.33\",\"mf\":\"NA\",\"desc\":\"bkdPrft\"},{\"trd\":\"-160.00\",\"mf\":\"NA\",\"desc\":\"mtmPrft\"},{\"trd\":\"-1750.67\",\"mf\":\"NA\",\"desc\":\"netAvalFnds\"}],\"detailLst\":[{\"trd\":\"29975.00\",\"mf\":\"NA\",\"desc\":\"depo\",\"subList\":[{\"trd\":\"29975.00\",\"mf\":\"NA\",\"desc\":\"casDepo\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"adhocDepo\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"ovrDrftLmt\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"notiDepo\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"misDepo\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"manCollat\"}]},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"funTrnsTday\",\"subList\":[]},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"fundWithdrawalAlloc\",\"subList\":[]},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"collat\",\"subList\":[{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"dpCollat\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"poCollat\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"saCollat\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"dpPledgCollat\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"poPledgCollat\"},{\"trd\":\"99999999999.99\",\"mf\":\"NA\",\"desc\":\"maxCollatLmt\"}]},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"crditFrSale\",\"subList\":[{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"dpCFS\"},{\"trd\":\"99999999999.99\",\"mf\":\"NA\",\"desc\":\"maxCFSLmt\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"SARCFS\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"poCFS\"}]},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"optCFS\",\"subList\":[{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"optCFS\"},{\"trd\":\"99999999999.99\",\"mf\":\"NA\",\"desc\":\"maxOptCFS\"},{\"trd\":\"29975.00\",\"mf\":\"NA\",\"desc\":\"totTrdPowLmt\"},{\"trd\":\"2.00\",\"mf\":\"NA\",\"desc\":\"Multip\"}]},{\"trd\":\"-33453.00\",\"mf\":\"NA\",\"desc\":\"lmtUtil\",\"subList\":[{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"comPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"curPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"derPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"eqtyPos\"}]},{\"trd\":\"1887.33\",\"mf\":\"NA\",\"desc\":\"bkdPrft\",\"subList\":[{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"comPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"curPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"derPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"eqtyPos\"}]},{\"trd\":\"-160.00\",\"mf\":\"NA\",\"desc\":\"mtmPrft\",\"subList\":[{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"comPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"curPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"derPos\"},{\"trd\":\"0.00\",\"mf\":\"NA\",\"desc\":\"eqtyPos\"},{\"trd\":\"-31725.67\",\"mf\":\"NA\",\"desc\":\"totUtiliz\"}]},{\"trd\":\"-1750.67\",\"mf\":\"NA\",\"desc\":\"netAvalFnds\",\"subList\":[]},{\"trd\":\"-1750.67\",\"mf\":\"NA\",\"desc\":\"frTrd\",\"subList\":[]},{\"trd\":\"14112.17\",\"mf\":\"NA\",\"desc\":\"frAllocWithdrawal\",\"subList\":[]}]},\"svcGroup\":\"Funds\",\"svcName\":\"Limit\",\"svcVersion\":\"1.0.0\",\"serverTime\":\"1457016556952\",\"appID\":\"66c4833e3c7932ff5bfb8b19d75c686a\"},\"echo\":{\"SpinnerItem\":\"COMMODITIES\"}}";
	
        GZip zipper; //"./sample", fileName.length() );
	string outPut;
	unsigned char *decCompData;
        size_t dLen=0;

	bool comStatus = zipper.deflateGet((unsigned char *) data.c_str(),strlen(data.c_str()), &decCompData,&dLen);
	for(int i =0; i<dLen;i++)
        {
             //printf("%c",((**destPtr)+i) );
             printf("%c",((*decCompData)+i) );
        }
	cout<<endl; 
	if( comStatus)
	{
        	zipper.inflateGet( (unsigned char *) decCompData, dLen , outPut);
	}
	
	free(decCompData);
        //for(size_t i = 0; i < decom_length; i++)
        //      printf("%d, %c\n", decom[i], decom[i]);
        //cout << decom_length << endl;
	cout<<"Output Data =="<< outPut<<endl;
}
