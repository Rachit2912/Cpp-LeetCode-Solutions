class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int i=0, n=s.length();
        while(i<n){
            ans.push_back(s.substr(i,k));
            i+=k;
        }
        ans.back() += string(k-ans.back().size(),fill);
        return ans;
    }
};