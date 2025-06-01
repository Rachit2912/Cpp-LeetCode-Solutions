class Solution {
public:
    int distributeCandies(int n, int limit) {
           int cnt=0;
       for(int i=0; i<=limit; i++){
            for(int j=0; j<=limit; j++){
                    if(n-i-j <= limit && n-i-j>=0)cnt++;
                }
            }
        return cnt;
    }
};