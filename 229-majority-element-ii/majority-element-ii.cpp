class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cand1=NULL,cnt2=0,cand2=NULL;
        int n = nums.size();

        for(int n : nums){
            if(n==cand1)cnt1++;
            else if(n==cand2)cnt2++;
            else if(cnt1==0){cand1=n;cnt1=1;}
            else if(cnt2==0){cand2=n;cnt2=1;}
            else {cnt1--;cnt2--;}
        }

        // validation part :
        vector<int> ans;
        int freq1=0,freq2=0;
        for(int n : nums){
            if(n==cand1)freq1++;
            else if(n==cand2)freq2++;
        }

        if(freq1 > floor(n/3))ans.push_back(cand1);
        if(freq2> floor(n/3))ans.push_back(cand2);

        return ans;
    }
};