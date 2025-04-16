#define ll long long 
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,j=0;
        long long pairs =0, ans=0;

        unordered_map<int,int>freq;
        while(j<n){
            pairs += freq[nums[j]];
            freq[nums[j]]++;
            
            while(pairs >= k){
                ans += (n-j);
                freq[nums[i]]--;
                pairs -= freq[nums[i]];
                i++;
            }
            
            j++;

        }

        return ans;
    }
};