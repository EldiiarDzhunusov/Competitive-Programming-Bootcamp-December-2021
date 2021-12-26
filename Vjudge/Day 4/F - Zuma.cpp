#include <bits/stdc++.h>
#define ll long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}

int dp[505][505];
int a[505],n;

int calc(int l,int r){
    if(l>=r) return 1;

    if(dp[l][r]!=0) return dp[l][r];

    dp[l][r] = 1e9;

    if(a[l]==a[r]){
        dp[l][r] = calc(l+1,r-1);
    }
    for (int i = l; i <=r ; i++) {
        dp[l][r] = min(dp[l][r], calc(l,i)+calc(i+1,r));
    }
    return dp[l][r];
}
void solve(){
    //insert your code here
//    memset(dp,-1,sizeof (dp));
    cin>>n;
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    cout<<calc(1,n)<<endl;
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