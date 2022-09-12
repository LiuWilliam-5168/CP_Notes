const int alphabet_size = 26;

struct TrieNode 
{
    struct TrieNode* kids[alphabet_size];
    
    bool isEnd;
};

struct TrieNode* getNode() 
{
    TrieNode* parNode = NULL;

    parNode = (struct TrieNode*) malloc(sizeof(struct TrieNode));
    
    parNode->isEnd = false;

    for (int i = 0; i < alphabet_size; i++) {
        parNode->kids[i] = NULL;
    }

    return parNode;
}

void insert(struct TrieNode* root, string word) 
{
    struct TrieNode* pCrawl = root;

    for (int i = (int)word.size() - 1; i >= 0; i--) {
        int idx = word[i] - 'a';

        if (!pCrawl->kids[idx]) {
            pCrawl->kids[idx] = getNode();
        }

        pCrawl = pCrawl->kids[idx];
    }

    pCrawl->isEnd = true;
}

// 依題目要求來更改 search() 內的東西
vector<int> search(struct TrieNode* root, string word) 
{
    struct TrieNode* pCrawl = root;
    vector<int> rtn;

    for (int i = (int)word.size() - 1; i >= 0; i--) {
        int idx = word[i] - 'a';

        if (!pCrawl->kids[idx]) {
            return rtn;
        }

        pCrawl = pCrawl->kids[idx];

        if (pCrawl->isEnd) {
            rtn.push_back((int)word.size() - i);
        }
    }

    return rtn;
}
