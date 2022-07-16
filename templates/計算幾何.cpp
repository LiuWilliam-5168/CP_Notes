const double EPS = 1e-7, pi = acos(-1);

struct point {
	int x, y;

	point operator * (int a) { return {x * a, y * a}; }
	point operator / (int a) { return {x / a, y / a}; }
	point operator + (point b) { return {x + b.x, y + b.y}; }
	point operator - (point b) { return {x - b.x, y - b.y}; }

	int operator * (point b) { return x * b.x + y * b.y; }
	int operator ^ (point b) { return x * b.y - y * b.x; }
};

int abs(point a) {
	return sqrt(a.x * a.x + a.y * a.y);
}

// 判斷浮點數正負
int sign(double a) {
	if (abs(a) < EPS) return 0;
	else return a > 0 ? 1 : -1;
}

// 判斷向量 AB 轉到向量 AC 是順時針還是逆時針
int ori(point a, point b, point c) {	
	return sign((b - a) ^ (c - a));
}

// 判斷是否三點共線
bool colinear(point a, point b, point c) {	
	return sign((b - a) ^ (c - a)) == 0;
}

// 點 C 是否在線段上
bool between(point a, point b, point c) {
	if (!colinear(a, b, c)) return false;
	return sign((a - c) * (b - c)) <= 0;
}

// 線段 AB 和線段 CD 是否相交
bool banana(point a, point b, point c, point d) {
	int abc = ori(a, b, c);
	int abd = ori(a, b, d);
	int cda = ori(c, d, a);
	int cdb = ori(c, d, b);
	if (abc == 0 && abd == 0) {
		return between(a, b, c) || between(a, b, d) || between(c, d, a) || between(c, d, b);
	}
	return abc * abd <= 0 && cda * cdb <= 0;
}

// 線段交點
point banana_point(point a, point b, point c, point d) {
	int acd = (c - a) ^ (d - a);
	int bcd = (c - b) ^ (d - b);
	return (a * bcd + b * acd) / (acd + bcd);
}

// 三角形面積 (假如要算面積記得要除以 2)
int area(point a, point b, point c) {
	return abs((b - a) ^ (c - a));
}
