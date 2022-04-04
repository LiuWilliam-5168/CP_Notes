#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#define size 100005
#define gogo ios_base::sync_with_stdio(0), cin.tie(0);

using namespace std;

int n, m;
vector <int> dis(size), g[size];
bitset <size> vis;
vector <int> an;
queue <int> q;

void GoBack(int u) {
	an.push_back(u);
	for (int v : g[u]) {
		if (dis[v] == dis[u] - 1) {
			GoBack(v);
			break;
		}
	}
}

int main() {
	gogo
	cin >> n >> m;
	
	for (int i = 1; i <= m; i++) {
		int u, v;  cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	q.push(1);  vis[1] = true;  dis[1] = 1;
	while (!q.empty()) {
		int u = q.front();  q.pop();
		for (int v : g[u]) {
			if (!vis[v]) {
				vis[v] = true;
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	
	if (!vis[n]) {
		cout << "IMPOSSIBLE\n";
	} else {
		an.push_back(0);
		GoBack(n);
		cout << dis[n] << '\n';
		for (auto it = prev(an.end()); it != an.begin(); it--) {
			cout << *it << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}
