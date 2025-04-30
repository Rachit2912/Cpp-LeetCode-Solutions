class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(auto n : nums){
            int digits = ceil(log10(n+1));
            if(digits%2==0)count++;
        }
        return count;
    }
};