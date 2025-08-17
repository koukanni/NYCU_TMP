#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <iostream>
#include <map>
#include <cmath>
#include <iomanip>
#include <tuple>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>
#include <numeric>
#include <unordered_map>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18;
const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

ll fpow(ll a, ll b, ll m)
{
    if(!b) return 1;
    ll tmp = 1;
    for(ll cur = a; b; b >>= 1, cur = cur * cur % m) if(b & 1) tmp = tmp * cur % m;
    return tmp;
}
ll inv(ll a, ll m) {return fpow(a, m - 2, m);}

#define fastio ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, n)  for(ll i = 0; i < n; i++)
#define rep1(i, n) for(ll i = 1; i <= n; i++)
#define F first
#define S second
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define sz(a) (ll) a.size()
#define all(x) x.begin(), x.end()
#define rep(i, n) for (ll i = 1; i <= n; i++)
#define lowbit(x) x&(-x)

const ll MAXN = 50 + 5;
const ll MOD = 1000000000 + 7;
const double eps = 1e-9;

ll N, M;
string virus[MAXN], antivirus[MAXN];

ll score(string s) {
  ll len_s = sz(s);
  for (ll l = 1; l <= len_s; l++) {
    if (len_s % l != 0) continue;
    else {
      bool flag = true;
      for (ll i = l; i < len_s; i += l) {
        if (s.substr(i, l) != s.substr(0, l)) {
          flag = false;
        }
      }
      if (flag) return l;
    }
  }
  return 0;
}

void solve() {
  cin >> N;
  vector<ll> num1, num2;
  for (ll i = 0; i < N; i++) {
    cin >> virus[i];
    num1.push_back(score(virus[i]));
  }
  for (ll i = 0; i < N; i++) {
    cin >> antivirus[i];
    num2.push_back(score(antivirus[i]));
  }
  sort(all(num1));
  sort(all(num2));
  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    ans += (num1[i] - num2[i]) * (num1[i] - num2[i]);
  }
  cout << ans << "\n";
}

signed main() {
  fastio ll T = 1;
  // cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}

/*
0. WA1 -> multiple input
1. WA7 -> specify mod, and use mod or not
*/