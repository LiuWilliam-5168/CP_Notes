struct Manacher_LPS {
    string s = "#|";
    
    int n;
    vector<int> z;    // 能從 i 往外走的步數
    int R = 1, C = 1;
    
    Manacher_LPS() {}
    Manacher_LPS(const string &_s) {
        for (int i = 0; i < (int)_s.size(); i++) {
            s += _s[i];
            s += "|";
        }
        n = (int)s.size() - 1;
        z.resize(n + 5);
    }

    vector<int> solve() {
        for (int i = 2; i <= n; i++) {
            int mirror = 2 * C - i;
            
            if (i <= R) {
                z[i] = min(z[mirror], R - i);
            }

            while (i + z[i] + 1 <= n && i - z[i] - 1 >= 1 && s[i - z[i] - 1] == s[i + z[i] + 1]) {
                ++z[i];
            }

            if (i + z[i] > R) {
                R = i + z[i];
                C = i;
            }
        }

        return z;
    }
};
