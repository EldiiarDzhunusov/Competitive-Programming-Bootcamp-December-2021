#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 3;
 
int n, m, q;
int u[N], v[N];
int p[N], sz[N];
string type[N], ans[N];
 
int find_parent(int v) {
    if (v == p[v]) return v;
    p[v] = find_parent(p[v]);
    return p[v];
}
 
void unite_set(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
    }
}
 
int main(){
    cin >> n >> m >> q;
 
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        sz[i] = 1;
    }
 
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
    }
 
    for (int i = 1; i <= q; i++) {
        cin >> type[i] >> u[i] >> v[i];
    }
 
    for (int i = q; i >= 1; i--) {
        if (type[i] == "ask") {
            if (find_parent(u[i]) == find_parent(v[i])) {
                ans[i] = "YES";
            } else {
                ans[i] = "NO";
            }
        } else {
            unite_set(u[i], v[i]);
        }
    }
 
    for (int i = 1; i <= q; i++) {
        if (type[i] == "ask")
            cout << ans[i] << endl;
    }
}