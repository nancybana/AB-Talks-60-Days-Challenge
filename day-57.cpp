#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

class SpamDetector
{
private:
    unordered_set<string> spamWords = {
        "win", "free", "prize", "offer",
        "money", "lottery", "click",
        "urgent", "bonus", "cash"
    };

public:
    void predict(string message)
    {
        auto start = high_resolution_clock::now();

        transform(message.begin(), message.end(),
                  message.begin(), ::tolower);

        stringstream ss(message);
        string word;

        int spamCount = 0;
        int totalWords = 0;

        while(ss >> word)
        {
            totalWords++;

            if(spamWords.count(word))
                spamCount++;
        }

        double confidence = 0;

        if(totalWords > 0)
            confidence = (double)spamCount / totalWords * 100;

        cout << "\nPrediction : ";

        if(spamCount >= 2)
            cout << "SPAM\n";
        else
            cout << "NOT SPAM\n";

        cout << "Confidence Score : "
             << fixed << setprecision(2)
             << confidence << "%\n";

        auto end = high_resolution_clock::now();

        auto duration =
        duration_cast<microseconds>(end - start);

        cout << "Prediction Time : "
             << duration.count()
             << " microseconds\n";
    }
};

int main()
{
    SpamDetector detector;

    string message;

    cout << "Enter Message: ";
    getline(cin, message);

    detector.predict(message);

    return 0;
}