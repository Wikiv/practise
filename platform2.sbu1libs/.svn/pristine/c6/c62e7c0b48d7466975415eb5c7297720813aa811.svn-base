#ifndef __UBAC_XML_PARSER_H__
#define __UBAC_XML_PARSER_H__

#include <libxml/xmlmemory.h>
#include <libxml/tree.h>
#include <libxml/xmlreader.h>

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <stdint.h>

using namespace std;

namespace UBACXML {
	/** This class implements a way to parse XML files, by setting callback functions to handle elements in each node.
	  * For example, consider the xml fileas given below:
	  * \verbatim
	  * <table>
	  *   <tableset>
	  *     <firstname>John</firstname>
	  *     <lastname>Woo</lastname>
	  *     <age>25</age>
	  *     <email>john@gmail.com</email>
	  *   </tableset>
	  * </table>
	  * \endverbatim
	  * When creating the object for XmlParser, pass the string containing the xml data, along with the 
	  * encoding. Currently the encoding is not handled and can be any value. Before invoking parse 
	  * member to start parsing, set the callback functions to handle the specific nodes. The callback 
	  * method takes the prototype as given below:
	  * \verbatim
	  * void callback(string sXpath, multimap<string, string>elements, multimap<string, string>attributes, void *user_data)
	  * \endverbatim
	  * For example to handle elements under `tableset', set the xpath as "/table/tableset". In this case, on invoking the 
	  * callback function, the elements would contain the element nodes and its corresponding values. The attributes for `tableset',
	  * would be available in `attributes'. In case you want to handle the xml data in a specific way, a `user_data' can be 
	  * passed as a void pointer, when setting the callback. For example:
	  * \verbatim
	  * xmlParserObject.setCallback("/table/tableset", callback, (void *)address_of_another_object);
	  * \endverbatim
	  * The underlying implementation of invoking callbacks is a bit tricky and is done recursively. The explanation is 
	  * beyond the scope of this document.
	  **/
	class XmlParser {
		public:
			/** Create the XmlParser. 'm_xmlData' is the XML data and 'm_encoding' is one of the
			  * supported xml encodings. Please ignore the value for now. */
			XmlParser(string m_xmlData, uint8_t m_encoding);
			~XmlParser();

			/** Parse the xml file. */
			void parse();
			/** Set the callback method to handle the XML data. 
			  * 'xpath' is the current XPath in the xml data. 
			  * 'f' is the callback function. */
			void setCallback(string xpath, void (*f)(string, multimap<string, string>, multimap<string, string>, void *), void *userData);
			/** Checks if the XML file is valid or not. */
			bool isXmlData();

		private:
			void resetEncodingInXmlData( string encodingToCheck , string encodingToReplace );
			void iterateAttributes(xmlNode *element, multimap<string, string> & attrMap);
			void iterateRoot( xmlNode *element );
			void iterate(string xpath, xmlNode *element);
			map<string, void (*)(string, multimap<string, string>, multimap<string, string>, void *)>xpathMap;
			map<string, void *>userDataMap;
			string xmlData;
	};
};

using namespace UBACXML;

#endif /* __UBAC_XML_PARSER_H__ */
