class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end());

        // we'll use minHeap to store the endpts. : 
        priority_queue<int,vector<int>,greater<int>> endPts;

        // current_start > end 

        for(auto i : intervals){
            if(!endPts.empty() && endPts.top() < i[0]){
            endPts.pop();
            }
            endPts.push(i[1]);
        }
        return endPts.size();
    }};
