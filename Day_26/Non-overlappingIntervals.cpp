#include <bits/stdc++.h>
using namespace std;

int minRemoval(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[1] < b[1];
    });

    int count = 0;
    int end = INT_MIN;

    for (const auto &interval : intervals) {
        if (interval[0] >= end) {
            end = interval[1];
        } else {
            count++;
        }
    }

    return count;
}

int main() {
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << minRemoval(intervals) << endl;

    intervals = {{1, 3}, {1, 3}, {1, 3}};
    cout << minRemoval(intervals) << endl;

    intervals = {{1, 2}, {5, 10}, {18, 35}, {40, 45}};
    cout << minRemoval(intervals) << endl;

    return 0;
}
