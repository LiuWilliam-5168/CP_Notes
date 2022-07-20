int fstpow(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;

    int mid = fstpow(a, b / 2);
    if (b & 1) return mid * mid % MOD * a % MOD;
    else return mid * mid % MOD;
}
