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
string out(const int x) {
  if (x < 10) {
    return "0" + to_string(x);
  } else {
    return to_string(x);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, C;
  cin >> N >> C;
  int ANS = 0;
  rep (i, 1, N) {
    string S;
    cin >> S;
    const int H = int(S[0] - '0');
    const int M = stoi(S.substr(2));
    ANS += 60 * H + M;
  }
  ANS -= (N - 1) * C;
  cout << out(ANS / 3600) << ":" << out(ANS % 3600 / 60) << ":" << out(ANS % 60) << '\n';
  return 0;
}