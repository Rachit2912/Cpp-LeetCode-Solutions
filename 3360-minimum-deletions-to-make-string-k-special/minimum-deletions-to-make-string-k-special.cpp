class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26,0);
        for(auto w : word)freq[w-'a']++;
        sort(begin(freq),freq.end());
        int ans = word.size();
        int deletionsB4i = 0;

        for(int i=0; i<26; i++){
            int currDeletions = deletionsB4i;
            
            for(int j=25; j>-1; j--){

                if(freq[j]-freq[i] <= k)break;

                currDeletions += (freq[j]-freq[i]-k);
            }

            ans = min(currDeletions,ans);
            deletionsB4i += freq[i];
        }

        return ans;
    }
};