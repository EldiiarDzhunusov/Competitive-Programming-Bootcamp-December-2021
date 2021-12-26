#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
void solve(){
    //insert your code here
    cin>>n;
    std::string str = std::bitset<32>(n).to_string();
//    cout<<str<<endl;
    string ans = "";
    bool isMet = false;
    for (int i = 1; i <= str.size(); i++) {
        if(str[i]=='1'){
            isMet = true;
            ans = ans+"SX";
        }else if(str[i]=='0'&& isMet){
            ans+="S";
        }
    }
//    cout<<ans<<endl;
    for (int i = 2; i < ans.size(); i++) {
        cout<<ans[i];
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
