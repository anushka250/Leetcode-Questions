class Solution(object):
    def smallestPalindrome(self, s):
        freq = Counter(s)
        left = ""
        mid = ""
        for ch in sorted(freq):
            left += ch * (freq[ch]//2)
            if freq[ch] % 2 == 1:
                mid = ch
        return left + mid + left[::-1]
                