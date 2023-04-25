struct EdmondsKarp {
    int n, m;
    vector<vector<int>> rg;
 
    void init() {
        cin >> n >> m;
 
        rg = vector<vector<int>> (n + 1, vector<int> (n + 1));
 
        for (int i = 1; i <= m; i++) {
            int u, v, w;  cin >> u >> v >> w;
            rg[u][v] += w;
        }       
    }
 
    vector<int> par;
    vector<bool> vis;
 
    bool BFS(int s, int t) {
        par = vector<int> (n + 1);
        vis = vector<bool> (n + 1, false);
 
        queue<int> q;  q.push(s);
        vis[s] = true;
        par[s] = -1;
        while (!q.empty()) {
            int u = q.front();  q.pop();
 
            for (int v = 1; v <= n; v++) {
                if (!vis[v] and rg[u][v] > 0) {
                    q.push(v);
                    par[v] = u;
                    vis[v] = true;
                }
            }
        }
 
        return vis[t];
    }
 
    int MaxFlow(int s, int t) {
        int an = 0;
 
        while (BFS(s, t)) {
            int now_f = INF;
            for (int v = t, u; v != s; v = par[v]) {
                u = par[v];
                now_f = min(now_f, rg[u][v]);
            }
 
            for (int v = t, u; v != s; v = par[v]) {
                u = par[v];
                rg[u][v] -= now_f;
                rg[v][u] += now_f;
            }
 
            an += now_f;
        }
 
        return an;
    }
};
