#include <bits/stdc++.h>
#define ll long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}

void solve(){
    //insert your code here
    int n; cin>>n;
    long ones = 0;
    long twos = 0;
    for (int i = 0; i < n; i++) {
        int b = 0;
        cin>>b;
        if(b==1){
            ones++;
        }else{
            twos++;
        }
    }
    if(twos%2==1 && ones>=2){
        ones-=2;
        twos++;
    }
    if(ones%2==0 && twos%2==0){
        cout<<"YES"<<endl;
    }
    else{
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