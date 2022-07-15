vector <int> Dijkstra(const vector <vector <pii>> &g, int start) {   // pair <weight of edge, neighbor> 
    priority_queue <pii, vector <pii>, greater <pii>> pq;
    vector <int> dis(n, INF);
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto tmp = pq.top();  pq.pop();
        int cnt = tmp.ff, u = tmp.ss;
        if (dis[u] != INF) continue;
        dis[u] = cnt;
        for (auto e : g[u]) {
            pq.push({e.ff + dis[u], e.ss});
        }
    }

    return dis;
}