#include <bits/stdc++.h>
#define ll long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}

void solve(){
    //insert your code here
    ll w,h,k1; cin>>w>>h>>k1;
    vector<ll> xUpper(k1);
    for (int i = 0; i < k1; i++) {
        cin>>xUpper[i];
    }
    ll k2; cin>>k2;
    vector<ll> xLower(k2);
    for (int i = 0; i < k2; i++) {
        cin>>xLower[i];
    }
    ll k3; cin>>k3;
    vector<ll> yLeft(k3);
    for (int i = 0; i < k3; i++) {
        cin>>yLeft[i];
    }
    ll k4; cin>>k4;
    vector<ll> yRight(k4);
    for (int i = 0; i < k4; i++) {
        cin>>yRight[i];
    }
    std::sort(xUpper.begin(), xUpper.end());
    std::sort(xLower.begin(), xLower.end());
    std::sort(yLeft.begin(), yLeft.end());
    std::sort(yRight.begin(), yRight.end());
    ll dist1 = abs(xUpper[0]-xUpper[xUpper.size()-1]) * h;
    ll dist2 = abs(xLower[0]-xLower[xLower.size()-1]) * h;
    ll dist3 = abs(yRight[0]-yRight[yRight.size()-1]) *w;
    ll dist4 = abs(yLeft[0]-yLeft[yLeft.size()-1]) * w;

    cout<<max(dist1,max(dist2,max(dist3,dist4)))<<endl;


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