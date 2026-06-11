#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool checkInc(string s1, string s2) {

    int n = s1.size();
    int m = s2.size();

    if(n > m) return false;

    vector<int> freq1(26, 0);
    vector<int> freq2(26, 0);

    for(char ch : s1) {
        freq1[ch - 'a']++;
    }

    for(int i = 0; i < n; i++) {
        freq2[s2[i] - 'a']++;
    }

    if(freq1 == freq2) return true;

    for(int i = n; i < m; i++) {

        freq2[s2[i] - 'a']++;
        freq2[s2[i - n] - 'a']--;

        if(freq1 == freq2) {
            return true;
        }
    }

    return false;
}

int main() {

    string s1, s2;

    cout << "Enter s1: ";
    cin >> s1;

    cout << "Enter s2: ";
    cin >> s2;

    if(checkInc(s1, s2))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}