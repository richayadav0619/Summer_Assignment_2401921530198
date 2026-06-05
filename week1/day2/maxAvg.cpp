#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double maxAvg(vector<int>& nums, int k) {
        long long sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        long long maxSum = sum;
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k];
            if (sum > maxSum) {
                maxSum = sum;
            }
        }

        return (double)maxSum / k;
    }
};

int main() {
    int n, k;

    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    double result = obj.maxAvg(nums, k);

    cout << "Maximum Average = " << result << endl;

    return 0;
}