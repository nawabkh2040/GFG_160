#include <bits/stdc++.h>
using namespace std;

int minChar(string& s) {
    string reversed_s = s;
    reverse(reversed_s.begin(), reversed_s.end());
    string combined = s + "#" + reversed_s;

    int n = combined.length();
    vector<int> lps(n, 0);
    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];
        while (j > 0 && combined[i] != combined[j]) {
            j = lps[j - 1];
        }
        if (combined[i] == combined[j]) {
            j++;
        }
        lps[i] = j;
    }

    int longest_palindromic_prefix = lps[n - 1];
    return s.length() - longest_palindromic_prefix;
}

int main() {
    string s = "fxtlsgypsfa";
    cout << minChar(s) << endl;
    return 0;
}
