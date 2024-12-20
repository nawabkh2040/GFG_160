#include <bits/stdc++.h>
using namespace std;

// Function to traverse the matrix in spiral order
vector<int> spirallyTraverse(vector<vector<int>> &mat) {
    vector<int> result;
    int n = mat.size();
    int m = mat[0].size();

    int top = 0, bottom = n - 1, left = 0, right = m - 1;

    while (top <= bottom && left <= right) {
        // Traverse from left to right along the top row
        for (int i = left; i <= right; ++i) {
            result.push_back(mat[top][i]);
        }
        top++;  // Move the top boundary down

        // Traverse from top to bottom along the right column
        for (int i = top; i <= bottom; ++i) {
            result.push_back(mat[i][right]);
        }
        right--;  // Move the right boundary left

        if (top <= bottom) {
            // Traverse from right to left along the bottom row
            for (int i = right; i >= left; --i) {
                result.push_back(mat[bottom][i]);
            }
            bottom--;  // Move the bottom boundary up
        }

        if (left <= right) {
            // Traverse from bottom to top along the left column
            for (int i = bottom; i >= top; --i) {
                result.push_back(mat[i][left]);
            }
            left++;  // Move the left boundary right
        }
    }

    return result;
}

int main() {
    // Example input
    vector<vector<int>> mat1 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<vector<int>> mat2 = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18}
    };

    // Output for mat1
    vector<int> result1 = spirallyTraverse(mat1);
    cout << "Spiral traversal of mat1: ";
    for (int val : result1) {
        cout << val << " ";
    }
    cout << endl;

    // Output for mat2
    vector<int> result2 = spirallyTraverse(mat2);
    cout << "Spiral traversal of mat2: ";
    for (int val : result2) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
