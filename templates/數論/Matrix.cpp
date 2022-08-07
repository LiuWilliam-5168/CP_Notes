// 單位矩陣
Matrix identity() {
    Matrix rtn;
    for (int i = 0; i < n; i++) {
        rtn[i][i] = 1;
    }
    return rtn;
}

// 矩陣乘法
Matrix operator * (const Matrix &a, const Matrix &b) {
    Matrix c;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < b.size(); k++) {
                c[i][j] += a[i][k] * b[k][j] % MOD;
            }
            c[i][j] %= MOD;
        }
    }
    return c;
}

// 矩陣快速冪
Matrix fstpow_matrix(Matrix a, int p) {
    if (p == 0) return I;
    if (p == 1) return a;

    Matrix rtn = fstpow_matrix(a, p >> 1);
    if (p & 1) return rtn * rtn * a;
    else return rtn * rtn;
}
