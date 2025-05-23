typedef long long ll ;
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll sum=0;
        int count=0;
        ll minLoss = LONG_MAX;

        for(ll num : nums){
            if((num^k) > num){
                count++ ;
                sum += (num^k);
            }else{
                sum += num;
            }
        minLoss = min(minLoss,abs(num-(num^k)));
        }

        if(count %2 == 0)return sum;

        return sum-minLoss;    
    }
};