#include <iostream>
#include <vector>
using namespace std;

int climbStairsMemo(int n, vector<int>& dp)
{
    if (n == 0 || n == 1)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] =
        climbStairsMemo(n - 1, dp) +
        climbStairsMemo(n - 2, dp);
}

int main()
{
    int n;
    cout << "Enter number of steps: ";
    cin >> n;

    vector<int> dp(n + 1, -1);

    cout << "Ways = "
         << climbStairsMemo(n, dp)
         << endl;

    return 0;
}