class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int sum=0,ans=0;
        unordered_map<int,int> rem;
        rem[0] =1;

        for(int i=0; i<n; i++){
            sum += nums[i];
            int r = ((sum)%k+k)%k;
            if(rem.find(r) != rem.end())ans += rem[r];
            rem[r]++;
        }
        return ans;
    }
};