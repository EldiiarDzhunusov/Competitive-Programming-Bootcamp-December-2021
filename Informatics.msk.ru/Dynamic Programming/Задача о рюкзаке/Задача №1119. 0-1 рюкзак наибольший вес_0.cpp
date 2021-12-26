#include <bits/stdc++.h>
#define ll long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}

int dp[1000005];

void solve(){
    //insert your code here
    int n,x,m; cin>>n>>x;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin>>m;
        for (int j = x; j-m >= 0 ; j--) {
            if(dp[j-m]==1){
                dp[j] = 1;
            }
        }
    }

    for (int i = x; i >= 0; i--) {
        if(dp[i]==1){
            cout<<i<<endl;
            return;
        }
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
