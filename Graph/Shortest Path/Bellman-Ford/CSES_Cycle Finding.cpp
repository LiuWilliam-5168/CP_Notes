#include <bits/stdc++.h>

#define int long long
#define pii pair <int, int>
#define ff first
#define ss second
#define pb push_back
using namespace std;
const int maxn = 2505;
const int INF = 1e18;

int n, m, start;
bool update = false;
vector <pii> e[maxn];   // {v, w}
vector <int> dis(maxn, INF);
vector <int> an;
vector <int> from(maxn, 0);

void dfs(int u) {
    an.pb(u);
    if (u == start && an.size() > 1) return;
    dfs(from[u]);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) e[0].pb({i, 0});
    while (m--) {
        int u, v, w;  cin >> u >> v >> w;
        e[u].pb({v, w});
    }
    dis[0] = 0;
    for (int _ = 0; _ <= n; _++) {
        for (int u = 0; u <= n; u++) {
            for (auto p : e[u]) {
                int v = p.ff, w = p.ss;
                if (dis[v] > dis[u] + w) {
                    if (_ == n) {
                        update = true;
                    }
                    dis[v] = dis[u] + w;
                    from[v] = u;
                    start = u;
                }
            }
        }
    }
    if (update) {
        cout << "YES\n";
        for (int i = 1; i <= n; i++) start = from[start];   // 確保 start 在負環內
        dfs(start);
        reverse(an.begin(), an.end());
        for (int i : an) cout << i << ' ';
        cout << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
