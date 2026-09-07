#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool containsDuplicateWithinK(vector<string>& activities, int k)
{
    unordered_map<string, int> lastSeen;

    for (int i = 0; i < activities.size(); i++)
    {
        if (lastSeen.find(activities[i]) != lastSeen.end())
        {
            if (i - lastSeen[activities[i]] <= k)
            {
                return true; // Suspicious duplicate found
            }
        }

        lastSeen[activities[i]] = i;
    }

    return false;
}

int main()
{
    int n, k;

    cout << "Enter number of activities: ";
    cin >> n;

    vector<string> activities(n);

    cout << "Enter activities:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> activities[i];
    }

    cout << "Enter K distance: ";
    cin >> k;

    if (containsDuplicateWithinK(activities, k))
    {
        cout << "Suspicious duplicate activity detected within K distance." << endl;
    }
    else
    {
        cout << "No suspicious duplicate activity found." << endl;
    }

    return 0;
}