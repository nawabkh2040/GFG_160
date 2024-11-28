#include <bits/stdc++.h>
using namespace std;

// Function to print an array
void printArray(vector<int> &arr) {
    cout << "Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Function to find split indices
vector<int> findSplit(vector<int> &arr) {
    int totalSum = 0;

    // Calculate the total sum of the array
    for (int num : arr) {
        totalSum += num;
    }

    // If the total sum is not divisible by 3, split is not possible
    if (totalSum % 3 != 0) {
        return {-1, -1};
    }

    int targetSum = totalSum / 3;
    int n = arr.size();
    int runningSum = 0, firstIdx = -1, secondIdx = -1;

    // Iterate to find split points
    for (int i = 0; i < n; i++) {
        runningSum += arr[i];

        if (runningSum == targetSum && firstIdx == -1) {
            firstIdx = i; // First split point
        } else if (runningSum == 2 * targetSum && firstIdx != -1) {
            secondIdx = i; // Second split point
            break;
        }
    }

    // If valid split points found, return them
    if (firstIdx != -1 && secondIdx != -1) {
        return {firstIdx, secondIdx};
    }

    // If no valid splits, return {-1, -1}
    return {-1, -1};
}

// Main function
int main() {
    cout << "Nawab Khan" << endl;

    // Test input
    vector<int> arr = {1, 3, 4, 0, 4};

    // Print the array
    printArray(arr);

    // Find and print the split indices
    vector<int> splitIndices = findSplit(arr);
    if (splitIndices[0] != -1 && splitIndices[1] != -1) {
        cout << "Split Indices: " << splitIndices[0] << ", " << splitIndices[1] << endl;
    } else {
        cout << "No valid split found." << endl;
    }

    return 0;
}
