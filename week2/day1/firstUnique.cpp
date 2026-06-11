#include <iostream>
#include <string>
using namespace std;

int firstUniq(string s) {

    int freq[26] = {0};

    for(char ch : s) {
        freq[ch - 'a']++;
    }

    for(int i = 0; i < s.size(); i++) {
        if(freq[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}

int main() {

    string s;

    cout << "Enter str: ";
    cin >> s;

    int ans = firstUniq(s);

    if(ans == -1) {
        cout << "No uniq character" << endl;
    }
    else {
        cout << "First unique character index: " << ans << endl;
        cout << "Character: " << s[ans] << endl;
    }

    return 0;
}