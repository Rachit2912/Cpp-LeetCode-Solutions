class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
           string s = s1 + " " + s2;
           unordered_map<string,int> freq;

           string word ="";
           for(auto &ch : s){
            if(ch == ' '){
                freq[word]++ ;
                word ="";
            }
            else{
                word += ch;
            }
           }

           if(word != ""){
            freq[word]++ ; 
            word ="";
           }

           vector<string> ans;
           for(auto &word : freq){
            if(word.second == 1){
                ans.push_back(word.first);
            }
           }
           return ans;
    }
};