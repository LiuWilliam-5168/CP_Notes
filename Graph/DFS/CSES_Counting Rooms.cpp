#include <iostream>
#include <queue>
#include <cstring>

#define gogo ios_base::sync_with_stdio(0), cin.tie(0);
#define size 1005
#define pp pair <int, int>
#define ff first
#define ss second

using namespace std;

int dodo[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m, an = 0;
int g[size][size];
queue <pp> q;

void input() {	// 1e6 + 2 * 1e3
	memset(g, 0, sizeof(g));
	for (int i = 1; i <= n; i++) {	// 1000000
		for (int j = 1; j <= m; j++) {
			char c;  cin >> c;
			if (c == '#') {
				g[i][j] = 0;
			} else {
				g[i][j] = 1;
			}
		}
	}
}

int main() {
	gogo
	cin >> n >> m;
	
	input();	// 1e6
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (g[i][j]) {
				an++;
				g[i][j] = 0;
				q.push({i, j});
				while (!q.empty()) {
					pp tmp = q.front();  q.pop();
					for (int d = 0; d < 4; d++) {
						int x = tmp.ff + dodo[d][0], y = tmp.ss + dodo[d][1];
						if (g[x][y]) {
							g[x][y] = 0;
							q.push({x, y});
						}
					}
				}
			}
		}
	}
	
	cout << an << '\n';
	
	return 0;
}
