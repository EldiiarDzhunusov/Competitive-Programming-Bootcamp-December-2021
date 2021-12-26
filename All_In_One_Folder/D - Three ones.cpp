#include <bits/stdc++.h>
#define ll long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}

const int N = 1e5+5;
int dp[N][2];

void solve(){
    //insert your code here
    int MOD = 12345;
    ll n; cin>>n;
    dp[0][0] = 1;
    dp[0][1] = 1;

    dp[1][0] = 2;
    dp[1][1] = 2;

    for (int i = 2; i <= n; i++) {
        dp[i][0] = (dp[i-1][0]+dp[i-1][1])%MOD;
        dp[i][1] = (dp[i-1][0]+dp[i-2][0])%MOD;
    }
    cout<<(dp[n-1][0]+dp[n-1][1])%MOD<<endl;

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