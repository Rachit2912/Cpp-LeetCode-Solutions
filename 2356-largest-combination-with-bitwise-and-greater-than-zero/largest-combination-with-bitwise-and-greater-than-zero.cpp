class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> setBits(24,0);
        for(int bitPos=0; bitPos<24; bitPos++){
            for(int &no : candidates){
                if((no & (1<<bitPos)) > 0){setBits[bitPos]++;}
            }
        }
        return *max_element(setBits.begin(),setBits.end());
    }
};