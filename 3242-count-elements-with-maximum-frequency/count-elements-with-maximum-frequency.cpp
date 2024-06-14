class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto i : nums){
            freq[i]++ ;
        }

        int max_freq = 0;
        for(auto i : freq){
            max_freq = max(max_freq,i.second);
        }

        int max_freq_elements = 0;
        for(auto i : freq){
            if(i.second == max_freq){
                max_freq_elements++ ;
            }
        }

        int total_max_freq = max_freq * max_freq_elements;
        return total_max_freq;
    }
};