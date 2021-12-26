#include bitsstdc++.h
#define ll long long
using namespace std;

string to_string(vectorbool v) { bool first = true; string res = [; for (int i = 0; i  static_castint(v.size()); i++) {if (!first) { res += , ;} first = false; res += to_string(v[i]);} res += ]; return res;}
template typename A
string to_string(A v) { bool first = true; string res = [; for (const auto &x  v) { if (!first) {res += , ; } first = false; res += to_string(x);} res += ]; return res;}

bool checkerForBinarySearch(vectorlong long &v1, long long num,ll d){
    ll sum = 0;
    for (int i = 0; i  v1.size(); i++) {
        sum+=v1[i]num;
    }
    return sumd;
}

long long lBinSearch(long long l, long long r, vectorlong long &v1,ll d){
    Assuming that we know that the elements exists there for sure, but we want to find the most optimal one
    After some point all numbers will be considered as Good
    We need to find most left Good number
    while(lr){
        long long m = l + (r-l)2;
        if(checkerForBinarySearch(v1, m, d)){
            r = m;
        }else{
            l = m+1;
        }
    }
    return l;
}

void solve(){
    insert your code here
    ll n,d; cinnd;
    vectorll v1(n);
    for (int i = 0; i  n; i++) {
        cinv1[i];
    }
    ll ans = lBinSearch(1,10e92,v1,d);
    coutans-1endl;

}


int main(){
    iossync_with_stdio(false); cin.tie(0);
    long t = 1;
    cint;
    for (int i = 1; i = t  ; i++) {
        coutCase #i+ ;
        solve();
    }
}