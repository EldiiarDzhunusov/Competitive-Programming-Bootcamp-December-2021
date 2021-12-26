#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 100005;
int sieve[N];
int a,b;
void solve(){
    //insert your code here
    cin>>a>>b;
    for (int i = 2; i <= b; i++) {
        if(sieve[i]==0){
            for (int j = i+i; j <= b; j+=i) {
                sieve[j]=1;
            }
        }
    }
    sieve[1] = 1;
    for (int i = a; i <= b; i++) {
        if(sieve[i]==0){
            cout<<i<<" ";
        }
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