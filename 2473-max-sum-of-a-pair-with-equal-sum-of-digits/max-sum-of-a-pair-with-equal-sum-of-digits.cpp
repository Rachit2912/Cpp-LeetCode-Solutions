class Solution {

private:
    int countDigits(int n){
        int d = 0,r = 0;
        while(n!=0){
            r = n%10;
            d+=r;
            // if(d>9){d=countDigits(d);}
            n=n/10;
        }
        return d;
    }
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,priority_queue<int,vector<int>>> mp;
        for(int i=0; i<nums.size(); i++){
            int digits = countDigits(nums[i]);
            mp[digits].push(nums[i]);
        }

        int ans =-1;
        for(auto& m : mp){
            if(m.second.size() > 1){
                int a = m.second.top();m.second.pop();
                int b = m.second.top();
                ans = max(ans,(a+b));
            }
        }
        return ans;
    }
};