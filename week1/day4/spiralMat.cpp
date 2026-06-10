#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {

            // Left to Right
            for (int j = left; j <= right; j++) {
                result.push_back(matrix[top][j]);
            }
            top++;

            // Top to Bottom
            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;

            // Right to Left
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    result.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            // Bottom to Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return result;
    }
};

int main() {
    int m, n;

    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution obj;
    vector<int> result = obj.spiralOrder(matrix);

    cout << "Spiral Order: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}