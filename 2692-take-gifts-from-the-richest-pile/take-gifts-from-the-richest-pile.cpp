class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> giftsHeap(begin(gifts),end(gifts));
        while(k--){
            giftsHeap.push(sqrt(giftsHeap.top()));
            giftsHeap.pop();
        }
        long long ans=0;
        while(giftsHeap.size()){
            ans += giftsHeap.top();
            giftsHeap.pop();
        }
        return ans;
    }
};
 