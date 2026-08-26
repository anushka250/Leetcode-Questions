class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0;
        int ones = 0;
        int minLen = INT_MAX;
        string ans = "";
        for(int right = 0; right < n; right++){
            if(s[right] == '1')
                ones++;
            while (ones > k){
                if(s[left] == '1')
                    ones--;
                left++;
            }
            while(ones == k){
                string curr = s.substr(left, right - left + 1);
                int len = curr.size();
                if(len < minLen){
                    minLen = len;
                    ans = curr;

                }
                else if (len == minLen && curr < ans){
                    ans = curr;
                }
                if (s[left] == '1')
                    ones--;
                left++;
            }
        }
        return ans;
    }
};