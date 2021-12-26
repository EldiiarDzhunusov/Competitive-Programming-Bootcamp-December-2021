#include <bits/stdc++.h>
#define ll long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}
void print(int dp[],int n){ cout<<"[";  bool isFirst = true;    for (int i = 0; i <= n; i++) {        if(isFirst){            cout<<dp[i]<<" ";            isFirst=false;            continue;        }        cout<<", "<<dp[i];    }    cout<<"]";    cout<<endl;}

const int N = 105;
int n,m,cnt=0;
int g[N][N];
int used[N];

void dfs(int v){
    used[v] = 1;
    for (int i = 1; i <= n; i++) {
        if(g[v][i]==1 && used[i]==0){
            dfs(i);
        }
    }
}

void solve(){
    //insert your code here
    cin>>n>>m;
    for (int i = 1; i <= m; i++) {
        int x,y; cin>>x>>y;
        g[x][y] = 1;
        g[y][x] = 1;
    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            cout<<g[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        if(used[i]==0){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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