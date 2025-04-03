class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        for(int i=1; i<n; i++){
            left[i]=max(left[i-1],nums[i-1]);
            right[n-i-1]=max(right[n-i],nums[n-i]);
        }

        long long res=0;
        for(int j=1; j<n; j++){
            res = max(res,(long long)(left[j]-nums[j])*right[j]);
        }
        return res;
    }
};