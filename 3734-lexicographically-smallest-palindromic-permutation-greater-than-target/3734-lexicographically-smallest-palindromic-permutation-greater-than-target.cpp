class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        // Frequency of characters
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        // Check if palindrome is possible
        int odd = 0;
        char midChar = '#';

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                odd++;
                midChar = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        // Characters available for the left half
        vector<int> half(26, 0);

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
        }

        int m = n / 2;

        /*
            We try to construct the left half.

            State:
            - pos = current position
            - greater = whether our prefix is already
                        greater than target
        */

        string left;

        // First try to make a palindrome whose left half
        // is exactly as small as possible while being > target.
        function<string(int, bool)> dfs =
            [&](int pos, bool greater) -> string {

                if (pos == m) {

                    string right = left;
                    reverse(right.begin(), right.end());

                    string ans = left;

                    if (n % 2)
                        ans += midChar;

                    ans += right;

                    if (ans > target)
                        return ans;

                    return "";
                }

                int start = 0;

                if (!greater)
                    start = target[pos] - 'a';

                for (int c = start; c < 26; c++) {

                    if (half[c] == 0)
                        continue;

                    // If still equal to target, we cannot
                    // choose a smaller character.
                    if (!greater && c < target[pos] - 'a')
                        continue;

                    half[c]--;
                    left += char('a' + c);

                    bool newGreater = greater;

                    if (!greater && c > target[pos] - 'a')
                        newGreater = true;

                    string res = dfs(pos + 1, newGreater);

                    if (!res.empty())
                        return res;

                    left.pop_back();
                    half[c]++;
                }

                return "";
            };

        return dfs(0, false);
    }
};