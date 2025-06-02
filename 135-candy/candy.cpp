class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), candy=n;

        int i=1;
        while(i<n){
            if(ratings[i] == ratings[i-1]){i++;continue;}

            int peak=0;
            while(i<n && ratings[i] > ratings[i-1]){
                peak++;
                candy += peak;
                i++;
            }

            if(i==n)return candy;

            int dip=0;
            while(i<n && ratings[i]<ratings[i-1]){
                dip++;
                candy += dip;
                i++;
            }

            candy -= min(dip,peak);
        }

        return candy;
    }
};