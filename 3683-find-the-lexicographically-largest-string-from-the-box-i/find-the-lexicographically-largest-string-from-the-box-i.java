class Solution {
    public String answerString(String word, int numFriends) {
        if(numFriends==1)return word;

        int n = word.length();
        String ans = "";

        int maxPossibleLen = n-(numFriends-1);
        for(int i=0; i<n; i++){
            int canTakeLen = Math.min(i+maxPossibleLen,n);
            String temp = word.substring(i,canTakeLen);

            if(ans.compareTo(temp) <= 0)ans=temp;
        }
        return ans;
    }
}