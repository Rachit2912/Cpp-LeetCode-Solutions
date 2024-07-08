class Solution {
public:
    int findTheWinner(int n, int k) {
        return indexFinder(n,k) + 1;
        // ye original winner ka index lake dega and usme +1 krenge to winner ka name ajayega
    }

    int indexFinder(int n, int k){

        // base case : last me 1 winner bacha hoga jiska index 0 hi ho skta h 
        if(n==1) return 0;

        // har step me saare indices -k se shift honge bcz we are deleting a frnd at index 'k' so it'll 
        // shift all the frnds to a measure of -k
        // ab dost kam hote jayenge har step me isliye n-1 hota jayega 
        int index = indexFinder(n-1,k);
        index = (index+k)%n; // bcz hme usko usi 'n' size k bound me rkhna h & sb -k se shift hue the isliye
        // wapas +k krke reset krdia 
        return index;
    }
};