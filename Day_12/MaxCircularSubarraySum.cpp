#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> &arr);

int circularSubarraySum(vector<int> &arr)
{

     int n = arr.size();

     int max_kadane = arr[0];
     int max_ending_here = arr[0];
     for (int i = 1; i < n; ++i){
          max_ending_here = max(arr[i], max_ending_here + arr[i]);
          max_kadane = max(max_kadane, max_ending_here);
     }

     int total_sum = 0;
     for (int i = 0; i < n; ++i){
          total_sum += arr[i];
     }

     int min_kadane = arr[0];
     int min_ending_here = arr[0];
     for (int i = 1; i < n; ++i){
          min_ending_here = min(arr[i], min_ending_here + arr[i]);
          min_kadane = min(min_kadane, min_ending_here);
     }

     int circular_sum = total_sum - min_kadane;

     if (circular_sum == 0){
          return max_kadane;
     }

     return max(max_kadane, circular_sum);
}

int main()
{
     cout << "Nawab khan" << endl;
     vector<int> arr1 = {8, -8, 9, -9, 10, -11, 12};
     vector<int> arr2 = {10, -3, -4, 7, 6, 5, -4, -1};
     vector<int> arr3 = {-1, 40, -14, 7, 6, 5, -4, -1};
     printArray(arr1);
     cout << circularSubarraySum(arr1) << endl; // Output: 22
     printArray(arr2);
     cout << circularSubarraySum(arr2) << endl; // Output: 23
     printArray(arr3);
     cout << circularSubarraySum(arr3) << endl; // Output: 52
     

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