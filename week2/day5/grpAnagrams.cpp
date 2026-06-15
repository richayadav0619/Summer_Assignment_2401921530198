#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (string str : strs) {
        string key = str;

        sort(key.begin(), key.end());

        mp[key].push_back(str);
    }

    vector<vector<string>> result;

    for (auto& pair : mp) {
        result.push_back(pair.second);
    }

    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> ans = groupAnagrams(strs);

    for (auto group : ans) {
        cout << "[ ";
        for (string word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}