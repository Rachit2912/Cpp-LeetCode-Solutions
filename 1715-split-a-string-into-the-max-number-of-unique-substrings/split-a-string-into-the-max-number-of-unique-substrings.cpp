class Solution {
public:
void solve(string &s, int idx, unordered_set<string> &subs, int currCnt, int &maxCnt){
    //pruning:
        if(currCnt + (s.length() - idx) <= maxCnt)return;
    
    // base case : 
    if(idx == s.length()){maxCnt = max(maxCnt, currCnt);return;}

    for(int end = idx; end<s.length(); end++){
        string sub = s.substr(idx,end-(idx-1));
        if(subs.find(sub) == subs.end()){
            subs.insert(sub);
            solve(s,end+1,subs,currCnt+1,maxCnt);
            subs.erase(sub);
        }
    }
}

    int maxUniqueSplit(string s) {
        unordered_set<string> subs;
        int maxCnt =0;
        solve(s,0,subs,0,maxCnt);
        return maxCnt;
    }
};