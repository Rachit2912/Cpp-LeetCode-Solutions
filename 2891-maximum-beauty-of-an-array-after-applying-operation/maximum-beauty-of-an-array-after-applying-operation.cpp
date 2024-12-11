#define p pair<int,int>  
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<p> intervals={};
        sort(nums.begin(),nums.end());
        
        for(auto i : nums){
            intervals.push_back({i-k,i+k});
        }


        deque<int> deq;
        int ans = -1;
        for(auto i : intervals){
            while(!deq.empty() && deq.front() < i.first){
                deq.pop_front();
            }

            deq.push_back(i.second);

            ans = max(ans,(int)deq.size());
        }
        return ans;
    }
};