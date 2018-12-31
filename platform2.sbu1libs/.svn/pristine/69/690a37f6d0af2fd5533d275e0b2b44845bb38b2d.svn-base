#include "XmlParser.h"

XmlParser::XmlParser(string m_xmlData, uint8_t m_encoding)
{
	xmlData.append( m_xmlData );
	if ( !isXmlData() ) {
		resetEncodingInXmlData( "UTF-8" , "ISO-8859-1" );
		//cout << "New XML Data = "  << xmlData << endl;
		if ( !isXmlData() ) {
			//cout << "New XML Data0= "  << xmlData << endl;
			resetEncodingInXmlData( "utf-8", "ISO-8859-1" );
			if ( !isXmlData() ) {
				resetEncodingInXmlData( "ISO-8859-1" , "UTF-16" );
				//cout << "New XML Data1= "  << xmlData << endl;
				if ( !isXmlData() ) {
					resetEncodingInXmlData( "UTF-16" , "UTF-32" );
					isXmlData();
				}
			}	
		}
	}
}

void XmlParser::resetEncodingInXmlData( string encodingToCheck , string encodingToReplace )
{
	size_t found;
	found = xmlData.find( encodingToCheck );
	if ( found!=string::npos )
		xmlData.replace( found , encodingToCheck.length() , encodingToReplace );
}

XmlParser::~XmlParser()
{
}

void XmlParser::iterateAttributes(xmlNode *element, multimap<string, string> &attrMap)
{
	xmlAttrPtr attr_iterator = element->properties;
	if( !attr_iterator ) return;
	for( ; attr_iterator != NULL; attr_iterator = attr_iterator->next ) {
		const xmlChar *xml_attr_name = attr_iterator->name;
		xmlChar *xml_attr_value = xmlGetProp(element, xml_attr_name);
		string strAttrName( (const char *)xml_attr_name );
		string strAttrValue( (const char *)xml_attr_value );
		attrMap.insert( make_pair(strAttrName, strAttrValue) );
        xmlFree( xml_attr_value);
//		cout << "Attribute: name = " << (char *)xml_attr_name << ", value = " << (char *)xml_attr_value << endl;
	}
}

void XmlParser::iterate(string xpath, xmlNode *element)
{
	xmlNode *iterator;
	const char *name = (const char *)element->name;
	multimap<string, string>attrMap;
	multimap<string, string>contentMap;
	iterateAttributes(element, attrMap);
	stringstream newXpathStream;
	newXpathStream << xpath << "/" << name;
//	cout << newXpathStream.str() << endl;
	for(iterator = element->children; iterator ; iterator = iterator->next) {
		if(iterator->type != XML_ELEMENT_NODE) continue;
		const char *content_name = (const char *)iterator->name;
		char *content_text = (char *)xmlNodeGetContent(iterator);
		string strContentName(content_name), strContentText(content_text);
		contentMap.insert( make_pair(strContentName, strContentText) );
		free(content_text);
	}
	map<string, void (*)(string, multimap<string, string>, multimap<string, string>, void *)>::iterator iCallback = xpathMap.find( newXpathStream.str() );
	if( iCallback != xpathMap.end() ) {
		map<string, void *>::iterator iUserData = userDataMap.find( newXpathStream.str() );
		iCallback->second(newXpathStream.str(), contentMap, attrMap, iUserData->second);
	}
	for(iterator = element->children; iterator ; iterator = iterator->next) {
		if(iterator->type != XML_ELEMENT_NODE) continue;
		iterate(newXpathStream.str(), iterator);
	}
}

void XmlParser::iterateRoot( xmlNode *element )
{
	xmlNode *iterator;
	multimap<string, string>attrMap;
	multimap<string, string>contentMap;
	iterateAttributes(element, attrMap);
	stringstream newXpathStream;
	newXpathStream << "/";
//	cout << newXpathStream.str() << endl;
	for(iterator = element; iterator ; iterator = iterator->next) {
		if(iterator->type != XML_ELEMENT_NODE) continue;
		const char *content_name = (const char *)iterator->name;
		char *content_text = (char *)xmlNodeGetContent(iterator);
		string strContentName(content_name), strContentText(content_text);
		contentMap.insert( make_pair(strContentName, strContentText) );
		free(content_text);
	}
	map<string, void (*)(string, multimap<string, string>, multimap<string, string>, void *)>::iterator iCallback = xpathMap.find( newXpathStream.str() );
	if( iCallback != xpathMap.end() ) {
		map<string, void *>::iterator iUserData = userDataMap.find( newXpathStream.str() );
		iCallback->second(newXpathStream.str(), contentMap, attrMap, iUserData->second);
	}
}

void XmlParser::parse()
{
	xmlNode *root_element = NULL;
	xmlDocPtr docPtr;
	docPtr = xmlReadMemory(xmlData.c_str(), xmlData.length(), NULL, NULL, 0);
	root_element = xmlDocGetRootElement(docPtr);
	string xpath = "";
	iterateRoot(root_element);
	iterate(xpath, root_element);
	xmlFreeDoc( docPtr );
}

void XmlParser::setCallback(string xpath, void (*f)(string, multimap<string, string>, multimap<string, string>, void *), void *userData)
{
	xpathMap.insert( make_pair(xpath, f) );
	userDataMap.insert( make_pair(xpath, userData) );
}

bool XmlParser::isXmlData()
{
	xmlDocPtr docPtr;
	docPtr = xmlReadMemory(xmlData.c_str(), xmlData.length(), NULL, NULL, 0);
	bool retFlag = ( docPtr != NULL );
	xmlFreeDoc(docPtr);
	return retFlag;
}
