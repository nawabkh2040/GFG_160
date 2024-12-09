#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval) {
    vector<vector<int>> result;
    int i = 0, n = intervals.size();

    // Add all intervals that come before the new interval
    while (i < n && intervals[i][1] < newInterval[0]) {
        result.push_back(intervals[i]);
        i++;
    }

    // Merge overlapping intervals with the new interval
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    result.push_back(newInterval); // Add the merged interval

    // Add all intervals that come after the new interval
    while (i < n) {
        result.push_back(intervals[i]);
        i++;
    }

    return result;
}

int main() {
    // Example 1
    vector<vector<int>> intervals1 = {{1, 3}, {4, 5}, {6, 7}, {8, 10}};
    vector<int> newInterval1 = {5, 6};
    vector<vector<int>> result1 = insertInterval(intervals1, newInterval1);

    cout << "Result for Example 1:" << endl;
    for (const auto &interval : result1) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    // Example 2
    vector<vector<int>> intervals2 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval2 = {4, 9};
    vector<vector<int>> result2 = insertInterval(intervals2, newInterval2);

    cout << "Result for Example 2:" << endl;
    for (const auto &interval : result2) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
