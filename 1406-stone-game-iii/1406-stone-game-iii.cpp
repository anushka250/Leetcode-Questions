class Solution {
public:
    vector<int> dp;
    int solve(int i, vector<int>& stones){
        int n= stones.size();
        if(i >= n)
        {
            return 0;
        }
        if(dp[i] != INT_MIN){
            return dp[i];
        }
        int ans = INT_MIN;
        int curr = 0;
        for(int j=i;j<min(n, i+3); j++){
            curr+= stones[j];
            int val = solve(j+1, stones);
            ans = max(ans, curr-val);
        }
        return dp[i] = ans;
    }
    string stoneGameIII(vector<int>& stoneValue){
            dp.assign(stoneValue.size(), INT_MIN);
            int diff=solve(0, stoneValue);
            if(diff>0){
                return "Alice";
            }
            else if(diff<0){
                return "Bob";
            }
            return "Tie";
    
    }
};