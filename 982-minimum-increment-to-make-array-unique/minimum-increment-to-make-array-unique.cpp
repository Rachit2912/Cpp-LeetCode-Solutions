auto speedUp = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int count=0;
        // for(int i=1;i<nums.size();i++)
        // {
        //     if(nums[i]<=nums[i-1])
        //     {
        //         count+=nums[i-1]-nums[i]+1;
        //         nums[i]=nums[i-1]+1;
        //     }

        // }
        // return count;
        int maxi=0;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            maxi=max(maxi,nums[i]);
        }
        vector<int>freq(maxi+1,0);
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
        for(int i=0;i<=maxi;i++)
        {
            if(freq[i]<=1) continue;
            int val=freq[i]-1;
            freq[i]=1;
            
            if(i!=maxi)
            {
                freq[i+1]+=val;
                count+=val;
            }
            else
            {
                count+=((val)*(val+1))/2;
            }
        }
        return count;
    }
};