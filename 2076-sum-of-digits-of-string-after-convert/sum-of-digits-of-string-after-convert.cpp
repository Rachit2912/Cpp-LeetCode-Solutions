class Solution {
public:
    int getLucky(string s, int k) {
        string num="";

        for(char i : s){
            num += to_string(i - 'a' + 1);
        }
        while(k--){
            int sum =0;
            for(char i : num){
                sum+=(i-'0');
            }
            num.clear();
            num = to_string(sum);
            
        }
        return stoi(num);
        
    }
};