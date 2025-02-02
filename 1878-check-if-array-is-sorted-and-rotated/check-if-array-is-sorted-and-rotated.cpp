class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int> chk(n);

        for(int r=0; r<n; r++){
            int idx=0;
            for(int i=r; i<n; i++){chk[idx++]=nums[i];}
            for(int i=0; i<r; i++){chk[idx++]=nums[i];}

            bool isSorted = true;
            for(int i=0; i<n-1; i++){
                if(chk[i]>chk[i+1]){isSorted=false;break;}
            }

            if(isSorted)return true;
        }
        return false;
    }
};