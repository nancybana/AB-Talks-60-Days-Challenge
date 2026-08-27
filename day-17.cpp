#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(vector<string>& gems, int index,
                     vector<string>& current,
                     vector<vector<string>>& result)
{
    if(index == gems.size())
    {
        result.push_back(current);
        return;
    }
    current.push_back(gems[index]);
    generateSubsets(gems, index + 1, current, result);
    current.pop_back();
    generateSubsets(gems, index + 1, current, result);
}

int main()
{
    vector<string> gems = {"Ruby", "Emerald", "Diamond"};

    vector<vector<string>> result;
    vector<string> current;

    generateSubsets(gems, 0, current, result);

    cout << "All Possible Gem Combinations:\n\n";

    for(auto subset : result)
    {
        cout << "{ ";
        for(auto gem : subset)
            cout << gem << " ";
        cout << "}\n";
    }

    cout << "\nTotal Combinations = " << result.size() << endl;

    return 0;
}