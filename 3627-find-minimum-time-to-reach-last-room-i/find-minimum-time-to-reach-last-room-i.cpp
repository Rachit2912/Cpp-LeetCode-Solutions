class Solution {
public:
vector<vector<int>> dirns{{-1,0},{1,0},{0,1},{0,-1}};
typedef pair<int,pair<int,int>> P;
    int minTimeToReach(vector<vector<int>>& moveTime) {
    int m = moveTime.size(), n = moveTime[0].size();

    vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
    priority_queue<P,vector<P>,greater<P>> pq;

    dist[0][0] = 0;
    pq.push({0,{0,0}});
    
    while(!pq.empty()){
        int currTime = pq.top().first;
        auto cell = pq.top().second;
        int i=  cell.first, j =cell.second;
        pq.pop();

        if(i==m-1 && j==n-1)return currTime;

        for(auto &d : dirns){
            int i_ = i+d[0], j_ = j+d[1];

            if(i_ >=0 && i_ <m && j_ >=0 && j_ <n){
                int waiting = max(moveTime[i_][j_] - currTime,0);
                int arrTime = currTime + waiting + 1; 

                if(dist[i_][j_] > arrTime){
                    dist[i_][j_] = arrTime;
                    pq.push({arrTime,{i_,j_}});
                }
            }
        }
    }
    return -1;
    }
};