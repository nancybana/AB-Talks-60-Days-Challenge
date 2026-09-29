#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* output)
{
    output->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main()
{
    string city;
    cout << "Enter city name: ";
    getline(cin, city);

    for(char &c : city)
    {
        if(c == ' ')
            c = '+';
    }

    string url = "https://wttr.in/" + city + "?format=j1";

    CURL* curl = curl_easy_init();

    if(!curl)
    {
        cout << "Failed to initialize CURL.\n";
        return 1;
    }

    string response;

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    CURLcode res = curl_easy_perform(curl);

    if(res != CURLE_OK)
    {
        cout << "API Request Failed: "
             << curl_easy_strerror(res) << endl;
        curl_easy_cleanup(curl);
        return 1;
    }

    curl_easy_cleanup(curl);

    try
    {
        json data = json::parse(response);

        auto current = data["current_condition"][0];

        cout << "\n===== Weather Summary =====\n";
        cout << "Temperature : "
             << current["temp_C"] << " °C\n";

        cout << "Feels Like  : "
             << current["FeelsLikeC"] << " °C\n";

        cout << "Humidity    : "
             << current["humidity"] << "%\n";

        cout << "Wind Speed  : "
             << current["windspeedKmph"] << " km/h\n";

        cout << "Condition   : "
             << current["weatherDesc"][0]["value"] << "\n";

        cout << "===========================\n";
    }
    catch(...)
    {
        cout << "Error parsing weather data.\n";
    }

    return 0;
}