class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g = 0;
        for(auto &i: numsDivide){
            g = __gcd(g,i);
        }
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto &i: nums){
            pq.push(i);
        }
        int x = 0;
        while(!pq.empty() && g%pq.top()){
            x++;
            pq.pop();
        }
        if(pq.empty())return -1;
        return x;
    }
};