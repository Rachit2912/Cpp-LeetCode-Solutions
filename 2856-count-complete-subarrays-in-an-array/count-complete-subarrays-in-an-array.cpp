class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>no(nums.begin(),nums.end());
        int distinct = no.size();
        unordered_map<int,int>freq;
        int ans=0;

        int i=0,j=0,n=nums.size();
        while(j<n){
            freq[nums[j]]++;
            while(freq.size()==distinct){
                ans += (n-j);
                freq[nums[i]]--;if(freq[nums[i]]==0)freq.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};