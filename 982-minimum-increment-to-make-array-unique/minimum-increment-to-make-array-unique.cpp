class Solution {
	public:
		int minIncrementForUnique(vector<int>& nums) {
			map<int,int>mp;
			int count=0;
			for(int i=0;i<nums.size();i++)mp[nums[i]]++;
			for(auto i:mp){
				if(i.second>1){
					mp[i.first+1]+=i.second-1;
					count+=i.second-1;
				}
			}
			return count;
		}
	};