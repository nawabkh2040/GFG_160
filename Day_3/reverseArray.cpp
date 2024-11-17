#include<bits/stdc++.h>
using namespace std;
void printArray(vector <int>& arr);
void reversArr(vector<int>& arr);

void printArray(vector <int>& arr){
     for(int num:arr){
          cout<<num<<" ";
     }
}


void reversArr(vector<int>& arr){
     int f = 0;
     int l = arr.size()-1;
     while(l>f){
          swap(arr[l],arr[f]);
          l--;
          f++;
     }

}

int main(){
    
     cout<<"Nawab khan "<<endl;
     vector<int> arr = {1,4,5,8,5,9,5,0,5,9,5,6,9};
     printArray(arr);
     cout<<endl;
     reversArr(arr);
     cout<<endl;
     printArray(arr);
     return 0;

}