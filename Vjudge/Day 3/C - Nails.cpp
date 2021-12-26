#include <bits/stdc++.h>
#define ll long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}

const int N = 100+5;
ll dp[N];
ll v[N];
ll n;

void solve(){
    //insert your code here
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }
    std::sort(v, v+n+1);
    dp[1] = 0;
    dp[2] = v[2]-v[1];
    dp[3] = v[3] - v[1];
    dp[4] = (v[4] - v[3]) + (v[2]-v[1]);
    for (int i = 5; i <= n; i++) {
        dp[i] = min(v[i]-v[i-1]+ dp[i-2], v[i]-v[i-2]+ dp[i-3] );
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
