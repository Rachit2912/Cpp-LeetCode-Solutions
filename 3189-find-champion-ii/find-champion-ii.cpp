class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_set<int> ans,result;
        for (auto edge : edges) {
            ans.insert(edge[1]);
        }

        for(int i =0; i<n; i++){
            if(ans.find(i) != ans.end())continue;
            else{
                result.insert(i);
            }
        }
        return result.size()==1 ?  *next(result.begin(),0) : -1;

        
    }
};