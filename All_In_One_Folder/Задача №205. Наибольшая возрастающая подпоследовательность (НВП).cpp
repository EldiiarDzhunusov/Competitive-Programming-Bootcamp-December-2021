#include <bits/stdc++.h>
#define ll long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}

int dp[1005];
void solve(){
    //insert your code here
    int n; cin>>n;
    vector<int> v(n+1);
    for (int i = 1; i < n+1; i++) {
        cin>> v[i];
        int ans = INT_MIN;
        for (int j = i; j >0; j--) {
            if(v[i]>v[j]){
                ans = max(dp[j],ans);
            }
        }
        ans = max(ans,0);
        dp[i] = ans+1;
    }
    int ans = 0;
    for (int i = 1; i < n+1; i++) {
        ans = max(ans,dp[i]);
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