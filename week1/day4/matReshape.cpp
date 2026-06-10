#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();

        // Check if reshape is possible
        if (m * n != r * c) {
            return mat;
        }

        vector<vector<int>> result(r, vector<int>(c));

        for (int i = 0; i < m * n; i++) {
            result[i / c][i % c] = mat[i / n][i % n];
        }

        return result;
    }
};

int main() {
    int m, n;

    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    int r, c;
    cout << "Enter desired rows and columns: ";
    cin >> r >> c;

    Solution obj;
    vector<vector<int>> result = obj.matrixReshape(mat, r, c);

    cout << "\nReshaped Matrix:\n";
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}