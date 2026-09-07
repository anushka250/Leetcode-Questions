class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1000000007;

        vector<long long> last(26, 0);

        long long total = 1;  
        for (char c : s) {
            int x = c - 'a';

            long long newSubseq = total;

            total = (total + newSubseq - last[x] + MOD) % MOD;

            last[x] = newSubseq;
        }

        return (total - 1 + MOD) % MOD;
    }
};