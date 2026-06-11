#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool isAnagram(string s, string t) {

    if (s.length() != t.length()) {
        return false;
    }

    unordered_map<char, int> freq1;
    unordered_map<char, int> freq2;

    for (char ch : s) {
        freq1[ch]++;
    }

    for (char ch : t) {
        freq2[ch]++;
    }

    return freq1 == freq2;
}

int main() {

    string s, t;

    cout << "Enter str 1: ";
    cin >> s;

    cout << "Enter str 2: ";
    cin >> t;

    if (isAnagram(s, t)) {
        cout << "Anagrams" << endl;
    } else {
        cout << "NOT Anagrams" << endl;
    }

    return 0;
}