class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> freq;
        for(auto i : answers)freq[i]++;
        int total=0;

        for(auto &f : freq){
            int groupMembers = f.first+1;
            int totalGroups = ceil((double)f.second/groupMembers) ; 
            total += (totalGroups * groupMembers);
        }
        return total;
    }
};