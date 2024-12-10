class Solution {
public:
    int maximumLength(string s) {
        vector<vector<int>> freq(26,vector<int>(s.size()+1,0));
        char prevchar = s[0];
        int substrlen = 1;
        freq[s[0]-'a'][1]=1;
        int ans =-1;

        for(int charidx=1; charidx<s.size(); charidx++){
            char currchar = s[charidx];

            if(currchar == prevchar){
                substrlen++ ;
                int cnt=1;
                freq[currchar-'a'][substrlen]+=1;
            }
            else{
                prevchar = currchar;
                substrlen =1;
                freq[currchar-'a'][1] +=1 ;
            }
        }

        for(int charidx=0; charidx<26; charidx++){
            for(int len = s.size()-1; len>=1; len--){
                freq[charidx][len] += freq[charidx][len+1];
                if(freq[charidx][len] >= 3){
                    ans = max(ans,len);
                    break;
                }
            }
        }
        return ans;
    }
};