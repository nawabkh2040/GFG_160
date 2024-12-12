#include <bits/stdc++.h>
using namespace std;
int countFreq(vector<int> &arr, int target)
{
     // code here
     int n = arr.size();
     int count = 0;
     for (int i = 0; i < n; i++)
     {
          if (arr[i] == target)
          {
               count += 1;
          }
     }
     return count;
}

int main()
{
     cout << "Nawab khan" << endl;
     vector<int> arr = {1, 1, 2, 2, 2, 2, 3};
     int target = 2;
     cout<<countFreq(arr, target);

     return 0;
}