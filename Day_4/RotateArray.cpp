#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int>& arr);
void firstApproach(vector<int>& arr, int d);
void optimizeApproach(vector<int>& arr,int d);


int main() {
    cout << "Nawab khan" << endl;
    vector<int> arr = {7, 3, 9, 1};
    int d = 9;
    printArray(arr);
    // Check First Approach 
//     cout<<endl;
//     firstApproach(arr,d);
//     printArray(arr);
//     cout<<endl;
//     cout<<"First Approach Takes O(nxd) Time Complexity"<<endl;
    // Optimize Approach it Takes O(n) Time Complexity 
    optimizeApproach(arr,d);
    cout<<endl;
    printArray(arr);
    cout<<endl;
    cout<<"Second (Optimize) Approach Takes O(n) Time Complexity"<<endl;
    
    return 0;
}

void printArray(vector<int>& arr){
     for (int num : arr){
          cout<<num<<" ";
     }
     
}

void firstApproach(vector<int>& arr, int d){
     int size = arr.size();
     if(size==0)return ;
     d = d%size;
     if(d==0) return ;
     for(int i = 0; i < d ; i++){
          arr.push_back(arr[0]);
          arr.erase(arr.begin());
     }
}

void optimizeApproach(vector<int>& arr,int d){
     int size = arr.size();
     if(size==0) return ;
     d = d%size;
     if(d==0) return ;
     reverse(arr.begin(),arr.begin()+d);
     reverse(arr.begin()+d,arr.end());
     reverse(arr.begin(),arr.end());

    
}