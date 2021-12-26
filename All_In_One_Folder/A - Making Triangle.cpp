#include <bits/stdc++.h>
#define ll long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}

bool isTriangle(int i, int j, int k){
    return (i+j>k && j+k>i && k+i>j);
}

void solve(){
    //insert your code here
    int n; cin>>n;
    vector<int> v(n);
    for (int i = 0; i <n; i++) {
        cin>>v[i];
    }
    ll ans = 0;
    for (int i = 0; i < n-2; i++) {
        for (int j = i+1; j < n-1; j++) {
            for (int k = j+1; k < n; k++) {
//                cout<<v[i]<<" "<<v[j]<<" "<<v[k]<<endl;
                if(v[i]!=v[j] && v[j]!=v[k] &&v[i]!=v[k] && v[i]+v[j]>v[k] && v[j]+v[k]>v[i] && v[i]+v[k]>v[j]){
                    ans++;
                }
            }
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
