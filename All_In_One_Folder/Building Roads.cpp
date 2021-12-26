#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int N = 1e5+5;
bool used[N];
vector<int> g[N];
int n,m;
 
void dfs(int v){
    used[v] = true;
 //   cout<<endl<<"Node: "<<v<<endl;
    for (int num : g[v]) {
//        cout<<num<<" ";
        if(used[num]==false){
            dfs(num);
        }
    }
}
void solve(){
    //insert your code here
    cin>>n>>m;
    for (int i = 1; i <= m; i++) {
        int a; cin>>a;
        int b; cin>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
//    for (int i = 1; i <= n; i++) {
//        for(auto x : g[i]){
//            cout<<x<<" ";
//        }
//        cout<<"\n";
//    }
    int counter = 0;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if(used[i]==false){
            used[i] = true;
            counter++;
            ans.push_back(i);
            dfs(i);
        }
    }
    cout<<counter-1<<endl;
    for (int i = 1; i < ans.size(); i++) {
        cout<<ans[i - 1]<< " " << ans[i] << endl;
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