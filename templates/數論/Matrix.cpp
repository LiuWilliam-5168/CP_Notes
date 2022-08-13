// 矩陣乘法
struct Matrix {
    int a[maxn][maxn] = {};
    Matrix operator * (const Matrix &b) {
        Matrix c;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    c.a[i][j] += a[i][k] * b.a[k][j];
                }
                c.a[i][j] %= MOD;
            }
        }
        return c;
    }
};

// 矩陣快速冪
Matrix fstpow_matrix(Matrix a, int p) {
    Matrix rtn;
    for (int i = 0; i < n; i++) rtn.a[i][i] = 1;
    while (p > 0) {
        if (p & 1) {
            rtn = rtn * a;
        }
        a = a * a;
        p >>= 1;
    }
    return rtn;
}
