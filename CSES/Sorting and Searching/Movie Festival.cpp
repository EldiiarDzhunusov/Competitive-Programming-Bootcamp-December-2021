#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}
 
void solve(){
    //insert your code here
    int n; cin>>n;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
        int a,b;
        cin>>a>>b;
        v[i].first= a;
        v[i].second =b;
    }
    std::sort(v.begin(), v.end());
    int e = v[0].second;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if(v[i].first>=e){
            ans++;
            e = v[i].second;
        }else{
            e = min(v[i].second,e);
        }
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