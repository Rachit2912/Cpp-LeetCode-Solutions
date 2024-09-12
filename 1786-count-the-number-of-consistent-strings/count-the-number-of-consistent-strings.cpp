class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> allowChar(26,false);
        for(int i =0; i<allowed.size(); i++){
            allowChar[allowed[i]-'a'] = true;
        }
        int ans =0;
        for(string& w : words){
            bool allow = true;
            for(int i =0; i<w.size(); i++){
                if(!allowChar[w[i]-'a']){
                    allow = false;
                    break;
                }
            }
            if(allow)ans++ ; 
        }
        return ans;
    }
};