class Solution {
public: 
    typedef long long ll;
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(),end(nums));
        ll ans=0,count=0;
        int i=0,j=0,n=nums.size();

        while(j<n){
            if(nums[j]==maxi)count++;
            while(count >= k){
                ans += (n-j);
                if(nums[i]==maxi)count--;
                i++;
            }
            j++;
        }
        return ans;
    }
};