// APPROACH 1 [ TLE ]


class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        int n = words.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i == j) continue;
                if (!check(words[i] + words[j])) continue;
                vector<int> temp = {i, j};
                ans.push_back(temp);
            }
        }
        return ans;
    }

private:
    bool check(string s) {
        int i = 0;
        int n = s.length();
        int j = n - 1;

        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};




// T.C. --> O(n^2 * k), where k is the length of the longest word in the input








// APPROACH 2


class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        Trie tree;
        for(int i = 0;i<words.size();i++){
            tree.insert(words[i],i);
        }
        for(int i = 0;i<words.size();i++){
            int m = words[i].length();
            for(int j = 0;j<=m;j++){
                if(isPalindrome(words[i],j,m-1)){
                    int right = tree.search(words[i].substr(0,j));
                    if(right!=-1&&right!=i){
                        res.push_back({i,right});
                    }
                }
                if(j!=0&&isPalindrome(words[i],0,j-1)){
                    int left = tree.search(words[i].substr(j,m));
                    if(left!=-1&&left!=i){
                        res.push_back({left,i});
                    }
                }
            }
        }
        return res;
    }
    
    bool isPalindrome(string word,int left,int right){
        while(left<right){
            if(word[left]!=word[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    
private:
    class Trie{
    public:
        Trie* children[26];
        int index;
        Trie(){
            for(int i=0; i<26; i++){
                children[i] = nullptr;
            }
            index = -1;
        }
        
        void insert(string word,int pos){
            Trie* node = this;
            for(int i = 0;i<word.length();i++){
                int j = word[i]-'a';
                if(node->children[j]==nullptr){
                    node->children[j] = new Trie();
                }
                node = node->children[j];
            }
            node->index = pos;
        }
        
        int search(string word){
            Trie* node = this;
            for(int i = word.length()-1;i>=0;i--){
                int j = word[i]-'a';
                if(node->children[j]==nullptr){
                    return -1;
                }
                node = node->children[j];
            }
            return node->index;
        }
    };
};








// APPROACH 3

class Solution {
public:
    struct Node {
        Node* children[26];
        vector<int> words;
        vector<int> suffixs;
        Node() {
            memset(children, 0, sizeof(children));
        }
    };

    Node* root;

    vector<vector<int>> palindromePairs(vector<string>& words) {
        root = new Node();
        int n = words.size();
        // 字典树的插入，注意维护每个节点上的两个列表
        for (int i = 0; i < n; i++) {
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            Node* cur = root;
            if (isPalindrome(rev.substr(0))) cur->suffixs.push_back(i);
            for (int j = 0; j < rev.length(); j++) {
                char ch = rev[j];
                if (!cur->children[ch-'a']) cur->children[ch-'a'] = new Node();
                cur = cur->children[ch-'a'];
                if (isPalindrome(rev.substr(j+1))) cur->suffixs.push_back(i);
            }
            cur->words.push_back(i);
        }
        // 用以存放答案的列表
        vector<vector<int>> ans;
        
        for (int i = 0; i < n; i++) {
            string word = words[i];
            Node* cur = root;
            int j = 0;
            for (; j < word.length(); j++) {
                // 到j位置，后续字符串若是回文对，则在该节点位置上所有单词都可以与words[i]构成回文对
                // 因为我们插入的时候是用每个单词的逆序插入的:)
                if (isPalindrome(word.substr(j))) {
                    for (int k : cur->words) {
                        if (k != i) ans.push_back({i,k});
                    }
                }
                
                char ch = word[j];
                if (!cur->children[ch-'a']) break;
                cur = cur->children[ch-'a'];
            }
            // words[i]遍历完了，现在找所有大于words[i]长度且符合要求的单词，suffixs列表就派上用场了:)
            if (j == word.length()) {
                for (int k : cur->suffixs) {
                    if (k != i) ans.push_back({i,k});
                }
            }
        }
        return ans;
    }
    //  判断一个字符串是否是回文字符串
    bool isPalindrome(string w) {
        int i = 0, j = w.length()-1;
        while (i < j) {
            if (w[i] != w[j]) return false;
            i++; j--;
        }
        return true;
    }
};






