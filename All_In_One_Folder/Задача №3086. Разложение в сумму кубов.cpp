#include <bits/stdc++.h>
#define ll long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}

const int N = 10e6+5;
int dp[N];
void solve(){
    //insert your code here
    int n; cin>>n;
    int x = 1 ;
    for (int i = 0; i <=n ; i++) {
        dp[i] = i;
    }
    while(x*x*x<=n){
        for (int i = x*x*x; i <= n; i++) {
            dp[i] = min(dp[i],dp[i-(x*x*x)]+1);
        }
        x++;
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