#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int res = 0;

    while (left < right) {
        int area = min(height[left], height[right]) * (right - left);
        res = max(res, area);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return res;
}

int main() {
    int n;

    cout << "Enter number of heights: ";
    cin >> n;

    vector<int> height(n);

    cout << "Enter heights: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    int result = maxArea(height);

    cout << "Maximum Area = " << result << endl;

    return 0;
}