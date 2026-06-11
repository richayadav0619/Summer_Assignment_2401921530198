#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> findAnagrams(string s, string p) {

    vector<int> ans;

    int n = s.size();
    int m = p.size();

    if(m > n) return ans;

    vector<int> freqP(26, 0);
    vector<int> window(26, 0);

    for(char ch : p) {
        freqP[ch - 'a']++;
    }

    for(int i = 0; i < m; i++) {
        window[s[i] - 'a']++;
    }

    if(freqP == window) {
        ans.push_back(0);
    }

    for(int i = m; i < n; i++) {

        window[s[i] - 'a']++;
        window[s[i - m] - 'a']--;

        if(freqP == window) {
            ans.push_back(i - m + 1);
        }
    }

    return ans;
}

int main() {

    string s, p;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter pattern p: ";
    cin >> p;

    vector<int> result = findAnagrams(s, p);

    cout << "Anagram indices: ";

    for(int idx : result) {
        cout << idx << " ";
    }

    cout << endl;

    return 0;
}