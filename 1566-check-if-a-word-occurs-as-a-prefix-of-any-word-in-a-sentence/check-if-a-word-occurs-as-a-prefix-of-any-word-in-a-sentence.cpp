class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream sen(sentence);
        string word;
        int wordPos = 1;

        while(sen >> word){
            if(word.length() >= searchWord.length() && word.compare(0,searchWord.length(),searchWord) ==0){
                return wordPos;
            }
            wordPos++;
        }   
        return -1;
    }
};