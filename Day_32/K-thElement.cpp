#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int>& a, vector<int>& b, int k) {
    int n1 = a.size(), n2 = b.size();

    // Ensure the first array is the smaller one
    if (n1 > n2) return kthElement(b, a, k);

    int low = max(0, k - n2), high = min(k, n1);

    while (low <= high) {
        int cut1 = (low + high) / 2;   // Partition point in a[]
        int cut2 = k - cut1;          // Partition point in b[]

        int left1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1]; // Left max of a[]
        int left2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1]; // Left max of b[]
        int right1 = (cut1 == n1) ? INT_MAX : a[cut1];   // Right min of a[]
        int right2 = (cut2 == n2) ? INT_MAX : b[cut2];   // Right min of b[]

        if (left1 <= right2 && left2 <= right1) {
            // Valid partition
            return max(left1, left2);
        } else if (left1 > right2) {
            // Move left in a[]
            high = cut1 - 1;
        } else {
            // Move right in a[]
            low = cut1 + 1;
        }
    }
    return -1; // Invalid input, should not happen for valid k
}

int main() {
    // Test case 1
    vector<int> a1 = {2, 3, 6, 7, 9};
    vector<int> b1 = {1, 4, 8, 10};
    int k1 = 5;
    cout << "The " << k1 << "th element is: " << kthElement(a1, b1, k1) << endl;

    // Test case 2
    vector<int> a2 = {100, 112, 256, 349, 770};
    vector<int> b2 = {72, 86, 113, 119, 265, 445, 892};
    int k2 = 7;
    cout << "The " << k2 << "th element is: " << kthElement(a2, b2, k2) << endl;

    // Test case 3
    vector<int> a3 = {1, 3, 8};
    vector<int> b3 = {2, 4, 5, 6, 7, 9};
    int k3 = 4;
    cout << "The " << k3 << "th element is: " << kthElement(a3, b3, k3) << endl;

    return 0;
}
