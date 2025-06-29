class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int m = 1e9+7, n = nums.size();
        sort(begin(nums),nums.end());
        int ans=0,l=0,r=n-1;
        while(l<=r){
            if(nums[l]+nums[r] <= target){
                ans = (ans % m + (mod_pow(2, r - l,m) % m)) % m;
                l++;
            }else r--;
        }
        return ans;
    }

private:
    long long mod_pow(long long base, long long exp, long long m){
        long long res=1;
        base %= m;
        while(exp){
            if(exp%2)res = (res*base)%m;
            base = (base*base)%m;
            exp /= 2;
        }
        return res;
    }
};