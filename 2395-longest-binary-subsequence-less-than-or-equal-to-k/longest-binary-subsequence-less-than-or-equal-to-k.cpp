class Solution {
public:
    int longestSubsequence(string s, int k) {
        int zeroes=0,length=0;
        for(auto i : s)if(i=='0')zeroes++;

        for(int i=s.size()-1; i>-1; i--){
            if(s[i]=='0'){
                length++;
                zeroes--;
            }else{
                if(length<31 && (1<<length) <= k){
                    k -= (1<<length);
                    length++;
                }else break;
            }
        }
        return length+zeroes;
    }
};