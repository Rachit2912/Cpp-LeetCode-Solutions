class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        int i=0,j=0;
        long long ans=0;
        long long diff;
        while(j<n){
            mp[nums[j]]++;

            diff = abs(mp.begin()->first - mp.rbegin()->first);

            // condtn. broken:
            while(diff>2){
                // shrink window:
                mp[nums[i]]--;
                if(!mp[nums[i]])mp.erase(nums[i]);
                i++;
                diff = abs(mp.begin()->first - mp.rbegin()->first);
            }
            ans += (j-i+1);
            j++;

        }
        return ans;
    }
};