#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
vector<long long> finder(long long n) {
    vector<long long> factorization;
    for (ll i = 2; i*i <=n ; i++) {
        while(n%i==0){
            factorization.push_back(i);
            n/=i;
        }
    }
    if(n>1){
        factorization.push_back(n);
    }
    return factorization;
}

void solve(){
    //insert your code here
    cin>>n;
    vector<ll> ans;
    ans = finder(n);
//    std::sort(ans.begin(), ans.end());
    bool isFirst = true;
    for(auto x: ans){
        if(isFirst){
            isFirst=false;
            cout<<x;

        }else{
            cout<<"*"<<x;

        }
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