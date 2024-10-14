class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>> pq;

        for(auto i : nums){
            pq.push(i);
        }

        long long scr = 0;

        while(k--){
            long long gr8 = pq.top();
            pq.pop();
            scr += gr8 ; 
            pq.push((gr8+3-1)/3);
        }
        return scr;
    }
};