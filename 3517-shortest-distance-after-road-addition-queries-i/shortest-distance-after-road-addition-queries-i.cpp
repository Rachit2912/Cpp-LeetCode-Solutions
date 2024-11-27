class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adjList(n,vector<int>(0));
        vector<int> ans={};

        for(int i =0; i<n-1; i++){
            adjList[i].push_back(i+1);
        }

        for(auto& q : queries){
            adjList[q[0]].push_back(q[1]);
            ans.push_back(bfs(n,adjList));
        }
        return ans;
    }

    int bfs(int n, vector<vector<int>> &adjList){
        vector<bool> visited(n,false);
        queue<int> q;

        q.push(0);
        visited[0]=true;

        int currNodes = 1, nextNodes = 0, layers=0;

        while(!q.empty()){
            for(int i =0; i<currNodes; i++){
                int currNode = q.front();q.pop();

                if(currNode == n-1)return layers;

                for(auto& n : adjList[currNode]){
                    if(visited[n])continue;

                    q.push(n);
                    visited[n] = true;
                    nextNodes++ ; 
                }
            }

            currNodes = nextNodes;
            nextNodes = 0;
            layers++;
        }
        return -1;
    }
};