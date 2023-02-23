#include <stdio.h>
#include <curl/curl.h>

int main(void) {
    CURL *curl;
    CURLcode res;

    struct curl_slist *recipients = NULL;
    char smtp_url[] = "mail.smtp2go.com";
    char username[] = "Ram sharma";
    char password[] = "!VMmjdUYKKrYy4s";
    char from[] = "pokacaf521@wiroute.com";
    char to[] = "goldjain3@gmail.com";
    char subject[] = "Test Email";
    char message[] = "This is a test email from SMTP2GO.";

    curl = curl_easy_init();
    if(curl) {
        // Set SMTP2GO API endpoint URL
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.smtp2go.com/v3/email/send");

        // Set SMTP2GO API endpoint authentication
        curl_easy_setopt(curl, CURLOPT_USERNAME, username);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, password);

        // Set email headers
        recipients = curl_slist_append(recipients, to);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, from);

        // Set email body
        curl_easy_setopt(curl, CURLOPT_READDATA, message);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

        // Perform HTTP POST request to SMTP2GO API endpoint
        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        else {
            printf("Email sent successfully!\n");
        }

        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);
    }

    return 0;
}
