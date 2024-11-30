class Solution {
public:
void dfs(int startNode,unordered_map<int,vector<int>> &adjMat, vector<int> &result){
    while(!adjMat[startNode].empty()){
        int nextNode = adjMat[startNode].front();
        // myvector.erase (myvector.begin());
        adjMat[startNode].erase(adjMat[startNode].begin());
        dfs(nextNode,adjMat,result);
    }
    result.push_back(startNode);
}

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adjMat; 
        unordered_map<int,int> in,out;
        for(auto& pair : pairs){
            adjMat[pair[0]].push_back(pair[1]);
            out[pair[0]]++;in[pair[1]]++;
        }

        vector<int> result;
        int startNode = -1;
        for(auto& n : out){
            if(out[n.first] == in[n.first]+1){startNode = n.first;break;}
        }
        startNode = (startNode == -1) ? pairs[0][0] : startNode;

        dfs(startNode,adjMat,result);
        reverse(begin(result),end(result));

        vector<vector<int>> ans;
        for(int i=1; i<result.size(); i++){
            ans.push_back({result[i-1],result[i]});
        }
        return ans;
    }
};