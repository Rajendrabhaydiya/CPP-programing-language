#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    int mv = 0;
    vector<int> counts(20001, 0);
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        v += 10000;
        ++counts[v];
        mv = min(mv, v);    
    }
    int c = 0;
    for (int i = mv; i < counts.size(); ++i) {
        c += counts[i];
        if (c * 2 > n) {
            cout << i - 10000 << endl;
            break;
        }
    }
    return 0;
}
