#include <bits/stdc++.h>
#define ll long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}

void solve(){
    //insert your code here
    string s; cin>>s;
    int n = s.size();
    if(n==2){
        if(s=="NE" || s=="EN"){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
        return;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if(s[i]=='N'){
            count++;
        }
    }
    if(count!=1){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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