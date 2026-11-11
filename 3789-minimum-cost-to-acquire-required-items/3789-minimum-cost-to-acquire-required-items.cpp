class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        // Buy only type 1 and type 2
        long long ans = (long long)need1 * cost1 +
                        (long long)need2 * cost2;

        // Use type 3 for all need1
        long long option1 = (long long)need1 * costBoth;

        if (need2 > need1)
            option1 += (long long)(need2 - need1) * cost2;

        ans = min(ans, option1);

        // Use type 3 for all need2
        long long option2 = (long long)need2 * costBoth;

        if (need1 > need2)
            option2 += (long long)(need1 - need2) * cost1;

        ans = min(ans, option2);

        return ans;
    }
};