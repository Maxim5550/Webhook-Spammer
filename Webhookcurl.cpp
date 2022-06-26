#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <curl/curl.h>
#include "cfg.h"

void spammer(int timer, std::string wurl) {
    CURL* curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl){
        
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_URL, wurl.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsoncontent.c_str());
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        std::cout << "[+]Started!\n";
        while(1){
            res = curl_easy_perform(curl);
            std::this_thread::sleep_for(std::chrono::seconds(sleeptimer));
        }
        
    }
}


int main(){
    std::string wURL = "";
    std::cout << R"(

 _  _  _       _     _                 _     
| || || |     | |   | |               | |    
| || || | ____| | _ | | _   ___   ___ | |  _ 
| ||_|| |/ _  ) || \| || \ / _ \ / _ \| | / )
| |___| ( (/ /| |_) ) | | | |_| | |_| | |< ( 
 \______|\____)____/|_| |_|\___/ \___/|_| \_)

[>]Webhook URL > )";
std::cin >> wURL;
spammer(sleeptimer, wURL);
}

