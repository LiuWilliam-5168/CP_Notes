template <typename T>
using rank_set = tree <T, null_type, less <T>, 
                       rb_tree_tag, tree_order_statistics_node_update>;

rank_set <T> rs;

// 找出第 k 大的迭代器位置 (0-based)
rs.find_by_order(k);

// 找到有幾個東西小於 k
rs.order_of_key(k);
