class Solution {
public:
    string countAndSay(int n) {
        return solve(n);
    }

private:
    string solve(int n){
        //base case : 
        if(n==1)return "1";

        string prev = solve(n-1);
        int i=0,j=0,prevSize=prev.size();
        if(prevSize==1)return ("1"+prev);
        string curr ="";

        while(i<prevSize){
            j=i;
            while(j<prevSize && prev[j]==prev[i])j++;
            curr+=to_string(j-1-i+1)+prev[i];
            i=j;
        }

        return curr;
    }
};