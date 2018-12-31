#include <stdio.h>
#include <curl/curl.h>
#include <unistd.h>

#define SKIP_PEER_VERIFICATION 1
#define SKIP_HOSTNAME_VERIFICATION 1

size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    return size * nmemb;
      //char *response = (char *) userdata;
}


int http_get(void)
{
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://example.com/");
 
#ifdef SKIP_PEER_VERIFICATION
    /*
     * If you want to connect to a site who isn't using a certificate that is
     * signed by one of the certs in the CA bundle you have, you can skip the
     * verification of the server's certificate. This makes the connection
     * A LOT LESS SECURE.
     *
     * If you have a CA cert for the server stored someplace else than in the
     * default bundle, then the CURLOPT_CAPATH option might come handy for
     * you.
     */ 
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
#endif
 
#ifdef SKIP_HOSTNAME_VERIFICATION
    /*
     * If the site you're connecting to uses a different host name that what
     * they have mentioned in their server certificate's commonName (or
     * subjectAltName) fields, libcurl will refuse to connect. You can skip
     * this check, but this will make the connection less secure.
     */ 
//    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
#endif

    //curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
 
    /* Perform the request, res will get the return code */ 
    res = curl_easy_perform(curl);
    /* Check for errors */ 
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
    /* always cleanup */ 
    curl_easy_cleanup(curl);
  }
 
 
  return 0;
}


int main(int argc, char * argv[])
{
    int n = 200;

    for (int i = 0; i < n; i++)
    {
        
        //curl_global_init(CURL_GLOBAL_DEFAULT);
        http_get();
        // Enable this clearing the memory.
        // curl_global_cleanup();
    }
    

    while(1) sleep(5);
}
