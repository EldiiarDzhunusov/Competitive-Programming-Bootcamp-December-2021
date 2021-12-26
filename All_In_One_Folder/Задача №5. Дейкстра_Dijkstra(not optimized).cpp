#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Dijkstra O(N^2+M)
const int N = 105;
const int inf = 1e9;
int g[N][N];
int dist[N];
int path[N];
bool used[N];
int n,s,f;
void solve(){
    //insert your code here
    cin>>n>>s>>f;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin>>g[i][j];
            if(g[i][j]==-1){
                g[i][j] = inf;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        dist[i] = inf;
    }
    dist[s] = 0;
    for (int i = 1; i <= n; i++) {
        int v = -1;
        for (int j = 1; j <= n; j++) {
            if(!used[j] &&(v==-1 || dist[j]<dist[v])){
                v = j;
            }
        }
        if(v==-1 || dist[v]==inf){
            break;
        }

        used[v] = true;
        for (int to = 1; to <= n; to++) {
            int len = g[v][to];
            if(dist[v] + len< dist[to]){
                dist[to] = dist[v]+len;
                path[to] = v;
            }
        }
    }
    if(dist[f]==inf){
        cout<<-1<<endl;
        return;
    }
    cout<<dist[f]<<endl;
    
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