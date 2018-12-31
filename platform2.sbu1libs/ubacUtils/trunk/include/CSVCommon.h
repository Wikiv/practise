#ifndef __UBAC_CSV_H__
#define __UBAC_CSV_H__

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

//#include "SLog.h"
//#include "Properties.h"
#include "IFHelper.h"

namespace UBACCSV {
        /// Implemente CSV formatted file.
        class CSVFile 
        {
                public:
                        /// Create CSVFile with default properties as `property'.
                        CSVFile();
                        ~CSVFile();

                        /// Set headers for the CSVFile.
                        void setHeader(vector<string>mHeaderList);
                        /// Set a header.
                        void setHeader(string mHeader);

                        /// Set data `mValue' for the header `mHeader'.
                        void setData(string mHeader, string mValue);
                        /// Sync data into the file. Shift date for the file if require.
                        void sync(bool checkShift = true);
                        /// Sync headers alone into the csv file.
                        void syncHeader();

                private:
                        vector<string>headerList;
                        map<string, string>dataMap;
        };

        class CSVRow :
                public vector<string>
        {
                public:
                        CSVRow();
                        ~CSVRow();

                        void addColumn(string sColumnData);
                        void addColumn(time_t time_stamp);
                        void addColumn(double dColumnData);
                        void toString(string & sRow);
                        void toString(string & sRow, char c_delimiter);
        };

        class CSVData :
                public vector<CSVRow>
        {
                public:
                        CSVData();
                        CSVData(string sData);
                        ~CSVData();

                        void setSNOFlagInCSVData( bool mIsSnoInCSVData );
                        void addRow(CSVRow row);
                        void toString(string & sRow, char delimiter = '|');

                        vector<string>  operator[](string sKey);
                private:

                        void parse(string sData);
                        void print();
                        map<string, vector<string> >columnMap;
                        vector<string> headerList;
                        bool isSnoInCSVData;
        };
};

using namespace UBACCSV;

#endif /* __UBAC_CSV_H__ */
