#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}
 
const int N = 10e6+5;
const int mod = 1e9+7;
ll dp[N];
void solve(){
    //insert your code here
    ll n; cin>>n;
    dp[1]= 1; dp[2] = 2; dp[3] = 4, dp[4] = 8; dp[5] =16; dp[6] = 32;
    for (int i = 7; i <= n; i++) {
        for (int j = 1; j <=6 ; j++) {
            dp[i] +=dp[i-j];
            dp[i] %=mod;
        }
    }
    cout<<dp[n]<<endl;
 
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