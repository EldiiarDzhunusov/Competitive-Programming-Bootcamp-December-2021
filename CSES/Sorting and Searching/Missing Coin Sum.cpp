#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}
 
void solve(){
    //insert your code here
    int n; cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }
    std::sort(v.begin(), v.end());
    ll sum = 0;
    if(v[0]>1){
        cout<<1<<endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if(sum+1<v[i]){
            cout<<sum+1<<endl;
            return;
        }
        sum+=v[i];
    }
    cout<<sum+1<<endl;
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