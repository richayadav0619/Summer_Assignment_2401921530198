#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (char ch : s) {
        if (ch == '(') {
            st.push(')');
        }
        else if (ch == '{') {
            st.push('}');
        }
        else if (ch == '[') {
            st.push(']');
        }
        else {
            if (st.empty() || st.top() != ch) {
                return false;
            }
            st.pop();
        }
    }

    return st.empty();
}

int main() {
    string s;

    cout << "Enter parentheses string: ";
    cin >> s;

    if (isValid(s)) {
        cout << "Valid Parentheses" << endl;
    } else {
        cout << "Invalid Parentheses" << endl;
    }

    return 0;
}