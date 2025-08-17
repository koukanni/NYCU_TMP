#include <bits/stdc++.h>
using namespace std;
#define int long long 
bool check(vector<int> &v, int val){
    int n = v.size();
    int sum = 0;
    for (int i = 1; i < n; i++)
        sum += max(0ll, v[i] - ((val + v[0]) - 1));
    return val >= sum;
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> ans, v(m);
    for (int i = 1; i <= n; i++){
        for (auto &j : v)
            cin >> j;
        bool ok = 1;
        for (int j = 1; j < m; j++)
            ok &= (v[0] > v[j]);
        if (ok){
            ans.push_back(0);
            continue;
        }
        int now = 1000000;
        for (int j = now / 2; j; j >>= 1){
            while (now - j > 0 && check(v, now - j))
                now -= j;
        }
        ans.push_back(now);
    }
    sort(ans.begin(), ans.end());
    int out = 0;
    for (int i = 0; i < n / 2 + 1; i++)
        out += ans[i];
    cout << out << "\n";
}
signed main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}