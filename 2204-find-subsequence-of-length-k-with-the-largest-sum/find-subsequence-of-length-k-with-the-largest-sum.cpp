class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(nums);
        nth_element(temp.begin(),temp.begin()+k-1,end(temp),greater<int>());

        int pivot = temp[k-1];
        int pivotCnt = count(temp.begin(),temp.begin()+k,pivot);

        vector<int>ans;
        for(int n : nums){
            if(n>pivot)ans.push_back(n);
            else if(pivot==n && pivotCnt>0){
                ans.push_back(pivot);
                pivotCnt--;
            }
        }

        return ans;
    }
};