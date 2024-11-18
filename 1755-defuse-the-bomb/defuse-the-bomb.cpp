class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> result(code.size(),0);
        if(k==0)return result;

        int i =1, j = k, sum = 0;
        if(k<0){i=code.size()-abs(k);j=code.size()-1;}
        for(int idx = i; idx <= j; idx++)sum+=code[idx];

        for(int idx=0; idx<code.size(); idx++){
            result[idx] = sum;
            sum -= code[(i++)%code.size()];
            sum += code[((j++)+1)%code.size()];
        }
        return result;
    }

};