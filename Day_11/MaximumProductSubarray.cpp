#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int>& arr);
int maxProduct(vector<int> &arr) {
     
     int n = arr.size();   
     int max_product = arr[0];
     int current_max = arr[0];
     int current_min = arr[0];
     for (int i = 1; i < n; i++) {
          int num = arr[i];
          if (num < 0) {
               swap(current_max, current_min);
          }
          current_max = max(num, current_max * num);
          current_min = min(num, current_min * num);
          max_product = max(max_product, current_max);
     }

     return max_product;
}

int main() {
    cout << "Nawab khan" << endl;
    vector<int> arr = {-2, 6, -3, -10, 0, 2};
    printArray(arr);
    cout<<"The Total Sum of the Sub Array is "<<maxProduct(arr);
    return 0;
}


void printArray(vector<int>& arr){
     cout<<endl;
     for(int num:arr){
          cout<<num<<" ";
     }
     cout<<endl;
}