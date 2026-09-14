#include <iostream>
#include <vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    long long windowSum = 0;

    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }

    long long maxSum = windowSum;

    for (int i = k; i < nums.size(); i++) {
        windowSum += nums[i];
        windowSum -= nums[i - k];

        maxSum = max(maxSum, windowSum);
    }

    return (double)maxSum / k;
}

int main() {
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    cout << findMaxAverage(nums);
    return 0;
}