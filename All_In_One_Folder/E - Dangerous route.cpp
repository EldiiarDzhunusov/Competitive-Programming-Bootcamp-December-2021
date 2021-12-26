#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6+6;
int p[N],sz[N], maxWeight = 0;
vector<pair<int,pair<int,int>>> g;
int x,y,w;
int n,m;

int getParent (int v) {
    if (v == p[v])
        return v;
    p[v] = getParent(p[v]);
    return p[v];
}
void unite (int a, int b, int w) {
    a = getParent(a);
    b = getParent(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        maxWeight = max(maxWeight,w);
        sz[a] += sz[b];
        p[b] = a;
    }
}


void solve(){
    //insert your code here
    cin>>n>>m;
    for (int i = 1; i <=n ; i++) {
        p[i] = i;
        sz[i] = 1;
    }


    for (int i = 1; i <= m; i++) {
        cin>>x>>y>>w;
        g.push_back({w,{x,y}});
    }
    sort(g.begin(),g.end());
    ll biggest = 0;
    for(auto x: g){
        if(getParent(1)== getParent(n)){
            cout<<maxWeight<<endl;
            return;
        }
        int a = x.second.first;
        int b = x.second.second;
        int c = x.first;
        unite(a, b, c);
    }
    if(getParent(1)== getParent(n)){
        cout<<maxWeight<<endl;
        return;
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