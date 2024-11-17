#include<bits/stdc++.h>
using namespace std;
void printArray(vector<int>& arr);
void moveZeroToBack(vector<int>& arr);

void printArray(vector<int>& arr){
     for(int num:arr){
          cout<<num<<" ";
     }
} 

void moveZeroToBack(vector<int>& arr){
     int index = 0;
     for(int i = 0; i<arr.size();i++){
          if(arr[i]!=0){
               swap(arr[i],arr[index]);
               index++;
          }
     }
     cout<<endl;
     printArray(arr);
}


int main(){
     
     cout<<"Nawab khan"<<endl;

     vector<int> arr = {1,4,8,0,94,0,8,0,8,58,0,2,86,4,8,5,89,0,45,9,55,44};
     printArray(arr);
     moveZeroToBack(arr);

     return 0;
}