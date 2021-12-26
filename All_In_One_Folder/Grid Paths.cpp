#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}
void print(int dp[],int n){ cout<<"[";  bool isFirst = true;    for (int i = 0; i <= n; i++) {        if(isFirst){            cout<<dp[i]<<" ";            isFirst=false;            continue;        }        cout<<", "<<dp[i];    }    cout<<"]";    cout<<endl;}
 
 
ll dp[1005][1005], n;
const int mod = 1e9+7;
void solve(){
    //insert your code here
    cin>>n;
    char a[n+1][n+1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin>>a[i][j];
        }
    }
 
    dp[1][1] = 1;
    if(a[1][1]=='*'){
        dp[1][1] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(i==1 && j==1) continue;
            if(a[i][j]!='*'){
                dp[i][j] = (dp[i-1][j]%mod+dp[i][j-1]%mod)%mod;
            }
        }
    }
//    for (int i = 0; i <= n; i++) {
//        print(dp[i],n);
//    }
    cout<<dp[n][n]<<endl;
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