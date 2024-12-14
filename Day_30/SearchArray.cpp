#include <bits/stdc++.h>
using namespace std;
int searchElement(vector<int> &arr,int ke)
{
     for(int i =0;i<arr.size();i++){
          if(arr[i]==ke){
               return i;
          }
     }
     return -1;
}

int main()
{
     cout << "Nawab khan" << endl;
     vector<int> arr = {1, 1, 2, 2, 2, 2, 3};
     int ke = 2;
     cout<<searchElement(arr,ke);

     return 0;
}