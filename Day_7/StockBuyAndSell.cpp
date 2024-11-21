#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int>& prices);
int stockByuAndSell(vector<int>& prices);

int stockByuAndSell(vector<int>& prices){
     int n = prices.size();
     int profit = 0;
     for(int i = 1; i<n ; i++){
          if(prices[i]>prices[i-1]){
               profit += prices[i] - prices[i-1];
          }
     }
     return profit;
}



int main() {
    cout << "Nawab khan" << endl;
    vector<int> prices = {100, 180, 260, 310, 40, 535, 695};
    vector<int> prices1 = {86, 92, 24, 5, 34, 72, 68, 52, 27, 95, 41, 28, 35};
    vector<int> prices2 = {4, 2, 2, 2, 4};
    printArray(prices1);

    cout<<"profit is "<<stockByuAndSell(prices1);


    return 0;
}

void printArray(vector<int>& prices){
     cout<<endl;
     for(int num : prices){
          cout<<num<<" ";
     }
     cout<<endl;
}