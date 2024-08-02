class Solution {
public:
    int minSwaps(vector<int>& nums) {

        // option 1 : accumulating zeroes :
        int total = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            total += (1-nums[i]);
        }

        if (total == 0 || total == n) return 0;


        // sliding window : 
        int ans1 =INT_MAX;
        int s =0,e=0,c1=0;
        while(e < total){
            c1 += nums[e++];
        }
        ans1 = min(ans1,c1);

        while(e < n){
            if(nums[s++]) c1-- ; 
            if(nums[e++]) c1++ ;
            ans1 = min(ans1,c1);
        }



        // option 2 : accumulating ones :
        total = 0;
        for(int i=0; i<n; i++){
            total += nums[i];
        }

        if (total == 0 || total == n) return 0;


        // sliding window : 
        int ans2 =INT_MAX;
        s =0,e=0,c1=0;
        while(e < total){
            c1 += (1-nums[e++]);
        }
        ans2 = min(ans2,c1);

        while(e < n){
            if(1-nums[s++]) c1-- ; 
            if(1-nums[e++]) c1++ ; 
            ans2 = min(ans2,c1);
        }
        return min(ans1,ans2);



}
};