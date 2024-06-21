class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
     int n = grumpy.size();
     int count = 0;
     for(int i = 0;i<n;i++){
        if(grumpy[i] == 0){
            count+= customers[i];
            customers[i] =0;
        }
     }   

     int max = 0, curr_window =0, max_window = 0;
     for(int i =0;i<minutes;i++){
        curr_window += customers[i];
        }// first window:

        // now start sliding it using 2 vars i &j : 
        int i = 0, j = minutes;
        max_window = curr_window;

        while(j < n){
            curr_window += customers[j];
            curr_window -= customers[i];

            if(max_window <= curr_window) max_window = curr_window;
            i++ ;
            j++ ;
        }
        
     return count+max_window ;
    }
};