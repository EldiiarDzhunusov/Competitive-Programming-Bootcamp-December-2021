#include <bits/stdc++.h>
#define ll long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}

ll dp[255];
void solve(){
    //insert your code here
    ll n,m; cin>>n>>m;
    vector<ll> v(m+1);
    for (int i = 1; i <= m; i++) {
        cin>>v[i];
    }
    std::sort(v.begin(), v.end());
    dp[0] = 1;
    for (int j = 1; j <= m; j++) {
        for (int i = v[j]; i <= n; i++) {
            dp[i] += dp[i-v[j]];
        }
    }
    cout<<dp[n]<<endl;
//    for (int i = 0; i <=n; i++) {
//        cout<<dp[i]<<" ";
//    }



}


int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    long t = 1;
//    cin>>t;
    for (int i = 1; i <= t; i++) {
//        cout<<"Case #"<<i<<+": ";
        solve();
    }
}