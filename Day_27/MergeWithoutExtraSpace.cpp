#include <bits/stdc++.h>
using namespace std;

void mergeArrays(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b.size();
    int gap = (n + m + 1) / 2; // Initial gap size
    
    while (gap > 0) {
        int i = 0, j = gap;
        
        // Compare elements in a[] and a[]
        while (j < n + m) {
            if (j < n && a[i] > a[j]) {
                swap(a[i], a[j]);
            } else if (j >= n && i < n && a[i] > b[j - n]) {
                swap(a[i], b[j - n]);
            } else if (j >= n && i >= n && b[i - n] > b[j - n]) {
                swap(b[i - n], b[j - n]);
            }
            i++;
            j++;
        }
        
        // Reduce the gap
        if (gap == 1) break;
        gap = (gap + 1) / 2;
    }
}

int main() {
    vector<int> a = {2, 4, 7, 10};
    vector<int> b = {2, 3};
    
    mergeArrays(a, b);
    
    // Print merged arrays
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << " ";
    }
    return 0;
}
