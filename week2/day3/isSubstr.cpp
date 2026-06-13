#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool repSub(string s) {
        int n = s.size();

        for (int len = 1; len <= n / 2; len++) {
            if (n % len != 0)
                continue;

            string pattern = s.substr(0, len);
            string formed = "";

            int times = n / len;

            for (int i = 0; i < times; i++) {
                formed += pattern;
            }

            if (formed == s)
                return true;
        }

        return false;
    }
};

int main() {
    string s;

    cout << "Enter string: ";
    cin >> s;

    Solution obj;

    if (obj.repSub(s))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}