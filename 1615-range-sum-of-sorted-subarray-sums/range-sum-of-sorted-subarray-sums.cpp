class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int i =0,j=0;
        int mod = 1e9+7;
        int sum = 0;
        vector<int> ans;
        while(i<nums.size()){
            j =i;
            int sum=0;
            while(j<nums.size()){
                sum+= nums[j];
            ans.push_back(sum);
                j++ ;
            }
            i++ ; 
        }
        sort(ans.begin(),ans.end());
        sum =0;

        for(int i=left-1; i<=right-1; i++){
          sum = (sum+ans[i])% mod;
        }
        return sum;
    }
};