#include <stdio.h>
#include <curl/curl.h>

int main(void) {
    curl_global_init(CURL_GLOBAL_ALL);

    CURL *curl = curl_easy_init();

    if (curl) {
        printf("Curl initialized\n");
        curl_easy_setopt(curl, CURLOPT_URL, "https://guildofstudents.com");

        const CURLcode response = curl_easy_perform(curl);

        if (response != CURLE_OK) {
            printf("Something went wrong!!\n");
            printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(response));
        } else {
            printf("Everything went okay!!\n");
            // TODO: idk print somet I guess
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

// TODO: New method to take in the curl session, make a request and extract the society name if present



