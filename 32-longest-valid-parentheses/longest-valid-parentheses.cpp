class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), ans=0;
        for(int i=0; i<n; i++){
                int score = (s[i]=='(') ? 1 : -1;
                if(score<0)continue;
            for(int j=i+1; j<n; j++){
                score += ((s[j]=='(') ? 1 : -1);
                if(score==0)ans = max(ans,j-i+1);
                if(score<0)break;
            }
        }
        return ans;
    }
};