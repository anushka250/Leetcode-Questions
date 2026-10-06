class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int size = 0;
        int open = 0;

        //from left to right.
        for(char ch : s){
            if(ch == '('){
                size++;
            }
            else if (size>0){
                size--;
            }
            else{
                open++;
            }
        }
        return open + size;
    }
};