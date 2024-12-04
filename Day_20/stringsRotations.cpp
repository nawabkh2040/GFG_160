#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool areRotations(string &s1, string &s2) {
    // Check if strings are of equal length
    if (s1.length() != s2.length()) {
        return false;
    }

    // Check if s2 is a substring of s1 concatenated with itself
    string doubled_s1 = s1 + s1;
    if (doubled_s1.find(s2) == string::npos) {
        return false;
    }

    // Ensure both strings have the same character frequencies
    string sorted_s1 = s1;
    string sorted_s2 = s2;
    sort(sorted_s1.begin(), sorted_s1.end());
    sort(sorted_s2.begin(), sorted_s2.end());
    
    return sorted_s1 == sorted_s2;
}

int main() {
    string s1, s2;


    s1 = "mightandmagic";
    s2 = "andmagicmigth";
    cout << "Example 1: " << (areRotations(s1, s2) ? "true" : "false") << endl; // Output: false


    s1 = "abcd";
    s2 = "cdab";
    cout << "Example 2: " << (areRotations(s1, s2) ? "true" : "false") << endl; // Output: true


    s1 = "aab";
    s2 = "aba";
    cout << "Example 3: " << (areRotations(s1, s2) ? "true" : "false") << endl; // Output: true

    return 0;
}
