class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // pehle to 1 to n tk ke 2 sbse shortest path nikalo using modified dijkstra
        // uske baad 1-1 path ka time nikalo 

        // step 1 : create adj list :
        unordered_map<int,list<int>> adj;
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // step 2 : modified dijkstra : 
        // har node ko 2 baar tk visit krenge taki hme shortest & second shortest distance miljaye
        vector<int> dist1(n+1,INT_MAX); vector<int> dist2(n+1,INT_MAX);
        vector<int> freq(n+1,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist1[1] = 0;
        pq.push({0,1});

        while(!pq.empty()){
            int topNode = pq.top().second;
            int topNodeDistance = pq.top().first;
            freq[topNode]++ ; // freq. increase hote jayegi
            pq.pop();

            // ab agr ya to ye node pheli baar visit hua h ya dusri baar : 
            // agr first time hua to no prblm, pr agr 2nd time hua h to :
            // agr 2 baar n wala vertex visit ho gya mtlb we've got the ans.
            if(freq[topNode] == 2 && topNode == n) return topNodeDistance;

            // signal changing time updation :
            if((topNodeDistance / change) % 2){ // red light, we need to wait for the next green
                topNodeDistance = change * (topNodeDistance/change + 1) + time;
            }

            else{
                topNodeDistance += time;
            }
            

            for(auto n : adj[topNode]){
                if(freq[n] == 2) continue; // already 2 baar visit ho chuka h means we have
                // top 2 minimum distances 

                // baaki sb else wale case h : 
                // ab agr min distance se bhi kuch chhoti distance aagyi to we have to update
                // min and second min distances 
                if(dist1[n] > topNodeDistance){
                    dist2[n] = dist1[n];
                    dist1[n] = topNodeDistance;
                    pq.push({topNodeDistance,n});
                }

                else if(dist2[n] > topNodeDistance && dist1[n] != topNodeDistance){
                    dist2[n] = topNodeDistance;
                    pq.push({topNodeDistance,n});
                }
            }
        }
        return 0;

    }
};