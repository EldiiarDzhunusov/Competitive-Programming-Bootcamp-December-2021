#include <bits/stdc++.h>
#define ll long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}

int dp[50][50];
void solve(){
    //insert your code here
    int n,m; cin>>n>>m;
    dp[1][1] = 1;
    for (int d = 3; d <= n+m ; d++) {
        for (int i = 1; i <=n ; i++) {
            int j = d-i;
            if(j<1 || j>m){
                continue;
            }
            dp[i][j] = dp[i+1][j-2] + dp[i-1][j-2] + dp[i-2][j-1] + dp[i-2][j+1];
        }
    }
//    for (int i = 0; i < n+1; i++) {
//        for (int j = 0; j < m+1; j++) {
//            if(dp[i][j]==13309){
//                cout<<"found"<<endl<<endl;
//            }
//            cout<<dp[i][j]<<"\t";
//        }
//        cout<<endl;
//
//    }
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
