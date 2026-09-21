class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);

        vector<long long> dp(k, 0);
        for(int num : nums){
            vector<long long> newDp(k, 0);

            int val = num % k;

            newDp[val]++;

            for(int r = 0; r<k; r++){
                int newRemainder = (r * val) % k;
                newDp[newRemainder] += dp[r];
            }

            for(int r=0; r < k; r++){
                ans[r] += newDp[r];
            }
            dp = newDp;
        }
        return ans;
    }
};