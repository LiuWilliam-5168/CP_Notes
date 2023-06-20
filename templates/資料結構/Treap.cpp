const int maxn = (int)2e5 + 5;

mt19937 ran(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> ud(1, 1e9);

struct TreapNode
{
    int key, pri;
    int sz;

    bool rev;
    int val;
    int add_tag;
    int min_val;

    TreapNode *lc = nullptr;
    TreapNode *rc = nullptr;

    TreapNode() {}
    TreapNode(int _val) {
        sz = 1;
        rev = false;

        val = _val;
        min_val = _val;
        add_tag = 0;
        pri = ud(ran);
    }

    void push() {
        if (rev) {
            swap(lc, rc);
            if (lc) lc->rev ^= 1;
            if (rc) rc->rev ^= 1;
            rev = false;
        }
        if (add_tag) {
            if (lc) {
                lc->val += add_tag;
                lc->add_tag += add_tag;
                lc->min_val += add_tag;
            }
            if (rc) {
                rc->val += add_tag;
                rc->add_tag += add_tag;
                rc->min_val += add_tag;
            }
            add_tag = 0;
        }
    }
    void pull() {
        sz = 1;
        if (lc) sz += lc->sz;
        if (rc) sz += rc->sz;

        min_val = val;
        if (lc) min_val = min(min_val, lc->min_val);
        if (rc) min_val = min(min_val, rc->min_val);
    }
};

TreapNode pool[maxn];
int pool_ptr = 0;

TreapNode *GetNode(int val) {
    pool[pool_ptr] = TreapNode(val);
    return &pool[pool_ptr++];
}

int MySize(TreapNode *root) {
    if (root == nullptr) return 0;
    return root->sz;
}

TreapNode *Merge(TreapNode *a, TreapNode *b) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;
    if (a->pri <= b->pri) {
        a->push();
        a->rc = Merge(a->rc, b);
        a->pull();
        return a;
    } else {
        b->push();
        b->lc = Merge(a, b->lc);
        b->pull();
        return b;
    }
}

pair<TreapNode*, TreapNode*> SplitBySize(TreapNode *root, int sz) {
    if (root == nullptr) return {nullptr, nullptr};
    root->push();
    if (MySize(root->lc) + 1 <= sz) {
        auto [a, b] = SplitBySize(root->rc, sz - MySize(root->lc) - 1);
        root->rc = a;
        root->pull();
        return {root, b};
    } else {
        auto [a, b] = SplitBySize(root->lc, sz);
        root->lc = b;
        root->pull();
        return {a, root};
    }
}

int N, Q;

TreapNode *root = nullptr;

void solve() {
    while (Q--) {
        string op;  cin >> op;
        if (op == "ADD") {  // 在 [L, R] 的值加上 val
            int L, R, val;  cin >> L >> R >> val;
            if (L > R) swap(L, R);
            auto [a, tmp] = SplitBySize(root, L - 1);
            auto [b, c] = SplitBySize(tmp, R - L + 1);
            b->val += val;
            b->add_tag += val;
            b->min_val += val;
            root = Merge(Merge(a, b), c);
        } else if (op == "REVERSE") {   // 翻轉 [L, R]
            int L, R;  cin >> L >> R;
            if (L > R) swap(L, R);
            auto [a, tmp] = SplitBySize(root, L - 1);
            auto [b, c] = SplitBySize(tmp, R - L + 1);
            b->rev = true;
            root = Merge(Merge(a, b), c);
        } else if (op == "REVOLVE") {   // 旋轉 [L, R] K 次
            int L, R, K;  cin >> L >> R >> K;
            if (L > R) swap(L, R);
            K %= (R - L + 1);
            if (K < 0) K += (R - L + 1);
            auto [a, tmp1] = SplitBySize(root, L - 1);
            auto [tmp, d] = SplitBySize(tmp1, R - L + 1);
            auto [b, c] = SplitBySize(tmp, R - L + 1 - K);
            root = Merge(Merge(Merge(a, c), b), d);
        } else if (op == "INSERT") {    // 在 pos 後面加上一個 val
            int pos, val;  cin >> pos >> val;
            auto [a, b] = SplitBySize(root, pos);
            root = Merge(Merge(a, GetNode(val)), b);
        } else if (op == "DELETE") {    // 刪掉 pos
            int pos;  cin >> pos;
            auto [a, tmp] = SplitBySize(root, pos - 1);
            auto [b, c] = SplitBySize(tmp, 1);
            root = Merge(a, c);
        } else if (op == "MIN") {   // 區間 [L, R] 的最小值
            int L, R;  cin >> L >> R;
            if (L > R) swap(L, R);
            auto [a, tmp] = SplitBySize(root, L - 1);
            auto [b, c] = SplitBySize(tmp, R - L + 1);
            cout << b->min_val << '\n';
            root = Merge(Merge(a, b), c);
        }
    }
}

void init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;  cin >> x;
        root = Merge(root, GetNode(x));
    }
    cin >> Q;
}
