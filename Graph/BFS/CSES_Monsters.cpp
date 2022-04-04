#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>

#define gogo ios_base::sync_with_stdio(0), cin.tie(0);
#define maxn 1005
#define pp pair <int, int>
#define ff first
#define ss second
using namespace std;

int n, m;
pair <int, int> start;
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int g[maxn][maxn];
int monster[maxn][maxn];
int player[maxn][maxn];
bool monster_vis[maxn][maxn] = {};
bool player_vis[maxn][maxn] = {};
queue <pp> monster_q, player_q;
string an = "";

void Input() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;  cin >> c;
			if (c == '#') {
				g[i][j] = 0; 
			} else if (c == '.') {
				g[i][j] = 1;
			} else if (c == 'M') {
				g[i][j] = 1;
				monster_q.push({i, j});
				monster[i][j] = 1;
				monster_vis[i][j] = true;
			} else {
				g[i][j] = 1;
				player_q.push({i, j});
				player[i][j] = 1;
				player_vis[i][j] = true;
				start = {i, j};
			}
		}
	}
}
void BFSMonster() {
	while (!monster_q.empty()) {
		pp tmp = monster_q.front();  monster_q.pop();
		int timer = monster[tmp.ff][tmp.ss] + 1;
		for (int k = 0; k < 4; k++) {
			int x = tmp.ff + d[k][0];
			int y = tmp.ss + d[k][1];
			if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] && !monster_vis[x][y]) {
				monster[x][y] = timer;
				monster_q.push({x, y});
				monster_vis[x][y] = true;
			}
		}
	}
}
void BFSPlayer() {
	while (!player_q.empty()) {
		pp tmp = player_q.front();  player_q.pop();
		int timer = player[tmp.ff][tmp.ss] + 1;
		for (int k = 0; k < 4; k++) {
			int x = tmp.ff + d[k][0];
			int y = tmp.ss + d[k][1];
			if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] && !player_vis[x][y]) {
				player[x][y] = timer;
				player_q.push({x, y});
				player_vis[x][y] = true;
			}
		}
	}
}
void Answer() {
	int x, y;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (player[i][0] < monster[i][0]) {
			x = i, y = 0;
			flag = false;  break;
		} else if (player[i][m - 1] < monster[i][m - 1]) {
			x = i, y = m - 1;
			flag = false;  break;
		}
	}
	if (flag) {
		for (int j = 0; j < m; j++) {
			if (player[0][j] < monster[0][j]) {
				x = 0, y = j;
				flag = false;  break;
			} else if (player[n - 1][j] < monster[n - 1][j]) {
				x = n - 1, y = j;
				flag = false;  break;
			}
		}
	}
	if (flag) {
		cout << "NO\n";
		return;
	} else {
		while (x != start.ff || y != start.ss) {
			// printf("(x, y) = (%d, %d)\n", x, y);
			for (int k = 0; k < 4; k++) {
				int i = x + d[k][0], j = y + d[k][1];
				// printf("(i, j) = (%d, %d)\n", i, j);
				if (i >= 0 && i < n && j >= 0 && j < m && player[i][j] == player[x][y] - 1 && g[i][j]) {
					x = i, y = j;
					if (k == 0) an += "U";
					else if (k == 1) an += "D";
					else if (k == 2) an += "L";
					else an += "R";
					
					break;
				}
			}
		}
		
		cout << "YES" << "\n";
		cout << an.size() << "\n";
		for (int i = an.size() - 1; i >= 0; i--) {
			cout << an[i];
		}
		cout << "\n";
	}
}

int main() {
	gogo
	cin >> n >> m;
	memset(monster, 0x3f3f3f3f, sizeof(monster));
	memset(player, 0x3f3f3f3f, sizeof(player));
	
	Input();
	BFSMonster();
	BFSPlayer();
	Answer();
	
	return 0;
}
