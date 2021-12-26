#include <bits/stdc++.h>
#define ll long long
using namespace std;
//Djikstra O(M log N)
const int N = 105;
int d[N];
const int inf = 1e9;
int n,s,f;
int g[N][N];
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
        d[i] = inf;
    }

    set<pair<int,int>> q;
    d[s] = 0;
    q.insert({0,s});
    while(!q.empty()){
        int v = q.begin()->second;
        q.erase(q.begin());
        for (int i = 1; i <= n; i++) {
            if(g[v][i]==inf) continue;
            int to = i;
            int len = g[v][i];
            if(d[v]+len<d[to]){
                q.erase({d[to],to});
                d[to] = d[v]+len;
                q.insert({d[to],to});
            }
        }
    }
    if(d[f]==inf) d[f]= -1;
    cout<<d[f]<<endl;
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