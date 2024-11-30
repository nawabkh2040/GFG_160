#include <bits/stdc++.h>
using namespace std;

bool areAnagrams(string s1, string s2) {
  
    if (s1.length() != s2.length())
        return false;

  
    unordered_map<char, int> count1, count2;
    for (char c : s1)
        count1[c]++;
    for (char c : s2)
        count2[c]++;

    return count1 == count2;
}

int main() {
    // Test cases
    string s1 = "geeks", s2 = "kseeg";
    cout << (areAnagrams(s1, s2) ? "true" : "false") << endl;

    s1 = "allergy", s2 = "allergic";
    cout << (areAnagrams(s1, s2) ? "true" : "false") << endl;

    return 0;
}
