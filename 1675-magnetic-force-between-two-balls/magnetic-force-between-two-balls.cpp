class Solution {
public:
    bool possibleMid(int mid, vector<int> &position, int m){
        int prev_ball = position[0];
        int count=  1;

        for(int i =1; i< position.size(); i++){
            int curr_ball = position[i];
            if(curr_ball - prev_ball >= mid){
                count++ ; 
                prev_ball = curr_ball ;
            }

            if(count == m) break;
        }
        return count== m;

    }




    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        int s = 1 , e = position[n-1] - position[0];
        int mid = s + (e-s)/2 ; int ans = -1 ; 
        while( s <= e) {
            if(possibleMid(mid,position,m)){
                ans = mid ;
                s = mid + 1 ;

            }
            else{
                e = mid - 1;

            }
            mid = s + (e-s)/2 ; 
        }
        return ans;
    }

};