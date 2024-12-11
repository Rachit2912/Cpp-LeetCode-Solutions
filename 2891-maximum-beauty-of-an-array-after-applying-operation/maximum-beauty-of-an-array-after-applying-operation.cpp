class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        int maxBeauty(0);

        for(int i=0; i<n; i++){
            int upperBound = findUpperBound(nums,nums[i]+2*k);
            maxBeauty = max(maxBeauty,upperBound-i+1);
        }
        return maxBeauty;
    }

    private:
    int findUpperBound(vector<int> &nums, int val){
        int l(0),h(nums.size()-1),res(0);

        while(l<=h){
            int mid = l+(h-l)/2;

            if(nums[mid] <= val){res=mid;l=mid+1;}
            else{h=mid-1;}
        }
        return res;
    }
};