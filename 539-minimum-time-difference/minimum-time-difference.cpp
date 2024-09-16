class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes(timePoints.size());
        int i=0;
        for(auto time : timePoints){
            int h = stoi(time.substr(0,2));
            int m = stoi(time.substr(3));
            minutes[i++] = h*60+m;
        }
        sort(begin(minutes),end(minutes));

        int ans = INT_MAX;
        for(int i =0; i<minutes.size()-1; i++){
            ans = min(ans, minutes[i+1]-minutes[i]);
        }
        return min(ans,-abs(minutes[minutes.size()-1]-minutes[0])+(24*60));
        //  return min(ans, 24 * 60 - minutes[minutes.size() - 1] + minutes[0]);
    }
};