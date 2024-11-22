#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int>& arr);
int stockBuyAndSell(vector<int>& prices);

int stockBuyAndSell(vector<int>& prices) {
    if (prices.size() < 2) return 0; // Edge case: less than 2 prices

    int buy = prices[0]; // Minimum price to buy
    int sell = prices[0]; // Maximum price to sell after buying
    int max_profit = 0; // Maximum profit

    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] < buy) {
            // Update buy price if a lower price is found
            buy = prices[i];
            cout << "Buy at " << buy << endl;
        }
        if (prices[i] > sell && prices[i] - buy > max_profit) {
            // Update sell price if a higher profit can be achieved
            sell = prices[i];
            max_profit = sell - buy;
            cout << "Sell at " << sell << endl;
        }
    }

    return max_profit;
}

int main() {
    cout << "Nawab Khan" << endl;
    vector<int> prices = {1, 3, 6, 9, 11};
    vector<int> prices1 = {7, 10, 1, 3, 6, 9, 2};
    vector<int> prices2 = {7, 6, 4, 3, 1};
    vector<int> prices3 = {23, 3, 32};
    vector<int> prices4 = {61, 44, 70, 78, 73, 95, 27, 1};

    printArray(prices4);
    cout << "The Max Profit is " << stockBuyAndSell(prices4) << endl;

    return 0;
}

void printArray(vector<int>& arr) {
    cout << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}
