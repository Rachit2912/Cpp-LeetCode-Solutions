class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int,int> mp;
        sort(nums.begin(),nums.end());

        int maxStrk = 0;
        for(int &no : nums){
            int root = (int)sqrt(no);
            if(root*root == no && mp.find(root) != mp.end()){
                mp[no] = mp[root] + 1;
            }
            else{
                mp[no] =1 ;
            }
            maxStrk = max(maxStrk,mp[no]);
        }
        return maxStrk<2 ? -1 : maxStrk;
    }
};