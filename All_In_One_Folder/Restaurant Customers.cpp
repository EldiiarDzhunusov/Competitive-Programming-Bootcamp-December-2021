#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}
 
void solve(){
    //insert your code here
    ll n; cin>>n;
    vector<pair<ll,int>> v(n*2);
    for (int i = 0; i < n*2; i+=2) {
        int a1;cin>>a1;
        int b1;cin>>b1;
        v[i].first = a1;
        v[i].second = 1;
        v[i+1].first = b1;
        v[i+1].second = -1;
    }
    std::sort(v.begin(), v.end());
    long max1 = 0;
    long localMax = 0;
    for (int i = 0; i < n*2; i++) {
        localMax+=v[i].second;
        max1 = max(localMax,max1);
    }
    cout<<max1<<endl;
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