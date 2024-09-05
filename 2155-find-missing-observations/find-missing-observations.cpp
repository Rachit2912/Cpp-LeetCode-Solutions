class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum_m=0;
        for(auto i : rolls)sum_m +=i;
        int sum_n = (mean*(n+rolls.size())) - sum_m;
        
        
        if(sum_n <n || (6*n)< sum_n)return {};

        
        int equals = sum_n / n;
        int mod = sum_n % n;
        vector<int> ans(n,equals);
        int i(0);
        while(mod--){
            ans[i++]++;
        }
        return ans;





    }
};