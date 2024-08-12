class Solution {
public:
    int romanToInt(string s) {
        size_t pos;

    while ((pos = s.find("IV")) != std::string::npos) s.replace(pos, 2, "a"); 
    while ((pos = s.find("IX")) != std::string::npos) s.replace(pos, 2, "b"); 
    while ((pos = s.find("XL")) != std::string::npos) s.replace(pos, 2, "c"); 
    while ((pos = s.find("XC")) != std::string::npos) s.replace(pos, 2, "d"); 
    while ((pos = s.find("CD")) != std::string::npos) s.replace(pos, 2, "e"); 
    while ((pos = s.find("CM")) != std::string::npos) s.replace(pos, 2, "f"); 

    std::unordered_map<char, int> roman_to_value = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000},
        {'a', 4},  
        {'b', 9},  
        {'c', 40}, 
        {'d', 90}, 
        {'e', 400},
        {'f', 900} 
    };

    int ans = 0;
    for (auto i : s){
        ans += roman_to_value[i];
    }
        return ans;
    }
};