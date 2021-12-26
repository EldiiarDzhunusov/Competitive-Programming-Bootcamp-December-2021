#include <bits/stdc++.h>
#define ll long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}
void print(int dp[],int n){ cout<<"[";  bool isFirst = true;    for (int i = 0; i <= n; i++) {        if(isFirst){            cout<<dp[i]<<" ";            isFirst=false;            continue;        }        cout<<", "<<dp[i];    }    cout<<"]";    cout<<endl;}

const int N = 105;
int a[N][N];
int color[N],n;
void solve(){
    //insert your code here
    cin>>n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin>>a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        cin>>color[i];
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            if(a[i][j]==1) {
                if (color[i] != color[j]) {
                    cnt++;
                }
            }
        }
    }
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
