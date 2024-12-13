#include <bits/stdc++.h>
using namespace std;
int finMIn(vector<int> &arr)
{
     
     int min = *min_element(arr.begin(), arr.end());
     return min;
}

int main()
{
     cout << "Nawab khan" << endl;
     vector<int> arr = {1, 1, 2, 2, 2, 2, 3};
     cout<<finMIn(arr);

     return 0;
}