#include <iostream>
#include <vector>
using namespace std;

int findUnique(vector<int> &arr) {
    int result = 0;
    for (int num : arr) {
        result ^= num;
    }
    return result;
}

int main() {
    vector<int> arr = {2, 3, 5, 4, 5, 3, 4};
    cout << "Unique element is: " << findUnique(arr) << endl;
    return 0;
}
