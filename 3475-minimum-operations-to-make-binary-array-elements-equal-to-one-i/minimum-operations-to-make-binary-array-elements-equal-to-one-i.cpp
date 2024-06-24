class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int k =3;
        int count = 0;
        int flipcount = 0;
        vector<bool> isFlipped(n,false); // for remembering if we have flipped at i'th index or not 

        for(int i =0;i<n;i++){
            // i > k means we are out of first window and we have flipped at i-k'th index which will not create 
            // impact on curr-index that's why decreasing flipcount
            if(i>=k && isFlipped[i-k]){
                flipcount-- ;
            }

            // if flipcount is even, no change
            if(flipcount%2 == nums[i]){
                if(i+k > n) return -1; // not possible 
                // updating all counts 
                flipcount++ ;
                count++ ;
                isFlipped[i] = true;
            }
        }
        return count;
    }
};