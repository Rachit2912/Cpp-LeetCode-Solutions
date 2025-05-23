#define ll long long
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<int> fayda;
        ll normalSum=0;
        for(int i=0; i<nums.size(); i++){
            normalSum += nums[i];
            fayda.push_back((nums[i]^k)-nums[i]);
        }

        sort(fayda.begin(),end(fayda),greater<>());
        int n = fayda.size();

        for(int i=0;i<n-1; i+=2){
            ll pairSum = fayda[i] + fayda[i+1];
            if(pairSum>0)normalSum += pairSum;
        }
        return normalSum;
    }
};