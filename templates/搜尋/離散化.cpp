int n;
vector <int> ar(maxn);

void dis_bs() {
    vector <int> tmp(ar, ar + n);
    sort(tmp.begin(), tmp.end());
    tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
    
    for (int i = 0; i < n; i++) {
        ar[i] = lower_bound(tmp.begin(), tmp.end(), ar[i]) - tmp.begin() + 1;
    }
}
