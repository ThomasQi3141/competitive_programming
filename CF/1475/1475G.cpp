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

struct LLHash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }

    size_t operator()(int64_t x) const noexcept {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return (size_t)splitmix64((uint64_t)x + FIXED_RANDOM);
    }
};


void solve() {
    // sort array. each successive element must have superset of prime factors compared w/ previous
    // -> find all factors, if factor in Counter += cnt
    // res = min(res, n - length)
    // process in increasing order -> dp[x] = length of longest sequence ending in x
    ll n; cin >> n;
    vector<ll> a(n);
    ll maxVal = 0;
    for (ll &x : a) {
        cin >> x;
        maxVal = max(maxVal, x);
    }
    vector<ll> cnt(maxVal + 1), dp(maxVal + 1);
    for (ll &x : a) cnt[x]++;
    // iterates through cnt in increasing key order
    // cnt = max length of longest sequence ending in x
    ll res = n;
    // a lot slower if we do the regular sqrt(n) method
    // -> O(m log m) this way! -> propogating to each multiple
    for (int i = 1; i <= maxVal; ++i) {
        // now, dp[i] = longest seq with factors of this
        dp[i] += cnt[i]; // all instances of i can extend the current sequence
        for (int j = 2 * i; j <= maxVal; j += i) {
            // all multiples of this can have this appended before them
            dp[j] = max(dp[j], dp[i]);
        }
        res = min(res, n - dp[i]);
    }
    cout << res << endl;
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
