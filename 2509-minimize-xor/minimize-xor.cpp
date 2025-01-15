class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int result = num1;
        int target = __builtin_popcount(num2);
        int setBits = __builtin_popcount(result);
        int curr =0;
        while(setBits < target){
            if(!isSet(result,curr)){
                setBit(result,curr);
                setBits++ ;
            }
            curr++ ; 
        }

        while(setBits > target){
            if(isSet(result,curr)){
                unsetBit(result,curr);
                setBits-- ;
            }
            curr++ ; 
        }
        return result;
    }

private : 
bool isSet(int x, int bit){return x & (1<<bit);}
void setBit(int &x, int bit){x |= (1<<bit);}
void unsetBit(int &x, int bit){x &= ~(1<<bit);}
};