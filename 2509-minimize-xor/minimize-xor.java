class Solution {
    public int minimizeXor(int num1, int num2) {
        int result = 0, target = Integer.bitCount(num2), setBits = 0, curr=31;

        while(setBits < target){
            if(isSet(num1,curr) || (target-setBits > curr)){
                result = setBit(result,curr);
                setBits++ ; 
            }
            curr-- ; 
        }
        return result;
    }

    private boolean isSet(int x, int bit){return (x & (1<<bit)) != 0;}
    private int setBit(int x, int bit){return x | (1<<bit);}
}