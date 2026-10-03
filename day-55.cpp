#include<bits/stdc++.h>
using namespace std;

bool isSpam(string message)
{
    vector<string> spamWords = {
        "win", "prize", "free", "offer",
        "cash", "urgent", "claim", "lottery"
    };

    transform(message.begin(), message.end(),
              message.begin(), ::tolower);

    for(string word : spamWords)
    {
        if(message.find(word) != string::npos)
            return true;
    }

    return false;
}

int main()
{
    string message;

    cout << "Enter Message: ";
    getline(cin, message);

    if(isSpam(message))
        cout << "Spam Message";
    else
        cout << "Not Spam Message";

    return 0;
}