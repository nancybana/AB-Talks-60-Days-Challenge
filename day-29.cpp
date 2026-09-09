#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    vector<string> hashtags = {
        "#AI", "#Coding", "#AI", "#Tech", "#Coding",
        "#AI", "#ML", "#Tech", "#Coding", "#AI"
    };

    int K = 3;

    unordered_map<string, int> freq;

    for (auto tag : hashtags) {
        freq[tag]++;
    }

    vector<pair<string, int>> result;

    for (auto item : freq) {
        result.push_back(item);
    }

    sort(result.begin(), result.end(),
         [](pair<string, int>& a, pair<string, int>& b) {
             return a.second > b.second;
         });

    cout << "Top " << K << " Trending Hashtags:\n";

    for (int i = 0; i < K && i < result.size(); i++) {
        cout << result[i].first << " -> "
             << result[i].second << " mentions\n";
    }

    return 0;
}