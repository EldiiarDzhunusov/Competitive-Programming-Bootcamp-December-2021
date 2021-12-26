#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 105;
const ll inf = 1e18;
ll g[N][N];
ll n;
void solve(){
    //insert your code here
    cin>>n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin>>g[i][j];
            if(g[i][j]==-1){
                g[i][j] = inf;
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    ll max1 = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(g[i][j]!=(inf)){
                max1 = max(max1,g[i][j]);
            }
        }
    }
    cout<<max1<<endl;

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