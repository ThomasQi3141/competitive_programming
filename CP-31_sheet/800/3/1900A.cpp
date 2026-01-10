#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    char x;
    vector<bool> blocked(n);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if(x == '#') {
           blocked[i] = true;
        }
    }
    int res = 0;
    int i = 0;
    while (i < n) {
        if (blocked[i]) {
            ++i;
            continue;
        }
        int j = i;
        while (j < n && !blocked[j]) {
            ++j;
        }
        int length = j - i;
        i = j;
        // 3 blocks = infinite water via operation 2 (minecraft LMFAO)
        // any point length 3 = inf water
        if (length >= 3) {
            cout << 2 << endl;
            return;
        }
        res += length;
    }
    cout << res << endl;
    return;
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