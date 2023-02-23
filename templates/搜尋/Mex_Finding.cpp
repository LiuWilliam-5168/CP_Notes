int firstMissingPositive(vector<int>& ar) {
    for (int i = 0; i < (int)ar.size(); i++) {
        while (ar[i] > 0 && ar[i] < (int)ar.size() && ar[ar[i] - 1] != ar[i]) {
            swap(ar[i], ar[ar[i] - 1]);
        }
    }
    for (int i = 0; i < (int)ar.size(); i++) {
        if (ar[i] != i + 1) return i + 1;
    }
    return (int)ar.size() + 1;
}
