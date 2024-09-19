class Solution {
private : 
    vector<int> solve(string str){
        vector<int> result;
        for(int i =0; i<str.length(); i++){

            if(str[i] == '+' || str[i] == '-' || str[i] == '*'){
                vector<int> left_part = solve(str.substr(0,i));
                vector<int> right_part = solve(str.substr(i+1));

                // club all the possible comb. of left and right answer
                for(int &l : left_part){
                    for(int &r : right_part){
                        if(str[i] == '+'){
                            result.push_back(l+r);
                        }
                        else if(str[i] == '-'){
                            result.push_back(l-r);
                        }
                        else{
                            result.push_back(l*r);
                        }
                    }
                }

            }


        }
            // after all these if result is still empty, it means operator isn't present at all
            // then return the given integer only 
            if(result.empty()){
                result.push_back(stoi(str));
            }

            return result;
    }

public:

    vector<int> diffWaysToCompute(string expression) {
        // first intuition : inclusion - exclusion principle 
        // 1 baar operator pr split kia, 1  bar nhi kia
        // to ab recursion to use krna pdega 
        // or 1 operator k i) split ii) no split case k andar poore string 
        // k fir alg case bnenge esa pura tree bnega
         return solve(expression);
    }
};