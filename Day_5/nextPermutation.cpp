#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int>& arr);
void nextPermutation(vector<int>& arr);



void nextPermutation(vector<int>& arr){
     int n = arr.size()-1;
     int index = -1;
     for(int i = n-1;i>=0;i--){
          if(arr[i]<arr[i+1]){
               index = i;
               break;
          }
     }

     if(index == -1){
          reverse(arr.begin(),arr.end());
          return ;
     }

     for(int i = n;i>=index;i--){
          if(arr[i]>arr[index]){
               swap(arr[i],arr[index]);
               break;
          }
     }

     reverse(arr.begin()+index,arr.end());
}

int main() {
    cout << "Nawab khan" << endl;
    vector<int> arr = {2, 4, 1, 7, 5, 0};
    printArray(arr);
    cout<<endl;
    nextPermutation(arr);
    cout<<endl;
    printArray(arr);


    return 0;
}

void printArray(vector<int>& arr){
     for(int num:arr){
          cout<<num<<" ";
     }
}