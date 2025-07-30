#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target) {
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (target < arr[mid]) {
            end = mid - 1;
        } else if (target > arr[mid]) {
            start = mid + 1;
        } else {
            return mid; // target == arr[mid]
        }
    }
    return -1;
}

int main() {
    int target = 12;
    vector<int> arr1 = {1, 2, 4, 5, 6, 7, 12, 13, 14}; // ✅ sorted array

    int index = binarySearch(arr1, target);
    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found.";
}