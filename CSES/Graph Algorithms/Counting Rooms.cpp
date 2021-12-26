#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}
const int N = 1005;
char g[N][N];
int used[N][N];
int n,m;
 
void dfs(int x,int y){
    used[x][y] = 1;
    if(x-1>0 && g[x-1][y]=='.' && used[x-1][y]==0){
        dfs(x-1,y);
    }
    if(x+1<=n && g[x+1][y]=='.' && used[x+1][y]==0){
        dfs(x+1,y);
    }
    if(y+1<=m && g[x][y+1]=='.' && used[x][y+1]==0){
        dfs(x,y+1);
    }
    if(y-1>0 && g[x][y-1]=='.' && used[x][y-1]==0){
        dfs(x,y-1);
    }
}
 
void solve(){
    //insert your code here
    cin>>n>>m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin>>g[i][j];
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(g[i][j]== '.' && used[i][j]==0){
                cnt++;
                dfs(i,j);
 
            }
        }
    }
    cout<<cnt<<endl;
 
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