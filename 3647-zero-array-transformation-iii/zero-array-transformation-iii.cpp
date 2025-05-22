class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int Q = queries.size();
        int n = nums.size();
        sort(queries.begin(),queries.end());

        priority_queue<int> farthestEnds;
        priority_queue<int,vector<int>,greater<int>>pastEnds;

        int j=0, usedQueries=0;

        for(int i=0; i<n; i++){
            while(j<Q && queries[j][0]==i){
                farthestEnds.push(queries[j][1]);
                j++;
            }

            nums[i] -= pastEnds.size();

            while(nums[i]>0 && !farthestEnds.empty() && farthestEnds.top() >= i){
                int r = farthestEnds.top(); farthestEnds.pop();
                pastEnds.push(r);
                usedQueries++;
                nums[i]--;
            }
 
            if(nums[i]>0)return -1;

            while(!pastEnds.empty() && pastEnds.top()<=i)pastEnds.pop();
        }
        return Q-usedQueries;
    }
};