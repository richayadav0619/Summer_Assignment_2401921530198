#include <iostream>
#include <vector>
#include <string>
using namespace std;

int compress(vector<char>& chars) {
    int i = 0;
    int index = 0;

    while (i < chars.size()) {
        char currChar = chars[i];
        int count = 0;

        while (i < chars.size() && chars[i] == currChar) {
            count++;
            i++;
        }

        chars[index++] = currChar;

        if (count > 1) {
            string freq = to_string(count);

            for (char ch : freq) {
                chars[index++] = ch;
            }
        }
    }

    return index;
}

int main() {
    vector<char> chars = {'a','a','b','b','c','c','c'};

    int len = compress(chars);

    cout << "Length = " << len << endl;

    cout << "Compressed Array: ";
    for (int i = 0; i < len; i++) {
        cout << chars[i] << " ";
    }

    return 0;
}