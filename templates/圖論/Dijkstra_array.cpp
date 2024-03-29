vector <int> Dijkstra(const vector <vector <int>> &g, int start) {   // g[i][j] = weight i -> j
    vector <int> an(n, INF);    // answer
    vector <int> d(n, INF);   // data structure
    d[start] = 0;
    for (int _ = 0; _ < n; _++) {
        int u, tmp = INF;
        for (int i = 0; i < n; i++) {    // pq min
            if (an[i] == INF && d[i] < tmp) {
                u = i;  tmp = d[i];
            }
        }
        an[u] = d[u];
        for (int i = 0; i < n; i++) {    // push in pq
            d[i] = min(d[i], d[u] + g[u][i]);
        }
    }
    return an;
}

// m > (n^2 / log n) => array faster
