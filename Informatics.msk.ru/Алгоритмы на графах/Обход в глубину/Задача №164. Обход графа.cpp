#include <bits/stdc++.h>
#define ll long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}

int n,s;
vector<int> vec[105];
int vis[105],cnt,x;

void dfs(int v){
    cnt++;
    vis[v] = 1;
    for (int i = 0; i < vec[v].size(); i++) {
        int to = vec[v][i];
        if(vis[to]==0){
            dfs(to);
        }
    }
}
void solve(){
    //insert your code here
    cin>>n>>s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin>>x;
            if(x==1){
                vec[i].push_back(j);
            }
        }
    }
    dfs(s);
    cout<<cnt<<endl;

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