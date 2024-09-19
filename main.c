#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(void) {
    curl_global_init(CURL_GLOBAL_ALL);

    CURL *curl = curl_easy_init();

    if (curl) {
        printf("Curl initialized\n");
        curl_easy_setopt(curl, CURLOPT_URL, "https://guildofstudents.com");

        CURLcode response = curl_easy_perform(curl);

        if (response != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(response));
            curl_easy_cleanup(curl);
        } else {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response);
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}
