#include "CMXMonitor.h"

using namespace UBACMONITOR;

CMXMonitor::CMXMonitor(int port, EventFax *fax, 
        vector<string> &servList, SLog *sLog){
    if(sLog != NULL) {
        sLog->debug("Starting CMX Monitor service\n");
    }

    sMonitor = new ServiceMonitor(servList, sLog);
    cmxListner = new CMXListner(sMonitor, sLog);
    cmxServer =  new CMXServer(port,fax,cmxListner);
    fax->addTCPServer(cmxServer);
}

CMXMonitor::~CMXMonitor() {
    delete cmxServer;
    delete cmxListner;
    delete sMonitor;
}

bool CMXMonitor::updateFailure(string sName) {
    return sMonitor->updateFailure(sName);
}

bool CMXMonitor::updateSuccess(string sName) {
    return sMonitor->updateSuccess(sName);
}



