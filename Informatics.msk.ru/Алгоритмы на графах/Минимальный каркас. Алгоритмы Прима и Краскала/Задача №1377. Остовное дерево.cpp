#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e6+5;
 
int n, m, p[N], sz[N], x, y, w;
long long sum_w[N];
 
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
 
        sum_w[a] += sum_w[b] + w;
        sz[a] += sz[b];
        p[b] = a;
    }
}
vector <pair <int, pair <int, int> > > g;
 
int main(){
    cin >> n >> m;    
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        sz[i] = 1;
        sum_w[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> w;
        g.push_back({w, {x, y}});
    }
    sort(begin(g), end(g));
 
    for (auto i : g) {
        int a = i.second.first, b = i.second.second;
        unite(a, b, i.first);
    }
    cout << sum_w[get(1)] << endl;
}