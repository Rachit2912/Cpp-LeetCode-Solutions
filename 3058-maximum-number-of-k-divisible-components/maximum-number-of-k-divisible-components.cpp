class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if(n<2)return 1;

        vector<vector<int>> adjList(n);

        for(auto e : edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        int components=0;
        int start=edges[0][0];
        int parent = -1;
        dfs(start,parent,adjList,k,values,components);
        return components;
    }
    private :
    int dfs(int current, int parent, vector<vector<int>> &adjList, int k, vector<int> &values, int& components){
        int sum =0;

        for(auto n : adjList[current]){
            if(n!=parent){
                sum += dfs(n,current,adjList,k,values,components);
                sum %= k ;
            }
        }

        sum += values[current];
        sum %= k;
        if(sum==0)components++;
        return sum;
    }
};