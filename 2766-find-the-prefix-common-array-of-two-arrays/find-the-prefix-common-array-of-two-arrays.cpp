class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(),ans(0);
        vector<int> res(n);
        unordered_map<int,int> freq;
        for(int i=0; i<n; i++){
            freq[A[i]]++ ;
            if(freq[A[i]] > 1)ans++ ;

            freq[B[i]]++ ; 
            if(freq[B[i]] > 1)ans++ ; 

            res[i] = ans;
        }
        return res;
    }
};