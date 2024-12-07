#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int inversionCount(vector<int>& arr) {
    auto mergeAndCount = [](vector<int>& arr, int left, int mid, int right) -> int {
        vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
        vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

        int i = 0, j = 0, k = left, invCount = 0;

        while (i < leftArr.size() && j < rightArr.size()) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k++] = leftArr[i++];
            } else {
                arr[k++] = rightArr[j++];
                invCount += (leftArr.size() - i); // Count inversions
            }
        }

        while (i < leftArr.size()) arr[k++] = leftArr[i++];
        while (j < rightArr.size()) arr[k++] = rightArr[j++];

        return invCount;
    };

    function<int(vector<int>&, int, int)> mergeSortAndCount = [&](vector<int>& arr, int left, int right) -> int {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;
        int invCount = mergeSortAndCount(arr, left, mid);
        invCount += mergeSortAndCount(arr, mid + 1, right);
        invCount += mergeAndCount(arr, left, mid, right);

        return invCount;
    };

    return mergeSortAndCount(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {2, 4, 1, 3, 5};

    cout << "Inversion Count: " << inversionCount(arr) << endl;

    return 0;
}
