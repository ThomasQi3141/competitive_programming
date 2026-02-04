#include <bits/stdc++.h>
using namespace std;
// macros for logging in cerr
#ifdef LOCAL
template <class A, class B>
ostream& operator<<(ostream& os, const pair<A,B>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) os << ", ";
        os << v[i];
    }
    return os << "]";
}

#define LOG(x) cerr << "[LOG] " << #x << " = " << (x) << "\n"

template <class Map>
void LOGMAP(const Map& mp, const string& name = "map") {
    cerr << "[LOG] " << name << " (size=" << mp.size() << "): {";
    bool first = true;
    for (const auto& [k, v] : mp) {
        if (!first) cerr << ", ";
        first = false;
        cerr << k << ": " << v;
    }
    cerr << "}\n";
}

#else
#define LOG(x) ((void)0)
template <class Map>
void LOGMAP(const Map&, const string& = "map") { /* no-op */ }
#endif
using ll = long long;
const ll INF = 1e9;

int toInt(char c) {
    return c - '0';
}

string add(string x, string y) {
    LOG(x);
    LOG(y);
    if (x.size() > y.size()) {
        swap(x, y);
    }
    // NOW, len(x) <= len(y)
    string res = "";
    int carry = 0;
    int xPos = x.size() - 1, yPos = y.size() - 1;
    string reversedCopy;
    while (xPos >= 0) {
        res += to_string((toInt(x[xPos]) + toInt(y[yPos]) + carry) % 10);
        carry = (toInt(x[xPos]) + toInt(y[yPos]) + carry) / 10;
        xPos--;
        yPos--;
    }
    while (yPos >= 0) {
        res += to_string((toInt(y[yPos]) + carry) % 10);
        carry = (toInt(y[yPos]) + carry) / 10;
        yPos--;
    }
    if (carry > 0) {
        res += to_string(carry);
    }
    reverse(res.begin(), res.end());
    LOG(res);
    return res;
}

void solve() {
    ll l;
    cin >> l;
    string num;
    cin >> num;
    // try to split down the middle (both ways), then compute the sum for optimal left and right split
    // make sure no trailing 0s
    // try adding all ways of splitting -> getting the min result
    ll lSplit = l / 2, rSplit = l / 2;
    while (lSplit >= 0 && num[lSplit] == '0') {
        lSplit--;
    }
    while (rSplit < l && num[rSplit] == '0') {
        rSplit++;
    }
    vector<string> candidates;
    if (l % 2 == 1) {

        candidates.push_back(add(num.substr(0, lSplit), num.substr(lSplit)));
        candidates.push_back(add(num.substr(0, rSplit), num.substr(rSplit)));

        if (lSplit + 1 < l && num[lSplit + 1] != '0')
            candidates.push_back(add(num.substr(0, lSplit + 1), num.substr(lSplit + 1)));

        if (rSplit + 1 < l && num[rSplit + 1] != '0')
            candidates.push_back(add(num.substr(0, rSplit + 1), num.substr(rSplit + 1)));
        LOG(candidates);
    } else {
        candidates.push_back(add(num.substr(0, lSplit), num.substr(lSplit)));
        candidates.push_back(add(num.substr(0, rSplit), num.substr(rSplit)));
    }
    // returns true when x < y based on integer values
    auto num_less = [](const string &x, const string &y) {
        if (x.size() != y.size()) {
            return x.size() < y.size();
        }
        // otherwise equal length
        return x < y;
    };

    cout << *min_element(candidates.begin(), candidates.end(), num_less) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
