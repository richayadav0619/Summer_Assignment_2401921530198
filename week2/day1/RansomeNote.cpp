#include <iostream>
#include <string>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {

    int freq[26] = {0};

    for(char ch : magazine) {
        freq[ch - 'a']++;
    }

    for(char ch : ransomNote) {
        if(freq[ch - 'a'] == 0) {
            return false;
        }

        freq[ch - 'a']--;
    }

    return true;
}

int main() {

    string ransomNote, magazine;

    cout << "Enter ransom note: ";
    cin >> ransomNote;

    cout << "Enter magazine: ";
    cin >> magazine;

    if(canConstruct(ransomNote, magazine))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}