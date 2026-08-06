class Solution {
public:
    int smallestNumber(int n, int t) {
        while(1){
            int prod = 1;
            int cpy = n;
            while(cpy){
                int rightMostD = cpy%10;
                prod = prod * rightMostD;
                cpy = cpy/10;
            }
            if(prod % t == 0) return n;
            n++;
        }
        return 1;
    }
};