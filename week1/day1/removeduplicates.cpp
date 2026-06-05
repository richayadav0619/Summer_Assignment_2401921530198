#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int k = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    int k = obj.removeDuplicates(nums);

    cout << "No. of unique elements: " << k << endl;
    cout << "Array after removing duplicates: ";

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}