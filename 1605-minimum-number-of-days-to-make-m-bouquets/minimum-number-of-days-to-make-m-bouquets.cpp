class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int s = 1;
        int e = 0;
        // if(mul > bloomDay.size()) return -1;
        for(int i =0; i<bloomDay.size(); i++){
            e = max(e,bloomDay[i]);
        }
        int ans = -1;

        int mid = s + (e-s)/2 ;
        while(s<=e){
            if(possibleBoque(mid, bloomDay, m, k)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1 ;
            }

            mid = s + (e-s)/2 ;
        }

        return ans;

    }

    bool possibleBoque(int mid, vector<int>& bloomDay, int m, int k){

        int bq = 0; int fl = 0 ;
        for(int i = 0; i<bloomDay.size();i++){
            if(bloomDay[i] <= mid){
                fl++ ;
                if(fl == k){
                    fl = 0;
                    bq++ ;}
            }

            else{
                fl = 0;
            }
        }
        if(bq >= m){return 1;}
        return 0;

    }
};