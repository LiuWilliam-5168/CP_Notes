#include <bits/stdc++.h>

#define int long long
#define pp pair <int, int>
#define ff first
#define ss second
const int INF = 1e9;
using namespace std;

vector <int> Dijkstra(const vector <vector <pp>> &g, int start) {   // pair <weight of edge, neighbor> 
    priority_queue <pp, vector <pp>, greater <pp>> pq;
    vector <int> dis(g.size(), INF);
    pq.push({0, start});
    
    while (!pq.empty()) {
        pp u = pq.top();  pq.pop();
        if (dis[u.ss] != INF) continue;
        dis[u.ss] = u.ff;
        for (pp e : g[u.ss]) {
            pq.push({e.ff + dis[u.ss], e.ss});
        }
    }

    return dis;
}