typedef pair<int,int> p;
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        int targetArr = times[targetFriend][0];

        // 2 min heaps will be used : 
        priority_queue<p,vector<p>,greater<p>> occupied ; // {departTime,chairNo}
        priority_queue<int,vector<int>,greater<int>> free ; // min indexed just free chair 

        int currChair = 0;
        sort(begin(times),end(times));

        for(int i =0;i<n; i++){
            int arr = times[i][0];
            int dep = times[i][1];

            // koi bhi occupied chair h jisko free krna ho :
            while((!occupied.empty()) && (occupied.top().first<= arr)){
                free.push(occupied.top().second);
                occupied.pop();
            }

            // ab agr koi bhi free chair nhi h : 
            if(free.empty()){
                occupied.push({dep,currChair});
                if(arr == targetArr){
                    return currChair;
                }
                currChair++ ; 
            }
            else{
                // sbse min. wali free chair dedo bhaiya : 
                int minFreeChair = free.top();
                free.pop();
                 if(arr == targetArr){
                    return minFreeChair;
                }
                occupied.push({dep,minFreeChair});
            }
        }
        return -1;

    }
};