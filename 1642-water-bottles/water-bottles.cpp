class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumedBottles = 0;
        while(numBottles >= numExchange){
            int k = numBottles/numExchange;
            int extra = numBottles%numExchange;
            numBottles = k + extra;
            consumedBottles += numExchange*k;
        }
        return consumedBottles+numBottles;
    }
};