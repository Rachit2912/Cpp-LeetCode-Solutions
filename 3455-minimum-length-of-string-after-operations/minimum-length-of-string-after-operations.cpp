class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26,0);
        int ans(0);
        for(auto ch : s)freq[ch-'a']++ ; 

        for(auto f : freq){
            if(f==0)continue;
            else if(f%2==0)ans+=2;
            else ans+=1;
        }
        return ans;
    }
};