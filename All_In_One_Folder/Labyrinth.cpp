#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}
void print(int dp[],int n){ cout<<"[";  bool isFirst = true;    for (int i = 0; i <= n; i++) {        if(isFirst){            cout<<dp[i]<<" ";            isFirst=false;            continue;        }        cout<<", "<<dp[i];    }    cout<<"]";    cout<<endl;}
 
const int N = 1005;
char g[N][N];
int dist[N][N];
bool used[N][N];
int n,m,a1,b1,a2,b2;
 
void solve(){
    //insert your code here
    cin>>n>>m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin>>g[i][j];
            if(g[i][j]=='A'){
                a1=i;
                b1=j;
            }
            if(g[i][j] == 'B'){
                a2 = i;
                b2 = j;
            }
        }
    }
    queue<pair<int,int>> q;
    q.push({a1,b1});
    used[a1][b1]=true;
 
    while(!q.empty()){
 
 
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x-1>0 && (g[x-1][y]=='.' || g[x-1][y]=='B') && used[x-1][y]==false ){
            q.push({x-1,y});
            used[x-1][y] = true;
            dist[x-1][y] = dist[x][y]+1;
        }
        if(x+1<=n && (g[x+1][y]=='.' || g[x+1][y]=='B') && used[x+1][y]==false ){
            q.push({x+1,y});
            used[x+1][y] = true;
            dist[x+1][y] = dist[x][y]+1;
        }
        if(y-1>0 && (g[x][y-1]=='.' || g[x][y-1]=='B') && used[x][y-1]==false ){
            q.push({x,y-1});
            used[x][y-1] = true;
            dist[x][y-1] = dist[x][y]+1;
        }
        if(y+1<=m && (g[x][y+1]=='.' || g[x][y+1]=='B') && used[x][y+1]==false ){
            q.push({x,y+1});
            used[x][y+1] = true;
            dist[x][y+1] = dist[x][y]+1;
        }
    }
    if(dist[a2][b2]==0){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    cout<<dist[a2][b2]<<endl;
    vector<string> ans;
    while(dist[a2][b2]>0){
        int x = a2;
        int y = b2;
//        for(auto x : ans){
//            cout<<x<<" ";
//        }
//        cout<<endl;
 
        if(x-1>0 && (g[x-1][y]=='.' || g[x-1][y]=='A') && (dist[x][y]-dist[x-1][y]==1)){
            a2 = x-1;
            b2 = y;
            ans.push_back("D");
            continue;
 
 
        }
        if(x+1<=n && (g[x+1][y]=='.' || g[x+1][y]=='A') && (dist[x][y]-dist[x+1][y]==1) ){
            a2 = x+1;
            b2 = y;
            ans.push_back("U");
            continue;
 
        }
        if(y-1>0 && (g[x][y-1]=='.' || g[x][y-1]=='A') && (dist[x][y]-dist[x][y-1]==1) ){
            a2 = x;
            b2 = y-1;
            ans.push_back("R");
            continue;
 
        }
        if(y+1<=m && (g[x][y+1]=='.' || g[x][y+1]=='A') && (dist[x][y]-dist[x][y+1]==1) ){
            a2 = x;
            b2 = y+1;
            ans.push_back("L");
            continue;
 
        }
 
 
    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            cout<<dist[i][j]<<" ";
//        }
//        cout<<endl;
//    }
 
    reverse(ans.begin(), ans.end());
    for (int i = 0; i <= ans.size(); i++) {
        cout<<ans[i];
    }
    cout<<endl;
 
 
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