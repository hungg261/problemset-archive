#include <bits/stdc++.h>
using namespace std;
#define ll long long
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll>a(n + 1), pref(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    map<ll, int> mp;
    mp[0] = 1;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ll cand = pref[i] - (1ll * i * i + i);
        ans += mp[cand];
        ++mp[cand];
    }
    cout << ans << "\n";
    return 0;
}