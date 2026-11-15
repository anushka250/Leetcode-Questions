class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const long long MOD = 1e9 + 7;

        long long even = 1;
        long long odd = 0;
        long long sum = 0;
        long long ans = 0;

        for (int x : arr) {
            sum += x;

            if (sum % 2 == 1) {
                ans = (ans + even) % MOD;
                odd++;
            } else {
                ans = (ans + odd) % MOD;
                even++;
            }
        }

        return ans;
    }
};