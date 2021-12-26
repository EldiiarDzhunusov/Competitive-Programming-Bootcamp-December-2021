#include <bits/stdc++.h>
#define ll long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}
void print(ll dp[],ll n){
    cout<<"[";
    for (int i = 0; i <= n; i++) {
        cout<<dp[i]<<", ";
    }
    cout<<"]";
    cout<<endl;
}
int a[101];

void solve(){
    //insert your code here
    int n,m;
    cin>>n>>m;
    for (int i = 1; i <= m; i++) {
        int x,y; cin>>x>>y;
        a[x]++;
        a[y]++;
    }
    for (int i = 1; i <= n; i++) {
        cout<<a[i]<<" ";
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