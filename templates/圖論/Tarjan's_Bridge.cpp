int t = 0;
vector <int> dfn(maxn), low(maxn);
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
            if (dfn[u] < low[v]) bridges.pb({u, v});
        }
    }
}
