class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
       int n = word1.size(), m = word2.size();

        vector<int> suf(n + 1, m);
        int j = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j])
                j--;
            suf[i] = j + 1;
        }

        vector<int> ans;
        int i = 0;
        bool used = false;

        for (int k = 0; k < m; k++) {
            while (i < n) {
                if (word1[i] == word2[k]) {
                    ans.push_back(i++);
                    break;
                }

                if (!used && suf[i + 1] <= k + 1) {
                    used = true;
                    ans.push_back(i++);
                    break;
                }

                i++;
            }

            if ((int)ans.size() != k + 1)
                return {};
        }

        return ans;
    
    }
};