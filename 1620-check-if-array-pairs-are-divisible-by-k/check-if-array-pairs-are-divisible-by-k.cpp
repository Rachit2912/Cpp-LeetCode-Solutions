class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> map(k,0);

        for(int &n : arr){
            int rem = ((n%k)+k)%k;
            map[rem]++;
        }

        if(map[0] %2 !=0)return false;

        for(int rem =1; rem<=k/2; rem++){
            int cntrPart = k-rem;
            if(map[rem] != map[cntrPart])return false;
        }
        return true;
    }
};