class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int maxCandies = *max_element(candies.begin(),candies.end());
        int l=1, r=maxCandies,ans=0;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(canAllocate(candies,k,mid)){ans=mid;l=mid+1;}
            else r = mid-1;
        }
        return ans;
    }

private:
bool canAllocate(vector<int> c, long long k, int noOfCandies){
    long long childNo = 0;
    for(int i=0; i<c.size(); i++){
        childNo += c[i]/noOfCandies;
    }
    return childNo >= k;
}
};