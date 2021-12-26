#include <bits/stdc++.h>
#define ll long long
using namespace std;
string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}
void print(int dp[],int n){ cout<<"[";  bool isFirst = true;    for (int i = 0; i <= n; i++) {        if(isFirst){            cout<<dp[i]<<" ";            isFirst=false;            continue;        }        cout<<", "<<dp[i];    }    cout<<"]";    cout<<endl;}

int n,m;
const int N = 205;
ll a[N][N], dp[N][N], cnt[N][N];

void solve(){
    //insert your code here
    cin>>n>>m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin>>a[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        dp[1][i] = a[1][i];
        cnt[1][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int mx = dp[i-1][j];

            if(j-1 >=1 && mx<dp[i-1][j-1]){
                mx = dp[i-1][j-1];
            }
            if(j+1<=m && mx< dp[i-1][j+1]){
                mx = dp[i-1][j+1];
            }

            dp[i][j] = mx + a[i][j];
            if(j-1>= 1 && dp[i-1][j-1]==mx){
                cnt[i][j] += cnt[i-1][j-1];
            }
            if(dp[i-1][j]==mx){
                cnt[i][j] +=cnt[i-1][j];
            }
            if(j+1 <= m  && dp[i-1][j+1]==mx){
                cnt[i][j]+= cnt[i-1][j+1];
            }
        }
    }

    ll mx = dp[n][1];
    for (int i = 2; i <= m; i++) {
        mx = max(mx,dp[n][i]);
    }
    cout<<mx<<" ";

    ll cn = 0;
    for (int i = 1; i <= m; i++) {
        if(dp[n][i]==mx){
            cn+= cnt[n][i];
        }
    }
    cout<<cn<<endl;

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