class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        int minEven = INT_MAX;

        for (int x : nums1) {
            if (x % 2 == 0)
                minEven = min(minEven, x);
            else
                minOdd = min(minOdd, x);
        }

        bool allEven = true;

        for (int x : nums1) {
            if (x % 2 != 0) {
                if (minOdd >= x) {
                    allEven = false;
                    break;
                }
            }
        }

        if (allEven)
            return true;
        bool allOdd = true;

        for (int x : nums1) {
            if (x % 2 == 0) {

                if (minOdd >= x) {
                    allOdd = false;
                    break;
                }
            }
        }

        return allOdd;
    }
};