struct trieNode{
    trieNode* children[26];
    bool isEnd;
};

trieNode* getNode(){
    trieNode* newNode = new trieNode();
    newNode->isEnd = false;
    for(int i=0; i<26; i++)newNode->children[i]=NULL;
    return newNode;
}


class Trie{
    public :
    trieNode* root;

    Trie(){
        root = getNode();
    }

    void insert(string word){
        trieNode* crawl = root;
        for(int i=0; i<word.size(); i++){
            int idx = word[i]-'a';
            if(crawl->children[idx]==NULL){
                crawl->children[idx]= getNode();
            }
            crawl = crawl->children[idx];
        }
        crawl->isEnd = true;
    }

    bool search(string word){
        trieNode* crawl = root;
        for(int i=0; i<word.size(); i++){
            int idx = word[i]-'a';
            if(crawl->children[idx] == NULL)return false;
            crawl = crawl->children[idx];
        }
        return true;
    }
};


class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans =0;

        for(int i=0; i<n; i++){
            Trie pre,suf;
            pre.insert(words[i]);

            string rev = words[i];
            reverse(rev.begin(),rev.end());
            suf.insert(rev);

            for(int j=i-1; j>=0; j--){
                if(words[j].length() > words[i].length())continue;

                string prefix = words[j];
                string suffix = prefix;
                reverse(begin(suffix),end(suffix));

                if(pre.search(prefix) && suf.search(suffix))ans++;
            }
        }
        return ans;
    }
};