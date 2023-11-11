#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, K, ai;
    priority_queue<int, vector<int>, greater<int>> A;
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> ai;
        A.push(ai);
    }
    int count = 0;
    while (A.top() < K) {
        if (A.size() < 2) {
            cout << "-1\n";
            return 0;
        }
        int m1 = A.top();
        A.pop();
        int m2 = A.top();
        A.pop();
        A.push(m1 + 2 * m2);
        count++;
    }
    cout << count << endl;
    return 0;
}
