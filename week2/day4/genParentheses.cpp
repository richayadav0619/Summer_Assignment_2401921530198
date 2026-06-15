#include <iostream>
#include <vector>
using namespace std;

vector<string> result;

void solve(string curr, int open, int close, int n) {
    if (curr.length() == 2 * n) {
        result.push_back(curr);
        return;
    }

    if (open < n) {
        solve(curr + "(", open + 1, close, n);
    }

    if (close < open) {
        solve(curr + ")", open, close + 1, n);
    }
}

vector<string> genParenthesis(int n) {
    solve("", 0, 0, n);
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<string> ans = genParenthesis(n);

    for (string s : ans) {
        cout << s << endl;
    }

    return 0;
}