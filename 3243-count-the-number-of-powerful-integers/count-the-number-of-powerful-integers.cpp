#define ll long long 
class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        auto countUpTo = [&](ll num) -> ll {
            string numStr = to_string(num);
            int suffixLen = s.size();
            int prefixLen = numStr.size()-suffixLen;

            if(prefixLen < 0)return 0;
            
            vector<vector<ll>> dp(prefixLen+1,vector<ll>(2,0));

            dp[prefixLen][0] = 1;
            string suffixFromNum = numStr.substr(prefixLen);
            dp[prefixLen][1] = stoll(suffixFromNum) >= stoll(s) ? 1 : 0;

            for(int i=prefixLen-1; i>=0; i--){
                int digit = numStr[i]-'0';

                dp[i][0] = (limit+1) * dp[i+1][0];

                if(digit <= limit){
                    dp[i][1] = digit*dp[i+1][0] + dp[i+1][1];
                }else{
                    dp[i][1] = (limit+1)*dp[i+1][0];
                }
            }

            return dp[0][1];
        };

        return countUpTo(finish)-countUpTo(start-1);
    }
};