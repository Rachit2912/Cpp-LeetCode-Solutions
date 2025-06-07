typedef pair<char,int> P;
class Solution {
public:
    struct comparator{
        bool operator()(P &p1, P &p2){
            if(p1.first == p2.first)return p1.second<p2.second;
            return p1.first>p2.first;
        }
    };
    
    string clearStars(string s) {
        int n = s.length();

        priority_queue<P,vector<P>,comparator>pq;

        for(int i=0; i<n; i++){
            if(s[i] != '*')pq.push({s[i],i});
            else{
                int idx = pq.top().second;
                pq.pop();
                s[idx] ='*';
            }
        }

            string ans="";
            for(int i=0; i<n; i++){
                if(s[i]!='*')ans.push_back(s[i]);       
            }

            return ans;
        
    }
};