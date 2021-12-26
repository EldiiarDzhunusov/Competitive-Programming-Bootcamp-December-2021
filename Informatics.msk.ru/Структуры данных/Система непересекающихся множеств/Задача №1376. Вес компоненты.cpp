#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e6+5;
 
int n, m, p[N], sz[N], sum_w[N], x, y, w, type;
 
int get (int v) {
    if (v == p[v])
        return v;
    p[v] = get(p[v]);
    return p[v];
}
 
void unite (int a, int b, int w) {
    a = get(a);
    b = get(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
 
        sum_w[a] += sum_w[b];
        sz[a] += sz[b];
        p[b] = a;
    }
    sum_w[a] += w;
}
 
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        sz[i] = 1;
        sum_w[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        cin >> type;
        if (type == 1) {
            cin >> x >> y >> w;
            unite(x, y, w);
        } else {
            cin >> x;
            cout << sum_w[get(x)] << endl;
        }
    }
}