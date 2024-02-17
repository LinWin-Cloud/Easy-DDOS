//
// Created by ubuntu on 24-2-11.
//

#include <curl/curl.h>


class HttpRequests {
private:
    string url;
public:
    explicit HttpRequests(string url) {
        this -> url = std::move(url);
    }

    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
    }

    string GetRequest() {
        /**
         * Send Get Http Requests. Use curl lib.
         * Author: LinWin-Cloud.
         */
        CURL *curl;
        CURLcode res;
        std::string readBuffer;
        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, this -> url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
            if (res == CURLE_OK) {
                return readBuffer;
            }else {
                return readBuffer;
            }
        }
        else {
            throw runtime_error("Http Requests Error , Method: GET.");
        }
    }
};
