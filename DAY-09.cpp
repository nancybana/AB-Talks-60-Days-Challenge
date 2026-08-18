#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {5, 2, 8, 3, 6, 1};

    int n = arr.size();

    vector<int> prefix(n);

    prefix[0] = arr[0];

    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    cout << "Prefix Sum Array: ";
    for (int x : prefix) {
        cout << x << " ";
    }
    cout << endl;

    vector<pair<int, int>> queries = {
        {0, 2},
        {1, 4},
        {2, 5}
    };

    for (auto q : queries) {
        int left = q.first;
        int right = q.second;

        int rangeSum;

        if (left == 0)
            rangeSum = prefix[right];
        else
            rangeSum = prefix[right] - prefix[left - 1];

        cout << "Sum from " << left << " to "
             << right << " = "
             << rangeSum << endl;
    }

    return 0;
}