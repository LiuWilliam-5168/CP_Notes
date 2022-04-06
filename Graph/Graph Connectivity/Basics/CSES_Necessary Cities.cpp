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
// dfn => 時間戳記, low => 最多經過一條回邊走到的最低時間戳記
vector <int> e[maxn];
set <int> cut;

void dfs(int u, int parent) {
    dfn[u] = low[u] = ++t;
    int cnt = 0;    // 看根有連幾塊
    for (int v : e[u]) {
        if (v == parent) continue;
        if (dfn[v]) {
            low[u] = min(low[u], dfn[v]);
        } else {
            dfs(v, u), cnt++;
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                cut.insert(u);
            }
        }
    }
    if (parent == -1 && cnt < 2) cut.erase(u);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;

    while (m--) {
        int a, b;  cin >> a >> b;
        e[a].pb(b), e[b].pb(a);
    }
    dfs(1, -1);
    cout << cut.size() << "\n";
    for (auto i : cut) {
        cout << i << ' ';
    }

    return 0;
}
