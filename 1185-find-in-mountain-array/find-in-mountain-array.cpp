class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        
        // Find peak
        int s = 0, e = n-1;
        while(s < e) {
            int m = s + (e-s)/2;
            if(mountainArr.get(m) < mountainArr.get(m+1))
                s = m + 1;
            else
                e = m;
        }
        int peakIdx = s;  // Assign peak index
        
        // Search increasing part
        s = 0, e = peakIdx;
        while(s <= e) {
            int m = s + (e-s)/2;
            int val = mountainArr.get(m);
            if(val == target)
                return m; 
            else if(val > target)
                e = m-1;
            else
                s = m+1;
        }
        

        s = peakIdx, e = n-1;
        while(s <= e) {
            int m = s + (e-s)/2;
            int val = mountainArr.get(m);
            if(val == target)
                return m; 
            else if(val > target) 
                s = m+1;
            else
                e = m-1;
        }
        
        return -1;
    }
};