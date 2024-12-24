class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l(0),ans(0);
        unordered_set<char> chars;

        for(int r=0; r<s.length(); r++){
            while(chars.find(s[r]) != chars.end()){chars.erase(s[l]);l++;}
            chars.insert(s[r]);
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};