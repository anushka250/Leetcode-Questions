class Solution {
public:
    int reverse(int n){
        int rev = 0;
        while(n != 0){
            int r = n % 10;
            if(rev > INT_MAX/10 || rev < INT_MIN/10){
                return 0;
            }
            rev = rev * 10 + r;
            n = n / 10;
        }
        return rev;
    }
    bool isPalindrome(int n) {
        if (n < 0){
            return false;
        }
        int revNum = reverse(n);
        return revNum == n;
    }
};