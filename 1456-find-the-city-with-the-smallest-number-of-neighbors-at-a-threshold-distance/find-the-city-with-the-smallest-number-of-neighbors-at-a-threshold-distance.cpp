class Solution {
public:
vector<int> dijkstra(vector<vector<int>> &edges, int n, int edges_size,int source) {
    // create adj list : 
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i =0; i<edges_size; i++){
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
    }

    // final shortest distance record for all nodes from the source: 
    vector<int> distance(n,INT_MAX);
    distance[source] = 0;

    // ab 1-1 node ko uthate rho source se or uske neighbours ki shortest distance ko update krte rho :
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    // starting with the source : 
    pq.push({0,source});

    while(!pq.empty()){
        int topNode = pq.top().second;
        int topNode_distance = pq.top().first;
        pq.pop();

        for(auto n : adj[topNode]){
            int n_node = n.first;
            int n_weight = n.second;

            // update the neighbours distance : 
            if(topNode_distance + n_weight < distance[n_node]){
                distance[n_node] = distance[topNode]+n_weight;
                pq.push({distance[n_node],n_node});
            }
        }
    }
    return distance;
}

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // ek ek shehar ko pdko or uske liye dijsktra lgakr sbhi shortest distances nikal lo :
        // and store it in the map :
            vector<int> no_cities(n,0);
        for(int i =0; i<n; i++){
            vector<int> shortest_distances = dijkstra(edges,n,edges.size(),i);
            int count = 0;
            for(int j =0 ;j<n; j++){
                if(j==i) continue;
                if(shortest_distances[j] <= distanceThreshold) count++ ;
            }
            no_cities[i] = count;
        }

        // ab hmares paas kis city ke liye kitni no of cities threshold distance pr h vo pta lg gya
        // ab return the city with the min no cities
        int mini = INT_MAX;
        for(int i =0; i<n; i++){
            mini = min(mini,no_cities[i]);
        }

        // agr koi mini firse aagyi i.e multiple cities with distance_threshol = mini
        // then update krdo mini with greates city no
        int index = -1;
        for(int i =0; i<n; i++){
            if(mini==no_cities[i]) index = i;
        }
        return index;
    }
};