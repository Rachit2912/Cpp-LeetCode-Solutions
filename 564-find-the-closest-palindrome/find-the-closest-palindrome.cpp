class Solution {
public:
    string nearestPalindromic(string n) {

        int len = n.size();
        int mid = (len%2)==0 ? (len/2)-1 : len/2 ;
        long firstHalf = stol(n.substr(0, mid + 1));

        vector<long> cases ;

        // 1 : n ==> n digits : mirror the half : 
        cases.push_back(halfFill(firstHalf,len%2==0)); 

        // 2 : middle digit increased
        cases.push_back(halfFill(firstHalf+1,len%2==0)); 

        //3 : middle digit decreased
        cases.push_back(halfFill(firstHalf-1,len%2==0)); 

        //4 : n => n-1 digit : greatest n-1 digit : 
        cases.push_back((long)pow(10, len - 1) - 1);


        // 5 : n => n+1 digit : smallest n+1 digit : 
        cases.push_back((long)pow(10, len) + 1);


        // min diff. of all 5 cases with our no is the ans.
        long diff = LONG_MAX, res =0, n1= stol(n);
        for(auto i : cases){
            if(i == n1) continue;
            if(abs(i-n1) < diff){
                diff = abs(i-n1);
                res = i;
            }
            else if(abs(i - n1) == diff){
                res = min(res,i);
            }
        }

        return to_string(res);
        
    }

    long halfFill(long left, bool even){
        long res = left ;
        if(!even) left = left/10;
        while(left>0){
            res = res*10 + left%10 ; 
            left /= 10 ;
        }
        return res;
    }
};