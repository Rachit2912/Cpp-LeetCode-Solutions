#define l long 
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<l,vector<l>,greater<l>> h;
        for(auto i : nums){
            h.push(i);
        }

        int ans=0;
        while(h.top() < k){
            l x = h.top();h.pop();
            l y = h.top();h.pop();
            h.push(x*2 + y);
            ans++ ; 
        }
        return ans;
    }
};