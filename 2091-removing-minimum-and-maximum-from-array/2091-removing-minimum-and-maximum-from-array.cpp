class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIndex = 0;
        int maxIndex = 0;

        for (int i=1; i<n; i++){
            if(nums[i]<nums[minIndex])
                minIndex = i;
            if(nums[i]>nums[maxIndex])
                maxIndex = i;
        }
        int l = min(minIndex, maxIndex);
        int r = max(minIndex, maxIndex);

        int fromFront = r + 1;
        int fromBack = n - l;
        int bothsides = (l + 1) + (n - r);

        return min({fromFront, fromBack, bothsides});
    }
};