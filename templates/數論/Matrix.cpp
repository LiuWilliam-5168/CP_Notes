// 矩陣
struct Matrix
{
	int R, C;
	vector<vector<long long>> m;

	Matrix() {}
	Matrix(int r, int c) : R(r), C(c) {
		m = vector<vector<long long>> (R, vector<long long> (C));
	}

	void input() {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> m[i][j];
			}
		}
	}

	Matrix operator * (const Matrix &b) {
		Matrix rtn(R, b.C);
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < b.C; j++) {
				for (int k = 0; k < C; k++) {
					rtn.m[i][j] += m[i][k] * b.m[k][j];
				}
			}
		}
		return rtn;
	}

	bool operator == (const Matrix &b) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (m[i][j] != b.m[i][j])
					return false;
			}
		}
		return true;
	}
};

// 矩陣快速冪
Matrix fstpow_matrix(Matrix a, int p) {
    Matrix rtn;
    for (int i = 0; i < n; i++) rtn.m[i][i] = 1;
    while (p > 0) {
        if (p & 1) {
            rtn = rtn * a;
        }
        a = a * a;
        p >>= 1;
    }
    return rtn;
}
