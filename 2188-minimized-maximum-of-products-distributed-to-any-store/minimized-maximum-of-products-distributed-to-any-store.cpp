class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        int s = 1, e = *max_element(quantities.begin(),quantities.end());
        int mid = s + (e-s)/2;
        while(s<e){
            mid = s + (e-s)/2;

            if(distribute(mid,quantities,n)){e = mid;}
            else{s = mid+1;}
            mid = s+(e-s)/2;
        }

        return s;
    }


    bool distribute(int mid, vector<int>& quantities,int n){
        int div = 0;
        for(auto i : quantities){
            div += (i+mid-1)/mid;
        
        }
        return div<=n;
    }
};