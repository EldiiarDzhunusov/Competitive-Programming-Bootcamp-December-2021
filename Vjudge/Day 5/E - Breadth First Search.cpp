#include <bits/stdc++.h>
#define ll long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}
void print(int dp[],int n){ cout<<"[";  bool isFirst = true;    for (int i = 0; i <= n; i++) {        if(isFirst){            cout<<dp[i]<<" ";            isFirst=false;            continue;        }        cout<<", "<<dp[i];    }    cout<<"]";    cout<<endl;}

const int N = 105;
int n,s,f;
int g[N][N];
bool used[N];
int distance1[N];
void solve(){
    //insert your code here
    cin>>n>>s>>f;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin>>g[i][j];
        }
    }
    queue<int> q;
    q.push(s);
    used[s] = true;
    while(!q.empty()){
        int x = q.front();

//        cout<<x<<" ";
        q.pop();
        for (int i = 1; i <= n; i++) {
            if(g[x][i]==1 && used[i]==false){

                distance1[i] = distance1[x]+1;
                q.push(i);
                used[i] = true;

            }
        }
    }
    cout<<distance1[f]<<endl;

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