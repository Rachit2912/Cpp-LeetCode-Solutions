class Solution {
private:
    int maxLexSubstrIdx(string &word){

        int i=0,j=1,n=word.length();

        while(j<n){
            int k=0;

            while(j+k<n && word[i+k]==word[j+k])k++;

            if(j+k<n && word[j+k]>word[i+k]){
                i=j;
                j++;
            }else{
                j=j+k+1;
            }

        }

        return i;

    }
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1)return word;

        int n = word.length();

        int i = maxLexSubstrIdx(word);

        int maxPossibleLen = n-(numFriends-1);
        int canTakeLen = min(maxPossibleLen,n-i);

        return word.substr(i,canTakeLen);

    }
};