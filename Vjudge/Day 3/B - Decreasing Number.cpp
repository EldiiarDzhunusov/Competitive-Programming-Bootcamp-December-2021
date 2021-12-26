#include <bits/stdc++.h>
#define ll long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}

const int N = 10e6+5;
ll dp[N];
void solve(){
    //insert your code here
    ll n;
    while(cin>>n){
        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 1;
        for (int i = 4; i <= n; i++) {
            ll a = INT_MAX;
            ll b = INT_MAX;
            ll c = INT_MAX;
            if(i%3==0){
                a = dp[i/3]+1;
            }if(i%2==0){
                b = dp[i/2]+1;
            }
            c = dp[i-1]+1;
            dp[i] = min(a,min(b,c));
        }
        cout<<dp[n]<<endl;
    }


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
