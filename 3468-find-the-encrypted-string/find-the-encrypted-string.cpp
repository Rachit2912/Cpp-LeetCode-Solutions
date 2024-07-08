class Solution {
public:
    string getEncryptedString(string s, int k) {
        string ans=  "";
        for(int i =0;i<s.length();i++){
            char ch = s[i];
            ch = s[(i+k)%s.length()];
            ans.push_back(ch);
        }
        return ans;
    }
};