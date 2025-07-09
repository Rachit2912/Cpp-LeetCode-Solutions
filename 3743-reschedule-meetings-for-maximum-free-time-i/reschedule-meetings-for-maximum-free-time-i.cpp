class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size(),ans=0,t=0;


        vector<int> freeArray; 
        freeArray.push_back(startTime[0]);
        for(int i = 1; i < startTime.size(); i++)freeArray.push_back(startTime[i] - endTime[i-1]);
        freeArray.push_back(eventTime - endTime[endTime.size()-1]);

        int i=0,j=0,currSum=0,maxSum=0;
        // *max_element(freeArray.begin(),end(freeArray));
        
        if(k+1 >= freeArray.size()){
            currSum = accumulate(freeArray.begin(),end(freeArray),0);
            return currSum;
        }

        for(; j<=k; ++j)currSum += freeArray[j];
        maxSum=currSum;
        while(j<freeArray.size()){
            currSum += freeArray[j];
            currSum -= freeArray[i];
            i++;
            j++;
            maxSum = max(maxSum,currSum);
        }
        return maxSum;
    }
};