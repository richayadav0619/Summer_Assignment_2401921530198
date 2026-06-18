#include <iostream>
#include <queue>
using namespace std;

class recentCounter{
private:
    queue<int> q;

public:
    recentCounter() {
    }

    int ping(int t) {
        q.push(t);

        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }

        return q.size();
    }
};

int main() {
    recentCounter rc;

    cout << rc.ping(1) << endl;      // 1
    cout << rc.ping(100) << endl;    // 2
    cout << rc.ping(3001) << endl;   // 3
    cout << rc.ping(3002) << endl;   // 3

    return 0;
}