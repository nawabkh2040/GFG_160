#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n)
            return -1; // More students than books, invalid allocation

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int result = -1;

        auto isValidAllocation = [&](int maxPages) {
            int studentsRequired = 1;
            int currentPages = 0;

            for (int pages : arr) {
                if (pages > maxPages)
                    return false; // Single book exceeds max limit
                if (currentPages + pages > maxPages) {
                    studentsRequired++;
                    currentPages = pages;
                    if (studentsRequired > k)
                        return false; // More students needed than available
                } else {
                    currentPages += pages;
                }
            }
            return true;
        };

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isValidAllocation(mid)) {
                result = mid; // Valid allocation, try for smaller maximum
                high = mid - 1;
            } else {
                low = mid + 1; // Invalid allocation, increase the limit
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> arr1 = {12, 34, 67, 90};
    int k1 = 2;
    cout << "Output: " << sol.findPages(arr1, k1) << endl; // Expected: 113

    vector<int> arr2 = {15, 17, 20};
    int k2 = 5;
    cout << "Output: " << sol.findPages(arr2, k2) << endl; // Expected: -1

    vector<int> arr3 = {22, 23, 67};
    int k3 = 1;
    cout << "Output: " << sol.findPages(arr3, k3) << endl; // Expected: 112

    return 0;
}
