#include <bits/stdc++.h>

#define int long long
#define pii pair <int, int>
#define ff first 
#define ss second
using namespace std;
const int maxn = 2505;
const int INF = 1e18;

int n, m;
bool update = false;
bitset <maxn> vis;
vector <pii> e[maxn];   // {v, w}
vector <int> re[maxn];
vector <int> dis(maxn, INF);

void find(int u) {
    if (vis[u]) return;
    vis[u] = true;
    for (int v : re[u]) {
        find(v);
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;

    while (m--) {
        int u, v, w;  cin >> u >> v >> w;
        e[u].push_back({v, -w});
        re[v].push_back(u);
    }
    vis.reset();
    find(n);

    dis[1] = 0;
    for (int _ = 1; _ <= n; _++) {
        update = false;
        for (int u = 1; u <= n; u++) {
            if (dis[u] == INF) continue;
            for (auto p : e[u]) {
                int v = p.ff, w = p.ss;
                if (dis[v] > dis[u] + w) {
                    if (_ == n && vis[v]) update = true;
                    dis[v] = dis[u] + w;
                }
            }
        }
        if (update) {
            cout << -1 << "\n";
            exit(0);
        }
    }
    cout << -dis[n] << "\n";

    return 0;
}
