#include <bits/stdc++.h>

#define int long long
#define pb push_back
#define pii pair <int, int>
#define ff first 
#define ss second
using namespace std;
const int maxn = 1e5 + 5;

int n, m, t = 0;
vector <int> dfn(maxn), low(maxn);  
// dfn => 時間戳記
// low => 最多經過一條回邊走到的最低時間戳記
vector <int> e[maxn];
vector <pii> bridges;

void dfs(int u, int parent) {
    dfn[u] = low[u] = ++t;
    for (int v : e[u]) {
        if (v == parent) continue;
        if (dfn[v]) {
            low[u] = min(low[u], dfn[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            // 從 u -> v, 當 dfn[u] < low[v] 時, {u, v} 為一條橋
            if (dfn[u] < low[v]) bridges.pb({u, v});
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;

    while (m--) {
        int a, b;  cin >> a >> b;
        e[a].pb(b), e[b].pb(a);
    }
    dfs(1, 1);
    cout << bridges.size() << "\n";
    for (auto [x, y] : bridges) {
        cout << x << ' ' << y << "\n";
    }

    return 0;
}
