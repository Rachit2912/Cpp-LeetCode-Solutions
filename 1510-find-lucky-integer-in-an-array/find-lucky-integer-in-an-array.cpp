class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = size(arr);
        for(auto no : arr){
            int val = no&((1<<16)-1);

            if(val<=n)arr[val-1] += (1<<16);
        }

        int ans=-1;
        for(int val=1; val<=n; val++){
            if((arr[val-1]>>16) == val)ans=max(ans,val);
        }
        return ans;
    }
};