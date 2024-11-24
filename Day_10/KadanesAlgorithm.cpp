#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int>& arr);
int maxOfSubArray(vector<int>& arr){
     int sum = 0;
     int n = arr.size();
     int maxi = INT_MIN;   
     for(int i = 0; i<n; i++){
          sum += arr[i];
          if(sum>maxi){
               maxi = sum;
          }
          if(sum<0){
               sum = 0;
          }
     }
     return maxi;
}

int main() {
    cout << "Nawab khan" << endl;
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3}; // it Should Give Output 11
    printArray(arr);
    cout<<"The Maximum sum of the Sub Array is "<<maxOfSubArray(arr)<<endl;
    return 0;
}


void printArray(vector<int>& arr){
     cout<<endl;
     for(int num:arr){
          cout<<num<<" ";
     }
     cout<<endl;
}