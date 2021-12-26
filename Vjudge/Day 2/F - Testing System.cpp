#include <bits/stdc++.h>
#define ll long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}


vector<pair<int,pair<int,int>>> v(100005);

bool cmp(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
    if(a.first==b.first){
        if(a.second.first==b.second.first){
            return a.second.second<b.second.second;
        }
        return a.second.first<b.second.first;

    }
    return a.first>b.first;
}
void solve(){
    int n;cin>>n;

    for (int i = 0; i < n; i++) {
        cin>>v[i].first;
        cin>>v[i].second.first;
        v[i].second.second = i+1;

    }

    sort(v.begin(), v.begin() + n,&cmp);
    for (int i = 0; i < n; i++) {
        cout<<v[i].second.second<<" ";
    }

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