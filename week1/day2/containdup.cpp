#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDup(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int num : nums) {
            if (mp[num] > 0) {
                return true;
            }
            mp[num]++;
        }

        return false;
    }
};

int main() {
    int n;

    cout << "Enter number: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;

    if (sol.containsDup(nums)) {
        cout << "Duplicate exists" << endl;
    } else {
        cout << "No duplicate element" << endl;
    }

    return 0;
}