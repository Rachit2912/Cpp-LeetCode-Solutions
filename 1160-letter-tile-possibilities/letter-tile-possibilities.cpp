class Solution {
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.length();
        vector<bool>seen(n+1,false);
        unordered_set<string>ans;
        string current = "";
        solve(tiles,seen,current,ans);
        return ans.size()-1;
    }
private:
    void solve(string tiles, vector<bool>& seen,string &current, unordered_set<string> &ans){
        ans.insert(current);

        for(int i=0; i<tiles.size(); i++){
            if(seen[i])continue;

            seen[i]=true;
            current.push_back(tiles[i]);

            solve(tiles,seen,current,ans);

            seen[i]=false;
            current.pop_back();
        }
    }
};
