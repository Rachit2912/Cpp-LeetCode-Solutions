class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26,0);
        for(auto w : word)freq[w-'a']++;
        int ans = word.size();

        for(int i=0; i<26; i++){
            int deletions = 0;
            
            for(int j=0; j<26; j++){
                
                if(i==j) continue;

                if(freq[j] < freq[i])deletions += freq[j];
                else if(abs(freq[j] - freq[i]) > k)deletions += (abs(freq[j]-freq[i])-k);
            }

            ans = min(deletions,ans);
        }

        return ans;
    }
};