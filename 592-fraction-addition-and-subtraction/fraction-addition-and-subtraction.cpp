class Solution {
public:
    string fractionAddition(string expression) {

        int num = 0,den = 1;
        

        int n = expression.size();
        int i =0;
        while(i<n ){

            int new_n = 0, new_d = 0;
            bool isNeg = false;


            // sign checking :
            if((expression[i] == '-' )|| (expression[i] == '+')){

                if(expression[i] == '-'){
                    isNeg = true;
                }

            i++ ; 
            }

            // new num : 
            while(isdigit(expression[i])){
                int val = expression[i]-'0';
                new_n = new_n*10 + val;
                i++ ;
            }

            if(isNeg) new_n *= -1;

            i++ ; 

            //new denom : 
            while(i<n && isdigit(expression[i])){
                int val = expression[i] -'0';
                new_d = new_d*10 + val;
                i++;
            }


            // operation on new_n & new_d :
            num = (new_n*den) + (num*new_d);
            den = (den*new_d);
        }

        int gcd = abs(FindGCD(num,den));

        num /= gcd;
        den /= gcd;

        return to_string(num) + '/' + to_string(den);   
    }

    int FindGCD(int a, int b){
        if(a == 0)return b;
        return FindGCD(b%a,a);
    }


};