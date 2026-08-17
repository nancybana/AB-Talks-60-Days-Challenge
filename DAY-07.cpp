#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int minPrice = prices[0];
    int buyDay = 0;

    int maxProfit = 0;
    int sellDay = -1;
    int bestBuyDay = 0;

    for (int i = 1; i < prices.size(); i++) {

        if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
            sellDay = i;
            bestBuyDay = buyDay;
        }

        if (prices[i] < minPrice) {
            minPrice = prices[i];
            buyDay = i;
        }
    }

    cout << "Maximum Profit = " << maxProfit << endl;

    if (maxProfit > 0) {
        cout << "Buy on Day " << bestBuyDay
             << " (Price = " << prices[bestBuyDay] << ")" << endl;

        cout << "Sell on Day " << sellDay
             << " (Price = " << prices[sellDay] << ")" << endl;
    } else {
        cout << "No profit possible." << endl;
    }

    return 0;
}