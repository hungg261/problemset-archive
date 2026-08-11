// author: baodat from HSG VNU HCM
#include <bits/stdc++.h>
using namespace std;
#define ll long long
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    vector<int> freq(26, 0);
    for(char c : s) ++freq[(int)c - 'a'];
    int ans = 0;
    for(int it : freq){
        if(it % 2 == 1){
            ++ans;
        }
    }
    cout << max(ans, 1) << "\n"; 
    return 0;
}