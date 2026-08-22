class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;
        int digitSum = 0;
        int digitProd = 1;
        while(n>0){
            int digit = n % 10;
            digitSum += digit;
            digitProd *= digit;
            n /= 10;
        }
        int total = digitSum + digitProd;
        return original % total == 0;
    }
};