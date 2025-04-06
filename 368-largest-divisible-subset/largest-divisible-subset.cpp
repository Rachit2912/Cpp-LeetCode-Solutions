class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> len(n,1); // for lengths of largest divisible subset
        vector<int> prev_idx(n,-1);  // to backtrack the largest divisible subset elements

        int maxLen = 1, maxLenIdx =0; // for remembering the largest length & from the idx it's starting 
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){

                if(nums[i]%nums[j]==0){

                    if(len[i]<len[j]+1){
                        len[i]=len[j]+1;
                        prev_idx[i]=j;
                    }

                    if(len[i]>maxLen){
                        maxLen=len[i];
                        maxLenIdx=i;
                    }
                }
            }
        }

        // now backtracking the prev_idx & building the ans : 
        vector<int> ans;
        while(maxLenIdx != -1){
            ans.push_back(nums[maxLenIdx]);
            maxLenIdx = prev_idx[maxLenIdx];
        }
        return ans;

    }
};