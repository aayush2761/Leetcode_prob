class TrieNode {
public:
    TrieNode *child[52];
    bool isEnd;
    TrieNode() {
        isEnd = false;
        for (auto &a: child) a = nullptr;
    }
};
class Solution {
public:
    TrieNode* root;
    Solution() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode *crawler = root;
        for (char it : word) {
            int index = islower(it) ? it - 'a' : it - 'A' + 26;
            if (!crawler->child[index]) {
                crawler->child[index] = new TrieNode();
            }
            crawler = crawler->child[index]; 
        }
        crawler->isEnd = true;
    }
    bool search(string word, string pattern) {
        TrieNode *crawler = root;
        int mat = 0;
        for (char ch : word) {
            int idx = islower(ch) ? ch - 'a' : ch - 'A' + 26;
            if (!crawler->child[idx]) {
                if (isupper(ch)) return false; 
                continue;  
            }
            crawler = crawler->child[idx];
            mat++;
        }
        return mat == pattern.size();
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        insert(pattern);
        int n = queries.size();
        vector<bool> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = search(queries[i], pattern);
        }
        return res;
    }
};
