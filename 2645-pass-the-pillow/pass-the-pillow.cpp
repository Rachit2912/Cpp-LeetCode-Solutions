class Solution {
public:
    int passThePillow(int n, int time) {
        int index = 1;
        bool flag = false;
        while(time){
            if(!flag) index++ ;
            else if(flag) index-- ;
            if(index==n) flag = true;
            else if(index == 1) flag = false;
            time-- ;
        }
        return index;
    }
};