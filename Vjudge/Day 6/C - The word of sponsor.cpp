#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 370;
const int inf = 1e9;
int n,m,k;
int d[N];
int g[N][N];
int a,b,c,s;
void solve(){
    cin>>n>>k>>m;
    vector<int> winners(k+1);
    for (int i = 0; i < k; i++) {
        cin>>winners[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = inf;
        }
    }

    for (int i = 1; i <= m; i++) {
        cin>>a>>b>>c;
        g[a][b]=min(c,g[a][b]);
        g[b][a]=min(c,g[b][a]);
    }
    cin>>s;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            cout << g[i][j] << " ";
//        }
//        cout<<endl;
//    }



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

//    for (int i = 1; i <= n; i++) {
//        cout<<d[i]<<" ";
//    }
//    cout<<endl;
    int mx = INT_MIN;
    for(int index : winners){
        if(d[index]==inf){
            cout<<"It is not fault of sponsor..."<<endl;
            return;
        }
        mx = max(mx,d[index]);
    }
    cout<<"The good sponsor!"<<endl;
    cout<<mx<<endl;

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