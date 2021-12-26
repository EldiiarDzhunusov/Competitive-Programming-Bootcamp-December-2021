#include <bits/stdc++.h>
#define ll long long
using namespace std;


int X[9] = {0,-1,-1,1,1,2,2,-2,-2};
int Y[9] = {0,2,-2,2,-2,1,-1,1,-1};
const int N = 55;
int g[N][N],n,a1,b1,a2,b2;
int used[N][N];
int used1[N][N];
int dist[N][N];
void solve(){
    cin>>n;
    bool isFirst = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char a; cin>>a;
            if(a=='@' && isFirst){
                isFirst = false;
                a1 = i;
                b1 = i;
                g[i][j] = 2;
            }else if(a=='@'){
                a2=i;
                b2 = j;
                g[i][j] = 2;
            }
            else if(a == '#'){
                g[i][j] = 0;
            }else{
                g[i][j] = 1;
            }
        }
    }
    queue<pair<int,int>> q;
    q.push({a1,b1});
    used[a1][b1] = 1;
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 1; i <= 8; i++) {
            int tox = x+X[i];
            int toy = y+Y[i];
            if(tox>=1 && tox<=n && toy >=1 && toy<= n && !used[tox][toy] && g[tox][toy]!=0){
                used[tox][toy] = 1;
                dist[tox][toy] = dist[x][y]+1;
                q.push({tox,toy});
            }
        }
    }
    if(dist[a2][b2]==0){
        cout<<"Impossible"<<endl;
        return;
    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            cout<<dist[i][j]<<" ";
//        }
//        cout<<endl;
//    }

    while(dist[a2][b2]>0){
        int x = a2;
        int y = b2;
        for (int i = 1; i <= 8; i++) {
            int tox = x+X[i];
            int toy = y+Y[i];
            if(tox>=1 && tox<=n && toy >=1 && toy<= n && dist[tox][toy]<dist[x][y] &&  g[tox][toy]!=0){

                a2 = tox;
                b2 = toy;
                g[a2][b2] = 2;
                break;

            }
        }
    }


    for (int i = 1; i <= n; i++) {
        for (int i2 = 1; i2 <= n; i2++) {
            if(g[i][i2]==2){
                cout<<"@";
            }else if(g[i][i2]==0){
                cout<<"#";
            }else{
                cout<<".";
            }

        }
        cout<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    long t = 1;
    for (int i = 1; i <= t; i++) {
        solve();
    }
}