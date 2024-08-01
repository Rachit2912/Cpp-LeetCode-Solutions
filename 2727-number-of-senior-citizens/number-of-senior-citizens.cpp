class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans =0;
        for(int i =0; i<details.size(); i++){
            char a = details[i][11];
            char b = details[i][12];
            if(a > '6') ans++ ;
            else if(a == '6' && b!='0') ans++ ;
        }
        return ans;
    }
};