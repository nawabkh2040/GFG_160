#include <bits/stdc++.h>
using namespace std;

vector<int> search(string& pat, string& txt) {
    int n = txt.size();
    int m = pat.size();
    vector<int> result;

    if (m > n) return result; // If pattern is longer than text, no match is possible.

    // Step 1: Build the LPS array
    vector<int> lps(m, 0);
    int len = 0, i = 1;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    // Step 2: Pattern matching using the LPS array
    i = 0; // Index for txt
    int j = 0; // Index for pat

    while (i < n) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
        }

        if (j == m) { // A match is found
            result.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && txt[i] != pat[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return result;
}

int main() {
    string txt, pat;

    // Input text and pattern
    cout << "Enter the text: ";
    getline(cin, txt);

    cout << "Enter the pattern: ";
    getline(cin, pat);

    // Find pattern occurrences
    vector<int> indices = search(pat, txt);

    // Output the result
    if (indices.empty()) {
        cout << "No occurrences found." << endl;
    } else {
        cout << "Pattern found at indices: ";
        for (int index : indices) {
            cout << index << " ";
        }
        cout << endl;
    }

    return 0;
}
