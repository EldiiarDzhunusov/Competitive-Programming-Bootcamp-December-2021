#include <bits/stdc++.h>
#define ll long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}

void solve(){
    //insert your code here
    ll n,d; cin>>n>>d;
    vector<ll> v(n);
    bool check =false;
    for (int i = 0; i < n; i++) {
        cin>>v[i];
        if(v[i]>d){
            check =true;
        }
    }
    std::sort(v.begin(), v.end());
    if(check){
    if(v[0]+v[1]<=d){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }}
    else{
        cout<<"YES"<<endl;
    }

}


int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    long t = 1;
    cin>>t;
    for (int i = 1; i <= t; i++) {
//        cout<<"Case #"<<i<<+": ";
        solve();
    }
}


/*      Solved by Eldiiar Dzhunusov       */