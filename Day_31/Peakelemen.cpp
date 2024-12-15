#include <bits/stdc++.h>
using namespace std;

int peakElement(vector<int> &arr) {
    int n = arr.size();
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if ((mid == 0 || arr[mid - 1] < arr[mid]) && (mid == n - 1 || arr[mid] > arr[mid + 1])) {
            return mid;
        }

        if (mid < n - 1 && arr[mid] < arr[mid + 1]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1;
}


int main() {
    vector<int> arr1 = {1, 2, 4, 5, 7, 8, 3};
    vector<int> arr2 = {10, 20, 15, 2, 23, 90, 80};
    vector<int> arr3 = {1, 2, 3};

    cout << peakElement(arr1) << endl;
    cout << peakElement(arr2) << endl;
    cout << peakElement(arr3) << endl;

    return 0;
}
