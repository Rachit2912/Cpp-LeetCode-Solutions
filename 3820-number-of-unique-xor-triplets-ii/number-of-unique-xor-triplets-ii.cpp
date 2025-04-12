class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return 1;
        unordered_set<int> st;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                st.insert(nums[i]^nums[j]);
            }
        }

        unordered_set<int>st2;

        for(auto elt : st){
            for(int i=0;i<n; i++)st2.insert(elt^nums[i]);
        }
        return st2.size();
    }
};