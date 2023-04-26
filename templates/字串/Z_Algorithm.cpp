int n;
string s;   // 1-based (0-based 也可以)
 
int z[maxn];
 
void Z_algo() {
    int l = 1, r = 1;
    for (int i = 2; i <= n; i++) {
        if (i + z[i - l + 1] <= r) {
            z[i] = z[i - l + 1];
        } else {
            l = i, r = max(i, r);
            while (r <= n && s[r] == s[r - i + 1]) ++r;
            z[i] = r - l;
            --r;
        }
    }
}
