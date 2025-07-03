class Solution {
public:
    char kthCharacter(int k) {
        string curr = "a";
        while(curr.length() < k){
            int n = curr.length();
            for(int i=0; i<n; ++i){
                char ch = curr[i] == 'z' ? 'a' : curr[i]+1;
                curr.push_back(ch);
            }
        }
        return curr[k-1];
    }
};