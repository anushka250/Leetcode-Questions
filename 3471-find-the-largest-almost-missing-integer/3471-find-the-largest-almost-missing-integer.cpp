class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> count(51, 0);
        for(int i = 0; i<= n-k; i++){
            vector<bool> present(51, false);
            for(int j=i; j<i+k; j++){
                present[nums[j]] = true;
            }
            for(int x = 0; x <= 50; x++){
                if(present[x]){
                    count[x]++;
                }
            }
        }
        int ans = -1;
        for(int x = 0; x<=50; x++){
            if(count[x] == 1){
                ans = x;
            }
        }
        return ans;
    }
};