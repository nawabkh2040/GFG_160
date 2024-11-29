#include <bits/stdc++.h>
using namespace std;

string addBinary(string& s1, string& s2) {
    s1.erase(0, s1.find_first_not_of('0'));
    s2.erase(0, s2.find_first_not_of('0'));
    if (s1.length() < s2.length()) swap(s1, s2);
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    string result;
    int carry = 0;
    for (size_t i = 0; i < s1.length(); i++) {
        int bit1 = s1[i] - '0';
        int bit2 = (i < s2.length()) ? s2[i] - '0' : 0;
        int sum = bit1 + bit2 + carry;
        result.push_back((sum % 2) + '0');
        carry = sum / 2;
    }
    if (carry) result.push_back('1');
    reverse(result.begin(), result.end());
    return result.empty() ? "0" : result;
}

int main() {
    string s1, s2;
    cout << "Enter first binary string: ";
    cin >> s1;
    cout << "Enter second binary string: ";
    cin >> s2;
    string result = addBinary(s1, s2);
    cout << "Resultant binary string: " << result << endl;
    return 0;
}
