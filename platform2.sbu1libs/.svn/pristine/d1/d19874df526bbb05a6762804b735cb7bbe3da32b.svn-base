#include <iostream>
#include <map>

#include <ubaclogger/SLog.h>
#include <ubacipc/EventFax.h>
#include <ubacipc/HTTPServer.h>

#include "Application.h"
#include "UBACWebServiceApplication.h"

int main()
{

    UBACWebServiceApplication * uWebServiceApp 
        = new UBACWebServiceApplication("/", NULL, NULL);

    EventFax fax;

    HTTPServer * h =  new HTTPServer(30002, &fax, uWebServiceApp);

    fax.addTCPServer(h);

    fax.run();

}
