include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (nums[j] > nums[j+1]) {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
}

int main() {
    vector<int> nums = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(nums);
    cout << "Sorted array is:\n";
    for (int i: nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}