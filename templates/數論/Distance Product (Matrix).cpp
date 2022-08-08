Matrix operator * (const Matrix &a, const Matrix &b) {
    Matrix c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = INF;
            for (int k = 0; k < n; k++) {
                c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    return c;
}
