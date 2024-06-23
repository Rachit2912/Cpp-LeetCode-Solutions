class Solution {
public:
typedef pair<int,int> p;
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        priority_queue<p,vector<p>> maxh;
        priority_queue<p,vector<p>,greater<p>> minh;

        int i = 0, j = 0;
        int maxLength = 0 ;
        while(j<n){
            maxh.push({nums[j],j});
            minh.push({nums[j],j});

            while(maxh.top().first - minh.top().first > limit){
                i = min(maxh.top().second,minh.top().second)+1;

                while(maxh.top().second < i){
                    maxh.pop();
                }
                while(minh.top().second < i){
                    minh.pop();
                }
            }
            maxLength = max(maxLength, j-i+1);
            j++ ;
        }
        return maxLength;

    }
};