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
constexpr int dx[] = {-1, 0, 1, 0};
constexpr int dy[] = {0, -1, 0, 1};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i64 xa, ya, ca;
  i64 xb, yb, cb;
  cin >> xa >> ya >> ca;
  cin >> xb >> yb >> cb;
  const i64 dis = abs(xa - xb) + abs(ya - yb); 
  if (dis > ca + cb or dis % 2 != (ca + cb) % 2) {
    cout << "impossible\n";
    return 0;
  }
  if (ca > cb) {
    swap(xa, xb);
    swap(ya, yb);
    swap(ca, cb);
  }
  i64 minD = i64(1E15);
  int i = -1;
  rep (d, 0, 3) {
    const i64 X = xa + dx[d] * ca;
    const i64 Y = ya + dy[d] * ca;
    if (chmin(minD, abs(X - xb) + abs(Y - yb))) {
      i = d;
    }
  }
  cout << xa + dx[i] * ca << " " << ya + dy[i] * ca << '\n';
  return 0;
}