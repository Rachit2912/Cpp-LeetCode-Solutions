class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> freq;
        int ans=0;
        for(auto &w : words){
            string rev = w;
            swap(rev[0],rev[1]);
            
            if(freq[rev] > 0){
                ans += 4;
                freq[rev]--;
            }else{
                freq[w]++;
            }
        }

        for(auto &it : freq){
            string w = it.first; int cnt = it.second;

            if(w[0]==w[1] && cnt>0){
                ans += 2;
                break;
            }
        }
        return ans;
    }
};