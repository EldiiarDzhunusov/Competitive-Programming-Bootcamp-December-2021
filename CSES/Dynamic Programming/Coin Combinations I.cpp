#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}
 
void print(ll dp[],ll n){
    cout<<"[";
    for (int i = 0; i <= n; i++) {
        cout<<dp[i]<<", ";
    }
    cout<<"]";
    cout<<endl;
}
const int N = 1e6+5;
const int mod = 1e9+7;
ll dp[N];
void solve(){
    //insert your code here
    ll n,x; cin>>n>>x;
    vector<ll> v(n+1);
    for (int i = 1; i <= n; i++) {
        cin>>v[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= n; j++) {
            if(i-v[j]>=0){
                dp[i] += dp[i-v[j]];
                dp[i]%=mod;
            }
 
        }
    }
    cout<<dp[x]<<endl;
//    print(dp,x);
 
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