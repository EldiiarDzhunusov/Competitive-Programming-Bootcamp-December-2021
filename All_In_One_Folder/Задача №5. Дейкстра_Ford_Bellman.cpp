#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Ford Bellman O(N*M)
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
    for (int k = 1; k <= n-1; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <=n; j++) {
                if(dist[i]+g[i][j]< dist[j]){
                    dist[j] = dist[i] + g[i][j];
                }
            }
        }
    }
    if(dist[f]==inf) dist[f] = -1;
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