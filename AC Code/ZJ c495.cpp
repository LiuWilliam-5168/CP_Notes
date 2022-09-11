#include <bits/stdc++.h>

#define int long long
#define ff first
#define ss second
#define pb push_back
#define pii pair <int, int>
using namespace std;
const int maxn = 1e5 + 5, maxm = 5e5 + 5, INF = (int)1e18, MOD = (int)1e9 + 7;

int n, m;

struct edge {
	int u, v, w, id;
	bool operator < (const edge &b) {
		return w < b.w;
	}
};

vector <edge> G(maxm);
vector <pii> e[maxn];
bitset <maxm> in_MST;

int par[maxn], sz[maxn];

int find(int u) { return (par[u] == u) ? u : par[u] = find(par[u]); }
void unite(int u, int v) {
	u = find(u), v = find(v);
	if (sz[u] > sz[v]) swap(u, v);
	par[u] = v, sz[v] += sz[u];
}

int mst = 0;

void MST() {
	iota(par, par + n + 1, 0);
	
	sort(G.begin() + 1, G.begin() + m + 1);
	
	for (int i = 1; i <= m; i++) {
		int u = G[i].u, v = G[i].v, w = G[i].w, id = G[i].id;
		int par_u = find(u), par_v = find(v);
		
		if (par_u != par_v) {
			unite(u, v);
			in_MST[id] = true;
			mst += w;
			
			e[u].push_back({v, w});
			e[v].push_back({u, w});
		}
	}
	
	cout << mst << ' ';
}

int tab[20][maxn], dp[20][maxn];
int dep[maxn];

void dfs(int u, int p) {
	for (auto [v, w] : e[u]) {
		if (v == p) continue;
		tab[0][v] = u;
		dp[0][v] = w;
		dep[v] = dep[u] + 1;
		dfs(v, u);
	}
}
void pre_lca() {
	for (int k = 1; k <= 19; k++) {
		for (int i = 1; i <= n; i++) {
			tab[k][i] = tab[k - 1][tab[k - 1][i]];
			dp[k][i] = max(dp[k - 1][i], dp[k - 1][tab[k - 1][i]]);
		}
	}
}
int query(int u, int v) {
	int rtn = 0;
	
	if (dep[u] > dep[v]) swap(u, v);
	
	for (int k = 19; k >= 0; k--) {
		if (dep[tab[k][v]] >= dep[u]) {
			rtn = max(rtn, dp[k][v]);
			v = tab[k][v];
		}
	}
	
	if (u == v) return rtn;
	
	for (int k = 19; k >= 0; k--) {
		if (tab[k][u] != tab[k][v]) {
			rtn = max({rtn, dp[k][u], dp[k][v]});
			u = tab[k][u], v = tab[k][v];
		}
	}
	rtn = max({rtn, dp[0][u], dp[0][v]});
	
	return rtn;
}

void sub_MST() {
	dfs(1, -1);
	
	pre_lca();
	
	int rtn = INF;
	
	for (int i = 1; i <= m; i++) {
		if (!in_MST[G[i].id]) {
			int u = G[i].u, v = G[i].v, w = G[i].w;
			int cnt = mst - query(u, v) + w;
			rtn = min(rtn, cnt);
		}
	}
	
	cout << rtn << endl;
}

void init() {
	fill(e, e + n + 1, vector <pii> ());
	in_MST.reset();
	mst = 0;
	fill(par, par + n + 1, 0);
	fill(sz, sz + n + 1, 0);
	memset(tab, 0, sizeof(tab));
	memset(dp, 0, sizeof(dp));
	fill(dep, dep + n + 1, 0);
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	while (cin >> n >> m) {
		init();

		for (int i = 1; i <= m; i++) {
			int u, v, w;  cin >> u >> v >> w;
			G[i] = {u, v, w, i};
		}
		
		MST();
		sub_MST();
	}
	
	return 0;
}
