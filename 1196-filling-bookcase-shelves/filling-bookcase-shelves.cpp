class Solution {
public:
int solve(int i, vector<vector<int>> &books, int w, int h, int shelfWidth,vector<vector<int>> &memo){
    int keep= INT_MAX;
    int skip = INT_MAX;

    // base case : 
    if(i == books.size()) return h;

    // using memo : 
    if(memo[i][w] != 0) return memo[i][w];

    // keep on same shelf:
    if(books[i][0] <= w){
    keep = solve(i+1,books,w-books[i][0],max(h,books[i][1]),shelfWidth,memo);
    }

    // skip and put it on new shelf:
    skip = h + solve(i+1,books,shelfWidth-books[i][0],books[i][1],shelfWidth,memo);

    int result = min(skip,keep);
    memo[i][w] = result;
    return result;

}

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<vector<int>> memo(books.size(),vector<int>(shelfWidth+1,0));
        return solve(0,books,shelfWidth,0,shelfWidth,memo);
    }
};