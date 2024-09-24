// A 1

class Solution {
public:
    int longestCommonPrefix(vector<int>& nums1, vector<int>& nums2) {
        Trie trie;
        int mx = 0;
        for(auto num : nums1) trie.insert(num);
        for(auto num : nums2) mx = max(mx, trie.fun(num));
        return mx;
    }

private:
    struct TrieNode {
        TrieNode* children[10] = {};
        bool isEnd = false;
    };
    class Trie {        
    public:
        TrieNode* root = new TrieNode();
        void insert(int num) {
            TrieNode* node = root;
            string str = to_string(num);
            for(char ch : str) {
                int dgt = ch - '0';
                if(!node -> children[dgt])
                    node -> children[dgt] = new TrieNode();
                node = node -> children[dgt];
            }
            node -> isEnd = true;
        }

        int fun(int num) {
            TrieNode* node = root;
            string str = to_string(num);
            int n = 0;
            for(char ch : str) {
                int dgt = ch - '0';
                if(!node -> children[dgt]) break;
                node = node -> children[dgt];
                n++;
            }
            return n;
        }
    };
};
