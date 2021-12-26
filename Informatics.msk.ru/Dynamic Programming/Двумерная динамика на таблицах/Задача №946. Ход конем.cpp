#include <bits/stdc++.h>
#define ll long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}

int dp[55][55];
void solve(){
    //insert your code here
    int n,m; cin>>n>>m;
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for(int j = 1; j<=m; j++){
            if(i==1 && j==1) continue;
            dp[i][j] = dp[i-1][j-2] + dp[i-2][j-1];
        }
    }
    cout<<dp[n][m]<<endl;
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