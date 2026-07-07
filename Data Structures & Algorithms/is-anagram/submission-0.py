class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        freq = 26 * [0]
        for i in range(0,len(s)):
            freq[ord(s[i])- ord('a')] += 1
            freq[ord(t[i])- ord('a')] -= 1
        
        for i in range(0,26):
            if(freq[i] != 0):
                return False
        return True