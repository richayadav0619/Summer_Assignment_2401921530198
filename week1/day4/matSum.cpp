#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += mat[i][i];           // Primary diagonal
            sum += mat[i][n - 1 - i];   // Secondary diagonal
        }

        // If n is odd, middle element was counted twice
        if (n % 2 == 1) {
            sum -= mat[n / 2][n / 2];
        }

        return sum;
    }
};

int main() {
    int n;
    cout << "Enter matrix size (n x n): ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    Solution obj;
    int result = obj.diagonalSum(mat);

    cout << "Diagonal Sum = " << result << endl;

    return 0;
}