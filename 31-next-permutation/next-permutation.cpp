class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        int inc_1_digit = -1;

        for(int i=n-1; i>0; i--){
            if(nums[i]>nums[i-1]){
                inc_1_digit=i-1;
                break;
            }
        }

        if(inc_1_digit!=-1){
            int swap_idx = inc_1_digit;

            for(int j=n-1; j>=inc_1_digit; j--){
                if(nums[j]>nums[inc_1_digit]){
                    swap_idx = j;
                    break;
                }
            }

            swap(nums[swap_idx],nums[inc_1_digit]);
        }

        reverse(nums.begin()+inc_1_digit+1,nums.end());



        
    }
};