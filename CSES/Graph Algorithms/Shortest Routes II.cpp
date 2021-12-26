#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int N = 505;
ll g[N][N];
 
ll n,m,q;
ll a,b,c;
void solve(){
    //insert your code here
    cin>>n>>m>>q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = 1e15;
            g[i][i] = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        cin>>a>>b>>c;
        g[a][b] = min(c,g[a][b]);
        g[b][a] = min(c,g[b][a]);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        cin>>a>>b;
        if(g[a][b]==1e15){
            cout<<-1<<endl;
        }else{
            cout<<g[a][b]<<endl;
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