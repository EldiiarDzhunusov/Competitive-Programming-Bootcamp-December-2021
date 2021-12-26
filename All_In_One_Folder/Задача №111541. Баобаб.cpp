#include <bits/stdc++.h>
#define ll long long
using namespace std;


const int N = 105;
int n,cnt=0;
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
    cin>>n;
    int edges = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin>>g[i][j];
            edges+=g[i][j];
        }
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        if(used[i]==0){
            cout<<"NO"<<endl;
            return;
        }
    }
    if(n-1==(edges/2)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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