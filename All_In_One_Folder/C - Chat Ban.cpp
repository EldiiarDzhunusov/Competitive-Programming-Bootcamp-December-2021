#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}

bool checkerForBinarySearch( long long messages, long long k, long long x){
    ll ans = 0;
    if(messages<=k){
        ll temp = (messages)*(messages+1)/2;
        return (temp<x );
    }else{
        ll previous = ((k)*(k+1))/2;
        messages=(k-(messages-k))-1;
        ll temp =(k-1)*(k)/2;

        ll temp2 = (messages)*(messages+1)/2;
        ans = previous+ (temp - (temp2));
        ans++;
        return (ans<=x );
    }

}

long long rBinSearch(long long l, long long r, long long k, long long x){
    //Assuming that we know that the elements exists there for sure, but we want to find the most optimal one
    //After some point all numbers will be considered as "Bad"
    //We need to find most Right "Good" number
    while(l<r){
        long long m = l + (r-l)/2;
        if(!checkerForBinarySearch(m,k,x)){
            r = m;
        }else{
            l = m+1;
        }
    }

    return l;
}

void solve(){
    //insert your code here
    ll k,x; cin>>k>>x;
    ll ans = rBinSearch(0LL,(k*2-1),k,x);
    cout<<ans<<endl;

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
