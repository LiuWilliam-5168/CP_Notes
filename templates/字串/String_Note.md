# *String*

## Trie 字典樹

<details> ***Template***
```cpp
const int maxn = 1000005;
const int alphabet_size = 26;

struct TrieNode 
{
    struct TrieNode* kids[alphabet_size];
    
    bool isEnd;
    
    TrieNode() {
        fill(kids, kids + alphabet_size, nullptr);
        isEnd = false;
    }
};

struct TrieNode pool[maxn];
int pool_ptr = 0;

struct TrieNode* getNode() 
{
    pool[pool_ptr] = TrieNode();
    return &pool[pool_ptr++];
}

void insert(struct TrieNode* root, string word) 
{
    // 依題目要求來更改 insert() 內的東西
}


int search(struct TrieNode* root, string word) 
{
    // 依題目要求來更改 search() 內的東西
}
```
<details/>

Introduction: [here](https://www.geeksforgeeks.org/trie-insert-and-search/)
| Problems | Link | Solution | Notes |
| -------- | ---- | ---- | ----- |
| *GeeksforGeeks - Trie (Insert and Search)* | [Problem](https://practice.geeksforgeeks.org/problems/trie-insert-and-search0651/1) | [Code](https://practice.geeksforgeeks.org/viewSol.php?subId=69e57929d30ea85a5f8077dff09d2d5b&pid=701748&user=liuwilliam) |  |
| *CSES  - Word Combinations* | [Problem](https://cses.fi/problemset/task/1731) | [Code](https://cses.fi/paste/9cd173e3492fd381466058/) | 【一個大字串被幾個小字串組成的方法數】 |
| *LeetCode - 421. Maximum XOR of Two Numbers in an Array* | [Problem](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/) | [Code](https://leetcode.com/submissions/detail/798413929/) | 【XOR 最大值】 |


## Rolling Hash
| Problems | Link | Solution | Notes |
| -------- | ---- | ---- | ----- |
| *CSES  - Longest Palindrome* | [Problem](https://cses.fi/problemset/task/1111) | [Code](https://cses.fi/paste/3182a35b25d70c8e47aa2e/) | 【最長回文】 |


## Knuth–Morris–Pratt algorithm (KMP)
簡易模板 : [HERE](https://github.com/LiuWilliam-5168/Code/blob/main/templates/%E5%AD%97%E4%B8%B2/KMP_Algorithm.cpp)

> 定義 $f(i)$ 為 $S_1...S_i$ 的「次長共同前後綴長度」
> $$
> f(i) = 
> \begin{cases}
> f(i - 1) + 1, & \text{if $s[i] = s[f(i - 1) + 1]$}\\
> f(f(i - 1)) + 1, & \text{if $s[i] = s[f(f(i - 1)) + 1]$}\\
> \vdots
> \end{cases}
> $$
> Time Complexity : $\mathcal O(N) \Rightarrow \text{fail function}$

| Problems | Link | Solution | Notes |
| -------- | ---- | ---- | ----- |
| *CSES  - String Matching* | [Problem](https://cses.fi/problemset/task/1753/) | [Code](https://cses.fi/paste/f717854138e2814e46cba0/) | 【一個小字串在大字串中的個數】 |
| *CSES  - Finding Borders* | [Problem](https://cses.fi/problemset/task/1732/) | [Code](https://cses.fi/paste/e62e34ac5692395046cbd1/) | 【共同前後綴的個數】 |
| *CSES  - Finding Periods* | [Problem](https://cses.fi/problemset/task/1733/) | [Code](https://cses.fi/paste/314d83a1ad1009a74780a2/) | 【找出所有週期性出現的子字串長度】<br /> 建立一棵樹，判斷是否在子樹內 |
| *Kattis  - Quite a Problem* | [Problem](https://open.kattis.com/problems/quiteaproblem) | [Code](https://open.kattis.com/submissions/9412359) |  |


## Z-Algorithm
簡易模板 : [HERE](https://github.com/LiuWilliam-5168/Code/blob/main/templates/%E5%AD%97%E4%B8%B2/Z_Algorithm.cpp)

> 定義 $z[i]$ 為「以 $S_i$ 開頭和整個字串 $S$ 的最長共同前綴長度」
> 並且，已經暴力搜過的地方可以直接從前面 copy

| Problems | Link | Solution | Notes |
| -------- | ---- | ---- | ----- |
| *CSES  - String Functions* | [Problem](https://cses.fi/problemset/task/2107/) | [Code](https://cses.fi/paste/69e8be6c60a2348247f0bd/) | 【Z 和 KMP 的練習】 |
| *CSES  - String Matching* | [Problem](https://cses.fi/problemset/task/1753/) | [Code](https://cses.fi/paste/b47a75c07bd30cf8481683/) | 【一個小字串在大字串中的個數】 |


## Longest Palindromic Substring (LPS)
> Q: 如何檢查一個字串 $S$ 是不是迴文？
> A: 將 $S$ 反轉在檢查與原來一不一樣

### Manacher Algorithm
中國 LeetCode 影片講解 : [Here](https://youtu.be/5Rqomc7na7A?t=766)
另外一個請處的講解 : [Here](https://cppext.com/?p=1743)

Template : [Here](https://github.com/LiuWilliam-5168/Code/blob/main/templates/%E5%AD%97%E4%B8%B2/Manacher_Algorithm.cpp)

> Time Complexity : $\mathcal O(N)$

| Problems | Link | Solution | Notes |
| -------- | ---- | ---- | ----- |
| *CSES  - Longest Palindrome* | [Problem](https://cses.fi/problemset/task/1111) | [Code](https://cses.fi/paste/af0beb28195373ff488404/) | 【最長回文】 |
