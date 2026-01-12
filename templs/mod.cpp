#include <bits/stdc++.h>
using namespace std;

auto mod = [](int64_t a, int64_t m) -> int64_t {
    a %= m;
    if (a < 0) a += m;
    return a;
};
