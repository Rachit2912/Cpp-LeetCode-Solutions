class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
       int n = nums.size();

        vector<int> results(n-k+1, -1);

        int cons = 1; //cons of consecutive elements

        //preprocess the first window
        for(int i = 1; i < k; i++) {
            if(nums[i] == nums[i-1]+1) {
                cons++;
            } else {
                cons = 1;
            }
        }

        if(cons == k) {
            results[0] = nums[k-1];
        }

        int i = 1;
        int j = k;

        // sliding window : 
        while(j < nums.size()){
            if((nums[j] - nums[j-1]) == 1){cons++;}
            else{cons=1;}

            if(cons >= k){results[i] = nums[j];}

            i++,j++;
        }
        return results;
    }
};