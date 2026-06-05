#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (currentSum + nums[i] > nums[i])
                currentSum = currentSum + nums[i];
            else
                currentSum = nums[i];

            if (currentSum > maxSum)
                maxSum = currentSum;
        }

        return maxSum;
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    Solution obj;
    cout << "Maximum Subarray Sum: " << obj.maxSubArray(nums) << endl;

    return 0;
}