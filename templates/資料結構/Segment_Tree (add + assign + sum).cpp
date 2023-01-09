struct Node {
	int sum, sz, give, add;
	Node() : sum(0), give(-1), add(0) {}
};

Node tr[maxn * 4];

struct SegTree {
	void push(int idx) {
		if (tr[idx].give != -1) {
			tr[idx * 2].give = tr[idx].give;
			tr[idx * 2].add = 0;
			tr[idx * 2].sum = tr[idx].give * tr[idx * 2].sz;
			tr[idx * 2 + 1].give = tr[idx].give;
			tr[idx * 2 + 1].add = 0;
			tr[idx * 2 + 1].sum = tr[idx].give * tr[idx * 2 + 1].sz;
			
			tr[idx].give = -1;
		}
		if (tr[idx].add != 0) {
			tr[idx * 2].add += tr[idx].add;
			tr[idx * 2].sum += tr[idx].add * tr[idx * 2].sz;
			tr[idx * 2 + 1].add += tr[idx].add;
			tr[idx * 2 + 1].sum += tr[idx].add * tr[idx * 2 + 1].sz;
			
			tr[idx].add = 0;
		}
	}
	void action(int idx) {
		tr[idx].sum = tr[idx * 2].sum + tr[idx * 2 + 1].sum;
	}
	void build(int l, int r, int idx) {
		tr[idx].sz = r - l + 1;
		
		if (l == r) return;
		
		int mid = (l + r) >> 1;
		build(l, mid, idx * 2);
		build(mid + 1, r, idx * 2 + 1);
	}
	void assign(int ql, int qr, int v, int l, int r, int idx) {
		if (ql <= l && r <= qr) {
			tr[idx].give = v;
			tr[idx].add = 0;
			tr[idx].sum = v * tr[idx].sz;
			
			return;
		}
		
		push(idx);
		
		int mid = (l + r) >> 1;
		if (ql <= mid) assign(ql, qr, v, l, mid, idx * 2);
		if (mid + 1 <= qr) assign(ql, qr, v, mid + 1, r, idx * 2 + 1);
		
		action(idx);
	}
	void adding(int ql, int qr, int v, int l, int r, int idx) {
		if (ql <= l && r <= qr) {
			tr[idx].add += v;
			tr[idx].sum += v * tr[idx].sz;
			
			return;
		}
		
		push(idx);
		
		int mid = (l + r) >> 1;
		if (ql <= mid) adding(ql, qr, v, l, mid, idx * 2);
		if (mid + 1 <= qr) adding(ql, qr, v, mid + 1, r, idx * 2 + 1);
		
		action(idx);
	}
	int query(int ql, int qr, int l, int r, int idx) {
		if (ql <= l && r <= qr) {
			return tr[idx].sum;
		}
		
		push(idx);
		
		int mid = (l + r) >> 1, rtn = 0;
		if (ql <= mid) rtn += query(ql, qr, l, mid, idx * 2);
		if (mid + 1 <= qr) rtn += query(ql, qr, mid + 1, r, idx * 2 + 1);
		
		return rtn;
	}
} tree;
