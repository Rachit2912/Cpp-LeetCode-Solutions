class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = 0, maxLen = 0, streak = 0;
        // kbhi bh kisi 2 no. ka bitwise and un 2 no. se bada nahi aa skta means ki dono me se max. no. se bda nhi aa skta
        // so to find the max. bitwise and we have to find the max. value
        // and to find the largest length we'll find the largest length of subarray having only elements = max. value

        for(auto no : nums){
            if(no> maxVal){
                maxVal = no;
                maxLen = 0;
                streak = 0;
            }

            if(no == maxVal){
                maxLen++ ; 
            }
            else{
                maxLen = 0;
            }
            streak = max(streak,maxLen);

        }
        return streak;
    }
};