class Solution {
public:
    string answerString(string word, int numFriends) {
        
        int n = size(word);
        if(numFriends==1)return word;
        string ans;
        int maxPossibleLength = n-(numFriends-1);
        for(int i=0; i<n; i++){
            int canTakeLength = min(maxPossibleLength,n-i);
            ans = max(ans,word.substr(i,canTakeLength));
        }
        return ans;
    }
};