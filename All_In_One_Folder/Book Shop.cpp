#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}
void print(int dp[],int n){ cout<<"[";  bool isFirst = true;    for (int i = 0; i <= n; i++) {        if(isFirst){            cout<<dp[i]<<" ";            isFirst=false;            continue;        }        cout<<", "<<dp[i];    }    cout<<"]";    cout<<endl;}
 
const int N = 1e5+5;
int dp[N], n, x,v1[1005],v2[1005];
void solve(){
    //insert your code here
    cin>>n>>x;
    for (int i = 1; i <= n; i++) {
        cin>> v1[i];
    }
    for (int i = 1; i <= n; i++) {
        cin>> v2[i];
    }
    for (int i = 1; i <= x; i++) {
        dp[i] = INT_MIN;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = x; j >= v1[i]; j--) {
            dp[j] = max(dp[j],dp[j-v1[i]]+v2[i]);
        }
    }
    int ans = 0;
    for (int i = x; i >= 1; i--) {
        ans = max(ans, dp[i]);
    }
    cout<<ans<<endl;
 
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