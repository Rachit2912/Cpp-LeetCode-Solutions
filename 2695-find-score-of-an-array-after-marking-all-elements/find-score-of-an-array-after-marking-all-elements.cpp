class Solution {
public:
    long long findScore(vector<int>& nums) {
        auto comp = [](pair<int, int> &p1, pair<int, int> &p2) {
    if (p1.first != p2.first) return p1.first > p2.first;
    return p1.second > p2.second;
};

      priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> minElts(comp);


        for(int i =0; i<nums.size(); i++){
            minElts.push({nums[i],i});
        }
        long long ans =0;
        vector<bool> marked(nums.size(),false);

        while(minElts.size()){
            pair<int,int> curr = minElts.top();
            minElts.pop();
            if(!marked[curr.second]){
                ans += curr.first;
                marked[curr.second]=true;

                if(curr.second-1 > -1)marked[curr.second-1]=true;
                if(curr.second+1 <nums.size()){marked[curr.second+1]=true;}

            }
        }
        return ans;
    }
};