#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int>& arr);

void printArray(vector<int>& arr){
     if(arr.size()<1){
          cout<<"Array is Empty"<<endl;
     }else{
          for(int num:arr){
               cout<<num<<" ";
          }
     }
}

void majorityElements(vector<int>& arr){
     int n = arr.size();
     unordered_map<int,int> map;
     vector<int> majority;
     for(int i =0;i<n; i++ ){
          map[arr[i]]++;
     }

     for(auto x: map){
          if(x.second>(n/3)){
               majority.push_back(x.first);
          }
     }
     printArray(majority);

}


int main() {
    cout << "Nawab khan" << endl;
    // Write your code here

    vector<int> arr={2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6};
    vector<int> arr1={1, 2, 3, 4, 5};
    cout<<"Test Case 1"<<endl;
    printArray(arr);
    cout<<endl;
    majorityElements(arr);
    cout<<endl;
    cout<<"Test Case 2"<<endl;
    printArray(arr1);
    cout<<endl;
    majorityElements(arr1);

    return 0;
}