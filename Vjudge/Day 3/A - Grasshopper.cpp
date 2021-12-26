#include <bits/stdc++.h>
#define ll long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}
int ans = 0;

void recursion(int distance, int counter,int n,int k){
    if(distance>=n){
        ans++;
        return;
    }
    for (int i = 1; i <= k; i++) {
//        cout<<distance+i<<" "<<n<<" "<<k<<endl;
        recursion(distance+i, counter,n,k);
    }
}

void solve(){
    //insert your code here
    int n,k; cin>>n>>k;
    vector<int> an;
    an.push_back(1);
    int sum = 0;
    for (int i = 1; i <= min(n,k); i++) {
        sum+=an.back();
        an.push_back(sum);
    }

    for (int i = k+1; i <=n ; i++) {
        sum = 0;
        for (int j = an.size()-k; j < an.size(); j++) {
            sum+=an[j];
        }
        an.push_back(sum);
    }
//    cout<<to_string(an)<<endl;
    cout<<an[n-1]<<endl;

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
