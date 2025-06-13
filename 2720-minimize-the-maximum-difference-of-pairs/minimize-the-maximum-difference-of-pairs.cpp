class Solution {
private:
    int bsearch(vector<int> &nums,int target){
        int i=0,cnt=0;
        while(i<nums.size()-1){
            if(nums[i+1]-nums[i] <= target){
                cnt++;
                i++;
            }
            i++;
        }
        return cnt;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),end(nums));
        int n = nums.size(),ans=0;
        int l=0, r=nums[n-1]-nums[0];
        while(l<=r){
            int mid = l+(r-l)/2;
            if(bsearch(nums,mid) >= p){
                r=mid-1;
                ans=mid;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};