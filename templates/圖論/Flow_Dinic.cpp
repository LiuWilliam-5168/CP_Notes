struct Dinic {
	struct Edge {
		int u, v, cap, rest;
	};
 
	int n, m, s, t;
	int d[maxn], cur[maxn];
	vector<Edge> edges;
	vector<int> g[maxn];
 
	void init() {
		edges.clear();
		for (int i = 0; i < n; i++) g[i].clear();
		n = 0;
	}
	
	void AddEdge(int u, int v, int cap) {
		edges.push_back({u, v, cap, cap});
		edges.push_back({v, u, 0, 0});
		m = sz(edges);
		g[u].push_back(m - 2);
		g[v].push_back(m - 1);
	}
 
	bool bfs() {
		fill(d, d + n, -1);
		queue<int> q;  
		q.push(s);  d[s] = 0;
		while (!q.empty()) {
			int u = q.front();  q.pop();
			for (int ei : g[u]) {
				Edge &e = edges[ei];
				if (d[e.v] < 0 and e.rest > 0) {
					d[e.v] = d[u] + 1;
					q.push(e.v);
				}
			}
		}
		return d[t] >= 0;
	}
 
	int dfs(int u, int now) {
		if (u == t or now == 0) return now;
		int rtn = 0, f;
		for (int i = cur[u]; i < sz(g[u]); i++) {
			Edge &e = edges[g[u][i]];
			if (d[e.v] != d[u] + 1) continue;
			f = dfs(e.v, min(now, e.rest));
			if (f > 0) {
				e.rest -= f;
				edges[g[u][i] ^ 1].rest += f;
				rtn += f;
				now -= f;
				if (now == 0) break;
			}
		}
		return rtn;
	}
 
	int MaxFlow(int _s, int _t) {
		s = _s, t = _t;
		int an = 0, mf;
		while (bfs()) {
			fill(cur, cur + n, 0);
			while (mf = dfs(s, INF)) an += mf;
		}
		return an;
	}
};
