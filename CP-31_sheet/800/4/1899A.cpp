#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    // % 3 = 0 -> vanya can't win
    // % 3 == 1 -> vanya always wins
    // % 3 == 2 -> vanya always wins
    if (n % 3 == 0) {
        cout << "Second" << endl;
        return;
    }
    cout << "First" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}