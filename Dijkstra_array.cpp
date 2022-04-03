#include <bits/stdc++.h>

#define int long long
const int INF = 1e9;
using namespace std;

// vector <pii> e[maxn];

vector <int> Dijkstra(const vector <vector <int>> &g, int start) {   // g[i][j] = weight i -> j
    vector <int> an(g.size(), INF);    // answer
    vector <int> d(g.size(), INF);   // data structure
    d[start] = 0;
    for (int _ = 0; _ < g.size(); _++) {
        int u, tmp = INF;
        for (int i = 0; i < g.size(); i++) {    // pq min
            if (an[i] == INF && d[i] < tmp) {
                u = i;
                tmp = d[i];
            }
        }
        an[u] = d[u];
        for (int i = 0; i < g.size(); i++) {    // push in pq
            d[i] = min(d[i], d[u] + g[u][i]);
        }
    }
    return an;
}

// m > (n^2 / log n) => array faster