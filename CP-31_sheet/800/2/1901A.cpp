#include <bits/stdc++.h>
using namespace std;

void solve() {
    // return the max dist between each gas station
    // note that last station to x is * 2
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int &x : arr) {
        cin >> x;
    }
    int maxGas = 0;
    maxGas = max(maxGas, arr[0]);
    for (int i = 1; i < n; ++i) {
        maxGas = max(maxGas, arr[i] - arr[i - 1]);
    }
    // last gap covered twice
    maxGas = max(maxGas, (x - arr[n - 1]) * 2);
    cout << maxGas << endl;
    return;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
       solve(); 
    }
    return 0;
}