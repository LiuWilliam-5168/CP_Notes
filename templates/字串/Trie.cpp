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
