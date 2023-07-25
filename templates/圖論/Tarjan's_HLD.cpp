struct Node {
    int val;
    int dep;
    int par;
    int sz;
    int next;
    int id;
    int root;
} inf[maxn];

struct HLD {
    void Pre(int u, int par, int d = 0) {
        int maxsub = 0;
        inf[u].dep = d;
        inf[u].par = par;
        inf[u].sz = 1;
        inf[u].next = -1;

        for (int v : e[u]) {
            if (v == par) continue;
            Pre(v, u, d + 1);
            
            inf[u].sz += inf[v].sz;
            if (inf[v].sz > maxsub) {
                maxsub = inf[v].sz;
                inf[u].next = v;
            }
        }
    }

    int ord = 0;
    void MapTo(int u, int par, int root) {
        inf[u].id = ++ord;
        inf[u].root = root;
        /* 丟入區間問題的資料結構，可以是 Segment Tree, BIT, Treap.... */
        seg.update(1, N, inf[u].id, inf[u].val, 1);

        if (inf[u].next != -1)
            MapTo(inf[u].next, u, root);

        for (int v : e[u]) {
            if (v == par) continue;
            if (v == inf[u].next) continue;
            MapTo(v, u, v);
        }
    }

    void update(int u, int val) {
        inf[u].val = val;
        seg.update(1, N, inf[u].id, val, 1);
    }

    int query(int s, int t) {
        int rtn = 0;
        while (inf[s].root != inf[t].root) {
            if (inf[inf[s].root].dep < inf[inf[t].root].dep)
                swap(s, t);

            rtn = max(rtn, seg.query(inf[inf[s].root].id, inf[s].id, 1, N, 1));
            s = inf[s].root;
            s = inf[s].par;
        }
        if (inf[s].id > inf[t].id)
            swap(s, t);
        rtn = max(rtn, seg.query(inf[s].id, inf[t].id, 1, N, 1));

        return rtn;
    }
} deco;
