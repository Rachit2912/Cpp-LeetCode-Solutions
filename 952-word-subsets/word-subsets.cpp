class Solution {
public:
bool isSubset(vector<int>& freq, vector<int> &freq2){
    for(int i=0; i<26; i++){
        if(freq[i] < freq2[i])return false;
    }
    return true;
}

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
          vector<string> res;
          vector<int> freq2(26);

          for(auto &w : words2){
            int temp[26] = {};
            for(char ch : w){
                temp[ch-'a']++;
                freq2[ch-'a'] = max(freq2[ch-'a'],temp[ch-'a']);
            }
          }

          for(auto &w : words1){
            vector<int> freq(26);

            for(char &ch : w){
                freq[ch-'a']++;
            }

            if(isSubset(freq,freq2)){res.push_back(w);}
          }
          return res;
    }
};