class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> dir;
        int count = 0;
        // dir.push("main");
        for(string folder: logs){
            if(folder =="../"){
                // dir.pop();
                if(count!=0) count-- ; 
            }

            else if(folder == "./"){
                // nothing to do 
            }

            else{
                // dir.push(folder);
                count++ ;
            }
        }
       return count;


    }
};