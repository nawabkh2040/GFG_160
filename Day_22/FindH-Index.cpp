#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate H-Index
int hIndex(vector<int>& citations) {
    // Step 1: Sort the array in descending order
    sort(citations.begin(), citations.end(), greater<int>());
    
    int h = 0;

    // Step 2: Find the largest H where H papers have at least H citations
    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] >= i + 1) {
            h = i + 1;
        } else {
            break;
        }
    }
    
    return h;
}

// Main function to test the hIndex function
int main() {
    // Example input
    vector<int> citations = {3, 0, 5, 3, 0};
    
    // Calculate H-Index
    int result = hIndex(citations);
    
    // Print the result
    cout << "The H-Index is: " << result << endl;
    
    // Additional test case
    citations = {5, 1, 2, 4, 1};
    result = hIndex(citations);
    cout << "The H-Index is: " << result << endl;

    return 0;
}
