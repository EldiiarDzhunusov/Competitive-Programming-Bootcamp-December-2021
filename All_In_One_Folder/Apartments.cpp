#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}
 
void solve(){
    //insert your code here
    ll n,m,k; cin>>n>>m>>k;
    vector<ll> applicants(n);
    vector<ll> apartments(m);
    for (int i = 0; i < n; i++) {
        cin>>applicants[i];
    }
    for (int i = 0; i < m; i++) {
        cin>>apartments[i];
    }
    std::sort(applicants.begin(), applicants.end());
    std::sort(apartments.begin(), apartments.end());
    ll i=0,j=0;
    ll ans = 0;
    while(i<n && j<m){
 
        if(applicants[i]-k <= apartments[j] && applicants[i]+k >= apartments[j]){
            i++;
            j++;
            ans++;
        }else if(applicants[i]-k <=  apartments[j]){
            i++;
        }
        else{
            j++;
//            cout<<"Hello"<<endl;
        }
    }
    cout<<ans;
 
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