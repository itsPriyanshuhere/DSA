#include <iostream>
#include <climits>
using namespace std;

pair<int, int> maxmin(int arr[], int low, int high) {
    if (low == high) {
        // Only one element in the array
        return make_pair(arr[low], arr[low]);
    } else if (high == low + 1) {
        // Two elements in the array
        if (arr[low] > arr[high]) {
            return make_pair(arr[low], arr[high]);
        } else {
            return make_pair(arr[high], arr[low]);
        }
    } else {
        // Divide the array into two halves
        int mid = (low + high) / 2;
        pair<int, int> left = maxmin(arr, low, mid);
        pair<int, int> right = maxmin(arr, mid + 1, high);

        // Find the maximum and minimum values
        int max_val = max(left.first, right.first);
        int min_val = min(left.second, right.second);

        return make_pair(max_val, min_val);
    }
}

int main() {
    int arr[] = {5, 9, 3, 2, 8, 4, 7, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    pair<int, int> result = maxmin(arr, 0, n - 1);

    cout << "Max value: " << result.first << endl;
    cout << "Min value: " << result.second << endl;

    return 0;
}
