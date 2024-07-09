class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double net = 0;
        int current = customers[0][0];
        for(int i =0;i<customers.size();i++){
            int aya = customers[i][0];
            int bnane = customers[i][1];
            current = max(current,aya)+ bnane;
            net += (current-aya);
        }
        net /= customers.size();
        return net;
    }
};