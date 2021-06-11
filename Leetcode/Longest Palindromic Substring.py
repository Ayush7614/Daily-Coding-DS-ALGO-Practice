class Solution:    
    def isPalindrome(self, s: str) -> bool:
        return s == s[::-1]
    
    def longestPalindrome(self, s: str) -> str:
        if not s:
            raise Exception("You werent supposed to be null")
            
        if self.isPalindrome(s):
            return s
                
        for i in range(len(s), 0, -1):
            for j in range(0, len(s)-i+1): 
                candidate = s[j:j+i]
                if self.isPalindrome(candidate):
                    return candidate
