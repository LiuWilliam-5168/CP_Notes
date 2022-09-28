int n;
string s;   // 1-based
 
int kmp[maxn];
 
void do_KMP() {
    for (int i = 2, now = 0; i <= n; i++) {
        while (now > 0 && s[i] != s[now + 1]) now = kmp[now];
        if (s[i] == s[now + 1]) {
            kmp[i] = ++now;
        }
    }
}
