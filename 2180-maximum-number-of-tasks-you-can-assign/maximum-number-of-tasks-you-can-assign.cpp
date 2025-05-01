class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int m = tasks.size(), n = workers.size();
        int l=0, r=min(m,n);

        sort(begin(tasks),end(tasks));sort(begin(workers),end(workers),greater<>());

        int ans=0;
        while(l<=r){
            int mid = l+(r-l)/2;

            if(check(tasks,workers,pills,strength,mid)){
                ans=mid;
                l=mid+1;
            }else{r=mid-1;}
        }
        return ans;
    }

    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid){
        int pillsUsed=0;
        multiset<int> st(begin(workers),begin(workers)+mid);

        for(int i=mid-1; i>=0; i--){
            int reqrd = tasks[i];
            auto it = --st.end();

            if(*it>=reqrd){
                st.erase(it);
            }else if(pillsUsed>=pills)return false;
            else{
                auto weakest = st.lower_bound(reqrd-strength);
                if(weakest==st.end())return false;
                st.erase(weakest);
                pillsUsed++;
            }
        }
        return true;
    }
};