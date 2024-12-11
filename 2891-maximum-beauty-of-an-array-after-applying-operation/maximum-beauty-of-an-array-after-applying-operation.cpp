class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int maxVal = -1;
        for(int n : nums)maxVal = max(maxVal,n);
        vector<int> freq(maxVal+1+k,0);
        int maxFreq = INT_MIN;
        for(auto i: nums){
            freq[max(i-k,0)]++ ;
            if(i+k+1 <= maxVal)freq[i+k+1]-- ;
        }

        int currSum =0;
        maxVal=-1;
        for(int val : freq){
            currSum+=val;
            maxVal = max(maxVal,currSum);
        }

        return maxVal;
    }
};
