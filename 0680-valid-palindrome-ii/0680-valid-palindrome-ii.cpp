class Solution {
public:
    bool checkP(string &s, int st, int end){
        while(st < end){
            if(s[st] != s[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.length();
        int st = 0, end = n-1;
        while(st < end){
            if(s[st] != s[end]){
                return checkP(s, st+1, end) || checkP(s, st, end-1);
            }
            st++;
            end--;
        }
        return true;
    }
};