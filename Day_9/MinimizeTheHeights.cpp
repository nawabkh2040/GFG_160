#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int>& arr);
int getMinDiff(vector<int> &arr, int k);

int getMinDiff(vector<int> &arr, int k){
        
        int n = arr.size();
        if(n==1) return 0;
        sort(arr.begin(),arr.end());
        int diff = arr[n-1]-arr[0];
        int mini , maxe;
        for(int i = 1; i<n ; i++){
            if(arr[i]-k < 0) continue;
            maxe = max(arr[i-1]+k ,arr[n-1]-k);
            mini = min(arr[i]-k,arr[0]+k);
            diff = min(diff,maxe-mini);   
        }
        return diff;
}

int main() {
    cout << "Nawab khan" << endl;
    vector<int> arr = {3, 9, 12, 16, 20};
    printArray(arr);
    cout<<endl;
    int k = 3;
    int min = getMinDiff(arr,k);
  
    cout<<"The min is "<<min;
    printArray(arr);


    return 0;
}

void printArray(vector<int>& arr){
     cout<<endl;
     for(int num:arr){
          cout<<num<<" ";
     }
     cout<<endl;
}