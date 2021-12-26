#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

//string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
//template <typename A>
//string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}
bool check(string a, string b, string s){

    vector<ll> ans;
    for (int i = b.size()-1; i >=0; i--) {

        ans.push_back((a[i]-'0')+ (b[i])-'0');
    }
    string s1 = "";
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        s1+= to_string(ans[i]);
    }
//    cout<<s1<<" "<<s<<endl;
    if(s1==s){
        return true;
    }
    return false;

}

void solve(){
    //insert your code here
    string a,s; cin>>a>>s;
    int i = a.size()-1;
    int j = s.size()-1;
    vector<ll> ans;
    while(j>=0){
        if(i==-1){
            i = 0;
            a.insert(0,"0");
        }
        if(a[i]<s[j]){
            ans.push_back(s[j]-a[i]);
        }
        else{
            string num = to_string(s[j]-'0');
            ll upperNumber =a[i]-'0';
            while(stoll(num)<upperNumber){
                j--;
                if(j==-1){
                    cout<<-1<<endl;
                    return;
                }
                num.insert(0, to_string(s[j]-'0'));
            }
            ans.push_back(stoll(num)-upperNumber);
        }

        j--;
        i--;
    }
    int gaw =10;
//    cout<<to_string(ans)<<endl;
    reverse(ans.begin(), ans.end());
    string ansString = "";
    for (int k = 0; k < ans.size(); k++) {
//        cout<<ans[k];
        ansString+= to_string(ans[k]);
    }
//    cout<<ansString<<endl;
    if(check(a,ansString,s)==true){

        cout<<stoll(ansString)<<endl;
    }else{
        cout<<-1<<endl;
    }



}


int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    long t = 100;
    cin>>t;
    for (int i = 1; i <= t; i++) {
//        cout<<"Case #"<<i<<+": ";
        solve();
    }
}


/*      Solved by Eldiiar Dzhunusov       */