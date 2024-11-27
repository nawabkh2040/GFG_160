#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> &arr);

int missingNumber(vector<int> &arr) {   
     int n = arr.size();
     for (int i = 0; i < n; i++) {
          while (arr[i] > 0 && arr[i] <= n && arr[i] != arr[arr[i] - 1]) {
               swap(arr[i], arr[arr[i] - 1]);
          }
     }
     for (int i = 0; i < n; i++) {
          if (arr[i] != i + 1) {
               return i + 1;
          }
     }
     return n + 1;
}

int main()
{
     cout << "Nawab khan" << endl;
     vector<int> arr = {2, -3, 4, 1, 1, 7};
     printArray(arr);
     cout<<"Missing Value is "<<missingNumber(arr);
     return 0;
}

void printArray(vector<int> &arr)
{
     cout << endl;
     for (int num : arr)
     {
          cout << num << " ";
     }
     cout << endl;
}