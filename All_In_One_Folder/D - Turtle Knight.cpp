#include <bits/stdc++.h>
#define ll long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}

int dp[105][105];
void solve(){
    //insert your code here
    int n,m; cin>>n>>m;
//    if(m<n || 2*n<m){
//        cout<<-1<<endl;
//    }

    for (int i = 2; i < n+2; i++) {
        for (int j = 2; j < m+2; j++) {
            int num; cin>>num;
            if(i==2 && j==2 ){
                dp[i][j] = num;
                continue;
            }

            int temp =  max(dp[i-1][j-2],dp[i-2][j-1]);
            if(temp!=0){
                dp[i][j] = temp+num;
            }else{
                dp[i][j] = 0;
            }
        }
    }
//    for (int i = 1; i < n+3; i++) {
//        for (int j = 1; j < m+3; j++) {
//            cout<<dp[i][j]<<"\t";
//        }
//        cout<<endl;
//    }
    if(dp[n+1][m+1]==0){
        cout<<-1<<endl;
        return;
    }
    cout<<dp[n+1][m+1]<<endl;

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