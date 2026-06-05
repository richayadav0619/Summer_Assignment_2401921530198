#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf = 0;
        int lowestBuy = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > lowestBuy) {
                maxProf = max(maxProf, prices[i] - lowestBuy);
            }
            lowestBuy = min(lowestBuy, prices[i]);
        }

        return maxProf;
    }
};

int main() {
    int n;
    cout << "Enter days: ";
    cin >> n;

    vector<int> prices(n);

    cout << "Enter stock: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    Solution obj;
    int profit = obj.maxProfit(prices);

    cout << "Max Profit: " << profit << endl;

    return 0;
}