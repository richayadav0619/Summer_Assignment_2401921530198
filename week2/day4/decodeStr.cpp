#include <iostream>
#include <stack>
#include <string>
using namespace std;

string decodeString(string s) {
    stack<int> numStack;
    stack<string> strStack;

    string currStr = "";
    int currNum = 0;

    for (char ch : s) {

        if (isdigit(ch)) {
            currNum = currNum * 10 + (ch - '0');
        }

        else if (ch == '[') {
            numStack.push(currNum);
            strStack.push(currStr);

            currNum = 0;
            currStr = "";
        }

        else if (ch == ']') {
            int repeat = numStack.top();
            numStack.pop();

            string temp = currStr;

            currStr = strStack.top();
            strStack.pop();

            while (repeat--) {
                currStr += temp;
            }
        }

        else {
            currStr += ch;
        }
    }

    return currStr;
}

int main() {
    string s;

    cout << "Enter encoded string: ";
    cin >> s;

    cout << "Decoded string: " << decodeString(s);

    return 0;
}