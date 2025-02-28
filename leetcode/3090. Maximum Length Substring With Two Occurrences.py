from collections import defaultdict

class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        l, r = 0, 0
        freq = defaultdict(int)
        result = 0

        while r < len(s):
            ch = s[r]
            freq[ch] += 1

            while freq[ch] > 2:
                freq[s[l]] -= 1
                l += 1
            
            result = max(result, r - l + 1)
            r += 1

        return result
