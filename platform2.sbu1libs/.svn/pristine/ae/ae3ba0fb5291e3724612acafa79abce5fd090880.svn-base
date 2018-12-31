#include "ServiceMonitor.h"

using namespace UBACMONITOR;

ServiceMonitor::ServiceMonitor(vector<string> &serviceList, SLog *logger) {
    sLogID = logger;
    init_map(serviceList);
}

void ServiceMonitor::init_map(vector<string> &serviceList) {
    vector<string>::iterator it = serviceList.begin();
    struct serviceInfo tmp;
    bzero(&tmp,sizeof(tmp));

    while( it != serviceList.end()) {
        status_map.insert(make_pair( *it, tmp));
        it++;
    }

}

ServiceMonitor::~ServiceMonitor() {
}

bool ServiceMonitor::updateFailure(string sName) {
    map<string,struct serviceInfo>::iterator it;
    bool flag = false;

    mMutex.lock();
    it = status_map.find(sName);
    if( it != status_map.end() ) {
        it->second.f_cnt++;
        flag = true;
    }
    mMutex.unlock();
    return flag;
}

bool ServiceMonitor::updateSuccess(string sName) {
    map<string,struct serviceInfo>::iterator it;
    bool flag = false;

    mMutex.lock();

    it = status_map.find(sName);
    if( it != status_map.end() ) {
        it->second.s_cnt++;
        flag = true;
    }

    mMutex.unlock();
    return flag;
}

bool ServiceMonitor::getStatus(string sName, struct serviceInfo &servInfo) {
    bool flag = false;	
    map<string,struct serviceInfo>::iterator it;

    mMutex.lock();	
    it = status_map.find(sName);
    if(it != status_map.end()) {
        servInfo = it->second;
        bzero(&it->second, sizeof(it->second));
        flag = true;
    }

    mMutex.unlock();
    logStatus(sName, servInfo);
    return flag;
}

string ServiceMonitor::convertIntegerToString(int iNumber) {
    ostringstream ss;
    ss << iNumber;
    return ss.str();
}

void ServiceMonitor::logStatus(string sName, struct serviceInfo &servInfo) {
    if(sLogID != NULL) {
        sLogID->debug("Service Name: %s, Success Count: %s, Failure Count: %s\n", sName.c_str(), \
                            convertIntegerToString(servInfo.s_cnt).c_str(), convertIntegerToString(servInfo.f_cnt).c_str());
    }
}
