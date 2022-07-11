#include <bits/stdc++.h>

#define int long long
#define ff first
#define ss second
using namespace std;
const int maxn = 2e5 + 5, INF = 1e18, MOD = 1e9 + 7;

int n;
vector <pair <int, int>> ar(maxn);
vector <int> an;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> ar[i].ff >> ar[i].ss;
	}
	
	sort(ar.begin() + 1, ar.begin() + n + 1);
	
	for (int i = 1; i <= n; i++) {
		auto it = upper_bound(an.begin(), an.end(), ar[i].ss);
		
		if (it == an.end()) an.push_back(ar[i].ss);
		else *it = ar[i].ss;
	}
	
	cout << an.size() << "\n";
	
	return 0;
}
