#include <bits/stdc++.h>
#define ll long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}
void print(int dp[],int n){ cout<<"[";  bool isFirst = true;    for (int i = 0; i <= n; i++) {        if(isFirst){            cout<<dp[i]<<" ";            isFirst=false;            continue;        }        cout<<", "<<dp[i];    }    cout<<"]";    cout<<endl;}

const int N = 105;
int a[N][N],n;

int distance(int x, int y, int z){
    return a[x][y] + a[x][z] + a[y][z];
}

void solve(){
    //insert your code here
    cin>>n;
    for (int i = 1; i <= n; i++) {
        for (int i2 = 1; i2 <= n; i2++) {
            cin>>a[i][i2];
        }
    }
    int x = 1;
    int y = 2;
    int z = 3;
    int ans = 1000000;
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            for (int k = j+1; k <= n; k++) {
                if(distance(i,j,k)< ans){
                    x = i;
                    y = j;
                    z = k;
                    ans = distance(x,y,z);
                }
            }
        }
    }
    cout<<x<<" "<<y<<" "<<z<<endl;

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