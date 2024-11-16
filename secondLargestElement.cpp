#include<bits/stdc++.h>
using namespace std;
void printArray(vector<int>& arr);
int secondLargeElement(vector<int>& arr);

void printArray(vector<int>& arr){
     for(int num: arr){
          cout<<num<<" ";
     }
}


int secondLargeElement(vector<int>& arr){
     if(arr.size() < 2){
          return -1;
     }
     int large = INT_MIN;
     int secondLarge = INT_MIN;
     for(int num:arr){
          if(num>large){
               secondLarge = large;
               large = num;
          }else if(num>secondLarge && num < large){
               secondLarge = num;
          }
     }
     if(secondLarge==INT_MIN){
          return -1;
     }else{
          return secondLarge;
     }
}

int main(){
     cout<<"Nawab khan"<<endl;
     vector<int> arr ={1,5,7,58,6,9,49,4};
     printArray(arr);
     cout<<endl;
     cout<<"Second Large Element is "<<secondLargeElement(arr)<<endl;   
     return 0;
}