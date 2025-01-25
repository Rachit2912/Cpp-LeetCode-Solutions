class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        int n = nums.size();
        //sort krdo :
        vector<int> numsSorted(nums);
        sort(begin(numsSorted),end(numsSorted));

        // konsa elt. konse grp me h :
        int currGrp = 0;
        unordered_map<int,int> noGrp;
        noGrp[numsSorted[0]] = currGrp;

        // ek grp me kon konse elt. h:
        unordered_map<int,list<int>> grpList;
        grpList[currGrp].push_back(numsSorted[0]);

        for(int i=1; i<n; i++){
            if(abs(numsSorted[i]-numsSorted[i-1]) > limit){
                ++currGrp ;
            }
            noGrp[numsSorted[i]] = currGrp;
            grpList[currGrp].push_back(numsSorted[i]);
        }


        //merge the grps :
        for(int i=0; i<n; i++){
            int no = nums[i];
            int grpNo = noGrp[no];
            nums[i] = *grpList[grpNo].begin();
            grpList[grpNo].pop_front();
        }
        return nums;
    }
};