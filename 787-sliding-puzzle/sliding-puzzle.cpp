class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> dirns = {{1, 3}, {0, 2, 4}, {1, 5},{0, 4}, {1, 3, 5}, {2, 4}};

        string start;
        for(auto i : board){
            for(auto j : i){
                start += to_string(j);
            }
        }
        string goal = "123450";
        unordered_set<string> visited;
        queue<string> q;
        q.push(start);
        visited.insert(start);


        int moves = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
            string curr = q.front();
            q.pop();
            if(curr == goal) return moves;

            int zeroPos = curr.find('0');
            for(int newPos : dirns[zeroPos]){
                string nextState = curr;
                swap(nextState[zeroPos],nextState[newPos]);
                if(visited.count(nextState))continue;

                visited.insert(nextState);
                q.push(nextState);
            }
        }
        moves++;}
        return -1;
    }
};