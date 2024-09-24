class TrieNode{
    public:
    TrieNode* children[10];
    TrieNode(){
    for(int i =0; i<10; i++){
        children[i] = nullptr;
    }
    }
};

class Trie{
    public : 
    TrieNode* root;
    Trie(){root = new TrieNode();}

    void insert(int num){
        TrieNode* node = root;
        string no = to_string(num);

        for(char d : no){
            int digit = d - '0';
            if(!node->children[digit]){
                node->children[digit] = new TrieNode();
            }
            node = node->children[digit];
        }
    }

    int findLongestPrefix(int num){
        TrieNode* node = root;
        string no = to_string(num);
        int pre =0;

        for(auto d : no){
            int digit = d - '0';

            if(node->children[digit]){
                pre++ ; 
                node = node->children[digit];
            }
            else{
                break;
            }
        }
        return pre;
    }
};


class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie t;
        int ans = INT_MIN;
        for(auto no:arr1){
            t.insert(no);
        }

        for(auto no: arr2){
            int len = t.findLongestPrefix(no);
            ans= max(len,ans);
        }
        return ans;
    }
};