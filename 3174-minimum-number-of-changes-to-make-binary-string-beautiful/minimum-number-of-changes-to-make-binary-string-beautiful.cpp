class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        char prev = s[0];int streak(1), ans(0);

        for(int i =1; i<n; i++){
            char curr = s[i];
            if(curr == prev){
                streak++ ; 
            }else{
                if(streak%2 == 0){
                streak = 1;
                }
                else{ans++ ;
                prev = !curr;
                streak=0;
                continue;
                }
                
                }
            prev = curr;
            }
        

        return ans;
    }
};