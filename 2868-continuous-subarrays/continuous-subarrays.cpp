class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int i(0),j(0);
        int currMin,currMax;
        long long winLen=0,total=0;
        currMin=currMax=nums[i];

        while(j<nums.size()){
            currMin = min(currMin,nums[j]);
            currMax = max(currMax,nums[j]);
            
            if(currMax - currMin > 2){
                winLen = j-i;
                total += (winLen*(winLen+1)/2);
                i=j;
                currMin = currMax = nums[j];

                while(i>0 && abs(nums[j]-nums[i-1])<=2){
                    i-- ;
                    currMin = min(currMin, nums[i]);
                    currMax = max(currMax,nums[i]);
                }

                if(i<j){
                    winLen = j-i;
                    total -= (winLen*(winLen+1)/2);
                }
            }
            j++;
        }
        winLen = j-i;
        total += (winLen*(winLen+1)/2);
        return total;
    }
};