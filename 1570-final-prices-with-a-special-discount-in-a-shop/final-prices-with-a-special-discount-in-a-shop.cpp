class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> backup(prices.size());
        vector<int> result = prices;
        stack<int> s;
        for(int i = prices.size()-1; i>=0 ; i--){
            while(!s.empty() && s.top()>prices[i]){
                int top = s.top();
                s.pop();
                backup.push_back(top);
                }

            if(!s.empty()){int disc = s.top();
            result[i] -=disc;}
            // else{}

            while(!backup.empty()){
                int elt = backup[backup.size()-1];
                backup.erase(backup.end()-1);
                s.push(elt);}
        s.push(prices[i]);
        }
        return result;
    }
};