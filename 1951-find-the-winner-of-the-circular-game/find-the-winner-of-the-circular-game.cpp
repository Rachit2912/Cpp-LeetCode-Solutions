class Solution {
public:
    int findTheWinner(int n, int k) {
        // real winner jb bachega to 0 index pr hoga
        int winner =0;
        //ab baaki bache n-1 frnds ko firse jodkr jodkr us winner ka naam nikal lenge
        for(int i=2;i<=n;i++){
            winner = (winner+k)%i; // bcz winner n-1 times -k krke shift hota hua pahucha h 0 index pr
            // or %i isliye kia h bcz us time pr grp me 'i' bande hi honge 
        }
        return winner+1;// final index aagya isme +1 krenge bcz we are using 0-indexing
    }
};