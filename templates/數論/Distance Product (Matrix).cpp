Matrix operator * (const Matrix &a, const Matrix &b) {
    Matrix c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c.a[i][j] = INF;
            for (int k = 0; k < n; k++) {
                c.a[i][j] = min(c.a[i][j], a.a[i][k] + b.a[k][j]);
            }
        }
    }
    return c;
}
