class Solution {

private:
void Strperm(vector<int>& str,vector<vector<int>>& ans,int index){

    // base case :
    if (index >= str.size()){
        ans.push_back(str);
        return ;
    }

    // recursive call : 
    for (int i=index;i<str.size();i++){
        swap(str[index],str[i]);
        Strperm(str,ans,index+1);
        swap(str[index],str[i]);
    }
    
}

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int index = 0;
        vector<vector<int>> ans;
        Strperm(nums,ans,index);
        return ans;
    }
};