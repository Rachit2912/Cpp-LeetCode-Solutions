class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long n = skill.size();
        int i(0),j(n-1);
        if(n==2)return(skill[i]*skill[j]);

        sort(begin(skill),end(skill));
        int mini = skill[i]+skill[j],curr = mini;
        while(i<=j){
            if(curr != mini){
                return -1;
            }
            i++;j--;
            curr = skill[i]+skill[j];
        }
        i=0,j=n-1;
        long long ans = 0;
        while(i<=j){
            ans+=(skill[i]*skill[j]);
            i++;j--;
        }
        return ans;


    }
};