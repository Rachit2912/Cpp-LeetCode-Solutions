class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        int n = nums.size();
        int count = 0;
        int flipcount = 0;
        vector<bool> isFlipped(n,false);

        for(int i =0;i<n;i++){
            if(i>=k && isFlipped[i-k]){
                flipcount-- ;
            }

            if(flipcount%2 == nums[i]){
                if(i+k > n) return -1;
                flipcount++ ;
                count++ ;
                isFlipped[i] = true;
            }
        }
        return count;
        
    }
};