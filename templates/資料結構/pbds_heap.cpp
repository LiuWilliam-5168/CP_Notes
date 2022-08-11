template <typename T>
using heap = __gnu_pbds::priority_queue <T>;

heap <T> hp_a, hp_b;

// 將兩個合併 O(log |a|+|b|)
hp_a.join(hp_b);
