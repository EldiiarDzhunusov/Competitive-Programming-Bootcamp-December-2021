#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 10005;
int sieve[N];
int a,b;

int reverseNum(int num){
    string s = to_string(num);
    reverse(s.begin(), s.end());
    int ans =  stoi(s);
//    cout<<ans;
    return ans;
}
void solve(){
    //insert your code here
    cin>>a>>b;

    for (int i = 2; i < N; i++) {
        if(sieve[i]==0){
            for (int j = i+i; j <N; j+=i) {
                sieve[j]=1;
            }
        }
    }

//    for (int i = 1; i <= 100; i++) {
//        cout<<sieve[i]<<" ";
//    }

    sieve[1] = 1;
    ll ans = 0;
    for (int i = a; i <= b; i++) {

        if(sieve[i]==0 && sieve[reverseNum(i)]==0){
            ans++;
        }
    }
    cout<<ans<<endl;

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