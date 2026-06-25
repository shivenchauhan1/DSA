class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        
        char1 = list(s.lower())
        char2 = list(t.lower())

        char1.sort()
        char2.sort()

        if len(char1) == len(char2) and char1 == char2:
            return True
        else:
            return False