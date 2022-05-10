#include <bits/stdc++.h>

#define int long long
#define pii pair <int, int>
#define ff first
#define ss second
#define pb push_back
using namespace std;
const int maxn = 1e5 + 5, INF = 1e18;

int N, w[maxn], dp[maxn][2];
vector <int> e[maxn];

void dfs(int u) {
    dp[u][1] = w[u];
    for (int v : e[u]) {
        dfs(v);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> w[1];

    for (int v = 2; v <= N; v++) {
        int u;  cin >> u >> w[v];
        e[u].pb(v);
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << "\n";

    return 0;
}
