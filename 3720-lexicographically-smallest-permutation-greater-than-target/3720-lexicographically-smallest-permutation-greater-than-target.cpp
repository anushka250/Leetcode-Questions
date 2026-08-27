class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        int n = s.size();
        string pref;

        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            // Case 1: We cannot match target[i].
            // Try to make the answer greater RIGHT HERE first.
            if (freq[x] == 0) {

                // Find smallest available character > target[i]
                for (int c = x + 1; c < 26; c++) {
                    if (freq[c] > 0) {
                        string result = pref;

                        result += char('a' + c);
                        freq[c]--;

                        // Add all remaining characters in sorted order
                        for (int j = 0; j < 26; j++) {
                            while (freq[j] > 0) {
                                result += char('a' + j);
                                freq[j]--;
                            }
                        }

                        return result;
                    }
                }

                // No greater character available here,
                // so we need to backtrack.
                break;
            }

            // Match target[i]
            pref += target[i];
            freq[x]--;
        }

        // Case 2:
        // Either target was matched completely,
        // or we couldn't make the current position greater.
        // Backtrack from right to left.
        for (int i = (int)pref.size() - 1; i >= 0; i--) {

            // Restore this character
            freq[pref[i] - 'a']++;

            int x = target[i] - 'a';

            // Find smallest available character > target[i]
            for (int c = x + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    string result = pref.substr(0, i);

                    result += char('a' + c);
                    freq[c]--;

                    // Fill remaining positions with smallest characters
                    for (int j = 0; j < 26; j++) {
                        while (freq[j] > 0) {
                            result += char('a' + j);
                            freq[j]--;
                        }
                    }

                    return result;
                }
            }
        }

        return "";
    }
};