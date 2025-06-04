class Solution {
    public String answerString(String word, int numFriends) {
        if(numFriends==1)return word;

        int n = word.length();
        int i = maxLexSubstrIdx(word);

        int maxLenPossible = n-(numFriends-1);
        return word.substring(i,Math.min(i+maxLenPossible,n));
    }

    private int maxLexSubstrIdx(String word){

        int i=0,j=1,n=word.length();

        while(j<n){
            int k=0;

            while(j+k<n && word.charAt(i+k)==word.charAt(j+k))k++;

            if(j+k<n && word.charAt(j+k) > word.charAt(i+k)){
                i=j;
                j++;
            }else{
                j=j+k+1;
            }
        }

        return i;
    }
}