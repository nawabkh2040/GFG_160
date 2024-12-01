#include <bits/stdc++.h>
using namespace std;

char nonRepeatingChar(const string& s) {
    unordered_map<char, int> freq;

    // Count frequencies
    for (char ch : s) {
        cout << "Processing character: " << ch << endl;
        freq[ch]++;
    }

    // Find first non-repeating character
    for (char ch : s) {
        cout << "Checking character: " << ch << " with frequency: " << freq[ch] << endl;
        if (freq[ch] == 1) {
            return ch;
        }
    }

    // If no non-repeating character found
    return '$';
}

int main() {
    cout << "Nawab Khan" << endl;
    string s = "geeksforgeeks";
    cout << "Here is the string: " << s << endl;
    char result = nonRepeatingChar(s);
    if (result == '$') {
        cout << "No non-repeating character found!" << endl;
    } else {
        cout << "The First Non-Repeating Character is: " << result << endl;
    }

    return 0;
}
