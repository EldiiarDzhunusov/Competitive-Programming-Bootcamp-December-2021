#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 105;
int g[N][N];

int n,s,f;
void solve(){
    //insert your code here
    cin>>n>>s>>f;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin>>g[i][j];
            if(g[i][j]==-1){
                g[i][j]= 1e7;
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    if(g[s][f]==1e7){
        cout<<-1<<endl;
        return;
    }
    cout<<g[s][f]<<endl;
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