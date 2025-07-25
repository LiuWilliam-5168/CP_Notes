void dijkstra() {
	priority_queue <pii, vector <pii>, greater <>> pq;
	vector <int> dis(maxn, INF);

	pq.push({0, 1});
	while (!pq.empty()) {
		auto [d, u] = pq.top();  pq.pop();

		if (dis[u] < d) continue;

		for (auto [v, w] : e[u]) {
			if (d + w < dis[v]) {
				dis[v] = d + w;
				pq.push({dis[v], v});
			}
		}
	}
}
