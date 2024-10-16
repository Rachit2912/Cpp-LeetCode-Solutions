class Solution {
public:
typedef pair<int,char> p; 
    string longestDiverseString(int a, int b, int c) {
        priority_queue<p,vector<p>> pq ;
        if(a)pq.push({a,'a'});
        if(b)pq.push({b,'b'});
        if(c)pq.push({c,'c'});

        string ans = "";
        while(!pq.empty()){
            int currFreq = pq.top().first;
            int currChar = pq.top().second;
            pq.pop();

            // agr alrdy 2 ho gye h to 3rd char me next push krnge
            if(ans.length()>=2 && ans[ans.length()-1]==currChar && ans[ans.length()-2]==currChar){

                // agr next char hoga to : 
                if(pq.empty())break;

                // move to next char : 
                int nextFreq = pq.top().first;
                int nextChar = pq.top().second;
                pq.pop();

                ans.push_back(nextChar);
                nextFreq-- ; 
                if(nextFreq){
                    pq.push({nextFreq,nextChar});
                }
            }

            // nhi to abhi wala hi chlne do 
            else{
                ans.push_back(currChar);
                currFreq-- ; 
                }
                if(currFreq){
                    pq.push({currFreq,currChar});
            }
        }
        return ans;

    }
};