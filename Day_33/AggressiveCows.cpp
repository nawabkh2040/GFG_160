#include <bits/stdc++.h>
using namespace std;

int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    
    auto canPlaceCows = [&](int minDist) {
        int count = 1;
        int lastPos = stalls[0];
        
        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPos >= minDist) {
                count++;
                lastPos = stalls[i];
                if (count == k) {
                    return true;
                }
            }
        }
        return false;
    };

    int low = 1, high = stalls.back() - stalls.front();
    int result = 0;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlaceCows(mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return result;
}

int main() {
    vector<int> stalls1 = {1, 2, 4, 8, 9};
    int k1 = 3;
    cout << aggressiveCows(stalls1, k1) << endl;

    vector<int> stalls2 = {10, 1, 2, 7, 5};
    int k2 = 3;
    cout << aggressiveCows(stalls2, k2) << endl;

    vector<int> stalls3 = {2, 12, 11, 3, 26, 7};
    int k3 = 5;
    cout << aggressiveCows(stalls3, k3) << endl;

    return 0;
}
