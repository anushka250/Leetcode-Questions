class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mine = INT_MAX, maxe = INT_MIN;
        vector<int> freq(101, 0);
        for(int val:nums){
            freq[val] = 1;
            maxe = max(maxe, val);
            mine = min(mine, val);
        }
        
        vector<int> ans;
        for(int i = mine + 1; i<maxe; i++){
            if(freq[i] == 0){
                ans.push_back(i);
            }
        }
    return ans;
    }
};