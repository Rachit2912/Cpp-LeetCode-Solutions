class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size(); int tuples = 0;
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                mp[nums[i]*nums[j]]++;
            }
        }

        for(auto& [prod,freq] : mp){
            if(freq!=1){
                // nC2 * (2)(pair swap) * (2)(first pair perms.) * (2)(sec. pair perms.) 
                tuples += ((freq*(freq-1))/2) * 2 * 2 * 2;
            }
        }
        return tuples;
    }
};