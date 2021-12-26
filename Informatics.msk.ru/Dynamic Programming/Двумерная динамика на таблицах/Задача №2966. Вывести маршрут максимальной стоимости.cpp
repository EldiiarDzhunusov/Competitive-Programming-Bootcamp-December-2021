#include <bits/stdc++.h>
#define ll long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}

int dp[105][105];

void solve(){
    //insert your code here
    int n,m; cin>>n>>m;
    vector<string> ans;
    for (int i = 1; i <=n ; i++) {
        for (int j = 1; j <= m; j++) {
            int a; cin>>a;
            if(i==1 &&j==1) {
                dp[i][j] = a;
                continue;
            }
            dp[i][j] = max(dp[i-1][j],dp[i][j-1])+a;
        }
    }
    int i = n;
    int j = m;
    while(i>1 || j>1 ){
        if((max(dp[i-1][j],dp[i][j-1])==dp[i-1][j]) ){
            ans.push_back("D");
            i--;
        }else{
            ans.push_back("R");
            j--;
        }
    }
//    ans.pop_back();
    reverse(ans.begin(), ans.end());
    cout<<dp[n][m]<<endl;
    for (int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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