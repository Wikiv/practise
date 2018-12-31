#include "CMXListner.h"

using namespace UBACMONITOR;

CMXListner::CMXListner(ServiceMonitor *sMonitor, SLog *logger) {
    this->sLogID = logger;
    this->sMonitor = sMonitor;
}

CMXListner::~CMXListner() {
}

void CMXListner::onGetRequest(HTTPServerRequest * request, HTTPConnection *client) {
    /* Not supporting get call */
    
    HTTPResponse httpResponse(HTTPResponse::service_unavailable);
    client->send(httpResponse);
    client->release();

    if(sLogID != NULL) {
        sLogID->debug("Received GET request; Not Supported; Kindly try with POST\n");
    }

}

void CMXListner::onPostRequest(HTTPServerRequest * request,HTTPConnection *client) {
    string path = request->url;
    if(path == "/getMonitorStatus") {

        HTTPResponse httpResponse(HTTPResponse::ok);
        httpResponse.setHeader("Content-type","application/json");

        try {
            JsonObject jObj = JsonParser(request->sContent).getJsonObject();;

            struct serviceInfo tmp;
            bzero(&tmp,sizeof(tmp));

            string info = jObj["info"];
            sMonitor->getStatus(info, tmp);

            httpResponse.setContent(convertStructToJson(tmp,info));
        } catch (Exceptions e) {
            cout<< "Excpetion catched="<< e.what()<<endl;
            
            if(sLogID != NULL) {
                sLogID->debug("Exception in onPostRequest: %s\n", e.what());
            }
 
            JsonObject data;
            data["errMsg"] = e.what();
 
            httpResponse.setContent(data.toString());
        }

        client->send(httpResponse);

    } else {
        HTTPResponse httpResponse(HTTPResponse::not_found);
    	client->send(httpResponse);
        if(sLogID != NULL) {
            sLogID->debug("Invalid path found: %s\n", path.c_str());    
        }
    }

    client->release();	
}

string CMXListner::convertStructToJson(struct serviceInfo &statusInfo, string info) {
    JsonObject data;
    data["f_cnt"] = statusInfo.f_cnt;
    data["s_cnt"] = statusInfo.s_cnt;
    data["info"] = info;
    return data.toString();
}
