#include <iostream>
#include <string>
#include <map>

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

//#include <ubacxml/XmlParser.h>
#include "XmlParser.h"

void callback(string xpath, multimap<string, string>dataMap, multimap<string, string> attrMap, void *ptr)
{
        printf("Address = %p\n", ptr);
        multimap<string, string>::iterator i;
        for(i = dataMap.begin(); i != dataMap.end(); i++)
                cout << "Elements: Xpath = " << xpath << ", Name = " << i->first << ", Value = " << i->second << endl;

        for(i = attrMap.begin(); i != attrMap.end(); i++)
                cout << "Attribute: Xpath = " << xpath << ", Name = " << i->first << ", Value = " << i->second << endl;
}

int main(int argc, char *argv[])
{
        printf("argc = %p\n", &argc);
        if( argc != 2 ) {
                cout << "Run as " << argv[0] << " <xml file name>" << endl;
                exit(EXIT_FAILURE);
        }
        int fd = open(argv[1], O_RDONLY);
        if( fd < 0 ) {
                cout << "unable to open " << argv[1] << endl;
                exit(EXIT_FAILURE);
        }
        char c;
        string xmlData;
        while( read(fd, &c, 1) == 1 )
                xmlData.append(&c, 1);
        XmlParser parser(xmlData, 0);
        parser.setCallback("/Envelope/Body/UserLoginRequestResponse/UserLoginRequestResult/AllowedGateway/KeyValueOfunsignedIntstring", callback, (void *)fd);
        // parser.setCallback("/Envelope/Body/UserLoginRequestResponse/UserLoginRequestResult/AllowedGateway/KeyValueOfunsignedIntstring", callback, (void *)(fd+1));
//        parser.setCallback("/Envelope/Body/UserLoginRequestResponse/UserLoginRequestResult/ClientCodes/KeyValueOfstringunsignedInt", callback, (void *)fd);
        parser.parse();
}

