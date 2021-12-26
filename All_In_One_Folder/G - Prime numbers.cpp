#include <bits/stdc++.h>
#define ll long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}

bool isPrime(int n){
//    cout<<" ceil "<<ceil(sqrt(n))<<endl;
    for (int i = 2; i <= ceil(sqrt(n)); i++) {
        if(n!=2 && n%i==0){
            return false;
        }
    }
    return true;
}

void solve(){
    //insert your code here
    int n,m; cin>>n>>m;
    vector<int> v;
    for (int i = n; i <= m; i++) {
        if(isPrime(i)){
            v.push_back(i);
        }
    }
    if(v.size()==0){
        cout<<"Absent"<<endl;
    }else{
        for (int i = 0; i < v.size(); i++) {
            cout<<v[i]<<"\n";
        }
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