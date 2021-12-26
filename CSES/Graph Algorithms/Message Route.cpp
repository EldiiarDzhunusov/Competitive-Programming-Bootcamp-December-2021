#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int N = 1e5+5;
vector<int> g[N];
int used[N];
int dist[N];
int n,m;
 
void solve(){
    //insert your code here
    cin>>n>>m;
    for (int i = 1; i <= m; i++) {
        int a,b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
 
    queue<int> q;
    q.push(1);
    used[1] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int num : g[x]){
            if(used[num]==0){
                used[num] = 1;
                q.push(num);
                dist[num] = dist[x]+1;
            }
        }
    }
//    for (int i = 1; i <= n; i++) {
//        cout<<dist[i]<<endl;
//    }
    if(dist[n]==0){
        cout<<"IMPOSSIBLE"<<endl;
    }
    int k = n;
    vector<int> ans;
    ans.push_back(n);
    while(dist[k]>0){
        for(int a : g[k]){
            if(dist[k]-dist[a]==1){
                k = a;
                ans.push_back(k);
                break;
            }
        }
    }
    reverse(ans.begin(), ans.end());
//    ans.push_back(n);
    cout<<ans.size()<<endl;
    for (int i = 0; i <= ans.size()-1; i++) {
        cout<<ans[i]<<" ";
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