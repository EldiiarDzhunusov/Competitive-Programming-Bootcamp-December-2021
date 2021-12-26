#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}

bool checkerForBinarySearch(vector<ll> &v1,ll n, ll k, ll h){
    for (int i = 0; i < n; i++) {
        h-=min(v1[i],k);
    }
    return h<=0;

}

long long lBinSearch(ll l, ll r, vector<ll> &v1,ll n, ll h){
    //Assuming that we know that the elements exists there for sure, but we want to find the most optimal one
    //After some point all numbers will be considered as "Good"
    //We need to find most left "Good" number
    while(l<r){
        ll m = l + (r-l)/2;
        if(checkerForBinarySearch(v1,n,m,h)){
            r = m;
        }else{
            l = m+1;
        }
    }
    return l;
}


void solve(){
    //insert your code here
    ll n, h;cin>>n>>h;
    vector<ll> v1(n);
    vector<ll> v2(n);
    for (int i = 0; i < n; i++) {
        cin>>v1[i];
        if(i!=0){
            v2[i-1] = v1[i]-v1[i-1];
        }
    }
    v2[n-1] = LONG_LONG_MAX;

    cout<<lBinSearch(0,h,v2,n,h)<<endl;


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