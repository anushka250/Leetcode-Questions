class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, int> mp;

        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int s = seat[1];

            mp[row] |= (1 << s);
        }

        int ans = 2 * n;

        for (auto &[row, mask] : mp) {

            bool left = (mask & (1 << 2)) ||
                        (mask & (1 << 3)) ||
                        (mask & (1 << 4)) ||
                        (mask & (1 << 5));

            bool middle = (mask & (1 << 4)) ||
                          (mask & (1 << 5)) ||
                          (mask & (1 << 6)) ||
                          (mask & (1 << 7));

            bool right = (mask & (1 << 6)) ||
                         (mask & (1 << 7)) ||
                         (mask & (1 << 8)) ||
                         (mask & (1 << 9));

            if (!left && !right) {
               
                continue;
            }

            if (!left || !right || !middle) {
               
                ans--;
            }
            else {
                
                ans -= 2;
            }
        }

        return ans;
    }
};