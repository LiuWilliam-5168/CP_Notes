vector <int> dijkstra(const vector <vector <pii>> &e, int start) {   // {neighbor, weight} 
    priority_queue <pii, vector <pii>, greater <pii>> pq;
    vector <int> dis(n, INF);
    
    pq.push({0, start});
    while (!pq.empty()) {
        auto [d, u] = pq.top();  pq.pop();
        
        if (dis[u] != INF) continue;
        dis[u] = cnt;
        for (auto [v, w] : e[u]) {
            pq.push({dis[u] + w, v});
        }
    }

    return dis;
}
