class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += ('z' - s[i] + 1) * (i+1);
        }
        return sum;
    }
};