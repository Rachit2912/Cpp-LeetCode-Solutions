class TrieNode{
    public :
    TrieNode* child[26];
    int cnt;

    TrieNode(){
        for(int i =0; i<26; i++){
            child[i] = NULL;
        }
        this->cnt = 0;
    }
};


class Solution {
public:
TrieNode* root = new TrieNode();

void insert(string word){
    TrieNode *node = root;

    for(char c : word){
        if(!node->child[c-'a']){
            node->child[c-'a'] = new TrieNode();
        }
        node->child[c-'a']->cnt++ ;
        node = node->child[c-'a'];
    }
}

int count(string s){
    TrieNode* node = root;
    int ans(0);
    for(char c : s){
        ans += node->child[c-'a']->cnt;
        node = node->child[c-'a'];
    }
    return ans;
}

    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        for(int i =0; i<n; i++){
            insert(words[i]);
        }

        vector<int> scores(n,0);
        for(int i=0; i<n; i++){
            scores[i] = count(words[i]);
        }
        return scores;
    }
};