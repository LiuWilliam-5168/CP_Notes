int dfn[maxn], low[maxn], scc[maxn], sccid = 0, ord = 0;
vector <int> e[maxn];
stack <int> stk;
bitset <maxn> instk;
 
void dfs(int u) {
	dfn[u] = low[u] = ++ord;
	stk.push(u);
	instk[u] = true;
	
	for (int v : e[u]) {
		if (!dfn[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if (instk[v]) {	// 為了排除 Cross Edge
			low[u] = min(low[u], dfn[v]);
		}
	}
	
	if (dfn[u] == low[u]) {
		sccid++;
		
		int x;
		do {
			x = stk.top();  stk.pop();
			scc[x] = sccid;
			instk[x] = false;
		} while (x != u);
	}
}
