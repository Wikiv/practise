#ifndef EXTMOD_INCLUDE
#define EXTMOD_INCLUDE
#include <iostream>
#include <ubacutils/IFHelper.h>
#include <map>

using namespace std;

namespace UBAC 
{
        class ExtMod :
                public string,
                public IFHelper
        {
                public:
                        ExtMod(string data);
                        ExtMod();
                        ~ExtMod();

                        /** Check if key is available or now. */
                        bool hasKeyIgnoreCase(string sKey);
                        /** Get value for a key from the extended modifer. */
                        void getValue(string name, string &value, bool bIgnoreCase = false);
                        /** Set key - value in the extended modifier. */
                        void setValue(string name, double value);
                        void setValue(string name, string value);
                        /** Print all the keys and values in the extended modifier. */
                        void print_all();
                        /** Deletes a key in 'name' from the extended modifier. */
                        bool deleteValue(string name);
                        /** Makes the string and appends to 'response'. */
                        void toString(string & response);
                        /** Adding a new string to current Ext Mod Object */
                        void addAnotherExtModtoThis( string data );
                        /** Merge 2 extmods. */
                        ExtMod operator+(ExtMod extMod);
                        /** Get name value pairs. */
                        map<string, string>getAllKeyValues();

                private:
                        void make();
                        void parse(string data);
                        map<string, string>name_value_pair;
        };
}

using namespace UBAC;
/*END OF Namespace UBAC*/
#endif
