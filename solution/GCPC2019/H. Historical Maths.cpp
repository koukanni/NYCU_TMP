#pragma GCC optimize("Ofast,unroll-loops")

#include <cstdio>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
#include <limits>
#include <iostream>
#include <chrono>
#include <queue>
#include <random>
#include <functional>
#include <vector>
#include <bitset>
#include <ranges>

using namespace std;

#ifdef LOCAL
#include "debug"
#else
#define debug(...)
#endif

using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using usize = size_t;
using f64 = double;
using i128 = __int128_t;
using u128 = __uint128_t;

template <class T>
constexpr T infty = 0;
template <>
constexpr int infty<int> = int(1e9);
template <>
constexpr int64_t infty<int64_t> = int64_t(1e18);
template <>
constexpr __int128_t infty<__int128_t> = __int128_t(1e36);
template <>
constexpr double infty<double> = 1e30;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define fi first
#define se second

template<class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, true : false);
}
template<class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, true : false);
}
constexpr i128 inf = i128(1E35);
constexpr usize maxn = 3005;
int N[5], M;
i64 D[5][maxn];
u128 R[maxn], C[maxn];
int get(const u128 x) {
  rep (i, 1, M + 6) C[i] = R[i];
  rep (i, 1, M + 5) {
    C[i + 1] += C[i] / x;
    C[i] %= x;
  }
  per (i, M + 6, 1) if (C[i] != D[3][i]) {
    return (C[i] < D[3][i] ? -1 : +1);
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i64 mx = 0;
  rep (i, 1, 3) {
    cin >> N[i];
    per (j, N[i], 1) cin >> D[i][j];
    rep (j, 1, N[i]) chmax(mx, D[i][j]);
  }
  rep (i, 1, N[1]) rep (j, 1, N[2]) R[i + j - 1] += D[1][i] * D[2][j];
  M = max(N[3], N[1] + N[2] - 1);
  u128 ok = mx + 1, ng = i64(2E21);
  while (ng - ok > 1) {
    const u128 mid = ok + (ng - ok) / 2;
    if (get(mid) >= 0) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  if (get(ok) == 0) {
    string res;
    while (ok > 0) {
      res += char('0' + ok % 10);
      ok /= 10;
    }
    ranges::reverse(res);
    cout << res << '\n';
  } else {
    cout << "impossible\n";
  }
  return 0;
}