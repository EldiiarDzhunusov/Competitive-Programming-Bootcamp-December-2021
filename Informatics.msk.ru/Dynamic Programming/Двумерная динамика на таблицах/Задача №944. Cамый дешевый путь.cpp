#include <bits/stdc++.h>
#define ll long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}

const int N = 1e5+5;
int dp[21][21];
int a[21][21];
void solve(){
    //insert your code here
    int n,m; cin>>n>>m;
    for (int i = 1; i <= n; i++) {
        for (int i2 = 1; i2 <= m; i2++) {
            cin>>a[i][i2];
        }
    }

    for (int i = 0; i <= n; i++) {
        dp[i][0] = INT_MAX;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = INT_MAX;
    }
    dp[1][1] = a[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(i==1 && j==1) {continue;}
            dp[i][j] = min(dp[i-1][j],dp[i][j-1])+a[i][j];
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
