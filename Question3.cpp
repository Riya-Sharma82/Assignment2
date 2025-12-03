#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1)
            return i + 1;
    }
    return n;
}

int findMissingBinary(int arr[], int n) {
    int left = 0;
    int right = n - 2;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == mid + 1)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left + 1;
}

int main() {
    int arr1[] = {1, 2, 3, 5, 6};
    int n1 = 6;

    cout << "Missing (Linear): " << findMissingLinear(arr1, n1) << endl;
    cout << "Missing (Binary): " << findMissingBinary(arr1, n1) << endl;

    return 0;
}
