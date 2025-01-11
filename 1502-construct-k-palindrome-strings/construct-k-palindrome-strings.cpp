class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if(n<k)return false;
        if(k==n)return true;

        vector<int> freq(26,0);
        for(auto ch : s){
            freq[ch-'a']++ ; 
        }

        int oddFreqWaleChar(0);
        for(int i=0; i<26; i++){
            if(freq[i]%2==1)oddFreqWaleChar++;
        }

        if(oddFreqWaleChar>k)return false;
        return true;
    }
};