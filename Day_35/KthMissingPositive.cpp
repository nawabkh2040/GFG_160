#include <bits/stdc++.h>
using namespace std;

// Function to find the kth missing positive number
int kthMissing(vector<int> &arr, int k) {
    int left = 0, right = arr.size() - 1;

    // Binary search to find the position where kth missing lies
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Count of missing numbers before arr[mid]
        int missingCount = arr[mid] - (mid + 1);

        if (missingCount < k) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    // If there are less than k missing numbers within the array, the answer lies outside
    return left + k;
}

int main() {
    // Input array and k
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    // Call the function and print the result
    cout << "The " << k << "th missing number is: " << kthMissing(arr, k) << endl;

    // Example 2
    arr = {1, 2, 3};
    k = 2;
    cout << "The " << k << "th missing number is: " << kthMissing(arr, k) << endl;

    // Example 3
    arr = {3, 5, 9, 10, 11, 12};
    k = 2;
    cout << "The " << k << "th missing number is: " << kthMissing(arr, k) << endl;

    return 0;
}
