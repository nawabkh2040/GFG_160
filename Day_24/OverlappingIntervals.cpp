#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to merge overlapping intervals
vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
    // Sort the intervals based on the start time
    sort(arr.begin(), arr.end());

    // Vector to store the merged intervals
    vector<vector<int>> merged;

    // Iterate over the sorted intervals
    for (const auto& interval : arr) {
        // If the merged vector is empty or the current interval does not overlap with the last interval in merged
        if (merged.empty() || merged.back()[1] < interval[0]) {
            // Add the interval to merged
            merged.push_back(interval);
        } else {
            // Merge the current interval with the last interval in merged
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }

    return merged;
}

// Main function
int main() {
    // Example input
    vector<vector<int>> intervals = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};

    // Call the mergeOverlap function
    vector<vector<int>> result = mergeOverlap(intervals);

    // Print the result
    cout << "Merged Intervals: ";
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}
