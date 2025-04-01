class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0, candidate=0;
        for(int n : nums){
            if(count==0)candidate=n;

            if(n==candidate)count++;
            else count--;
        }

        if(count!=0)return candidate;
        else return -1;
    }
};