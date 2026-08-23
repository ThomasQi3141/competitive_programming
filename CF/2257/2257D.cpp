#include <bits/stdc++.h>
using namespace std;
// ============================ DEBUG ============================
// Enabled by -DLOCAL or -DDEBUG. Everything below compiles to nothing
// in a release build, so debug calls are free on the judge.
#if defined(LOCAL) || defined(DEBUG)
#define DBG_ON 1
#else
#define DBG_ON 0
#endif
 
#if DBG_ON
 
// ---- scalars -------------------------------------------------
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
 
// ---- forward declarations (needed for mutual recursion) -------
template <typename T, typename V> void __print(const pair<T, V> &x);
template <typename... Ts> void __print(const tuple<Ts...> &x);
template <size_t N> void __print(const bitset<N> &x);
 
// ---- generic iterable: vector, set, map, array, deque, ... ----
template <typename T> void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x)
    cerr << (f++ ? ", " : ""), __print(i);
  cerr << '}';
}
 
template <typename T, typename V> void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
 
template <typename... Ts> void __print(const tuple<Ts...> &x) {
  int f = 0;
  cerr << '{';
  apply([&](const auto &...args) { ((cerr << (f++ ? ", " : ""), __print(args)), ...); }, x);
  cerr << '}';
}
 
template <size_t N> void __print(const bitset<N> &x) { cerr << x; }
 
// ---- adaptors: copied by value, so logging is non-destructive -
template <typename T, typename C> void __print(stack<T, C> s) {
  vector<T> v;
  while (!s.empty()) { v.push_back(s.top()); s.pop(); }
  reverse(v.begin(), v.end());  // bottom -> top
  __print(v);
}
template <typename T, typename C> void __print(queue<T, C> q) {
  vector<T> v;
  while (!q.empty()) { v.push_back(q.front()); q.pop(); }
  __print(v);  // front -> back
}
template <typename T, typename C, typename Cmp>
void __print(priority_queue<T, C, Cmp> pq) {
  vector<T> v;
  while (!pq.empty()) { v.push_back(pq.top()); pq.pop(); }
  __print(v);  // pop order
}
 
// ---- variadic driver -----------------------------------------
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
 
// ---- the macros ----------------------------------------------
// dbg(a, b, c) -> solve:42 [a, b, c] = [1, {2, 3}, "hi"]
#define dbg(...)                                                               \
  do {                                                                         \
    cerr << __func__ << ":" << __LINE__ << " [" << #__VA_ARGS__ << "] = [";    \
    _print(__VA_ARGS__);                                                       \
    cerr << flush;                                                             \
  } while (0)
 
// LOG(x) -> [LOG] x = value      (same shape as before)
#define LOG(x)                                                                 \
  do {                                                                         \
    cerr << "[LOG] " << #x << " = ";                                           \
    __print(x);                                                                \
    cerr << "\n" << flush;                                                     \
  } while (0)
 
// LOGMAP(mp, "name") -> [LOG] name (size=2): {k: v, k: v}
template <class Map> void LOGMAP(const Map &mp, const string &name = "map") {
  cerr << "[LOG] " << name << " (size=" << mp.size() << "): {";
  bool first = true;
  for (const auto &[k, v] : mp) {
    if (!first) cerr << ", ";
    first = false;
    __print(k);
    cerr << ": ";
    __print(v);
  }
  cerr << "}\n" << flush;
}
 
#else
#define dbg(...) ((void)0)
#define LOG(x) ((void)0)
template <class Map> void LOGMAP(const Map &, const string & = "map") {}
#endif
// ========================== END DEBUG ==========================
 
using ll = long long;
using pll = pair<ll, ll>;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

// get height of tower this thing is in
ll heightAt(ll x, vector<pll> &towers) {
    auto it = lower_bound(towers.begin(), towers.end(), make_pair(x, 0LL));
    return it->second;
}

// gets total number of cells from [0, x] with unlim height
ll getCells(ll x, const vector<pll> &towers, const vector<pll> &prefix) {
    // NOTE: uppper_bound - 1 method to get the last thing that's <= x
    // find first thing that's > x -> -1 to get last thing <= x
    auto it = upper_bound(prefix.begin(), prefix.end(), make_pair(x, 0LL));
    // towers[0].first == 1 <= x, k >= 0
    // k = index of last tower with idx <= x
    ll k = it - prefix.begin() - 1;
    ll res = prefix[k].second;
    // if extra portion, add on
    if (x > towers[k].first) res += (x - towers[k].first) * towers[k + 1].second;
    return res;
}

void solve() {
    ll S, q;
    cin >> S >> q;
    // for each point x, y
    // x -> get all of the towers (partial ones) [0, x]
    // y -> for each tower, we can get at MOST y height from that
    // y gives us a cutoff tower -> BEFORE cutoff tower -> can only take at most y height, after is js regular height

    // if y <= cur tower height -> x * y
    // if y > cur tower height -> take (cutoffTower * y) + (prefix[x] - prefix[cutoffTower/position])
    // towers -> [startIdx, towerheight]
    vector<pll> towers; // idx, towerHeight
    vector<pll> prefix; // idx -> sum of total cells that has x <= idx
    for (ll i = 1; i * i <= S; ++i) {
        if (S % i == 0) {
            towers.push_back({i, S / i});
            // CONSIDER PERFECT SQUARES!
            if (i != S / i) towers.push_back({S / i, i});
        }
    }
    // dont really need sorting, but it works wtv
    sort(towers.begin(), towers.end());
    prefix.push_back({towers[0].first, towers[0].first * towers[0].second});
    for (int i = 1; i < towers.size(); ++i) {
        prefix.push_back({towers[i].first, prefix[i - 1].second + (towers[i].first - towers[i - 1].first) * towers[i].second});
    }
    LOG(towers);
    LOG(prefix);
    ll x, y;
    for (int i = 0; i < q; ++i) {
        cin >> x >> y;
        ll h = heightAt(x, towers);
        // smaller than cur tower
        if (y <= h) {
            cout << x * y << endl;
            continue;
        }
        // 
        ll C = heightAt(y, towers); // last column (x value) with height >= y
        cout << getCells(x, towers, prefix) - (getCells(C, towers, prefix) - C * y) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; // Keep in for codeforces
    while (t--) {
        solve();
    }
    return 0;
}