vector <point> tubao() {
	for (int i = 1; i <= n; i++) {
		cin >> ar[i].x >> ar[i].y;
	}
	sort(ar.begin() + 1, ar.begin() + n + 1);
	
	vector <point> hull;

	for (int _ = 1; _ <= 2; _++) {
		int sz = (int)hull.size();
		for (int i = 1; i <= n; i++) {
			if ((int)hull.size() - sz < 2) {
				hull.push_back(ar[i]);
				continue;
			}
			point a = hull[(int)hull.size() - 2], b = hull[(int)hull.size() - 1];
			while ((int)hull.size() - sz >= 2 && ori(a, b, ar[i]) <= 0) {
				hull.pop_back();
				if ((int)hull.size() >= 2) {
					a = hull[(int)hull.size() - 2], b = hull[(int)hull.size() - 1];
				}
			}
			hull.push_back(ar[i]);
		}
		hull.pop_back();
		reverse(ar.begin() + 1, ar.begin() + n + 1);
	}

	return hull;
}
int rotating_caliper(vector <point> hull) {
	int sz = hull.size(), rtn = 0;

	if (sz == 2) return abs(hull[0] - hull[1]);

	hull.push_back(hull[0]);  ++sz;

	for (int l = 0, r = 2; l < sz - 1; l++) {
		while (area(hull[l], hull[l + 1], hull[r]) < area(hull[l], hull[l + 1], hull[(r + 1) % (sz - 1)])) {
			r = (r + 1) % (sz - 1);
		}
		rtn = max({rtn, abs(hull[l] - hull[r]), abs(hull[l + 1] - hull[r])});
	}
	return rtn;
}
