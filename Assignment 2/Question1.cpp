#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& nums, int k) {
    int n = nums.size();
    int l = 0;
    int r = n-1;
    while (l <= r) {
        int mid = (l+r)/2;
        if (nums[mid] < k) l = mid + 1;
        else if (nums[mid] > k) r = mid - 1;
        else return mid;
    }
    return -1;
}

int main() {
    vector<int> nums = {2,4,7,9,16,30,45};
    int index = binarySearch(nums, 30);
    if (index == -1) cout << "Element not found" << endl;
    else cout << "Element found at index " << index << endl;
    re