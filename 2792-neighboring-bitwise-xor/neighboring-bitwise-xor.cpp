class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
           int xOR = 0;
           for(auto elt : derived){
            xOR ^= elt;
           }
           return xOR==0;
    }
};